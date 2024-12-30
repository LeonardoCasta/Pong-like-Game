#!/bin/bash

g++ -c ./source/main.cpp -o main.o

g++ -c ./source/Animation.cpp -o animation.o

g++ main.o animation.o -o game -lsfml-graphics -lsfml-window -lsfml-system

#./sfml-app