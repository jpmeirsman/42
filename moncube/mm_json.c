#include "mm_json.h"

/*
 * Les types des objets sont :
 * 0 : mylist;
 * 1 : Object
 * 2 : Array
 * 3 : String
 * 4 : Number
 * 5 : Boolean
 * 6 : null
*/

typedef struct					s_json_value
{
	short						type_value;
	void						*value;
}								t_json_value;

typedef struct					s_json_string
{
	char						*s;;
}								t_json_string;

typedef struct					s_json_number
{
	double						nb;;
}								t_json_number;

typedef struct					s_json_boolean
{
	short						bl;
}								t_json_boolean;

typedef struct					s_json_null
{
	void						*p;
}								t_json_null;

typedef struct					s_json_array
{
	void						*value;
	struct s_json_array			*next;
	struct s_json_array			*last;
}								t_json_array;

typedef struct					s_json_object
{
	char						*s;
	void						*value;
	struct s_json_object		*next;
	struct s_json_object		*last;
}								t_json_object;

typedef struct					s_json_list
{
	short						type_value;
	struct s_json_list			*first;
}								t_json_list;

typedef struct					s_json_tree
{
	short						type_value;
	void						*value;
	struct s_json_tree			*first;
	struct s_json_tree			*last;
	struct s_json_tree			*next;
	struct s_json_tree			*previous;
	struct s_json_tree			*parent;
	struct s_json_tree			*child;
}								t_json_tree;

typedef struct					s_json_pushpop
{
	short						type_value;
	void						*value;
	struct s_json_pushpop		*first;
}								t_json_pushpop;

	int				indent;
	long			file_size;
	long			file_pos;
	char			*buffer;
	short			print_bool;
	short			print_bool2;
	t_json_list		*my_list;
	t_json_pushpop	*pp;
	t_json_tree		*curr_tree;
	t_json_tree		*root_tree;

t_json_tree			*json_new_tree()
{
	t_json_tree		*curr;

	curr = malloc(sizeof(t_json_tree));
	curr->value = NULL;
	curr->first = NULL;
	curr->last = NULL;
	curr->next = NULL;
	curr->previous = NULL;
	curr->parent = NULL;
	curr->child = NULL;
	return (curr);
}

void				json_tree_add_child(short type_value)
{
	t_json_tree		*curr;

	curr = json_new_tree();
	curr->type_value = type_value;
	if (curr_tree->last == NULL)
		curr->parent = curr_tree;
	else
		curr->parent = curr_tree->last;
	if (curr_tree->last == NULL)
		curr_tree->child = curr;
	else
		curr_tree->last->child = curr;
	curr_tree = curr;
printf("Ajout de Curr: %p en tant qu'enfant de curr_tree:%p\n",curr, curr_tree->parent);

//	curr_tree->parent->child = curr;

}

void				json_tree_add_next(short type_value)
{
	t_json_tree		*curr;

//printf("DEB - Curr:%p Parent:%p Child:%p Next:%p\n",curr_tree, curr_tree->parent,
//	curr_tree->child, curr_tree->next);
	curr_tree = curr_tree->child;
	curr = json_new_tree();
	curr->type_value = type_value;
	if (curr_tree->next == NULL)
		curr_tree->next = curr;
	if (curr_tree->last == NULL)
		curr->previous = curr_tree;
	else
	{
		curr->previous = curr_tree->last;
		curr_tree->last->next = curr;
	}
	curr_tree->last = curr;
	curr->parent = curr_tree->parent;
//	curr_tree->last->next = curr;
//	curr_tree->last->last = curr;


printf("Ajout de Curr: %p en tant que dernier de curr_tree:%p\n",curr, curr_tree);

}

t_json_tree			*json_tree_add_next_leaf(short type_value)
{
	t_json_tree		*curr;

//printf("DEB - Curr:%p Parent:%p Child:%p Next:%p\n",curr_tree, curr_tree->parent,
//	curr_tree->child, curr_tree->next);
//	curr_tree = curr_tree->child;
	curr = json_new_tree();
	curr->type_value = type_value;
	if (curr_tree->next == NULL)
		curr_tree->next = curr;
	if (curr_tree->last == NULL)
		curr->previous = curr_tree;
	else
	{
		curr->previous = curr_tree->last;
		curr_tree->last->next = curr;
	}
	curr_tree->last = curr;
	curr->parent = curr_tree->parent;
	return (curr);
//	curr_tree->last->next = curr;
//	curr_tree->last->last = curr;
}

