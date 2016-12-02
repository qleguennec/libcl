PROJECT		=	libcl
BINDIR		?=	.
BUILDDIR	?=	build
NAME		=	$(BINDIR)/libcl.a

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g

BLACK		=	"\033[0;30m"
RED			=	"\033[0;31m"
GREEN		=	"\033[0;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[0;34m"
MAGENTA		=	"\033[0;35m"
CYAN		=	"\033[0;36m"
WHITE		=	"\033[0;37m"
END			=	"\033[0m"

PRINT		=	@printf COL$(PROJECT)$(END)'\t'
PRPROJ		=	$(subst COL, $(MAGENTA), $(PRINT))
PRRM		=	$(subst COL, $(CYAN), $(PRINT))

SRCEX		=
SRC			=	$(filter-out $(SRCEX), $(filter %.c, $(shell ls)))
OBJECTS		=	$(addprefix $(BUILDDIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(BUILDDIR)/%.o: %.c
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)
	$(PRPROJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(PRPROJ)
	@ar rc $(@) $(OBJECTS)
	@echo OK

.PHONY: clean sclean fclean re r

clean:
	$(PRRM)
	rm -rf $(BUILDDIR)

fclean: clean
	$(PRRM)
	rm -rf $(NAME)

re: fclean all
