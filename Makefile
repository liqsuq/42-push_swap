NAME := push_swap
SOURCE := main.c sort.c calc.c push.c swap.c rotate.c misc.c
OBJECT := $(SOURCE:.c=.o)
BONUS := checker
BONSRC := bonus/checker.c bonus/command.c \
          bonus/push.c bonus/swap.c bonus/rotate.c misc.c
BONOBJ := $(BONSRC:.c=.o)
LFTDIR := libft
LFT := $(LFTDIR)/libft.a
CFLAGS := -Wall -Wextra -Werror -I$(LFTDIR) -I.

$(NAME): $(LFT) $(OBJECT)
	$(LINK.o) $(OBJECT) $(LFT) -o $@

$(BONUS): $(LFT) $(BONOBJ)
	$(LINK.o) $(BONOBJ) $(LFT) -o $@

$(LFT): | $(LFTDIR)
	$(MAKE) -C $(LFTDIR)

$(LFTDIR):
	git clone https://github.com/liqsuq/libft

all: $(NAME)

bonus: $(BONUS)

clean:
	-$(MAKE) -C $(LFTDIR) clean
	$(RM) $(OBJECT) $(BONOBJ)

fclean: clean
	$(RM) -r $(LFTDIR)
	$(RM) $(NAME) $(BONUS)

re: fclean all
