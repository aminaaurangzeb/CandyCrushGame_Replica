#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

//General functions
bool isCursorKeyPressed(int& whickKey) {   //whichKey passed as reference.... 
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1){
		whickKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1){
		whickKey = 2;		// 2 if up key is pressed
		return true;
	}
	key = GetAsyncKeyState(39);
	if (key == 1){
		whickKey = 3;		// 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1){
		whickKey = 4;		// 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(13);
	if (key == 1) {
		whickKey = 5;		// 5 if enter key is pressed
		return true;
	}
	key = GetAsyncKeyState(83);
	if (key == 1) {
		whickKey = 6;		// 6 if 'S' key is pressed
		return true;
	}
	key = GetAsyncKeyState(76);
	if (key == 1) {
		whickKey = 7;		//7 if 'L' key is pressed
		return true;
	}
	key = GetAsyncKeyState(84);
	if (key == 1) {
		whickKey = 8;		//8 if 'T' key is pressed
		return true;
	}
	key = GetAsyncKeyState(89);
	if (key == 1) {
		whickKey = 9;		//8 if 'Y' key is pressed
		return true;
	}
	return false;
}
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void swaparray(int data[][8][3], int x, int y, int swapx, int swapy) {
	for (int i = 0; i < 3; i++) {
		swap(data[y][x][i], data[swapy][swapx][i]);
	}
}

//Draw functions

void myLineblack(int x1, int y1, int x2, int y2) //Draws a black line
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0)); 
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void gem1(int y, int x) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 79, 167));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 79, 167));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 430; //calculating starting pixel values
	int x2 = x1 + 60;
	int y1 = 100 * y + 30;
	int y2 = y1 + 60;

	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}
void gem2(int y, int x) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(190, 0, 190));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(190, 0, 190));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 430;
	int x2 = x1 + 60;
	int y1 = 100 * y + 30;
	int y2 = y1 + 60;

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void gem3(int y, int x) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(60, 168, 220));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(60, 168, 220));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 420;
	int x2 = x1 + 80;
	int y1 = 100 * y + 20;
	int y2 = y1 + 80;


	Rectangle(device_context, x1, y1 + 25, x2, y2 - 25);
	Rectangle(device_context, x1 + 25, y1, x2 - 25, y2);

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void gem4(int y, int x) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(68, 174, 92));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(68, 174, 92));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 420;
	int x2 = x1 + 80;
	int y1 = 100 * y + 20;
	int y2 = y1 + 80;


	Ellipse(device_context, x1 + 20, y1, x1 + 60, y1 + 40);
	Ellipse(device_context, x1 + 20, y1 + 40, x1 + 60, y1 + 80);
	Ellipse(device_context, x1, y1 + 20, x1 + 40, y1 + 60);
	Ellipse(device_context, x1 + 40, y1 + 20, x1 + 80, y1 + 60);



	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void gem5(int y, int x) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(97, 94, 149));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(97, 94, 149));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 420;
	int x2 = x1 + 80;
	int y1 = 100 * y + 20;
	int y2 = y1 + 80;

	Rectangle(device_context, x1 + 10, y1 + 10, x1 + 70, y1 + 20);
	Rectangle(device_context, x1 + 10, y1 + 60, x1 + 70, y1 + 70);
	Rectangle(device_context, x1 + 10, y1 + 10, x1 + 20, y1 + 70);
	Rectangle(device_context, x1 + 60, y1 + 10, x1 + 70, y1 + 70);
	Ellipse(device_context, x1 + 30, y1 + 30, x1 + 50, y1 + 50);


	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void flamingOverlay(int y, int x) {
	int x1 = 100 * x + 40 + 410; //calculating starting pixel values
	int x2 = x1 + 20;
	int y1 = 100 * y + 40 + 10;
	int y2 = y1 + 20;
	myLineblack(x2, y1 - 30, x2, y1 + 50);
	myLineblack(x1, y1 - 30, x1, y1 + 50);
	myLineblack(x2 + 20, y1 - 30, x2 + 20, y1 + 50);
	myLineblack(x1 - 20, y1 - 30, x1 - 20, y1 + 50);
	myLineblack(x2 + 10, y1 - 30, x2 + 10, y1 + 50);
	myLineblack(x1 - 10, y1 - 30, x1 - 10, y1 + 50);

}
void destroyerOverlay(int y, int x) { //draws destroyer indication
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(150, 150, 150));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 40 + 410; //calculating starting pixel values
	int x2 = x1 + 20;
	int y1 = 100 * y + 40 + 10;
	int y2 = y1 + 20;

	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myLine(int x1, int y1, int x2, int y2) //Draws a white line
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void cubegem(int y, int x) {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 0));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 0, 255));
	SelectObject(device_context, brush);
	int x1 = 100 * x + 40 + 410; //calculating starting pixel values
	int x2 = x1 + 20;
	int y1 = 100 * y + 40 + 10;
	int y2 = y1 + 20;

	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}
