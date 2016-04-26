
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include "./libft/includes/libft.h"

# define BUFF_SIZE 1


typedef struct TElement Elem;
struct TElement
{
	char buff[BUFF_SIZE];
	long long FilePosition;
	long long FileNbCharRead;
	int fd;
	Elem *next;
};
/*
typedef struct TList List;
struct TList
{
	void *first;
};

List	*initialisation()
{
	List *List = malloc(sizeof(List));
	if (List == NULL)
	{
		exit(EXIT_FAILURE);
	}
	List->first = NULL;
	return List;
}

void	realloc_str(char ** Source, long long len, long long lenmore)
{
void	*temp;

	temp = *Source;
	*Source = malloc(len + lenmore + 1);
 	memset(*Source, '\0', len + lenmore + 1);
	strncpy(*Source, temp, len);
 	free(temp);
}
*/
//int	get_line(int const fd, char ** line, Elem * Curr, int nbCharLine);
int	get_next_line(int const fd, char ** line);
#endif
