/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:51:40 by imiqor            #+#    #+#             */
/*   Updated: 2025/07/10 01:39:02 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../header.h"
int count_map_lines(char **content, int start)
{
    int count = 0;
    while (content[start + count])
        count++;
	
    return count;
}
void trim_newline(char *str)
{
    int len = ft_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void store_map_lines(char **content, int start, t_map *map)
{
	int map_lines;
	int j;
	j = 0;
    map_lines = count_map_lines(content, start);
    map->map_grid = ft_gc(sizeof(char *) * (map_lines + 1),'m');
    if (!map->map_grid)
	{
        error_exit("Malloc failed for map grid");
	}
    while (j < map_lines)
	{
        map->map_grid[j] = ftt_strdup(content[start + j]);
		trim_newline(map->map_grid[j]); 
		
		j++;
		
	}
	
    map->map_grid[map_lines] = NULL; // Null terminate
    map->line_count = map_lines;

}
