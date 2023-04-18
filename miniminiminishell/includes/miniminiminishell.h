#ifndef MINIMINIMINISHELL_H
# define MINIMINIMINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "./environment_variables.h"
# include "./token.h"

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

int	g_exit_status; // 시그널 받을 때도 바뀌어야 함

typedef struct s_info
{
	int				stdin;
	int				stdout;
	int				syntax_error;
	struct termios  ms_termios;
	t_env_node		*env_list;
	char			**path_list;//execve(명령어, 인자, 환경변수)
}	t_info;

typedef struct s_redirection
{
	char	*type;
	char	*file;
	struct 	s_redirection *next;
}	t_redirection;

typedef struct s_cmd
{
	char			**argv;
	t_redirection	*redirection;
	int				pipe[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;
// 프린트 해줄라고 만든 놈
void			print_token_list(t_token *token_list);

/* lexical_analysis dir */
t_token			*lexical_analysis(t_info *info, char *input);
void			handle_heredoc_limiter(t_info *info, t_token *token_list);
void			handle_quotes(t_info *info, t_token *token_list);
void			handle_environment_variables(t_info *info, t_token *token_list);
void			seperate_token_by_arg(t_token *token_list, char *arg);
void			handle_chunk(t_token **token_list);
void			merge_continuous_argv_token(t_token **token_list);
void			remove_space_token(t_token **token_list);

/* syntax_analysis */
int				syntax_analysis(t_token *token_list);

/* cmd_list dir */
t_cmd			*make_cmd_node(void);
t_redirection	*make_redirection_node(t_token *token_list);
int				get_argv_cnt(t_token *token_list);
t_cmd			*create_cmd_list(t_token *token_list);
void			free_cmd_list(t_cmd **cmd_list);

/* bult_in dir */
int				ms_cd(t_info *info, char **argv);
int				ms_echo(char **argv);
int				ms_env(t_env_node *env_list);
int				ms_exit(t_info *info, t_cmd *cmd_list);
int				ms_export(t_info *info, char **argv);
int				ms_pwd(void);
int				ms_unset(t_info *info, char **argv);

/* utils dir - utils.c */
void			ms_error(char *blame, char *blame2);
int				is_tokenable_sep(char c);
void			free_2d_arr(char **arr);
void			free_strs(char *str1, char *str2, char *str3, char *str4);
char			*join_strs(char *str1, char *str2, char *str3);

/* utils dir - signal.c */
void			signal_handler(int signum);
void			parent_handler(int signum);
void			heredoc_handler(int signum);
void			quit_handler(int signum);
void			set_signal(void);

/* excute dir */
char			*get_cmd_file(char *cmd, char **path_list);
void			print_command_not_found(char **path_list, char *str);
int				check_builtin(t_info *info, t_cmd *cmd_list, int cnt);
void			ms_execute(t_info *info, t_cmd *cmd_list);
void			execute_heredoc(t_info *info, t_cmd *cmd_list);
void			unlink_heredoc_tmp(t_cmd *cmd_list);
int				set_redirection_fd(t_cmd *cmd_list, int cnt);
void			execute_single_cmd(t_info *info, t_cmd *cmd_list);
void			execute_multiple_cmd(t_info *info, t_cmd *cmd_list);


#endif