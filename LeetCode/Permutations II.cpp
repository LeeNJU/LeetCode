#include<vector>
#include<algorithm>

//��Ŀ����������һ���������飨�����ظ�Ԫ�أ���������Щ�������е����
//�ⷨ�������ݹ飬�����������ظ�Ԫ�ؾ����������ظ�Ԫ�ؾͰ����ŵ���ǰ���еĵ�һλ���Ѹ�Ԫ�ؼ��뵽perm�У�Ȼ��ݹ飬�ݹ�����Ҫ����

void dfs(std::vector<int>& nums, int index, std::vector<int> &perm, std::vector<std::vector<int> > &result)
{
	int size = nums.size();
	if (size == index)  //�ҵ�һ����
		result.push_back(perm);
	else 
	{
		for (int i = index; i < size; ++i) //��index��ʼ���� 
		{
			if ((i > index) && (nums[i] == nums[index])) //���ظ�Ԫ�أ�����
				continue;
			else 
				std::swap(nums[index], nums[i]); //�����ظ�Ԫ�أ�i��index�������ѵ�ǰԪ�طŵ���һλ
			perm.push_back(nums[index]);
			dfs(nums, index + 1, perm, result);
			perm.pop_back();
		}
		sort(nums.begin() + index, nums.end()); //ǰ�����nums��˳�򣬽��лָ�
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	std::vector<std::vector<int> > result;
	std::vector<int> perm;
    std::sort(nums.begin(), nums.end());  //�Ƚ������򣬷���ȥ��
	dfs(nums, 0, perm, result);
    return result;
}