#include<vector>
//��Ŀ����������һ������n��������˹�������εĵ�n��
//�ⷨ����������generate�������Բ�����˹������������һ�У�������һ�е�ֵ��������һ�е�ֵ��Ϊ�˽�ʡ�ռ䣬ֻ����һ�е�ֵ����һ�еļ�����ֱ�Ӹ����ڵ�ǰ
//�����ϣ����ڴ������Ҽ���Ḳ����һ�е�ֵ�����Ըĳɴ���������㣬���Ḳ����һ�е�ֵ

std::vector<int> getRow(int rowIndex)
{
	std::vector<int> result;
	for (int i = 0; i <= rowIndex; i++) 
	{
		for (int j = i - 1; j > 0; j--)
		{
			result[j] = result[j - 1] + result[j];
		}
		result.push_back(1);//����ÿһ��ĩβ��1�� ��i=0��1��ʱ�򣬸��д�������һ�к͵ڶ��е�1
	}
	return result;
}
