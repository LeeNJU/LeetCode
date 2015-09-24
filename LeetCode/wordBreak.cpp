#include<string>
#include<vector>
#include<unordered_set>
//��Ŀ����������һ���ַ������ַ������飬�жϸ��ַ����ܷ񱻲�ֳ��ַ��������еĵ��ʣ�����s = "leetcode"�� dict = "leet", "code"�� ��ôs�ܱ����
//�ⷨ��������̬�滮 ת�Ʒ���vec[i] = any_of(vec[j]&&s[j + 1; i] ���� dict); 0 <=j < i

bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict)
{
	std::vector<bool> vec(s.size() + 1, false);
	vec[0] = true;
	for (int i = 1; i <= s.size(); ++i) 
	{
		for (int j = i - 1; j >= 0; --j)//ע���������������
		{
			if (vec[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) 
			{
				vec[i] = true;
				break;
			}
		}
	}
	return vec[s.size()];
}

//���ֶ�
//��Ŀ����������һ���ַ������ַ������飬���ظ��ַ�������ֳ��ַ��������еĵ���
//�ⷨ������ͨ����̬�滮�ҵ����еĽ⣬���õݹ��������еĽ�

void gen_path(const std::string &s, const std::vector<std::vector<bool>>& prev,
	int cur, std::vector<std::string>& path, std::vector<std::string>& result) 
{
	if (cur == 0) 
	{
		std::string tmp;
		for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
			tmp += *iter + " ";
		tmp.erase(tmp.end() - 1);
		result.push_back(tmp);
	}
	for (int i = 0; i < s.length(); ++i) 
	{
		if (prev[cur][i]) 
		{
			path.push_back(s.substr(i, cur - i));
			gen_path(s, prev, i, path, result);
			path.pop_back();
		}
	}
}

std::vector<std::string> wordBreak2(std::string s, std::unordered_set<std::string>& dict) 
{
	// ����Ϊn ���ַ�����n+1 ������
	std::vector<bool> f(s.length() + 1, false);
	// path[i][j] Ϊtrue����ʾs[j, i) ��һ���Ϸ����ʣ����Դ�j ���п�
	// ��һ��δ��
	std::vector<std::vector<bool>> prev(s.length() + 1, std::vector<bool>(s.length()));
	f[0] = true;
	for (int i = 1; i <= s.length(); ++i) 
	{
		for (int j = i - 1; j >= 0; --j) 
		{
			if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) 
			{
				f[i] = true;
				prev[i][j] = true;
			}
		}
	}
	std::vector<std::string> result;
	std::vector<std::string> path;
	gen_path(s, prev, s.length(), path, result);
	return result;
}