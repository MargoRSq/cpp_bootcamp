NAME = phonebook

SRC_DIR = src
OBJ_DIR = objs
SRCS = $(addprefix src/, Contact.cpp)
OBJ = ${addprefix ${OBJ_DIR}/, ${SRCS:.cpp=.o}}
DEPS = ${OBJ:.o=.d}

INCLUDES = -Iincludes

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
DEBUG = -g

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) ${DEBUG} ${INCLUDES} -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf ${OBJ} ${OBJ_DIR}

fclean:	clean
	rm ${NAME}

re:	fclean all

.PHONY: all clean fclean re

-include ${DEPS}