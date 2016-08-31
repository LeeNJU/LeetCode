#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
//��Ŀ����:����һ���ַ������飬�������е�pair�±�(i, j)��ʹ��i�ַ�����j�ַ�������һ����palindrome������
//        ["abcd", "dcba", "lls", "s", "sssll"],��ô����[[0, 1], [1, 0], [3, 2], [2, 4]]
//�ⷨ����:��hash���ÿ��Ԫ�ص��±꣬��ô����ÿ��Ԫ�أ����������е����ַ���������"sssll", ���е�һ���Ӵ���
//        "ss",ʣ�µ��Ӵ���"sll"����ô��ת"sll"�õ�"lls",��hash���в��Ҹ��ַ�����������ַ������ڣ���ô��
//        ���ַ���������ߣ��Ϳ������palindrome��ע�⿼�ǿմ������

bool isPalindrome(std::string& str)
{
	int left = 0, right = str.length() - 1;
	while (left < right)
	{
		if (str[left++] != str[right--])
			return false;
	}

	return true;
}

std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words)
{
	std::vector<std::vector<int>> result;
	if (words.size() == 0 || words.size() < 2)
		return result;

	std::unordered_map<std::string, int> map;
	for (int i = 0; i < words.size(); ++i)//��¼Ԫ���±�
		map[words[i]] = i;

	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words[i].length(); ++j)//�����������ַ���
		{
			std::string str1 = words[i].substr(0, j + 1);
			std::string str2 = words[i].substr(j + 1);

			if (isPalindrome(str1))
			{
				std::string rstr2(str2);
				std::reverse(rstr2.begin(), rstr2.end());//��תʣ�µ��ַ���
				if (map.find(rstr2) != map.end() && map[rstr2] != i)
					result.push_back({ map[rstr2], i });
			}
			if (isPalindrome(str2))
			{
				std::string rstr1(str1);
				std::reverse(rstr1.begin(), rstr1.end());

				if (map.find(rstr1) != map.end() && map[rstr1] != i)
					result.push_back({ map[rstr1], i });
			}
		}
	}

	return result;
}