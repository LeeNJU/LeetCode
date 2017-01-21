#include<vector>
#include<algorithm>
//��Ŀ����:�����������飬ÿ������ֻ����0��9�����֣�����������������ֵk��������������ѡ��k�����֣�ʹ��������ɵ�
//        �����ÿ�������е����ֵ����˳�򱣳ֲ��䡣����[3, 4, 6, 5]��[9, 1, 2, 5, 8, 3]�� k = 5����ɵ����
//        ����[9, 8, 6, 5, 3]
//�ⷨ����:�ӵ�һ��������һ��ȡ��i�����֣��ڶ���������ȡ��k - i�����֣�0 <= i <= k,�������е�������������ֵ


std::vector<int> maxVector(std::vector<int> nums, int k)//��������ѡ��k�����֣�ʹ����ɵ��������
{
	int drop = nums.size() - k;
	std::vector<int> result;
	for (int num : nums)
	{
		while (drop && result.size() && result.back() < num)
		{
			result.pop_back();
			--drop;
		}
		result.push_back(num);
	}

	result.resize(k);
	return result;
}

std::vector<int> mergeVector(std::vector<int> nums1, std::vector<int> nums2)
{                           //�����������кϲ������γ��������֣�ע�������vector���бȽϣ�
	std::vector<int> result;//����ָ����бȽϵķ�ʽ�д�����[6,0],  [6,7,9],������������ȵ�ʱ���޷�ȷ��
	while (nums1.size() + nums2.size()) //Ӧ���ƶ��ĸ�ָ��
	{
		std::vector<int>& tmp = nums1 > nums2 ? nums1 : nums2;
		result.push_back(tmp[0]);
		tmp.erase(tmp.begin());
	}
	return result;
}

std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) 
{
	int m = nums1.size(), n = nums2.size();
	std::vector<int> result;
	for (int i = std::max(0, k - n); i <= std::min(k, m); ++i)//ע������i��ȡֵ��Χ
	{  //�������п��ܵ�k��ȡ���
		result = std::max(result, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
	}
	return result;
}