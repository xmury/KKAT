#include <iostream>

using namespace std;

int a_in_six(){
    int a = 5, step = 0;

    cout << "������� �: "; cin >> a; cout << endl;
    cout << "������� �������: "; cin >> step; cout << endl;
    cout << "� � " << step << " ������� = " << endl;
    return a;
}

int metall_list(){
    double a,b,h;
    cout << "������� �������: " << endl;
    cin >> a >> b >> h;
    double list_chir = 1.25, list_vis = 2.5;
    double s_list, pol, b_short, b_long;
    s_list = list_chir * list_vis;
    int lists;
    pol = (a*b)/s_list;
    b_short = (b*h)/s_list;
    b_long = (a*h)/s_list;
    lists =  pol + b_short*2 + b_long*2;
    cout << " ��� �����������: " << lists << endl;
    cout << s_list << endl;
    // cout << a << "|" << b << "|" << h << endl;
}

int work_time(){
    int time, hours_work, minutes_work;
    int h1, h2, min1, min2;

    cout << "�� ������ �������� � (�� ��):"; cin >> h1 >> min1; cout << endl;
    cout << "�� ��������� �������� � (�� ��):"; cin >> h2 >> min2; cout << endl;

    time = (h2 * 60 + min2) - (h1 * 60 + min1);
    hours_work = time / 60;
    minutes_work = time % 60;

    cout << "�� ��������: " << hours_work << " : " << minutes_work << endl;
    }

int garden(){
    int height, weight, vasya;
    int P, colvo_vasy;

    cout << "������� ����� � ������ ������ ������� � ������:" << endl;
    cin >> height >> weight;
    cout << "������� ������ �����: " << endl;
    cin >> vasya;
    cout << height;
    P = (height*2 + weight*2)*100;
    cout << P;
    colvo_vasy = P/vasya;

    if (P%vasya > 0){colvo_vasy += 1;}

    cout << "��� ����������� ��������� ����� �����:" << colvo_vasy << endl;
}

int shop(){
    const int PRICE = 8, WIDTH = 80;
    int height;
    double full_price, S;

    cout << "������� ����� ������ �����: "; cin >> height;

    S = height * WIDTH;
    full_price = S*PRICE;

    cout << "��������� ����� �����: " << full_price << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    while (true){
        int n;
        cout << " 1: � � 6-��" << endl;
        cout << " 2: ������������ �����" << endl;
        cout << " 3: ����� ������" << endl;
        cout << " 4: ��������� �����" << endl;

        cout << " 0: ����� �� ���������" << endl;
        cin >> n;

        if (n == 1){a_in_six();}
        if (n == 2){metall_list();}
        if (n == 3){work_time();}
        if (n == 4){garden();}

        if (n == 0){ break;}

        if (n != 1 &&
            n != 2 &&
            n != 3 &&
            n != 4 &&
            n != 'e')
        {
            continue;
        }
    }
    return 0;
}
