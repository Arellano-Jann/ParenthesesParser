CPPFLAGS = -std=c++11 -g

all: main

main: main.cpp
	g++ $(CPPFLAGS) -o $@ $^

clean: 
	rm main