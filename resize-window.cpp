#include <iostream>
#include <windows.h> 

using namespace std;


void SetWindow(int Width, int Height) 
{ 
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
} 

int main(int argc,char **argv) 
{   
	int cols  = atoi(argv[1]);
	int lines = atoi(argv[2]);
    SetWindow(cols,lines);

	/*
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	
    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);
	*/

  return 0;
}  
