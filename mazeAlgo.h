//Ben Siri Jan 22 2024

#ifndef MAZEALGO_H
#define MAZEALGO_H

#include <unistd.h>
#include <stdio.h>
#include "graphics.h"

int checkPosition(Maze* self, int y, int x);

int moveDown(Maze* self);
int moveUp(Maze* self);
int moveRight(Maze* self);
int moveLeft(Maze* self);

int customAlgo(Maze* self);

#endif