void clearscreen() { //clears the board
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0, 0, 0)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, 0, 0, 1920, 1080);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}
void drawDestroy(int y, int x) { //draws cross on gem to be destroyed
	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	SelectObject(pen_device_context, pen);

	int x1 = x * 100 + 410;
	int y1 = y * 100 + 10;
	MoveToEx(pen_device_context, x1, y1, NULL);
	LineTo(pen_device_context, x1 + 100, y1 + 100);
	MoveToEx(pen_device_context, x1 + 100, y1, NULL);
	LineTo(pen_device_context, x1, y1 + 100);

	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);

}
void printArray(int data[][8][3]) {
	//Drawing 8x8 grid 
	//system("cls");
	clearscreen();
	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(pen_device_context, pen);
	for (int i = 10; i <= 810; i = i + 100) {
		MoveToEx(pen_device_context, i + 400, 10, NULL);
		LineTo(pen_device_context, i + 400, 810);

		MoveToEx(pen_device_context, 10 + 400, i, NULL);
		LineTo(pen_device_context, 1210, i);
	}

	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);


	//Drawing gems
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			switch (data[x][y][0]) {
			case 1: gem1(x, y);
				break;
			case 2: gem2(x, y);
				break;
			case 3: gem3(x, y);
				break;
			case 4: gem4(x, y);
				break;
			case 5: gem5(x, y);
				break;
			case 6: cubegem(x, y);
				break;
			}
			if (data[x][y][2] == 1)
				drawDestroy(x, y);
			if (data[x][y][1] == 1 || data[x][y][1] == 2)
				flamingOverlay(x, y);
			if (data[x][y][1] == 3)
				destroyerOverlay(x, y);

		}
	}
	Sleep(50);
}
void printCursor(int x, int y, int color) { // 1 = white, 2 = green, 3 = blue
	int R = 255, G = 255, B = 255;
	if (color == 2) {
		R = 0;
		B = 0;
	}
	else if (color == 3) {
		R = 0;
		G = 0;
	}

	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(R, G, B));
	SelectObject(pen_device_context, pen);
	x = (x * 100) + 410;
	y = (y * 100) + 10;
	MoveToEx(pen_device_context, x, y, NULL);
	LineTo(pen_device_context, x + 100, y);
	LineTo(pen_device_context, x + 100, y + 100);
	LineTo(pen_device_context, x, y + 100);
	LineTo(pen_device_context, x, y);


	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);
}

