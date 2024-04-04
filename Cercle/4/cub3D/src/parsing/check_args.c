/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:46 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/04 10:45:41 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool is_right_xpm_file(char *file);
//check if the argument is a valid ".cub" file
int check_args(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("argc: %d\n", argc);
    }
    //check is the file is termanited with.cub
    // if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5) != 0)
    //     return (FAILURE);
    // check if the file is a valid xpm file
    if (!is_right_xpm_file(argv[1]))
        return (FAILURE);
    return (SUCCESS);
}
//try to open an xpm file and check if it is a valid xpm file
bool is_right_xpm_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        printf("xpm file not found\n");
        return (false);
    }
    close(fd);
    return (true);
}