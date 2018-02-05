##
## Makefile for 42sh in /home/anthony/documents/repository/PSU_2015_42sh
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Tue May 31 15:16:00 2016 Anthony LECLERC
## Last update Wed Jun  8 21:10:03 2016 teisse_m
##

# CC		=	/home/teisse_m/afl/afl-2.13b/afl-gcc

CC		=	gcc
ERRORS		=	errlog~
NAME		=	42sh

GREEN		=	""
RED		=	""
CYAN		=	""
ENDC		=	""

OK		=	"[OK]"
WARNING		=	"[WARNING]"
KO		=	"[ERROR]"

ECHO		=	echo
NL		=	"\n---------------------"

SRC		=	src/main.c			\
			src/line_edit_loop.c		\
			src/init_shell.c		\
			src/misc/my_putchar.c		\
			src/misc/my_strlen.c		\
			src/misc/my_str_to_wordtab.c	\
			src/misc/my_strcpy.c		\
			src/misc/my_strcat.c		\
			src/misc/epur_str.c		\
			src/misc/my_strdup.c		\
			src/misc/my_putstr.c		\
			src/misc/my_perror.c		\
			src/misc/my_tabcpy.c		\
			src/misc/my_show_wordtab.c	\
			src/misc/is_num.c		\
			src/misc/is_separator.c		\
			src/misc/is_alpha_num.c		\
			src/misc/free_tab.c		\
			src/getline/get_next_line.c	\
			src/getline/reset_gnl.c		\
			src/getline/buf_free.c		\
			src/parsing/action_table.c	\
			src/parsing/lexer/get_and.c	\
			src/parsing/lexer/get_comma.c	\
			src/parsing/lexer/get_or_pipe.c	\
			src/parsing/lexer/get_redir.c	\
			src/parsing/lexer/is_word.c	\
			src/parsing/lexer/lexer.c	\
			src/parsing/llparser.c		\
			src/parsing/rules/A_state_rules.c \
			src/parsing/rules/E_state_rules.c \
			src/parsing/rules/Eps_rule.c	\
			src/parsing/rules/F_state_rules.c \
			src/parsing/rules/G_state_rules.c \
			src/parsing/rules/H_state_rules.c \
			src/parsing/rules/I_state_rules.c \
			src/parsing/rules/J_state_rules.c \
			src/parsing/rules/O_state_rules.c \
			src/parsing/rules/P_state_rules.c \
			src/parsing/rules/Q_state_rules.c \
			src/parsing/rules/S_state_rules.c \
			src/parsing/rules/T_state_rules1.c \
			src/parsing/rules/T_state_rules2.c \
			src/parsing/rules/W_state_rules.c \
			src/parsing/add_stack_elem.c	\
			src/parsing/pop_stack_elem.c	\
			src/parsing/replace_top_stack.c \
			src/parsing/get_word.c		\
			src/parsing/term_match.c	\
			src/parsing/pass_separator.c	\
			src/parsing/errors_msg/ambiguous.c \
			src/parsing/errors_msg/invalid_null_command.c \
			src/parsing/errors_msg/missing_name_redirect.c

BIN_TREE	=	src/binary_tree/new_node.c \
			src/binary_tree/clean_last_command.c \
			src/binary_tree/tree_manipulation/add_arg.c \
			src/binary_tree/tree_manipulation/add_cmd.c \
			src/binary_tree/tree_manipulation/add_down_left.c \
			src/binary_tree/tree_manipulation/add_down_right.c \
			src/binary_tree/tree_manipulation/add_file.c \
			src/binary_tree/tree_manipulation/add_pipe.c \
			src/binary_tree/tree_manipulation/add_up.c \
			src/binary_tree/tree_manipulation/add_first.c \
			src/binary_tree/tree_manipulation/add_right_redir.c \
			src/binary_tree/tree_manipulation/add_left_redir.c \
			src/binary_tree/tree_manipulation/add_list.c \
			src/binary_tree/free_binary_tree.c

