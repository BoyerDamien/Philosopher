# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 09:03:17 by dboyer            #+#    #+#              #
#    Updated: 2021/02/22 12:39:12 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#									SOURCES
################################################################################

NAME    			=	philo_three

MAIN				= 	./srcs/main.c

SRCS    			=	./srcs/ft_atoi.c \
						./srcs/ft_cinset.c \
						./srcs/ft_isdigit.c \
						./srcs/ft_isspace.c \
						./srcs/ft_isnum.c \
						./srcs/ft_check_args.c \
						./srcs/ft_parse_args.c \
						./srcs/ft_table.c \
						./srcs/ft_clean_table.c \
						./srcs/ft_philo.c\
						./srcs/ft_do.c \
						./srcs/ft_time_to_milli.c\
						./srcs/ft_live.c \
						./srcs/ft_take_forks.c\
						./srcs/ft_sleep.c\
						./srcs/ft_eat.c\
						./srcs/ft_think.c\
						./srcs/ft_wait.c\
						./srcs/ft_get_timestamp.c\
						./srcs/ft_diff.c\
						./srcs/ft_output.c\
						./srcs/ft_try_actions.c\
						./srcs/ft_finish.c\
						./srcs/ft_kill_threads.c
                        
INCLUDES			=	-I ./includes

HEADERS				=	./includes/philo_three.h

OBJS_MAIN			= 	$(MAIN:.c=.o)
OBJS				= 	$(SRCS:.c=.o)

################################################################################
#								COMPILATION
################################################################################

CFLAGS  			= 	-Werror -Wall -Wextra -Ofast -pedantic ${INCLUDES}
CC      			= 	clang
RM      			= 	rm -f

################################################################################
#								Minishell Rules
################################################################################

%.o: %.c ${HEADERS}
	$(CC) $(CFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(OBJS) $(OBJS_MAIN)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} -lpthread

clean   :
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

################################################################################
#									Extra Rules
################################################################################

run 	:	all
	./${NAME}

norm	:	fclean
	norminette ${SRCS} ${HEADERS}

.PHONY  :	all clean fclean re bonus%
