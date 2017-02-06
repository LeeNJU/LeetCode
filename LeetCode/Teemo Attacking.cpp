#include<vector>
//��Ŀ����:����һ�������һ��ֵ��ʾduration������[1,4], 2����ʾ��1��ʼ������ʱ�䳤����2��[1,2]���������poison
//        ״̬��Ȼ���4������[4,5]�Ǵ���poison״̬�����ܹ�����poison״̬��ʱ�䣬������[1,2],2,����[1,2]��
//        poison״̬��Ȼ���2������[2,3]����poison״̬���ܹ���3��ʱ�䴦��poison״̬
//�ⷨ����:�������飬���ڵ�ǰʱ��㣬�������֮ǰ��poison״̬��Χ֮�ڣ���¼poison�Ŀ�ʼʱ�䣬
//        [begin, beign + duration],�����ǰʱ��㴦�������Χ֮�ڣ�ֻ��Ҫ����t - begin��ʱ�䣬������������
//        ��Χ֮�ڣ���ֱ�Ӽ���duration

int findPoisonedDuration(std::vector<int>& timeSeries, int duration)
{
	if (timeSeries.empty()) 
		return 0;

	int begin = timeSeries[0], total = 0;
	for (int t : timeSeries) 
	{
		total += t < begin + duration ? t - begin : duration;
		begin = t;
	}

	return total + duration;
}

/*
int findPoisonedDuration(std::vector<int>& timeSeries, int duration) 
{
	if (timeSeries.empty())
		return 0;
	if (timeSeries.size() == 1)
		return duration;

	int end = timeSeries[0] + duration - 1;
	int result = 0;
	for (int i = 1; i < timeSeries.size(); ++i)
	{
		if (timeSeries[i] > end)
		{
			result += duration;
			end = timeSeries[i] + duration - 1;
		}
		else
		{
			result += timeSeries[i] - timeSeries[i - 1];
			end = timeSeries[i] + duration - 1;
		}
	}

	return result + duration;
}*/