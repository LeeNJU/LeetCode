#include<string>
#include<unordered_map>
#include<algorithm>

//��Ŀ����������һ���ַ������ҳ���������û���ظ��ַ����Ӵ��ĳ��ȡ�"abcabcbb"����abc,����Ϊ3��"bbbbb"����b������Ϊ1
//�ⷨ������������ָ�룬�ֱ�ָ��ǰ�Ӵ����൱�ڴ��ڣ���hashtable��ʾ�Ӵ��г��ֹ���Ԫ�أ������ǰԪ��û���ظ���j��1������ظ��ˣ��ظ����ֵ�λ��Ϊi����ô
//���ָ���λ��Ϊi+1��ͬʱҪɾȥhashtable�еĲ���Ԫ�أ�ֻ����i+1��j��Ԫ��   bugs

int lengthOfLongestSubstring(std::string s)
{
	int result = 0;
	std::unordered_map<char, int> m;

	for (int i = 0, j = 0; j < s.length();)
	{
		std::unordered_map<char, int>::iterator iter = m.find(s[j]);
		if (iter == m.end())//Ԫ��û���ظ�
		{
			m[s[j]] = j;
			++j;
		}
		else
		{
			int index = iter->second + 1;
			m.erase(m.begin(), );
			i = index;
		}
		result = result > j - i ? result : j - i;
	}

	return result;
}