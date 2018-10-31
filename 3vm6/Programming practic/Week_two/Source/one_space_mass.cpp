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
    int N = 20;
    int a[N];
    for ( int i = 1; i <= N; i++ ){ a[i] = rand(); }

    int summ = 0;
    for ( int i = 1; i <= N; i++ ){
        if ( (a[i] % 3) == 2 ){ summ += a[i]; }
    }
    
    cout << summ << endl;
}

void task_2(){
    /*
    Дан линейный массив целых чисел. 
    Проверьте, является ли он упорядоченным по убыванию.
    */
    
    srand (time(NULL));
    int N = 3;; int a[N];
    for ( int i = 1; i <= N; i++ ){ a[i] = rand(); }

    cout << "- My massive otsortirovan po ubivanuy?" << endl;
    for ( int i = 1; i <= N; i++ ){ 
        if( i <= N && a[i] < a[i+1] ){
            cout << "- This is false..." << endl;
            break;
        }
        if ( (i + 1) > N ){ cout << "- This is true" << endl; }
    }
}

void task_3(){
        /*
    Задан массив D. Определить следующие суммы: 
    D[l] + D[2] + D[3]; D[3] + D[4] + D[5]; D[4] + D[5] + D[6]. 
    Пояснение. Составить подпрограмму для вычисления суммы трех 
    последовательно расположенных элементов массива с номерами от k до т.
    */
    
    srand (time(NULL));
    int k,t; cout << "Input k and t: "; cin >> k >> t;

    int N = 10; int D[N];
    for ( int i = 1; i <= N; i++ ){ D[i] = rand() %10 + 1; }

    for ( int i = k; i <= t; i++ ){
        if( (i + 2) > t || (i + 1) >= t){ break; }
        cout << ( D[i] + D[i+1] + D[i+2] ) << endl; 
    }

    cout << "---------------" << endl;
    for ( int i = 1; i <= N; i++ ){ cout << i << " | " << D[i] << endl; }
}

void task_4(){
    /*
    Одномерный массив 12 элементов заполнить 
    случайными положительными и отрицательными значениями.
    Переставить местами первый положительный элемент с последним отрицательным. 
    */

    srand (time(NULL));
    int N = 12; int D[N];
    for ( int i = 1; i <= N; i++ ){ D[i] = rand() %1000 - 500; }
    
    int sub1, sub2;
    for ( int i = 1; i <=N; i++ ){
        if ( D[i] >= 0){
            sub1 = D[i]; 
            
            for ( int ii = N; ii >= 1; i--){
                if ( D[ii] < 0){
                    sub2 = D[ii];
                    D[ii] = sub1;
                    break;
                }
            }

            D[i] = sub2; 
            break;
        }
    }

}

void add_task_1(){
        /*
    Задана таблица названий товаров, выпускаемых заводом. 
    Определите, повторяется ли в этой таблице название первого товара, 
    и, если повторяется, удалите название первого товара из таблицы.
    */

    srand (time(NULL));
    int N = 10; int D[N];
    for ( int i = 1; i <= N; i++ ){ D[i] = rand()%1000 + 1000; }    

    int sub = D[1];
    for ( int i = 2; i <= N; i++ ){ 
        if ( sub == D[i] ){
            for (int ii = 1; ii <= (N - 1); ii++ ){
                if (ii == N){
                    D[ii] = 0;
                }
                else{
                    D[ii] = D[ii + 1];
                }
                }
            } 
            break;
        }
}

void add_task_2(){
    /*
    Дан массив чисел. Найти, сколько в нем пар одинаковых соседних элементов.
    */
    srand (time(NULL));
    int N = 10; int D[N];
    for ( int i = 1; i <= N; i++ ){ D[i] = rand(); }    

    int num = 0;
    for ( int i = 1; i <= N; i++ ){
        if ( D[i] == D[i + 1] ){
            num++;
        }
    }

    cout << num << endl;;
}

int stalker(int N[20], int len, int b){
    for ( int i = 1; i <= len; i++ ){
        if ( N[i] == b){ return 0; }
    }
    return 1;
}

void hard_task(){
        /*
    Даны одномерные массивы А(состоит из 20 элементов) и В(из 10).
    Сформировать массивы, состоящие из элементов:
    1) равных и в А, и в В
    2) А, которых нет в В
    3) В, которых нет в А
    */

    srand (time(NULL));
    int D = 20, N = 10; int A[D], B[N];
    for ( int i = 1; i <= D; i++ ){ A[i] = rand()%10 +1; }
    for ( int i = 1; i <= N; i++ ){ B[i] = rand()%10 +1; }

    // ==
    int NA[D], k = 1;
    for ( int i = 1; i <= D; i++ ){ NA[i] = 0; }
    for ( int i = 1; i <= D; i++ ){
        for ( int ii = 1; ii <= N; ii++ ){
            if ( (A[i] == B[ii]) && stalker(NA, 20, A[i]) == 1 ){ NA[k] = A[i]; k++; break;}
        }
    }
    //==

    // Есть в А но нет в B
    int NoB[D], kk = 1;
    for ( int i = 1; i <= D; i++ ){ NoB[i] = 0; }
    for ( int i = 1; i <= D; i++ ){
        if ( stalker(NA, D, A[i]) == 1 ){ NoB[kk] = A[i]; kk++; }
    }
    // Есть в А но нет в B

    int NoA[D], kkk = 1;
    for ( int i = 1; i <= D; i++ ){ NoA[i] = 0; }
    for ( int i = 1; i <= D; i++ ){
        if ( stalker(NA, D, B[i]) == 1 ){ NoA[kkk] = A[i]; kkk++; }
        
    }
    cout << "In A and B: " << endl;
    for ( int i = 1; i <= (k - 1); i++ ){ cout << i << " | " << NA[i] << endl; }
    cout << "In A, but not in B: " << endl;
    for ( int i = 1; i <= (kk -1); i++ ){ cout << i << " | " << NoB[i] << endl; }
    cout << "IN B, but not in A: " << endl;
    for ( int i = 1; i <= (kkk -1); i++ ){ cout << i << " | " << NoA[i] << endl; }
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
    task_3();
    return 0;
}
