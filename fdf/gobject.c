#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "itoa.c"
#include "math.c"
#include "ftoa.c"

typedef struct typeVector3
{
	double			x;
	double			y;
	double			z;
} tVector3;

typedef struct typeVector2
{
	double			x;
	double			y;
} tVector2;

typedef struct typeface
{
	double			A;
	double			B;
	double			C;
} tfaces;

typedef struct typematrix
{
	double			m[16];
} tmatrix;

typedef struct typemesh
{
	char			*name;
	tVector3		*vertices;
	tfaces			*faces;
	tVector3		Rotation;
	tVector3		Position;
	long long		length;
} tmesh;

typedef struct		typetabmesh
{
	long long		length;
	tmesh			*m;
} tabmesh;

typedef struct typecamera
{
	tVector3		Position;
	tVector3		Target;
} tcam;

typedef struct typecanvas
{
	long		width;
	long		height;
	char		*context;
} tcanvas;

typedef struct typedevice
{
	tcanvas		workingCanvas;
	double		workingWidth;
	double		workingHeight;
	char		*workingContext;
} tdevice;

typedef struct typecolor4
{
	short		r;
	short		g;
	short		b;
	short		a;
} tcolor4;

int	canvaslength;
int canvasheight;

tcolor4	newColor4(short R, short G, short B, short A)
{
	tcolor4	tc;

	tc.r = R;
	tc.g = G;
	tc.b = B;
	tc.a = A;
	return (tc);
}

