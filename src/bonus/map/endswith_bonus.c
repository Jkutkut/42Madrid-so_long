/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endswith_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:58:45 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/04/19 19:10:35 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Checks whenever the given string ends with the given suffix
 * 
 * @param str String to check
 * @param end Suffix to check
 * @return int Result of the comparation (0: false, else true)
 */
int	endswith(char *str, char *end)
{
	int	str_len;
	int	end_len;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (str_len < end_len)
		return (0);
	return (!ft_strncmp(str + str_len - end_len, end, end_len));
}
