#include<string>
#include<algorithm>
#include<unordered_map>
//��Ŀ����:����һ���ַ������ҵ�����Ӵ���ʹ����������������ͬ���ַ�������"eceba",����Ӵ���"ece"
//�ⷨ����:��hash�����ַ����ֵĴ�������hash���С����2��ʱ��ɾ����ߵ�Ԫ�أ�ɾ����ʱ��ֻ�е�����ַ�
//        ���ִ���Ϊ1��ʱ�����ɾ����

int lengthOfLongestSubstringTwoDistinct(std::string s)
{
	int result = 0, left = 0;
	std::unordered_map<char, int> m;
	for (int i = 0; i < s.size(); ++i)
	{
		++m[s[i]];
		while (m.size() > 2)
		{
			if (--m[s[left]] == 0)//���ִ���Ϊ1����hash����ɾ���������Ϊ1��ֻ�ܼ����ƶ�left 
				m.erase(s[left]);
			++left;
		}
		result = std::max(result, i - left + 1);
	}
	return result;
}