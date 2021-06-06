GCC=arm-mingw32ce-g++
OPTION=-Wall -O2 -std=gnu++2a -march=armv5tej -mcpu=arm926ej-s -static -s -lcommctrl

all:
	mkdir -p bin
	${GCC} ${OPTION} -o bin/AppMain.exe src/*.cpp
	touch bin/index.din
	touch bin/AppMain.cfg

clean:
	rm -rf bin
