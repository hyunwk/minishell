CC = gcc
CFLAGS = -Wextra -Wall -Werror
CFLAGS_DEBUG = -g
# -L : 라이브러리 경로 지정
AR = ar rcs

NAME = minishell
FORDER = srcs/
D_SET = set/
SRC_LIST = init.c\
		$(D_SET)find.c\
		$(D_SET)insert.c\
		$(D_SET)print.c\
		$(D_SET)util.c\

SRC = $(addprefix $(FORDER), $(SRC_LIST))
OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	make -C $(FORDER)libft/ bonus
	$(CC) $(CFLAGS) $^ -o $@ $(FORDER)libft/libft.a

all: $(NAME)

debug: $(OBJS)
	make -C $(FORDER)libft/ bonus
	$(CC) $(CFLAGS_DEBUG) $^ -o $@ $(FORDER)libft/libft.a 

fclean: clean
	rm -rf $(NAME)
	rm -rf $(FORDER)libft.a
	make fclean -C $(FORDER)libft/

clean:
	rm -rf $(OBJS)
	make clean -C $(FORDER)libft/

re: fclean all