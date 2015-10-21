//��Ŀ������Ҫ�����һ����������ʹ�ý���������ݣ�����1234,abcd,������Ӧ�ý������1a2b3c4d���������һ��������û��
//         Ԫ���ˣ���ֻ���ʣ��һ����������Ԫ��
//�ⷨ������index��ʾ��ǰ���������±꣬���һ��Ԫ��֮�����Ѱ�ҵ�һ����Ԫ�صĵ�����
class Iterator
{
private:
	int* pointer;
public:
	bool hasNext()
	{
		return pointer != nullptr;
	}
	int getNext()
	{
		int result = *pointer;
		++pointer;
		return result;
	}
};

class ZigzagIterator
{
private:
	Iterator iter[2];
	int index;
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
		while (!iter[index].hasNext() && index != old_index)//Ѱ����һ����Ԫ�صĵ����������߻ص���ǰ�ĵ�����
			index = ++index % 2;
		return result;
	}
};