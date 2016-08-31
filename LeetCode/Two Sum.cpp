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


//version 2
//�������ź���������Ԫ�أ�ʹ�����ǵĺ͵���target
std::vector<int> twoSum2(std::vector<int> &numbers, int target)
{
	std::vector<int> result(2,0);
	int left = 0, right = numbers.size() - 1;
	while (left < right)
	{
		if (numbers[left] + numbers[right] == target)
		{
			result[0] = left + 1;
			result[1] = right + 1;
			break;
		}
		else if (numbers[left] + numbers[right] < target)
			++left;
		else
			--right;
	}
	return result;
}

//version 3
//���һ���࣬������������add��find��add���һ������find�ҵ���������ʹ�����ǵĺ͵��ڸ����Ĳ���
//�ⷨ����:��һ��map����ÿ��Ԫ���Լ����ֵĴ���(��Ϊ�������ظ�Ԫ��)��Ȼ������map���в���
class TwoSum 
{
private:
	std::unordered_map<int, int> elemCount;

public:
	void add(int number) 
	{
		elemCount[number]++;
	}

	bool find(int value) 
	{
		for (auto elem : elemCount) 
		{
			if ((elem.first < value - elem.first && elemCount.count(value - elem.first)) ||
				(elem.first == value - elem.first && elem.second > 1))
				return true;
		}
		return false;
	}
};
