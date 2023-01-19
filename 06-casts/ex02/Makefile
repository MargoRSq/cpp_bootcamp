include makefile.files

NAME = base

INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g

CC = c++
RM = rm -rf

all : ${NAME}

.SECONDEXPANSION:
${OBJS}: $$(patsubst %.o, %.cpp, $$(subst ${OBJS_DIR}/, ${SRCS_DIR}/, $${@}))
	@mkdir -p ${OBJS_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} $^ -o $@
clean :
	${RM} ${OBJS_DIR}

fclean : clean
	${RM} ${NAME}

re : fclean all

-include ${DEPS}

.PHONY : re clean fclean all