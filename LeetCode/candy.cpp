#include<vector>
#include<algorithm>
#include<numeric>
//��Ŀ����������һ������ratings����ʾÿ��С����ֵ����ÿ��С�����ǹ���Ҫ��ratingsֵ��ı���Ҫ�����ڵ�ratingsֵС���ǹ���Ҫ��
//��������Ҫ���ٸ��ǹ�
//�ⷨ������ɨ�����飬�ȴ�������ɨ�裬��λ�ڲ���λ�õ�ֵ��Ϊ1�����μ�1��һֱ�ӵ����壬�ٵ�����ʱ����1�������μӵ�����
//�ٴ�������ɨ�裬����ʱ��Ϊ1�����μ�1�����壬��ʱ�Ĳ�����Ϊ��һ��ɨ���Ѿ���ֵ�ˣ�����ȥ���ߵ����ֵ

int candy(std::vector<int> &ratings)
{
	int result = 0;
	std::vector<int> candy(ratings.size(), 1);//��ʼ��Ϊ1����Ϊÿ��С�����ٿ��Եõ�1���Ͳ���Ϊ���ȸ�ֵ��

	for (int i = 1, inc = 1; i < ratings.size(); ++i)//��������ɨ��
	{
		if (ratings[i] > ratings[i - 1])
			candy[i] = ++inc;
		else
			inc = 1;
	}

	for (int i = ratings.size() - 2, inc = 1; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			candy[i] = std::max(++inc, candy[i]);//����Ҫ�����ҵĶ�������Ҫȡ���ֵ
		else
			inc = 1;
	}

	result = std::accumulate(candy.begin(), candy.end(), 0);
	return result;
}