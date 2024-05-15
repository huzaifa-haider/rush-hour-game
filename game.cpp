//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
bool menu=true;
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
bool check=true;
bool *checkptr=&check;
void drawperson(int x,int y){ // for draw a person
	
	DrawCircle(x+5,y+14,5,colors[BLACK]);
	DrawSquare(x,y, 10, colors[RED]);
}
void drawtree(int x,int y){ //drawing the tree
	DrawCircle(x,y+19,7,colors[GREEN]);
	DrawLine(x , y ,  x , y+15 , 7 , colors[BROWN] );
}

int xI = 60, yI = 700,xc=70,yc=400,x2=400,y2=700;

void drawCar1() { // for red taxi...
		
	DrawSquare(xI, yI, 20, colors[RED]);DrawSquare(xI+5, yI+5, 10, colors[WHITE]);
	DrawCircle(xI+5,yI,5,colors[BLACK]);DrawCircle(xI+15,yI,5,colors[BLACK]);
	glutPostRedisplay();
}
void drawCar2() { //for yellow taxi....
		
	DrawSquare(xI, yI, 20, colors[YELLOW]);DrawSquare(xI+5, yI+5, 10, colors[WHITE]);
	DrawCircle(xI+5,yI,5,colors[BLACK]);DrawCircle(xI+15,yI,5,colors[BLACK]);
	glutPostRedisplay();
}

void drawcar(){ //for verticle moving car
	DrawSquare(xc, yc, 20, colors[GOLD]);DrawSquare(xc+5, yc+5, 10, colors[WHITE]);
	DrawCircle(xc+5,yc,5,colors[BLACK]);DrawCircle(xc+15,yc,5,colors[BLACK]);
	glutPostRedisplay();
}
void drawcar2(){ // for horizental moving car
	DrawSquare(x2, y2, 20, colors[DARK_ORANGE]);DrawSquare(x2+5, y2+5, 10, colors[WHITE]);
	DrawCircle(x2+5,y2,5,colors[BLACK]);DrawCircle(x2+15,y2,5,colors[BLACK]);
	glutPostRedisplay();
}
bool flag = true;
void moveCar() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}
bool checkc = true;
void movecar() {
	
	if (yc > 10 && checkc) {
		yc -= 10;
		//cout << "going down";
		if(yc < 150)
			
			checkc = false;

	}
	else if (yc < 700 && !checkc) {
	//	cout << "go up";
		yc += 10;
		if (yc > 690)
			checkc = true;
	}
}
bool flag2 = true;
void movecar2() {
	
	if (x2 > 10 && flag2) {
		x2 -= 10;
		cout << "going left";
		if(x2 < 100)
			
			flag2 = false;

	}
	else if (x2 < 600 && !flag2) {
		cout << "go right";
		x2 += 10;
		if (x2 > 550)
			flag2 = true;
	}
}


/*
 * Main Canvas drawing function.
 * */
 bool runGame = false,taxi_choice=false,yellow=false,red=false;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	if(!runGame){
	if(menu){
	DrawString( 50, 760, "@@@@@@@     Main Menu    @@@@@@", colors[RED]);
	DrawString( 50, 700, "1.Play Game ", colors[BLACK]);
	DrawString( 50, 650, "2. Exit ", colors[BLACK]);
	DrawString( 50, 600, "@@@@@@@@@@@@@@@@@", colors[RED]);
	}
	
	if(taxi_choice){
	DrawString( 50, 760, "3.yellow taxi ", colors[BLACK]);
	DrawString( 50, 700, "4. Red taxi  ", colors[BLACK]);
	}
	}
	
	
	
	if(runGame) {
		if(check==true){
	drawperson(300,100);drawperson(600,100);drawperson(300,500);drawperson(600,700);
	}
	DrawString( 50, 800, "Score=0", colors[BLACK]);
	
	drawtree(300,400);
	drawtree(500,500);drawtree(220,650);drawtree(600,200);
	drawtree(400,500);drawtree(200,550);

	

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[BLACK] );	
	// making hurdles in the grid
	//DrawLine(100 , 700 ,  200 , 700 , 10 , colors[BLACK] ); DrawLine(300 , 700 ,  600 , 700 , 10 , colors[BLACK] );
	
	
	DrawRectangle(100,650,100,40,colors[BLACK]); DrawRectangle(300,650,300,40,colors[BLACK]);
	DrawRectangle(150,550,300,40,colors[BLACK]);
	DrawRectangle(300,250,40,210,colors[BLACK]);DrawRectangle(250,450,150,40,colors[BLACK]);
	DrawRectangle(100,450,100,40,colors[BLACK]);DrawRectangle(100,300,40,160,colors[BLACK]);
	DrawRectangle(200,100,40,200,colors[BLACK]);DrawRectangle(400,350,200,40,colors[BLACK]);
	DrawRectangle(500,450,100,150,colors[BLACK]);
	
	
	//******************
	//making grid boundry
	//*******************
	
	DrawLine(50 , 750 ,  650 , 750 , 3 , colors[BLACK] );DrawLine(50 , 100 ,  650 , 100 , 3 , colors[BLACK] );
	DrawLine(650 , 100 ,  650 , 750 , 3 , colors[BLACK] );DrawLine(50 , 100 ,  50 , 750 , 3 , colors[BLACK] );
	
	//*******************
	//drawing the roads...
	//*******************
	
	DrawLine(100 , 100 ,  100 , 750 , 1 , colors[BLACK] );
	DrawLine(150 , 100 ,  150 , 750 , 1 , colors[BLACK] );DrawLine(200 , 100 ,  200 , 750 , 1 , colors[BLACK] );
	DrawLine(250 , 100 ,  250 , 750 , 1 , colors[BLACK] );DrawLine(300 , 100 ,  300 , 750 , 1 , colors[BLACK] );
	DrawLine(350 , 100 ,  350 , 750 , 1 , colors[BLACK] );DrawLine(400 , 100 ,  400 , 750 , 1 , colors[BLACK] );
	DrawLine(450 , 100 ,  450 , 750 , 1 , colors[BLACK] );DrawLine(500 , 100 ,  500 , 750 , 1 , colors[BLACK] );
	DrawLine(550 , 100 ,  550 , 750 , 1 , colors[BLACK] );DrawLine(600 , 100 ,  600 , 750 , 1 , colors[BLACK] );
	DrawLine(650 , 100 ,  650 , 750 , 1 , colors[BLACK] );
	//DrawCircle(100,670,10,colors[DARK_VIOLET]);
	
	
	
	if(red){
	drawCar1();
	}
	if(yellow){
	drawCar2();
	}
	
		drawcar();
		drawcar2();
	}

	glutSwapBuffers(); // do not modify this line..

	}




