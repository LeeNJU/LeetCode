#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
//��Ŀ����:����һ���ַ���p��s��s="...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...",s��
//        ���޳��ģ�Ҫ��p���ж��ٸ�Ψһ�����ַ���Ҳ��s�����ַ���������p="zab"���ܹ���6�����ַ�����"z", 
//        "a", "b", "za", "ab", "zab",��6�����ַ�������s�����ַ���
//�ⷨ����:���ַ��������������Ĳ���s�����ַ���������ֻ��Ҫ��עp���������������ַ�������һ������ֱ��¼��a��b
//        c,d,..,ÿ���ַ������������������ַ����ĳ��ȣ�����"cdabcd"����dΪ�������������������ַ����ĳ�����4��
//        Ȼ���������ͼ���

int findSubstringInWraproundString(std::string p) 
{
	std::vector<int> count(26, 0);
	int maxLengthCur = 0;

	for (int i = 0; i < p.length(); ++i) 
	{
		if (i > 0 && (p[i] - p[i - 1] == 1 || (p[i - 1] - p[i] == 25))) 
			++maxLengthCur;
		else 
			maxLengthCur = 1;

		int index = p[i] - 'a';
		count[index] = std::max(count[index], maxLengthCur);
	}

	return std::accumulate(count.begin(), count.end(), 0);
}