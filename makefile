src=$(wildcard *.cpp)
target=$(patsubst %.cpp, ./target/%, $(src))

ALL:$(target)

args=-g -Wall -pthread

$(target):./target/%:%.cpp
	g++ $(args) $< -o $@

.PHONY: clean ALL

clean:
	-rm ./target/*
