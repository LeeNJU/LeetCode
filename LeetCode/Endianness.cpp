//��Ŀ����:�ж����ϵͳ�Ǵ�˴洢integer����С�˴洢integer. ����1�Ķ����ƴ洢ΪOx00000001,���Ǵ�˴洢��С�˴洢
//        ΪOx10000000
//�ⷨ��������һ��unsigned integer 1, �����ĵ�ַת����char*, Ȼ������ã�char*������ֻ�õ���һ���ֽڣ�����Ǵ��
//         �洢�����Ӧ����0�� С�˴洢�����1

bool isBigEndian()
{
	unsigned int i = 1;
	char *c = (char*) &i;
	if (!*c)
		return true;
	else
		return false;
}