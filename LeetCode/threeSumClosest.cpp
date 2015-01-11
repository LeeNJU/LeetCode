#include<vector>
#include<algorithm>

//��Ŀ����������һ�����飬�����ҳ���������ʹ���ǵĺ���target��ӽ���������ֵ��С�������������ĺ�
//�ⷨ��������Ȼ����ͷβ����ָ�����м�ƽ�����ʼ���þ���ֵ��ֵΪINT_MAX���ҵ�����ֵ��С�ĺ�

int threeSumClosest(std::vector<int> &num, int target) 
{
	sort(num.begin(), num.end());
	int sum = 0, diff = INT_MAX;
	for (int i = 0; i < (int)num.size() - 2; ++i)
	{
		int left = i + 1, right = num.size() - 1;
		while (left < right)
		{
			if (abs(num[i] + num[left] + num[right] - target) < diff)//�ͱ���һ�εĸ��ӽ�������
			{
				sum = num[i] + num[left] + num[right];
				diff = abs(num[i] + num[left] + num[right] - target);
			}
			if (num[i] + num[left] + num[right] < target)//�����±������
				++left;
			else if (num[i] + num[left] + num[right] > target)
				--right;
			else
				return sum;
		}
	}
	return sum;
}