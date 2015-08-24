#include<string>
#include<vector>

//��Ŀ����������һ��ֵn�������ܹ����������ֵģ������У�����n=3�����Բ�����������"((()))", "(()())", "(())()", 
//         "()(())", "()()()"
//�ⷨ�������ݹ���ݷ���ÿ���ȷţ����ٷţ�


void dfs(std::vector<std::string>& result, std::string intermediate, int left, int right, int n)//left��right
                                                                           //��ʾ����ʣ�µĸ���
{
	if (intermediate.size() == n * 2)
	{
		result.push_back(intermediate);
		return;
	}

	if (left && left <= right) //leftһ��ҪС��right���ܷ�
		dfs(result, intermediate + "(", left - 1, right, n);
	if (right && right > left)//rightһ��Ҫ����left���ܷ�
		dfs(result, intermediate + ")", left, right - 1, n);
}


std::vector<std::string> generateParenthesis(int n)
{
	std::vector<std::string> result;
	dfs(result, "", n, n, n);
	return result;
}