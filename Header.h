#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

#define CLEARLINE(n) for (int i=0;i<n;i++) cout << "\033[F\r\033[K"
#define LINES(a) for (int i=0;i < a;i++) cout << endl
#define CURSORPOS GetCursorPosition();
