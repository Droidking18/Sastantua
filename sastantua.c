/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:10 by dkaplan           #+#    #+#             */
/*   Updated: 2018/02/15 17:08:31 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_base(int i)
{
	if (i % 2 == 0)
		i = 6 * (i / 2) * (i / 2) + 14 * (i / 2) - 1;
	else
		i = 6 * ((i + 1) / 2) * ((i + 1) / 2) + 8 * ((i + 1) / 2) - 7;
	return (i);
}

void	ft_line(int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		putchar('-');
		j++;
	}
}

void	ft_block(int i, int j, int k, int l)
{
	int door;
	int charc;

	door = 1 + 2 * ((j - 1) / 2);
	charc = 0;
	while (charc < k)
	{
		if (charc == 0)
			putchar('/');
		else if (charc == k - 1)
			ft_putchar(92);
		else
		{
			if (j == i && charc >= (k - door) / 2
					&& charc < (k + door) / 2 && 2 + j - l <= door)
				if (door >= 5 && l == 2 + j - door / 2 - 1
						&& charc == (k + door) / 2 - 2)
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
			ft_line(3);
			ft_block(i, floor, width, step);
			ft_putchar('\n');
			step++;
		}
		floor++;
		width += 4 + 2 * ((floor - 2) / 2);
	}
}

int main (void)
{
		sastantua(3);

}
