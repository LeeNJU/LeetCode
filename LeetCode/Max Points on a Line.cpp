#include<vector>
#include<unordered_map>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����������һ��������飬�ҵ�һ��ֱ�ߣ�ʹ��ֱ���ϵĵ���࣬�������ĵ���
//�ⷨ�������Ե�Ϊ���ģ������ʣ�µĵ�����ɵ�б�ʣ�б����ͬ������ͬһ��ֱ���ϣ���¼�������

int maxPoints(std::vector<Point>& points)
{
	if (points.size() < 3) 
		return points.size();
	
	int result = 0;
	std::unordered_map<double, int> slope_count;
	for (int i = 0; i < points.size() - 1; ++i) 
	{
		slope_count.clear();
		int samePoint = 0;
		for (int j = i + 1; j < points.size(); ++j) 
		{
			double slope; // б��
			if (points[i].x == points[j].x)
			{
				slope = std::numeric_limits<double>::infinity(); // б��Ϊ�������������ֱ����x�ᴹֱ
				if (points[i].y == points[j].y)  //��ͬ�ĵ���������������Ľ���������ͬ�ĵ���
				{
					++samePoint;
					continue;
				}
			}
			else 
				slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x); //��б��
			
			++slope_count[slope];
		}

		int max = 0;
		auto iter = slope_count.begin();
		while (iter != slope_count.end()) //�ҵ��õ��Ӧ��ֱ�߰������ĵ���
		{
			max = std::max(max, iter->second);
			++iter;
		}
		result = std::max(result, max + 1 + samePoint); //�غϵĵ�Ҳ���ȥ
	}
	return result;
}
