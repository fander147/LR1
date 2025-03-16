#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

#define CLEARLINE(n) for (int i=0;i<n;i++) cout << "\033[F\r\033[K"
