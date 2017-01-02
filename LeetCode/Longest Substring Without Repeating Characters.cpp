#include<string>
#include<unordered_map>
#include<algorithm>

//��Ŀ����������һ���ַ������ҳ���������û���ظ��ַ����Ӵ��ĳ��ȡ�"abcabcbb"����abc,����Ϊ3��"bbbbb"����b������Ϊ1
//�ⷨ������������ָ�룬�ֱ�ָ��ǰ�Ӵ����൱�ڴ��ڣ������ַ������������[i,j]�������Ƿ����ظ�Ԫ��

int lengthOfLongestSubstring(std::string s)
{
	int length = 0;
	std::unordered_map<char, int> map;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (map.find(s[j]) != map.end())
		{
			int index = map[s[j]];
			while (i <= index)
				map.erase(s[i++]);
		}
		map[s[j]] = j;
		length = std::max(length, j - i + 1);
	}
	return length;
}