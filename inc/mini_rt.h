/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:39 by jaeshin           #+#    #+#             */
/*   Updated: 2023/11/03 15:51:17 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

// Keycodes
# define ESC 53
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

typedef struct s_rt
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*info_img;
	int		bbp;
	int		size_line;
	int		endian;
}	t_rt;

#endif
