#include<vector>
//题目描述:给定一个二维数组，实现next和hashNext函数
//解法描述:x和y分别代表行和列，hashNext的时候，要小心y不能超过当前列的下标。要注意考虑某一行是空的情况
class Vector2D 
{
private:
	std::vector<std::vector<int>> vec;
	int x, y;

public:
	Vector2D(std::vector<std::vector<int>>& vec2d) 
	{
		vec = vec2d;
		x = y = 0;
	}

	int next() 
	{
		return vec[x][y++];
	}

	bool hasNext() 
	{
		while (x < vec.size() && y == vec[x].size()) //用while循环是为了防止出现连续的空行
		{
			++x;
			y = 0;
		}
		return x < vec.size();
	}
};