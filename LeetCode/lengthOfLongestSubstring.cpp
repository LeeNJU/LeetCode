#include<string>
#include<unordered_map>
#include<algorithm>

//��Ŀ����������һ���ַ������ҳ���������û���ظ��ַ����Ӵ��ĳ��ȡ�"abcabcbb"����abc,����Ϊ3��"bbbbb"����b������Ϊ1
//�ⷨ������������ָ�룬�ֱ�ָ��ǰ�Ӵ����൱�ڴ��ڣ������ַ������������[i,j]�������Ƿ����ظ�Ԫ��

int lengthOfLongestSubstring(std::string s)
{
	int result = 0;
	for (int i = 0, j = 0; i <= j && j < s.length(); ++j)
	{
		int index = i;
		while (index < j)
		{
			if (s[index] == s[j])
			{
				i = index + 1;
				break;
			}
			++index;
		}
		result = result >= j - i + 1 ? result : j - i + 1;
	}
	return result;
}