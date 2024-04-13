/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:25:12 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 17:25:16 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <assert.h>

// int main() {
//     char *argv[] = {"./cub3D", "valid.cub"};

//     int **worldmap = malloc(sizeof(int *) * 31);
//     for (int i = 0; i < 31; i++)
//         worldmap[i] = malloc(sizeof(int) * 31);
//     for (int i = 0; i < 30; i++)
//     {
//         for (int j = 0; j < 30; j++)
//             worldmap[i][j] = woorldMap[j][i];
//     }
//     t_path *path = check_args(2, argv);
//     // Assert that all textures and RGB values are present
//     // assert(path->so != NULL);
//     // assert(path->we != NULL);
//     // assert(path->ea != NULL);
//     // assert(path->no != NULL);
//     // assert(path->floor != NULL);
//     // assert(path->ceiling != NULL);
//     // // Assert that the map is not empty
//     // assert(path->map != NULL);
//     // // Assert that the player orientation is set
//     // assert(path->player_orientation != 0);
//     // Clean up memory
//     free(path);
//     return 0;
// }