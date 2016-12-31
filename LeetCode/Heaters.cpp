#include<vector>
#include<algorithm>
//��Ŀ����:����һ�������ʾ���ӵ�λ�ã�һ�������ʾheater��λ�ã��ҵ���С�İ뾶��ʹ�����еķ��Ӷ����Ա�heater
//        ����
//�ⷨ����:��heater�������򣬶���ÿһ�����ӣ����ö��ֲ��ң��ҵ���ӽ���heater������뾶����Щ�뾶����С�ľ���
//        ��

int findRadius(std::vector<int>& houses, std::vector<int>& heaters) 
{
	std::sort(heaters.begin(), heaters.end());
	int minRadius = 0;
	for (int i = 0; i < houses.size(); ++i)
	{
		auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);//�ҵ���һ�����ڵ���val��
		int curRadius = INT_MAX;                           //λ��
		if (larger != heaters.end())
			curRadius = *larger - houses[i];

		if (larger != heaters.begin())
		{
			auto smaller = larger - 1;//ֻҪlarger���������ǵ�һ����large - 1����С��val��Ԫ��
			curRadius = std::min(curRadius, houses[i] - *smaller);
		}
		minRadius = std::max(minRadius, curRadius);
	}
	return minRadius;
}