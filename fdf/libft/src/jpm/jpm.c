#include <stdlib.h>
#include "libft.h"

t_list2		*initialisation()
{
	t_list2 *my_list = malloc(sizeof(my_list));
	if (my_list == NULL/* | element == NULL*/)
	{
		return(NULL);
	}
	my_list->first = NULL;
	return my_list;
}

void		realloc_str(char ** Source, long long len, long long lenmore)
{
void		*temp;

	temp = *Source;
	*Source = malloc(len + lenmore + 1);
 	ft_memset(*Source, '\0', len + lenmore + 1);
	ft_strncpy(*Source, temp, len);
 	free(temp);
}

