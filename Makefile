S = src/
O = obj/
I = inc/

SRCs = $(wildcard $(S)server/*.c)
SRCc = $(wildcard $(S)client/*.c)
OBJs = $(patsubst $(S)server/%.c,$(O)server/%.o,$(SRCs))
OBJc = $(patsubst $(S)client/%.c,$(O)client/%.o,$(SRCc))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I $(I)
RM = rm -f
RMDIR = rm -rf
SERVER_NAME = server
CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

$(O)server:
		@mkdir -p $@
$(O)client:
		@mkdir -p $@

$(OBJs): | $(O)server
$(OBJc): | $(O)client

$(O)server/%.o : $(S)server/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(O)client/%.o : $(S)client/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME): $(OBJs)
		$(CC) $(OBJs) -o $@

$(CLIENT_NAME): $(OBJc)
		$(CC) $(OBJc) -o $@

cleanobj:
		$(RM) $(wildcard $(O)server/*.o) $(wildcard $(O)client/*.o)

cleanobjdir: cleanobj
		$(RMDIR) $(O)

clean: cleanobjdir

fclean: clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
