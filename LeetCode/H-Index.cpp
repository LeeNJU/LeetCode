#include<vector>
#include<algorithm>
//��Ŀ����������һ�������ʾ��ѧ�ҵ�����������������ܵ�����ָ��h��ʹ��hƪ���ĵ�����ָ�����ڵ���h��ʣ�µ�N-hƪ���ĵ�
//         ����ָ��С��h
//�ⷨ����������������index��ʾָ�����Ӻ���ǰɨ��
int hIndex(std::vector<int>& citations) 
{
	int n = citations.size();

	std::vector<int> vec(n + 1, 0);//vec[i]��ʾ����Ϊi��������
	for (int i = 0; i < n; i++) 
	{
		if (citations[i] > n) //vec[n]��ʾ���������ڵ���n��������
			vec[n] += 1;
		else 
			vec[citations[i]] += 1;
	}

	int t = 0;
	for (int i = n; i >= 0; --i)//�Ӻ���ǰɨ��
	{
		t += vec[i];
		if (t >= i) 
			return i;
	}
	return 0;
}

//���֣���������Ѿ����ź����ˣ���������index��Ҫ������ʱ����log(n)
//�ⷨ�������ö��ַ����в���
int hIndex2(std::vector<int>& citations) 
{
	if (citations.empty())
		return 0;

	int left = 0, right = citations.size() - 1, middle = 0;
	while (left <= right)//���ַ������±꣬��left��right���ʱ����Ҫ�����Ƚ�citations[left]
	{
		middle = (left + right) / 2;
		if (citations[middle] >= (citations.size() - middle))//ע��֮����±���citations.size() - middle
			right = middle - 1;
		else
			left = middle + 1;
	}
	return citations.size() - left;
}