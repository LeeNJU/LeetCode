#include<vector>
#include<string>
#include<stack>
#include<algorithm>
//��Ŀ����:����һ���ַ�����ʾ�ļ�֮��Ĳ㼶��ϵ������
//        "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
//        ��ʾ
//        dir
//           subdir1
//              file1.ext
//              subsubdir1
//           subdir2
//              subsubdir2
//                 file2.ext
//        ����\t�ĸ�����ʾ����
//�ⷨ����:��ջ����ʾ�Ӹ�Ŀ¼����ǰĿ¼�����ļ���·�����ȣ�'\t'��ʾ�㼶��ϵ��Ҳ�����ж��ٸ���Ŀ¼���������ļ�
//        ��ʱ��������ȡ�

int lengthLongestPath(std::string input) 
{
	std::vector<std::string> vec;//����'\n'�ָ��ÿ���ļ����ļ���
	int i = 0;
	for (int j = 0; j < input.size(); ++j)
	{
		if (input[j] == '\n')
		{
			vec.push_back(input.substr(i, j - i));
			i = j + 1;
		}
	}
	vec.push_back(input.substr(i));

	std::stack<int> stack;
	stack.push(0);//dummy���ȣ���ֹ����ջΪ�յ����
	int result = 0;
	for (std::string s : vec)
	{
		int level = s.find_last_of('\t') + 1;
		while (level + 1 < stack.size())//��Ϊ��dummy�ڵ㣬����Ҫ��1
			stack.pop();

		int length = stack.top() + s.length() - level + 1;
		stack.push(length);

		if (s.find('.') != std::string::npos)
			result = std::max(result, length - 1);
	}
	return result;
}