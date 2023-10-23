S = src/
B = bonus/
O = obj/
Oo = obj_bonus/
I = inc/

SRCs = $(wildcard $(S)server/*.c)
SRCc = $(wildcard $(S)client/*.c)
SRCbs = $(wildcard $(B)server/*.c)
SRCbc = $(wildcard $(B)client/*.c)
OBJs = $(patsubst $(S)server/%.c,$(O)server/%.o,$(SRCs))
OBJc = $(patsubst $(S)client/%.c,$(O)client/%.o,$(SRCc))
OBJbs = $(patsubst $(B)server/%.c,$(Oo)server/%.o,$(SRCbs))
OBJbc = $(patsubst $(B)client/%.c,$(Oo)client/%.o,$(SRCbc))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -I $(I)
RM = rm -f
RMDIR = rm -rf
SERVER_NAME = server
CLIENT_NAME = client
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

all: $(SERVER_NAME) $(CLIENT_NAME)

$(O)server:
		@mkdir -p $@
$(O)client:
		@mkdir -p $@
$(Oo)server:
		@mkdir -p $@
$(Oo)client:
		@mkdir -p $@


$(OBJs): | $(O)server
$(OBJc): | $(O)client
$(OBJbs): | $(Oo)server
$(OBJbc): | $(Oo)client

all: $(SERVER_NAME) $(CLIENT_NAME)
bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(O)server/%.o : $(S)server/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(O)client/%.o : $(S)client/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(Oo)server/%.o : $(B)server/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(Oo)client/%.o : $(B)client/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME): $(OBJs)
		$(CC) $(OBJs) -o $@

$(CLIENT_NAME_BONUS): $(OBJbc)
		$(CC) $(OBJbc) -o $@

$(SERVER_NAME_BONUS): $(OBJbs)
		$(CC) $(OBJbs) -o $@

$(CLIENT_NAME): $(OBJc)
		$(CC) $(OBJc) -o $@

cleanobj:
		$(RM) $(wildcard $(O)server/*.o) $(wildcard $(O)client/*.o)
		$(RM) $(wildcard $(Oo)server/*.o) $(wildcard $(Oo)client/*.o)

cleanobjdir: cleanobj
		$(RMDIR) $(O)
		$(RMDIR) $(Oo)

clean: cleanobjdir

fclean: clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		$(RM) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
