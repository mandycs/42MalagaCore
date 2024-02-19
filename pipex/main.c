#include <stdio.h>
#include "pipex.h"
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {

	printf("%d",access("/Users/mancorte/.brew/bin/ls", F_OK));
    return 0;
}
