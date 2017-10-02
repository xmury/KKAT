#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void task1(){// i know number
    int m, i = 5, out;
    srand(time(NULL));  m = 1+rand() % 9;
    
    cout << "I know number of 1 - 10. Think!" << endl;
    do{
      cout << " Attempts left: " << i << ": "; cin >> out; 
      if (out == m){
          cout << " You win" << endl; break;
      }  
      else{
          cout << " Error, try again." << endl; i--;
      }
    }while(i > 0);
}

void task2(){// size displey
    cout << "A task 1" << endl;
    double x,y;
    cout << " Input size displey in inch (duim): "; cin >> x >> y;
    
    while(x != y++){
        cout << " inches: " << x << " = centimeters " << x * 2.54;
        x++;
    }
}

void task3(){// table of multiplication
    cout << "A task 3" << endl;
    int x;
    cout << " Input num: " << x;

    for(int i = 1; i <=10; i++){
        cout << i << " * " << x << " = " << i*x;
    }
}

void task4(){// your deposite
    cout << "A task 4" << endl;
    int N, y = 0;
    double x, d = 0;
    
    int t;
    cout << " Input summ on your deposite: "; cin >> x;
    cout << " How years your deposits? : "; cin >> N; 
    double P; cout << " How percent your devidents? : "; cin >> P;
    cout << d << endl;
    while(N >= 1){
        y++; N--; t = (x / 100)*P ;
        cout << "Years passed: " << y << ", your dividents:  " << d << endl;
        x = x + t; d = d + t;
    }

    cout << " Summ your dividents: " << d << endl;
}

void task5(){// heppined tickets
    int q,w,e,r,y = 0;
    cout << "A task 5" << endl;
    cout << " - How heppined tickets?" << endl;
        for(int i = 1; i < 10000; i++){
            q = i/1000;
            w = i/100%10;
            e = i/10%10;
            r = i%10;
    
            if (q+w == e+r){
                y++;
            }
        }
    
        cout << " - " << y << endl;
        cout << " - Excelent. Bye!" << endl;
}
int main(){
    int in; cout << "Input nuber of 1 - 5: "; cin >> in;
    switch (in){
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;

    default:
        cout << " Your inpet is'n corected..." << endl;
        break;
    }
    return 0;
}