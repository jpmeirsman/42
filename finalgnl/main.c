#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <libc.h>
#include "get_next_line.h"

void get_next_line2(int const fd, char ** line)
{
    int returncode = get_next_line(fd, line);
    if (returncode == 0)
    {
        printf("Chaine lue : ===%s===\n", *line);
        printf("Fin de fichier atteinte\n");
    }
    if (returncode == 1)
    {
        printf("Chaine lue : ---%s---\n", *line);
    }
    if (returncode == -1)
    {
        printf("Une erreur est survenue...\n");
    }
//return returncode;
}


int main(void)
{
    int fd1, fd2, fd3, fd4, fd5;
    char * BUFF;

fd1 = open("1.txt",O_RDONLY);
fd2 = open("2.txt",O_RDONLY);
fd3 = open("3.txt",O_RDONLY);
fd4 = open("4.txt",O_RDONLY);
fd5 = 444;


get_next_line2(fd5, &BUFF);
get_next_line2(fd4, &BUFF);
get_next_line2(fd1, &BUFF);

get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd2, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd2, &BUFF);
get_next_line2(fd3, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd3, &BUFF);
get_next_line2(fd2, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);
get_next_line2(fd1, &BUFF);

return 0;
}
