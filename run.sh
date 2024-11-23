#!/usr/bin/bash
g++ -O3 -o ./bin/$1.x -Wall $1 && ./bin/$1.x
