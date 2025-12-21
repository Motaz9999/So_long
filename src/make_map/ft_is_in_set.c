/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:02:20 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/12 19:53:11 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// but it in libft
// its  to see if the str have other chars 
// that is differ from the set to the str[n]
// 0 = something not from the set in str

int	ft_is_in_set_n(char *str, char *set, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (!ft_strchr(set, str[i]))
			return (0);
		i++;
	}
	return (1);
}
