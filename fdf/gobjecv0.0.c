#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct typevertex
{
	double			x;
	double			y;
	double			z;
} tvertex;

typedef struct typeface
{
	double			A;
	double			B;
	double			C;
} tfaces;

typedef struct typemesh
{
	char		*name;
	tvertex		*vertices;
	tfaces		*faces;
} tmesh;

tmesh		*newmesh(char *name, long nbvertex, long nbfaces)
{
	tmesh		*mymesh;

	mymesh = malloc(sizeof(tmesh));
	mymesh->name = malloc(strlen(name));
	strcpy(mymesh->name, name);
	mymesh->vertices = malloc(sizeof(tvertex) * nbvertex);
	mymesh->faces = malloc(sizeof(tfaces) * nbfaces);
	return mymesh;
}

void		putvertex(tvertex *vertex, double x, double y, double z)
{
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
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
	putvertex(&mycube->vertices[0], -1,  1,  1);
	putvertex(&mycube->vertices[1],  1,  1,  1);
	putvertex(&mycube->vertices[2], -1, -1,  1);
	putvertex(&mycube->vertices[3],  1, -1,  1);
	putvertex(&mycube->vertices[4], -1,  1, -1);
	putvertex(&mycube->vertices[5],  1,  1, -1);
	putvertex(&mycube->vertices[6],  1, -1, -1);
	putvertex(&mycube->vertices[7], -1, -1, -1);
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

int main()
{
tmesh		*cube;

cube = newcube("MonCube");
printcube(cube);
return 0;
}
