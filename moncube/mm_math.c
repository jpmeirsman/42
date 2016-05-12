#include "mm_math.h"
#include "mm_basic.h"

t_color4			new_color4(short r, short g, short b, short a)
{
	t_color4		tc;

	tc.r = r;
	tc.g = g;
	tc.b = b;
	tc.a = a;
	return (tc);
}

char				*color4_to_string(t_color4 tc)
{
	char			*s;
	char			buf[4];

	s = (char *) malloc(100);
	memset(s,0,100);
	strcat(s,"{R:");
	itoa(tc.r, buf);
	strcat(s,buf);
	strcat(s," G:");
	itoa(tc.g, buf);
	strcat(s,buf);
	strcat(s," B:");
	itoa(tc.b, buf);
	strcat(s,buf);
	strcat(s," A:");
	itoa(tc.a, buf);
	strcat(s,buf);
	strcat(s,"}");
	return (s);
}

int				color4_to_int(t_color4 tc)
{
	return ((((tc.a * 256) + tc.r) * 256 + tc.g) * 256 + tc.b);
}

t_color4		int_to_color4(int color)
{
	t_color4	tc;
	int			temp;

	tc.b = color % 256;
	color /= 256;
	tc.g = color % 256;
	color /= 256;
	tc.r = color % 256;
	tc.a = color / 256;

	return (tc);
}

