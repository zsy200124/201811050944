#include<iostream>
using namespace std;
int fun(int N, int M)
{
	int i;
	int monkey[100];
	for (i = 0; i < N; i++)
		monkey[i] = 1;     //����״̬��ʼ����Ϊ1��ʾ���ܱ�ѡ�ϣ�
	int sum = 0,     //ѭ��������
		count = N;   //�ۻ�������ʼ��������1�������д�����ѡ�ˣ�
	while (count > 1)
	{
		count = 0;
		for (i = 0; i < N; i++)
		{
			sum += monkey[i];
			if (sum == M)
				sum = monkey[i] = 0;  //��̭���ӣ�
			count += monkey[i];
		}
	}
	for (i = 0; i < N; i++)
		if (monkey[i] != 0)
			return i;   //�ҵ����Ӵ�����ţ���0��ʼ�ģ���
}
void main()
{
	int m, n;
	cout << "�����������m: ";
	cin >> m;
	cout << "�������n: ";
	cin >> n;
	cout << "��" << fun(m, n) + 1 << "�������Ǻ��Ӵ���" << endl;
}