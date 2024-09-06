	const enum texid{
		DOOR,
		WINDOW,
		WALL,
		WINDOW2,
		BIGWALL,
		ROOF,
		GRASS,
		MOUNTAIN,
		FACE,
		BUST,
		SKIN,
		SBUST,
		HAIR,
		MOUTH,
		BUST2,
		EYE,
		GRASS2		
	};
	
	void	loadtextures(void)
{
	jo_sprite_add_tga(JO_ROOT_DIR, "DOOR.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "WINDOW.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "WALL.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "WINDOW2.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "BIGWALL.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "ROOF.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "GRASS.TGA", JO_COLOR_Black);
	jo_sprite_add_tga(JO_ROOT_DIR, "MOUNTAIN.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "FACE.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "BUST.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "SKIN.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "SBUST.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "HAIR.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "MOUTH.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "BUST2.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "EYE.TGA", JO_COLOR_Transparent);
	jo_sprite_add_tga(JO_ROOT_DIR, "GRASS2.TGA", JO_COLOR_Black);
	
	
}

#include "femaletex.h"
#include "meshes.h"
#include "fergusthefrog.h"
#include "tree.h"
#include "house.h"
#include "boulder.h"

