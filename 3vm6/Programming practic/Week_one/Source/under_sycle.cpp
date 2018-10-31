#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    /*
    Ввести с клавиатуры № лотерейного билета. 
    Задать случайным образом 16 целых чисел от 1 до 1000№№ выигравших билетов. 
    Напечатать, выиграл ли купленный билет.
    */

    srand(time(NULL));
    
    int N, n; cout << "Input number of bullet: "; cin >> N;
    for ( int i = 1; i < 17; i++ ) {
        n = rand() % 1000 + 1;
        if ( N == n )  { cout << "You win!  " << endl; break; }
        if ( i == 16 ) { cout << "You luse! " << endl; }
    }
    return 0;
}