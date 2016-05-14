
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include "./libft/includes/libft.h"

# define BUFF_SIZE 4096

typedef struct TElement
//struct TElement
{
	char buff[BUFF_SIZE];
	long long FilePosition;
	long long FileNbCharRead;
	int fd;
	struct TElement *next;
} Elem;

int	get_next_line(int const fd, char ** line);
int	get_next_line1(int const fd, char ** line);
#endif
