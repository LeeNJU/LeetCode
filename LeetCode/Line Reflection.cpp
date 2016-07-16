#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
//��Ŀ����:����һЩ�㣬Ҫ���ж��Ƿ����һ����y��ƽ�е��ߣ�ʹ�����еĵ���������߶Գ�
//�ⷨ����:���ҵ������ԳƵ��ߣ�Ȼ�����ÿһ�����Ƿ���ڹ��������߶ԳƵĵ㡣

bool isReflected(std::vector<std::pair<int, int>>& points) 
{
	std::unordered_map<int, std::set<int>> m; //�������Ӧ��������
	int mx = INT_MIN, mn = INT_MAX;
	for (auto point : points) //ͨ������������ֵ����Сֵ���ҶԳ���
	{
		mx = std::max(mx, point.first);
		mn = std::min(mn, point.first);
		m[point.first].insert(point.second);
	}

	double middle = (double) (mx + mn) / 2;
	for (auto point : points) 
	{
		int x = 2 * middle - point.first; //�����Ӧ�ĺ�����
		if (!m.count(x) || !m[x].count(point.second)) //����Ӧ���������Ƿ����
			return false;
	}
	return true;
}