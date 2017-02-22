/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:52:09 by rvinnako          #+#    #+#             */
/*   Updated: 2017/01/17 19:23:35 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	sastantua(int size);

int		main(int size, char *sizev[])
{
	if (size < 2)
		return (0);

	sastantua(atoi(sizev[1]));
}
