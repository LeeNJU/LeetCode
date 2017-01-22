#include<vector>
#include<string>
//��Ŀ����:����һ���ַ���ֻ����0��9�����֣�����һ��targetֵ��������֮�����+,-����*,ʹ�õõ��ı��ʽ��ֵ����
//        targetֵ������"123", 6 -> ["1+2+3", "1*2*3"] 
//�ⷨ����:�ݹ飬ע��Ҫ��¼��һ����������ֵ�������������ĳ˺ţ���Ҫ��������"012"�����֣����ֿ�����0�����ǲ���
//        ����0��ͷ�����֡�

void dfs(std::vector<std::string>& result, std::string path, std::string num, int target, int index, 
			long cur, long prev)//cur��ʾ���ݹ鵽��ǰ�������ֵ�Ƕ��٣�prev��ʾ��һ���������Ƕ���
{
	if (index == num.size())
	{
		if (cur == target)   
			result.push_back(path);
		return;
	}

	for (int i = index; i < num.size(); ++i)
	{
		if (num[index] == '0' && i > index) //��ֹ����012�����ķǷ�����
			break;

		std::string str = num.substr(index, i - index + 1);
		long value = stol(str); //��ֹ���
		if (index == 0)//ע������
			dfs(result, path + str, num, target, i + 1, value, value);
		else
		{
			dfs(result, path + "+" + str, num, target, i + 1, cur + value, value);
			dfs(result, path + "-" + str, num, target, i + 1, cur - value, -value);//���ŵ��ɸ���
			dfs(result, path + "*" + str, num, target, i + 1, cur - prev + prev * value, prev * value);
		}
	}
}

std::vector<std::string> addOperators(std::string num, int target) 
{
	std::vector<std::string> result;
	if (num.size() == 0)   
		return result;
	dfs(result, "", num, target, 0, 0, 0);
	return result;
}