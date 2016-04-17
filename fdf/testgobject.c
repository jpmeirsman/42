#include "gobject.c"

int main()
{
tmesh		*cube;
tcam		*camera;
tcanvas		*canvas;
char		*s;
tcolour4	tc;

canvaslength = 640;
canvasheight = 480;

//canvas = newcanvas("frontBuffer");
camera = newcam(0, 0, 10, 0, 0, 0);
cube = newcube("MonCube");
cube->Rotation.x += 0.01;
cube->Rotation.y += 0.01;

return 0;
}
