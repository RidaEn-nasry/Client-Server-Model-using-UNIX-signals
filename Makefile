

# ==================================== Mandatory =================================

CLIENT =  ./mandatory/src/client.c
SERVER = ./mandatory/src/server.c

UTILS_SRCS = ./mandatory/utils/ft_atoi.c \
			./mandatory/utils/ft_putchar_fd.c \
			./mandatory/utils/ft_putnbr_fd.c \
			./mandatory/utils/ft_putstr_fd.c \
			./mandatory/utils/ft_strlen.c \
			./mandatory/utils/handle_errors.c 

INC = ./mandatory/include/minitalk.h

UTILS_OBJS = $(UTILS_SRCS:.c=.o)
CLIENT_OBJ = $(CLIENT:.c=.o)
SERVER_OBJ = $(SERVER:.c=.o)

all: NAME $(INC)

NAME : $(UTILS_OBJS) $(CLIENT_OBJ) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJS) -o $(CLIENT_EXE)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJS) -o $(SERVER_EXE)



# ==================================== Bonus =========================================

CLIENT_BONUS = ./bonus/src/client_bonus.c
SERVER_BONUS = ./bonus/src/server_bonus.c

INC_BONUS = ./bonus/include/minitalk.h

UTILS_SRCS_BONUS = ./bonus/utils/ft_atoi.c\
					./bonus/utils/ft_putchar_fd.c \
					./bonus/utils/ft_putnbr_fd.c \
					./bonus/utils/ft_putstr_fd.c \
					./bonus/utils/ft_strlen.c \
					./bonus/utils/handle_errors.c\
					./bonus/utils/ft_isacsii.c \

UTILS_OBJS_BONUS = $(UTILS_SRCS_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_BONUS:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_BONUS:.c=.o)

bonus: NAME_BONUS $(INC_BONUS)

NAME_BONUS: $(UTILS_OBJS_BONUS) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) $(UTILS_OBJS_BONUS) -o $(CLIENT_EXE)
	$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) $(UTILS_OBJS_BONUS) -o $(SERVER_EXE)

# ======================================================================================

CLIENT_EXE = client
SERVER_EXE = server

RM = rm -rf 
CFLAGS =  -Wall -Wextra -Werror

clean:
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	$(RM) $(UTILS_OBJS) $(UTILS_OBJS_BONUS)


fclean: clean
	$(RM) $(CLIENT_EXE) $(SERVER_EXE) 

re: fclean all

.PHONY: all clean fclean bonus 




