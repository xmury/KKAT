#include <iostream>

using namespace std;

void task_1(){
    cout << "Pass" << endl;
}

void task_2(){
    cout << "Pass" << endl;
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
    
    return 0;
}