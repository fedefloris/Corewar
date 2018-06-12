/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:57:57 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/12 16:11:32 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "libft.h"

# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE

# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3

# define MAX_ARGS_NUMBER 4
# define MAX_PLAYERS 4
# define MEM_SIZE (4 * 1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define REG_NUMBER 16

# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10

typedef char	t_arg_type;

# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8

# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct	s_header
{
	unsigned int	magic;
	char			*prog_name;
	unsigned int	prog_size;
	char			*comment;
}				t_header;

typedef struct	s_op
{
	char		*opname;
	int			param_count;
	int			param_type[3];
	int			opcode;
	int			cycles;
	char		*description;
	int			acb;
	int			half_size;
}				t_op;

typedef struct	s_line
{
	char			*label;
	char			*opname;
	int				opcode;
	char			*param[3];
	int				param_type[3];
	int				param_count;
	t_list			*bytecode;
	struct s_line	*next;
	struct s_line	*last;
}				t_line;

typedef struct	s_label
{
	char			*name;
	int				dist;
	char			*line;
	int				line_nb;
	int				used;
	struct s_label	*next;
}				t_label;

typedef struct	s_error
{
	char			*description;
	char			*line;
	int				line_nb;
	struct s_error	*next;
}				t_error;

typedef struct	s_frame
{
	t_header	*header;
	t_line		*lines;
	t_label		*request;
	t_label		*declare;
	size_t		bytecount;
	t_error		*errors;
}				t_frame;

int				ft_input(int fd, t_frame *frame);
char			*ft_line(char *s, t_frame *frame);
char			*ft_header(char *s, int name, t_frame *frame);
char			*ft_initline(t_line **line);
char			*ft_get_opname(char **s, char **opname);
char			*ft_get_label(char **s, char **label);
void			ft_push_line(t_line *line, t_frame *frame);
int				ft_push_bytecode(t_list **bytecode, char c);
char			*ft_get_arguments(char *s, t_line *line);
int				ft_error(char *line, char *msg, int line_nb,
					t_error **err_list);
void			ft_error_output(t_error *error);
int				ft_valid_arg(char *s);
int				ft_argno(char **arg);
char			*ft_produce_line(t_frame *frame, char *str, int nb);
char			*ft_push_decl(char *name, int dist, t_frame **frame);
char			*ft_push_request(char *name, t_frame **frame, char *str, int nb);
void			ft_free_label(t_label **labels);
void			ft_free_lines(t_line **lines);
void			ft_free_frame(t_frame **frames);
int				ft_line_bytes(t_line *line, t_op op, t_frame *f);
int				ft_fill_dist(t_label *req, t_label *first, t_error *error);
void			ft_output(int fd, t_frame *f, t_op *op);
void			ft_get_arg_byte(t_line *line, int nb, int half, t_label *req);
#endif
