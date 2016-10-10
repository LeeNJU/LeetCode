#include<vector>
#include<algorithm>
//题目描述：给定一个数组，a0,a1,a2,..每一个点代表一条线段(i,0)和(i,ai)，找出两条线段，使这两条线段与x轴形成的
//         面积最大
//解法描述：贪心，两个指针往中间移动，保持最大的面积

int maxArea(std::vector<int>& height)
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