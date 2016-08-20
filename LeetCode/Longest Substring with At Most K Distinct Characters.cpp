#include<string>
#include<unordered_map>
#include<algorithm>
//��Ŀ����:����һ���ַ�����һ��kֵ���ҵ�����Ӵ���ʹ���Ӵ�������k����ͬ���ַ�������:"eceba",k=2,��İ�
//        ��k���ַ����Ӵ���"ece"
//�ⷨ����:��hash�����ַ��Լ����ִ�������hash��Ĵ�С����k��ʱ��ɾ����ߵ��ַ���ʹ��hash���СС��k
int lengthOfLongestSubstringKDistinct(std::string s, int k) 
{
	int result = 0, left = 0;
	std::unordered_map<char, int> m;
	for (int i = 0; i < s.size(); ++i) 
	{
		++m[s[i]];
		while (m.size() > k) 
		{
			if (--m[s[left]] == 0)//���ִ���Ϊ1����hash����ɾ���������Ϊ1��ֻ�ܼ����ƶ�left 
				m.erase(s[left]);
			++left;
		}
		result = std::max(result, i - left + 1);
	}
	return result;
}