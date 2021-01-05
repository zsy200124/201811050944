#include <iostream>
#include "MyStack.cpp"
#include "Calculator.h"
#include <ctype.h>//������isdigit��isalpha����
using namespace std;
void Calculator::evaluate()//����ջ�ṹ�������������׺���ʽתΪRPN���㣬������������ȷ��
{
	char ch, op, theta;//��ǰ�����ַ����������������
	double val, a, b;//��ֵ������������Ҳ�����
	cin >> ch;
	op = '=';
	bool is_matched = true;//������������Ƿ�ƥ��
	do
	{
		while (isalpha(ch)) { cin >> ch; }//���˷Ƿ��ַ����루Ӣ����ĸ��
		is_matched = true;

		switch (ch)//��������ƥ����
		{
		case '(': bracket.push(ch); break;//��������ջ
		case ')': if (bracket.empty())
			//������û������ջ����������ƥ��ʱ������Ƿ�
			is_matched = false;
				  else
		{
			bracket.pop();  is_matched = true;
		}//ƥ��ʱ������һ��������
				  break;
		default: break;//�����ŵ��ַ�һ�ɹ��˵�
		}
		while (is_matched)//������ƥ��ʱ��ִ����׺���ʽ����
		{
			if (isdigit(ch))//��ǰ�ַ�Ϊ����ʱ���������������ջ
			{//isdigit������λ�����Զ�ʶ����
				cin.putback(ch);//�𣺵�Ȼ���ܡ���Ϊisdigt�Ĳ�����char�͵ģ���ֻ���ж�һλ�ַ�
				cin >> val;//��Ҳ��ΪʲôҪcin.putback(ch)��cin>>out�ˡ�cin�Ĺ��ܺ�ǿ���Զ�ƥ���������ͣ�������scanf�ĸ��ָ�ʽ�������
				opnd.push(val);
				cin >> ch; break;
			}
			else if (lp(op) < rp(ch))
			{//��ǰ���������ȼ�����ջ��������ʱ����ջ
				optr.push(ch);
				op = optr.top();
				cin >> ch; break;
			}
			else if (lp(op) == rp(ch))
			{//��ǰ���������ȼ�����ջ��������ʱ����ǰջ����������ջ
				optr.pop();
				op = optr.top();
				cin >> ch; break;
			}
			else if (lp(op) > rp(ch))
			{//��ǰ���������ȼ�����ջ������ջ��ȡ���������㣬�ٽ�����Żز�����ջ
				theta = op;  optr.pop();
				b = opnd.top();  opnd.pop();
				a = opnd.top();  opnd.pop();//ע�������������ĳ�ջ˳��
				opnd.push(operate(theta, a, b));
				op = optr.top();
				if ((ch == ')') && (op == '('))//�����������ƥ��������
				{
					optr.pop();  op = optr.top();//�����ų�ջ
					cin >> ch;//ˢ�µ�ǰ�ַ�������������Ŷ����жϣ�
					if (ch == '(') is_matched = false;//�����Ž��������ţ�����
				}
				break;
			}
		}
		if (is_matched == false || (op == '(' && ch == '#'))
		{//���ʣû���϶Ե������ţ�����������û����������ƥ�䣬������Ƿ�
			cout << "Bad match." << endl;
			ch = op = '#';
			is_matched = false;
		}
	} while (ch != '#' || op != '#');

	if (is_matched == true) cout << '=' << opnd.top();//ѭ�������󣬽���ڲ�����ջ��
	else {
		cout << "sorry, cannot compute this expression." << endl;
	}
}
int Calculator::lp(char op)//������˲����������ȼ�
{
	int prior;//���ȼ�
	switch (op)
	{
	case '+'://�����ȼ��������д��
	case '-': prior = 3; break;
	case '*':
	case '/': prior = 5; break;
	case '(': prior = 1; break;
	case ')': prior = 6; break;
	case '#': prior = 0; break;
	}
	return prior;
}
int Calculator::rp(char op)//�����Ҷ˲����������ȼ�
{
	int prior;//���ȼ�
	switch (op)
	{
	case '+':
	case '-': prior = 2; break;
	case '*':
	case '/': prior = 4; break;
	case '(': prior = 6; break;
	case ')': prior = 1; break;
	case '#': prior = 0; break;
	}
	return prior;
}
double Calculator::operate(char theta, double a, double b)
//���к�׺���ʽ�����㣬����������
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default: return 0;
	}
}