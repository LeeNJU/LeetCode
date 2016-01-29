#include<stack>
//题目描述:用stack实现queue
//解法描述:用两个栈
class Queue 
{
private:
	std::stack<int> stack1;
	std::stack<int> stack2;
public:
	void push(int x) 
	{
		stack1.push(x);
	}

	void pop(void) 
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int element = stack2.top();
		stack2.pop();
	}

	int peek(void) 
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();
	}

	bool empty(void) 
	{
		return stack1.empty() && stack2.empty();
	}
};