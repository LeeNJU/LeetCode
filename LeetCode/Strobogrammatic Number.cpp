#include<string>
#include<vector>
#include<unordered_map>
//��Ŀ����:����һ���ַ������֣������Щ���ַ�ת180�ȣ��ж��Ƿ��ԭ���������ַ�����ȣ�����"69",��ת180�Ⱥ�
//        ����"69"
//�ⷨ����:����ָ�����м��ߣ����߷�ת֮��������
bool isStrobogrammatic(std::string num) 
{
	std::unordered_map<char, char> m;
	m['0'] = '0';//ֻ����Щ�ַ���ת180�Ⱥ���һ������
	m['1'] = '1';
	m['6'] = '9';
	m['8'] = '8';
	m['9'] = '6';

	for (int i = 0, j = num.length() - 1; i <= j; ++i, --j)
	{
		if (m.find(num[i]) == m.end() || m[num[i]] != num[j])//�����ǰ�ַ�����map����������Ҳ���
			return false;
	}
	return true;
}

//version2
//��Ŀ����:����һ��n���ҵ����г���Ϊn��strobogramatic�ַ���,����n=2������["11","69","88","96"]
std::vector<std::string> findStrobogrammatic(int n) 
{
	std::vector<std::string> strobos;
	if (n % 2 == 1)//���� 
		strobos = { "0", "1", "8" };
	else //ż��
		strobos = { "" };
	std::vector<std::string> bases = { "00", "11", "88", "69", "96" };
	int m = bases.size();
	while (n > 1) 
	{
		n -= 2;
		std::vector<std::string> temp;
		for (std::string strobo : strobos)
		{
			for (int i = (n < 2 ? 1 : 0); i < m; i++)//ÿ�ΰ�base�е��ַ����ӵ���ʼ�ͽ�β
				temp.push_back(bases[i].substr(0, 1) + strobo + bases[i].substr(1));
		}
		swap(temp, strobos);//����temp��ʵ�ֵݹ�
	}
	return strobos;
}

//version 3
//��Ŀ����:����һ��range��low��high���ҵ�������low<=num<=high��Strobogrammatic Number
//�ⷨ����:������һ�⣬�ڲ�����ʱ��Ҫ�ж��ǲ�����range֮��
bool compare(std::string s1, std::string s2) 
{
	if (s1.length() != s2.length())
		return s1.length() <= s2.length();

	for (int i = 0; i < s1.length(); i++) 
	{
		if (s1[i] < s2[i]) 
			return true;
		else if (s1[i] > s2[i]) 
			return false;
	}

	return true;
}

int strobogrammaticInRange(const std::vector<std::pair<char, char>>& nums, const std::string& low, const std::string& high, std::string t, int count) 
{
	if (high.length() < t.length())
		return count;
	if (compare(low, t) && compare(t, high))
	{
		if (t.length() == 1 || t.length() > 1 && t.front() != '0')
			++count;
	}

	for (auto iter = nums.begin(); iter != nums.end(); ++iter)
		count = strobogrammaticInRange(nums, low, high, std::string(1, iter->first) + t + std::string(1, iter->second), count);

	return count;
}

int strobogrammaticInRange(std::string low, std::string high) 
{
	if (!compare(low, high)) 
		return 0;

	std::vector<std::pair<char, char>> nums = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };

	int count = strobogrammaticInRange(nums, low, high, "", 0);
	count = strobogrammaticInRange(nums, low, high, "0", count);
	count = strobogrammaticInRange(nums, low, high, "1", count);
	count = strobogrammaticInRange(nums, low, high, "8", count);

	return count;