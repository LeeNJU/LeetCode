#include<vector>
//��Ŀ����:���һ��������������������hit��getHits��hit�Ĳ���Ϊʱ��㣬��λΪ�룬ÿ����hit�����ͱ�ʾ��һ��hit��
//        ÿ����getHits�������ͷ���300�����ڵ�hit����ע����ܻ���ͬһʱ�����hit����
//�ⷨ����:��������СΪ300�����鱣��hit��ʱ���������ÿ����hit��ʱ��ʱ���timestamp��300ȡ�࣬�ȼ��times
//        ���飬���ʱ����ֵ�뵱ǰ��ʱ�����ͬ����ʾ��ͬһʱ����ε��ã���Ӧ��hit��1�����ʱ��㲻ͬ����ʾ
//        ʱ����Ѿ�����300�ˣ�����Ӧ��hit����Ϊ1�����õ�300�����ڵ�hit����ʱ�򣬱���times���飬��ʱ����
//        300�����ڵ�hit������ӡ�
class HitCounter 
{
private:
	std::vector<int> times, hits;

public:
	HitCounter() //��ʼ����300
	{
		times.resize(300);
		hits.resize(300);
	}

	void hit(int timestamp) 
	{
		int idx = timestamp % 300;
		if (times[idx] != timestamp)//�뵱ǰʱ��㲻ͬ����ʾ�Ѿ�����300���ˣ���Ϊ1 
		{
			times[idx] = timestamp;
			hits[idx] = 1;
		}
		else 
			++hits[idx];
	}

	int getHits(int timestamp) 
	{
		int res = 0;
		for (int i = 0; i < 300; ++i)//�������뵱ǰʱ����������300���hit��������� 
		{
			if (timestamp - times[i] < 300) 
				res += hits[i];
		}
		return res;
	}
};