S = src/
O = obj/
I = inc/

SRC = $(wildcard $(S)*.c)
OBJ = $(patsubst $(S)%.c,$(O)%.o,$(SRC))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I $(I)
RM = rm -f
RMDIR = rm -rf
NAME = client

all: $(NAME)

$(O):
		@mkdir -p $@

$(OBJ): | $(O)

$(O)%.o : $(S)%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $@

cleanobj:
		$(RM) $(wildcard $(O)*.o)

cleanobjdir: cleanobj
		$(RMDIR) $(O)

clean: cleanobjdir

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
