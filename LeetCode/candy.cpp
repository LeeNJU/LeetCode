#include<vector>
#include<algorithm>
#include<numeric>
//��Ŀ����:����һ������ratings����ʾÿ��С����ֵ����ÿ��С�����ǹ���Ҫ��ratingsֵ��ı���Ҫ�����ڵ�ratings
//         ֵС���ǹ���Ҫ��,��������Ҫ���ٸ��ǹ�
//�ⷨ����:ɨ�����飬�ȴ�������ɨ�裬��λ�ڲ���λ�õ�ֵ��Ϊ1�����μ�1��һֱ�ӵ����壬�ٵ�����ʱ����1��������
//         �ӵ�����,�ٴ�������ɨ�裬����ʱ��Ϊ1�����μ�1�����壬��ʱ�Ĳ�����Ϊ��һ��ɨ���Ѿ���ֵ�ˣ�����ȡ
//         ���ߵ����ֵ

int candy(std::vector<int> &ratings)
{
	std::vector<int> candy(ratings.size(), 1);//��ʼ��Ϊ1����Ϊÿ��С�����ٿ��Եõ�1���Ͳ���Ϊ���ȸ�ֵ��

	for (int i = 1; i < ratings.size(); ++i)//��������ɨ��
	{
		if (ratings[i] > ratings[i - 1])
			candy[i] = candy[i - 1] + 1;
	}

	for (int i = ratings.size() - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			candy[i] = std::max(candy[i + 1] + 1, candy[i]);//����Ҫ�����ҵĶ�������Ҫȡ���ֵ
	}

	return std::accumulate(candy.begin(), candy.end(), 0);
}