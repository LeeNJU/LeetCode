#include<string>
#include<vector>
#include<sstream>

//��Ŀ����������һ���ַ�����ʾUnix����Ŀ¼��Ҫ������Ŀ¼���м򻯣�����.��ʾ��ǰĿ¼�� ..��ʾ��Ŀ¼
//�ⷨ��������һ��vector�洢�����ĸ���Ŀ¼���ƣ����������

std::string simplifyPath(std::string path)
{
	std::vector<std::string> dirs; // ����ջ
	for (std::string::iterator i = path.begin(); i != path.end();) 
	{
		++i;  //�����ͷ��/
		std::string::iterator j = find(i, path.end(), '/'); 
		std::string dir = std::string(i, j); // �ҵ���ǰĿ¼��
		if (!dir.empty() && dir != ".") // ��������'///' ʱ��dir Ϊ��
		{
			if (dir == "..") //��Ŀ¼
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
	if (dirs.empty())  //�ѽ��������
		out << "/";
	else 
	{
		for (auto dir : dirs)
			out << '/' << dir;
	}
	return out.str();
}