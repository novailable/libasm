UNAME := ${shell uname}

NAME = libasm.a
NASM = nasm
ifeq ($(UNAME), Darwin)
	NASMFLAGS = -f macho64 
else ifeq ($(UNAME), Linux)
	NASMFLAGS = -f elf64
endif

RM = rm -rf

SRCS = ft_strlen.s

OBJS = ${SRCS:.s=.o}

all: ${NAME}
		

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}
		
%.o : %.s
		${NASM} ${NASMFLAGS} $< -o $@

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

test: cc main.c libasm.a

.PHONY: all clean fclean re