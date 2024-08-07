### PROGRAM NAME ###
NAME		:= so_long

### UTILS ###
CC 			:= clang
CFLAGS 		:= -Wall -Wextra -Werror -Imlx -g3
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
MAC_FLAG	:= -framework OpenGL -framework AppKit
RM 			:= rm -rf
X11			:= -I/opt/X11/include

### COLORS ###
DEFAULT    	:= \033[0m
BLACK    	:= \033[0;30m
RED        	:= \033[0;31m
DRED		:= \033[0;31;5m
GREEN    	:= \033[0;32m
UGREEN    	:= \033[4;32m
YELLOW    	:= \033[;33m
BLUE    	:= \033[0;34m
PURPLE    	:= \033[0;35m
CYAN    	:= \033[0;36m
BWHITE    	:= \033[1;37m
NEW			:= \r\033[K

### DIRECTORIES ###
SRC_DIR 	:= src
INCLD_DIR 	:= include
OBJS_DIR 	:= objs
LIBS_DIR 	:= libs
LIBFT_DIR 	:= $(LIBS_DIR)/libft
LIBMLX_DIR = $(LIBS_DIR)/mlx


### FILES ###
INCLUDES	:= -I${INCLD_DIR}/ \
	-I${LIBFT_DIR}/${INCLD_DIR}/ \
	-I${LIBMLX_DIR}/

INCLD_FLAG 	:= ${INCLUDES}
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx.a

SRC :=	game_init.c \
		map_checks.c \
		map_checks2.c \
		map_draw.c \
		player.c \
		so_long.c \
		utils.c

SRC 		:= ${strip ${SRC}}
OBJS 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRC}}
DEPS		:= ${patsubst %.c,${OBJS_DIR}/%.d,${SRC}}

### PROJECT ###

.PHONY: all
all: ${NAME}

${NAME}: ${LIBFT} $(LIBMLX) ${OBJS}
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Building:${DEFAULT}${BWHITE} $@${DEFAULT}"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(MAC_FLAG) -o $(NAME)
	@printf "\n"

-include ${DEPS}
${OBJS_DIR}/%.o: ${SRC_DIR}/%.c
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Building:${DEFAULT} $<"
	@mkdir -p ${OBJS_DIR}
	@$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include $(X11) -c $< -o $@

.PHONY: clean
clean:
	@printf "${PURPLE}[${NAME}] ${RED}Obliterating ${DEFAULT}${OBJS_DIR} files\n"
	@${RM} ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	@printf "${PURPLE}[${NAME}] ${RED}Obliterating ${DEFAULT}${NAME}\n"
	@${RM} ${NAME} @${DEP_FLAGS}

.PHONY: re
re: fclean all

### LIBFT ###
${LIBFT}:
	@make -C ${LIBFT_DIR} ${MAKE_FLAG}

$(LIBMLX):
	@make -C ${LIBMLX_DIR} ${MAKE_FLAG}

.PHONY: cleanlib
cleanlib:
	@make -C ${LIBFT_DIR} clean ${MAKE_FLAG}

.PHONY: fcleanlib
fcleanlib:
	@make -C ${LIBFT_DIR} fclean ${MAKE_FLAG}
	@printf "${DRED}[${LIBFT_DIR}] Lib obliterated\n"

.PHONY: relib
relib:
	@make -C ${LIBFT_DIR} re ${MAKE_FLAG}

### NORM ###
.PHONY: norm
norm: ; @make -C ${LIBFT_DIR} norm ${MAKE_FLAG}
	@norminette ${SRC_DIR} ${INCLD_DIR} | awk '/Error/ {print; found=1} END \
	{if {!found} {print "${PURPLE}[${NAME}] ${DEFAULT}Norm: ${BWHITE}OK${DEFAULT}"; exit 0 }; exit 1 }'
