
#pragma once

void menulab1();
void lab1Dot1();
void lab1Dot2();
void lab1res();
void setCursorPosition(int x, int y);
void uslovie1();


typedef
enum enColor {
	CL_BLACK, //������ 
	CL_BLUE,   // �����
	CL_GREEN,  // ������
	CL_CYAN,  // �������
	CL_RED,    // �������
	CL_PURPLE,  //����������
	CL_YELLOW,  //�����
	CL_WHITE,  // �����
	CL_LIGHT_BLACK,//������ �������
	CL_LIGHT_BLUE,//����� �������
	CL_LIGHT_GREEN,//������ �������
	CL_LIGHT_CYAN,// ������� �������
	CL_LIGHT_RED,// ������� �������
	CL_LIGHT_PURPLE,// ���������� �������
	CL_LIGHT_YELLOW,//����� �������
	CL_LIGHT_WHITE,//����� �������

	������ = 0,
	�����,
	��˨���,
	�������,
	�������,
	����������,
	ƨ����,
	�����,
	�����,
	��_�����,
	��_��˨���,
	��_�������,
	��_�������,
	��_����������,
	��_ƨ����,

} COLORS, �����;// ���������
static COLORS DefBKColor = enColor::CL_BLACK;
static COLORS DefTextColor = enColor::CL_LIGHT_WHITE;
//static - �����, ����� ���� ������, ��� ���������� ����������
void SetColor(short int pnTextColor, short int pnBkcolor);
void SetColor();
void SetDefBkColor(short int pnBkColor);