#include "Header.h"
#include "my_function.h"
using namespace std;

int N = 16;
double* masA = nullptr;
double* masB = nullptr;
int sizeMas();
void save();
void load();
void Table(double* pmas, int pnsize, int pnsec, string pstitle);
void Tabletex(double* mas, int N, const string& title, const string& namep);
void outmas(double masi[]);
void menulab1() {
	masA = new double[N];
	masB = new double[N];
	for (int i = 0; i < N; i++) {
		masA[i] = masB[i] = 0;
	}
	char ch = 0;
	do {

		system("cls");

		SetColor(CL_YELLOW, 0);
		cout << " ���� ����������� 1\n";
		SetColor();
		cout << "  0 - �������� ������ �������\n";
		cout << "  1 - ������� 1\n";
		cout << "  2 - ������� 2\n";
		cout << "  3 - ������ � ��������� ������ � ����\n";
		cout << "  4 - �������� ������ �� �����\n";
		cout << "  5 - ������� ������ ������ �� �����\n";
		cout << "  6 - ��������� ����������� ������������� �������\n";
		cout << "  7 - ��������� ������������� �������\n";
		cout << " ESC - ����� �� ��������� \n\n";

		ch = _getch();

		switch (ch) {
		case '0': sizeMas(); break;
		case '1': lab1Dot1(); break;
		case '2': lab1Dot2(); break;
		case '3':
			system("cls");
			uslovie1();
			save();
			break;
		case '4':
			system("cls");
			uslovie1();
			load();
			system("pause");
			break;
		case '5':
			system("cls");
			uslovie1();
			SetColor(CL_YELLOW, 0);
			cout << "  ������� c ������:\n\n";
			SetColor();
			load();
			LINES(2);
			lab1res();
			Tabletex(masA, N, "�������� ������", "A");
			cout << endl;
			Tabletex(masB, N, "������������ ������", "B");
			system("pause");
			break;
		case '6':
			system("cls");
			//uslovie1();
			cout << endl;
			Table(masA, N, 16, "�������� ������");
			LINES(8);
			Table(masB, N, 16, "������������ ������");
			cout << endl;
			_getch();
			break;
		case '7':
			Tabletex(masA, N, "�������� ������", "A");
			cout << endl;
			Tabletex(masB, N, "������������ ������", "B");
			system("pause");
			break;

		case 27: break;
		default:
			cout << " ������ ������� " << ch << " � ����� " << int(ch) << endl;
			Sleep(1500);
		}

	} while (ch != 27);
}
//������ �������
int sizeMas() {
	while (true) {
		cout << "������� ������ �������: "; cin >> N;
		if (N < 10) {
			cout << "�� ������� ��������� ������� 10 ���������\n";
			system("pause");
		}
		else {
			cout << "������� ������? 1 - ��\n";
			SetColor();
			if (_getch() == '1') {
				masA = new double[N];
				masB = new double[N];
				for (int i = 0; i < N; i++) {
					masA[i] = masB[i] = 0;
				}
			}
			return N;
			break;
		}
		CLEARLINE;
	}
}
//���� �������
void inmas() {
	for (int i = 1; i <= N; i++) {
		string input;
		if (i == N) {
			SetColor(CL_RED, 0);
		}
		while (true) {
			cout << "  A[" << i << "]=";
			getline(cin, input);
			try {
				size_t pos = 0;
				masA[i - 1] = stod(input, &pos);
				if (pos == input.size()) {
					//cout << "\033[F\r\033[K";
					CLEARLINE;
					break;
				}
				else { cout << "\033[F\r\033[K"; }
			}
			catch (const std::invalid_argument&) { cout << "\033[F\r\033[K"; }
		}
		SetColor();
	}
}
//����� ������
void outmas(double masi[]) {
	cout << "[";
	for (int i = 0; i < N; i++) {
		double intPart;
		double fracPart = std::modf(masi[i], &intPart);
		if (std::abs(fracPart) >= 0.001) {
			cout << " " << fixed << setprecision(2) << masi[i] << " ";
		}
		else {
			cout << " " << masi[i] << " ";
		}
		if (i != N - 1) {
			cout << ",";
		}
		else { cout << "]"; }
	}
}
//������� 1
void lab1Dot1() {

	char ch = 0;
	system("cls");
	uslovie1();
	SetColor(CL_YELLOW, 0);
	cout << "  ������� 1:\n\n";
	SetColor();
	cout << "  ������� ������ ������" << endl;
	inmas();
	//CLEARLINE;// (1);
	cout << "  �������� ������: \n";
	outmas(masA);
	cout << endl << "  �������� ������: \n";
	lab1res();
	outmas(masB);
	ch = _getch();
}
void lab1Dot2(){
	char ch = 0;
	system("cls");
	uslovie1();
	SetColor(CL_YELLOW, 0);
	cout << "  ������� 2:\n\n";
	SetColor();
	cout << "  ������� ������ ������" << endl;
	inmas();
	CLEARLINE;// (1);
	lab1res();
	Tabletex(masA, N, "�������� ������", "A");
	cout << endl;
	Tabletex(masB, N, "�������� ������", "B");
	system("pause");
}
// ���������
string namef;
void save() {
	cout << "  ������� �������� ����� ";
	getline(cin, namef);
	cout << "\n  ������� ������ ������ \n";
	inmas();
	ofstream File(namef);
	if (File.is_open()) {
		for (int i = 1; i <= N; i++) {
			File << masA[i - 1] << endl;
		}
		File.close();
		cout << "  ������ �������� � ����: " << namef << endl;
		Sleep(2000);
	}
	else {
		cout << "  �� ������� �������� ������ � ����" << endl;
		Sleep(1500);
	}
}
// ���������
void load() {
	cout << "  ������� �������� ����� ";
	getline(cin, namef);
	ifstream File(namef);
	int lineCount = 0;
	string line;
	while (getline(File, line)) {
		lineCount++;
	}
	if (File.is_open()) {
		if (lineCount >= N) {
			if (lineCount > N) {
				cout << " � ������ ���� ��������� ������ " << N << " ,��� ��� ������ ������� ������ ������� �����";
			}
		}
		else {
			cout << "  ������ ������� ������ ������� �����, ������� ����������� ��������\n";
			for (int i = lineCount + 1; i <= N; i++) {
				string input;
				if (i == N) {
					SetColor(CL_RED, 0);
				}
				while (true) {
					cout << "  A[" << i << "]=";
					getline(cin, input);

					try {
						size_t pos = 0;
						masA[i - 1] = stod(input, &pos);
						if (pos == input.size()) {
							cout << "\033[F\r\033[K";
							break;
						}
						else { cout << "\033[F\r\033[K"; }
					}
					catch (const std::invalid_argument&) { cout << "\033[F\r\033[K"; }
				}
				SetColor();
			}
		}
		for (int i = 1; i <= N; i++) {
			File >> masA[i - 1];
		}
		File.close();
		cout << "\n  ���������e ������ �� �����: " << endl;
		outmas(masA);
		cout << endl;
	}
	else {
		cout << "  �� ������� ������� ����" << endl;
		Sleep(1500);
	}
}
// ��������� �������
void lab1res() {
	for (int i = 0; i < N; i++) {
		masB[i] = masA[i];
	}
	int maxi = 0;
	for (int i = 1; i < N; i++) {
		if (masA[i] > masA[maxi]) {
			maxi = i;
		}
	}

	if (maxi < 9) {
		double A2 = masA[1];
		for (int i = 0; i < maxi; i++) {
			masB[i] = A2;
		}
	}
	else {
		for (int i = 0; i <= N - 1; i++) {
			masB[i] = masA[i] / 3;
		}
	}

}
//��������� �������
void Tabletex(double* mas, int N, const string& title, const string& namep) {
	cout << title << endl;
	for (int i = 0; i < N; i++) {
		cout << "|" << namep << left << setw(4) << i + 1 << setw(2) << ":  " << setw(10) << left << mas[i] << endl;
	}

}
//����������� �������
void Table(double* pmas, int pnsize, int pnsec, string pstitle) {
	HWND hwnd = (HWND)GetStdHandle(STD_OUTPUT_HANDLE);
	HDC hdc = GetDC(GetConsoleWindow());

	CONSOLE_FONT_INFO conf{};
	GetCurrentConsoleFont(hwnd, false, &conf);
	COORD cxy = CURSORPOS;


	int indentY = conf.dwFontSize.Y * (cxy.Y + 1), // ������ ������ ���� ������
		indentX = 30;

	HFONT hfont = CreateFontA(34, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	HFONT holdfont = (HFONT)SelectObject(hdc, hfont);

	SetTextColor(hdc, RGB(0, 255, 255));
	SetBkColor(hdc, RGB(0, 0, 0));
	TextOutA(hdc, indentX + 100, indentY, pstitle.c_str(), pstitle.length());
	SelectObject(hdc, holdfont);
	DeleteObject(hfont);


	indentY += 34;
	int nsec = pnsize / pnsec + ((pnsize % pnsec > 0) ? 1 : 0);

	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	LOGBRUSH lgbr{ PS_SOLID, RGB(94, 94, 94), 0 };
	HBRUSH hbrush = CreateBrushIndirect(&lgbr);
	HANDLE oldbrush = SelectObject(hdc, hbrush),
		odlpen = SelectObject(hdc, hpen);


	Rectangle(hdc, indentX, indentY, indentX + pnsec * 5 * conf.dwFontSize.X, indentY + (5 * conf.dwFontSize.Y) * nsec);
	for (int i = 0; i < nsec; i++) {
		int nx = indentX,
			nx2 = indentX + pnsec * 5 * conf.dwFontSize.X;
		MoveToEx(hdc, nx, indentY + i * 5 * conf.dwFontSize.Y + (5 * conf.dwFontSize.Y) / 2, NULL);
		LineTo(hdc, nx2, indentY + i * 5 * conf.dwFontSize.Y + (5 * conf.dwFontSize.Y) / 2);
		MoveToEx(hdc, nx, indentY + i * (5 * conf.dwFontSize.Y), NULL);
		LineTo(hdc, nx2, indentY + i * (5 * conf.dwFontSize.Y));
	}

	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkColor(hdc, RGB(94, 94, 94));

	for (int i = 0; i < pnsec; i++) {
		int nx = indentX + (i) * 5 * conf.dwFontSize.X,
			ny = indentY;
		MoveToEx(hdc, nx, ny, NULL);
		LineTo(hdc, nx, ny + (5 * conf.dwFontSize.Y * nsec));

		char txt[30]{};
		for (int j = 0; j < nsec; j++) {
			if (j * pnsec + i < pnsize) {
				sprintf_s(txt, "X%d", j * pnsec + i + 1);
				SIZE sz{};
				GetTextExtentPoint32A(hdc, txt, strlen(txt), &sz);
				SetTextColor(hdc, RGB(50, 205, 50));
				SetBkColor(hdc, RGB(94, 94, 94));
				TextOutA(hdc, nx + (5 * conf.dwFontSize.X - sz.cx) / 2, ny + j * (conf.dwFontSize.Y * 5) + conf.dwFontSize.Y, txt, strlen(txt));
				sprintf_s(txt, "%5.1f", pmas[j * pnsec + i]);
				GetTextExtentPoint32A(hdc, txt, strlen(txt), &sz);
				SetTextColor(hdc, RGB(255, 255, 255));
				SetBkColor(hdc, RGB(94, 94, 94));
				TextOutA(hdc, nx + (5 * conf.dwFontSize.X - sz.cx) / 2, ny + j * (conf.dwFontSize.Y * 5) + 3 * conf.dwFontSize.Y, txt, strlen(txt));
			}
		}
	}
}