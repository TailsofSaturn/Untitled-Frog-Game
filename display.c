#include "display.h"
#include "globals.h"

// Positions

obj player[] = {
	{.x = 0, .y = 0, .z = 200, .rx = 0, .ry = 0, .rz = 0, .s = 0, .h = 0}
};

obj houses[] = {
   // {.x = 375, .y = 0, .z = 0, .rx = 0, .ry = 90, .rz = 0, .s = 200, .h = 200},
    //{.x = 375, .y = 0, .z = 300, .rx = 0, .ry = 90, .rz = 0, .s = 200, .h = 200},
    //{.x = 375, .y = 0, .z = 600, .rx = 0, .ry = 90, .rz = 0, .s = 200, .h = 200},
    //{.x = -375, .y = 0, .z = 0, .rx = 0, .ry = -90, .rz = 0, .s = 200, .h = 200},
    //{.x = -375, .y = 0, .z = 300, .rx = 0, .ry = -90, .rz = 0, .s = 200, .h = 200},
   // {.x = -375, .y = 0, .z = 600, .rx = 0, .ry = -90, .rz = 0, .s = 200, .h = 200},
    //{.x = -130, .y = 0, .z = 900, .rx = 0, .ry = 0, .rz = 0, .s = 200, .h = 200},
    {.x = 130, .y = 0, .z = 920, .rx = 0, .ry = -90, .rz = 0, .s = 200, .h = 200},
    //{.x = 375, .y = 0, .z = -300, .rx = 0, .ry = 90, .rz = 0, .s = 200, .h = 200},
    //{.x = 375, .y = 0, .z = -600, .rx = 0, .ry = 90, .rz = 0, .s = 200, .h = 200},
    //{.x = -375, .y = 0, .z = -300, .rx = 0, .ry = -90, .rz = 0, .s = 200, .h = 200},
   // {.x = -375, .y = 0, .z = -600, .rx = 0, .ry = -90, .rz = 0, .s = 200, .h = 200},
    //{.x = -130, .y = 0, .z = -1200, .rx = 0, .ry = 180, .rz = 0, .s = 200, .h = 200},
    //{.x = 130, .y = 0, .z = -1200, .rx = 0, .ry = 180, .rz = 0, .s = 200, .h = 200},
    //{.x = -390, .y = 0, .z = -1200, .rx = 0, .ry = 180, .rz = 0, .s = 200, .h = 200},
   // {.x = 390, .y = 0, .z = -1200, .rx = 0, .ry = 180, .rz = 0, .s = 200, .h = 200},
};

obj mounds[] = {
    {.x = 0, .y = 0, .z = -375, .rx = 0, .ry = 0, .rz = 0, .s = 30, .h = 25},
    {.x = -50, .y = 0, .z = -90, .rx = 0, .ry = 0, .rz = 0, .s = 25, .h = 25},
    {.x = 50, .y = 0, .z = -20, .rx = 0, .ry = 0, .rz = 0, .s = 25, .h = 25},
};


obj casks[] = {
    {.x = -12, .y = 0, .z = 658, .rx = 0, .ry = 45, .rz = 0, .s = 45, .h = 60},
    {.x = -46, .y = 0, .z = 703, .rx = 0, .ry = 60, .rz = 0, .s = 45, .h = 60},
    {.x = 6, .y = 0, .z = 701, .rx = 0, .ry = 0, .rz = 0, .s = 45, .h = 60},
    {.x = 55, .y = 0, .z = -350, .rx = 0, .ry = 30, .rz = 0, .s = 45, .h = 60},
};

/*
obj casks[] = {
    {.x = -12, .y = 0, .z = 700, .rx = 0, .ry = 45, .rz = 0, .s = 45, .h = 60},
    {.x = -46, .y = 0, .z = 800, .rx = 0, .ry = 60, .rz = 0, .s = 45, .h = 60},
    {.x = 6, .y = 0, .z = 900, .rx = 0, .ry = 0, .rz = 0, .s = 45, .h = 60},
    {.x = 8, .y = -60, .z = 1000, .rx = 0, .ry = 30, .rz = 0, .s = 45, .h = 60},
};
*/

