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

    int g, n, m; cout << "Input: g, m, n --> "; cin >> g >> m >> n;
    int q = 0;

    bool frytin_one = n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12;
    bool frytin = n == 4 || n == 6 || n == 9 || n == 11;

    if ( frytin_one ){ q = 31; }
    if ( frytin ){ q = 30; }
    if (n == 28){ q = n; }

    switch (q){
        case 31:
            if (m == 12){ m = 1; g++; }
            else{ m++; }
            break;

        case 30:
            break;

        case 28:
            break;

        case 0:
            break;
    }
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

        default:
            cout << "Your input are wrong" << endl;
    }
    return 0;
}