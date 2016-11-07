#include<vector>
#include<string>
//��Ŀ����:����һ���ַ������飬�ж����ǲ���valid square,��i�к͵�i�б�����ȣ�����
//       [
//        "abcd",
//        "bnrt",
//        "crmy",
//        "dtye"
//       ]
//�ⷨ����:�ö�ά��������ǶԳƵģ��ӵ�i�п�ʼ��ɨ���i�У�ȷ��words[i][j] == words[j][i],Ҫע���±�ķ�Χ��
//        �����±��ǺϷ���

bool validWordSquare(std::vector<std::string>& words) 
{
	for (int i = 0; i < words.size(); ++i) 
	{
		for (int j = 0; j < words[i].size(); ++j) 
		{
			if (j >= words.size() || words[j].size() <= i || words[j][i] != words[i][j])
				return false;
		}
	}
	return true;
}