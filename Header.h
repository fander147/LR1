#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

#define LINES(a) for (int ii=0;ii < a;ii++) cout << endl
#define CURSORPOS GetCursorPosition()
#define BACK(n) for (int ii=0; ii<n; ii++) cout<<"\b"
#define SPACEBACK(n)  SPACE(n); BACK(n) 
#define SPACE(a) for (int i=0;i < a;i++) cout << " "
#define CLEARLINE setCursorPosition( 0 , GetCursorPosition().Y); SPACEBACK(80)
