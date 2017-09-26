#include <iostream>
#include <time.h>

using namespace std;

void longest(){
    int ed; double L;

    cout << "Введите Единицу измерения \n (1 - дц, 2 - км, 3 - м, 4 - мм, 5 - см): " << endl;
    cin >> ed;
    cout << "Введите длину отрезка: "; cin >> L;

    switch (ed){
        case 1:{
            cout << L << " дц = " << L/10 << " м " << endl; break;
        }
        case 2:{
            cout << L << " км = " << L*1000 << " м " << endl; break;
        }
        case 3:{
            cout << L << " м = " << L << " м " << endl; break;
        }
        case 4:{
            cout << L << " мм = " << L/10000 << " м " << endl; break;
        }
        case 5:{
            cout << L << " см = " << L/100 << " м " << endl; break;
        }
    }
}

void knb(){// Камень ножницы бумага
    int player, computer;
    //srand(time(NULL)); computer = 1+rand() % 3;
    cin >> computer;
    cout << "Выберите предмет (камень -1, ножницы – 2, бумага - 3): ";
    cin >> player;

    switch (computer){
        case 1:{
            cout << "Компьютер выбрал камень";
        }
        case 2:{
            cout << "Компьютер выбрал ножицы";
        }
        case 3:{
            cout << "Компьютер выбрал бумага";
        }
    }
    switch (player){
        case 1:{
            cout << "   Вы выбрали камень";
        }
        case 2:{
            cout << "   Вы выбрали ножицы";
        }
        case 3:{
            cout << "   Вы выбрали бумага";
        }
    }
    // Находим победителя
    switch (computer){
        case 1:{
            if (player == 2){
                cout << " Вы проиграли, камень тупит ножницы" << endl; break;
            }
            if (player == 3){
                cout << "Вы выиграли, бумага накрывает камень" << endl; break;
            }
        }
        case 2:{
            if (player == 3){
                cout << "Вы проиграли, ножницы режут камень" << endl; break;
            }
            if (player == 1){
                cout << "Вы выиграли, камень тупит ножницы" << endl; break;
            }
        }
        case 3:{
            if (player == 1){
                cout << "Вы проиграли, бумага накрывает камень" << endl; break;
            }
            if (player == 2){
                cout << "Вы выиграли, ножницы режут бумагу" << endl; break;
            }
        }
        default:{
            cout << "Ничья!" << endl; break;
        }
    }

}

int main(){
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "1 - Задание про длину \n 2 - Камень ножницы бумага \n"; cin >> a;
	switch (a){
		case 1:{
			longest(); break;
		}
		case 2:{
			knb(); break;
        }
        default:{
            cout << "Ваш ввод не соответствует условию" << endl;
        }
	}
}
