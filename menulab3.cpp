#include "Header.h"
#include "my_function.h"
#include "menulab3.h"
using namespace std;

#include <vector>




struct Matrix {
    vector<vector<double>> data;  // данные матрицы
    int rows;                         // количество строк
    int cols;                         // количество столбцов

    // Конструктор для создания матрицы заданного размера (по умолчанию 0x0)
    Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
        data.resize(rows, vector<double>(cols, 0));  // заполняем нулями
    }
    // Метод для изменения размера матрицы
    void resize(int new_rows, int new_cols) {
        rows = new_rows;
        cols = new_cols;
        data.resize(rows);
        for (auto& row : data) {
            row.resize(cols, 0);  // заполняем новые элементы нулями
        }
    
    }

    // Оператор для доступа к элементам (можно использовать matrix[i][j])
    vector<double>& operator[](int index) {
        return data[index];
    }

    // Константная версия оператора []
    const std::vector<double>& operator[](int index) const {
        return data[index];
    }
};
void outmat(const Matrix& mati);



int M = 3;
Matrix matA(M, M);
Matrix matB(M, M);


void menulab3() {

    char ch = 0;
    do {

        system("cls");
        SetColor(CL_YELLOW, 0);
        cout << " Меню Лабораторки 3\n";
        SetColor();
        cout << "  0 - изменить размер матрицы\n";
        cout << "  1 - решение 1\n";
        cout << "  2 - ввести и сохранить матрицу в файл\n";
        cout << "  3 - згрузить матрицу из файла\n";
        cout << "  4 - Решение задачи данные из файла\n";
        cout << " ESC - Выход из программы \n\n";

        ch = _getch();

        switch (ch) {
        case '0': lab3Dot0(); break;
        case '1': lab3Dot1(); break;
        case '2': lab3Dot2(); break;
        case '3': lab3Dot3(); break;
        case '4': lab3Dot4(); break;

        case 27: break;
        default:
            cout << " Нажата клавиша " << ch << " с кодом " << int(ch) << endl;
            Sleep(1500);
        }

    } while (ch != 27);
}

void lab3Dot0()
{
    system("cls");
    uslovie3();
    sizeMat();
}

void lab3Dot1()
{
    system("cls");
    uslovie3();
    SetColor(CL_YELLOW, 0);
    cout << "  Решение 1:\n\n";
    SetColor();
    cout << "  Введите значения для марицы" << endl;
    inmat();
    cout << "  Введённая матрица: \n";
    outmat(matA);
    lab3res();
    cout << endl << "  итоговая матрица: \n";
    outmat(matB);
    LINES(2);
    system("pause");
}

void lab3Dot2()
{
    system("cls");
    uslovie3();
    savemat();
    LINES(2);
    system("pause");
}

void lab3Dot3()
{
    system("cls");
    uslovie3();
    loadmat();
    outmat(matA);
    LINES(2);
    system("pause");

}

void lab3Dot4()
{
}


void sizeMat() {
    int C;
    cout << "Укажите размер квадратной матрицы: "; cin >> M;
    cout << "Создать массив? 1 - да\n";
    SetColor(); 
    if (_getch() == '1') {
        matA.resize(M,M);
        matB.resize(M,M);
        for (int i = 0; i < matA.rows; ++i) {
            for (int j = 0; j < matA.cols; ++j) {
                matB[i][j] = matA[i][j] = 0;
            }
        }
    }
    CLEARLINE;
}

void outmat(const Matrix& mati) {
    for (int j = 0; j < mati.cols; j++) { cout << "+-------"; }
    cout << "+\n";
    for (int i = 0; i < mati.rows; i++) {
        cout << "|";
        for (int j = 0; j < mati.cols; j++) {
            double intPart;
            double fracPart = std::modf(mati[i][j], &intPart);
            if (abs(fracPart) >= 0.001) {
                cout << " " << fixed << setprecision(2) << setw(5) << mati[i][j] << " ";
                cout.unsetf(ios_base::fixed);
            }
            else {
                cout << " " << setw(5) << mati[i][j] << " ";
            }
            if (j != mati.cols - 1) {
                cout << "|";
            }
            else { cout << "|\n"; }
        }
    }
    for (int j = 0; j < mati.cols; j++) { cout << "+-------"; }
    cout << "+\n";
}

string vvodz() {
    string input;
    int Y = GetCursorPosition().Y;
    getline(cin, input);
    setCursorPosition(0, Y);
    SPACE(80);
    setCursorPosition(0, Y);
    return input;
}

//ввод массива
void inmat() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            string input;
            if (i == M && j == M) {
                SetColor(CL_RED, 0);
            }
            while (true) {
                cout << "  A[" << i << "][" << j << "] = ";
                    input = vvodz();
                try {
                    size_t pos = 0;
                    matB[i - 1][j - 1] = matA[i - 1][j - 1] = stod(input, &pos);
                    if (pos == input.size()) {
                        break;
                    }
                }
                catch (const std::invalid_argument&) {}
            }
            SetColor();
        }
    }
}


void lab3res() {
    int col_neg = 0;
    int col_pos = 0;
    for (int i = 1; i < M; i = i + 2) {
        for (int j = 0; j < M; j++) {
            if (matA.data[i][j] < 0) {
                col_neg++;
            }
        }
       
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j = j + 2) {
            if (matA.data[i][j] > 0) {
                col_pos++;
            }
        }

    }
    cout << "col_neg" << col_neg << endl;
    cout << "col_pos" << col_pos << endl;
    if (col_neg > col_pos) {
        for (int i = 1; i < M ; i++ ) {
            matB.data[i][i] = matA.data[0][i];
            matB.data[0][i] = matA.data[i][i];
        }
    }

    
}
// сохранить
string fname;
void savemat() {
    cout << "  Введите название файла ";
    cin.clear();
    cin >> fname;
    ofstream FileOut;
    FileOut.open(fname);
    if (FileOut.is_open()) {
        cout << "\n  Введите значения для марицы\n";
        inmat();
        cout << endl;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= M; j++) {
                FileOut << matA[i - 1][j - 1] << " ";
            }
            FileOut << endl;
        }
        FileOut.close();
        cout << "  Данные згружены в файл: " << fname << endl;
        Sleep(2000);
    }
    else {
        cout << "  Не удалось згрузить данные в файл" << endl;
        Sleep(1500);
    }
}
void loadmat() {
    cout << "  Введите название файла ";
    cin.clear();
    cin >> fname;
    ifstream File(fname);
    if (!File.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
    string line;
    int Lines = 0;
    int Spaces = 0;
    while (getline(File, line)) {
        Lines++;
        int spacesInLine = count(line.begin(), line.end(), ' ');
        Spaces += spacesInLine;
    }
    File.clear();
    File.seekg(0);
    if (Lines == (Spaces / Lines)) {
        M = Lines;
        matA.resize(M, M);
        matB.resize(M, M);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                File >> matA[i][j];
                matB[i][j] = matA[i][j];
            }
        }
    }
    else {
        cout << "  файл повреждён!!!";
        return;
    }
    File.close();
}
