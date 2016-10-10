#include<vector>
#include<set>
#include<algorithm>
//��Ŀ����:skyline����
//�ⷨ����:����ÿһ���߶Σ�������˵��Ӧ�ĸ߶Ⱥ��Ҷ˵��Ӧ�ĸ߶ȣ���multiset��С�����˳�򱣴���˵�ĸ߶ȣ�
//        ��ʾ��Щ����߶λ�û�н�������prev������һ��ȡ�õ���ߵ㣬��������ɨ�裬�������˵㣬����multiset
//        �У���������Ҷ˵㣬��ʾ��ǰ�߶εĽ�������multisetɾ����
//        http://www.cnblogs.com/grandyang/p/4534586.html

std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings) 
{
	std::vector<std::pair<int, int>> height, result;
	std::multiset<int> m;
	int prev = 0, cur = 0;
	for (auto &a : buildings) 
	{
		height.push_back(std::pair<int, int>(a[0], -a[2]));//ȡ��������������˵�
		height.push_back(std::pair<int, int>(a[1], a[2]));//�����Ҷ˵�
	}
	
	sort(height.begin(), height.end());
	m.insert(0);
	for (auto &a : height) 
	{
		if (a.second < 0)//��˵� 
			m.insert(-a.second);
		else 
			m.erase(m.find(a.second));//�Ҷ˵㣬�����߶εĽ���
		
		cur = *m.rbegin();
		if (cur != prev) 
		{
			result.push_back(std::pair<int, int>(a.first, cur));
			prev = cur;
		}
	}
	return result;
}