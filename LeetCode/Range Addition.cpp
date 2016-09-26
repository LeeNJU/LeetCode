#include<vector>
//题目描述:给定一个数组，全部是0，还有一组操作，[i, j, k]表示把区间[i, j]之间的元素都加上k，现在给定一组操作，
//        求操作完成之后的数组里的值,例如，[ 0, 0, 0, 0, 0 ]，给定的一组操作是[ [1, 3, 2], [2, 4, 3],
//        [0, 2, -2]],操作完成之后的数组是[-2, 0, 3, 5, 3]
//解法描述:对于每一格操作，在下标i的地方加上k，在下标j + 1的位置减去k，然后进行对每个位置进行累加

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
	result.pop_back();//弹出最后一个元素
	return result;
}