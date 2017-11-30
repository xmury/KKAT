#include <iostream>
#include <math.h>

using namespace std;

void task1(){
    /*Определить, верно ли, что при делении неотрицательного целого числа
     а на положительное число b, получается остаток, 
     равный одному из двух заданных чисел х и у.*/

    int x, y, a, b;

    cin >> a >> b >> x >> y;
    double ost = a % b;
    if (ost == x || ost == y){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}

void task2(){
    /*Даны положительные числа a, b, c, d. 
    Выяснить, можно ли прямоугольник со сторонами a, b 
    уместить внутри прямоугольника со сторонами c, d, 
    так, чтобы каждая из сторон одного прямоугольника была 
    параллельна или перпендикулярна каждой стороне второго 
    прямоугольника. Ответ получить в текстовой форме: можно или нельзя.*/

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a <= c && b <= d){
        cout << "Mojno" << endl;
    }
    else{
        cout << "Nelza" << endl;
    }
}

void task3(){
    /* Составить программу, выбирающую из трех чисел то, 
    которое лежит между двумя другими.*/   

    int a, b, c;
    cin >> a >> b >> c;

    if ( (a > b && a < c) || (a < b && a > c) ){       // Если а находится в центре
        cout << "This is " << a << endl;            
    }
    else{
        if ( (b >= a && b < c) || (b < a && b >= c)){  // Если b находится в центре
            cout << "This is " << b << endl;
        }
        else{                                          // Если c находится в центре
            cout << "This is " << c << endl;
        } 
    }
}

void task4(){
    /*Написать программу вычисления стоимости разговора 
    по телефону с учетом скидки 20%, предоставляемой по 
    субботам и воскресеньям.*/

    int week_day; 
    double skid = 0.2;     // скидка
    int tarif = 1;      // тариф 1 тг = 1 с разговора
    int call_time;
    
    cout << "How time you talk? - "; cin >> call_time;
    cout << "What day is it today? (1,2,3,4,5,6,7) - "; cin >> week_day;

    if (week_day == 6 || week_day == 7){
        cout << "Your price: " << call_time * (tarif - tarif * skid);
    }
    else{
        cout << "Your price: " << call_time * tarif;
    }
}

void add_task1(){
    /*Известны год, номер месяца и день рождения каждого из двух человек. 
    Определить, кто из них старше.*/
    int year_1, year_2;
    int mounth_1, mounth_2;
    int day_1, day_2;
    cout << "Year, mounth and day birthday first human: "; 
    cin >> year_1 >> mounth_1 >> day_1;
    cout << "Year, mounth and day birthday second human: "; 
    cin >> year_2 >> mounth_2 >> day_2;

    if (year_1 < year_2){                       // Проверяем Год рождения
        cout << "First over" << endl;
    }
    
    if (year_1 > year_2){                       // Проверяем Год рождения
        cout << "Second over" << endl;
    }
    
    if (year_1 == year_2){                      // Проверяем Год рождения
        
        if (mounth_1 < mounth_2){               // Проверяем Месяц рождения
            cout << "First over" << endl;
        }
        
        if (mounth_1 > mounth_2){               // Проверяем Месяц рождения
            cout << "Second over" << endl;
        }
        
        if (mounth_1 == mounth_2){              // Проверяем Месяц рождения
            
            if (day_1 < day_2){                 // Проверяем День рождения                 
                cout << "First over" << endl;
            }
            
            if (day_1 > day_2){                 // Проверяем День рождения
                cout << "Second over" << endl;
            }
            
            if (day_1 == day_2){                // Проверяем День рождения
                cout << "They're equal" << endl;
            }
        }
    }
    
}

void add_task2(){
    /*На затонувшем корабле обнаружены сундуки с сокровищами. 
    Сундуки можно извлечь только через иллюминатор. 
    Составить программу определения, можно ли это сделать,
    если известны r — радиус иллюминатора, 
    a, b, c — линейные размеры прямоугольных сундуков.*/

    int r, a, b, c;
    cout << "Input raduis and size(AxBxC): "; cin >> r >> a >> b >> c;

    int D = r * 2;
    double diagonal_1 = sqrt( a * a + b * b);
    double diagonal_2 = sqrt( b * b + c * c);

    if (diagonal_1 <= D || diagonal_2 <= D){
        cout << "Mojno" << endl;
    }
    else{
        cout << "Nelza" << endl;
    }
}

void hard_task(){
    /*В небоскрёбе N этажей и всего один подъезд; 
    на каждом этаже по 3 квартиры; 
    лифт может останавливаться только на нечётных этажах. 
    Человек садится в лифт и набирает номер нужной ему квартиры M . 
    На какой этаж должен доставить лифт пассажира?*/

    int N, M;
    int num_apart = 3;
    cout << "Input number of floors and apartment number:";
    cin >> N >> M;

    bool f = true;
    if (M <= 6 && M > 0){
        f = false;
        cout << "You need't Elevator" << endl;
    }
    if (f){
        if ( ( M > N * num_apart ) || (M < 0) ){
            cout << "Your appartment does not exist" << endl;
        }

        else{
            int flour = M / num_apart; // этаж

            if ( flour % 2 == 0 ){
                cout << "You need " << flour - 1 << " flour " << endl;
            }
        
            else{
                cout << "Your need " << flour << " flour " << endl;
            }
        }
    }
}
        
    
int main(){
    int a; cout << "Change task: simpl(1,2,3,4); add(5,6); hard(7)" << endl; 
    cin >> a;

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
            add_task1(); break;
        
        case 6:
            add_task2(); break;

        case 7:
            hard_task(); break;

        default:
            cout << "Your input are wrong" << endl;
    }

    return 0;
}