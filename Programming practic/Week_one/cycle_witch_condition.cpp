#include <iostream>

using namespace std;

void task_1(){
    /*Мистер Пипкин и Мистер Липкин одновременно внесли в свои
     банки одинаковые вклады по V долларов. Банк мистера Пипкина 
     начисляет своим клиентам 10% годовых, а банк мистера Липкина – 7%.
      Во сколько раз больше денег окажется через 10 лет на счете у
       мистера Пипкина, чем у мистера Липкина?*/

    int years = 10;
    float present_1 = 0.1, present_2 = 0.07;

    int V; cout << "How many you puts on depozite? : "; cin >> V;
    double divid_1 = V, divid_2 = V;

    int i = 0;
    while( i < years ){
        i++;
        divid_1 += divid_1 * present_1;
        divid_2 += divid_2 * present_2;
    }
    cout << divid_1 << endl;
    cout << divid_2 << endl;

    cout << "Dividents Ms. Pipkin > Dividents Ms. Lipkin in: " << divid_1 / divid_2 << endl;  
}

void task_2(){
    /*В водоеме 100 т рыбы. Каждый год рыболовецкая бригада вылавливает 15 т.
     Воспроизводство рыбы 5 % в год.
      Для сохранения воспроизводства необходимо прекращать лов, 
      когда в водоеме ее остается менее 5 т.
       Через сколько лет лов рыбы должен быть прекращен?*/

    double fish = 100;
    int fishers = 15, preset = 0.05;

    int i = 0;
    while(fish > 5){
        fish += fish * preset;
        fish -= fishers;
        i++;
    }

    i++;
    cout << i << " years ago" << endl;
}

void task_3(){
    /*Малыш и Карлсон живут в прямоугольной комнате. 
    Как им подсчитать, сколько понадобится квадратных 
    ковриков со стороной 1х1 метр, чтобы полностью покрыть 
    пол комнаты (ни Малыш, ни Карлсон не умеют ни делить, ни умножать).*/

    int a, b, S = 0; cout << "Input S (width and length: "; cin >> a >> b;

    int i = 0;
    while(b > 0){
        S += a; b--;
    }

    cout << "Them need " << S << " kovrocov" << endl;
}

void task_4(){
    /*Царевна-лягушка съедает ежедневно на К% комаров больше,
     чем в предыдущий день, и еще два комара. 
     Составить алгоритм, определяющий, через сколько дней 
     количество съеденных комаров превысит М, если в первый
      день было съедено Х комаров.*/

    double K;
    
    int M, X; cout << "Input M, X and K: "; cin >> M >> X >> K;
    K *= 0.01;

    int d = 0;
    while(X <= M){
        d++; X += X * K + 2; 
    }
    cout << d << " day ago..." << endl;
}

void add_task_1(){
    /*Натуральное число из n цифр является числом Армстронга, 
    т.е. сумма его цифр, возведенная в n степень, 
    равна самому числу (153=1*1*1+5*5*5+3*3*3). 
    Получите все числа Армстронга для n=3 и n=4.*/
    int num, max, Amst;
    int n; cout << "Input n (3 or 4): "; cin >> n;

    bool f = false;
    if(n == 3){ num = 100;  max = 1000;  f = true;}
    if(n == 4){ num = 1000; max = 10000;          }

    if(n < 3 || n > 4){ cout << "You input are wrong" << endl; }

    int a,b,c,d;
    while(num < max){ 
        if(f){
            a = num / 100;
            b = num / 10 % 10;
            c = num % 10;

            Amst = (a * a * a) + (b * b * b) + (c * c * c);
        }
        else{
            a = num / 1000;
            b = num / 100 % 10;
            c = num % 100 / 10;
            d = num % 10;

            Amst = (a * a * a * a) + (b * b * b * b) + (c * c * c * c) + (d * d * d * d);
        }

        if (num == Amst){ cout << num << endl; }
        num++;
    }
}

void add_task_2(){
    /*Дано натуральное число А. 
    Как наименьшим количеством монет можно выплатить А рублей. 
    Предполагается, что в достаточном количестве имеются монеты 
    достоинством в 1, 3, 5, 10, 15, 20 и 50 рублей.*/

    double A; cout << "Input cash: "; cin >> A;
    int one = 50, summ = 0;    
    while (A > 0){
        switch (one){
            case 50:
                summ += A / one;
                cout << " 50-th money: " << A / one << " tg" << endl;
                A -= one * (A / 50); one = 20; 
                break;

            case 20:
                summ += A / one;
                cout << one << "-th money: " << A / one << " tg" << endl;
                A -= one * (A / one); one = 15; 
                break;

            case 15:
                summ += A / one;
                cout << one << "-th money: " << A / one << " tg" << endl;
                A -= one * (A / one); one = 10; 
                break;

            case 10:
                summ += A / one;
                cout << one << "-th money: " << A / one << " tg" << endl;
                A -= one * (A / one); one = 5; 
                break;

            case 5:
                summ += A / one;
                cout << one << "-th money: " << A / one << " tg" << endl;
                A -= one * (A / one); one = 3; 
                break;

            case 3:
                summ += A / one;
                cout << one << "-th money: " << A / one << " tg" << endl;
                A -= one * (A / one); one = 1; 
                break;
            
            case 1:
                summ += A / one;
                cout << one << "-th money: " << A / one << " tg" << endl;
                A -= one * (A / one); one = 1; 
                break;
        }
    }
    cout << "All " << summ << " money" << endl;
}

void hard_task(){
    /*Незнайка считает, что операция «увеличить» число 
    означает увеличить каждую его цифру, 
    а может быть еще при этом приписать одну ненулевую цифру слева. 
                    У Незнайки сегодня четверг (он по четвергам занимается математикой) и 
    он хочет увеличить все увиденные им числа в 4 раза, 
    используя свой способ «увеличения». Помогите Незнайке.*/
    int sub = 10;
    int num; cout << "Input num: "; cin >> num;

    int i = 0;                          // Определение длины числа
    while(true){
        if( num % sub == num ){ i++; break; }
        else{ i++; sub *= 10; }
    }

    i++; int ms[i], l = 1; sub = num;    // Разбиение числа на цифры
    while(i >= l){
        ms[l] = sub % 10;
        sub /= 10;
        l++;    
    }

    l = 1; int add = 0; bool f = true;  // Умножение
    while (i >= l){
        if ( ms[l] >= 5 ) { cout << "nevojmojno" << endl; f = false; break; }
        else { 
            if ( ms[l] * 4 > 9 && l == i ){ 
                ms[l] = (ms[l] *= 4) % 10 + add;
                l++;
                ms[l] = 1;
                break; 
             }

            if ( ms[l] * 4 > 9 && l != i ){
                ms[l] = (ms[l] *= 4) % 10 + add;
                l++;
                add = 1;
                continue;
            }
            
            ms[l] = (ms[l] * 4) + add; 
            l++; 
        }
    }
    
    if(f){
        l = i;                              // Цикл вывода информации
        while (l >= 1){             
            if(l == i && ms[l] == 0){ l--; continue; }
            cout << ms[l];
            l--;
        }
    }
    cout << endl;
}

int main(){
    int a; cout << "Change task: 1, 2, 3, 4; add(5, 6); hard(7): "; cin >> a;

    switch(a){
        case 1:
            task_1(); break;
        
        case 2:
            task_2(); break;

        case 3:
            task_3(); break;

        case 4:
            task_4(); break;

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