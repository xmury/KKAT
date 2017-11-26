#include <iostream>
#include <cstdlib>  
#include <ctime>

using namespace std;

void task_1(){
    /*
    Найти сумму всех элементов массива целых чисел, 
    удовлетворяющих условию: остаток от деления на 3 равен 2. 
    Размерность массива – 20.
    */

    srand (time(NULL));    
    
    int a[20];
    for ( int i = 1; i <= 20; i++ ){ a[i] = rand(); }

    int summ = 0;
    for ( int i = 1; i <= 20; i++ ){
        if ( (a[i] % 3) == 2 ){ summ += a[i]; }
    }
    
    cout << summ << endl;
}

void task_2(){
    /*
    Дан линейный массив целых чисел. 
    Проверьте, является ли он упорядоченным по убыванию.
    */
    int N = 3;
    int a[N];
    for ( int i = 1; i <= N; i++ ){ a[i] = rand(); }

    cout << "- My massive otsortirovan po ubivanuy?" << endl;
    for ( int i = 1; i <= N; i++ ){ 
        if( i < N && a[i] < a[i+1] ){
            cout << "- This is false..." << endl;
            break;
        }
        if ( (i + 1) > N ){ cout << "- This is true" << endl; }
    }
}

void task_3(){
    cout << "Pass" << endl;
}

void task_4(){
    cout << "Pass" << endl;
}

void add_task_1(){
    cout << "Pass" << endl;
}

void add_task_2(){
    cout << "Pass" << endl;
}

void hard_task(){
    cout << "Pass" << endl;
}
int main(){
    /*
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
    */
    

    return 0;
}