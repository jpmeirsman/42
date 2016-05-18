#ifndef				MM_JSON_H
#define MM_JSON_H

#include <stdio.h>
#include <unistd.h>
#include <libc.h>
#include "get_next_line.h"
#include "mm_libx.h"

typedef struct			s_json
{
	int					a;
}						t_json;
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

void		json_indent();
void		json_get_object();
void		json_get_boolean(short bl);
//void		json_get_false();
void		json_get_array();
void		json_get_string();
void		json_get_number(char first_digit);
void		json_choose_rule(char c);
int			json_load(t_data *data, char * file_name);

#endif

