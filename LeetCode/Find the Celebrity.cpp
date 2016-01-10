#include<vector>
//��Ŀ����:����n���ˣ��ֱ���0,1,2...n-1��ʾ��celebrity�Ķ����ǣ������˶���ʶ��������������ʶ�����ˣ��ж���n���������Ƿ�
//        ��celebrity�����û�з���-1������з��ض�Ӧ��label
//�ⷨ����:ÿ��ѡ������a��b,���a��ʶb����ôa�϶�����celebrity�����a����ʶb,��ôb�϶�����celebrity�����ֻʣһ���ˣ���
//        ������ǲ���celebrity

bool knows(int a, int b);

int findCelebrity(int n) 
{
	std::vector<int> candidates(n,0);//��ʼ��
	for (int i = 0; i < n; ++i)
		candidates[i] = i;

	while (candidates.size() >= 2) //ÿ��ȡ������
	{
		int a = candidates.back(); 
		candidates.pop_back();
		int b = candidates.back(); 
		candidates.pop_back();
		if (knows(a, b)) 
			candidates.push_back(b);
		else 
			candidates.push_back(a);
	}

	for (int i = 0; i < n; i++) 
	{
		if (i == candidates[0]) //ѡ���Լ�
			continue;
		if (knows(candidates[0], i) || !knows(i, candidates[0]))
			return -1;
	}
	return candidates[0];
}