void				json_tree_return_to_parent()
{
	curr_tree = curr_tree->parent;
}

void				json_push_pp(void *ptr, short type_value)
{
	t_json_pushpop	*curr;

	curr = malloc(sizeof(t_json_pushpop));
	curr->type_value = type_value;
	curr->value = ptr;
	curr->first = pp;
	pp = curr;
}

void				*json_get_pp_value()
{
	return (pp->value);
}

void				*json_get_pp()
{
	return (pp);
}

void				json_pop_pp()
{
	void			*curr;

	curr = pp;
	pp = pp->first;
	free(curr);
}

int					json_get_char(char *c)
{
	if (file_pos < file_size)
	{
		*c = buffer[file_pos++];
		return (1);
	}
	return (0);
}

void				json_choose_rule(/*t_json *js,*/ char c)
{
	int			result;

	switch (c)
	{
		case '{':
//printf("DEB - Curr:%p Parent:%p Child:%p Next:%p\n",curr_tree, curr_tree->parent,
//	curr_tree->child, curr_tree->next);
			json_indent();
			if (print_bool) printf("Object:\n");
			indent += 2;
			if (curr_tree->child == NULL)
			{
//	printf("add child\n");
				json_tree_add_child(1);
			}
			else
			{
//	printf("add next\n");
	//			curr_tree = curr_tree->child;
				json_tree_add_next(1);
			}
			json_get_object();
			json_tree_return_to_parent();
			indent -= 2;
			json_indent();
//printf("FIN - Curr:%p Parent:%p Child:%p Next:%p\n",curr_tree, curr_tree->parent,
//	curr_tree->child, curr_tree->next);
//	printf("add return\n");
			if (print_bool) printf("End Object:\n");
			break;
		case '[':
			indent += 2;
			if (print_bool) printf("\n");
			json_indent();
			if (print_bool) printf("Array:\n");
			json_get_array();
			json_indent();
			if (print_bool) printf("End Array:\n");
			indent -= 2;
			break;
		case 't':
			json_get_true();
			break;
		case 'f':
			json_get_false();
			break;
		case '"':
			json_get_string();
			if (print_bool) printf("\n");
			break;
		case ',':
			result = json_get_char(&c);
			break;
		case '-':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			json_get_number(c);
			break;
		default:
			if (print_bool) printf("%c", c);
			if (print_bool) printf("\nEnd default:\n");
			break;
	
	}
}

void				json_get_false()
{
	int			i;
	int			result;
	char		c;

	i = 0;
	while (i < 4)
	{
		result = json_get_char(&c);
		if (print_bool) printf("%c",c);
		i++;
	}
	if (print_bool)printf(" = false\n");
}

void				json_get_null()
{
	int			i;
	int			result;
	char		c;

	i = 0;
	while (i < 3)
	{
		result = json_get_char(&c);
		i++;
	}
	if (print_bool)printf(" = null\n");
}

void				json_get_true()
{
	int			i;
	int			result;
	char		c;

	i = 0;
	while (i < 3)
	{
		result = json_get_char(&c);
		i++;
	}
	if (print_bool) printf(" = true\n");
}

void				json_indent()
{
	int			i;

	i = 0;
	while (i < indent)
	{
		if (print_bool) printf(" ");
		if (print_bool2) printf(" ");
		i++;
	}
}

void				json_get_number(char first_digit)
{
	char		*s;
	int			len;
	int			result;
	char		c;
	double		number;

	s = ft_memalloc(100);
	len = 0;
	result = 1;
	c = first_digit;
	while (result  && (c != ',') && (c != '}') && (c != ']'))
	{
		s[len] = c;
		len++;
		result = json_get_char(&c);
	}
	file_pos--;
	json_indent();
	number = atof(s);
	if (print_bool) printf("%le\n",number);
}

