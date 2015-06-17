#include<string>
#include<vector>
#include<sstream>

//题目描述：给定一个字符串表示Unix风格的目录，要求对这个目录进行简化，其中.表示当前目录， ..表示父目录
//解法描述：用一个vector存储遇到的各个目录名称，分情况处理

std::string simplifyPath(std::string path)
{
	std::vector<std::string> dirs; // 当做栈
	for (std::string::iterator i = path.begin(); i != path.end();) 
	{
		++i;  //忽略最开头的/
		std::string::iterator j = find(i, path.end(), '/'); 
		std::string dir = std::string(i, j); // 找到当前目录名
		if (!dir.empty() && dir != ".") // 当有连续'///' 时，dir 为空
		{
			if (dir == "..") //父目录
			{
				if (!dirs.empty())
					dirs.pop_back();
			}
			else
				dirs.push_back(dir);
		}
		i = j;
	}

	std::stringstream out; 
	if (dirs.empty())  //把结果连起来
		out << "/";
	else 
	{
		for (auto dir : dirs)
			out << '/' << dir;
	}
	return out.str();
}