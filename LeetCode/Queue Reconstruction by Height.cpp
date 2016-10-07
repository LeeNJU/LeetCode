#include<vector>
#include<algorithm>
//��Ŀ����:����һ��pair,��һ��Ԫ�ر�ʾ�˵���ߣ��ڶ���Ԫ�ر�ʾ���������������֮ǰ�ж��ٸ��˵���ߴ��ڵ��ڵ�ǰ
//        ����˵���ߣ�����[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]��[7,0]��ʾ����˵������7��������
//        λ��֮ǰ����ߴ��ڵ���������ߵĸ�����0��[4,4]��ʾ�����4������֮ǰ��ߴ��ڵ��������˵ĸ�����4��
//        ����Ҫ�ָ�������У����ؽ��[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//�ⷨ����:�����������ʱ���Ȱ������߽���������������ȣ����յڶ���Ԫ����������Ȼ��������飬�����ǰ
//        Ԫ�صĵڶ���ֵ��k���Ͱѵ�ǰԪ�ز��뵽��k��λ��

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
	for (auto val : people)//�ڶ���Ԫ����k���Ͳ��뵽��k��λ��
		result.insert(result.begin() + val.second, val);
	return result;
}