SRC_EXEC_TEMP	=	src/execution/exec/exec_tree.c \
			src/execution/exec/execute_new_command.c \
			src/execution/exec/check_error_status.c \
			src/execution/exec/child_exec.c \
			src/execution/exec/exec_command_line.c \
			src/execution/exec/check_if_exec.c \
			src/execution/exec/dup_before_exec.c \
			src/execution/exec/exec_cmd_line.c \
			src/execution/exec/exec_no_path.c \
			src/execution/environment/my_wordtab_len.c \
			src/execution/environment/env_copy.c \
			src/execution/environment/free_wordtab.c \
			src/execution/environment/my_str_to_dot_wordtab.c \
			src/execution/env_var/get_paths.c \
			src/execution/env_var/is_env_var.c \
			src/execution/redirections/close_pipes.c \
			src/execution/redirections/direct_right_redir.c \
			src/execution/redirections/left_redir.c \
			src/execution/redirections/pipe_exec.c \
			src/execution/error/error.c

SRC_BUILTINS	=	src/Builtins/echo.c \
			src/Builtins/my_setenv.c \
			src/Builtins/my_unsetenv.c \
			src/Builtins/my_cd.c \
			src/Builtins/my_cd_second.c \
			src/Builtins/exec_builtins.c \
			src/Builtins/my_exit.c \
			src/Builtins/get_env_var.c \
			src/misc/my_strcompare.c \
			src/misc/my_tablen.c \
			src/Builtins/my_modif_env.c

SRC_HISTORY	=	src/history_file/update.c \
			src/history_file/show_history.c \
			src/history_file/cut_history.c \
			src/history_file/find_in_history.c

SRC_LINE_EDIT	=	src/line_edit/del_char.c \
			src/line_edit/left_key.c \
			src/line_edit/line_edit.c \
			src/line_edit/right_key.c \
			src/line_edit/write_char.c \
			src/line_edit/init_term.c \
			src/line_edit/word_left.c \
			src/line_edit/word_right.c \
			src/line_edit/start.c \
			src/line_edit/end.c \
			src/line_edit/destroy_line.c \
			src/line_edit/del.c \
			src/line_edit/kill_end.c

LIBS		=	-lncurses

OBJ		= 	$(SRC:.c=.o)
OBJ		+=	$(SRC_EXEC_TEMP:.c=.o)
OBJ		+=	$(BIN_TREE:.c=.o)
OBJ		+=	$(SRC_HISTORY:.c=.o)
OBJ		+=	$(SRC_BUILTINS:.c=.o)
OBJ		+=	$(SRC_LINE_EDIT:.c=.o)

lCFLAGS		+=	-W -Wall -Wextra
INC		=	-Iinclude/ -Iinclude/types

ifeq ($(DEBUG), 1)
CFLAGS		+=	-g -ggdb3 -DDEBUG
else
CFLAGS		+=	$(WERR)
endif


all:		$(NAME)

$(NAME): 	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(INC) && \
		$(ECHO) $(GREEN) $(OK) $(CYAN) $@ $(ENDC) $(NL) || \
		$(ECHO) $(RED) $(KO) $(CYAN)  $@ $(ENDC) $(NL)

erase:
		@rm -f $(ERRORS)
clean:		erase
		@rm -f $(OBJ)
		@$(ECHO) Deleting .o files...
fclean: 	clean
		@rm -f $(NAME)
		@$(ECHO) Deleting binary file...
re_:
		@$(ECHO) $(CYAN) Recompiling... $(ENDC)
re: 		re_ fclean all

%.o: 		%.c
		@$(CC) -c $< -o $@  $(CFLAGS) $(LIBS) $(INC) && \
		$(ECHO) $(GREEN) $(OK) $(RED) $< $(ENDC)  || \
		$(ECHO) $(RED) $(KO) $(RED) $< $(ENDC)

.PHONY: 	erase clean fclean re all
