#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int N = 2, M = 2;


void printer(int* arrey[]){
    cout << *arrey << endl;
}

int main(){

    int A[N][M];
    
    int c; srand (time(NULL));
    for ( int i = 0; i <= N; i++ ) {
        for ( int ii = 0; ii <= M; ii++ ) {
            c = rand() % 9 + 1;
            A[i][ii] = c;
            cout << i << "][" <<  ii << " | " << A[i][ii] << endl;
        }
        cout << endl;
    }

    cout << "---------------------" << endl;

    for ( int i = 0; i <= N; i++ ) {
        for ( int ii = 0; ii <= M; ii++ ) {
            cout << i << "][" <<  ii << " | " << A[i][ii] << endl;
        }
        cout << endl;
    }

    cout << "A           = " << A           << endl;
    cout << "&A          = " << &A          << endl;
    cout << "&A[0][0]    = " << &A[0][0]    << endl;
    cout << "&A[N][M]    = " << &A[N][M]    << endl;
    
    int *a = &A[0][0];
    
    cout << "*a         = " << *a      << endl;
    cout << "*(a+1)     = " << *(a+1)  << endl;
    cout << "a(a+3)     = " << *(a+5)  << endl;
    cout << "&a[0]      = " << &a[0]   << endl;

    cout << endl;
    for ( int x = 0; x <= (M + N + 2); x++ ) {
        cout << *(a + x) << " |(" << x << ")| ";
        if ( ((x + 1) % (M + 1)) == 0 && x != 0) { cout << endl; }
        
    }
    return 0;
}