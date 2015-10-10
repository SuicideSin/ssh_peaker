CPP=g++
CFLAGS=-O -Wall -m32 -static -static-libstdc++ -static-libgcc

all: ssh_peaker

ssh_peaker: ssh_peaker.cpp
	$(CPP) $(CFLAGS) $^ -o $@

clean:
	- rm -f ssh_peaker
