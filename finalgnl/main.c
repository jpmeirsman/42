#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
** 2 lines with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d %d\n",ret,errors);
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			printf("%d %d\n",ret,errors);
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors++;
			printf("%s:%s:%d\n",line,"abcdefg",strcmp(line,"abcdefg"));
			printf("%d %d\n",ret,errors);
			count_lines++;
			printf("%d %d\n",ret,errors);
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" and \"abcdefg\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
