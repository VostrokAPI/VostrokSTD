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

STATIC_LIB			= $(DIST)/$(NAME).a
DYNAMIC_LIB			= $(DIST)/$(NAME).so

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

ifdef NO_HIDE
	CFLAGS += -DNO_HIDE=1
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
	$(AS) $< -o $@

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJDIR) $(OBJS_ASM) $(OBJS)
	mkdir -p dist
	$(AR) $(STATIC_LIB) $(OBJS) $(OBJS_ASM)

$(DYNAMIC_LIB): $(OBJDIR) $(OBJS_ASM) $(OBJS)
	mkdir -p dist
	$(CC) $(CFLAGS) -shared $(OBJS) $(OBJS_ASM) -o $(DYNAMIC_LIB)

$(OBJDIR):
	mkdir -p $(sort $(addprefix $(OBJDIR)/, $(dir $(SRCS))))

clean:
	rm -rf $(OBJS) $(OBJS_ASM)

fclean: clean
	rm -rf $(STATIC_LIB) $(DYNAMIC_LIB) $(OBJDIR)
	rm -rf $(DIST)

re: fclean $(STATIC_LIB) $(DYNAMIC_LIB)

.PHONY: all clean fclean re
