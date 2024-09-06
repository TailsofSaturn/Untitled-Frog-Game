#ifndef GLOBALS_H
#define GLOBALS_H

#include <jo/jo.h>


typedef struct {
    int x;
    int y;
    int z;
    int rx;
    int ry;
    int rz;
    int s;
	int h;
} obj;


//Objects
extern obj player[];
extern obj houses[];
extern obj mounds[];
extern obj casks[];
extern obj females[];
extern obj keyfs[];
extern obj trees[];
extern obj boulders[];
//extern obj *objects[];  not used anymore?


//3D Variables
extern jo_camera cam;
extern jo_palette image_pal;

extern int cam_pos[3];
extern float cam_angle[3];
extern int cam_tar[3];
extern int dcpos[3];
extern int delta[3];

extern int flrmin;
extern bool jumping;
extern int jumpstart;

#endif