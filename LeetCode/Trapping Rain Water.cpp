#include<vector>
#include<algorithm>

//��Ŀ����������һ���߶����飬����ÿ�����ӵĸ߶ȣ�������֮���ܴ����ˮ��
//�ⷨ��������¼�ڶ��ߵ����ӣ������ߵ��м䣬��ڶ��߶ȵĲ����ˮ��

int trap(std::vector<int>& height)
{
	int secHight = 0;
	int left = 0;
	int right = height.size() - 1;
	int area = 0;
	while (left < right)
	{
		if (height[left] < height[right])
		{
			secHight = std::max(height[left], secHight);
			area += secHight - height[left];//���㵱ǰ�����װ��ˮ������
			left++;
		}
		else 
		{
			secHight = std::max(height[right], secHight);
			area += secHight - height[right];
			right--;
		}
	}
	return area;
}