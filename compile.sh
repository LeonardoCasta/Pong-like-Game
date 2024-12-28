#!/bin/bash

g++ -c ./source/main.cpp ./source/main.cpp

g++ ./main.o -o game -lsfml-graphics -lsfml-window -lsfml-system

#./sfml-app