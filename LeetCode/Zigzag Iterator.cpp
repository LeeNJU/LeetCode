#include"TreeNode.h"
//题目描述：要求设计一个迭代器，使得交替输出内容，例如1234,abcd,迭代器应该交替输出1a2b3c4d，如果其中一个迭代
//         器没有元素了，就只输出剩下一个迭代器的元素
//解法描述：index表示当前迭代器的下标，输出一个元素之后，向后寻找第一个有元素的迭代器

class ZigzagIterator
{
private:
	Iterator iter[2];
	int index; //index表示当前可用的迭代器
public:
	ZigzagIterator(Iterator& a, Iterator& b)
	{
		iter[0] = a;
		iter[1] = b;
		index = a.hasNext() ? 0 : 1;
	}

	bool hasNext()
	{
		return iter[index].hasNext();
	}

	int getNext()
	{
		int result = iter[index].getNext();
		int old_index = index;
		index = ++index % 2;
		while (!iter[index].hasNext() && index != old_index)//寻找下一个有元素的迭代器，或者回到当前的迭代器
			index = ++index % 2;
		return result;
	}
};