t_vector2			new_vector2(double x, double y)
{
	t_vector2		vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

char				*vector2_to_string(t_vector2 tv)
{
	char			*s;
	char			buf[40];

	s = (char *) malloc(100);
	memset(s,0,100);
	strcat(s,"{X:");
	ftoa(tv.x, buf,6);
	strcat(s,buf);
	strcat(s," Y:");
	ftoa(tv.y, buf,6);
	strcat(s,buf);
	strcat(s,"}");
	return (s);
}

t_vector2			add_vector2(t_vector2 myvector, t_vector2 other)
{
	t_vector2		temp;

	temp.x = myvector.x + other.x;
	temp.y = myvector.y + other.y;
	return (temp);
}

t_vector2			subtract_vector2(t_vector2 myvector, t_vector2 other)
{
	t_vector2		temp;

	temp.x = myvector.x - other.x;
	temp.y = myvector.y - other.y;
	return (temp);
}

t_vector2			negate_vector2(t_vector2 myvector)
{
	t_vector2		temp;

	temp.x = -myvector.x;
	temp.y = -myvector.y;
	return (temp);
}

t_vector2			scale_vector2(t_vector2 myvector, double scale)
{
	t_vector2		temp;

	temp.x = myvector.x * scale;
	temp.y = myvector.y * scale;
	return (temp);
}

short				equals_vector2(t_vector2 myvector, t_vector2 other)
{
	if ((myvector.x == other.x) && (myvector.y == other.y))
		return (true);
	return (0);
}

double				length_vector2(t_vector2 myvector)
{
	double			length_vector2;

	length_vector2 = sqrt(myvector.x * myvector.x + myvector.y * myvector.y);
	return (length_vector2);
}

double				len_squared_vector2(t_vector2 myvector)
{
	double			length_vector2;

	length_vector2 = myvector.x * myvector.x + myvector.y * myvector.y;
	return (length_vector2);
}

t_vector2			normalize_vector2(t_vector2 myvector)
{
	t_vector2		temp;
	double			len;
	double			num;

	len = length_vector2(myvector);
	if (len == 0)
		len = 1;
	num = 1 / len;
	temp.x = myvector.x * num;
	temp.y = myvector.y * num;
	return (temp);
}

t_vector2			zero_vector2()
{
	t_vector2		temp;

	temp.x = 0;
	temp.y = 0;
	return (temp);
}

t_vector2			copy_vector2(t_vector2 source)
{
	t_vector2		temp;

	temp.x = source.x;
	temp.y = source.y;
	return (temp);
}

t_vector2			normalize2_vector2(t_vector2 source)
{
	t_vector2		temp;

	temp = copy_vector2(source);
	temp = normalize_vector2(temp);
	return (temp);
}

t_vector2			minimize_vector2(t_vector2 left, t_vector2 right)
{
	t_vector2		temp;

	temp.x = (left.x < right.x) ? left.x : right.x;
	temp.y = (left.y < right.y) ? left.y : right.y;
	return (temp);
}

t_vector2			maximize_vector2(t_vector2 left, t_vector2 right)
{
	t_vector2		temp;

	temp.x = (left.x > right.x) ? left.x : right.x;
	temp.y = (left.y > right.y) ? left.y : right.y;
	return (temp);
}

t_vector2			transform_vector2(t_vector2 vector, t_matrix transform)
{
	t_vector2		temp;

	temp.x = (vector.x * transform.m[0]) + (vector.y * transform.m[4]);
	temp.y = (vector.x * transform.m[1]) + (vector.y * transform.m[5]);
	return temp;
}

double				dist_squared_vector2(t_vector2 value1, t_vector2 value2)
{
//	return (sqrt(dist_squared_vector2(value1, value2)));
	return (sqrt(dist_vector2(value1, value2)));
}

double				dist_vector2(t_vector2 value1, t_vector2 value2)
{
	double			x;
	double			y;

	x = value1.x - value2.x;
	y = value1.y - value2.y;
	return ((x * x) + (y * y));
}

char				*vector3_to_string(t_vector3 tv)
{
	char			*s;
	char			buf[40];

	s = (char *) malloc(100);
	memset(s,0,100);
	strcat(s,"{X:");
	ftoa(tv.x, buf,6);
	strcat(s,buf);
	strcat(s," Y:");
	ftoa(tv.y, buf,6);
	strcat(s,buf);
	strcat(s," Z:");
	ftoa(tv.z, buf,6);
	strcat(s,buf);
	strcat(s,"}");
	return (s);
}

t_vector3			add_vector3(t_vector3 myvector, t_vector3 other)
{
	t_vector3		temp;

	temp.x = myvector.x + other.x;
	temp.y = myvector.y + other.y;
	temp.z = myvector.z + other.z;
	return (temp);
}

t_vector3			subtract_vector3(t_vector3 myvector, t_vector3 other)
{
	t_vector3		temp;

	temp.x = myvector.x - other.x;
	temp.y = myvector.y - other.y;
	temp.z = myvector.z - other.z;
	return (temp);
}

t_vector3			negate_vector3(t_vector3 myvector)
{
	t_vector3		temp;

	temp.x = -myvector.x;
	temp.y = -myvector.y;
	temp.z = -myvector.z;
	return (temp);
}

t_vector3			scale_vector3(t_vector3 myvector, double scale)
{
	t_vector3		temp;

	temp.x = myvector.x * scale;
	temp.y = myvector.y * scale;
	temp.z = myvector.z * scale;
	return (temp);
}

short				equals_vector3(t_vector3 myvector, t_vector3 other)
{
	if ((myvector.x == other.x) && (myvector.y == other.y) &&
			(myvector.z == other.z))
		return (true);
	return (0);
}

t_vector3			multiply_vector3(t_vector3 myvector, t_vector3 other)
{
	t_vector3		temp;

	temp.x = myvector.x * other.x;
	temp.y = myvector.y * other.y;
	temp.z = myvector.z * other.z;
	return (temp);
}

t_vector3			divide_vector3(t_vector3 myvector, t_vector3 other)
{
	t_vector3		temp;

	temp.x = myvector.x / other.x;
	temp.y = myvector.y / other.y;
	temp.z = myvector.z / other.z;
	return (temp);
}

double				length_vector3(t_vector3 myvector)
{
	double			length_vector3;

	length_vector3 = sqrt(myvector.x * myvector.x + myvector.y * myvector.y
		+ myvector.z * myvector.z);
	return (length_vector3);
}

double				len_squared_vector3(t_vector3 myvector)
{
	double			length_vector3;

	length_vector3 = myvector.x * myvector.x + myvector.y * myvector.y 
		+ myvector.z * myvector.z;
	return (length_vector3);
}

t_vector3			normalize_vector3(t_vector3 myvector)
{
	t_vector3		temp;
	double			len;
	double			num;

	len = length_vector3(myvector);
	if (len == 0)
		len = 1;
	num = 1 / len;
	temp.x = myvector.x * num;
	temp.y = myvector.y * num;
	temp.z = myvector.z * num;
	return (temp);
}

t_vector3			from_array_vector3(double *array, long offset)
{
	t_vector3		temp;

	if (!offset)
		offset = 0;
	temp.x = array[offset];
	temp.y = array[offset+1];
	temp.z = array[offset+2];
	return (temp);
}

t_vector3			set_vector3(double X, double Y, double Z)
{
	t_vector3		temp;

	temp.x = X;
	temp.y = Y;
	temp.z = Z;
	return (temp);
}

t_vector3			zero_vector3()
{
	return (set_vector3(0, 0, 0));
}

t_vector3			up_vector3()
{
	return (set_vector3(0, 1.0, 0));
}

t_vector3			copy_vector3(t_vector3 source)
{
	t_vector3		temp;

	temp.x = source.x;
	temp.y = source.y;
	temp.z = source.z;
	return (temp);
}

t_vector3			transform_coord_vector3(t_vector3 vect, t_matrix t)
{
	double			x;
	double			y;
	double			z;
	double			w;
	t_vector3		temp;

	x = (vect.x * t.m[0]) + (vect.y * t.m[4]) + (vect.z * t.m[8]) + t.m[12];
	y = (vect.x * t.m[1]) + (vect.y * t.m[5]) + (vect.z * t.m[9]) + t.m[13];
	z = (vect.x * t.m[2]) + (vect.y * t.m[6]) + (vect.z * t.m[10]) + t.m[14];
	w = (vect.x * t.m[3]) + (vect.y * t.m[7]) + (vect.z * t.m[11]) + t.m[15];
	temp.x = x / w;
	temp.y = y / w;
	temp.z = z / w;
	return (temp);
}

t_vector3			transform_normal_vector3(t_vector3 vector, t_matrix t)
{
	t_vector3		temp;

	temp.x = (vector.x * t.m[0]) + (vector.y * t.m[4]) + (vector.z * t.m[8]);
	temp.y = (vector.x * t.m[1]) + (vector.y * t.m[5]) + (vector.z * t.m[9]);
	temp.z = (vector.x * t.m[2]) + (vector.y * t.m[6]) + (vector.z * t.m[10]);
	return (temp);
}

double				dot_vector3(t_vector3 left, t_vector3 right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

t_vector3			cross_vector3(t_vector3 left, t_vector3 right)
{
	t_vector3		temp;

	temp.x = left.y * right.z - left.z * right.y;
	temp.y = left.z * right.x - left.x * right.z;
	temp.z = left.x * right.y - left.y * right.x;
	return (temp);
}

t_vector3			normalize2_vector3(t_vector3 vector)
{
	t_vector3		temp;

	temp = copy_vector3(vector);
	temp = normalize_vector3(temp);
	return (temp);
}

double				dist_squared_vector3(t_vector3 value1, t_vector3 value2)
{
	return (sqrt(dist_squared_vector3(value1, value2)));
	return (sqrt(dist_vector3(value1, value2)));
}

double				dist_vector3(t_vector3 value1, t_vector3 value2)
{
	double				x;
	double				y;
	double				z;

	x = value1.x - value2.x;
	y = value1.y - value2.y;
	z = value1.z - value2.z;
	return ((x * x) + (y * y) + (z * z));
}
/*
void				put_vector3(t_vector3 *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}
*/
void				put_face(t_face *face, double a, double b, double c)
{
	face->a = a;
	face->b = b;
	face->c = c;
}

t_mesh				*new_mesh(char *name, long long vertCount, long long nbface)
{
	t_mesh			*result;

	result = malloc(sizeof(t_mesh));
	result->name = malloc(strlen(name));
	strcpy(result->name, name);
	result->vertices = (t_vector3 *) malloc(sizeof(t_vector3) * vertCount);
	result->faces = (t_face *) malloc(sizeof(t_face) * nbface);
	result->rotation = zero_vector3();
	result->position = zero_vector3();
	result->length = vertCount;
	return (result);
}

t_meshes			*new_meshes(long long len)
{
	t_meshes	*result;
	long long	i;

	result = malloc(sizeof(t_meshes*) * len);
	result->length = len;
	i = 0;
	while (i < len)
	{
		result->m = malloc(sizeof(t_mesh*) * len);
		i++;
	}
	return result;
}

short				matrix_is_identity(t_matrix matrix)
{
	char			index;

	index = true;
	if ((matrix.m[0] != 1.0) || (matrix.m[5] != 1.0) || (matrix.m[10] != 1.0)
		|| (matrix.m[15] != 1.0))
		return (0);
	if (matrix.m[1] != 0.0 || matrix.m[2] != 0.0 || matrix.m[3] != 0.0 ||
		matrix.m[4] != 0.0 || matrix.m[6] != 0.0 || matrix.m[7] != 0.0 ||
		matrix.m[8] != 0.0 || matrix.m[9] != 0.0 || matrix.m[11] != 0.0 ||
		matrix.m[12] != 0.0 || matrix.m[13] != 0.0 || matrix.m[14] != 0.0)
		return false;
	return (true);
}

double				determinant_matrix(t_matrix matrix)
{
	double			temp1;
	double			temp2;
	double			temp3;
	double			temp4;
	double			temp5;
	double			temp6;

	temp1 = (matrix.m[10] * matrix.m[15]) - (matrix.m[11] * matrix.m[14]);
	temp2 = (matrix.m[9] * matrix.m[15]) - (matrix.m[11] * matrix.m[13]);
	temp3 = (matrix.m[9] * matrix.m[14]) - (matrix.m[10] * matrix.m[13]);
	temp4 = (matrix.m[8] * matrix.m[15]) - (matrix.m[11] * matrix.m[12]);
	temp5 = (matrix.m[8] * matrix.m[14]) - (matrix.m[10] * matrix.m[12]);
	temp6 = (matrix.m[8] * matrix.m[13]) - (matrix.m[9] * matrix.m[12]);
	return ((((matrix.m[0] * (((matrix.m[5] * temp1) - (matrix.m[6] * temp2)) +
		(matrix.m[7] * temp3))) - (matrix.m[1] * (((matrix.m[4] * temp1) -
		(matrix.m[6] * temp4)) + (matrix.m[7] * temp5)))) + (matrix.m[2] *
		(((matrix.m[4] * temp2) - (matrix.m[5] * temp4)) + (matrix.m[7] *
		temp6)))) - (matrix.m[3] * (((matrix.m[4] * temp3) - (matrix.m[5] *
		temp5)) + (matrix.m[6] * temp6))));
}

t_matrix			to_array_matrix(t_matrix matrix)
{
	return (matrix);
}

t_matrix			invert_matrix(t_matrix matrix)
{
	double			l1 = matrix.m[0];
	double			l2 = matrix.m[1];
	double			l3 = matrix.m[2];
	double			l4 = matrix.m[3];
	double			l5 = matrix.m[4];
	double			l6 = matrix.m[5];
	double			l7 = matrix.m[6];
	double			l8 = matrix.m[7];
	double			l9 = matrix.m[8];
	double			l10 = matrix.m[9];
	double			l11 = matrix.m[10];
	double			l12 = matrix.m[11];
	double			l13 = matrix.m[12];
	double			l14 = matrix.m[13];
	double			l15 = matrix.m[14];
	double			l16 = matrix.m[15];
	double			l17 = (l11 * l16) - (l12 * l15);
	double			l18 = (l10 * l16) - (l12 * l14);
	double			l19 = (l10 * l15) - (l11 * l14);
	double			l20 = (l9 * l16) - (l12 * l13);
	double			l21 = (l9 * l15) - (l11 * l13);
	double			l22 = (l9 * l14) - (l10 * l13);
	double			l23 = ((l6 * l17) - (l7 * l18)) + (l8 * l19);
	double			l24 = -(((l5 * l17) - (l7 * l20)) + (l8 * l21));
	double			l25 = ((l5 * l18) - (l6 * l20)) + (l8 * l22);
	double			l26 = -(((l5 * l19) - (l6 * l21)) + (l7 * l22));
	double			l27 = 1.0 / ((((l1 * l23) + (l2 * l24)) + (l3 * l25)) 
							+ (l4 * l26));
	double			l28 = (l7 * l16) - (l8 * l15);
	double			l29 = (l6 * l16) - (l8 * l14);
	double			l30 = (l6 * l15) - (l7 * l14);
	double			l31 = (l5 * l16) - (l8 * l13);
	double			l32 = (l5 * l15) - (l7 * l13);
	double			l33 = (l5 * l14) - (l6 * l13);
	double			l34 = (l7 * l12) - (l8 * l11);
	double			l35 = (l6 * l12) - (l8 * l10);
	double			l36 = (l6 * l11) - (l7 * l10);
	double			l37 = (l5 * l12) - (l8 * l9);
	double			l38 = (l5 * l11) - (l7 * l9);
	double			l39 = (l5 * l10) - (l6 * l9);

	matrix.m[0] = l23 * l27;
	matrix.m[4] = l24 * l27;
	matrix.m[8] = l25 * l27;
	matrix.m[12] = l26 * l27;
	matrix.m[1] = -(((l2 * l17) - (l3 * l18)) + (l4 * l19)) * l27;
	matrix.m[5] = (((l1 * l17) - (l3 * l20)) + (l4 * l21)) * l27;
	matrix.m[9] = -(((l1 * l18) - (l2 * l20)) + (l4 * l22)) * l27;
	matrix.m[13] = (((l1 * l19) - (l2 * l21)) + (l3 * l22)) * l27;
	matrix.m[2] = (((l2 * l28) - (l3 * l29)) + (l4 * l30)) * l27;
	matrix.m[6] = -(((l1 * l28) - (l3 * l31)) + (l4 * l32)) * l27;
	matrix.m[10] = (((l1 * l29) - (l2 * l31)) + (l4 * l33)) * l27;
	matrix.m[14] = -(((l1 * l30) - (l2 * l32)) + (l3 * l33)) * l27;
	matrix.m[3] = -(((l2 * l34) - (l3 * l35)) + (l4 * l36)) * l27;
	matrix.m[7] = (((l1 * l34) - (l3 * l37)) + (l4 * l38)) * l27;
	matrix.m[11] = -(((l1 * l35) - (l2 * l37)) + (l4 * l39)) * l27;
	matrix.m[15] = (((l1 * l36) - (l2 * l38)) + (l3 * l39)) * l27;
	return (matrix);
}

t_matrix			multiply_matrix(t_matrix matrix, t_matrix other)
{
	t_matrix		result;

	result.m[0] = matrix.m[0] * other.m[0] + matrix.m[1] * other.m[4] +
		matrix.m[2] * other.m[8] + matrix.m[3] * other.m[12];
	result.m[1] = matrix.m[0] * other.m[1] + matrix.m[1] * other.m[5] +
		matrix.m[2] * other.m[9] + matrix.m[3] * other.m[13];
	result.m[2] = matrix.m[0] * other.m[2] + matrix.m[1] * other.m[6] +
		matrix.m[2] * other.m[10] + matrix.m[3] * other.m[14];
	result.m[3] = matrix.m[0] * other.m[3] + matrix.m[1] * other.m[7] +
		matrix.m[2] * other.m[11] + matrix.m[3] * other.m[15];
	result.m[4] = matrix.m[4] * other.m[0] + matrix.m[5] * other.m[4] +
		matrix.m[6] * other.m[8] + matrix.m[7] * other.m[12];
	result.m[5] = matrix.m[4] * other.m[1] + matrix.m[5] * other.m[5] +
		matrix.m[6] * other.m[9] + matrix.m[7] * other.m[13];
	result.m[6] = matrix.m[4] * other.m[2] + matrix.m[5] * other.m[6] +
		matrix.m[6] * other.m[10] + matrix.m[7] * other.m[14];
	result.m[7] = matrix.m[4] * other.m[3] + matrix.m[5] * other.m[7] +
		matrix.m[6] * other.m[11] + matrix.m[7] * other.m[15];
	result.m[8] = matrix.m[8] * other.m[0] + matrix.m[9] * other.m[4] +
		matrix.m[10] * other.m[8] + matrix.m[11] * other.m[12];
	result.m[9] = matrix.m[8] * other.m[1] + matrix.m[9] * other.m[5] +
		matrix.m[10] * other.m[9] + matrix.m[11] * other.m[13];
	result.m[10] = matrix.m[8] * other.m[2] + matrix.m[9] * other.m[6] +
		matrix.m[10] * other.m[10] + matrix.m[11] * other.m[14];
	result.m[11] = matrix.m[8] * other.m[3] + matrix.m[9] * other.m[7] +
		matrix.m[10] * other.m[11] + matrix.m[11] * other.m[15];
	result.m[12] = matrix.m[12] * other.m[0] + matrix.m[13] * other.m[4] +
		matrix.m[14] * other.m[8] + matrix.m[15] * other.m[12];
	result.m[13] = matrix.m[12] * other.m[1] + matrix.m[13] * other.m[5] +
		matrix.m[14] * other.m[9] + matrix.m[15] * other.m[13];
	result.m[14] = matrix.m[12] * other.m[2] + matrix.m[13] * other.m[6] +
		matrix.m[14] * other.m[10] + matrix.m[15] * other.m[14];
	result.m[15] = matrix.m[12] * other.m[3] + matrix.m[13] * other.m[7] +
		matrix.m[14] * other.m[11] + matrix.m[15] * other.m[15];
	return (result);
}

int				equals_matrix(t_matrix value, t_matrix matrix)
{
	return (matrix.m[0] == value.m[0] && matrix.m[1] == value.m[1] &&
		matrix.m[2] == value.m[2] && matrix.m[3] == value.m[3] &&
		matrix.m[4] == value.m[4] && matrix.m[5] == value.m[5] &&
		matrix.m[6] == value.m[6] && matrix.m[7] == value.m[7] &&
		matrix.m[8] == value.m[8] && matrix.m[9] == value.m[9] &&
		matrix.m[10] == value.m[10] && matrix.m[11] == value.m[11] &&
		matrix.m[12] == value.m[12] && matrix.m[13] == value.m[13] &&
		matrix.m[14] == value.m[14] && matrix.m[15] == value.m[15]);
}

t_matrix		from_values_matrix(double initialM11, double initialM12,
				double initialM13, double initialM14, double initialM21,
				double initialM22, double initialM23, double initialM24,
				double initialM31, double initialM32, double initialM33,
				double initialM34, double initialM41, double initialM42,
				double initialM43, double initialM44)
{
	t_matrix		result;

	result.m[0] = initialM11;
	result.m[1] = initialM12;
	result.m[2] = initialM13;
	result.m[3] = initialM14;
	result.m[4] = initialM21;
	result.m[5] = initialM22;
	result.m[6] = initialM23;
	result.m[7] = initialM24;
	result.m[8] = initialM31;
	result.m[9] = initialM32;
	result.m[10] = initialM33;
	result.m[11] = initialM34;
	result.m[12] = initialM41;
	result.m[13] = initialM42;
	result.m[14] = initialM43;
	result.m[15] = initialM44;
	return (result);
}

t_matrix		identity_matrix()
{
	return (from_values_matrix(1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0, 0,
		0, 1.0));
}

t_matrix		zero_matrix()
{
	return (from_values_matrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0));
}

t_matrix		copy_matrix(t_matrix source)
{
	return (from_values_matrix(source.m[0], source.m[1], source.m[2],
		source.m[3], source.m[4], source.m[5], source.m[6], source.m[7],
		source.m[8], source.m[9], source.m[10], source.m[11], source.m[12],
		source.m[13], source.m[14], source.m[15]));
}

t_matrix		rot_x_matrix(double angle)
{
	t_matrix	result;
	double		c;
	double		s;

	result = zero_matrix();
	s = sin(angle);
	c = cos(angle);
	result.m[0] = 1.0;
	result.m[15] = 1.0;
	result.m[5] = c;
	result.m[10] = c;
	result.m[9] = -s;
	result.m[6] = s;
	return (result);
}

t_matrix		rot_y_matrix(double angle)
{
	t_matrix	result;
	double		c;
	double		s;

	result = zero_matrix();
	s = sin(angle);
	c = cos(angle);
	result.m[5] = 1.0;
	result.m[15] = 1.0;
	result.m[0] = c;
	result.m[2] = -s;
	result.m[8] = s;
	result.m[10] = c;
	return (result);
}

t_matrix		rot_z_matrix(double angle)
{
	t_matrix	result;
	double		c;
	double		s;

	result = zero_matrix();
	s = sin(angle);
	c = cos(angle);
	result.m[10] = 1.0;
	result.m[15] = 1.0;
	result.m[0] = c;
	result.m[1] = s;
	result.m[4] = -s;
	result.m[5] = c;
	return (result);
}

t_matrix		rot_axis_matatrix(t_vector3 axis, double angle)
{
	t_matrix	result;
	double		s;
	double		c;
	double		c1;

	s = sin(-angle);
	c = cos(-angle);
	c1 = 1 - c;
	axis = normalize_vector3(axis);
	result = zero_matrix();
	result.m[0] = (axis.x * axis.x) * c1 + c;
	result.m[1] = (axis.x * axis.y) * c1 - (axis.z * s);
	result.m[2] = (axis.x * axis.z) * c1 + (axis.y * s);
	result.m[3] = 0.0;
	result.m[4] = (axis.y * axis.x) * c1 + (axis.z * s);
	result.m[5] = (axis.y * axis.y) * c1 + c;
	result.m[6] = (axis.y * axis.z) * c1 - (axis.x * s);
	result.m[7] = 0.0;
	result.m[8] = (axis.z * axis.x) * c1 - (axis.y * s);
	result.m[9] = (axis.z * axis.y) * c1 + (axis.x * s);
	result.m[10] = (axis.z * axis.z) * c1 + c;
	result.m[11] = 0.0;
	result.m[15] = 1.0;
	return result;
}

t_matrix		rot_yaw_pitch_roll_matrix(double y, double p, double r)
{
	t_matrix	result;

	result = multiply_matrix(multiply_matrix(rot_z_matrix(r), rot_x_matrix(p)),
		rot_y_matrix(y));
	return (result);
}

t_matrix		scaling_matrix(double x, double y, double z)
{
	t_matrix	result;

	result = zero_matrix();
	result.m[0] = x;
	result.m[5] = y;
	result.m[10] = z;
	result.m[15] = 1.0;
	return (result);
}

t_matrix		translation_matrix(double x, double y, double z)
{
	t_matrix	result;

	result = identity_matrix();
	result.m[12] = x;
	result.m[13] = y;
	result.m[14] = z;
	return (result);
}

t_matrix		look_at_lh_matrix(t_vector3 eye, t_vector3 targt, t_vector3 up)
{
	t_vector3	xaxis;
	t_vector3	yaxis;
	t_vector3	zaxis;
	double		ex;
	double		ey;
	double		ez;

	zaxis = subtract_vector3(targt, eye);
	zaxis = normalize_vector3(zaxis);
	xaxis = cross_vector3(up, zaxis);
	xaxis = normalize_vector3(xaxis);
	yaxis = cross_vector3(zaxis, xaxis);
	yaxis = normalize_vector3(yaxis);
	ex = -dot_vector3(xaxis, eye);
	ey = -dot_vector3(yaxis, eye);
	ez = -dot_vector3(zaxis, eye);
	return (from_values_matrix(xaxis.x, yaxis.x, zaxis.x, 0, xaxis.y, yaxis.y,
		zaxis.y, 0, xaxis.z, yaxis.z, zaxis.z, 0, ex, ey, ez, 1));
}

t_matrix		perspective_lh_matrix(double width, double height, 
				double znear, double zfar)
{
	t_matrix	matrix;

	matrix = zero_matrix();
	matrix.m[0] = (2.0 * znear) / width;
	matrix.m[1] = matrix.m[2] = matrix.m[3] = 0.0;
	matrix.m[5] = (2.0 * znear) / height;
	matrix.m[4] = matrix.m[6] = matrix.m[7] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[8] = matrix.m[9] = 0.0;
	matrix.m[11] = 1.0;
	matrix.m[12] = matrix.m[13] = matrix.m[15] = 0.0;
	matrix.m[14] = (znear * zfar) / (znear - zfar);
	return (matrix);
}

t_matrix		perspective_fov_lh_matrix(double fov, double aspect, double znear, double zfar)
{
	t_matrix	matrix;
	double		tang;

	matrix = zero_matrix();
	tang = 1.0 / (tan(fov * 0.5));
	matrix.m[0] = tang / aspect;
	matrix.m[1] = matrix.m[2] = matrix.m[3] = 0.0;
	matrix.m[5] = tang;
	matrix.m[4] = matrix.m[6] = matrix.m[7] = 0.0;
	matrix.m[8] = matrix.m[9] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[11] = 1.0;
	matrix.m[12] = matrix.m[13] = matrix.m[15] = 0.0;
	matrix.m[14] = (znear * zfar) / (znear - zfar);
	return (matrix);
}

t_matrix		transpose_matrix(t_matrix matrix)
{
	t_matrix	result;

	result.m[0] = matrix.m[0];
	result.m[1] = matrix.m[4];
	result.m[2] = matrix.m[8];
	result.m[3] = matrix.m[12];
	result.m[4] = matrix.m[1];
	result.m[5] = matrix.m[5];
	result.m[6] = matrix.m[9];
	result.m[7] = matrix.m[13];
	result.m[8] = matrix.m[2];
	result.m[9] = matrix.m[6];
	result.m[10] = matrix.m[10];
	result.m[11] = matrix.m[14];
	result.m[12] = matrix.m[3];
	result.m[13] = matrix.m[7];
	result.m[14] = matrix.m[11];
	result.m[15] = matrix.m[15];
	return (result);
}

int				matrix_mult(int n, int m, int p, void *m1, void *m2, void *m3)
{
	int			i;
	int			j;
	int			k;
	double		(*mat1) [n][m];
	double		(*mat2) [m][p];
	double		(*matres) [n][p];

	mat1 = m1;
	mat2 = m2;
	matres = m3;
	for (i = 0; i < n; i++)
		for (j = 0; j < p; j++)
			matres[0][i][j] = 0;
	for (i = 0; i < n; i++)
		for ( j = 0; j < p; j++)
			for (k = 0; k < m; k++)
				matres[0][i][j] = mat1[0][i][k] * mat2[0][k][j] + 
					matres[0][i][j];
	return (0);
}

void			print_matrix(t_matrix m)
{
	short		i;

	i = 0;
	while (i < 16)
	{
		printf("m[%d] = %le\t", i, m.m[i]);
		if (i % 4 == 3)
			printf("\n");
		i++;
	}
}

void			print_vector3(t_vector3 tv)
{
	printf("x: %le, y:%le, z:%le\n", tv.x, tv.y, tv.z);
}


