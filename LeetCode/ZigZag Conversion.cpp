#include<vector>
#include<string>
//��Ŀ����������һ���ַ���s������ת����zigzag�ĸ�ʽ��Ȼ��ÿһ�д������Ҷ����γ�һ���µ��ַ���
//�ⷨ�������ҵ���ѧ���ɣ���ֱԪ�ص�����(i; j) = (j + 1) * n + i��б�Խ�Ԫ��(i; j) = (j + 1) * n + i
std::string convert(std::string s, int numRows)
{
	if (numRows <= 1 || s.size() <= 1) 
		return s;
	
	std::string result;
	for (int i = 0; i < numRows; i++) //i��jΪ���꣬�����Ҫ��ӵ�Ԫ����s�е��±�index����s[index]���뵽result�� 
	{
		for (int j = 0, index = i; index < s.size(); j++, index = (2 * numRows - 2) * j + i) 
		{
			result.append(1, s[index]); // ��ֱԪ��
			if (i == 0 || i == numRows - 1) // б�Խ�Ԫ��
				continue; 
			if (index + (numRows - i - 1) * 2 < s.size())
				result.append(1, s[index + (numRows - i - 1) * 2]);
		}
	}
	return result;
}