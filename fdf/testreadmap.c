#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <libc.h>
#include "get_next_line.h"
#include "readmap.c"

int main(int argc, char **argv)
{
	int			fd;
	tfic		tf;
	List		*myList;

	if ((argc != 2) || (fd = open(argv[1],O_RDONLY)) <= 0)
		return (-1);
	myList = initialisation();
	chargeMap(myList, &tf, fd);
	createMap(myList, &tf);
	printMap(myList, &tf);
	close(fd);
	return 0;
}
