//��Ŀ����:����������a��b���������ǵĺͣ�����ֱ��ʹ��+��-
//�ⷨ����:λ����

int getSum(int a, int b) 
{
	while (b != 0)
	{
		int carry = a & b;//����������õ���λ
		a ^= b; //������
		b = carry << 1;
	}
	return a;
}