//��Ŀ����������һ�����飬ÿ��Ԫ�ر�ʾ�ܹ���ǰ��Ծ�������������ܷ���Ծ�����һ��Ԫ��
//�ⷨ������̰�ģ���¼��ǰԪ���ܹ���Ծ����Զ���룬�ж���Զ�����Ƿ�������鳤��

bool canJump(int A[], int n) //��¼ÿһ���ܹ�ǰ�������maxIndex���ж�maxIndex�Ƿ�������һ��Ԫ��
{
	if (n == 1)
		return true;

	int maxIndex = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if ((A[i] + i) >= maxIndex)
		{
			maxIndex = i + A[i];
		}

		if (maxIndex >= n - 1)
			return true;
		if ((i + 1) > maxIndex)//ѭ��������Ҫ�ж��ܹ�ǰ������һ��index����ΪmaxIndex���С��i + 1�Ļ���˵���޷��ﵽ��һ��index
			return false;
	}
	return false;
}