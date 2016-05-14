#include "mm_json.h"
/*
int			**create_table(int nb_row, int nb_col){
	int		**table1;
	int		*table2;

	table1 = (int **) malloc(sizeof(int*) * nb_row);
	table2 = (int *) malloc(sizeof(int) * nb_col*nb_row);
	for(int i = 0 ; i < nb_row ; i++){
		table1[i] = &table2[i*nb_col];
	}
	return table1;
}

t_vector3				**create_table_v3(int nb_row, int nb_col){
	t_vector3			**table1;
	t_vector3		*table2;

	table1 = (t_vector3 **) malloc(sizeof(void *) * nb_row);
	table2 = (t_vector3 *) malloc(sizeof(t_vector3) * nb_col*nb_row);
	for(int i = 0 ; i < nb_row ; i++){
		table1[i] = &table2[i*nb_col];
	}
	return table1;
}

void		free_table(int **table1)
{
	free(table1[0]);
	free(table1);
}

void		print_map(t_list2 *my_list, t_fic *tf)
{
	t_elem_int		*curr;
	long long		i;
	long long		j;

	curr = my_list->first;
	i = 0;
	while (i < tf->nb_rows)
	{
		j = 0;
		while (j < tf->nb_columns)
		{
			printf("%d ", tf->values[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

}

void		create_map(t_list2 *my_list, t_fic *tf)
{
	t_elem_int		*curr;
	long long		i;
	long long		j;
	double			center_x;
	double			center_y;

	tf->min_elev = 1e70;
	tf->max_elev = -1e70;
	curr = my_list->first;
	tf->values = create_table(tf->nb_rows,tf->nb_columns);
	tf->tvect = create_table_v3(tf->nb_rows,tf->nb_columns);
	center_x = (float) (tf->nb_columns - 1) / 2;
	center_y = (float) (tf->nb_rows - 1) / 2;

	i = tf->nb_rows - 1;
	while (i >= 0)
	{
		j = tf->nb_columns - 1;
		while (j >= 0)
		{
			if (tf->min_elev > curr->value)
				tf->min_elev = curr->value;
			if (tf->max_elev < curr->value)
				tf->max_elev = curr->value;
			tf->values[i][j] = curr->value;
			tf->tvect[i][j] = set_vector3( j - center_x, i - center_y, 
				curr->value);
			curr = curr->next;
			j--;
		}
		i--;
	}
}

void		load_map(t_list2 *my_list, t_fic *tf, int fd)
{
	t_elem_int		*curr;
	char		*buff;
	char		**str_buf;

	curr = NULL;
	my_list->first = curr;
	tf->nb_rows = 0;
	while ((get_next_line(fd, &buff) > 0))
	{
		str_buf = ft_strsplit(buff, ' ');
		tf->nb_columns = 0;
		while (str_buf[tf->nb_columns] != 0)
		{
			curr = malloc(sizeof(t_elem_int));
			curr->value = ft_atoi(str_buf[tf->nb_columns]);
			curr->next = my_list->first;
			my_list->first = curr;
			tf->nb_columns++;
		}
		tf->nb_rows++;
	}
}

t_fic		*read_file(char *file_name)
{
	int			fd;
	t_fic		*tf;
	t_list2		*my_list;

	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (NULL);
	my_list = initialisation();
	tf = malloc(sizeof(t_fic));
	load_map(my_list, tf, fd);
	create_map(my_list, tf);
	return (tf);
}

unsigned short				ahtos(char *s)
{
	int		a;
	int		b;

	if (s[0] >= 'A')
		a = s[0] - 55;
		else
		a = s[0] - 48;
	if (s[1] >= 'A')
		b = s[1] - 55;
		else
		b = s[1] - 48;
	return (a * 16 + b);
}

unsigned int					ahtoi(char *s)
{
	int				a;
	int				b;
	int				c;
	int				d;
	unsigned int	result;

	a = ahtos(&s[2]);
	b = ahtos(&s[4]);
	c = ahtos(&s[6]);
	d = ahtos(&s[8]);
//	result = (((a * 256 ) + b * 256) + c * 256) + d;
	result = (unsigned int) (((((a * 256) + b) * 256) + c) * 256) + d;
	return (result);

}

void				load_pal(t_list2 *my_list, t_data *data, int fd)
{
	t_elem_pal		*curr;
	char			*buff;
	char			**str_buf;
	double			prev_range;
	double			range;
	int				i;

	curr = NULL;
	my_list->first = curr;
	data->nb_palette = 0;
	prev_range = 0;
	while ((get_next_line(fd, &buff) > 0))
	{
		str_buf = ft_strsplit(buff, ' ');
		curr = malloc(sizeof(t_elem_pal));
		curr->value.start_color = int_to_color4(ahtoi(str_buf[0]));
		curr->value.end_color = int_to_color4(ahtoi(str_buf[2]));
		curr->value.start_range = prev_range;
		range = (double) ft_atoi(str_buf[1]);
		prev_range += range;
		curr->value.end_range = prev_range;
		curr->next = my_list->first;
		my_list->first = curr;
		data->nb_palette++;
	}
	data->palette = (t_palette *) malloc(sizeof(t_palette) * data->nb_palette);
	curr = my_list->first;
	i = data->nb_palette - 1;
	while (i >= 0)
	{
		data->palette[i] = curr->value;
//		printf("--Start range:%le\n", curr->value.start_range);
//		printf("--Start range:%le\n", data->palette[i].start_range);
		curr = curr->next;
		i--;
	}
}

void		print_pal(t_data *data)
{
	int		i;
//	int		color;

	printf("Il y a %d palette(s)\n ", data->nb_palette);
	i = 0;
	while (i < data->nb_palette)
	{
		printf("Palette n°%d\n", i);
		printf("Start color:%s\n",color4_to_string(data->palette[i].start_color));
		printf("End color:%s\n",color4_to_string(data->palette[i].end_color));
		printf("Start range:%le\n", data->palette[i].start_range);
		printf("End range:%le\n", data->palette[i].end_range);
		i++;
	}

}

int	read_pal(t_data *data, char *file_name)
{
	int			fd;
	t_list2		*my_list;

	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (-1);
	my_list = initialisation();
	data->palette = malloc(sizeof(t_palette));
	load_pal(my_list, data, fd);
//	print_pal(data);
//	create_pal(my_list, tp);
	return (0);
*/

