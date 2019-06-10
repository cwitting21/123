/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:51:56 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 20:53:28 by cwitting         ###   ########.fr       */
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
	int				s;
	char			name;
	struct s_matrix	*root;
	struct s_matrix *set_next;
	struct s_matrix	*set_prev;
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

int					fillit(const int fd, int opt);
int					ft_read(const int fd, char **read);
int					*identify(int len, char **read);
int					bitmove(int bits, char map);
int					ft_error(void);
int					solve(int *figures, int opt);
int					ft_sqrt(int nb);
int					buildmatrix(int *figures, t_matrix **knut, unsigned edge);
t_matrix			*newlst(t_matrix *root, unsigned x, unsigned y, char name);
int					header_lst_str(t_matrix **root, unsigned len);
int					buildsets(t_matrix **root, int *figures, unsigned len);
unsigned			new_lst_set(t_matrix *root, int figure, int lvl,
					unsigned len);
int					new_lst_subset(unsigned last, t_matrix *root, int lvl,
					unsigned len);
void				printmatrix(t_matrix *root);
void				ft_links(t_matrix *new, t_matrix *ptr);
t_stack				*backtracking(t_matrix **knut, int *figures, int opt);
int					algorithm_dlx(t_matrix *knut, t_stack *stack, int figures);
void				sew(t_matrix *knut);
t_stack				*add_to_stack(t_stack *stack, t_matrix *res);
t_stack				*new_lst_stack(t_matrix *res);
t_stack				*del_lst_stack(t_stack *lstdel);
void				printres(t_stack *res);
void				del_lst_col(t_matrix *del, int stage);
t_matrix			*del_lst_str(t_matrix *del, int stage);
void				del_sets(t_matrix *start, int stage);
void				del_subset(t_matrix *end, t_matrix *start, int stage);
void				recovery_subset(t_matrix *rec, int stage);
void				recovery_sets(t_matrix *rec, int stage);
t_matrix			*recovery_lst_str(t_matrix *rec, int stage);
void				recovery_lst_col(t_matrix *rec, int stage);
void				recovery(t_matrix *rec, int stage);
int					select_next_guess(t_stack **stack, int figures);
void				del_cover(t_matrix *start, int stage);

#endif
