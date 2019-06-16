/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:51:56 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 03:26:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define O	0x33
# define Z	0x63
# define Z1	0x36
# define Z2	0x132
# define Z3	0x231
# define I	0x1111
# define I1	0xF
# define T	0x27
# define T1 0x72
# define T2	0x131
# define T3	0x232
# define L	0x71
# define L1 0x74
# define L2	0x17
# define L3	0x47
# define L4	0x311
# define L5	0x322
# define L6	0x113
# define L7	0x223

typedef struct		s_matrix
{
	unsigned		x;
	unsigned		y;
	char			name;
	struct s_matrix	*root;
	struct s_matrix	*top;
	struct s_matrix	*right;
	struct s_matrix	*bot;
	struct s_matrix	*left;
}					t_matrix;

typedef struct		s_stack
{
	t_matrix		*res;
	unsigned		edge;
	struct s_stack	*left;
	struct s_stack	*right;
}					t_stack;

typedef struct		s_dlx
{
	t_matrix		*knut;
	t_stack			*res;
	int				*figures;
	int				edge;
	int				equal;
}					t_dlx;

int					fillit(const int fd, int opt);
int					ft_read(const int fd, char **read);
int					*identify(int len, char **read);
int					bitmove(int bits, char map);
int					ft_error(void);
int					solve(t_dlx **box, int opt);
int					ft_sqrt(int nb);
int					buildmatrix(t_dlx *box);
int					header_lst_str(t_matrix **root, unsigned len);
int					buildsets(t_matrix **root, int *figures, unsigned len);
int					new_lst_subset(unsigned last, t_matrix *root, int lvl,
					unsigned len);
int					algorithm_dlx(struct s_dlx *box, int stage);
int					direct_print(t_dlx **box);
void				del_stack(t_stack *end, t_stack *start);
void				clean_matrix(t_matrix **root);
void				recovery_lst_col(t_matrix *rec);
void				recovery_sets(t_matrix *rec);
void				del_sets(t_matrix *start);
void				del_lst_col(t_matrix *del);
void				printres(t_dlx *box);
void				sew(t_matrix *knut);
void				ft_links(t_matrix *new, t_matrix *ptr);
void				printmatrix(t_matrix *root);
int					backtracking(t_dlx *box);
t_stack				*add_to_stack(t_stack *stack, t_matrix *res);
t_stack				*new_lst_stack(t_matrix *res);
t_matrix			*del_lst_str(t_matrix *del);
t_matrix			*recovery_lst_str(t_matrix *rec);
t_matrix			*newlst(t_matrix *root, unsigned x, unsigned y, char name);
unsigned			new_lst_set(t_matrix *root, int figure, int lvl,
					unsigned len);

#endif
