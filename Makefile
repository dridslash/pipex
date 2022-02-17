CC = cc -c

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_split.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strtrim.c \
	get_path.c \
	ft_pipe.c \
	check_error_fork.c \
	count_argc.c \
	fork_for_child_cmdone.c \
	fork_for_child_cmdtwo.c \
	get_params.c \
	ft_strnstr.c

OBJS = ${SRCS:.c=.o}

LIB = pipex.a

REM = rm -f

ARV = ar -rcs

.c.o :
	${CC} ${CFLAGS} $< -o $@
	${ARV} $(LIB) $@

all : $(LIB)
$(LIB) : $(OBJS)
	cc ${CFLAGS} pipex.c ${LIB} -o pipex

clean :
	${REM} ${OBJS} pipex

fclean : clean
	${REM} ${LIB}

re : fclean all

.PHONY : all clean fclean re
