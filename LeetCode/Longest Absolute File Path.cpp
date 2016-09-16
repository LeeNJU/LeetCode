#include<vector>
#include<string>
#include<stack>
#include<algorithm>
//题目描述:给定一个字符串表示文件之间的层级关系，例如
//        "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
//        表示
//        dir
//           subdir1
//              file1.ext
//              subsubdir1
//           subdir2
//              subsubdir2
//                 file2.ext
//        其中\t的个数表示层数
//解法描述:用栈，表示从根目录到当前目录或者文件的路径长度，'\t'表示层级关系，也就是有多少个父目录，当碰到文件
//        的时候，算出长度。

int lengthLongestPath(std::string input) 
{
	std::vector<std::string> vec;//根据'\n'分割出每个文件和文件夹
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
	stack.push(0);//dummy长度，防止处理栈为空的情况
	int result = 0;
	for (std::string s : vec)
	{
		int level = s.find_last_of('\t') + 1;
		while (level + 1 < stack.size())//因为有dummy节点，所以要加1
			stack.pop();

		int length = stack.top() + s.length() - level + 1;
		stack.push(length);

		if (s.find('.') != std::string::npos)
			result = std::max(result, length - 1);
	}
	return result;
}