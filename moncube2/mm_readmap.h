#ifndef					MM_READMAP_H
#define MM_READMAP_H

#include <stdio.h>
#include <unistd.h>
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

#endif
