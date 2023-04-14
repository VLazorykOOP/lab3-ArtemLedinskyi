#include <iostream>
#include "Lab3Example.h"
using namespace std;
class Game {
private:
    char Place[3][3];  // Поле,яке буде використовуватись для гри
    char Player;  // Гравець
public:
    Game() {
        // Підготовлюємо місце для гри 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Place[i][j] = '-';
            }
        }
        Player = 'X';
    }

    // вивід ігрового поля 
    void displayBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << Place[i][j] << " ";
            }
            cout << endl;
        }
    }

    // метод,у якому ми робимо так,щоб гравець міг виконувати ходи
    void makeMove() {
        int R, C;
        cout << "Хiд гравця " << Player << endl;
        cout << "Введiть номер рядка (вiд 1 до 3): ";
        cin >> R;
        cout << "Введiть номер стовбця (вiд 1 до 3): ";
        cin >> C;

        // перевіряємо чи поле не зайняте,чи ми не вийшли за кордони поля 
        if (R > 0 && R <= 3 && C > 0 && C <= 3 && Place[R - 1][C - 1] == '-') {
            Place[R - 1][C - 1] = Player;
        }
        else {
            cout << "Не правильний хід.Спробуйте ще раз." << endl;
            makeMove();  // Якщо ход не правильний,то переходить на початок цього методу 
        }
    }

    // метод,що перевіряє перемогу 
    bool checkWin() {
        // переверяє рядок
        for (int i = 0; i < 3; i++) {
            if (Place[i][0] == Place[i][1] && Place[i][1] == Place[i][2] && Place[i][0] != '-') {
                return true;
            }
            // переверяє стовбець
            if (Place[0][i] == Place[1][i] && Place[1][i] == Place[2][i] && Place[0][i] != '-') {
                return true;
            }
        }

        // перевіряє першу діагональ 
        if (Place[0][0] == Place[1][1] && Place[1][1] == Place[2][2] && Place[0][0] != '-') {
            return true;
        }
        // переверяє другу діагональ 
        if (Place[0][2] == Place[1][1] && Place[1][1] == Place[2][0] && Place[0][2] != '-') {
            return true;
        }
        return false;
    }
    bool ChekTie() { // метод, що перевірятиме чи закінчилась гра в нічию
        for (int i = 0; i < 3; i++) {// перевіряємо чи всі поля зайняті
            for (int j = 0; j < 3; j++) {
                if (Place[i][j] == '-') {
                    return false;
                }
            }
        }
        if (!checkWin()) {// якщо всі поля зайняті і немає переможця - нічия
            return true;
        }
        return false;
    }

    // метод,що перевірятиме хто має ходити наступним 
    void nextTurn() {
        if (Player == 'X') {
            Player = 'O';
        }
        else {
            Player = 'X';

        }
    }
    // метод ,який розпочинає гру 
    void play() {
        cout << "Як це працює :Ви вказуєте,який рядок Ви хочете обрати,пiсля чого ви обираєте,який стовбець"<<endl;
        cout << "Пiсля того,як Ви обрали стовбець гра вважає,що Ви зробили хiд,який не можливо повернути,тому перед тим, як походити"<<endl;
        cout << "Подумайте двiчi,куди та як саме реалiзувати Ваш хiд."<<endl;
        cout << "\t\t\t\tМої рекомендацiї щодо гри:" << endl;
        cout << "\t\t\t\tЗавдяки цьому неймовiрно зручному керуванню варто подумати довше, нiж завжди)))"<<endl;
        cout << "\t\t\t\t!!!Гарної гри!!!"<<endl;
        cout << "\t\t\t\t!Гра розпочалась!" << endl;
        while (true) {
            displayBoard();
            makeMove();
            if (checkWin()) {
                displayBoard();
                cout << "Виграв гравець " << Player << "!" << endl;
                break;
            }
            if (ChekTie()) {
                displayBoard();
                cout << "Нiчия" << endl;
                break;
            }
            nextTurn();
        }
    }

};

void GameCreated() {
    setlocale(LC_ALL, "ukr");
    Game game;
    game.play();
    return;
}

