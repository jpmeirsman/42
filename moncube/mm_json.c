#include "mm_json.h"

/*
 * Les types des objets sont :
 * 0 : mylist;
 * 1 : Object
 * 2 : EndObject
 * 3 : Array
 * 4 : EndArray
 * 5 : String
 * 6 : Number
 * 7 : Boolean
 * 8 : null
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
	struct s_json_list			*next;
	struct s_json_list			*last;
	struct s_json_tree			*leaf;
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
}

void				json_tree_add_next(short type_value)
{
	t_json_tree		*curr;

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
}

t_json_tree			*json_tree_add_next_leaf(short type_value)
{
	t_json_tree		*curr;

	curr = json_new_tree();
	curr->type_value = type_value;
	if (curr_tree->child == NULL)
	{
		curr->parent = curr_tree;
		curr_tree->child = curr;
	}
	else
	{
		curr_tree = curr_tree->child;
		if (curr_tree->last == NULL)
		{
			curr->previous = curr_tree;
			curr->last = curr;
			curr->next = curr;
		 }
		else
		{
			curr->previous = curr_tree->last;
			curr_tree->last->next = curr;
			curr_tree->last->next = curr;
			curr_tree->last = curr;
		}
		curr_tree = curr_tree->parent;
	}
	return (curr);
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

void				json_indent()
{
	int			i;

	i = 0;
	while (i < indent)
	{
		printf(" ");
		i++;
	}
}

void				json_print_curr_info()
{
	t_json_object	*my_object;
	t_json_string	*my_string;
	t_json_array	*my_array;
	t_json_boolean	*my_boolean;

	switch (curr_tree->type_value)
	{
		case 1:
			my_object = (t_json_object *) curr_tree->value;
			json_indent();
			printf("Object: ");
			printf("%d \n", curr_tree->child->type_value);
			if (curr_tree->child->type_value == 3)
			{
				my_string = (t_json_string *) curr_tree->child->value;
				printf("%s ", my_string->s);
				if (curr_tree->child->next->type_value == 3)
				{
					my_string = (t_json_string *) curr_tree->child->next->value;
					printf("%s ", my_string->s);
				}
				else if (curr_tree->child->next->type_value == 5)
				{
					my_boolean = (t_json_boolean *) curr_tree->child->next->value;
					if (my_boolean->bl == 1)
						printf("true ");
					else
						printf("false");
				}
			}
			else
				printf("n'est pas une string");
			printf("\n");
			break;
		case 2:
			my_array = (t_json_array *) curr_tree->value;
			json_indent();
			printf("Array:\n");
			break;
		case 3:
			json_indent();
			my_string = NULL;
			my_string = (t_json_string *) curr_tree->value;
			printf("%s\n", my_string->s);
			break;
		case 5:
			json_indent();
			my_boolean = (t_json_boolean *) curr_tree->value;
			if (my_boolean->bl == 1)
				printf("true\n");
			else
				printf("false\n");
			break;
		default:
			printf("Type_value :%d\n",curr_tree->type_value);
			break;
	}
}

void				json_print_tree()
{
	short			search_child_at_first;

	search_child_at_first = 1;
	while (curr_tree != NULL)
	{
		if ((search_child_at_first == 1) && (curr_tree->child != NULL))
		{
			indent += 2;
			curr_tree = curr_tree->child;
			json_print_curr_info();
		}
		else
		if (curr_tree->next != NULL)
		{
			curr_tree = curr_tree->next;
			json_print_curr_info();
			search_child_at_first = 1;
		}
		else
		{
			indent -= 2;
			search_child_at_first = 0;
			curr_tree = curr_tree->parent;
		}
	}
}

void			json_add_token_to_list(void *curr, short type_value)
{
	t_json_list		*elem;

	elem = malloc(sizeof(t_json_list));
	elem->next = NULL;
	elem->last = NULL;
	elem->leaf = NULL;
	if (my_list->next == NULL)
	{
		my_list->next = elem;
		my_list->last = elem;
	}
	else
	{
		my_list->last->next = elem;
		my_list->last = elem;
	}
	elem->leaf = curr;
	elem->type_value = type_value;
}

void					json_token_start_object()
{
	json_add_token_to_list(NULL, 1);
}

void					json_token_end_object()
{
	json_add_token_to_list(NULL, 2);
}

void					json_token_start_array()
{
	json_add_token_to_list(NULL, 3);
}

void					json_token_end_array()
{
	json_add_token_to_list(NULL, 4);
}

void				json_token_string()
{
	char				*s;
	int					len;
	int					result;
	char				c;

	s = ft_memalloc(100);
	len = 0;
	while (((result = json_get_char(&c)) != 0) && (c != '"'))
	{
		s[len] = c;
		len++;
	}
	json_add_token_to_list(s, 5);
}

void				json_token_boolean(short bl)
{
	int					result;
	char				c;
	int					i;
	short				*pbl;

	pbl = malloc(sizeof(short));
	*pbl = bl;
	i = 0;
	while (i < 3)
	{
		result = json_get_char(&c);
		i++;
	}
	if (bl == 0)
		result = json_get_char(&c);
	json_add_token_to_list(pbl, 7);
}

void				json_token_null()
{
	json_add_token_to_list(NULL, 8);
}

void				json_token_number()
{
	char		*s;
	int			len;
	int			result;
	char		c;
	double		*number;

	number = malloc(sizeof(double));
	s = ft_memalloc(100);
	len = 0;
	result = 1;
	file_pos--;
	result = json_get_char(&c);
while ((c == '-') || (c == '.') || ((c >= '0') && (c <= '9')))
	{
		s[len] = c;
		len++;
		result = json_get_char(&c);
	}
	file_pos--;
	*number = atof(s);
	json_add_token_to_list(number, 6);
}

void				json_choose_token(char c)
{
	switch (c)
	{
		case '{':
			json_token_start_object();
			break;
		case '}':
			json_token_end_object();
			break;
		case '[':
			json_token_start_array();
			break;
		case ']':
			json_token_end_array();
			break;
		case 't':
			json_token_boolean(1);
			break;
		case 'f':
			json_token_boolean(0);
			break;
		case 'n':
			json_token_null();
			break;
		case '"':
			json_token_string();
			break;
		case ',':
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
			json_token_number();
			break;
		default:
			break;
	}
}

void				json_print_token()
{
	t_json_list		*curr;


	curr = my_list;
	while (curr != NULL)
		{
		switch (curr->type_value)
		{
			case 0:
				json_indent();
				printf("List\n");
				break;
			case 1:
				json_indent();
				printf("Start object\n");
				indent += 2;
				break;
			case 2:
				indent -= 2;
				json_indent();
				printf("End object\n");
				break;
			case 3:
				json_indent();
				printf("Start array\n");
				indent += 2;
				break;
			case 4:
				indent -= 2;
				json_indent();
				printf("End array\n");
				break;
			case 5:
				json_indent();
				printf("String: %s\n", (char *) curr->leaf);
				break;
			case 6:
				json_indent();
				printf("Number: %le\n", *(double *) curr->leaf);
				break;
			case 7:
				json_indent();
				printf("Boolean: %d\n", *(short *) curr->leaf);
				break;
			case 8:
				json_indent();
				printf("Null\n");
				break;
			default:
				json_indent();
				printf("\n");
				break;
		}
		curr = curr->next;
	}
}

void				*json_create_table(short type_value, int nb_rows)
{
	void			**table1;
//	void			*table2;

	table1 = NULL;
	switch (type_value)
	{
		case 6:
			table1 = (void **) malloc(sizeof(double *) * nb_rows + 1);
			break;
/*			table1[nb_rows] = NULL;
	table2 = (int *) malloc(sizeof(int) * nb_col*nb_rows);
	for(int i = 0 ; i < nb_row ; i++)
	{
		table1[i] = &table2[i*nb_col];
*/
	}
	return ((void *) table1);
}

