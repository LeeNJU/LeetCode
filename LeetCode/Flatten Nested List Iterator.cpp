#include"TreeNode.h"
#include<vector>
#include<stack>

//题目描述:给定一个嵌套链表，将其扁平化，调用hasNext返回true如果还有元素，否则返回false，调用next返回当前元素
//        例如[[1,1],2,[1,1]],扁平化后应该是[1,1,2,1,1]
//解法描述:用一个栈，先把元素逆序存入栈中，hasnext方法中，如果当前元素不是一个整数，那么就是一个链表，把链表
//        的元素一次压入栈中，直到栈为空或者当前栈顶元素为一个整数为止。
class NestedIterator 
{
private:
	std::stack<NestedInteger> s;
public:
	NestedIterator(std::vector<NestedInteger>& nestedList) 
	{   //逆序放入栈中
		for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); ++iter)
			s.push(*iter);
	}

	int next() 
	{
		NestedInteger t = s.top(); 
		s.pop();
		return t.getInteger();
	}

	bool hasNext() 
	{
		while (!s.empty()) 
		{
			NestedInteger t = s.top();
			if (t.isInteger()) 
				return true;
			
			s.pop();
			for (int i = t.getList().size() - 1; i >= 0; --i) //栈顶元素是链表，把链表元素放入栈中
				s.push(t.getList()[i]);
		}
		return false;
	}
};