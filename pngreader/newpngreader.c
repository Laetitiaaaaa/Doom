/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpngreader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:36:24 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/10 20:31:55 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

int			ft_abs(int	value)
{
	value = value < 0 ? -value : value;
	return (value);
}

int			ft_power(int value, int power)
{
	if (power == 0)
		return (1);
	while (power > 1)
	{
		value *= 16;
		power -= 1;
	}
	return (value);
}

int			hextoint(unsigned char *str, int len)
{
	int 	i;
	int		index;

	index = 0;
	i = 0;
	while (index < len)
	{
		if (str[index] >= 'A')
			i += ((str[index] - 'A') + 10) * (ft_power(16, ft_abs(index - (len - 1))));
		else
			i += (str[index] - '0') * (ft_power(16, ft_abs(index - (len - 1))));
		index++;
	}
	return (i);
}

void		stopload(t_png *file)
{
	if (file != NULL)
	{
		file->name != NULL ? free (file->name) : 0;
		free(file);
	}
}

void		loadpng(char *path)
{
	t_png	*file;

	printf("Yo\n");
	file = ft_memalloc(sizeof(t_png));
	printf("Yo\n");
	file->name = ft_strdup(path);
	printf("Yo\n");
	file->name == NULL ? stopload(file) : 0;
	printf("Yo\n");
	file->chunk = NULL;
	printf("Yo\n");
	checkpath(file);
	printf("PATH\n");
	checksignature(file);
	printf("SIGNATURE\n");
	loadIHDR(file);
	printf("IHDR\n");
	
	loadchunk(file);
	printf("CHUNK\n");
	checkprint(file);
	printf("PRINT\n");
}
