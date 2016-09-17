#include<string>
#include<unordered_map>
#include<algorithm>
//��Ŀ����:����һ���ַ�����kֵ���ҵ�������ַ�����ʹ�����ַ����е�ÿ���ַ����ִ������ڵ���k������
//        "aaabb", k = 3,����3��"ababbc", k = 2������5
//�ⷨ����:�ݹ飬�Ե�ǰ�ַ�����ͳ��ÿ���ַ��ĳ��ִ��������ÿ���ַ����ִ��������ڵ���k����ôֱ�ӷ����ַ������ȣ�
//        ������ַ��Ĵ���С��k������Щ�ַ��������ַ������ֳ�С���ַ�������ô���Ž��Ȼ��������ЩС�ַ����У�
//        Ȼ�����ЩС�ַ����ݹ���á�

int longestSubstring(std::string s, int k) 
{
	std::unordered_map<char, int> map;
	for (char c : s)  //ͳ���ַ�����
		++map[c];

	bool exist = true;
	auto iter = map.begin();
	while (iter != map.end())//�ж��Ƿ�ÿ���ַ��Ĵ��������ڵ���k
	{
		if (iter->second < k)
		{
			exist = false;
			break;
		}
		++iter;
	}

	if (exist)
		return s.size();
	
	int result = 0;
	int i = 0, j = 0;
	for (; j < s.size(); ++j)
	{
		if (map[s[j]] < k) //�Ҵ�һ������С��k���ַ����Դ������������ַ���
		{
			result = std::max(result, longestSubstring(s.substr(i, j - i), k));
			i = j + 1;
		}
	}
	result = std::max(result, longestSubstring(s.substr(i, j - i), k));//ע�������β���ַ���
	return result;
}