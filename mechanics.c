/*
Camera must always point at player, therefore player is always centered at cam_tar
Player movement due to input is always relative to camera position and angle, not player (no tank controls)
Player must have walk, jump, action and attack animations 
camera position should move in straight line towards player if over a certain distance away 
Camera must be affected by collission the same as the player (Can the camera go up if near wall, is there a min cam distance?)
*/

#include "mechanics.h"
#include "globals.h"
#include "display.h"



void	jump(void)
{
	int jumpmax = jumpstart - 60;
	if (dcpos[1] < (jumpmax*32)){
	jumping = false;}
else{
delta[1] = -50;
}
}


void fpscontrols(void)
{
   
          
    if (!jo_is_pad1_available())
        return;
    
    // Movement
    if (jo_is_pad1_key_pressed(JO_KEY_C))
        delta[1] = 16;
    if (jo_is_pad1_key_pressed(JO_KEY_L))
        delta[0] = -16;
    if (jo_is_pad1_key_pressed(JO_KEY_R))
        delta[0] = 16;
    if (jo_is_pad1_key_pressed(JO_KEY_DOWN))
        delta[2] = -16;
    if (jo_is_pad1_key_pressed(JO_KEY_UP))
        delta[2] = 16;
    if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
        cam_angle[1] -= 3;
    if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
        cam_angle[1] += 3;
    if (jo_is_pad1_key_pressed(JO_KEY_START)) {}




    // Bound Camera Angle
    if (cam_angle[1] > 180)
        cam_angle[1] -= 360;
    else if (cam_angle[1] <= -180)
        cam_angle[1] += 360;

    // Gravity
    delta[1] += 30;

    // Rate of change of Camera Position multiplied by 16 for more precision
    dcpos[0] += (delta[0] * jo_cos(cam_angle[1]) + delta[2] * jo_sin(cam_angle[1])) >> 15;
    dcpos[1] += delta[1];
    dcpos[2] += (delta[2] * jo_cos(cam_angle[1]) - delta[0] * jo_sin(cam_angle[1])) >> 15;
    
    // Change cam position divide by 16 with bitshift
    player->x = dcpos[0] >> 4;
    player->y = dcpos[1] >> 4;
    player->z = dcpos[2] >> 4;
	
	cam_pos[0] = player->x;
    cam_pos[1] = player->y - 60;
    cam_pos[2] = player->z;

    // Fix Camera Target/Orientation
    cam_tar[0] = (cam_pos[0]) + (100 * jo_sin(cam_angle[1]) >> 15);
    cam_tar[1] = cam_pos[1];
    cam_tar[2] = (cam_pos[2]) + (100 * jo_cos(cam_angle[1]) >> 15);
	
	
	
    // Targeting
     static unsigned int i = 1;
    if (jo_is_pad1_key_pressed(JO_KEY_Z))
    {
        cam_angle[1] = jo_atan2f(casks[i].x - cam_pos[0], casks[i].z - cam_pos[2]);
        if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
            delta[0] = -32;
        if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
            delta[0] = 32;
        if (jo_is_pad1_key_down(JO_KEY_X))
            ++i;
        if (jo_is_pad1_key_down(JO_KEY_Y))
           --i;
	   //why does going above 3 or below 0 cycle me onto different object types?
	   //because an array is a memory address and all are declared in sequence, therefore sequential memory addresses are sent indefinitely
    }

	
	
}




