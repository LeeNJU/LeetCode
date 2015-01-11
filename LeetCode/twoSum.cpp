#include<vector>
#include<algorithm>
#include<unordered_map>

//��Ŀ����������һ�����飬���м��ҳ�2����ʹ�����������ָ����һ����������array={2,9,33,1}�ҳ��͵���11��2����
//�ⷨ����unordered_map��ÿ�������±꣬ʱ�临�Ӷ�ΪO(n)

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
	std::vector<int> result;
	std::unordered_map<int, int> map;

	for (int i = 0; i < numbers.size(); ++i)//��hash���ÿ�������±�
		map[numbers[i]] = i;

	for (int i = 0; i < numbers.size(); ++i)
	{
		std::unordered_map<int, int>::iterator iter = map.find(target - numbers[i]);
		if (iter != map.end())//��hash���в���Ԫ�أ����Ӷ�Ϊ������
		{
			if (iter->second == i)//�ҵ���ͬһ��Ԫ�أ�����array={3,2,4}���Һ͵���6��2��������ֹ�ظ��ҵ�3
				continue;

			result.push_back(i + 1);
			result.push_back(map[target - numbers[i]] + 1);
			break;
		}
	}
	return result;
}

