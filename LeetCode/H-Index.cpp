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