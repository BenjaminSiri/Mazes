//Ben Siri Jan 8 2024

#ifndef MAZEALGO_H
#define MAZEALGO_H

#include <unistd.h>
#include <stdio.h>
#include "graphics.h"

int checkPosition(Maze* self, int y, int x){
	char temp = self->frame[y][x];
	if(temp == 'E'){
		//Found
		return 2;
	} else if(temp == '#' || temp == '*'){
		//Wall
		return 0;
	} else {
		//Free to move
		return 1;
	}
}

int moveDown(Maze* self){
	int check = checkPosition(self, self->currentY+1, self->currentX);
	if(check == 1){
		//Free to move
		setFrame(self, self->currentY+1, self->currentX, '*');
		self->currentY++;
	}
	return check;

}

int moveUp(Maze* self){
	int check = checkPosition(self, self->currentY-1, self->currentX);
	if(check == 1){
		//Free to move
		setFrame(self, self->currentY-1, self->currentX, '*');
		self->currentY--;
	}
	return check;
}

int moveRight(Maze* self){
	int check = checkPosition(self, self->currentY, self->currentX+1);
	if(check == 1){
		//Free to move
		setFrame(self, self->currentY, self->currentX+1, '*');
		self->currentX++;
	}
	return check;
}

int moveLeft(Maze* self){
	int check = checkPosition(self, self->currentY, self->currentX-1);
	if(check == 1){
		//Free to move
		setFrame(self, self->currentY, self->currentX-1, '*');
		self->currentX--;
	}
	return check;
}

int customAlgo(Maze* self){
	usleep(100000);
	writeRep(self);

	int result = moveDown(self);
	if(result == 1){
		if(customAlgo(self) == 1){
			return 1;
		}
		self->currentY--;
	} else if(result == 2){
		return 1;
	}

	result = moveUp(self);
	if(result == 1){
		if(customAlgo(self) == 1){
			return 1;
		}
		self->currentY++;
	} else if(result == 2){
		return 1;
	}

	result = moveRight(self);
	if(result == 1){
		if(customAlgo(self) == 1){
			return 1;
		}
		self->currentX--;
	} else if(result == 2){
		return 1;
	}

	result = moveLeft(self);
	if(result == 1){
		if(customAlgo(self) == 1){
			return 1;
		}
		self->currentX++;
	} else if(result == 2){
		return 1;
	}

	setFrame(self, self->currentY, self->currentX, ' ');
	return 0;
}

#endif
