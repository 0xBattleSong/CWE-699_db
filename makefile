SRC    := traverse.c
CC     := gcc
CFLAGS := -Wall -g
LIBS   := -lxml2
DBG    := gdb
DEBUGOPTS := --args
BIN    := traverse
ARGS   := comVulns.xml

build:
	${CC} ${CFLAGS} ${LIBS} -o ${BIN} ${SRC}

run: build
	./${BIN} ${ARGS}

debug:
	${DBG} ${DEBUGOPTS} ./${BIN} ${ARGS}
