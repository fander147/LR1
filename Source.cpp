#include "Header.h"
#include "my_function.h"

using namespace std;
void Creator();
int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");
	SetConsoleTitle(L"Учебная программ по дисциплине \"Прогромирование\"");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char ch = 0;
	do {
		system("cls");
		SetColor(CL_YELLOW, 0);
		cout << " Меню приложения\n";
		SetColor();
		cout << " 0 - Информация о програмисте \n";
		cout << " 1 - Лабораторная работа №1 \n";
		cout << " 2 - Лабораторная работа №2 \n";
		cout << " 3 - Лабораторная работа №3 \n";
		cout << " 4 - Лабораторная работа №4 \n";
		cout << " ESC - Выход из программы \n\n";
		cout << " Нажмите клавишу для выполнения функии\n\n";

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
			cout << " Нажата клавиша " << ch << " с кодом " << int(ch) << endl;
			Sleep(1500);
		}
	} while (ch != 27);
}
void Creator() {
	system("cls");
	cout << "\n";
	SPACE(30);
	cout <<	"Программу написал Щепилов П. Д. из группы 1бИВТ2 \n\n";
	SPACE(13);
	cout << "Место обучения: Московский автомобильно-дорожный государственный технический университет\n\n";
	system("pause");
}