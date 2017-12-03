#include <iostream>
#include <cstdlib>  
#include <ctime>

using namespace std;

int main(){
    /*
    Дан одномерный массив а. 
    Сформировать новый массив, 
    который состоит только из тех элементов массива а, 
    которые превосходят свой номер на 10. 
    Если таких элементов нет, то выдать сообщение.
    */

    srand (time(NULL));        
    const int N = 10; int a[N];
    for ( int i = 1; i <= N; i++ ){ a[i] = rand() %100 +1; }

    int aa[N], k = 1;
    for ( int i = 1; i <= N; i++ ){ aa[i] = 0; }
    for ( int i = 1; i <= N; i++ ){
        if( (a[i] - i) > 10 ){ aa[k] = a[i]; k++;}    
    }

    for ( int i = 1; i <= k - 1; i++ ){ cout << aa[i] << " | ";}
    
    return 0;
}