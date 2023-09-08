# Compiler
CC = gcc

# Compilers files
CFILES = *.c

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror -pedantic

# Compiler Libraries
CLIBS = -lSDL2

# Compiler Output
COUT = visualSA





all: ${CFILES}
	${CC} ${CFLAGS} ${CFILES} -o ${COUT} ${CLIBS}