//Array modifier functions
bool boardEmpty(int data[8][8][3]) {  //is the board empty?
	bool result = false;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (data[x][y][0] == 0) {
				result = true;
				break;
			}
		}
	}
	return result;
}
bool ToBeDestroyed(int data[][8][3]) { //are there any gems to be destroyed?
	bool result = false;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (data[x][y][2] == 1) {
				result = true;
				break;
			}
		}
	}
	return result;
}
bool checkMatch(int data[][8][3]) { //USED fOR RANDOM GENERATION.
	bool found = false;
	int checkX, checkY;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			checkX = x;
			checkY = y;
			while (data[y][x][0] == data[y][checkX][0] && checkX < 8 && data[y][x][0] != 0) {
				checkX++;
			}
			if (checkX - x >= 3) {
				found = true;
			}
			while (data[y][x][0] == data[checkY][x][0] && checkY < 8 && data[y][x][0] != 0) {
				checkY++;
			}

			if (checkX - x >= 3 || checkY - y >= 3) {
				found = true;
			}
		}
	}

	return found;
}
bool hcheck(int data[][8][3], int x1, int y1, int x2, int y2) { //checks for 3+ horizontal matches
	bool found = false;
	int checkX;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			checkX = x;
			//Count consecutive
			while (data[y][x][0] == data[y][checkX][0] && checkX < 8 && data[y][x][0] != 0) {
				checkX++;
			}

			//Mark gems for destruction
			if (checkX - x >= 3) {
				for (int i = x; i < checkX; i++) {
					data[y][i][2] = 1;
				}
				found = true;
			}

			//Check special conditions
			if (checkX - x == 4){ //Flaming
				found = true;
				if (x1 >= x && x1 <= checkX - 1 && y1 == y) {
					data[y][x1][1] = 1;
				}
				else if (x2 >= x && x2 <= checkX - 1 && y2 == y) {
					data[y][x2][1] = 1;
				}
			}

			else if (checkX - x >= 5) { //Cube
				Beep(2000, 150);
				Beep(2000, 150);

				if (x1 >= x && x1 <= checkX - 1 && y1 == y) {
					data[y][x1][0] = 6;
					data[y][x1][2] = 0;
				}
				else if (x2 >= x && x2 <= checkX - 1 && y2 == y) {
					data[y][x2][0] = 6;
					data[y][x2][2] = 0;
				}
			}
			if (checkX - x >= 3) {
				x = checkX - 1; //shift starting point forward
			}

		}
	}
	return found;
}
bool vcheck(int data[][8][3], int x1, int y1, int x2, int y2) { //checks for 3+ horizontal matches
	bool found = false;
	int checkY;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			checkY = y;
			//Count consecutive
			while (data[y][x][0] == data[checkY][x][0] && checkY < 8 && data[y][x][0] != 0) {
				checkY++;
			}

			//Mark gems for destruction
			if (checkY - y >= 3) {
				for (int i = y; i < checkY; i++) {
					data[i][x][2] = 1;
				}
				found = true;
			}


			//Check special conditions
			if (checkY - y == 4) {		//Flaming
				found = true;
				if (y1 >= y && y1 <= checkY - 1 && x1 == x) {
					data[y1][x][1] = 1;
				}
				else if (y2 >= x && y2 <= checkY - 1 && x2 == x) {
					data[y2][x][1] = 1;
				}
			}
			else if (checkY - y >= 5) { //cube
				Beep(2000, 150);
				Beep(2000, 150);

				if (y1 >= y && y1 <= checkY - 1 && x1 == x) {
					data[y1][x][0] = 6;
					data[y1][x][2] = 0;
				}
				else if (y2 >= x && y2 <= checkY - 1 && x2 == x) {
					data[y2][x][0] = 6;
					data[y2][x][2] = 0;
				}
			}

			if (checkY - y >= 3) {
				y = checkY - 1; //shift starting point forward
			}

		}
	}


	return found;
}
bool cubeDestroyer(int data[][8][3], int x1, int y1, int x2, int y2) { //used in cube gem destruction
	bool result = false;
	if (data[y1][x1][0] == 6) {
		data[y1][x1][0] = 0;
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (data[y][x][0] == data[y2][x2][0]) {
					data[y][x][2] = 1; //mark to be destroyed
					result = true;
				}
			}
		}
	}
	else if (data[y2][x2][0] == 6) {
		(data[y2][x2][0] = 0);
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (data[y][x][0] == data[y1][x1][0]) {
					data[y][x][2] = 1; //mark to be destroyed
					result = true;
				}
			}
		}
	}
	return result;
}
void destroyGems(int data[][8][3], int& score) { //destroys gems and special gems
	printArray(data);
	//Sleep(500); 
	Beep(400, 200);
	Beep(703, 150);

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {


			if (data[y][x][2] == 1) {  //TO BE DESTROYED

				data[y][x][2] = 0; //reset to be destroyed flag

				if (data[y][x][1] == 3) { //if destroyer gem 
					Beep(900, 50);
					Beep(900, 50);

					data[y][x][1] = 0;
					for (int b = 0; b < 8; b++) {
						data[y][b][2] = 1;
						data[b][x][2] = 1;
					}
					destroyGems(data, score);
				}

				if (data[y][x][1] == 0) { //if normal gem 
					data[y][x][0] = 0;	//destroy
					score = score + 10; //10 points for each gem destroyed
				}



				if (data[y][x][1] == 2) {//if flaming to be destroyed	
					Beep(800, 50);
					for (int i = 0; i <= 2; i++) {
						for (int j = 0; j <= 2; j++) {
							if ((y + i - 1 >= 0) && (y + i - 1 < 8) && (x + j - 1 >= 0) && (x + j - 1 < 8)) {
								data[y + i - 1][x + j - 1][2] = 1; //mark surrounding 9 to be destroyed	
							}
						}
					}

					data[y][x][1] = 0; //remove flaming status
				}

				if (data[y][x][1] == 1) {//If flaming created this turn
					data[y][x][1] = 2; //Mark flaming to be destroyed next turn
				}
			}
		}
	}

	if (ToBeDestroyed(data) == true) {
		destroyGems(data, score);
	}
}
void randomize(int data[][8][3]) { //randomly fills the board empty cells
	srand(time(0));
	while (boardEmpty(data)){
		bool changes = false;
		for (int x = 7; x >= 0; x--) {
			for (int y = 0; y < 8; y++) {

				while (data[x][y][0] == 0) { //Check if gem exists at x,y
					data[x][y][0] = rand() % 5 + 1;
					while (checkMatch(data) == true) {	//retry until no consecutive 3 found 						
						data[x][y][0] = rand() % 5 + 1;
						changes = true;
					}
				}
			}
			if (changes) {
				printArray(data);

				changes = false;
			}
		}

	}

}
void Falling(int data[][8][3]) { //moves empty gems to the top
	bool changeMade = false;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (data[y][x][0] == 0) {
				changeMade = true;

				for (int k = y; k > 0; k--) {
					swaparray(data, x, k, x, k - 1);
				}

			}
		}
		if (changeMade == true) {
			printArray(data);

			changeMade = false;
		}
	}
	//CHECK AND DESTROY MATCHES AFTER FALLING
}
bool elbowcheck(int data[][8][3]) { //checks for all 4 possible elbow matches
	bool  found = false;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (data[i][j][0] == data[i][j + 1][0] && data[i][j][0] == data[i][j + 2][0] && data[i][j][0] == data[i + 1][j][0] && data[i][j][0] == data[i + 2][j][0]){
				data[i][j][1] = 3;
				data[i][j + 1][2] = 1;
				data[i][j + 2][2] = 1;
				data[i + 1][j][2] = 1;
				data[i + 2][j][2] = 1;
				found = true;
			}
		}
	}
	for (int i = 2; i < 8; i++){
		for (int j = 2; j < 8; j++){
			if (data[i][j][0] == data[i][j - 1][0] && data[i][j - 1][0] == data[i][j - 2][0] && data[i][j][0] == data[i - 1][j][0] && data[i - 1][j][0] == data[i - 2][j][0]){
				data[i][j][1] = 3;
				data[i][j - 1][2] = 1;
				data[i][j - 2][2] = 1;
				data[i - 1][j][2] = 1;
				data[i - 2][j][2] = 1;
				found = true;

			}
		}
	}
	for (int i = 0; i < 6; i++){
		for (int j = 2; j < 8; j++){
			if (data[i][j][0] == data[i][j - 1][0] && data[i][j - 1][0] == data[i][j - 2][0] && data[i][j][0] == data[i + 1][j][0] && data[i][j][0] == data[i + 2][j][0]){
				data[i][j][1] = 3;
				data[i][j - 1][2] = 1;
				data[i][j - 2][2] = 1;
				data[i - 1][j][2] = 1;
				data[i - 2][j][2] = 1;
				found = true;

			}
		}
	}
	for (int i = 2; i < 8; i++){
		for (int j = 0; j < 6; j++){
			if (data[i][j][0] == data[i - 1][j][0] && data[i][j][0] == data[i - 2][j][0] && data[i][j][0] == data[i][j + 1][0] && data[i][j][0] == data[i][j + 2][0]){
				data[i][j][1] = 3;
				data[i - 1][j][2] = 1;
				data[i - 2][j][2] = 1;
				data[i][j + 2][2] = 1;
				data[i][j + 1][2] = 1;
				found = true;
			}
		}
	}

	return(found);
}

