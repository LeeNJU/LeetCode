#include<vector>
#include<unordered_map>
#include<stack>
//题目描述:给定两个数组，都不包含重复元素，nums1 = [4,1,2], nums2 = [1,3,4,2]，对于nums1中的元素，找到下一个
//        大的元素，例如nums2中，4之后没有比4大的元素，所以是-1,1后面比1大的元素是3，所以是3,2后面没有元素，所
//        以是-1
//解法描述:用stack保存一个递减的序列，例如[9,5,3,1],当下一个元素是4的时候，4比1和3都大，所以3和1的下一个比较大
//        的元素是4，用hashtable保存，然后把4压入栈中。

std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums)
{
	std::stack<int> stack;
	std::unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		while (!stack.empty() && nums[i] > stack.top())
		{
			int val = stack.top();
			stack.pop();
			map[val] = nums[i];
		}

		stack.push(nums[i]);
	}

	std::vector<int> result;
	for (int i = 0; i < findNums.size(); ++i)
	{
		if (map.find(findNums[i]) != map.end())
			result.push_back(map[findNums[i]]);
		else
			result.push_back(-1);
	}

	return result;
}


//版本2:现在只给定一个循环数组，例如[1,2,1],返回数组[2,-1,2]
//解法描述:跟上一题类似，只不过存的是下标

std::vector<int> nextGreaterElements(std::vector<int>& nums) 
{
	int n = nums.size();
	std::vector<int> result(n, -1);
	std::stack<int> stack; //存下标
	for (int i = 0; i < n * 2; ++i)//注意这里是2 * n
	{
		int num = nums[i % n];
		while (!stack.empty() && nums[stack.top()] < num) 
		{
			result[stack.top()] = num;
			stack.pop();
		}

		if (i < n) 
			stack.push(i);
	}

	return result;
}