#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int N = 0, M = 5;                                           // Declare sizes of massiv


void sorter_of_bubbles(){
    int sub = 0, k = 0, help = 0;
    for ( int x = 0; x <= N; x++){
        sub = 0;
        
        int f = 0;
        cout << endl;
        for ( int y = 0; y  < M; y++ ) {
            if ( A[x][y] <= A[x][y+1] ) {
                sub = A[x][y];
                A[x][y] = A[x][y+1];
                A[x][y+1] = sub; 
            }

            if ( y == (M-1) ) { 
                f++;
            }
            if ( y == (M-1) && f < M ) { y = -1; }
        }
    }
}

int generator(int range){
    int A[N][M];                                            // Declare kwad massiv
    srand (time(NULL));
    for ( int i = 0; i <= N; i++ ) {
        for ( int ii = 0; ii <= M; ii++ ) {
            A[i][ii] = rand() % range + 1;
        }
    }
    return A;
}

void sorte_of_inserts(){
    int sub = 0, k = 0, help = 0;
    for ( int x = 0; x <= N; x++){
        sub = 0; int f = 0; cout << endl;
        k = 0;
        while ( k < M ) {
            for ( int y = k + 1; y <= M; y++ ) {
                if ( A[x][k] <= A[x][y] ) {
                    sub = A[x][k];
                    A[x][k] = A[x][y];
                    A[x][y] = sub;
                }
            }
            k++; 
        }
    }
}

void printer(){
    for ( int x = 0; x <= N; x++ ) {
        for ( int y = 0; y <= M; y++ ) {
            cout << A[x][y] << " | ";
        }
        cout << endl;
    }
}
int main(){
    /*
    Отсортировать строки массива целых чисел по убыванию.
    */

    int A = generator( 9 );                                     // Generator

    printer();                                                  // Printer

    sorte_of_inserts();                                         // Sort

    printer();                                                  // Printer


    cout << endl;                                               //Check
    cout << A[0][5] << endl;
    cout << A[1][5] << endl;

    return 0;
}