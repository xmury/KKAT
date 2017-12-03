#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    /*
    Отсортировать строки массива целых чисел по убыванию.
    */

    srand (time(NULL)); 
    int N = 5, M = 10;
    int A[N][M];
    for ( int i = 0; i <= N; i++ ) {
        for ( int ii = 0; i <= M; ii++ ) {
            A[i][ii] = rand() % 10 +1;
        }
    }

    

    // Printer
    for ( int i = 0; i <= N; i++ ) {
        for ( int ii = 0; i <= M; ii++ ) {
            if ( (ii + 1) > N ) {
                cout << A[i][ii] << endl;
            }
            else {
                cout << A[i][ii] << " | ";
            }
        }
    }

    return 0;
}