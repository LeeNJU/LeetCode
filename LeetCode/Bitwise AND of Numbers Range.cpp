//��Ŀ����������ֵm��n�����ǷǸ���������[m,n]�����Χ�ڵ���һ�ν��������֮���ֵ
//�ⷨ���������[m,n]�����Χ�����е����Ķ����Ʊ�ʾ�������ͬ�Ĳ��֣�����[26,30],�����Ʊ�ʾΪ11010, 11011, 11100, 11101, 11110���Ϊ11000
//�Ȱ�m��nͬʱ�����ƶ���ֱ��������ȣ���¼�ƶ��Ĵ������ٰ�m�����ƶ���ȵĴ���

int rangeBitwiseAnd(int m, int n)
{
	int count = 0;
	while (m != n)
	{
		m = m >> 1;
		n = n >> 1;
		++count;
	}
	return m << count;
}