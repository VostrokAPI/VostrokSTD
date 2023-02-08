AUTHOR = https://github.com/Unam3dd
NAME = libvsstd
CC = gcc
AS = as
AR = ar rcs
VS_VER	= 0.0.1
VERSION = $(shell $(CC) --version | head -n1)
CFLAGS = -Wall -Wextra -Werror -Iinc

OBJDIR = obj
DIST = dist

vpath %.c src
vpath %.s src
vpath %.h inc

##################################
#
#		COLOR
#
##################################

GREEN 	= \033[38;5;82m
RED   	= \033[38;5;196m
YELLOW 	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;207m
LBLUE	= \033[38;5;45m
BLUE	= \033[38;5;26m
DGREY	= \033[90m
RESET 	= \033[00m

NUM_CF		= $(shell ls -lR src/ | grep -F .c | wc -l)
cnt			= 2
cnta		= 2
PERC		= 0
APERC		= 0
NUM_AF		= $(shell -ls -lR src/ | grep -F .s | wc -l)


##############################################
#
#
#			Assembly Source Files
#
#
##############################################

SRCS_ASM				=	$(shell find src -iname "*.s" -type f -print)
OBJS_ASM				=	$(addprefix $(OBJDIR)/, $(SRCS_ASM:.s=.o))

##############################################
#
#
#			C Source Files
#
#
##############################################

SRCS 				=	$(shell find src -iname "*.c" -type f -print)
OBJS				=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

##############################################
#
#
#				OUTPUT
#
#
##############################################

STATIC_LIB			= $(DIST)/$(NAME).a
DYNAMIC_LIB			= $(DIST)/$(NAME).so

##############################################
#
#
#				TESTS
#
#
##############################################

TEST_DIR = tests
TESTS = $(shell find tests -iname "main.c" -print)

ifdef DEBUG
	CFLAGS	+= -g
endif

ifdef OSIZE
	CFLAGS += -Os
endif

ifdef OFAST
	CFLAGS += -Ofast
endif

ifdef O3
	CFLAGS += -O3
endif

ifdef 32
	CFLAGS += -m32
else
	CFLAGS += -m64
endif

define credits
\t\tVostrok API
\t\tVersion\t:\t$(VS_VER)
\t\tModules Name\t:\t$(NAME)
\t\tCC Version\t:\t$(VERSION)
\t\tGithub\t:\thttps://github.com/Vostrok/
\t\tAuthor\t:\t$(AUTHOR)


endef
export credits

all: CREDITS $(STATIC_LIB) $(DYNAMIC_LIB)

CREDITS:
	@printf "$$credits"

obj/%.o: %.s
	@printf "$(GREEN)[$(LBLUE)+$(GREEN)] ASM Files Create... $(GREEN)$<$(GREEN) [$(LBLUE) $(APERC)%% $(GREEN)]$(RESET)                \r"
	@$(AS) $< -o  $@
	@$(eval APERC=$(shell echo "$(cnta)/$(NUM_CF)*100" | bc -l | tr '.' '\n' | head -n 1))
	@$(eval cnta=$(shell echo $$(($(cnta)+1))))

obj/%.o: %.c
	@printf "$(GREEN)[$(LBLUE)+$(GREEN)] C Files Create... $(GREEN)$<$(GREEN) [$(LBLUE) $(PERC)%% $(GREEN)]$(RESET)                \r"
	@$(CC) $(CFLAGS) -c $< -o  $@
	@$(eval PERC=$(shell echo "$(cnt)/$(NUM_CF)*100" | bc -l | tr '.' '\n' | head -n 1))
	@$(eval cnt=$(shell echo $$(($(cnt)+1))))

$(STATIC_LIB): $(OBJDIR) $(OBJS_ASM) $(OBJS)
	@mkdir -p dist
	@printf "\r\n$(GREEN)[$(LBLUE)+$(GREEN)] $(LBLUE)$(NAME).a was created !\n$(RESET)"
	@printf "$(GREEN)[$(LBLUE)+$(GREEN)] Build type : Static linked\n"
	@$(AR) $(STATIC_LIB) $(OBJS) $(OBJS_ASM)

$(DYNAMIC_LIB): $(OBJDIR) $(OBJS_ASM) $(OBJS)
	@printf "\r\n$(GREEN)[$(LBLUE)+$(GREEN)] $(LBLUE)$(NAME).so was created !\n$(RESET)"
	@printf "$(GREEN)[$(LBLUE)+$(GREEN)] Build type : dynamic linked shared object (SO)\n$(RESET)"
	@mkdir -p dist
	@$(CC) $(CFLAGS) -shared $(OBJS) $(OBJS_ASM) -o $(DYNAMIC_LIB)

$(OBJDIR):
	@mkdir -p $(sort $(addprefix $(OBJDIR)/, $(dir $(SRCS))))

clean:
	@printf "$(GREEN)[$(LBLUE)+$(GREEN)] $(LBLUE)Clean Object files !\n$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(STATIC_LIB) $(DYNAMIC_LIB) $(OBJDIR)
	@rm -rf $(DIST)

re: fclean $(STATIC_LIB) $(DYNAMIC_LIB)

tests: $(TESTS) $(STATIC_LIB)
	@printf "$(GREEN)[$(LBLUE)+$(GREEN)] $(LBLUE)Compile Test : $< \n$(RESET)"
	@$(CC) $(CFLAGS) -Iinc -L. $< -o a.out $(STATIC_LIB)
	@./a.out
	@rm -rf ./a.out

.PHONY: all clean fclean re