void				*json_found_token(t_json_list *curr, short type_value)
{
	void			*ptr;
	int				nb;
	int				count;
	t_json_list		*start_curr;
	void			**tab;

	switch (type_value)
	{
		case 0:
			printf("List\n");
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 1:
			printf("Start object\n");
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 2:
			printf("End object\n");
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 3:
			curr = curr->next;
			start_curr = curr;
			nb = 0;
			while (curr->type_value != 4)
			{
				nb++;
				curr = curr->next;
			}
			nb--;
			tab = (void **) json_create_table(6, nb);
			count = 0;
			curr = start_curr;
			curr = curr->next;
			while (count < nb)
			{
				tab[count] = (void *)  curr->leaf;
				count++;
				curr = curr->next;
			}
			printf("%d==\n", nb / 3);
			ptr = tab;
			break;
		case 4:
			printf("End array\n");
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 5:
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 6:
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 7:
			curr = curr->next;
			ptr = curr->leaf;
			break;
		case 8:
			curr = curr->next;
			ptr = curr->leaf;
			break;
		default:
			ptr = NULL;
			printf("???\n");
			break;
	}
	return (ptr);
}

void				*json_search_item(char *s, short type_value)
{
	double			*nb;
	char			**tab;
	int				i;
	short			found;
	t_json_list		*curr;
//	int				nb_rec;

	nb = malloc(sizeof(double));
	tab = ft_strsplit(s, ' ');
	i = 0;
	found = 0;
	curr = my_list;
	while ((curr != NULL) && !found)
	{
		if (curr->type_value == 5)
		{
			if (strcmp(tab[i], (char *) curr->leaf) == 0)
			{
				i++;
				if (tab[i] == NULL)
				{
					found = 1;
					nb = json_found_token(curr, type_value); 
				}
				
			}
		}
		curr = curr->next;
	}
	return (nb);

}

