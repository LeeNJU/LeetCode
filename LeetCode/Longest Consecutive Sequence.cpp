#include<vector>
#include<unordered_map>
#include<algorithm>
//题目描述：给定一个整数数组，找到最长的连续数字的长度，例如{100, 4, 200, 1, 3, 2},最长的连续数字为{1, 2, 3, 4}.
//         长度为4
//解法描述：用hashtable表示每个数字是否被使用过，遍历数组中的每个数字，分别向左和向右进行扩张（减1和加1），判断其相邻的
//         元素是否在数组中，如果在数组中，则标记为已经使用过，下次扫描到这个元素时就不用扫描了

int longestConsecutive(std::vector<int> &num)
{
	std::unordered_map<int, bool> used;
	for (auto i : num)//初始化
		used[i] = false;

	int longest = 0;
	for (auto i : num)
	{
		if (used[i])//该数字在前面已经被使用过，所有不用再使用了，节省
			continue;

		int length = 1;
		used[i] = true;

		for (int j = i + 1; used.find(j) != used.end(); ++j) //向右扩张，依次加1，判断是否存在数组中
		{	
			used[j] = true;
			++length;
		}
		for (int j = i - 1; used.find(j) != used.end(); --j) //向左扩张，依次减1,
		{	
			used[j] = true;
			++length;
		}
		longest = std::max(longest, length);
	}
	return longest;
}