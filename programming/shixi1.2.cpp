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
	cout << "����һ����λ��x��" << endl;
	cin >> x;
	cout << "����һ����λ��y��" << endl;
	cin >> y;
	cout << "���Ϊ��" << fun(x, y) << endl;
	return 0;
}