char		*color4toString(tcolor4 tc)
{
	char		*s;
	char		buf[4];

	s = malloc(100);
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

tVector2	newVector2(double X, double Y)
{
	tVector2	Vector2;

	Vector2.x = X;
	Vector2.y = Y;
	return (Vector2);
}
char		*Vector2toString(tVector2 tv)
{
	char		*s;
	char		buf[40];

	s = malloc(100);
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

tVector2	addVector2(tVector2 myVector, tVector2 other)
{
	tVector2	temp;

	temp.x = myVector.x + other.x;
	temp.y = myVector.y + other.y;
	return (temp);
}

tVector2	subtractVector2(tVector2 myVector, tVector2 other)
{
	tVector2	temp;

	temp.x = myVector.x - other.x;
	temp.y = myVector.y - other.y;
	return (temp);
}

tVector2	negateVector2(tVector2 myVector)
{
	tVector2	temp;

	temp.x = -myVector.x;
	temp.y = -myVector.y;
	return (temp);
}

tVector2	scaleVector2(tVector2 myVector, double scale)
{
	tVector2	temp;

	temp.x = myVector.x * scale;
	temp.y = myVector.y * scale;
	return (temp);
}

bool		equalsVector2(tVector2 myVector, tVector2 other)
{
	bool	test;

	if ((myVector.x == other.x) && (myVector.y == other.y))
		return (true);
	return (false);
}

double	lengthVector2(tVector2 myVector)
{
	double	lengthVector2;

	lengthVector2 = sqrt(myVector.x * myVector.x + myVector.y 
			* myVector.y);
	return (lengthVector2);
}

double	lengthSquaredVector2(tVector2 myVector)
{
	double	lengthVector2;

	lengthVector2 = myVector.x * myVector.x + myVector.y 
		* myVector.y;
	return (lengthVector2);
}

tVector2	normalizeVector2(tVector2 myVector)
{
	tVector2	temp;
	double		len;
	double		num;

	len = lengthVector2(myVector);
	if (len == 0)
		len = 1;
	num = 1 / len;
	temp.x = myVector.x * num;
	temp.y = myVector.y * num;
	return (temp);
}

tVector2	zeroVector2()
{
	tVector2	temp;

	temp.x = 0;
	temp.y = 0;
	return (temp);
}

tVector2	CopyVector2(tVector2 source)
{
	tVector2	temp;

	temp.x = source.x;
	temp.y = source.y;
	return (temp);
}

tVector2	NormalizeVector2(tVector2 source)
{
	tVector2	temp;

	temp = CopyVector2(source);
	temp = normalizeVector2(temp);
	return (temp);
}

tVector2	MinimizeVector2(tVector2 left, tVector2 right)
{
	tVector2	temp;

	temp.x = (left.x < right.x) ? left.x : right.x;
	temp.y = (left.y < right.y) ? left.y : right.y;
	return (temp);
}

tVector2	MaximizeVector2(tVector2 left, tVector2 right)
{
	tVector2	temp;

	temp.x = (left.x > right.x) ? left.x : right.x;
	temp.y = (left.y > right.y) ? left.y : right.y;
	return (temp);
}

tVector2	TransformVector2(tVector2 vector, tmatrix transformation)
{
	tVector2	temp;

	temp.x = (vector.x * transformation.m[0]) + (vector.y * transformation.m[4]);
	temp.y = (vector.x * transformation.m[1]) + (vector.y * transformation.m[5]);
	return temp;
}

double		DistanceSquaredVector2(tVector2 value1, tVector2 value2)
{
	return (sqrt(DistanceSquaredVector2(value1, value2)));
}

double		DistanceVector2(tVector2 value1, tVector2 value2)
{
	double		x;
	double		y;

	x = value1.x - value2.x;
	y = value1.y - value2.y;
	return ((x * x) + (y * y));
}

char		*Vector3toString(tVector3 tv)
{
	char		*s;
	char		buf[40];

	s = malloc(100);
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

tVector3	addVector3(tVector3 myVector, tVector3 other)
{
	tVector3	temp;

	temp.x = myVector.x + other.x;
	temp.y = myVector.y + other.y;
	temp.z = myVector.z + other.z;
	return (temp);
}

tVector3	subtractVector3(tVector3 myVector, tVector3 other)
{
	tVector3	temp;

	temp.x = myVector.x - other.x;
	temp.y = myVector.y - other.y;
	temp.z = myVector.z - other.z;
	return (temp);
}

tVector3	negateVector3(tVector3 myVector)
{
	tVector3	temp;

	temp.x = -myVector.x;
	temp.y = -myVector.y;
	temp.z = -myVector.z;
	return (temp);
}

tVector3	scaleVector3(tVector3 myVector, double scale)
{
	tVector3	temp;

	temp.x = myVector.x * scale;
	temp.y = myVector.y * scale;
	temp.z = myVector.z * scale;
	return (temp);
}

bool		equalsVector3(tVector3 myVector, tVector3 other)
{
	bool	test;

	if ((myVector.x == other.x) && (myVector.y == other.y) &&
			(myVector.z == other.z))
		return (true);
	return (false);
}

tVector3	multiplyVector3(tVector3 myVector, tVector3 other)
{
	tVector3	temp;

	temp.x = myVector.x * other.x;
	temp.y = myVector.y * other.y;
	temp.z = myVector.z * other.z;
	return (temp);
}

tVector3	divideVector3(tVector3 myVector, tVector3 other)
{
	tVector3	temp;

	temp.x = myVector.x / other.x;
	temp.y = myVector.y / other.y;
	temp.z = myVector.z / other.z;
	return (temp);
}

double	lengthVector3(tVector3 myVector)
{
	double	lengthVector3;

	lengthVector3 = sqrt(myVector.x * myVector.x + myVector.y		* myVector.y + myVector.z * myVector.z);
	return (lengthVector3);
}

double	lengthSquaredVector3(tVector3 myVector)
{
	double	lengthVector3;

	lengthVector3 = myVector.x * myVector.x + myVector.y		* myVector.y + myVector.z * myVector.z;
	return (lengthVector3);
}

tVector3	normalizeVector3(tVector3 myVector)
{
	tVector3	temp;
	double		len;
	double		num;

	len = lengthVector3(myVector);
	if (len == 0)
		len = 1;
	num = 1 / len;
	temp.x = myVector.x * num;
	temp.y = myVector.y * num;
	temp.z = myVector.z * num;
	return (temp);
}

tVector3	FromArrayVector3(double *array, long offset)
{
	tVector3	temp;
	double		a;
	double		b;
	double		c;

	if (!offset)
		offset = 0;
	temp.x = array[offset];
	temp.y = array[offset+1];
	temp.z = array[offset+2];
	return (temp);
}

tVector3	setVector3(double X, double Y, double Z)
{
	tVector3	temp;

	temp.x = X;
	temp.y = Y;
	temp.z = Z;
	return (temp);
}

tVector3	ZeroVector3()
{
	return (setVector3(0, 0, 0));
}

tVector3	UpVector3()
{
	return (setVector3(0, 1.0, 0));
}

tVector3	CopyVector3(tVector3 source)
{
	tVector3	temp;

	temp.x = source.x;
	temp.y = source.y;
	temp.z = source.z;
	return (temp);
}

tVector3	TransformCoordinatesVector3(tVector3 vector, tmatrix transformation)
{
	double		x;
	double		y;
	double		z;
	double		w;
	tVector3	temp;

	x = (vector.x * transformation.m[0]) + (vector.y * transformation.m[4]		) + (vector.z * transformation.m[8]) + transformation.m[12];
	y = (vector.x * transformation.m[1]) + (vector.y * transformation.m[5]		) + (vector.z * transformation.m[9]) + transformation.m[13];
	z = (vector.x * transformation.m[2]) + (vector.y * transformation.m[6]		) + (vector.z * transformation.m[10]) + transformation.m[14];
	w = (vector.x * transformation.m[3]) + (vector.y * transformation.m[7]		) + (vector.z * transformation.m[11]) + transformation.m[15];
	temp.x = x / w;
	temp.y = y / w;
	temp.z = z / w;
	return (temp);
}

tVector3	TransformNormalVector3(tVector3 vector, tmatrix transformation)
{
	tVector3	temp;

	temp.x = (vector.x * transformation.m[0]) + (vector.y * 
			transformation.m[4]) + (vector.z * transformation.m[8]);
	temp.y = (vector.x * transformation.m[1]) + (vector.y * 
			transformation.m[5]) + (vector.z * transformation.m[9]);
	temp.z = (vector.x * transformation.m[2]) + (vector.y * 
			transformation.m[6]) + (vector.z * transformation.m[10]);
	return (temp);
}

double		DotVector3(tVector3 left, tVector3 right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

tVector3	CrossVector3(tVector3 left, tVector3 right)
{
	tVector3	temp;

	temp.x = left.y * right.z - left.z * right.y;
	temp.y = left.z * right.x - left.x * right.z;
	temp.z = left.x * right.y - left.y * right.x;
	return (temp);
}

tVector3	NormalizeVector3(tVector3 vector)
{
	tVector3	temp;

	temp = CopyVector3(vector);
	temp = normalizeVector3(temp);
	return (temp);
}

double		DistanceSquaredVector3(tVector3 value1, tVector3 value2)
{
	return (sqrt(DistanceSquaredVector3(value1, value2)));
}

double		DistanceVector3(tVector3 value1, tVector3 value2)
{
	double		x;
	double		y;
	double		z;

	x = value1.x - value2.x;
	y = value1.y - value2.y;
	z = value1.z - value2.z;
	return ((x * x) + (y * y) + (z * z));
}

void		putVector3(tVector3 *Vector3, double x, double y, double z)
{
	Vector3->x = x;
	Vector3->y = y;
	Vector3->z = z;
}

void		putface(tfaces *face, double A, double B, double C)
{
	face->A = A;
	face->B = B;
	face->C = C;
}

tcam		newCam()
{
	tcam		result;

	result.Position = ZeroVector3();
	result.Target = ZeroVector3();
	return (result);
}

tcam		setCam(long posx, long posy, long posz, long targetx, long targety, long targetz)
{
	tcam	camera;

	camera.Position.x = posx;
	camera.Position.y = posy;
	camera.Position.z = posz;
	camera.Target.x = targetx;
	camera.Target.y = targety;
	camera.Target.z = targetz;
	return (camera);
}

tmesh		newMesh(char *name, long long verticesCount)
{
	tmesh	result;

	strcpy(result.name, name);
	result.vertices = malloc(sizeof(tVector3) * verticesCount);
	result.Rotation = ZeroVector3();
	result.Position = ZeroVector3();
	result.length = verticesCount;
	return (result);
}

tmesh		newmesh(char *name, long long verticesCount, long long nbfaces)
{
	tmesh		result;

	result.name = malloc(strlen(name));
	strcpy(result.name, name);
	result.vertices = malloc(sizeof(tVector3) * verticesCount);
	result.faces = malloc(sizeof(tfaces) * nbfaces);
	result.length = verticesCount;
	return (result);
}

tdevice		setDevice(tcanvas canvas)
{
	tdevice		result;

	result.workingCanvas = canvas;
	result.workingWidth = canvas.width;
	result.workingHeight = canvas.height;
	//A implémenter si besoin
	//	result.workingContext = getContextCanvas(result.workingContext"2d");
	return (result);
}

void		clearDevice(tdevice *device)
{
	/*
	   device
	   this.workingContext.clearRect(0, 0, this.workingWidth, this.workingHeight);
	   this.backbuffer = this.workingContext.getImageData(0, 0, this.workingWidth, this.workingHeight);
	   */
}

void		presentDevice(tdevice device)
{
	//	device.workingContext.putImageData(this.backbuffer, 0, 0);
}

void		putPixel(tdevice *device, long x, long y, tcolor4 color)
{
	/*
	   this.backbufferdata = this.backbuffer.data;
	   var index = ((x >> 0) + (y >> 0) * this.workingWidth) * 4;
	   this.backbufferdata[index] = color.r * 255;
	   this.backbufferdata[index + 1] = color.g * 255;
	   this.backbufferdata[index + 2] = color.b * 255;
	   this.backbufferdata[index + 3] = color.a * 255;
	   */
}

tVector2	projectDevice(tdevice device, tVector3 coord, tmatrix transMat)
{
	tVector3	point;
	double		x;
	double		y;

	point = TransformCoordinatesVector3(coord, transMat);
	//	x = round((point.x * device.workingWidth) + (device.workingWidth / 2.0)) >> 0;
	x = round((point.x * device.workingWidth) + (device.workingWidth / 2.0));
	y = round((point.y * device.workingHeight) + (device.workingHeight / 2.0));
	return (newVector2(x, y));
}

void		drawPointDevice(tdevice device, tVector2 point)
{
	if(point.x >= 0 && point.y >= 0 && point.x < device.workingWidth && point.y < device.workingHeight) {
		putPixel(&device, point.x, point.y, newColor4(1, 1, 0, 1));
	}
}

tmesh		newcube(char *name)
{
	tmesh		mycube;
	mycube = newmesh(name, 8, 12);
	putVector3(&mycube.vertices[0], -1,  1,  1);
	putVector3(&mycube.vertices[1],  1,  1,  1);
	putVector3(&mycube.vertices[2], -1, -1,  1);
	putVector3(&mycube.vertices[3],  1, -1,  1);
	putVector3(&mycube.vertices[4], -1,  1, -1);
	putVector3(&mycube.vertices[5],  1,  1, -1);
	putVector3(&mycube.vertices[6],  1, -1, -1);
	putVector3(&mycube.vertices[7], -1, -1, -1);
	putface(&mycube.faces[0],  0, 1, 2);
	putface(&mycube.faces[1],  1, 2, 3);
	putface(&mycube.faces[2],  1, 3, 6);
	putface(&mycube.faces[3],  1, 5, 6);
	putface(&mycube.faces[4],  0, 1, 4);
	putface(&mycube.faces[5],  1, 4, 5);
	putface(&mycube.faces[6],  2, 3, 7);
	putface(&mycube.faces[7],  3, 6, 7);
	putface(&mycube.faces[8],  0, 2, 7);
	putface(&mycube.faces[9],  0, 4, 7);
	putface(&mycube.faces[10], 4, 5, 6);
	putface(&mycube.faces[11], 4, 6, 7);
	return mycube;
}

void		printcube(tmesh *mycube)
{
	printf("Nom du cube : %s\n",mycube->name);
	for(int i = 0 ; i < 8; i++)
		printf("Vertex n° %d : x=%f, y=%f, z=%f\n",i,mycube->vertices[i].x,
				mycube->vertices[i].y,mycube->vertices[i].z);
	for(int i = 0 ; i < 12; i++)
		printf("Face n° %d : A=%f, B=%f, C=%f\n",i,mycube->faces[i].A,
				mycube->faces[i].B,mycube->faces[i].C);
}

bool		MatrixisIdentity(tmatrix matrix)
{
	char	index;

	index = true;
	if ((matrix.m[0] != 1.0) || (matrix.m[5] != 1.0) || 
			(matrix.m[10] != 1.0) || (matrix.m[15] != 1.0))
		return (false);
	if (matrix.m[1] != 0.0 || matrix.m[2] != 0.0 || matrix.m[3] != 0.0 || matrix.m[4] != 0.0 || matrix.m[6] != 0.0 || matrix.m[7] != 0.0 || matrix.m[8] != 0.0 || matrix.m[9] != 0.0 || matrix.m[11] != 0.0 || matrix.m[12] != 0.0 || matrix.m[13] != 0.0 || matrix.m[14] != 0.0 )
		return false;
	return (true);
}

double		determinantMatrix(tmatrix matrix)
{
	double temp1;
	double temp2;
	double temp3;
	double temp4;
	double temp5;
	double temp6;

	temp1 = (matrix.m[10] * matrix.m[15]) - (matrix.m[11] * matrix.m[14]);
	temp2 = (matrix.m[9] * matrix.m[15]) - (matrix.m[11] * matrix.m[13]);
	temp3 = (matrix.m[9] * matrix.m[14]) - (matrix.m[10] * matrix.m[13]);
	temp4 = (matrix.m[8] * matrix.m[15]) - (matrix.m[11] * matrix.m[12]);
	temp5 = (matrix.m[8] * matrix.m[14]) - (matrix.m[10] * matrix.m[12]);
	temp6 = (matrix.m[8] * matrix.m[13]) - (matrix.m[9] * matrix.m[12]);
	return ((((matrix.m[0] * (((matrix.m[5] * temp1) - (matrix.m[6] * temp2)) 
							+ (matrix.m[7] * temp3))) - (matrix.m[1] * (((matrix.m[4] * temp1)
								- (matrix.m[6] * temp4)) + (matrix.m[7] * temp5)))) + (matrix.m[2]
					* (((matrix.m[4] * temp2) - (matrix.m[5] * temp4)) + (matrix.m[7]
							* temp6)))) - (matrix.m[3] * (((matrix.m[4] * temp3)
							* - (matrix.m[5] * temp5)) + (matrix.m[6] * temp6))));
}

tmatrix		toArrayMatrix(tmatrix matrix)
{
	return (matrix);
}

tmatrix		invertMatrix(tmatrix matrix)
{
	double l1 = matrix.m[0];
	double l2 = matrix.m[1];
	double l3 = matrix.m[2];
	double l4 = matrix.m[3];
	double l5 = matrix.m[4];
	double l6 = matrix.m[5];
	double l7 = matrix.m[6];
	double l8 = matrix.m[7];
	double l9 = matrix.m[8];
	double l10 = matrix.m[9];
	double l11 = matrix.m[10];
	double l12 = matrix.m[11];
	double l13 = matrix.m[12];
	double l14 = matrix.m[13];
	double l15 = matrix.m[14];
	double l16 = matrix.m[15];
	double l17 = (l11 * l16) - (l12 * l15);
	double l18 = (l10 * l16) - (l12 * l14);
	double l19 = (l10 * l15) - (l11 * l14);
	double l20 = (l9 * l16) - (l12 * l13);
	double l21 = (l9 * l15) - (l11 * l13);
	double l22 = (l9 * l14) - (l10 * l13);
	double l23 = ((l6 * l17) - (l7 * l18)) + (l8 * l19);
	double l24 = -(((l5 * l17) - (l7 * l20)) + (l8 * l21));
	double l25 = ((l5 * l18) - (l6 * l20)) + (l8 * l22);
	double l26 = -(((l5 * l19) - (l6 * l21)) + (l7 * l22));
	double l27 = 1.0 / ((((l1 * l23) + (l2 * l24)) + (l3 * l25)) + (l4 * l26));
	double l28 = (l7 * l16) - (l8 * l15);
	double l29 = (l6 * l16) - (l8 * l14);
	double l30 = (l6 * l15) - (l7 * l14);
	double l31 = (l5 * l16) - (l8 * l13);
	double l32 = (l5 * l15) - (l7 * l13);
	double l33 = (l5 * l14) - (l6 * l13);
	double l34 = (l7 * l12) - (l8 * l11);
	double l35 = (l6 * l12) - (l8 * l10);
	double l36 = (l6 * l11) - (l7 * l10);
	double l37 = (l5 * l12) - (l8 * l9);
	double l38 = (l5 * l11) - (l7 * l9);
	double l39 = (l5 * l10) - (l6 * l9);
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

tmatrix		multiplyMatrix(tmatrix matrix, tmatrix other)
{
	tmatrix		result;

	result.m[0] = matrix.m[0] * other.m[0] + matrix.m[1] * other.m[4] + matrix.m[2] * other.m[8] + matrix.m[3] * other.m[12];
	result.m[1] = matrix.m[0] * other.m[1] + matrix.m[1] * other.m[5] + matrix.m[2] * other.m[9] + matrix.m[3] * other.m[13];
	result.m[2] = matrix.m[0] * other.m[2] + matrix.m[1] * other.m[6] + matrix.m[2] * other.m[10] + matrix.m[3] * other.m[14];
	result.m[3] = matrix.m[0] * other.m[3] + matrix.m[1] * other.m[7] + matrix.m[2] * other.m[11] + matrix.m[3] * other.m[15];
	result.m[4] = matrix.m[4] * other.m[0] + matrix.m[5] * other.m[4] + matrix.m[6] * other.m[8] + matrix.m[7] * other.m[12];
	result.m[5] = matrix.m[4] * other.m[1] + matrix.m[5] * other.m[5] + matrix.m[6] * other.m[9] + matrix.m[7] * other.m[13];
	result.m[6] = matrix.m[4] * other.m[2] + matrix.m[5] * other.m[6] + matrix.m[6] * other.m[10] + matrix.m[7] * other.m[14];
	result.m[7] = matrix.m[4] * other.m[3] + matrix.m[5] * other.m[7] + matrix.m[6] * other.m[11] + matrix.m[7] * other.m[15];
	result.m[8] = matrix.m[8] * other.m[0] + matrix.m[9] * other.m[4] + matrix.m[10] * other.m[8] + matrix.m[11] * other.m[12];
	result.m[9] = matrix.m[8] * other.m[1] + matrix.m[9] * other.m[5] + matrix.m[10] * other.m[9] + matrix.m[11] * other.m[13];
	result.m[10] = matrix.m[8] * other.m[2] + matrix.m[9] * other.m[6] + matrix.m[10] * other.m[10] + matrix.m[11] * other.m[14];
	result.m[11] = matrix.m[8] * other.m[3] + matrix.m[9] * other.m[7] + matrix.m[10] * other.m[11] + matrix.m[11] * other.m[15];
	result.m[12] = matrix.m[12] * other.m[0] + matrix.m[13] * other.m[4] + matrix.m[14] * other.m[8] + matrix.m[15] * other.m[12];
	result.m[13] = matrix.m[12] * other.m[1] + matrix.m[13] * other.m[5] + matrix.m[14] * other.m[9] + matrix.m[15] * other.m[13];
	result.m[14] = matrix.m[12] * other.m[2] + matrix.m[13] * other.m[6] + matrix.m[14] * other.m[10] + matrix.m[15] * other.m[14];
	result.m[15] = matrix.m[12] * other.m[3] + matrix.m[13] * other.m[7] + matrix.m[14] * other.m[11] + matrix.m[15] * other.m[15];
	return (result);
}

int			equalsMatrix(tmatrix value, tmatrix matrix)
{
	return (matrix.m[0] == value.m[0] && matrix.m[1] == value.m[1] && matrix.m[2] == value.m[2] && matrix.m[3] == value.m[3] && matrix.m[4] == value.m[4] && matrix.m[5] == value.m[5] && matrix.m[6] == value.m[6] && matrix.m[7] == value.m[7] && matrix.m[8] == value.m[8] && matrix.m[9] == value.m[9] && matrix.m[10] == value.m[10] && matrix.m[11] == value.m[11] && matrix.m[12] == value.m[12] && matrix.m[13] == value.m[13] && matrix.m[14] == value.m[14] && matrix.m[15] == value.m[15]);
}

tmatrix		FromValuesMatrix(double initialM11, double initialM12, double initialM13, double initialM14, double initialM21, double initialM22, double initialM23, double initialM24, double initialM31, double initialM32, double initialM33, double initialM34, double initialM41, double initialM42, double initialM43, double initialM44)
{
	tmatrix		result;

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

tmatrix		IdentityMatrix()
{
	return (FromValuesMatrix(1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0));
}

tmatrix		ZeroMatrix()
{
	return (FromValuesMatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
}

tmatrix		CopyMatrix(tmatrix source)
{
	return (FromValuesMatrix(source.m[0], source.m[1], source.m[2], source.m[3], source.m[4], source.m[5], source.m[6], source.m[7], source.m[8], source.m[9], source.m[10], source.m[11], source.m[12], source.m[13], source.m[14], source.m[15]));
}

tmatrix		RotationXMatrix(double angle)
{
	tmatrix		result;
	double		c;
	double		s;

	result = ZeroMatrix();
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

tmatrix		RotationYMatrix(double angle)
{
	tmatrix		result;
	double		c;
	double		s;

	result = ZeroMatrix();
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

tmatrix		RotationZMatrix(double angle)
{
	tmatrix		result;
	double		c;
	double		s;

	result = ZeroMatrix();
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

tmatrix		RotationAxisMatrix(tVector3 axis, double angle)
{
	tmatrix		result;
	double		s;
	double		c;
	double		c1;

	s = sin(-angle);
	c = cos(-angle);
	c1 = 1 - c;
	axis = normalizeVector3(axis);
	result = ZeroMatrix();
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

tmatrix		RotationYawPitchRollMatrix(double yaw, double pitch, double roll)
{
	tmatrix		result;

	result = multiplyMatrix(multiplyMatrix(RotationZMatrix(roll), RotationXMatrix(pitch)), RotationYMatrix(yaw));
	return (result);
}

tmatrix		ScalingMatrix(double x, double y, double z)
{
	tmatrix		result;

	result = ZeroMatrix();
	result.m[0] = x;
	result.m[5] = y;
	result.m[10] = z;
	result.m[15] = 1.0;
	return (result);
}

tmatrix		TranslationMatrix(double x, double y, double z)
{
	tmatrix		result;

	result = IdentityMatrix();
	result.m[12] = x;
	result.m[13] = y;
	result.m[14] = z;
	return (result);
}

tmatrix		LookAtLHMatrix(tVector3 eye, tVector3 target, tVector3 up)
{
	tVector3	xAxis;
	tVector3	yAxis;
	tVector3	zAxis;
	double		ex;
	double		ey;
	double		ez;

	zAxis = subtractVector3(target, eye);
	zAxis = normalizeVector3(zAxis);
	xAxis = CrossVector3(up, zAxis);
	xAxis = normalizeVector3(xAxis);
	yAxis = CrossVector3(zAxis, xAxis);
	yAxis = normalizeVector3(yAxis);
	ex = -DotVector3(xAxis, eye);
	ey = -DotVector3(yAxis, eye);
	ez = -DotVector3(zAxis, eye);
	return (FromValuesMatrix(xAxis.x, yAxis.x, zAxis.x, 0, xAxis.y, yAxis.y, zAxis.y, 0, xAxis.z, yAxis.z, zAxis.z, 0, ex, ey, ez, 1));
}

tmatrix		PerspectiveLHMatrix(double width, double height, double znear, double zfar)
{
	tmatrix matrix;

	matrix = ZeroMatrix();
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

tmatrix		PerspectiveFovLHMatrix(double fov, double aspect, double znear, double zfar)
{
	tmatrix		matrix;
	double		tang;

	matrix = ZeroMatrix();
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

tmatrix		TransposeMatrix(tmatrix matrix)
{
	tmatrix		result;

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

void render(tdevice device, tcam camera, tabmesh *meshes)
{
	tmatrix		viewMatrix;
	tmatrix		projectionMatrix;
	tmatrix		worldMatrix;
	tmatrix		transformMatrix;
	long long	index;
	long long	indexvertices;
	tmesh		cMesh;
	tVector2	projectedPoint;

	viewMatrix = LookAtLHMatrix(camera.Position, camera.Target, 
		UpVector3());
	projectionMatrix = PerspectiveFovLHMatrix(0.78, 
		device.workingWidth / device.workingHeight, 0.01, 1);
	for (index = 0; index < meshes->length; index++)
	{
		tmesh cMesh = meshes->m[index];
		worldMatrix = multiplyMatrix(RotationYawPitchRollMatrix(
			cMesh.Rotation.y, cMesh.Rotation.x, cMesh.Rotation.z),
			TranslationMatrix(cMesh.Position.x, cMesh.Position.y, 
			cMesh.Position.z));
			transformMatrix = multiplyMatrix(worldMatrix,multiplyMatrix(
				viewMatrix,projectionMatrix));
		for (indexvertices = 0; indexvertices < cMesh.length; indexvertices++)
		{
			projectedPoint = projectDevice(device, cMesh.vertices[indexvertices], transformMatrix);
			drawPointDevice (device, projectedPoint);
		}
	}
}

