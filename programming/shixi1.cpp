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
	cout << "输入一个两位数a："<< endl; 
	cin >> a;
	cout << "输入一个两位数b："<< endl;
	cin >> b;
	int c = fun(a, b);
	cout << "结果为：" << c << endl;
	return 0;
}