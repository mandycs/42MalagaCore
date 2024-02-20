#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char *line;
    char **line2;
    int y;

    y = 0;
    line2 = malloc(sizeof(char *) * 100); // Asigna espacio para 100 punteros a char
    if (line2 == NULL)
    {
        return -1; // Retorna error si la asignación de memoria falla
    }

    int fd = open("map1.ber", O_RDONLY);
    if (fd < 0)
    {
        free(line2); // Libera la memoria si falla abrir el archivo
        return -1; // Retorna error si no se puede abrir el archivo
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        line2[y] = malloc(strlen(line) + 1); // Asigna memoria para la línea actual
        if (line2[y] == NULL)
        {
            // Manejo de error: liberar memoria asignada previamente
            for (int i = 0; i < y; ++i)
            {
                free(line2[i]);
            }
            free(line2);
            return -1; // Retorna error si la asignación de memoria falla
        }
        memcpy(line2[y], line, strlen(line) + 1);
        free(line); // Libera la memoria de la línea leída
        y++;
    }
    close(fd); // Cierra el archivo

    // Imprime las líneas almacenadas y libera la memoria
    y = 0;
    while (line2[y] != NULL)
    {
        printf("%s", line2[y]);
        free(line2[y]); // Libera la memoria de cada línea después de imprimir
        y++;
    }
    free(line2); // Libera el array de punteros

    return 0;
}
