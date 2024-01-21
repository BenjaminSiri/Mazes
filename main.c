//Ben Siri Jan 8 2024

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "graphics.h"
#include "mazeAlgo.c"

int main(int argc, char* argv[]){
	Maze *myMaze = readFromFile(argv[1]);
	writeInit(myMaze);
	
	if(customAlgo(myMaze)){
		printf("FOUND\n");
	}

	return 0;
}
