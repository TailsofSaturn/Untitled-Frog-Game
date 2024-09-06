/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2017, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/




#include <jo/jo.h>
#include "globals.h"
#include "3dmodels.h"
#include "display.h"
#include "mechanics.h"





	

void initialise(void)
{
	
	jo_core_init(JO_COLOR_Black);
	jo_3d_camera_init(&cam);
	loadtextures();
	jo_set_tga_palette_handling(my_tga_palette_handling);
	init_3d_planes();
    //create_house();
	create_mound();
	create_cask();
	create_arm();
	}




void draw_objects(void) {
    // Infinite Plane
    jo_3d_push_matrix();
    {
        jo_3d_rotate_matrix(90, 0, 0);
        jo_3d_translate_matrix(0, 0, 0);
        jo_background_3d_plane_a_draw(true);
    }
    jo_3d_pop_matrix();

    draw_mesh(&house, houses, 1);
    draw_mesh(mound, mounds, 3);
    //interpolate_intverts(cask_verts, cask1_verts, cask2_verts,cask1_verts, cask2_verts, 10, 36, cask);
    draw_mesh(cask, casks, 4);
    interpolate_fixedverts(Pointfemale, femaleleft, femaleright, femaleleft, femaleright, 20, 137, &female);
	{
	if (delta[0] != 0 || delta[2] != 0){
	interpolate_fixedverts(Pointfergus, fergusrightmid, fergusrightforward, fergusleftmid, fergusleftforward, 20, 202, &fergus);}
	else if (delta[0] == 0 && delta[2] == 0){
	revertfixedverts(Pointfergus, fergusstand,202, &fergus);}
	}
	movethenrotate(females);
    draw_mesh(&female, females, 1);
   // moveandrotate(keyfs);
    // draw_mesh(arm, keyfs, 1);
	draw_mesh(&fergus, player, 1);
	draw_mesh(&tree, trees, 1);
	draw_mesh(&boulder, boulders, 2);

}

jo_palette *my_tga_palette_handling(void) {
    // We create a new palette for each image. It's not optimal but OK for a demo.
    jo_create_palette(&image_pal);
    return (&image_pal);
}



void			    my_draw(void)
{
    
    jo_3d_camera_look_at(&cam);
    jo_3d_camera_set_viewpoint(&cam,cam_pos[0],cam_pos[1],cam_pos[2]);
    jo_3d_camera_set_target(&cam,cam_tar[0],cam_tar[1],cam_tar[2]);
	tpscontrols();
	tpwall_collision(houses, 1);
	tpwall_collision(casks, 4);
	tpwall_collision(females, 1);
	tpwall_collision(trees, 1);
	tpwall_collision(boulders, 2);
	//terrain_collision(casks, 3);
	terrain_collision(mounds, 3);
	draw_objects();
	debug_menu();
	}



void			jo_main(void)
{
	initialise();
	//my_background();
	jo_core_add_callback(my_draw);
	slDynamicFrame(ON);
	jo_core_run();
}



/*
** END OF FILE
*/
