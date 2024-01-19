//Ben Siri Jan 8 2024

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct Maze Maze;

struct Maze {
	char **frame;
	int height;
	int width;
	int currentX;
	int currentY;
	char start;
	char end;
};

Maze *newMaze(int width, int height){
	Maze *new = (Maze*)malloc(sizeof(Maze));
	new->height = height;
	new->width = width;
	new->start = 'S';
	new->end = 'E';

	new->frame = (char**)malloc(sizeof(char*)*height);
	for(int i=0; i<height; i++){
		new->frame[i] = (char*)malloc((sizeof(char)*width));
	}
	return new;
}

void destroyMaze(Maze* self){
	for(int i=0; i<self->height; i++){
		free(self->frame[i]);
	}
	free(self->frame);
	free(self);
}

void findStart(Maze* self){
	for(int i=0; i<self->height; i++){
		for(int j=0; j<self->width; j++){
			if(self->frame[i][j] == 'S'){
				self->currentX = j;
				self->currentY = i;
			}
		}
	}
}

Maze *readFromFile(char *fileName){
	FILE *fptr;
	fptr = fopen(fileName, "r");
	if(fptr == NULL){
		printf("Unable to open file.\n");
		return NULL;
	}
	char widthBuf[5];
	char heightBuf[5];
	fgets(widthBuf, 5, fptr);
	fgets(heightBuf, 5, fptr);
	int width = atoi(widthBuf);
	int height = atoi(heightBuf);

	Maze *fileMaze = newMaze(width, height);

	int size = width+1;
	int i = 0;
	while(fgets(fileMaze->frame[i], size+1, fptr)){
		i++;
	}
	fclose(fptr);
	findStart(fileMaze);
	return fileMaze;
}

void setFrame(Maze* self, int y, int x, char input){
	self->frame[y][x] = input;
}

void setEmpty(Maze* self){
	for(int i=0; i<self->height; i++){
		for(int j=0; j<self->width; j++){
			if(i==0||j==0||i==self->height-1||j==self->width-1){
				self->frame[i][j] = '#';
			}
			else{
				self->frame[i][j] = ' ';
			}
		}
	}
}

void writeInit(Maze* self){
	for(int i=0; i<self->height; i++){
		for(int j=0; j<self->width; j++){
			printf("%c", self->frame[i][j]);
		}
		printf("\n");
	}
}

void writeRep(Maze* self){
	printf("\r\033[%dA", self->height);
	for(int i=0; i<self->height; i++){
		for(int j=0; j<self->width; j++){
			printf("%c", self->frame[i][j]);
		}
		printf("\n");
	}
}

#endif
