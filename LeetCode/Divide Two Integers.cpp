#include<string>

//��Ŀ�����������������������г��������������ó˷���������ȡģ����
//�ⷨ�������ų�һЩ���������ת����long���ͷ�ֹ��������г����������divisor�����ƶ�nλ��ʹ��divisorС�ڵ���dividend���൱��divisor��2��n�η�
//divident��ȥdivisor��Ȼ�����ƶ�divisor aλ��ֱ��divisorС�ڵ���divident���൱��divisor��2��a�η���...����Щ���������ǽ����ע���жϽ�������

int divide(int dividend, int divisor)
{
	if (divisor == 1)  //�ų��������
		return dividend;
	if (dividend == 0)
		return 0;

	int flag = 1;
	if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) //�жϽ���ķ���
		flag = -1;

	long divide = static_cast<long>(dividend);  //ǿ������ת������ֹ��������г������
	long divis = static_cast<long>(divisor);
	divide = abs(divide); // ת��������
	divis = abs(divis);

	int result = 0;
	while (divide >= divis)
	{
		int count = 1;
		long temp = divis;
		while ((temp <<= 1) <= divide) //temp�������ƶ�
		{
			count = count << 1; //count�����ƶ�����¼
		}
		result += count;
		divide -= (temp >> 1);
	}
	if (result < 0)  //�жϽ���Ƿ����
		return INT_MAX;
	return flag * result;
}