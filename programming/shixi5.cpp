#include <iostream>
#include "MyStack.cpp"
#include "Calculator.h"
using namespace std;
int main()
{
	Calculator calc1;//��������������
	do
	{
		calc1.clear();
		cout << "Please input an expression, ended with a '#'" << endl;
		calc1.evaluate();//������ʽ����ʾ���
		cout << endl << "Would you like to continue? [y/n]" << endl;
		fflush(stdin);
	} while (cin.get() == 'y');

	return 0;
}