obj females[] = {
    {.x = -180, .y = 0, .z = 600, .rx = 180, .ry = 135, .rz = 0, .s = 35, .h = 80},
    {.x = -180, .y = 0, .z = 600, .rx = 180, .ry = 225, .rz = 0, .s = 35, .h = 80},
    {.x = 180, .y = 0, .z = 0, .rx = 180, .ry = 45, .rz = 0, .s = 35, .h = 80},
};

obj keyfs[] = {
    {.x = 10, .y = -22, .z = 0, .rx = 0, .ry = 0, .rz = 0, .s = 35, .h = 60},
    {.x = 10, .y = -22, .z = 0, .rx = 0, .ry = 0, .rz = 0, .s = 35, .h = 60}, // mid up
    {.x = 10, .y = -18, .z = 10, .rx = 30, .ry = 0, .rz = 0, .s = 35, .h = 60}, // forward
    {.x = 10, .y = -20, .z = 0, .rx = 0, .ry = 0, .rz = 0, .s = 35, .h = 60}, // mid down
    {.x = 10, .y = -18, .z = -10, .rx = -30, .ry = 0, .rz = 0, .s = 35, .h = 60}, // back
};

obj trees[] = {
	{.x = 505, .y = 0, .z = 630, .rx = 0, .ry = 37, .rz = 0, .s = 50, .h = 400},
};

obj boulders[] = {
	{.x = 50, .y = 0, .z = -500, .rx = 0, .ry = 0, .rz = 0, .s = 125, .h = 100},
	{.x = 300, .y = 0, .z = -500, .rx = 0, .ry = 0, .rz = 0, .s = 125, .h = 100},
};

int distance(int x1, int x2, int z1, int z2) {
    int dist = (x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1);
    return dist;
}




// Animations

