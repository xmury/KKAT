#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void string_runnner_puzirjek(){
    /*
    // String runer
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
    */
}
int main(){
    /*
    Отсортировать строки массива целых чисел по убыванию.
    */

    // Generator
    srand (time(NULL)); 
    int N = 0, M = 5;
    int A[N][M];
    for ( int i = 0; i <= N; i++ ) {
        for ( int ii = 0; ii <= M; ii++ ) {
            A[i][ii] = rand() % 8 +1;
        }
    }
    
    cout << endl;
    // String runer
    int sub = 0, k = 0, help = 0;
    for ( int x = 0; x <= N; x++){
        sub = 0; int f = 0; cout << endl;
        k = 0;
        while ( k < M ) {
            cout << endl; // Printer
            for ( int xx = 0; xx <= N; xx++ ) {
                for ( int yy = 0; yy <= M; yy++ ) {
                    cout << A[xx][yy] << " | ";
                }
                cout << endl;
            }

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
    
    cout << "----------------------------" << endl;
    // Printer
    for ( int x = 0; x <= N; x++ ) {
        for ( int y = 0; y <= M; y++ ) {
            cout << A[x][y] << " | ";
        }
        cout << endl;
    }

    cout << endl;
    cout << A[0][5] << endl;
    cout << A[1][5] << endl;

    return 0;
}