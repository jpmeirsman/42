#include "mm_intersects.h"
#include <stdio.h>

int same_signs(double a, double b)
{
	if ((a * b) >= 0)
		return (1);
	return (0);
}

int			lines_intersect(double x1, double y1, double x2, double y2, 
				double x3, double y3, double x4, double y4,
				double *x, double *y)
{
	double	a1;
	double	a2;
	double	b1;
	double	b2;
	double	c1;
	double	c2;
	double	r1;
	double	r2;
	double	r3;
	double	r4;
	double	denom;
	double	offset;
	double	num;

	a1 = y2 - y1;
	b1 = x1 - x2;
	c1 = x2 * y1 - x1 * y2;
	r3 = a1 * x3 + b1 * y3 + c1;
	r4 = a1 * x4 + b1 * y4 + c1;
	if (r3 != 0 && r4 != 0 && same_signs(r3, r4))
		return ( dont_intersect );
	a2 = y4 - y3;
	b2 = x3 - x4;
	c2 = x4 * y3 - x3 * y4;
	r1 = a2 * x1 + b2 * y1 + c2;
	r2 = a2 * x2 + b2 * y2 + c2;
	denom = a1 * b2 - a2 * b1;
	if ((((r1 != 0) && (r2 != 0)) && (same_signs( r1, r2))) || ((denom == 0) &&
		((((x3 > x1) && (x3 > x2)) || ((x3 < x1) && (x3 < x2))) ||
		(((y3 > y1) && (y3 > y2)) || ((y3 < y1) && (y3 < y2))))))
			return (dont_intersect);
	if ( denom == 0 )
		return (collinear);
	offset = denom < 0 ? - denom / 2 : denom / 2;
	num = b1 * c2 - b2 * c1;
	*x = ( num < 0 ? num - offset : num + offset ) / denom;
	num = a2 * c1 - a1 * c2;
	*y = ( num < 0 ? num - offset : num + offset ) / denom;
	return (do_intersect);
}

/*

Si les 2 points sont dans le canvas
	on utilise la procédure standard
	sinon 
	on intersect les 2 points avec les 4 côtés du canvas jusqu'à ce que l'on 
		trouve une intersection ou collinéarité
	s'il n'y a aucune intersection 
		on ne dessine pas
		sinon
		si les deux points son collinéaires
			on limite les valeurs de x et y à celles min et max du canvas et on dessine ; l'astuce est que le calcul se fait sur est un pixel plus grand et large que le vrai canvas donc on n'a pas besoin de dessiner
			sinon
			un des point se trouve dans le canvas et l'autre point intersecte
			on trace un trait entre celui dans le canvas et celui qui intersecte

*/
/*
int		main(void)
{
	double x1, x2, x3, x4, y1, y2, y3, y4;
	double  x, y;

		x1 = 2;
		y1 = 5;
		x2 = 5;
		y2 = 4;

		x3 = 3;
		y3 = 6;
		x4 = 3;
		y4 = 2;

		switch ( lines_intersect( x1, y1, x2, y2, x3, y3, x4, y4, &x, &y )) {
			case dont_intersect:
				printf( "Lines don't intersect\n" );
				break;
			case collinear:
				printf( "Lines are collinear\n" );
				break;
			case do_intersect:
				printf( "Lines intersect at %le,%le\n", x, y );
				break;
		}
	return (0);
}
*/

