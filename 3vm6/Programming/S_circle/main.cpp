#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double Pi = double(M_PI);
    int d; double S;

    cout << "������� ������� ����������: "; cin >> d; cout << endl;
    S = Pi * d;

    cout << "S ������ ���������� = " << S << endl;
    return 0;
}
