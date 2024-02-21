#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {

	int i = 0;
	while (strstr(envp[i], "PATH") == NULL)
	{
		i++;
	}
	char *path = envp[i];

	path += 5;
	printf("%s \n", path);
    return 0;
}
