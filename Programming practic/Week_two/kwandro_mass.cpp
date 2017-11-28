#include <iostream>
#include <cstdlib>  
#include <ctime>

using namespace std;

void task_1(){
    /*
    Подсчитать сумму элементов двумерного массива, 
    которые стоят на нечетных строках, но на четных столбцах.
    */
    
    srand (time(NULL));  
    const int N = 10, M = 20;
    int a[N][M]; 

    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= M; ii++){
            a[i][ii] = rand() % 10 +1;
        }
    }

    int summ = 0;
    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= M; ii++){
            if ( (i % 2) == 1 && (ii % 2) == 0){ summ += a[i][ii]; }
        }
    }

    cout << summ << endl;
}

void task_2(){
        /*
    Дан массив размерностью NxN. 
    Найти в каждой строке наибольший элемент и поменять 
    его местами с элементом главной диагонали.
    */    
    
    srand (time(NULL)); 
    int N = 5; int a[N][N];
    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= N; ii++){
            a[i][ii] = rand() % 10 +1;
        }
    }
    
    cout << "__Bylo__" << endl; 
    for ( int i = 1; i <= N; i++ ){
            for ( int ii = 1; ii <= N; ii++){
                cout << a[i][ii] << " ";
            }
            cout << endl;
        }
    
    int sub = 0, sub2 = 0, k = 1, kk; int M = N;
    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= M; ii++){
            if ( sub < a[i][ii]){ sub = a[i][ii]; kk = ii;}
            if ( (ii + 1) > M){ 
                sub2 = a[i][k]; 
                a[i][k] = sub;
                a[i][kk] = sub2;
                sub = 0; k++;}

        }
    
      
    }
    
    cout << "__Stalo__" << endl;
    for ( int i = 1; i <= N; i++ ){
            for ( int ii = 1; ii <= N; ii++){
                cout << a[i][ii] << " ";
            }
            cout << endl;
        } 
}

void task_3(){
        /*
    Подсчитать количество столбцов массива, 
    элементы которых упорядочены по убыванию.
    */

    srand (time(NULL)); 
    int N = 3; int a[N][N];
    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= N; ii++){
            a[i][ii] = rand() % 10 +1;
        }
    }

    int k = 0, sub;
    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= N; ii++){
            if ( ii == 1 ){ sub = a[i][ii]; }
            else {
                if ( a[i][ii] > sub ){ break;}
            }

            if ( ii + 1 > N ){ k++; }
            else { sub = a[i][ii]; }  
        }
    }
    cout << k << endl;

    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= N; ii++){
            cout << a[i][ii] << " ";
        }
        cout << endl;
    }
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
    //int a; cout << "Change task: 1, 2, 3, 4; add(5, 6); hard(7): "; cin >> a;
    /*
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
    
    /*
    Даны две матрицы А и В. 
    Вычислить произведение матриц АхВ
    https://msdn.microsoft.com/ru-ru/library/hh873134.aspx
    */

    srand (time(NULL)); 
    int N = 3, M = 2; int a[N][M];
    for ( int i = 1; i <= N; i++ ){
        for ( int ii = 1; ii <= M; ii++){
            a[i][ii] = rand() % 10 +1;
        }
    }

    int N2 = 3, M2 = 2; int b[N2][M2];
    for ( int i = 1; i <= N2; i++ ){
        for ( int ii = 1; ii <= M2; ii++){
            a[i][ii] = rand() % 10 +1;
        }
    }

    

    return 0;
}