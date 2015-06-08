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
//�ⷨ������

