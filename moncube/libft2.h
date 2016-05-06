#ifndef				LIBFT2_H
#define LIBFT2_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "libft/includes/libft.h"

void		reverse(char *str, int len);
int			intToStr(int x, char str[], int d);
void		ftoa(float n, char *res, int afterpoint);
void		reverse2(char s[]);
void		itoa(int n, char s[]);
char		*dtoa(double f, short precision);

#endif