//Saveload
void savearray(int data[][8][3], time_t t, int score) {
	ofstream fout("LULALALA.ini");
	for (int i = 0; i < 8; i++)	{
		for (int j = 0; j < 8; j++)		{
			fout << data[i][j][0];
			fout << " ";
			fout << data[i][j][1];
			fout << " ";
			fout << data[i][j][2];
			fout << endl;
		}
	}
	fout << t;
	fout << endl;
	if (score == 0) {
		fout << 0;
	}
	fout << score;
	fout << endl;
}
void loadarray(int data[][8][3], time_t& t, int& score) {
	ifstream fin("LULALALA.ini");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			fin >> data[i][j][0];
			fin >> data[i][j][1];
			fin >> data[i][j][2];
		}
	}
	fin >> t;
	fin >> score;

}


//Front end
void timer(time_t GameTime) {//drawing progression bar
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	myLine(33, 5, 207, 5);//drawing outer rectangle
	myLine(33, 25, 207, 25);
	myLine(207, 5, 207, 25);
	myLine(33, 5, 33, 25);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(200, 170, 200));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(200, 170, 200));
	SelectObject(device_context, brush);

	int x1 = 35;
	int x2 = 205;
	int y1 = 7;
	int y2 = 23;
	x2 = 35 + GameTime * 3;
	Rectangle(device_context, x1, y1, x2, y2);//drawing moving rectangle

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void PrintScore(int& Score, int highscore) {//drawing score board
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	myLine(10, 30, 230, 30);//drawing outer rectangle
	myLine(10, 140, 230, 140);
	myLine(250, 30, 250, 110);
	myLine(10, 30, 10, 110);
	gotoxy(8, 2);
	cout << "SCORE BOARD";
	myLine(10, 47, 230, 47);
	gotoxy(5, 4);
	cout << "High Score : " << highscore;
	gotoxy(5, 5);
	cout << "Total Score : " << Score;


}


