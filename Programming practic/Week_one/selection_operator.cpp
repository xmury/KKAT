#include <iostream>

using namespace std;

void task1(){
    /*Составить программу для определения подходящего возраста кандидатуры для вступления в брак, 
    используя следующее соображение: возраст девушки равен половине возраста мужчины плюс 7, 
    возраст мужчины определяется соответственно как удвоенный возраст девушки минус 14.*/

    int human, ages;

    cout << "Input gender (1 - man, 2 - woman) and age: "; cin >> human >> ages;

    switch (human){
        case 1:
            cout << "Optimal ages your spouse: " << ages * 2 - 14 << endl;
            break;

        case 2:
            cout << "Optimal ages your spouse: " << ages / 2 + 7 << endl;
            break;
        default:
            cout << "Your input are wrong (gender)" << endl;
    }
}

void task2(){
    /*В зависимости от введённого символа L, S, V 
    программа должна вычислять длину окружности; площадь круга; объём цилиндра.*/

    int r;
    char inp; 
    const double PI = 3.14;

    cout << "Please, type length circl [L], area round [S], volume of a cylinder [V]: "; 
    cin >> inp;

    switch (inp){
        case 'L':
            cout << "Input r: "; cin >> r;
            cout << "L = " << 2 * r * PI << endl;
            break;

        case 'S':
            cout << "Input r: "; cin >> r;
            cout << "S = " << r * r * PI << endl;
            break;

        case 'V':
            int h; cout << "Input r and h: "; cin >> r >> h;
            cout << "V = " << r * r * PI * h << endl; 
            break;

        default:
            cout << "You input are wrong" << endl;
            break;
    }
}

void task3(){
    /*Дано неотрицательное число К (К<=10000). Написать фразу «К ворон». 
    Пример: при К=23 должно быть напечатано «23 вороны».*/

    /* Однако, тут проще на if-ах*/

    int K; cout << "K = "; cin >> K;
    int q = K % 10;

    if ( K == 1 ){ cout << K << " voron-a" << endl; }
    else {
        switch (q){
            case 0:
                cout << K << " voron" << endl;
                break;
            case 1:
                cout << K << " voron" << endl;
                break;
            
            case 2:
                cout << K << " voron-i" << endl;
                break;

            case 3:
                cout << K << " voron-i" << endl;
                break;

            case 4:
                cout << K << " voron-i" << endl;
                break;
            
            case 5:
                cout << K << " voron" << endl;
                break;
            
            case 6:
                cout << K << " voron" << endl;
                break;
            
            case 7:
                cout << K << " voron" << endl;
                break;
            
            case 8:
                cout << K << " voron" << endl;
                break;
            
            case 9:
                cout << K << " voron" << endl;
                break;
        }
    }
}

void task4(){
    /*Дата некоторого дня определяется тремя натуральными числами: 
    g (год), m (порядковый номер месяца) и n (число). 
    По заданным g, n и m определить дату следующего дня.*/

    int g, n, m, v; cout << "Input: g, m, n --> "; cin >> g >> m >> n;
    if ( m == 2 ){
        cout << "This is year visokosny? (1 - Yes; 2 - No): "; cin >> v;
    }

    int q = 0;

    bool frytin_one = m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12;
    bool frytin = m == 4 || m == 6 || m == 9 || m == 11;

    if ( ( ( frytin_one && n == 31 ) || ( frytin && n == 30 ) ) || ( n == 28 && m == 2 && v == 0) ){ q = 1; }        // Для обычных месяцев
    if (n == 29 && m == 2 && v == 1){ q = 1; }                      // Если это 29 февраля

    switch (q){
        case 1:                                           // Если это конец месяца
            if (m == 12){ m = 1; g++; n = 1;}
            else { m++; n = 1; }
            break;

        case 0:                                            // Если это ДРУГАЯ дата
            n++;
            break;
    }

    cout << "Tomorrow -> " << g << "." << m << "." << n << endl;
}

