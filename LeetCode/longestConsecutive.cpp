#include<vector>
#include<unordered_map>
#include<algorithm>
//��Ŀ����������һ���������飬�ҵ�����������ֵĳ��ȣ�����{100, 4, 200, 1, 3, 2},�����������Ϊ{1, 2, 3, 4}.����Ϊ4
//�ⷨ��������hashtable��ʾÿ�������Ƿ�ʹ�ù������������е�ÿ�����֣��ֱ���������ҽ������ţ���1�ͼ�1�����ж������ڵ�Ԫ���Ƿ��������У�����������У�
//����Ϊ�Ѿ�ʹ�ù����´�ɨ�赽���Ԫ��ʱ�Ͳ���ɨ����

int longestConsecutive(std::vector<int> &num)
{
	std::unordered_map<int, bool> used;
	for (auto i : num)//��ʼ��
		used[i] = false;

	int longest = 0;
	for (auto i : num)
	{
		if (used[i])//��������ǰ���Ѿ���ʹ�ù������в�����ʹ���ˣ���ʡ
			continue;

		int length = 1;
		used[i] = true;

		for (int j = i + 1; used.find(j) != used.end(); ++j) {//�������ţ����μ�1���ж��Ƿ����������
			used[j] = true;
			++length;
		}
		for (int j = i - 1; used.find(j) != used.end(); --j) {//�������ţ����μ�1,
			used[j] = true;
			++length;
		}
		longest = std::max(longest, length);
	}
	return longest;
}