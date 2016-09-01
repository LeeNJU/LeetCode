#include<queue>

//��Ŀ��������queueʵ��һ��ջ������ֻ��ʹ��queue�ı�׼������pop��push��top��
//�ⷨ������������que��currentָ��ǰ��que��������que����ʹ��

class Stack 
{
private:
	std::queue<int> que[2]; //����queue��������queue����ʹ��
	int current = 0; //current��ʾ��ǰqueue���±�
public:
	// Push element x onto stack.
	void push(int x) 
	{
		que[current].push(x);
	}

	// Removes the element on top of the stack.
	void pop() 
	{
		while (que[current].size() > 1)
		{
			que[1 - current].push(que[current].front()); //�ѵ�ǰque��Ԫ��ת�Ƶ���һ��que
			que[current].pop();
		}

		que[current].pop();
		current = 1 - current; //ת��que���±꣬����ʹ��
	}

	// Get the top element.
	int top() 
	{
		while (que[current].size() > 1)
		{
			que[1 - current].push(que[current].front());
			que[current].pop();
		}

		int top = que[current].front();
		que[1 - current].push(top);
		que[current].pop();
		current = 1 - current;
		return top;
	}

	// Return whether the stack is empty.
	bool empty() 
	{
		return que[current].empty();
	}
};