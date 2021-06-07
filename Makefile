CC=arm-mingw32ce-g++
OPTION=-Wall -O2 -std=gnu++2a -march=armv5tej -mcpu=arm926ej-s -static -s -lcommctrl
OUTPUT_DIR=bin

all:
	mkdir -p ${OUTPUT_DIR}
	${CC} ${OPTION} -o ${OUTPUT_DIR}/AppMain.exe src/*.cpp
	touch ${OUTPUT_DIR}/index.din
	touch ${OUTPUT_DIR}/AppMain.cfg

clean:
	rm -rf ${OUTPUT_DIR}
