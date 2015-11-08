#include<vector>
#include<algorithm>
#include<numeric>
//题目描述：给定一个数组ratings，表示每个小孩的值，给每个小孩发糖果，要求ratings值大的必须要比相邻的ratings值小的糖果数要多
//求最少需要多少个糖果
//解法描述：扫描两遍，先从左往右扫描，把位于波谷位置的值设为1，依次加1，一直加到波峰，再到波谷时又是1，再依次加到波峰
//再从右往左扫描，波谷时设为1，依次加1到波峰，此时的波峰因为第一遍扫描已经有值了，必须去二者的最大值

int candy(std::vector<int> &ratings)
{
	std::vector<int> candy(ratings.size(), 1);//初始化为1，因为每个小孩最少可以得到1，就不用为波谷赋值了

	for (int i = 1; i < ratings.size(); ++i)//从左往右扫描
	{
		if (ratings[i] > ratings[i - 1])
			candy[i] = candy[i - 1] + 1;
	}

	for (int i = ratings.size() - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			candy[i] = std::max(candy[i + 1] + 1, candy[i]);//波峰要比左右的都大，所以要取最大值
	}

	int sum = std::accumulate(candy.begin(), candy.end(), 0);
	return sum;
}