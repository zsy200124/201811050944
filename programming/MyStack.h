const int maxstack = 10;//ջ��Ԫ�ظ��������ֵ
enum Error_code { success, underflow, overflow };//�������гɹ������ڲ���ǩ
template <class Stack_entry>//��ģ�壬�������ͽ�Stack_entry
class MyStack
{
public:                    //���г�Ա��������г�Ա������
	MyStack();
	bool empty() const;
	Error_code push(const Stack_entry &item);
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Stack_entry top()const;        //����top��������Ӧ��ͬ����Ҫ
	void setnull();//���ջ
private:                //˽�г�Ա�����ݳ�Ա��
	int count;        //������
	Stack_entry entry[maxstack];//������ʵ�ִ洢
};
