#include<vector>
#include<algorithm>

//����һ�������һ��ֵ�������ҳ��ĸ����֣�ʹ�����ǵĺ͵��ڸ�����ֵ
//�ⷨ�� ����������forѭ����ȷ��ͷ�������֣�Ȼ��������ͷβָ�����м�ƽ���ע��ȥ�أ����Ӷ�O(n3)

std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;

	for (int i = 0; i < num.size(); ++i)//��һ��forѭ����ȷ����һ������
	{
		if (i > 0 && num[i] == num[i - 1])//��ֹ�ظ�
			continue;

		for (int j = i + 1; j < num.size(); ++j)//�ڶ���forѭ����ȷ���ڶ�������
		{
			if (j > i + 1 && num[j] == num[j - 1])//��ֹ�ظ�
				continue;

			int left = j + 1, right = num.size() - 1;
			while (left < right)
			{
				if (left > j + 1 && num[left] == num[left - 1])//��ֹ�ظ�
				{
					++left;
					continue;
				}
				if (right < num.size() - 1 && num[right] == num[right + 1])//��ֹ�ظ�
				{
					--right;
					continue;
				}
				if (num[i] + num[j] + num[left] + num[right] == target)
				{
					result.push_back(std::vector<int>{num[i], num[j], num[left], num[right]});
					++left;
					--right;
				}
				else if (num[i] + num[j] + num[left] + num[right] < target)
				{
					++left;
				}
				else
				{
					--right;
				}
			}
		}
	}

	return result;
}