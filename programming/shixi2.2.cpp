#include <iostream>    
using namespace std;
struct monkey
{
	int num;
	monkey* next;
};
monkey* head, *tail;
void creat(int M)
{
	int i;
	monkey* p, *q;
	p = new monkey;
	p->num = 1;
	p->next = NULL;
	head = p;
	q = p;
	for (i = 2; i <= M; i = i + 1)
	{
		p = new monkey;
		p->num = i;
		q->next = p;
		q = p;
		p->next = NULL;
	}
	tail = q;
	tail->next = head;
}
void fun(int N)
{
	int x = 0;
	monkey* p, *q;
	q = tail;
	do
	{
		p = q->next;
		x = x + 1;
		if (x % N == 0)
		{
			cout << p->num << "  ";
			q->next = p->next;
			delete p;
			p = NULL;
		}
		else
			q = p;
	} while (q != q->next);
	head = q;;
}
int main()
{
	int n, m;
	head = NULL;
	cout << "输入猴子总数m: ";
	cin >> m;
	cout << "输入个数n: ";
	cin >> n;
	creat(m);
	cout << "离开的猴子是: ";
	fun(n);
	cout << " " << endl;
	cout << "第" << head->num << "个猴子是猴子大王" << endl;
	delete head;
	return 0;
}