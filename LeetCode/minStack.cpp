#include<stack>
//��Ŀ���������һ��ջ��ʹ�����ܹ�֧��pop��push��top���ڳ���ʱ���ڵõ���СԪ�ص�getMin
//�ⷨ������MinStack�ڲ��ñ�׼stack��ʵ�֣�������ά��һ��minStack������׷����СԪ��

class MinStack {
private:
	std::stack<int> s;
	std::stack<int> minStack;
public:
	void push(int x) 
	{
		if (minStack.empty() || x <= minStack.top())
			minStack.push(x);
		s.push(x);
	}

	void pop() 
	{
		if (minStack.top() == s.top())
			minStack.pop();
		s.pop();
	}

	int top() 
	{
		return s.top();
	}

	int getMin() 
	{
		return minStack.top();
	}
};