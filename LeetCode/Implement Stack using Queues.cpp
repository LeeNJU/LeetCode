#include<queue>

//题目描述：用queue实现一个栈，其中只能使用queue的标准操作，pop，push，top等
//解法描述：用两个que，current指向当前的que，这两个que交替使用

class Stack 
{
private:
	std::queue<int> que[2]; //两个queue，这两个queue交替使用
	int current = 0; //current表示当前queue的下标
public:
	void push(int x) 
	{
		que[current].push(x);
	}

	void pop() 
	{
		while (que[current].size() > 1)
		{
			que[1 - current].push(que[current].front()); //把当前que的元素转移到另一个que
			que[current].pop();
		}

		que[current].pop();
		current = 1 - current; //转换que的下标，交替使用
	}

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

	bool empty() 
	{
		return que[current].empty();
	}
};