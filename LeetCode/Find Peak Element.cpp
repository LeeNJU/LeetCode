#include <vector>
//��Ŀ����������һ�����飬��������Ԫ�ز��ȣ��ҵ�һ��peak element��ʹ�����������ڵ�����Ԫ�ض��󣬼���n[0]��n[n]�����ڸ�����
//�ⷨ������ɨ��һ�飬�ҵ���һ����ǰ��Ԫ��С��Ԫ�أ��±��1���Ǵ�

int findPeakElement(const std::vector<int> &num) 
{
	for (int i = 1; i < num.size(); ++i)
	    if (num[i] < num[i - 1])
		   return i - 1;

	return num.size() - 1;
}