/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:39:07 by segunes           #+#    #+#             */
/*   Updated: 2025/04/04 18:25:19 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(char **nbr)
{
    int i = 0;
    while (nbr[i])
        free(nbr[i++]);
    free(nbr);
}
void ft_check(char **nbr)
{
    int i;
    int j;

    i = 0;
    while (nbr[i])
    {
        j = 0;
        if (nbr[i][0] == '-' || nbr[i][0] == '+')
            j = 1;
        if (!nbr[i][j] || !ft_isdigit(nbr[i][j]))
        {
            write(2, "Error\n", 6);
            //ft_free(nbr);
            return ;
        }
        while (nbr[i][j])
        {
            if (!ft_isdigit(nbr[i][j]))
            {
                write(2, "Error\n", 6);
                //ft_free(nbr);
                return ;
            }
            j++;
        }
        i++;
    }
}
