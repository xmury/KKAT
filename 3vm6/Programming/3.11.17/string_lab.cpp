#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

void t1(){
	string stroka; int i,k=0;
	cout<<" Введите строку >>";
	cin>>stroka;
	for (i=0;i<stroka.length();i++)
		{ 
			if ((stroka[i]=='c' || stroka[i] == 'С' || stroka[i] == 'с' || stroka[i] == 'С')) k++; 
		}
	
	cout << " Number letters 'c' = " << k;
	
}

int main()
{
	setlocale(LC_ALL,"Rus");
	int in; cin >> in;

	switch(in){
		case 1: t1(); break;

		default: cout << "Error" << endl;
	}

	return 0;
}