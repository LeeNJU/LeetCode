#include<vector>
#include<algorithm>

//题目描述：给定一个高度数组，表明每个柱子的高度，求柱子之间能存多大的水量
//解法描述：记录第二高的柱子，从两边到中间，与第二高度的差就是水量
//          http://fisherlei.blogspot.com/2013/01/leetcode-trapping-rain-water.html
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
			area += secHight - height[left];//计算当前格的能装雨水的容量
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