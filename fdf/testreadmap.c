#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <libc.h>
#include "get_next_line.h"
#include "mm_readmap.c"
#include "mm_readmap.h"

int main(int argc, char **argv)
{
	int			fd;
	t_fic		tf;
	t_list2		*my_list;

	if ((argc != 2) || (fd = open(argv[1],O_RDONLY)) <= 0)
		return (-1);
	my_list = initialisation();
	charge_map(my_list, &tf, fd);
	create_map(my_list, &tf);
	print_map(my_list, &tf);
	close(fd);
	return 0;
}
