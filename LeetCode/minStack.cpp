#include<stack>
//题目描述：设计一个栈，使得他能够支持pop，push，top和在常数时间内得到最小元素的getMin
//解法描述：MinStack内部用标准stack来实现，另外再维护一个minStack，用来追踪最小元素

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