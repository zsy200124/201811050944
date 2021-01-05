#include<iostream>
#include <algorithm>
using namespace std;
struct student
{
	int ch, math, eng, sum, num;
}stu[10];
bool cmp(student stu1, student stu2)  //排序依据 
{
	if (stu1.sum != stu2.sum)
		return stu1.sum > stu2.sum;  //总成绩高则排在前
	else if (stu1.ch != stu2.ch)
		return stu1.ch > stu2.ch;  //语文成绩高则排在前
	else return stu1.num < stu2.num;
}
int main() {
	int i, n;
	bool first = true; //每个案例中间隔一个空行 
	while (cin >> n)
	{
		for (i = 0; i < n; i++) {
			stu[i].num = i + 1;
			cin >> stu[i].ch >> stu[i].math >> stu[i].eng;
			stu[i].sum = stu[i].ch + stu[i].math + stu[i].eng;
		}
		if (first) first = false;
		else cout << endl;
		sort(stu, stu + n, cmp);   //数组中从第一个到最后一个以定义的cmp函数要求排序 
		for (i = 0; i < 5; i++)
			cout << stu[i].num << " " << stu[i].sum << endl;
	}
	return 0;
}