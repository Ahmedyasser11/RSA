#include<iostream>
#include"biginteger.h"
#include<string>
using namespace std;
void main()
{

	biginteger k;
	char op;
	string s1, s2,result;
	
	cout << "cin::num1 operation number2" << endl;
	cin >> s1 >> op >> s2;
	////cin as num1 space operation number2;
	

		switch (op)
		{
		case '+':
			result = k.addition(s1, s2);
			break;
		case '-':
			result = k.subtrication(s1, s2);
			break;
		case '*':
			result = k.multpication(s1, s2);
			break;
		default:
			break;
		}
		cout << result;
		system("pause");
}