#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <libc.h>
#include "get_next_line.h"

typedef struct			typefic
{
	long long			nbrows;
	long long			nbcolumns;
	int					**values;
} tfic;

typedef struct			TElementInt
{
	int				value;
	struct TElementInt	*next;
} ElemInt;

