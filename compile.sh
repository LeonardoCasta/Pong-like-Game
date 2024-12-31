#!/bin/bash

g++ -c ./source/main.cpp -o main.o

g++ -c ./source/Animation.cpp -o animation.o

g++ -c ./source/Bomb.cpp -o bomb.o

g++ -c ./source/Player.cpp -o player.o

g++ main.o animation.o bomb.o player.o -o game -lsfml-graphics -lsfml-window -lsfml-system

#./sfml-app