/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//conditions for collisions with buildings
		if((xI<=53) || ((xI>=100 && xI<=200)  && (yI>=640&&yI<=680)) || ((xI>=300 && xI<=350)  && (yI>=640&&yI<=700)) || ((xI>=550 && xI<=600)  && (yI>=440 && yI<=590)) || ((xI>=400 && xI<=450)  && (yI>=540&&yI<=580))  || ((xI>=300 && xI<=340)  && (yI>=240&&yI<=460))|| ((xI>=280 && xI<=400)  && (yI>=440&&yI<=480))){
		xI -= 0;
		}
		else{
		xI-=10;
		}
		
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if( (xI>=628) ||((xI>=80 && xI<=150)  && (yI>=640&&yI<=680)) || ((xI>=280 && xI<=600)  && (yI>=640&&yI<=680))|| ((xI>=480 && xI<=550)  && (yI>=440 && yI<=590)) || ((xI>=130 && xI<=150)  && (yI>=540&&yI<=580))  || ((xI>=280 && xI<=300)  && (yI>=240&&yI<=460))  || ((xI>=230 && xI<=350)  && (yI>=440&&yI<=480))){
		xI+= 0;
		}
		else{
		xI += 10;
		}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if((yI>=728)||((xI>=90 && xI<=190)  && (yI>=630&&yI<=650))   || ( (yI>=630 && yI<=660) && (xI>=290 && xI<=590))|| ((xI>=490 && xI<=590)  && (yI>=430 && yI<=500)) || ((xI>=140 && xI<=440)  && (yI>=530&&yI<=580))  || ((xI>=290 && xI<=330)  && (yI>=230&&yI<=460))){
		yI+=0;
		}
		else{
		yI += 10;
		}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if((yI<=107)||((xI>=90 && xI<=190)  && (yI>=640&&yI<=690))  || ( (yI>=650&&yI<=690) && (xI>=290&&xI<=590))|| ((xI>=490 && xI<=590)  && (yI>=450 && yI<=600)) || ((xI>=140 && xI<450)  && (yI>=540&&yI<=590))  || ((xI>=290 && xI<=330)  && (yI>=240&&yI<=460))){
		yI-=0;
		}
		else{
		yI -= 10;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
	
	
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 int i = 0;
void PrintableKeys(unsigned char key, int x, int y) {
	
	if(menu){
		if(key==49){
			
			menu=false;
			taxi_choice=true;
		}
	}
	if(menu){
		if(key==50){
		exit(1);
		}
	}
	if(key==51){
	yellow=true;
	
	runGame=true;
	
	}
	if(key==52){
	runGame=true;
	red=true;
	}
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if(xI+20==600||yI+20==700||xI-20==600||yI-20==700){
	if (key == 32){
	check=false;
	
	}
	}
	
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	movecar();
	movecar2();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	
		
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Huzaifa Haider"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
