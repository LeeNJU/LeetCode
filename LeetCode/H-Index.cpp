#include<vector>
#include<algorithm>
//��Ŀ����������һ�������ʾ��ѧ�ҵ�����������������ܵ�����ָ��h��ʹ��hƪ���ĵ�����ָ�����ڵ���h��ʣ�µ�N-hƪ���ĵ�
//         ����ָ��С��h
//�ⷨ��������������index��ʾָ�����Ӻ���ǰɨ��
int hIndex(std::vector<int>& citations) 
{
	sort(citations.begin(), citations.end());
	int index = 1;
	for (; index <= citations.size(); ++index)
	{
		if (citations[citations.size() - index] < index)
			break;
	}
	return index - 1;
}

//���֣���������Ѿ����ź����ˣ���������index��Ҫ������ʱ����log(n)
//�ⷨ�������ö��ַ����в���
int hIndex2(std::vector<int>& citations) 
{
	if (citations.empty())
		return 0;

	int left = 0, right = citations.size() - 1, middle = 0;
	int result = 0;//������
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (citations[middle] >= (citations.size() - middle))//ע��֮����±���citations.size() - middle
		{
			result = citations.size() - middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	return result;
}