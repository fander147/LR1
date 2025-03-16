
#pragma once

void menulab1();
void lab1Dot1();
void lab1res();
void setCursorPosition(int x, int y);
COORD GetCursorPosition();
void uslovie1();


typedef
enum enColor {
	CL_BLACK, //черный 
	CL_BLUE,   // синий
	CL_GREEN,  // зелёный
	CL_CYAN,  // голубой
	CL_RED,    // красный
	CL_PURPLE,  //фиолетовый
	CL_YELLOW,  //жёлтый
	CL_WHITE,  // белый
	CL_LIGHT_BLACK,//черный светлый
	CL_LIGHT_BLUE,//синий светлый
	CL_LIGHT_GREEN,//зелёный светлый
	CL_LIGHT_CYAN,// голубой светлый
	CL_LIGHT_RED,// красный светлый
	CL_LIGHT_PURPLE,// фиолетовый светлый
	CL_LIGHT_YELLOW,//жёлтый светлый
	CL_LIGHT_WHITE,//белый светлый

	ЧЕРНЫЙ = 0,
	СИНИЙ,
	ЗЕЛЁНЫЙ,
	ГОЛУБОЙ,
	КРАСНЫЙ,
	ФИОЛЕТОВЫЙ,
	ЖЁЛТЫЙ,
	БЕЛЫЙ,
	СЕРЫЙ,
	СВ_СИНИЙ,
	СВ_ЗЕЛЁНЫЙ,
	СВ_ГОЛУБОЙ,
	СВ_КРАСНЫЙ,
	СВ_ФИОЛЕТОВЫЙ,
	СВ_ЖЁЛТЫЙ,

} COLORS, ЦВЕТА;// нумератор
static COLORS DefBKColor = enColor::CL_BLACK;
static COLORS DefTextColor = enColor::CL_LIGHT_WHITE;
//static - нужен, чтобы дать понять, что переменные глобальные
void SetColor(short int pnTextColor, short int pnBkcolor);
void SetColor();
void SetDefBkColor(short int pnBkColor);
