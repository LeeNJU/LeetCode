#include<vector>
#include<algorithm>

//题目描述，给定一个数组，从中找出三个数，使它们的和与target最接近，即绝对值最小，返回三个数的和
//解法，先排序，然后用头尾两个指针向中间逼近，开始设置绝对值差值为INT_MAX，找到绝对值最小的和

int threeSumClosest(std::vector<int>& num, int target) 
{
	sort(num.begin(), num.end());
	int sum = 0, diff = INT_MAX;
	for (int i = 0; i < (int)num.size() - 2; ++i)
	{
		int left = i + 1, right = num.size() - 1;
		while (left < right)
		{
			if (abs(num[i] + num[left] + num[right] - target) < diff)//和比上一次的更接近，更新
			{
				sum = num[i] + num[left] + num[right];
				diff = abs(num[i] + num[left] + num[right] - target);
			}
			if (num[i] + num[left] + num[right] < target)//控制下标的走向
				++left;
			else if (num[i] + num[left] + num[right] > target)
				--right;
			else
				return sum;
		}
	}
	return sum;
}