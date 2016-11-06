#include<string>
#include<vector>
#include<unordered_set>

//��Ŀ����:����һ���ַ������ַ������飬�жϸ��ַ����ܷ񱻲�ֳ��ַ��������еĵ��ʣ�����s = "leetcode"��
//        dict = "leet", "code"�� ��ôs�ܱ����
//�ⷨ����:��̬�滮 ת�Ʒ���dp[i] = any_of(dp[j]&&s[j + 1; i] ���� dict); 0 <=j < i

bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict)
{
	std::vector<bool> vec(s.size() + 1, false);
	vec[0] = true;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = i; j >= 0; --j)//ע���������������
		{
			if (vec[j] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end())
			{
				vec[i + 1] = true;
				break;
			}
		}
	}
	return vec[s.size()];
}

//���ֶ�
//��Ŀ����������һ���ַ������ַ������飬���ظ��ַ�������ֳ��ַ��������еĵ���
//�ⷨ������ֱ�ӵݹ��������еĽ⣬����Ҫע���֦

void GetAllSolution(int start, const std::string& s, const std::unordered_set<std::string>& dict, 
	int len, std::string& result, std::vector<std::string>& solutions, std::vector<bool>& possible)
{
	if (start == len)
	{
		solutions.push_back(result.substr(0, result.size() - 1));//ȥ�����Ŀո�
		return;
	}

	for (int i = start; i < len; ++i)
	{
		std::string piece = s.substr(start, i - start + 1);
		if (dict.find(piece) != dict.end() && possible[i]) // ������ʣ�������н�ż����ݹ�
		{
			result.append(piece).append(" ");
			int beforeChange = solutions.size();
			GetAllSolution(i + 1, s, dict, len, result, solutions, possible);
			if (solutions.size() == beforeChange) // �ж�ʣ�������Ƿ��н�
				possible[i] = false;
			result.resize(result.size() - piece.size() - 1);
		}
	}
}

std::vector<std::string> wordBreak2(std::string s, std::unordered_set<std::string>& dict) 
{
	std::string result;
	std::vector<std::string> solutions;
	int len = s.size();
	std::vector<bool> possible(len, true); //possible[i]Ϊtrue��ʾ[i, n - 1]�н�
	GetAllSolution(0, s, dict, len, result, solutions, possible);
	return solutions;
}

