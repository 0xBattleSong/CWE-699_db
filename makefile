SRC    := traverse.c
CC     := gcc
CFLAGS := -Wall -g
LIBS   := -lxml2
DBG    := gdb
BIN    := traverse
ARGS   :=

build:
	${CC} ${CFLAGS} ${LIBS} -o ${BIN} ${SRC}

run: build
	./${BIN} ${ARGS}

debug:
	${DBG} ./${BIN} ${ARGS}
