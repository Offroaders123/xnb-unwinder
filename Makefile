NAME = xnb
CFLAGS = -std=c++20 -O0 -Isrc -Istb

.PHONY: clean

all: bin/$(NAME)

debug: CFLAGS += -DXNA_LOG -g
debug: bin/$(NAME)

bin/$(NAME) : src/*.cpp $(OUT) | bin
	clang++ $(CFLAGS) $^ -o bin/$(NAME)

bin:
	mkdir bin

clean:
	rm -rf bin