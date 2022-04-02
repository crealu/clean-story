#!/bin/bash

g++ main.cpp -o cleanstory \
  -I/usr/local/include/SDL2 \
  -D_THREAD_SAFE \
  -L/usr/local/lib -lSDL2 -lSDL2_ttf
