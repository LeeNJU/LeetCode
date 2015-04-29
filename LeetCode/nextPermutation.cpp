#include<vector>
#include<algorithm>
//��Ŀ�����������һ������
//�ⷨ������1.��������ɨ�裬�ҵ���һ���ǵ�����ֵvalue��2.��������ɨ�裬�ҵ���һ����value���ֵ 3.����������ֵ 4.��value�����ֵ���з�ת
//Ҫע������ȫ���ݼ������  ��ʱֻҪ��ת��������Ϳ�����
void nextPermutation(std::vector<int> &num)
{
	int left = num.size() - 1;
	for (int i = num.size() - 1; i >= 1; --i)//��������ɨ�裬�ҵ���һ���ǵ�����ֵleft
	{
		if (num[i - 1] < num[i])
		{
			left = i - 1;
			break;
		}
	}

	if (left == num.size() - 1)//�ж��Ƿ�Ϊȫ���ݼ�  �����  ֱ�ӷ�ת��������
	{
		std::reverse(num.begin(), num.end());
		return;
	}

	int right = 0;
	for (int i = num.size() - 1; i >= 0; --i)//��������ɨ�裬�ҵ���һ����left���ֵright
	{
		if (num[i] > num[left])
		{
			right = i;
			break;
		}
	}

	std::swap(num[left], num[right]);//��left��right����
	std::reverse(num.begin() + left + 1, num.end());//��left֮���Ԫ��ȫ����ת
}