typedef struct					s_json_value
{
	short						type_value;
	void						*value;
}								t_json_value;

typedef struct					s_json_string
{
	char						s;;
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

	int			indent;
	long		file_size;
	long		file_pos;
	char		*buffer;


int			json_get_char(char *c)
{
	if (file_pos < file_size)
	{
		*c = buffer[file_pos++];
		return (1);
	}
	return (0);
}

void		json_choose_rule(/*t_json *js,*/ char c)
{
	int			result;

	switch (c)
	{
		case '{':
			json_indent();
			printf("Object:\n");
			indent += 2;
			json_get_object();
			indent -= 2;
			json_indent();
			printf("End Object:\n");
			break;
		case '[':
			indent += 2;
			printf("\n");
			json_indent();
			printf("Array:\n");
			json_get_array();
			json_indent();
			printf("End Array:\n");
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
			printf("\n");
			break;
		case ',':
			result = json_get_char(&c);
			printf("\nEnd ,:\n");
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
			printf("%c", c);
			printf("\nEnd default:\n");
			break;
	
	}
}

void			json_get_false()
{
	int			i;
	int			result;
	char		c;

	i = 0;
	while (i < 4)
	{
		result = json_get_char(&c);
		printf("%c",c);
		i++;
	}
	printf(" = false\n");
}

void			json_get_null()
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
	printf(" = null\n");
}

void			json_get_true()
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
	printf(" = true\n");
}

void			json_indent()
{
	int			i;

	i = 0;
	while (i < indent)
	{
		printf(" ");
		i++;
	}
}

void			json_get_number(char first_digit)
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
	printf("%le\n",number);
}

void			json_get_string()
{
	char		*s;
	int			len;
	int			result;
	char		c;

	s = ft_memalloc(100);
	len = 0;
//	result = json_get_char(fd, &s[0]);
	while (((result = json_get_char(&c)) != 0) && (c != '"'))
	{
		s[len] = c;
		len++;
	}
	json_indent();
	printf("%s",s);
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
void		json_get_array()
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

void		json_get_object()
{
	char		c;
	int			result;

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

int			json_print(t_json *js, char * file_name)
{
	int					fd;
//	t_list2				*my_list;
//	t_json_object		*curr;
	char				c;
//	char				**str_buf;
	int					result;

	indent = 0;
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (-1);
	file_size = lseek (fd, 0, SEEK_END);
	lseek (fd, 0, 0);
	buffer = malloc(file_size);
	file_pos = 0;
	result = read(fd, buffer, file_size);
//	my_list = initialisation();
	while ((result = json_get_char(&c)) )
	{
//		curr = malloc(sizeof(t_json_object));
		json_choose_rule(c);
//		curr->next = my_list->first;
//		my_list->first = curr;
	}
//	js = (t_json *) my_list;
	js = NULL;

	return (0);
}
