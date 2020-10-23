AMP = @

CC = ${AMP}gcc
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = -lrumi

AR = ${AMP}ar
RM = ${AMP}rm -f

RUMI_NAMES = 
RUMI_NAMES += rumi
RUMI_NAMES += rumi_macros
RUMI_NAMES += rumi_types
RUMI_NAMES += rumi_colors
RUMI_NAMES += rumi_base
RUMI_NAMES += rumi_switches
RUMI_NAMES += rumi_log
RUMI_NAMES += ru

RUMI_OBJ_NAMES = ${addsuffix .o, ${RUMI_NAMES}}
RUMI_OBJS = ${addprefix build/, ${RUMI_OBJ_NAMES}}

RUMI_STATIC_LIB = build/librumi.a
RUMI_DYNAMIC_LIB = build/librumi.so

MAIN_SRC = src/main.c
MAIN_OBJ = build/main.o

BIN = build/rumi

default: clean lib ${BIN}

lib: ${RUMI_STATIC_LIB} ${RUMI_DYNAMIC_LIB}

debug:
	${eval AMP := }

${BIN}: ${MAIN_OBJ} ${RUMI_OBJS}
	${CC} $^ -o $@

${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${RUMI_OBJS}: build/%.o: lib/%.c include/%.h
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${RUMI_STATIC_LIB}: ${RUMI_OBJS}
	${AR} rcs $@ $^

${RUMI_DYNAMIC_LIB}: ${RUMI_OBJS}
	${CC} -shared $^ -o $@

redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${RUMI_OBJS}
	${RM} ${RUMI_STATIC_LIB}
	${RM} ${RUMI_DYNAMIC_LIB}