int main() {

	int data[8][8][3] = { 0 }; //LAYER 1 gems LAYER 2 type LAYER 3 marking
	randomize(data);
	printArray(data);

	int x = 0, y = 0;
	int swapx = -2, swapy = -2; // moves offscreen
	int key = 0;



	bool waitingToSwap = false;
	//Scoring
	int highscore = 0;
	ifstream fin("Highscore.txt");
	fin >> highscore;
	int score = 0;

	int prevhighscore = highscore;


	//initial time declaration
	time_t StartTime = time(0);
	time_t timeElapsed = 0;
	time_t PrevTimeElapsed = 0;
	time_t TimeLimit = 60;
	time_t GameTime = 0;

	while (GameTime < TimeLimit) {
		//time handling
		PrevTimeElapsed = timeElapsed;
		timeElapsed = time(0) - StartTime;

		if (PrevTimeElapsed != timeElapsed) { //only update when time changes
			GameTime++;
			gotoxy(5, 6);
			cout << "time: " << GameTime << "/" << TimeLimit << "       ";
			timer(GameTime);
			PrintScore(score, highscore);

		}
		if (isCursorKeyPressed(key) == true) { //only runs if a key has been pressed
			Beep(300, 50);
			printCursor(x, y, 1);
			printCursor(swapx, swapy, 3);

			switch (key) { //check which key has been pressed
			case 1:
				if (x > 0) {
					x--;
				}break;
			case 2:
				if (y > 0) {
					y--;
				}break;
			case 3:
				if (x < 7) {
					x++;
				}break;
			case 4:
				if (y < 7) {
					y++;
				}break;
			case 6:
				savearray(data, GameTime, score);
				break;
			case 7:
				loadarray(data, GameTime, score);
				printArray(data);
				break;
			case 8:
				data[y][x][0] = 6;
				printArray(data);
				Beep(5000, 400);
				break;
			case 9:
				data[y][x][1] = 2;
				printArray(data);
				Beep(5000, 400);
				break;
			}
			if (waitingToSwap == true) { //if enter key has been pressed previously
				swaparray(data, x, y, swapx, swapy); //new xy values have been updated in case statement


				if (data[y][x][0] == 6 || data[swapy][swapx][0] == 6) {
					cubeDestroyer(data, x, y, swapx, swapy); //cube gem swapped 
				}


				if (checkMatch(data) == false) { //check for invalid swap + check for cubegem
					swaparray(data, x, y, swapx, swapy); //reverse invalid swap
				}


				if (elbowcheck(data)) {
					destroyGems(data, score); //destroys marked gems
				}

				while (checkMatch(data) == true || ToBeDestroyed(data) == true) { //Matches exist on board 

					hcheck(data, x, y, swapx, swapy); //checks and marks any gems to be destroyed
					vcheck(data, x, y, swapx, swapy);
					destroyGems(data, score); //destroys marked gems
					printArray(data);
					Falling(data); //brings other gems lower
				}

				randomize(data);
				printArray(data);

				waitingToSwap = false; //reset swap flag

				printCursor(swapx, swapy, 1); //removes the blue selection cursor
				swapx = -2;	//reset swap vaues to offscreen
				swapy = -2;
				printArray(data);
			}

			if (key == 5) {//Enter pressed; prepare next input for swap
				waitingToSwap = true;
				swapx = x;
				swapy = y;
				printCursor(swapx, swapy, 3); //highlights selected gem
			}
			else {
				printCursor(x, y, 2); //prints where cursor currently is only when xy changes and enter not pressed
			}
		}
	}


	clearscreen();

	gotoxy(80, 20);
	cout << "TIME UP!!!";

	if (score > highscore)
	{
		ofstream fout("HighScore.txt");
		fout << endl;
		fout << score;
		gotoxy(80, 25);
		cout << "CONGRATULATIONS!!";
		gotoxy(80, 27);
		cout << "NEW HIGHSCORE: " << score;


	}
	else {
		PrintScore(score, highscore);
	}

	while (true);


}