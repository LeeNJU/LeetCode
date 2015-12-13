#include<string>
#include<unordered_map>
//��Ŀ����:����һ���ַ������֣������Щ���ַ�ת180�ȣ��ж��Ƿ��ԭ���������ַ�����ȣ�����"69",��ת180�Ⱥ󣬻���"69"
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