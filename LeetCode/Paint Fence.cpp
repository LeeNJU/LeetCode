//��Ŀ����:��k����ɫ����n�����ӽ���Ϳɫ������������ڸ��ӵ���ɫ������ͬ�����ܹ��ж�����Ϳ��
//�ⷨ����:S[i]��ʾ��i���������i - 1��������ɫ��ͬ���ж�����Ϳ����D[i]��ʾ��i���������i - 1��������ɫ��ͬ���ж�����
//        Ϳ������ôS[i] = D[i - 1],D[i] = (k - 1) * D[i - 1] + S[i],����ֻ�õ�ǰһ��������ֵ�����Կ���ֻ����������
int numWays(int n, int k) 
{
	if (n == 0 || k == 0)
		return 0;
	if (n == 1)
		return k;

	int lastD = k * (k - 1);
	int lastS = k;
	for (int i = 2; i < n; i++) 
	{
		int tempD = (k - 1) * (lastD + lastS);//lastD + lastS����һ���ܹ���Ϳ��
		lastS = lastD;
		lastD = tempD;
	}

	return lastS + lastD;
}