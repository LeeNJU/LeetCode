#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬a0,a1,a2,..ÿһ�������һ���߶�(i,0)��(i,ai)���ҳ������߶Σ�ʹ�������߶���x���γɵ�������
//�ⷨ������̰�ģ�����ָ�����м��ƶ��������������

int maxArea(std::vector<int> &height)
{
	int result = 0;
	int i = 0, j = height.size() - 1;

	while (i < j)
	{
		int area = (j - i) * std::min(height[i], height[j]);
		result = std::max(result, area);

		if (height[i] < height[j])
			++i;
		else
			--j;
	}
	return result;
}