class Vector {
private:
    double Arr[3];
    int stateVar;
    int count;
public:
    Vector() : Arr{ 0,0,0 }, stateVar(0) {// Конструктор без параметрів
        count++;
    }
    Vector(double A) : Arr{ A,A,A }, stateVar(0) {// Конструктор з одним параметром double
        count++;
    }
    Vector(double* A) : stateVar(0) {// Конструктор з одним параметром вказівник на тип
        if (A != nullptr) {
            for (int i = 0; i < 3; i++) {
                Arr[i] = A[i];
            }
        }
        else {// Якщо вказівник NULL(nulptr) то встановити код помилки
            stateVar = 1;// код помилки 
        }
        count++;
    }
    ~Vector() {// Деструктор із виведенням інформації про стан вектора
        cout << endl;
        cout << "Вектор деструктований iз змiнною стану :" << stateVar << endl;
        count--;
    }
    void setVal(double A, int i) {//функція, яка присвоює масиву деяке значення
        Arr[i] = A;
    }
    double getEl(int A) {// функція, яка одержує деякий елемент з масиву
        if (A < 0 || A >= 3) {
            stateVar = 2;//код помилки 
            cout << "Значення перебiльшують заданний(A < 0 || A >= 3)лiмiт ";
        }
        return Arr[A];
    }
    void print() {//  функція друку
        for (int i = 0; i < 3; i++) {
            cout << endl;
            cout << Arr[i];
        }
    }
    Vector add(Vector V) {// додавання
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.Arr[i] = Arr[i] + V.Arr[i];
        }
        return result;
    }
    Vector sub(Vector V) {// віднімання
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.Arr[i] = Arr[i] - V.Arr[i];
        }
        return result;
    }
    Vector mult(Vector V) {// векторний добуток
        Vector  R;
        R.Arr[0] = Arr[1] * V.Arr[2] - Arr[2] * V.Arr[1];
        R.Arr[1] = Arr[2] * V.Arr[0] - Arr[0] * V.Arr[2];
        R.Arr[2] = Arr[0] * V.Arr[1] - Arr[1] * V.Arr[0];
        return R;
    }
    Vector Div(short V) {// функція ділення на ціле типу short
        Vector result;
        if (V == 0) {
            stateVar = 3;//код помилки 
            cout << "Відбулось ділення на нуль";
        }
        else {
            for (int i = 0; i < 3; i++) {
                result.Arr[i] = Arr[i] / V;
            }
        }
        return result;
    }
    bool operator==(Vector E) {//функція порівняння рівно
        for (int i = 0; i < 3; i++) {
            if (Arr[i] != E.Arr[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(Vector E) {// функція порівняння більше
        double A = sqrt(Arr[0] * Arr[0] + Arr[1] * Arr[1] + Arr[2] * Arr[2]);
        double B = sqrt(E.Arr[0] * E.Arr[0] + E.Arr[1] * E.Arr[1] + E.Arr[2] * Arr[2]);
        if (A > B) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(Vector E) {// функція порівняння менше
        double A = sqrt(Arr[0] * Arr[0] + Arr[1] * Arr[1] + Arr[2] * Arr[2]);
        double B = sqrt(E.Arr[0] * E.Arr[0] + E.Arr[1] * E.Arr[1] + E.Arr[2] * Arr[2]);
        if (A < B) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void Task() {
    setlocale(LC_ALL, "ukr");
    cout << "Стосовно булевих функцiй, якщо виводить 1,то значення повертає true,а якщо 0 -false";
    double M = 2;
    double* A = new double;
    *A = 3;
    Vector Aa;
    cout << endl;
    cout << "Виведення конструктора без параметрiв";
    Aa.print();
    Vector Y(M);
    cout << endl;
    cout << "Виведення конструктора з одним параметром типу double";
    Y.print();
    Vector D(*A);
    cout << endl;
    cout << "Виведення конструктора з одним параметром вказiвник на тип";
    D.print();
    cout << endl;
    cout << "Додавання :" << endl;
    Vector Bb;
    Bb = Y.add(D);
    Bb.print();
    Vector Cc;
    cout << endl;
    cout << "Вiднiмання :" << endl;
    Cc = Y.sub(D);
    Cc.print();
    cout << endl;
    Vector Zz;
    double V;
    for (int i = 0; i < 3; i++) {
        cout << "Введiть значення :" << endl;
        cin >> V;
        Y.setVal(V, i);
    }
    Zz = Y.mult(D);
    cout << endl;
    cout << "Операцiя множення :" << endl;
    Zz.print();
    Vector S;
    cout << endl;
    cout << "Операцiя дiлення на певне число :" << endl;
    S = Y.Div(2);
    S.print();
    bool I;
    I = Y.operator==(D);
    cout << "Оператор дорiвнює :";
    cout << I;
    bool P;
    P = Y.operator<(D);
    cout << "Оператор менше :";
    cout << P;
    bool T;
    T = Y.operator>(D);
    cout << "Оператор бiльше :";
    cout << T;
    delete A;
    return;
}
#include <iostream>
using namespace std;
/*Створити клас матриця. Даний клас містить вказівник на int, розміри рядків і
стовпців та стан помилки. У класі визначити
o конструктор без параметрів( виділяє місце для матриці 3 на 3 елемента та
інінціалізує його в нуль);
o конструктор з одним параметром – розмір n матриці (виділяє місце n на n та
інінціалізує матрицю значенням нуль);
o конструктор із трьома розміри матриці (n , m) та значення ініціалізації value
(виділяє місце перші аргументи та інінціалізує значенням третього аргументу -
value);
o конструктор копій та операцію присвоєння; // !!!
o деструктор звільняє пам'ять.
o визначити функцію, яка присвоює елементу масиву деяке значення (параметр за
замовчуванням);
o функцію яка одержує деякий елемент матриці за індексами i та j;
o визначити функції друку, додавання, множення, віднімання, які здійснюють ці
арифметичні операції з даними цього класу;
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі
матриці. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму
тестування всіх можливостей цього класу.*/
#include<iostream>
#include<string>
using namespace std;
class Matrix {
private:
    int** A;
    int R, C;
    int state;
    bool L;
public:
    void SetL(bool L) {
       this->L=L;
    }
    Matrix() :R(3), C(3), state(0) {
        A = new int* [3];
        for (int i = 0; i < 3; i++) {
            A[i] = new int[3];
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                A[i][j] = 0;
            }
        }
    }
    Matrix(int n) :R(n), C(n), state(0) {
        A = new int* [n];
        for (int i = 0; i < n; i++) {
            A[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }
    }
    Matrix(int n, int m, int value) :R(n), C(m), state(0) {
        A = new int* [n];
        for (int i = 0; i < n; i++) {
            A[i] = new int[m];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = value;
            }
        }
    }
    Matrix(const Matrix& B) :R(B.R), C(B.C), state(0) {
        this->A = new int* [B.R];
        for (int i = 0; i < B.R; i++) {// Конструктор копій
            A[i] = new int[B.C];
        }
        for (int i = 0; i < B.R; i++) {// Операцію присвоєння
            for (int j = 0; j < B.C; j++) {
                A[i][j] = B.A[i][j];
            }
        }
    }
    ~Matrix() {
        if (L) {
            for (int i = 0; i < R; i++) {
                delete[] A[i];
            }
            delete[] A;
        }
        else {
            L = true;
        }
    }
    void SetVal(int Value, int i, int j) {
        A[i][j] = Value;
    }
    int  GetVal(int i, int j) {
        return A[i][j];
    }
    void print() {
        for (int i = 0; i < R; i++) {
            cout << endl;
            for (int j = 0; j < C; j++) {
                cout << A[i][j] << " ";
            }
        }
    }
    Matrix Add(Matrix B) {
        Matrix result;
        if (R != B.R || C != B.C) {
            cout << "Розмірність матриць не співпадає ";
            return result;
        }
        else {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    result.A[i][j] = A[i][j] + B.A[i][j];
                }
            }
        }
        result.SetL(false);
        return result;
    }
    Matrix Sub(Matrix B) {
        Matrix result;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                result.A[i][j] = A[i][j] - B.A[i][j];
            }
        }
        result.SetL(false);
        return result;
    }
    Matrix Mult(const Matrix& B) {
        Matrix result(R, B.C, 0);
        if (C != B.R) {
            state = 1;
            cout << "Перемноження матриць неможливе!";
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < B.C; j++) {
                int sum = 0;
                for (int k = 0; k < C; k++) {
                    sum += A[i][k] * B.A[k][j];
                }
                result.A[i][j] = sum;
            }
        }
        result.SetL(false);
        return result;
    }
    bool operator==(Matrix E) {//функція порівняння рівно
        if (this->R != E.R || this->C != E.C) {
            return false;
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (this->A[i][j] != E.A[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    int GetR() {
        return this->R;
    }
    int GetC() {
        return this->C;
    }
    bool operator>(Matrix G) {
        if (this->R != G.GetR() || this->C != G.GetC()) {
            cout << "Функцію зробити не можливо!";
            return false;
        }
        else {
            for (int i = 0; i < R; i++) {
                {
                    for (int j = 0; j < C; j++) {
                        if (this->A[i][j] <= G.GetVal(i, j)) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
    bool operator<(Matrix G) {
        if (this->R != G.GetR() || this->C != G.GetC()) {
            cout << "Функцію зробити не можливо!";
            return false;
        }
        else {
            for (int i = 0; i < R; i++) {
                {
                    for (int j = 0; j < C; j++) {
                        if (this->A[i][j] >= G.GetVal(i, j)) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
};
void task3(){
     setlocale(LC_ALL, "ukr");
    Matrix A;
    cout << "Конструктор з одним параметром .";
    A.print();
    Matrix B(3);
    cout << endl;
    cout << "Конструктор з двома параметром .";
    B.print();
    Matrix C(3, 3, 5);
    cout << endl;
    cout << "Конструктор з трьома параметрами .";
    C.print();
    cout << endl;
    cout << "Додавання " << endl;
    Matrix Z;
    Z = C.Add(B);
    Z.print();
    cout << endl;
    Matrix Cc;
Cc=C.Mult(B);
cout<<"Множення :"<<endl;
Cc.print();
bool P = C.operator==(B);
cout<<endl;
cout<<"Оператор дорівнює :"<<endl;
cout<<P<<endl;
bool J =C.operator<(B);
cout<<"Оператор менше :"<<endl;
cout<<J<<endl;
bool L = C.operator>(B);
cout<<"Оператор більше :"<<endl;
cout<<L<<endl;
Matrix DCP;
cout<<"Вставлення значення :"<<endl;
DCP.SetVal(5,1,2);
DCP.print();
cout<<endl;
    return;
}
int main()
{
    setlocale(LC_ALL, "ukr");
    int n;
    cout << "1 чи 2 :" << endl;
    cin >> n;
    if (n == 1) {
        GameCreated();
    }
    if (n == 2) {
        Task();
    }
    if(n == 3){
        Task3();
    }
    return 0;
}
