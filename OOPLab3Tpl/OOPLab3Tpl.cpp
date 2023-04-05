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

    // метод,що перевіряє перемоги 
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
        cout << "Після того,як Ви обрали стовбець гра вважає,що Ви зробили хiд,який не можливо повернути,тому перед тим, як походити"<<endl;
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
                cout << "Нічия" << endl;
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


int main()
{
    GameCreated();
}

