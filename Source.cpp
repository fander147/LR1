#include "Header.h"
#include "my_function.h"

using namespace std;
void Creator();
int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");
	SetConsoleTitle(L"������� �������� �� ���������� \"���������������\"");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char ch = 0;
	do {
		system("cls");
		SetColor(CL_YELLOW, 0);
		cout << " ���� ����������\n";
		SetColor();
		cout << " 0 - ���������� � ����������� \n";
		cout << " 1 - ������������ ������ �1 \n";
		cout << " 2 - ������������ ������ �2 \n";
		cout << " 3 - ������������ ������ �3 \n";
		cout << " 4 - ������������ ������ �4 \n";
		cout << " ESC - ����� �� ��������� \n\n";
		cout << " ������� ������� ��� ���������� ������\n\n";

		ch = _getch();
		switch (ch)
		{
		case '0': Creator(); break;
		case '1': menulab1(); break;
		case '2': break;
		case '3': break;
		case '4': break;
		case 27: break;
		default:
			cout << " ������ ������� " << ch << " � ����� " << int(ch) << endl;
			Sleep(1500);
		}
	} while (ch != 27);
}
void Creator() {
	system("cls");
	cout << "\n";
	SPACE(30);
	cout <<	"��������� ������� ������� �. �. �� ������ 1����2 \n\n";
	SPACE(13);
	cout << "����� ��������: ���������� ������������-�������� ��������������� ����������� �����������\n\n";
	system("pause");
}