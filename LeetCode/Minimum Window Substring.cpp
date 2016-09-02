#include<vector>
#include<unordered_map>
#include<algorithm>

//��Ŀ����:���������ַ���s��t����s���ҵ���С�ĳ��ȵ��Ӵ���ʹ���Ӵ�����t�������ַ�������s="ADOBECODEBANC"��
//         t="ABC"�����Ϊ"BANC"
//�ⷨ����:����Ҫ���ǵ�����ܶ࣡����1��hashtable�����ַ���t���ֵ�Ԫ���Լ�����������i��j����ָ��ά��һ��С��
//        �䣬��j�����ַ���s����hashtable��¼���ֵ�Ԫ���Լ�������ͬʱ��count��¼�ܹ������˶��ٸ�t�е�Ԫ�أ�
//        ����Ҫע���ظ���Ԫ�أ�������ע�ͣ�����i��j�������������t��ʱ�򣬴�i��ʼ��������ͼ����i��ʹ�ó�����
//        С�����൱���ҵ���һ���⣬��¼��������С�Ľ⣬Ȼ�������j�����ַ���s

std::string minWindow(std::string s, std::string t)
{
	if (s.size() < t.size())
		return "";

	int min_length = INT_MAX; //����������С���Ⱥ���Ӧ����ʼ�±�
	int min_start = 0;
	std::unordered_map<char, int> appeared_count;
	std::unordered_map<char, int> expected_count;//����Ϊ�˷�ֹt�����ظ�Ԫ�أ������¼ÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < t.size(); ++i)
		++expected_count[t[i]];
	
	int count = 0;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (expected_count.count(s[j]) > 0)//��t�а�����ǰԪ��
		{
			++appeared_count[s[j]];//��¼���ִ���
			if (appeared_count[s[j]] <= expected_count[s[j]])//��ֹ���ڵ��ظ����֣�����s="AAA", t="A",��ô��������һ��
				++count;
		}

		if (count == t.size())//����������t
		{
			while (expected_count.count(s[i]) == 0 || appeared_count[s[i]] > expected_count[s[i]])//ѭ�������󣬴������һ����
			{
				--appeared_count[s[i]];
				++i;
			}
			if (j - i + 1 < min_length)//�����ǰ����ţ�����
			{
				min_length = j - i + 1;
				min_start = i;
			}
		}
	}

	if (min_length == INT_MAX)
		return "";
	return s.substr(min_start, min_length);
}