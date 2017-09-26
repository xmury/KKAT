#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	int N, n;
	int summ = 0, colvo = 0; 
	while (N >= chag){
		chag++;

		cin >> n;
		if (n%5 == 0){
			colvo++; summ = summ + n; 
		} 
	}
	cout << "Количество: " << colvo << endl;
	cout << "Сумма: " << summ << endl;

	return 0;
}