#include <iostream>

using namespace std;

int main(){
    /*
    Дано натуральное число n (n<=9999). 
    Является ли это число палиндромом (перевертышем) 
    с учетом четырех цифр,  
    как, например, числа 2222, 6116, 0440 и т.д.?
    */

    int N; cout << "Input N: "; cin >> N;
    int a,b,c,d;

    if ( N <= 9999 ){
        a = N / 1000    ;
        b = N / 100 % 10;
        c = N % 100 / 10;
        d = N % 10      ; 

        if ( a == d && b == c ) { 
            cout << " This is palindrom!   " << endl; 
        }
        else { 
            cout << " This is'n palindrom! " << endl; 
            }   
    }
    else {
        cout << "Wrong!" << endl;
    }

    return 0;
}
