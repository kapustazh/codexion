YELLOW	= \033[33m
GREEN	= \033[32m
WHITE	= \033[37m
RESET	= \033[0m

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread -g

NAME	= codexion

SRC_DIR		= src
INC_DIR		= includes

SRCS = $(SRC_DIR)/main.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I$(INC_DIR)

all: $(NAME)


$(NAME): $(OBJS)
	@$(CC)	$(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Making $(NAME)$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS) $(SRC_DIR)/*.o
	@echo "$(GREEN)clean$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