enum State {
    first,
    second,
    third,
    fourth
}state;

   bool sameint(int verts1[][3], int verts2[][3], int numverts) {
    for (int i = 0; i < numverts; i++) {
        for (int j = 0; j < 3; j++) {
            if (verts1[i][j] - verts2[i][j] > 1 || verts1[i][j] - verts2[i][j] < -1) {
                return false;
            }
        }
    }
    return true;
}

   bool samefixed(jo_fixed verts1[][3], jo_fixed verts2[][3], int numverts) {
	   
	bool same = true;
    for (int i = 0; i < numverts; i++) {
        for (int j = 0; j < 3; j++) {
            if (verts1[i][j] - verts2[i][j] >= 100 || verts1[i][j] - verts2[i][j] <= -100) {
                same = false;
				break;
            }
        }
    }
    return same;
}


	
	
		void	interpolate_intverts(int verts[][3],int verts1[][3],int verts2[][3],int verts3[][3], int verts4[][3], int frames, int numverts, jo_3d_mesh *mesh){
	static int state = 1;
	
	
	switch (state) {
		case 1:
		if (!sameint(verts, verts1, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts1[i][0] - verts4[i][0])/frames);
       verts[i][1] = verts[i][1] + ((verts1[i][1] - verts4[i][1])/frames);
       verts[i][2] = verts[i][2] + ((verts1[i][2] - verts4[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 2;}
	break;
	
	case 2:
		if (!sameint(verts, verts2, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts2[i][0] - verts1[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts2[i][1] - verts1[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts2[i][2] - verts1[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 3;}
	break;	

	case 3:
		if (!sameint(verts, verts3, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts3[i][0] - verts2[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts3[i][1] - verts2[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts3[i][2] - verts2[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 4;}
	break;	
	
		case 4:
		if (!sameint(verts, verts4, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts4[i][0] - verts3[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts4[i][1] - verts3[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts4[i][2] - verts3[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, jo_int2fixed(verts[i][0]), jo_int2fixed(verts[i][1]), jo_int2fixed(verts[i][2]), i);
		 }	
	}
	else {state = 1;}
	break;	
}
}

		void	interpolate_fixedverts(jo_fixed verts[][3],jo_fixed verts1[][3],jo_fixed verts2[][3],jo_fixed verts3[][3],jo_fixed verts4[][3], int frames, int numverts, jo_3d_mesh *mesh){
	static int state = 1;
	
	switch (state) {
		case 1:
		if (!samefixed(verts, verts1, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts1[i][0] - verts4[i][0])/frames);
       verts[i][1] = verts[i][1] + ((verts1[i][1] - verts4[i][1])/frames);
       verts[i][2] = verts[i][2] + ((verts1[i][2] - verts4[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, (verts[i][0]), (verts[i][1]), (verts[i][2]), i);
		 }	
	}
	else {state = 2;}
	break;
	
	case 2:
		if (!samefixed(verts, verts2, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts2[i][0] - verts1[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts2[i][1] - verts1[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts2[i][2] - verts1[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, (verts[i][0]), (verts[i][1]), (verts[i][2]), i);
		 }	
	}
	else {state = 3;}
	break;	
	
	case 3:
		if (!samefixed(verts, verts3, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts3[i][0] - verts2[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts3[i][1] - verts2[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts3[i][2] - verts2[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, (verts[i][0]), (verts[i][1]), (verts[i][2]), i);
		 }	
	}
	else {state = 4;}
	break;
	
	case 4:
		if (!samefixed(verts, verts4, numverts)) {
		 for (int i = 0; i < numverts; i++) {
        verts[i][0] = verts[i][0] + ((verts4[i][0] - verts3[i][0])/frames);
      verts[i][1] = verts[i][1] + ((verts4[i][1] - verts3[i][1])/frames);
      verts[i][2] = verts[i][2] + ((verts4[i][2] - verts3[i][2])/frames);
		jo_3d_set_mesh_vertice(mesh, (verts[i][0]), (verts[i][1]), (verts[i][2]), i);
		 }	
	}
	else {state = 1;}
	break;
}
}

void revertfixedverts(jo_fixed verts[][3],jo_fixed verts1[][3],int numverts, jo_3d_mesh *mesh){
	
		for (int i = 0; i < numverts; i++) {
		verts[i][0] = verts1[i][0];
		verts[i][1] = verts1[i][1];
		verts[i][2] = verts1[i][2];
		jo_3d_set_mesh_vertice(mesh, (verts[i][0]), (verts[i][1]), (verts[i][2]), i);
		}
}
	


void movethenrotate(obj object[]) {
    static enum State state = first;  // Initial state

    switch (state) {
        case first:
            if (object[0].z != object[1].z ) {
			object[0].z += (object[1].z - object[2].z) / 600;}
			if (object[0].x != object[1].x){
				object[0].x += (object[1].x - object[2].x) / 300;
            }
			else {
                state = second;  // Transition to turn around state
            }
            break;

        case second:
            if (object[0].ry != object[1].ry) {
                ++object[0].ry;
            }
			else {
                state = third;  // Transition to move backward state
            }
            break;

        case third:
            if (object[0].z != object[2].z) {
			object[0].z += (object[2].z - object[1].z) / 600;}
			if (object[0].x != object[2].x){
				object[0].x += (object[2].x - object[1].x) / 300;
				
            }
			else {
                state = fourth;  // Transition to reset state
            }
            break;

        case fourth:
            if (object[0].ry != object[2].ry) {
                --object[0].ry;
            } 
			else {
                state = first;  // Transition back to move forward state
            }
            break;
    }
}


void moveandrotate(obj object[]) {
    //static state = MID_UP;  // Initial state
	
	static enum State state = first;  // Initial state

    switch (state) {
        case first:
            if (object[0].y != object[2].y) {
			object[0].y += (object[2].y - object[1].y) / 6;}
			if (object[0].z != object[2].z) {
			object[0].z += (object[2].z - object[1].z) / 6;}
			if (object[0].rx != object[2].rx) {
			object[0].rx += (object[2].rx - object[1].rx) / 6;}
            else {
                state = second;  // Transition to turn around state
            }
            break;

           case second:
            if (object[0].y != object[3].y) {
			object[0].y += (object[3].y - object[2].y) / 6;}
			if (object[0].z != object[3].z) {
			object[0].z += (object[3].z - object[2].z) / 6;}
			if (object[0].rx != object[3].rx) {
			object[0].rx += (object[3].rx - object[2].rx) / 6;}
            else {
                state = third;  // Transition to turn around state
            }
            break;

          case third:
            if (object[0].y != object[4].y) {
			object[0].y += (object[4].y - object[3].y) / 6;}
			if (object[0].z != object[4].z) {
			object[0].z += (object[4].z - object[3].z) / 6;}
			if (object[0].rx != object[4].rx) {
			object[0].rx += (object[4].rx - object[3].rx) / 6;}
            else {
                state = fourth;  // Transition to turn around state
            }
            break;

             case fourth:
            if (object[0].y != object[1].y) {
			object[0].y += (object[1].y - object[4].y) / 6;}
			if (object[0].z != object[1].z) {
			object[0].z += (object[1].z - object[4].z) / 6;}
			if (object[0].rx != object[1].rx) {
			object[0].rx += (object[1].rx - object[4].rx) / 6;}
            else {
                state = first;  // Transition to turn around state
            }
            break;
	}
}



// Display

jo_camera cam;
jo_palette image_pal;



void debug_menu(void) {
    // Write Text to Screen
    jo_printf(0, 0, "              *Test Game*              ");
    //jo_printf(0, 3, "Camera Angle: %4d Degrees", cam_angle[1]);
    //jo_printf(0, 4, "Camera Position:%7d,%7d,%7d ", cam_pos[0], cam_pos[1], cam_pos[2]);
	jo_printf(0, 3, "Ground height:%7d, ", flrmin);
	jo_printf(0, 4, "jumstart:%7d, ", jumpstart);
    jo_printf(0, 5, "Camera Target:  %7d,%7d,%7d ", cam_tar[0], cam_tar[1], cam_tar[2]);
    jo_printf(0, 6, "Camera Fixed Position:%7d,%7d,%7d ", dcpos[0], dcpos[1], dcpos[2]);
    //jo_printf(0, 27, "Polygons: %7d ", jo_3d_get_polygon_count());
    //jo_printf(0, 28, "Vertices: %7d ", jo_3d_get_vertices_count());
    //jo_printf(0, 29, "Displayed Polygons: %7d ", jo_3d_get_displayed_polygon_count());
}

void draw_mesh(jo_3d_mesh *mesh, obj position[], int numobj) {
    int i;
    for (i = 0; i < numobj; i++) {
        jo_3d_push_matrix();
        {
            jo_3d_translate_matrix(position[i].x, position[i].y, position[i].z);
            jo_3d_rotate_matrix(position[i].rx, position[i].ry, position[i].rz);
            jo_3d_mesh_draw(mesh);
        }
        jo_3d_pop_matrix();
    }
}



void init_3d_planes(void) {
    jo_img_8bits img;

    jo_core_tv_off();

    jo_enable_background_3d_plane(JO_COLOR_Black);

    // FLOOR
    img.data = JO_NULL;
    jo_tga_8bits_loader(&img, JO_ROOT_DIR, "GRASS.TGA", JO_COLOR_Transparent);
    jo_background_3d_plane_a_img(&img, image_pal.id, true, true);
    jo_free_img(&img);
    jo_core_tv_on();
}

void            my_background()
{
    jo_img      bg;

    bg.data = NULL;
    jo_tga_loader(&bg, JO_ROOT_DIR, "BG.TGA", JO_COLOR_Transparent);
    jo_set_background_sprite(&bg, 0, 0);
    jo_free_img(&bg);
}
