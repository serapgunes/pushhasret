/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:23:22 by segunes           #+#    #+#             */
/*   Updated: 2025/04/04 19:46:30 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_total_length(int argc, char **argv)
{
    int total_len = 0;
    int i = 1;
    while (i < argc)
    {
        total_len += ft_strlen(argv[i]);
        i++;
    }
    return total_len;
}

char *merge_strings(int argc, char **argv)
{
    int total_len = get_total_length(argc, argv);
    char *merged = (char *)malloc(total_len + argc - 1);
    int i = 1, j, idx = 0;
    
    if (!merged)
        return NULL;
    
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
            merged[idx++] = argv[i][j++];
        if (i < argc - 1)
            merged[idx++] = ' ';
        i++;
    }
    merged[idx] = '\0';
    return merged;
}

char **merge_arguments(int argc, char **argv)
{
    char *merged = merge_strings(argc, argv);
    char **result;
    
    if (!merged)
        return NULL;
    
    result = ft_split(merged, ' ');
    free(merged);
    return result;
}
