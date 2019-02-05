/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_one_sh.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:06:41 by schakor           #+#    #+#             */
/*   Updated: 2019/02/04 14:32:52 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTY_ONE_SH_H
# define TWENTY_ONE_SH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

# define SH_ENOMEM			1
# define SH_EINVAL			2
# define SH_ENOTTY			3

# define BUF_TMP			32
# define ENTER_KEY			10
# define DELETE_KEY			127
# define HOME_KEY			4741915
# define END_KEY			4610843
# define LEFT_KEY			4479771
# define RIGHT_KEY			4414235
# define UP_KEY				4283163
# define DOWN_KEY			4348699

typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;
typedef char				t_int8;
typedef short				t_int16;
typedef int					t_int32;
typedef long long			t_int64;

typedef struct termios		t_termios;

t_termios					g_cooked_tio;

typedef struct				s_envl
{
	char					*name;
	char					*value;
	struct s_envl			*next;
}							t_envl;

typedef struct				s_input
{
	char					*buffer;
	size_t					buf_i;
	size_t					bufsize;
	size_t					buftmp;
	t_uint8					bufkey[8];
}							t_input;

typedef struct				s_token
{
	char					*arg;
	int						identify;
	struct s_token			*next;
	struct s_token			*prev;
}							t_token;

typedef struct				s_ast
{
	char					*oper;
	struct s_ast			*left;
	struct s_ast			*right;
}							t_ast;

typedef struct				s_history
{
	char					*buffer;
	size_t					bufsize;
	size_t					buftmp;
	struct s_history		*next;
	struct s_history		*bfr;
}							t_history;

typedef struct				s_trie
{
	struct s_trie			*children;
	struct s_trie			*next;
	unsigned char			key;
	unsigned long long		value;
}							t_trie;

typedef struct				s_shell
{
	char					**env;
	t_envl					*envl;
	int						key;
	int						history_save;
	size_t					len_prompt;
	t_input					*in;
	t_history				*history;
	t_token					*tk;
	t_ast					*root;
	t_termios				cooked_tio;
	t_termios				raw_tio;
}							t_shell;

/*
**	ENVIRONNEMENT FUNCTIONS
*/

t_envl						*addlast_envl(t_envl *head, t_envl *new);
t_envl						*envarr_2_envl(char **env);
char						*get_env_val(t_envl *envl, char *name);
void						push_env(t_envl **envl, char *name, char *value);

/*
**	TERMINAL / SHELL FUNCTIONS
*/

t_shell						*init_shell(int ac, char **av, char **env);
void						init_terminal(t_shell *sh);
void						reset_terminal(void);

/*
**	READING FUNCTIONS
*/

void						read_raw_mode(t_shell *sh);
void						insert_buffer(t_shell *sh, char c);
void						increase_buffer(t_shell *sh);
void						delete_buffer(t_shell *sh);
void						display_prompt(t_shell *sh);

/*
**	TERMCAPS FUNCTIONS
*/

void						move_start(t_shell *sh);
void						move_left_cursor(t_shell *sh, size_t *index);
void						move_right_cursor(t_shell *sh, size_t *index);
void						delete_until_cursor(t_shell *sh, size_t index);
void						move_end(t_shell *sh);

/*
**	HISTORY FUNCTIONS
*/

void						up_history(t_shell *sh);
void						down_history(t_shell *sh);
void						add_history(t_shell *sh);
void						print_history(t_shell *sh);
void						switch_history(t_shell *sh);
void						history_from_file(t_shell *sh, char *path);
void						file_from_history(t_shell *sh, char *path);
int							listlen(t_history *list);
t_history					*new_hist(char *buf, size_t bufsize, size_t buftmp);
t_history					*add_hist(t_history *list, t_history *new_hist);
void						exclaim(t_shell *sh);

/*
**	SIGNAL FUNCTIONS
*/

void						ft_sig_handler(int signo);
void						ft_signal(int signo);

/*
**	CLEANING FUNCTIONS
*/

void						free_input(t_input *list);
void						free_envlst(t_envl *list);
void						free_history(t_history *list);
void						free_term(t_shell *sh);
void						fatal_exit(t_shell *sh, int code);

/*
**	LEXING FUNCTIONS
*/

void						lexer(t_shell *sh);

#endif
