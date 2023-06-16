#include "../inc/so_long.h"

void init_player_animation(t_game *game)
{
    game->player_animation.up = "2,3";
	game->player_animation.down = "0,1";
	game->player_animation.left = "4,5,4,6";
	game->player_animation.right = "7,8,7,9";
}

void play_animation(char *direction, int32_t )
{

}

/*
(direction, animation_spd)

struct player_animation:
    index = 0;
    up = [0, 1];
    down = [2, 3];
    right = [4, 5, 4, 6];
    left = [7, 8, 7, 9];


while:
    indwx = 0;
    if (>= array_length) {
        index = 0;
    } else {
        index++;
    }
*/
