/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:32:32 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/13 09:35:16 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int array_size(char **array)
{
    int size;

    size = 0;
    if (array == NULL)
        return(0);
    while(array[size] != NULL)
        size++;
    return(size);
}