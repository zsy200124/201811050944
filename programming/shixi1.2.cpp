#include <iostream>
using namespace std;
int fun(int &a, int &b)
{
	int  c;
	c = (b / 10) + 10 * (a / 10) + 100 * (b % 10) + 1000 * (a % 10);
	return c;
}
int main()
{
	int x, y;
	cout << "输入一个两位数x：" << endl;
	cin >> x;
	cout << "输入一个两位数y：" << endl;
	cin >> y;
	cout << "结果为：" << fun(x, y) << endl;
	return 0;
}