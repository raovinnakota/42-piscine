/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:36:35 by rvinnako          #+#    #+#             */
/*   Updated: 2017/01/15 21:02:20 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_calc_base(int size)
{
	int floor;
	int width;
	int floor_step;

	floor = 1;
	width = 1;
	floor_step = 4;
	while (floor <= size)
	{
		width += 2 * (2 + floor);
		floor++;
		width += floor_step;
		if (floor % 2 == 1 && floor < size)
			floor_step += 2;
	}
	width -= floor_step;
	return (width);
}

void	ft_putline(int space)
{
	int i;

	i = 0;
	while (i < space)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_putblocks(int size, int floor, int width, int step)
{
	int i;
	int door;

	door = 1 + 2 * ((floor - 1) / 2);
	i = 0;
	while (i < width)
	{
		if (i == 0)
			ft_putchar('/');
		else if (i == width - 1)
			ft_putchar('\\');
		else
		{
			if (floor == size && i >= (width - door) / 2
					&& i < (width + door) / 2 && 2 + floor - step <= door)
				if (door >= 5 && step == 2 + floor - door / 2 - 1
						&& i == (width + door) / 2 - 2)
					ft_putchar('$');
				else
					ft_putchar('|');
			else
				ft_putchar('*');
		}
		i++;
	}
}

void	sastantua(int size)
{
	int floor;
	int height;
	int step;
	int width;

	if (size < 1)
		return ;
	floor = 1;
	width = 1;
	while (floor <= size)
	{
		height = floor + 2;
		step = 0;
		while (step < height)
		{
			width = width + 2;
			ft_putline((ft_calc_base(size) - width) / 2);
			ft_putblocks(size, floor, width, step);
			ft_putchar('\n');
			step++;
		}
		floor++;
		width += 4 + 2 * ((floor - 2) / 2);
	}
}
