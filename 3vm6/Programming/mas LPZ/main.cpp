#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
void task1(){
    cout << "Lacomka" << endl;

}
void task2(){
    cout << "Temperatura" << endl;
    int temp_stat[365];
    for(int i = 1; i < 366; i++){
        // от -90 до +70; 70 - 90 + 1 + 70
        temp_stat[i] = rand()%161 - 90;
       cout << i << endl;
    }
}
void task3(){
    cout << "task3" << endl;
    cout << rand() << endl;
}
int main(){
    srand(time(NULL));
    int input; cout << "Please, input number task (1-3): "; cin >> input;
    switch(input){
        case 1: { task1(); break;}
        case 2: { task2(); break;}
        case 3: { task3(); break;}
    }

    return 0;
}