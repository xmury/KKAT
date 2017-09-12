#include <iostream>

using namespace std;

int a_in_six(){
    int a = 5, step = 0;

    cout << "¬ведите а: "; cin >> a; cout << endl;
    cout << "¬ведите степень: "; cin >> step; cout << endl;
    cout << "а в " << step << " степени = " << endl;
    return a;
}

int metall_list(){
    double a,b,h;
    cout << "¬ведите размеры: " << endl;
    cin >> a >> b >> h;
    double list_chir = 1.25, list_vis = 2.5;
    double s_list, pol, b_short, b_long;
    s_list = list_chir * list_vis;
    int lists;
    pol = (a*b)/s_list;
    b_short = (b*h)/s_list;
    b_long = (a*h)/s_list;
    lists =  pol + b_short*2 + b_long*2;
    cout << " ¬ам потребуетс€: " << lists << endl;
    cout << s_list << endl;
    // cout << a << "|" << b << "|" << h << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    while (true){
        int n;
        cout << " 1: а в 6-ой" << endl;
        cout << " 2: ћеталические листы" << endl;
        cout << " 3: –езерв" << endl;

        cin >> n;

        if(n == 1){
            a_in_six(); break;
        }
        if (n == 2){
            metall_list(); break;
        }
        if (n != 1 && n != 2 && n != 3){
            continue;
        }
    }
    return 0;
}
