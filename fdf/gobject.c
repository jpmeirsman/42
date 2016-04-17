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
} tmesh;

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
	char		*workingContext;
} tdevice;

typedef struct typecolour4
{
	short		r;
	short		g;
	short		b;
	short		a;
} tcolour4;

int	canvaslength;
int canvasheight;

tcolour4	setcolour4(short R, short G, short B, short A)
{
	tcolour4	tc;

	tc.r = R;
	tc.g = G;
	tc.b = B;
	tc.a = A;
	return (tc);
}

char		*colour4toString(tcolour4 tc)
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

tVector2	setVector2(double X, double Y)
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

tVector3	FromArrayVector3(array, short offset)
{
	tVector3	temp;

	if (!offset)
		offset = 0;
	return (setVector3(array[offset], array[offset + 1], array[offset + 2]));
}

tVector3	setVector3(double X, double Y, double Z)
{
	tVector3	Vector3;

	Vector3.x = X;
	Vector3.y = Y;
	Vector3.z = Z;
	return (Vector3);
}

tcam		*newcam(long posx, long posy, long posz, long targetx, long targety, long targetz)
{
	tcam	*camera;

	camera = malloc(sizeof(tcam));
	camera->Position.x = posx;
	camera->Position.y = posy;
	camera->Position.z = posz;
	camera->Target.x = targetx;
	camera->Target.y = targety;
	camera->Target.z = targetz;
	return (camera);
}

tmesh		*newmesh(char *name, long nbVector3, long nbfaces)
{
	tmesh		*mymesh;

	mymesh = malloc(sizeof(tmesh));
	mymesh->name = malloc(strlen(name));
	strcpy(mymesh->name, name);
	mymesh->vertices = malloc(sizeof(tVector3) * nbVector3);
	mymesh->faces = malloc(sizeof(tfaces) * nbfaces);
	return mymesh;
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

tmesh		*newcube(char *name)
{
	tmesh		*mycube;
	mycube = newmesh(name, 8, 12);
	putVector3(&mycube->vertices[0], -1,  1,  1);
	putVector3(&mycube->vertices[1],  1,  1,  1);
	putVector3(&mycube->vertices[2], -1, -1,  1);
	putVector3(&mycube->vertices[3],  1, -1,  1);
	putVector3(&mycube->vertices[4], -1,  1, -1);
	putVector3(&mycube->vertices[5],  1,  1, -1);
	putVector3(&mycube->vertices[6],  1, -1, -1);
	putVector3(&mycube->vertices[7], -1, -1, -1);
	putface(&mycube->faces[0],  0, 1, 2);
	putface(&mycube->faces[1],  1, 2, 3);
	putface(&mycube->faces[2],  1, 3, 6);
	putface(&mycube->faces[3],  1, 5, 6);
	putface(&mycube->faces[4],  0, 1, 4);
	putface(&mycube->faces[5],  1, 4, 5);
	putface(&mycube->faces[6],  2, 3, 7);
	putface(&mycube->faces[7],  3, 6, 7);
	putface(&mycube->faces[8],  0, 2, 7);
	putface(&mycube->faces[9],  0, 4, 7);
	putface(&mycube->faces[10], 4, 5, 6);
	putface(&mycube->faces[11], 4, 6, 7);

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
	if (matrix.m[0] != 1 || matrix.m[5] != 1 || matrix.m[10] != 1 || matrix.m[15] != 1 )
		return (false);
	if (matrix.m[1] != 0 || matrix.m[2] != 0 || matrix.m[3] != 0 || matrix.m[4] != 0 || matrix.m[6] != 0 || matrix.m[7] != 0 || matrix.m[8] != 0 || matrix.m[9] != 0 || matrix.m[11] != 0 || matrix.m[12] != 0 || matrix.m[13] != 0 || matrix.m[14] != 0 )
		return false;
	return (true);
}

void render(tdevice device, tcam camera, tmesh meshes)
{
/*
ViewMatrix viewMatrix = MatrixLookAtLH(camera.Position, camera.Target, Vector3Up());
	ProjectionMatrix projectionMatrix = MatrixPerspectiveFovLH(0.78, workingWidth / workingHeight, 0.01, 1);
	for (int index = 0, index < meshes.length, index++)
	{
		tmesh cMesh = meshes[index];
		WorldMatrix worldMatrix = MatrixRotationYawPitchRoll(cMesh.Rotation.y,cMesh.Rotation.x, cMesh.Rotation.z)
	+++
	TransformMatrix TransformMatrix(worldMatrix
	}
*/
}
