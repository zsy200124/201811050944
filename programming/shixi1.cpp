#include <iostream>
using namespace std;
int fun(int a, int b)
{
	int c = (b / 10) + 10 * (a / 10) + 100 * (b % 10) + 1000 * (a % 10);
	return c;
}
int main()
{
	int a;
	int b;
	cout << "����һ����λ��a��"<< endl; 
	cin >> a;
	cout << "����һ����λ��b��"<< endl;
	cin >> b;
	int c = fun(a, b);
	cout << "���Ϊ��" << c << endl;
	return 0;
}