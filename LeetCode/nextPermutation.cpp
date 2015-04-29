#include<vector>
#include<algorithm>
//题目描述：求出下一个排列
//解法描述：1.从右往左扫描，找到第一个非递增的值value，2.从右往左扫描，找到第一个比value大的值 3.交换这两个值 4.把value后面的值进行反转
//要注意数组全部递减的情况  这时只要反转整个数组就可以了
void nextPermutation(std::vector<int> &num)
{
	int left = num.size() - 1;
	for (int i = num.size() - 1; i >= 1; --i)//从右往左扫描，找到第一个非递增的值left
	{
		if (num[i - 1] < num[i])
		{
			left = i - 1;
			break;
		}
	}

	if (left == num.size() - 1)//判断是否为全部递减  如果是  直接反转整个数组
	{
		std::reverse(num.begin(), num.end());
		return;
	}

	int right = 0;
	for (int i = num.size() - 1; i >= 0; --i)//从右往左扫描，找到第一个比left大的值right
	{
		if (num[i] > num[left])
		{
			right = i;
			break;
		}
	}

	std::swap(num[left], num[right]);//把left和right交换
	std::reverse(num.begin() + left + 1, num.end());//把left之后的元素全部反转
}