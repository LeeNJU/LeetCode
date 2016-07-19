#include"TreeNode.h"
#include<vector>
#include<stack>

//��Ŀ����:����һ��Ƕ�����������ƽ��������hasNext����true�������Ԫ�أ����򷵻�false������next���ص�ǰԪ��
//        ����[[1,1],2,[1,1]],��ƽ����Ӧ����[1,1,2,1,1]
//�ⷨ����:��һ��ջ���Ȱ�Ԫ���������ջ�У�hasnext�����У������ǰԪ�ز���һ����������ô����һ������������
//        ��Ԫ��һ��ѹ��ջ�У�ֱ��ջΪ�ջ��ߵ�ǰջ��Ԫ��Ϊһ������Ϊֹ��
class NestedIterator 
{
private:
	std::stack<NestedInteger> s;
public:
	NestedIterator(std::vector<NestedInteger>& nestedList) 
	{   //�������ջ��
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
			for (int i = t.getList().size() - 1; i >= 0; --i) //ջ��Ԫ��������������Ԫ�ط���ջ��
				s.push(t.getList()[i]);
		}
		return false;
	}
};