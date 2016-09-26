#include<vector>
//��Ŀ����:����һ�����飬ȫ����0������һ�������[i, j, k]��ʾ������[i, j]֮���Ԫ�ض�����k�����ڸ���һ�������
//        ��������֮����������ֵ,���磬[ 0, 0, 0, 0, 0 ]��������һ�������[ [1, 3, 2], [2, 4, 3],
//        [0, 2, -2]],�������֮���������[-2, 0, 3, 5, 3]
//�ⷨ����:����ÿһ����������±�i�ĵط�����k�����±�j + 1��λ�ü�ȥk��Ȼ����ж�ÿ��λ�ý����ۼ�

std::vector<int> getModifiedArray(int length, std::vector<std::vector<int>>& updates) 
{
	std::vector<int> result(length + 1);
	for (auto a : updates) 
	{
		result[a[0]] += a[2];
		result[a[1] + 1] -= a[2];
	}
	for (int i = 1; i < result.size(); ++i)
		result[i] += result[i - 1];
	result.pop_back();//�������һ��Ԫ��
	return result;
}