#include<string>
#include<vector>
//��Ŀ����:����һ�������������������nullָ����#��ʾ������"9,3,4,#,#,1,#,#,2,#,6,#,#",�ж��ǲ�����ȷ������
//�ⷨ����:�ȸ���,����split����¼��������ȵĲ�ǿսڵ��ṩ2�����Ⱥ�һ����ȣ��սڵ��ṩ1����ȣ�����������
//        diff������С��0���������ȷ�����������diff���һ����0
bool isValidSerialization(std::string preorder) 
{
	std::vector<std::string> vec;
	int i = 0, j = 0;
	for (; j < preorder.size(); ++j)//����,����split
	{
		if (preorder[j] == ',')
		{
			vec.push_back(preorder.substr(i, j - i));
			i = j + 1;
		}
	}
	vec.push_back(preorder.substr(i, j - i));

	int diff = 1; //ע������Ҫ��ʼ��Ϊ1����Ϊ���ڵ�
	for (i = 0; i < vec.size(); ++i)
	{
		--diff;
		if (diff < 0)
			return false;
		if (vec[i] != "#")
			diff += 2;
	}
	return diff == 0;
}