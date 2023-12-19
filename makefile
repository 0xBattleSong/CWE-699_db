SRC    := parse.c
CC     := gcc
CFLAGS := -Wall -g
LIBS   := -lxml2
DBG    := gdb
<<<<<<< HEAD
BIN    := parse
ARGS   :=
=======
DEBUGOPTS := --args
BIN    := traverse
ARGS   := comVulns.xml
>>>>>>> 35a2f01 (added DEBUGOPTS)

build:
	${CC} ${CFLAGS} ${LIBS} -o ${BIN} ${SRC}

run: build
	./${BIN} ${ARGS}

debug:
	${DBG} ${DEBUGOPTS} ./${BIN} ${ARGS}
