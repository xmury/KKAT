#include <iostream>

using namespace std;

void task1(){
    /*На двух кустах сидело 16 птиц 
    со второго куста улетело две птицы, 
    а затем с первого куста на второй перелетели 5 птиц 
    после этого на каждом кусте оказалось одно и тоже число птиц. 
    
    Вопрос, сколько птиц было в начале на каждом кусте?*/

    int x = (16 + 8)/2;
    int y = 16 - x;

    cout << x << " " << y << endl;
}




int main(){
    int a;
    cout << "Change task: 1"; cin >> a;
    while(true){
        switch (a){
            case 1:
                task1();
                break;
            default:
                cout << "Your input have wrong or you input 'n'" << endl;
                break;
        }
    }
    return 0;
}