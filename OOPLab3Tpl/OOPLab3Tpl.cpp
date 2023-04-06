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
    Vector() : Arr{ 0,0,0 }, stateVar(0) {
        count++;
    }
    Vector(double A) : Arr{ A,A,A }, stateVar(0) {
        count++;
    }
    Vector(double* A) : stateVar(0) {
        if (A != nullptr) {
            for (int i = 0; i < 3; i++) {
                Arr[i] = A[i];
            }
        }
        else {
            stateVar = 1;// код помилки 
        }
        count++;
    }
    ~Vector() {
        cout << endl;
        cout << "Вектор деструктований iз змiнною стану :" << stateVar << endl;
        count--;
    }
    void setVal(double A, int i) {
        Arr[i] = A;
    }
    double getEl(int A) {
        if (A < 0 || A >= 3) {
            stateVar = 2;//код помилки 
            cout << "Значення перебiльшують заданний(A < 0 || A >= 3)лiмiт ";
        }
        return Arr[A];
    }
    void print() {
        for (int i = 0; i < 3; i++) {
            cout << endl;
            cout << Arr[i];
        }
    }
    Vector add(Vector V) {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.Arr[i] = Arr[i] + V.Arr[i];
        }
        return result;
    }
    Vector sub(Vector V) {
        Vector result;
        for (int i = 0; i < 3; i++) {
            result.Arr[i] = Arr[i] - V.Arr[i];
        }
        return result;
    }
    Vector mult(Vector V) {
        Vector  R;
        R.Arr[0] = Arr[1] * V.Arr[2] - Arr[2] * V.Arr[1];
        R.Arr[1] = Arr[2] * V.Arr[0] - Arr[0] * V.Arr[2];
        R.Arr[2] = Arr[0] * V.Arr[1] - Arr[1] * V.Arr[0];
        return R;
    }
    Vector Div(short V) {
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
    bool operator==(Vector E) {
        for (int i = 0; i < 3; i++) {
            if (Arr[i] != E.Arr[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(Vector E) {
        double A = sqrt(Arr[0] * Arr[0] + Arr[1] * Arr[1] + Arr[2] * Arr[2]);
        double B = sqrt(E.Arr[0] * E.Arr[0] + E.Arr[1] * E.Arr[1] + E.Arr[2] * Arr[2]);
        if (A > B) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(Vector E) {
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
    Aa.print();
    Vector Y(M);
    Y.print();
    Vector D(*A);
    D.print();
    Y.add(D);
    Vector Bb;
    Bb = Y.add(D);
    Bb.print();
    Vector Cc;
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
    Zz.print();
    Vector ShadowFiend;
    ShadowFiend = Y.Div(2);
    ShadowFiend.print();
    bool Invoker;
    Invoker = Y.operator==(D);
    cout << "Оператор дорiвнює :";
    cout << Invoker;
    bool Puck;
    Puck = Y.operator<(D);
    cout << "Оператор менше :";
    cout << Puck;
    bool Tinker;
    Tinker = Y.operator>(D);
    cout << "Оператор бiльше :";
    cout << Tinker;

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
}

