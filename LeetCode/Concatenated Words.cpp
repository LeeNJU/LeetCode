#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
//��Ŀ����:����һ���ַ�������(û���ظ�)���ҵ��������е��ַ�����ʹ�ø��ַ����������������������ַ���ƴ�Ӷ��ɣ�����
//        ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"],����
//        ["catsdogcats","dogcatsdog","ratcatdogcat"]����Ϊ"catsdogcats"������"cats","dot"��"cats"��ɣ�
//        Ҫ�󷵻����е��ַ���
//�ⷨ����:��̬�滮��������word break���ȸ����ַ������������ж�ÿһ���ַ�����ʱ�򣬰�֮ǰ�������ַ������뵽
//        hashset��

static int compare(const std::string& s1, const std::string& s2)
{
	return s1.size() < s2.size();
}

bool canForm(const std::string& s, const std::unordered_set<std::string>& set)
{        //�ж�����ַ����Ƿ�����hashset�е��ַ������
	if (s.empty())
		return false;

	std::vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (!dp[j])
				continue;

			std::string str = s.substr(j, i - j + 1);
			if (set.find(str) != set.end())
				dp[i + 1] = dp[i + 1] | dp[j];
			if (dp[i + 1])
				break;
		}
	}

	return dp.back();
}

std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) 
{
	std::sort(words.begin(), words.end(), compare);
	std::unordered_set<std::string> set;

	std::vector<std::string> result;
	for (const std::string& s : words)//ע��������ǵ�ǰԪ�ص�ʱ�򣬲��ܰѵ�ǰԪ�ؼ��뵽hashset��
	{
		if (canForm(s, set))
			result.push_back(s);
		set.insert(s);
	}

	return result;
}