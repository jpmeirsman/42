#include "get_next_line.h"

int			get_line(int const fd, char ** line, Elem * Curr, int nbCharLine)
{
	while (1)
	{
		if ((Curr->FileNbCharRead == 0)
			|| (Curr->FilePosition == Curr->FileNbCharRead))
		{
			if ((Curr->FileNbCharRead = read(fd, Curr->buff, BUFF_SIZE)) == 0)
				return (*line[0] == 0 ? 0 : 1);
			Curr->FilePosition = 0;
			realloc_str(line, nbCharLine, Curr->FileNbCharRead);
		}
		while (Curr->FilePosition < Curr->FileNbCharRead)
		{
			if (Curr->buff[Curr->FilePosition] == '\n')
			{
				Curr->FilePosition++;
				return (1);
			}
			line[0][nbCharLine++] = Curr->buff[Curr->FilePosition++];
			if (Curr->FilePosition == Curr->FileNbCharRead)
			{
				Curr->FileNbCharRead = 0;
				Curr->FilePosition = 0;
			}
		}
	}
}

int			get_next_line(int const fd, char ** line)
{
			Elem			*Curr;
			static List		*myList = NULL;
			char			c[1];

	myList = myList ? myList : initialisation();
	if ((fd<0) || (myList == NULL) || (read(fd, c, 0) == -1) || !line)
		return (-1);
	Curr = myList->first;
	while ((Curr != NULL) && (Curr->fd != fd))
		Curr = Curr-> next;
	if (Curr == NULL)
	{
		Curr = malloc(sizeof(Elem));
		Curr->FilePosition = 0;
		Curr->fd = fd;
		Curr->next = myList->first;
		myList->first = Curr;
		Curr->FileNbCharRead = 0;
	}
	*line = malloc(1);
	line[0][0] = '\0';
	return (get_line(fd, line, Curr,0));
}