int					json_print(t_json *js, char * file_name)
{
	int					fd;
	char				c;
	int					result;
//	double				*verticesCount;
	int					vertices_count;
	int					indices_count;
	double				**tab_vertices;
	double				**tab_indices;
	int					i;

	indent = 0;
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (-1);
	file_size = lseek (fd, 0, SEEK_END);
	lseek (fd, 0, 0);
	buffer = malloc(file_size);
	result = read(fd, buffer, file_size);
	file_pos = 0;
	my_list = malloc(sizeof(t_json_list));
	my_list->next = NULL;
	my_list->last = NULL;
	my_list->type_value = 0;

// Création de la liste de tokens
	while ((result = json_get_char(&c)) )
	{
		json_choose_token(c);
	}

// Affichage de la liste de tokens
	indent = 0;
//	json_print_token();

// Recherche d'un objet dans la liste
	vertices_count = *(double *) json_search_item("meshes subMeshes verticesCount", 6);
	printf("%d vertices\n", vertices_count);
	indices_count = *(double *) json_search_item("meshes subMeshes indexCount", 6);
	printf("%d indices\n", indices_count);
	tab_vertices = (double **) json_search_item("meshes Cube vertices", 3);
	tab_indices = (double **) json_search_item("meshes Cube indices", 3);
//	tab_vertices = (double *) json_search_item("meshes Suzanne vertices", 3);
//	tab_indices = (double *) json_search_item("meshes Suzanne indices", 3);
//	printf("%d indices\n", indices_count);
	i = 0;
	while (tab_vertices[i] != NULL)
	{
		printf("%le\t",(double) *tab_vertices[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (tab_indices[i] != NULL)
	{
		printf("%le\t",(double) *tab_indices[i]);
		i++;
	}
	printf("\n");


js = NULL;
	return (0);
/*
	print_bool2 = 0;
	print_bool = 0;
	my_list->type_value = -1;
	pp = malloc(sizeof(t_json_pushpop));
	pp->type_value = -1;
	pp->first = NULL;
	pp->value = NULL;

	curr_tree = json_new_tree();
	root_tree = curr_tree;

	js = NULL;
	print_bool2 = 1;
	curr_tree = root_tree;
	json_print_tree();
	return (0);
*/
}
