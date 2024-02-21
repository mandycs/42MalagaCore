#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "pipex.h"

int	main(char **envp)
{
	// Search for the path in envp
	char *path = NULL;
	for (int i = 0; envp[i] != NULL; i++) {
		if (strncmp(envp[i], "PATH=", 5) == 0) {
			path = envp[i] + 5;
			break;
		}
	}

	// Print the path where the "ls" command is located
	if (path != NULL) {
		char command[256];
		snprintf(command, sizeof(command), "%s/ls", path);
		printf("Path of ls command: %s\n", command);
	} else {
		printf("PATH environment variable not found.\n");
	}
}
