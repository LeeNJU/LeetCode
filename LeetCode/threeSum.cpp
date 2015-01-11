#include<vector>
#include<algorithm>
#include <iostream>

//��Ŀ����������һ�����֣������ҳ���������ʹ�����ǵĺ͵���0�������±�
//�ⷨ��������ȷ������һ������������ͷβָ�����м�ƽ����ң����Ӷ�O(n2)
//���ܻ��ж��ֽ�����ظ��������Ҫ���ǣ�����array={0,0,0,0}����Ӧ����0,0,0һ��

std::vector<std::vector<int>> threeSum(std::vector<int>& num)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	for (int i = 0; i < (int)num.size() - 2; ++i)//num.size() - 2,��ֹ�±�Խ��
	{
		if (i > 0 && num[i] == num[i - 1])//��Ԫ��i��Ԫ��i-1���ʱ������
			continue;

		int value = -num[i], left = i + 1, right = num.size() - 1;
		while (left < right)//�����±꣬����ͷ���м�ƽ�
		{
			if (left > i + 1 && num[left] == num[left - 1])//�����ظ�Ԫ��ʱ������
			{
				++left;
				continue;
			}
			if (right < num.size() - 1 && num[right] == num[right + 1])//�����ظ�Ԫ��ʱ������
			{
				--right;
				continue;
			}
			if (num[left] + num[right] > value)
				--right;
			else if (num[left] + num[right] < value)
				++left;
			else
			{
				result.push_back(std::vector<int> {num[i], num[left], num[right]});//�ҵ�һ�ֽ��
				++left;
				--right;
			}
		}
	}
	return result;
}