/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:54:50 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/22 11:53:20 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_READER_H
# define TGA_READER_H

# include "../libft/libft.h"
# include "../libui/SDL2/SDL.h"
# include <fcntl.h>
# include <sys/stat.h>


typedef struct		s_pixel
{
	unsigned char 	a;
	unsigned char 	r;
	unsigned char 	g;
	unsigned char 	b;
//	struct s_pixel	*next;
//	struct s_pixel	*bf;
}					t_pixel;

typedef struct		s_tga
{
	t_pixel			*cm;
	t_pixel			*pxl;
	t_pixel			*done;
	char			*str;
	unsigned char	*colormap;
	unsigned char	*file;
	int				nb_elem;
	int				cm_begin;
	int				w;
	int				h;
	int				bits_cm;	//number of bits per palette entry 15,16,24,32
	int				color_type; // type of colour map 0=none, 1=has palette
	int				compress; 	//type of image 0=none,1=indexed,2=rgb,3=grey,+8=rle packed
	int				bitspix;	// image bits per pixel 8,16,24,32
	int				alpha;
	int				len_cm;		// number of colours in palette
}					t_tga;

//rle.c
void				rle_uncompress(t_tga *tga);

// tga_reader_file.c
void				hdr_parser(t_tga *tga, unsigned char *hdr);
int					count_n_malloc(t_tga *tga, char *str);
int					get_data_tga(t_tga *tga, const char *path);
int					tga_load(t_tga *tga, const char *path);
int					read_hdr(t_tga *tga, int fd);
int					check_tv_signature(t_tga *tga);
int					get_data_tga(t_tga *tga, const char *path);
int					read_data(t_tga *tga, int fd);
int					read_cm(t_tga *tga, int fd);

//set_pxl_color.c
void				range_pxl(t_tga *tga);

//set_data_pxl.c.c
void				fill_pxl(t_tga *tga, int i, int mode);
void				fille_pxl_from_cm(t_tga *tga);
void				fill_data(t_tga *tga, int mode);
void				create_pxl(t_tga *tga);

//tga_type_read.c
void				read_color(t_pixel *tab, int bits, unsigned char *file, int pos);

//rle_color.c
int					loadnew(int bpp, unsigned char *n, unsigned char *file, int mode);

SDL_Surface			*set_surface(t_tga *tga);
SDL_Surface			*ui_make_surface(int height, int width);
SDL_PixelFormat		*fill_pxlformat(SDL_PixelFormat *fmt);

#endif
