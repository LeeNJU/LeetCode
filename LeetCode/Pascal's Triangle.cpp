#include<vector>
//��Ŀ����������һ������n��������Ӧ����˹��������
//�ⷨ�������õ���һ�е�ֵ��һ�μ�����һ�е�ֵ

std::vector<std::vector<int> > generate(int numRows)
{
	std::vector<std::vector<int>> result;
	if (numRows == 0) 
		return result;
	result.push_back(std::vector<int>(1, 1)); //first row
	
	for (int i = 2; i <= numRows; ++i) 
	{
		std::vector<int> current(i, 1); // ����
		const std::vector<int> &prev = result[i - 2]; // ��һ��
		for (int j = 1; j < i - 1; ++j) 
			current[j] = prev[j - 1] + prev[j]; // ���ϽǺ����Ͻ�֮��
		result.push_back(current);
	}
	return result;
}


//��Ŀ����:����һ������n��������˹�������εĵ�n��
//�ⷨ����:����generate�������Բ�����˹������������һ�У�������һ�е�ֵ��������һ�е�ֵ��Ϊ�˽�ʡ�ռ䣬ֻ��
//        ��һ�е�ֵ����һ�еļ�����ֱ�Ӹ����ڵ�ǰ�����ϣ����ڴ������Ҽ���Ḳ����һ�е�ֵ�����Ըĳɴ�����
//        ����㣬���Ḳ����һ�е�ֵ

std::vector<int> getRow(int rowIndex)
{
	std::vector<int> result;
	for (int i = 0; i <= rowIndex; i++)
	{
		for (int j = i - 1; j > 0; j--)
			result[j] = result[j - 1] + result[j];
		result.push_back(1);//����ÿһ��ĩβ��1�� ��i=0��1��ʱ�򣬸��д�������һ�к͵ڶ��е�1
	}
	return result;
}

