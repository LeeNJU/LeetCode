#include<vector>
#include<set>
#include<algorithm>
//题目描述:skyline问题
//解法描述:对于每一格线段，保存左端点对应的高度和右端点对应的高度，用multiset从小到大的顺序保存左端点的高度，
//        表示这些点的线段还没有结束，用prev保存上一次取得的最高点，从左往右扫描，如果是左端点，存入multiset
//        中，如果碰到右端点，表示当前线段的结束，从multiset删除，
//        http://www.cnblogs.com/grandyang/p/4534586.html

std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings) 
{
	std::vector<std::pair<int, int>> height, result;
	std::multiset<int> m;
	int prev = 0, cur = 0;
	for (auto &a : buildings) 
	{
		height.push_back(std::pair<int, int>(a[0], -a[2]));//取负数表明这是左端点
		height.push_back(std::pair<int, int>(a[1], a[2]));//这是右端点
	}
	
	sort(height.begin(), height.end());
	m.insert(0);
	for (auto &a : height) 
	{
		if (a.second < 0)//左端点 
			m.insert(-a.second);
		else 
			m.erase(m.find(a.second));//右端点，表明线段的结束
		
		cur = *m.rbegin();
		if (cur != prev) 
		{
			result.push_back(std::pair<int, int>(a.first, cur));
			prev = cur;
		}
	}
	return result;
}