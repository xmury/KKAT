#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void task1(){// Задача 1
    int m, i = 5;
    srand(time(NULL));  m = 1+rand() % 9;
    
    cout << "Я задумал число от 1 до 10. Попробуйте отгадать!"
    do{
      cout << "Попыток осталось: " << i << ": "; cin >> out; 
      if (out == m){
          cout << "Вы победили" << endl; break
      }  
      else{
          cout << "Не верно. Пробуйте снова." << endl; i--;
      }
    }while(i > 0)
}

void task2(){// Задача 2
    cout << "Задача 2" << endl;
    double x,y;
    cout << " Введите размеры экранов в дюймах от x до y: "; cin >> x >> y;
    
    while(x != y++){
        cout << " дюймы : " << x << " = сантиметры: " << x * 2.54;
        x++;
    }
}

void task3(){// Задача 3
    cout << "Задача 3" << endl;
    int x;
    cout << " Введите число: " << x;

    for(int i = 1; i <=10; i++){
        cout << i << " * " << x << " = " << i*x;
    }
}

void task4(){// Задача 4
    cout << "Задача 4" << endl;
    int x, N, y = 0;
    int d;
    cout << " Введите сумму которую хотите положить на депозит: "; cin >> x;
    cout << " На сколько лет? : "; cin >> N; 
    double P; cout << " Под какой процент? : "; cin P;
    
    while(N >= 1){
        y++; N--;
        cout << "Лет прошло: " << y << ". Ваши диведенты равны:  " << x/100*P << endl;
        x = x + x/100*P; d = d + x/100*P; 
    }

    cout << " Сумма ваших дивидентов = " << d;
}

void task5(){// Задача 5
    int q,w,e,r,y = 0;
    
        for(int i = 1; i < 10000; i++){
            q = i/1000;
            w = i/100%10;
            e = i/10%10;
            r = i%10;
    
            if (q+w == e+r){
                y++;
            }
        }
    
        cout << y;
}
int main(){
    task1();
    tasl2();
    task3();
    task4();

    return 0;
}