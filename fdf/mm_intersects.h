#ifndef				MM_INTERSECTS_H
#define MM_INTERSECTS_H

#define			dont_intersect    0
#define			do_intersect      1
#define 		collinear         2


int				lines_intersect(double x1, double y1, double x2, double y2, 
					double x3, double y3, double x4, double y4, double *x, 
					double *y);
#endif