void				json_get_string()
{
	char				*s;
	int					len;
	int					result;
	char				c;
	t_json_string		*curr;
	t_json_tree			*temp;

	curr = malloc(sizeof(t_json_string));
	temp = json_tree_add_next_leaf(3);
	temp->value = curr;
//	curr_tree->type_value = 3;
	s = ft_memalloc(100);
	len = 0;
//	result = json_get_char(fd, &s[0]);
	while (((result = json_get_char(&c)) != 0) && (c != '"'))
	{
		s[len] = c;
		len++;
	}
	json_indent();
	if (print_bool) printf("%s",s);
//	printf("%s\n",s);
	curr->s = ft_memalloc(ft_strlen(s));
	strcpy(curr->s, s);;
}
/*
void		json_read_value(int fd)
{
	char		c;
	int			result;

	
	printf("%c\n",c);
	exit(0);
}
*/
void				json_get_array()
{
	char		c;
	int			result;

	result = json_get_char(&c);
	while (result && (c != ']'))
	{
		json_choose_rule(c);
		result = json_get_char(&c);
		if (c == ',')
			result = json_get_char(&c);
	}
//		printf("===%c\n",c);
//		exit(0);

}

void				json_get_object()
{
	char				c;
	int					result;
	t_json_object		*curr;

	curr = malloc(sizeof(t_json_object));
	curr_tree->value = curr;
	curr_tree->type_value = 1;
	result = json_get_char(&c);
	while (result  && (c != '}'))
	{
		json_get_string();
		result = json_get_char(&c);
		result = json_get_char(&c);
		json_choose_rule(c);
		result = json_get_char(&c);
		if (c == ',')
			result = json_get_char(&c);
	}

}

void				json_print_curr_info()
{
	t_json_object	*my_object;
	t_json_string	*my_string;

//printf("%d\n",curr_tree->type_value);
	switch (curr_tree->type_value)
	{
		case 1:
			my_object = (t_json_object *) curr_tree->value;
			json_indent();
			printf("Object: ");
//			printf("%p ", curr_tree->next);
//			printf("%p ", curr_tree->next->value);
			if (curr_tree->next->type_value == 3)
			{
				my_string = (t_json_string *) curr_tree->next->value;
//				printf("%p %p ", my_string, my_string->s);
				printf("%s ", my_string->s);
				if (curr_tree->next->next->type_value == 3)
				{
					my_string = (t_json_string *) curr_tree->next->next->value;
					printf("%s ", my_string->s);
				}
			}
			else
				printf("n'est pas une string");
			printf("\n");
			break;
		case 3:
			json_indent();
			my_string = NULL;
			my_string = (t_json_string *) curr_tree->value;
//			printf("%p %p ", my_string, my_string->s);
			printf("%s\n", my_string->s);
			break;
		default:
			printf("Type_value :%d\n",curr_tree->type_value);
			break;
	}
}

void				json_print_tree()
{
//	short			find_next_parent;
	short			search_child_at_first;

	search_child_at_first = 1;
	while (curr_tree != NULL)
	{
		if ((search_child_at_first == 1) && (curr_tree->child != NULL))
		{
			indent += 2;
//			printf("%p",curr_tree);
			curr_tree = curr_tree->child;
//			printf(" -> %p - ",curr_tree);
//			printf("child\n");
			json_print_curr_info();
		}
		else
		if (curr_tree->next != NULL)
		{
//			printf("%p",curr_tree);
			curr_tree = curr_tree->next;
//			printf(" -> %p - ",curr_tree);
//			printf("next\n");
			json_print_curr_info();
			search_child_at_first = 1;
		}
		else
		{
			indent -= 2;
			search_child_at_first = 0;
//			printf("%p",curr_tree);
			curr_tree = curr_tree->parent;
//			printf(" -> %p - ",curr_tree);
//			printf("parent\n");
		}
	}
}

int					json_print(t_json *js, char * file_name)
{
	int					fd;
//	t_list2				*my_list;
//	t_json_object		*curr;
	char				c;
//	char				**str_buf;
	int					result;
//	t_json_pushpop		*curr;
//	void				*ptr;

	indent = 0;
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (-1);
	file_size = lseek (fd, 0, SEEK_END);
	lseek (fd, 0, 0);
	buffer = malloc(file_size);
	file_pos = 0;
	print_bool2 = 0;
	result = read(fd, buffer, file_size);
	print_bool = 0;
	my_list = malloc(sizeof(t_json_list));
	my_list->type_value = -1;
	my_list->first = NULL;
	pp = malloc(sizeof(t_json_pushpop));
	pp->type_value = -1;
	pp->first = NULL;
	pp->value = NULL;

	curr_tree = json_new_tree();
	root_tree = curr_tree;

	while ((result = json_get_char(&c)) )
	{
		json_choose_rule(c);
	}
	js = NULL;

	print_bool2 = 1;
	curr_tree = root_tree;
	json_print_tree();
	return (0);
}