void add_task_1(){
    /*Придумайте шуточный тест с выдачей шуточных результатов.*/
    int a, b = 0;
    cout << "We begin the test" << endl;

    cout << "Who do you?" << endl;
    cout << "1. Male" << endl;
    cout << "2. Woman" << endl;
    cout << "3. ???" << endl;
    cin >> a;

    switch (a){
        case 1:
            cout << "Not bat" << endl;
            b++;
            break;
        case 2:
            cout << "Not bat" << endl;
            b++;
            break;
        case 3:
            cout << "0_0" << endl;
        
        default:
            cout << "x_x" << endl;
            break;
    }

    cout << "^_'" << endl;
    cout << "1. 0_0" << endl;
    cout << "2. [/'\\]" << endl;
    cout << "3. =_=" << endl;
    cin >> a;

    switch (a){
        case 1:
            cout << "@_@" << endl;
            b++;
            break;
        case 2:
            cout << "(0)_(0)" << endl;
            b++;
            break;
        case 3:
            cout << "|_|" << endl;
        
        default:
            cout << "x_x" << endl;
            break;
    }

    cout << "Do you like me, bro?" << endl;
    cout << "1. Noooo" << endl;
    cout << "2. Yeeee" << endl;
    cout << "3. Whaaat?!" << endl;
    cin >> a;

    switch (a){
        case 1:
            cout << "Ox, nooo" << endl;
            break;
        case 2:
            cout << "Yeeee" << endl;
            b++;
            break;
        case 3:
            cout << "#_#" << endl;
        
        default:
            cout << "x_x" << endl;
            break;
    }
    cout << "You balls: " << b << endl;
}

void add_task_2(){
    /*Мастям игральных карт условно присвоены следующие порядковые номера:
     масти «пики» - 1, масти «трефы» - 2, масти «бубны» - 3, масти «червы» - 4.
      По заданному номеру масти определить название соответствующей масти.*/

    int a; cout << "Carts: input num (1-4): "; cin >> a;
    
    switch(a){
        case 1:
            cout << "Pikiiii" << endl;
            break;
        
        case 2:
            cout << "Trefiiii" << endl;
            break;
        
        case 3:
            cout << "Bubiiii" << endl;
            break;
        
        case 4:
            cout << "Cherviiii" << endl;
            break;
        
        default:
            cout << "Wroooong!" << endl;
    }
}

void hard_task(){
    /*День учителя ежегодно отмечается в первое воскресенье октября.
     Дано натуральное число n, обозначающее номер года. 
     Определить число, на которое приходится День учителя.

    Примечание. «Вечный календарь». 
    Установлено: если исследуемая дата лежит в диапазоне от 1582 до 4902 гг.,
     в этом случае номер дня недели (воскресенье имеет номер 0, 
     понедельник - 1, ..., суббота - 6) 
     равен остатку от деления на 7 значения выражения 
     [2.6m-0.2] + d + y + [y/4] + [c/4] - 2c, 
     где d - номер дня в месяце (1, 2,...); 
     m - номер месяца в году, 
     нумерация начинается с марта (март имеет номер 1, апрель - номер 2,
      ..., декабрь - номер 10, январь и февраль считаются месяцами с 
      номером 11 и 12 предыдущего года); 
      y - две младшие цифры года; 
      c - две старшие цифры года; 
      [x] - означает целую часть числа x.*/
    
    int year; cout << "Input year: "; cin >> year;
    int y = year % 100;
    int d_w = 7;   
    double d;
    double m = 8.0;  double m_n = 2.6 * m - 0.2; 
    int c = year / 100;

    cout << m_n << endl;
    if ( year >= 1582 && 4902 >= year){
        d = (d_w + 2 * c) - (m_n + y + (y / 4.0) + (c / 4.0)); 
    } 

    cout << d << endl;
}
int main(){
    int a; cout << "Change task: 1, 2, 3, 4; add(5, 6); hard(7): "; cin >> a;

    switch(a){
        case 1:
            task1(); break;
        
        case 2:
            task2(); break;
        
        case 3:
            task3(); break;
        
        case 4:
            task4(); break;
        
        case 5:
            add_task_1(); break;
        
        case 6:
            add_task_2(); break;

        case 7:
            hard_task(); break;

        default:
            cout << "Your input are wrong" << endl;
    }
    
    return 0;
}