/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:10 by dkaplan           #+#    #+#             */
/*   Updated: 2018/02/16 10:07:20 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_base(int size)
{
	if (size % 2 == 0)
		size = 6 * (size / 2) * (size / 2) + 14 * (size / 2) - 1;
	else
		size = 6 * ((size + 1) / 2) * ((size + 1) / 2) + 8 * ((size + 1) / 2) - 7;
	return (size);
}

void	ft_line(int i)
{
	int charc;

	charc = 0;
	while (charc < i)
	{
		putchar('-');
		charc++;
	}
}

void	ft_block(int size, int floor, int width, int step)
{
	int door;
	int charc;

	door = 1 + 2 * ((floor - 1) / 2);
	charc = 0;
	while (charc < width)
	{
		if (charc == 0)
			putchar('/');
		else if (charc == width - 1)
			ft_putchar(92);
		else
		{
			if (floor == size && charc >= (width - door) / 2
					&& charc < (width + door) / 2 && 2 + floor - step <= door)
				if (door >= 5 && step == 2 + floor - door / 2 - 1
						&& charc == (width + door) / 2 - 2)
					ft_putchar('$');
			else
				ft_putchar('|');
			else
				ft_putchar('*');
		}
	charc++;
	}
}

void	sastantua(int i)
{
	int floor;
	int height;
	int step;
	int width;

	if (i < 1)
		return ;
	floor = 1;
	width = 1;
	while (floor <= i)
	{
		height = 2 + floor;
		step = 0;
		while (step < height)
		{
			width += 2;
			ft_line((ft_base(i) - width) / 2);
			ft_block(i, floor, width, step);
			ft_putchar('\n');
			step++;
		}
		floor++;
		width += 4 + 2 * ((floor - 2) / 2);
	}
}

int main ()
{
		sastantua(3);
}
