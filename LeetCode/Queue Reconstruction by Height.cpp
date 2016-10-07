#include<vector>
#include<algorithm>
//题目描述:给定一组pair,第一个元素表示人的身高，第二个元素表示在这个队列中在这之前有多少个人的身高大于等于当前
//        这个人的身高，例如[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]，[7,0]表示这个人的身高是7，在它的
//        位置之前，身高大于等于他的身高的个数是0，[4,4]表示身高是4，在它之前身高大于等于他的人的个数是4，
//        现在要恢复这个队列，返回结果[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//解法描述:先排序，排序的时候先按照升高降序排序，如果身高相等，按照第二个元素升序排序，然后遍历数组，如果当前
//        元素的第二个值是k，就把当前元素插入到第k个位置

static int compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.first == b.first ? a.second < b.second : a.first > b.first;
}

std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>>& people) 
{
	std::vector<std::pair<int, int>> result;
	if (people.size() == 0) 
		return result;

	sort(people.begin(), people.end(), compare);
	for (auto val : people)//第二个元素是k，就插入到第k个位置
		result.insert(result.begin() + val.second, val);
	return result;
}