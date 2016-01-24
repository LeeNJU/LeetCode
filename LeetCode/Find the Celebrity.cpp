#include<vector>
//题目描述:给定n个人，分别用0,1,2...n-1表示，celebrity的定义是，所有人都认识他，但是他不认识其他人，判断这n个
//        人里面是否有celebrity，如果没有返回-1，如果有返回对应的label
//解法描述:每次选两个人a和b,如果a认识b，那么a肯定不是celebrity，如果a不认识b,那么b肯定不是celebrity，最后只
//         剩一个人，判这个人是不是celebrity

bool knows(int a, int b);

int findCelebrity(int n) 
{
	std::vector<int> candidates(n,0);//初始化
	for (int i = 0; i < n; ++i)
		candidates[i] = i;

	while (candidates.size() >= 2) //每次取两个人
	{
		int a = candidates.back(); 
		candidates.pop_back();
		int b = candidates.back(); 
		candidates.pop_back();
		if (knows(a, b)) 
			candidates.push_back(b);
		else 
			candidates.push_back(a);
	}

	for (int i = 0; i < n; i++) 
	{
		if (i == candidates[0]) //选到自己
			continue;
		if (knows(candidates[0], i) || !knows(i, candidates[0]))
			return -1;
	}
	return candidates[0];
}