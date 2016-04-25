#include "gobject.c"

int main(void)

{
tmesh		*cube;
tcam		*camera;
tcanvas		*canvas;
char		*s;
tcolour4	tc;
tVector2	tv2;
tVector3	tv3;

canvaslength = 640;
canvasheight = 480;

//canvas = newcanvas("frontBuffer");
camera = newcam(0, 0, 10, 0, 0, 0);
cube = newcube("MonCube");
cube->Rotation.x += 0.01;
cube->Rotation.y += 0.01;

tv2.x = 6.31;
tv2.y = 1297.2508;
tv3.x = 6.31;
tv3.y = .7;
tv3.z = 5;
s = Vector2toString(tv2);
printf("'%s'\n",s);
s = Vector3toString(tv3);
printf("'%s'\n",s);
return 0;
}
