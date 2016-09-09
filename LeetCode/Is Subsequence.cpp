#include<string>
//��Ŀ����:����һ���ַ���s��t��t�ǳ������ж�s�ǲ���t��һ�������У�����s="abc", t="ahbgdc",����true
//�ⷨ����:������ָ��i��jɨ���ַ��������s[i]��t[j]��ȣ���ʾƥ����һ���ַ���i����ƶ��������ƥ�䣬i������j
//        ��������ƶ�����ƥ�����ʱ�����i����ʣ����ַ�����˵�������������������У����i�Ѿ����ڵ���s�ĳ��ȣ�
//        ˵��ƥ�䡣
//follow-up:����кܶ���ַ���s������S1,S2,S3,��Ҫÿ�ζ������������ж���
//�ⷨ����:���ַ���t������������¼ÿ���ַ����±꼯�ϣ�Ȼ�����ÿ��s������s�������е�ÿһ���ַ����ж��ֲ��ң�

bool isSubsequence(std::string s, std::string t) 
{
	int i = 0, j = 0;
	while (j < t.size() && i < s.size())
	{
		if (s[i] == t[j])
			++i;
		++j;
	}

	return i >= s.size();
}

/*
bool isSubsequence(string s, string t) {
	//build a record the index of each char in t
	vector<vector<int>> record(26);
	//add indexs
	for (int i = 0; i < t.size(); i++) {
		record[t[i] - 'a'].push_back(i);
	}
	//check if each char in s is in the legal place
	int index = -1;
	for (int i = 0; i < s.size(); i++) {
		auto iter = upper_bound(record[s[i] - 'a'].begin(), record[s[i] - 'a'].end(), index);
		if (iter == record[s[i] - 'a'].end()) 
			return false;
		index = *iter;
	}
	return true;
}*/