#include<vector>
#include<map>
#include"TreeNode.h"
//��Ŀ����:����һ��interval��interval j��������interval i���ұߣ����interval j����ʼλ�ô��ڵ���interval i
//        �Ľ���λ�ã���ÿ��interval���ҵ���ӽ���"right"interval���±꣬����[ [3,4], [2,3], [1,2] ]�� ��
//        ô����[-1, 0, 1]��ĳ��interval������"right" interval������-1
//�ⷨ����:��¼ÿ��interval��ʼλ���Լ��±꣬����ÿ��interval�Ľ���λ�ã��ҵ���ӽ�����ʼλ�ã����ֲ��ң�

std::vector<int> findRightInterval(std::vector<Interval>& intervals) 
{
	std::map<int, int> map;
	for (int i = 0; i < intervals.size(); ++i)//������ʼλ���Լ��±�
		map[intervals[i].start] = i;

	std::vector<int> result(intervals.size(), -1);
	for (int i = 0; i < intervals.size(); ++i)
	{
		auto iter = map.upper_bound(intervals[i].end - 1);//ע������Ҫ��1
		if (iter != map.end())
			result[i] = iter->second;
	}

	return result;
}