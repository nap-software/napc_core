#!/bin/bash -eux

rm -rf bin
mkdir bin

gcc \
	./src/*.c \
	-L./lib/ \
	-lnap_hal0 \
	./tests/main.c \
	-o ./bin/main

./bin/main
