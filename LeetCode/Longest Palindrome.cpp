#include<string>
#include<unordered_map>
//��Ŀ����:����һ���ַ����������е��ַ����palindrome���ҵ��ܹ���ɵ����palindrome�ĳ��ȣ�����"abccccdd"��
//        �ܹ���ɵ����palindrome��"dccaccd"��������7
//�ⷨ����:��hashtable��ÿ��Ԫ�صĴ��������ִ�����ż������ֱ�Ӽӵ�length�У�������������ȼ�1��Ȼ��ӵ�length
//        Ҫע�������ĸ������������������������ô���Ľ��Ҫ��1��Ҳ����˵������ַ��ŵ��м�

int longestPalindrome(std::string s) 
{
	std::unordered_map<char, int> map;
	for (char c : s)
		++map[c];

	bool odd = false;//�Ƿ���������ε��ַ�
	auto iter = map.begin();
	int length = 0;
	while (iter != map.end())
	{
		if (iter->second % 2 == 0)
			length += iter->second;
		else
		{
			odd = true;
			length += (iter->second - 1);
		}
		++iter;
	}
	return odd ? length + 1 : length;
}