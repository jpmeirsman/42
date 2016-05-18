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

void		json_indent();
void		json_get_object();
void		json_get_boolean(short bl);
//void		json_get_false();
void		json_get_array();
void		json_get_string();
void		json_get_number(char first_digit);
void		json_choose_rule(char c);
int			json_print(t_json *js, char * file_name);

#endif

