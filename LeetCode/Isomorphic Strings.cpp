#include<string>
#include<unordered_map>

//��Ŀ����:���������ַ������ж������ǲ���isomorphic�ģ�����paper���Ա�title�滻������true��egg���Ա�add�滻
//        ����true
//�ⷨ����:��hashtable����s��t��ӳ���ϵ�����s�ǲ���ӳ�䵽t���ټ��t�ǲ���ӳ�䵽s

bool isIsomorphic(std::string s, std::string t)
{
	if (s.length() != t.length())
		return false;

	std::unordered_map<char, char> mp;
	for (int i = 0; i < s.length(); ++i) 
	{
		if (mp.find(s[i]) == mp.end()) //������s[i]��t[i]��ӳ��
			mp[s[i]] = t[i];
		else if (mp[s[i]] != t[i]) //�жϵ�ǰs[i]�ǲ���ӳ�䵽t[i]
			return false;
	}

	mp.clear();//���������t�ǲ���ӳ�䵽s����Ϊ����s�еĶ��Ԫ��ӳ�䵽t�е�ͬһ��Ԫ�أ�����Ҫ���t�ǲ���ӳ�䵽s
	for (int i = 0; i < s.length(); ++i) //����paher��title��p��hͬʱӳ�䵽t
	{
		if (mp.find(t[i]) == mp.end()) 
			mp[t[i]] = s[i];
		else if (mp[t[i]] != s[i]) 
			return false;
	}
	return true;
}