void	tpscontrols (void)
{
				
	int camh = -50;

	{
	if (jo_is_pad1_key_pressed(JO_KEY_DOWN)){
	delta[2] = -32;}
	else if (jo_is_pad1_key_pressed(JO_KEY_UP)){
	delta[2] = 32;}
	else {delta[2] = 0;}
	}
	{
    if (jo_is_pad1_key_pressed(JO_KEY_LEFT)){
	delta[0] = -32;}
	else if (jo_is_pad1_key_pressed(JO_KEY_RIGHT)){
	delta[0] = 32;}
	else {delta[0] = 0;}
	}
	if (jo_is_pad1_key_pressed(JO_KEY_R))
        cam_angle[1] += 1;
	if (jo_is_pad1_key_pressed(JO_KEY_L))
        cam_angle[1] -= 1;
	if (jo_is_pad1_key_pressed(JO_KEY_Z))
        camh -= 80;
	if (jo_is_pad1_key_pressed(JO_KEY_Y))
        camh += 40;
	
	

	if (jo_is_pad1_key_down(JO_KEY_C) && !jumping && (((player->y)<<5) - flrmin > -5)){
		jumpstart = player->y;
		jumping = true;
	}
	
	if (jumping == true){
	jump();}

	

	
		 // Bound Camera Angle
    if (cam_angle[1] > 180)
        cam_angle[1] -= 360;
    else if (cam_angle[1] <= -180)
        cam_angle[1] += 360;
	
	   // Gravity
	   flrmin = 0;
    if(delta[1] < 50)
	delta[1] = (delta[1]+10);


	
	
	
	cam_pos[0] = player->x - jo_sin_mult(150, cam_angle[1]);
	cam_pos[1] = player->y + camh;
	cam_pos[2] = player->z - jo_cos_mult(150, cam_angle[1]);
	
	
	    // Rate of change of Camera Position multiplied by 16 for more precision
    dcpos[0] += jo_cos_mult(delta[0], cam_angle[1]) + jo_sin_mult(delta[2],cam_angle[1]);
	dcpos[1] += delta[1];
    dcpos[2] += jo_cos_mult(delta[2], cam_angle[1]) - jo_sin_mult(delta[0], cam_angle[1]);
	
	 player->x = dcpos[0] >> 5;
    player->y = dcpos[1] >> 5;
    player->z = dcpos[2] >> 5;

	
	cam_tar[0] = player->x ;
	cam_tar[1] = player->y ;
	cam_tar[2] = player->z;
	if (delta[0] != 0 || delta[2]!=0){
		
	player->ry = cam_angle[1] + jo_atan2f(delta[0], delta[2]);}
	
	

}





//Collision

//Walls


void	wall_collision(obj walls[], int numobj){
	flrmin = 0;
int i;
for(i=0; i < numobj; i++)
{
	
if (((cam_pos[0]) >= (walls[i].x - walls[i].s)) && ((cam_pos[0]) <= (walls[i].x - (walls[i].s-10))) && ((cam_pos[2]) <= ((walls[i].z)+(walls[i].s-10))) && ((cam_pos[2]) >= ((walls[i].z)-(walls[i].s-10))))
{dcpos[0] = ((walls[i]).x - walls[i].s)<<4;}

if (((cam_pos[0]) <= ((walls[i]).x + walls[i].s)) && ((cam_pos[0]) >= ((walls[i].x) + (walls[i].s-10))) && ((cam_pos[2]) <= ((walls[i].z)+(walls[i].s-10))) && ((cam_pos[2]) >= ((walls[i].z)-(walls[i].s-10))))
{dcpos[0] = ((walls[i]).x + walls[i].s)<<4;}

if (((cam_pos[2]) <= ((walls[i]).z + walls[i].s)) && ((cam_pos[2]) >= ((walls[i].z) + (walls[i].s-10))) && ((cam_pos[0]) <= ((walls[i].x)+(walls[i].s-10))) && ((cam_pos[0]) >= ((walls[i].x)-(walls[i].s-10))))
{dcpos[2] = ((walls[i]).z + walls[i].s)<<4;}

if (((cam_pos[2]) >= ((walls[i]).z - walls[i].s)) && ((cam_pos[2]) <= ((walls[i].z) - (walls[i].s-10))) && ((cam_pos[0]) <= ((walls[i].x)+(walls[i].s-10))) && ((cam_pos[0]) >= ((walls[i].x)-(walls[i].s-10))))
{dcpos[2] = ((walls[i]).z - walls[i].s)<<4;}
}
}







