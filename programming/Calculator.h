using namespace std;
class Calculator
{
private://˽�г�Ա�����ݳ�Ա��
	MyStack<char> optr;//������ջ
	MyStack<double> opnd;//������ջ
	MyStack<char> bracket;//���ڴ�������ŵ�ջ
public://���г�Ա���������õĳ�Ա��������������
	Calculator()//���캯��
	{
		optr.setnull();
		opnd.setnull();
		bracket.setnull();
		optr.push('#');//��#����Ϊջ���ڱ�
	}
	void evaluate();//����ջ�ṹ����׺���ʽתΪPRN�����㣬���������ĺϷ���
	void clear()//��ռ�����
	{
		optr.setnull();
		optr.setnull();
		bracket.setnull();
		optr.push('#');//�빹���ʵ����һ�µ�
	}

private://˽�г�Ա���������صĳ�Ա������ֻ���ڲ����ã�
	int lp(char op);//������˲����������ȼ�
	int rp(char op);//�����Ҷ˲����������ȼ�
	double operate(char theta, double a, double b);//���к�׺���ʽ�����㣬����������
};
