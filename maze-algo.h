//Ben Siri Jan 8 2024

#ifndef MAZEALGO_H
#define MAZEALGO_H

#include <unistd.h>
#include "graphics.h"

int checkPosition(Maze* self, int y, int x){
	char temp = self->frame[y][x];
	if(temp == 'E'){
		return 2;
	} else if(temp == '#' || temp == '*'){
		return 1;
	} else {
		return 0;
	}
}

int moveDown(Maze* self){

	int check = checkPosition(self, self->currentY+1, self->currentX);
	if(check == 2){
		//Found
		return 2;
	} else if(check == 1){
		//Wall
		return 0;
	} else {
		//Free to move
		setFrame(self, self->currentY+1, self->currentX, '*');
		self->currentY++;
		return 1;
	}

}

int moveUp(Maze* self){
	if(self->frame[self->currentY-1][self->currentX] == 'E'){
		return 2;
	}
	if(self->frame[self->currentY-1][self->currentX] == ' '){
		setFrame(self, self->currentY-1, self->currentX, '*');
		self->currentY--;
		return 1;
	}	
	return 0;
}

int moveRight(Maze* self){
	if(self->frame[self->currentY][self->currentX+1] == 'E'){
		return 2;
	}
	if(self->frame[self->currentY][self->currentX+1] == ' '){
		setFrame(self, self->currentY, self->currentX+1, '*');
		self->currentX++;
		return 1;
	}	
	return 0;
}

int moveLeft(Maze* self){
	if(self->frame[self->currentY][self->currentX-1] == 'E'){
		return 2;
	}
	if(self->frame[self->currentY][self->currentX-1] == ' '){
		setFrame(self, self->currentY, self->currentX-1, '*');
		self->currentX--;
		return 1;
	}	
	return 0;
}

int customAlgo(Maze* self){
	usleep(100000);

	int result = moveDown(self);
	if(result == 1){
		writeRep(self);
		return customAlgo(self);
	} else if(result == 2){
		return 1;
	}

	result = moveUp(self);
	if(result == 1){
		writeRep(self);
		return customAlgo(self);
	} else if(result == 2){
		return 1;
	}

	result = moveRight(self);
	if(result == 1){
		writeRep(self);
		return customAlgo(self);
	} else if(result == 2){
		return 1;
	}

	result = moveLeft(self);
	if(result == 1){
		writeRep(self);
		return customAlgo(self);
	} else if(result == 2){
		return 1;
	}
	
	

	return 0;
}

#endif
