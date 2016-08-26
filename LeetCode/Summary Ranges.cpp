#include<string>
#include<vector>

//��Ŀ����:����һ��û���ظ�Ԫ�ص��������飬���ط�Χ������[0,1,2,4,5,7]������["0->2","4->5","7"]
//�ⷨ����:��first��last����ʾһ����Χ,���������ʱ��last��ʾ��һλӦ�ó��ֵ�Ԫ�أ������ǰԪ����last����
//        ˵���ҵ���һ������
std::vector<std::string> summaryRanges(std::vector<int>& nums)
{
	std::vector<std::string> result;
	if (nums.empty())
		return result;

	int first = nums[0];
	int last = first + 1; //��һ��Ӧ�ó��ֵ�Ԫ��
	for (int i = 1; i < nums.size(); ++i)
	{
		if (last != nums[i])
		{
			if (last - 1 == first)//������ֻ��һ��Ԫ��
				result.push_back(std::to_string(first));
			else
				result.push_back(std::to_string(first) + "->" + std::to_string(last - 1));
			first = nums[i];
			last = first + 1;
		}
		else
			++last;
	}

	if (last - 1 == first)
		result.push_back(std::to_string(first));
	else
		result.push_back(std::to_string(first) + "->" + std::to_string(last - 1));
	return result;
}