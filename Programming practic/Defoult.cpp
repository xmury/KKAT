#include <iostream>

using namespace std;

int main(){
    int a; cout << "Change task: 1, 2, 3, 4; add(5, 6); hard(7): "; cin >> a;

    switch(a){
        case 1:
            task1(); break;
        
        default:
            cout << "Your input are wrong" << endl;
    }
    return 0;
}