void	tpwall_collision(obj walls[], int numobj){
	
int i;
for(i=0; i < numobj; i++)
{
	if (((player->y) > walls[i].y - walls[i].h)){
	
if (((player->x) > (walls[i].x - walls[i].s)) && ((player->x) < (walls[i].x - (walls[i].s-10))) && ((player->z) < ((walls[i].z)+(walls[i].s-10))) && ((player->z) > ((walls[i].z)-(walls[i].s-10))))
{
dcpos[0] = ((walls[i]).x - walls[i].s)<<5;
}

if (((player->x) < ((walls[i]).x + walls[i].s)) && ((player->x) > ((walls[i].x) + (walls[i].s-10))) && ((player->z) < ((walls[i].z)+(walls[i].s-10))) && ((player->z) > ((walls[i].z)-(walls[i].s-10))))
{
dcpos[0] = ((walls[i]).x + walls[i].s)<<5;
}

if (((player->z) < ((walls[i]).z + walls[i].s)) && ((player->z) > ((walls[i].z) + (walls[i].s-10))) && ((player->x) < ((walls[i].x)+(walls[i].s-10))) && ((player->x) > ((walls[i].x)-(walls[i].s-10))))
{
dcpos[2] = ((walls[i]).z + walls[i].s)<<5;
}

if (((player->z) > ((walls[i]).z - walls[i].s)) && ((player->z) < ((walls[i].z) - (walls[i].s-10))) && ((player->x) < ((walls[i].x)+(walls[i].s-10))) && ((player->x) > ((walls[i].x)-(walls[i].s-10))))
{
dcpos[2] = ((walls[i]).z - walls[i].s)<<5;
}
}
}


	int j;
for(j=0; j < numobj; j++){
if (((player->x) >= (walls[j].x - walls[j].s + 30)) && ((player->x) <= (walls[j].x + walls[j].s - 30)) && ((player->z) <= ((walls[j].z)+walls[j].s - 30)) && ((player->z) >= ((walls[j].z)-walls[j].s + 30)) )
{	

	flrmin = (walls[j].y - walls[j].h)<<5;
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
break;
}

}
}

// Terrain

void	terrain_collision(obj mounds[], int numobj){
	
	//Bound Cam height
	//flrmin = 0;
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
	
	int i;
for(i=0; i < numobj; i++)
if (((player->x) >= (mounds[i].x - mounds[i].s)) && ((player->x) <= (mounds[i].x + mounds[i].s)) && ((player->z) <= ((mounds[i].z)+mounds[i].s)) && ((player->z) >= ((mounds[i].z)-mounds[i].s)))
{	

	flrmin = ((mounds[i].y - mounds[i].h))<<5;
	//*((1 - (JO_ABS(((player->x - mounds[i].x)*(player->z - mounds[i].z))/mounds[i].s))))
	if (dcpos[1] > flrmin)
	dcpos[1] = flrmin;
break;
}
//else {flrmin=0;}


}


void	modelview (jo_3d_mesh *mesh)
{
	static unsigned int r=0;
	static unsigned int g=0;
	static unsigned int b=0;
static unsigned	int quadNo = 0;
if (jo_is_pad1_key_down(JO_KEY_L))
--quadNo;
if (jo_is_pad1_key_down(JO_KEY_R))
++quadNo;
if (jo_is_pad1_key_pressed(JO_KEY_UP))
++player->rx;
if (jo_is_pad1_key_pressed(JO_KEY_DOWN))
--player->rx;
if (jo_is_pad1_key_down(JO_KEY_X))
++r;
if (jo_is_pad1_key_down(JO_KEY_A))
--r;
if (jo_is_pad1_key_down(JO_KEY_Y))
++g;
if (jo_is_pad1_key_down(JO_KEY_B))
--g;
if (jo_is_pad1_key_down(JO_KEY_Z))
++b;
if (jo_is_pad1_key_down(JO_KEY_C))
--b;
if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
++player->ry;
if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
--player->ry;
jo_3d_set_mesh_color(mesh, JO_COLOR_RGB (r, g, b));
jo_3d_set_mesh_polygon_color(mesh, JO_COLOR_Red, quadNo);

jo_printf(0, 2, "Polygon No: %4d Degrees", quadNo);
jo_printf(0, 3, "R: %4d Degrees", r);
jo_printf(0, 4, "G: %4d Degrees", g);
jo_printf(0, 5, "B: %4d Degrees", b);
}