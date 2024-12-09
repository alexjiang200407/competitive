SRC_DIR=src
BIN_DIR=bin
CC=g++
CFLAGS=-g -Wall


UTIL_FILES:=$(shell find . -type f -name '*.cpp' -path "./util/*")
CODEFORCES_FILES:=$(shell find . -type f -name '*.cpp' -path "./codeforces/*")
UTIL_TARGETS:=$(patsubst %.cpp, bin/%.exe, $(UTIL_FILES))
CODEFORCES_TARGETS:=$(patsubst %.cpp, bin/%.exe, $(CODEFORCES_FILES))

.PHONY: all

all: util codeforces

util: $(UTIL_TARGETS)

codeforces: $(CODEFORCES_TARGETS)


bin/%.exe: %.cpp
	@mkdir -p "$(@D)"
	$(CC) $(CFLAGS) $< -lstdc++ -o $@

clean:
	rm -rf bin/*
 