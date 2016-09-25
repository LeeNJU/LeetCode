#include<vector>
#include<string>
#include<bitset>
//��Ŀ����:�����������֣���һ��Ϊ1��2��4��8,��һ��������ʾСʱ���ڶ���Ϊ1��2��4��8��16��32����һ�б�ʾ���ӣ�
//        ��������n���ӵ�һ����ѡa�����֣��ӵڶ�����ѡb�����֣�ʹ��n = a + b�����һ��ʱ�䣬������е�ʱ�䡣
//        ����n = 1,����["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//�ⷨ����:����λ������ʾСʱ��Ҫ4λ����ʾ������Ҫ6λ��������Ҫ10λ����Ӧ��λ��1����ʾѡ�и����֣�
std::vector<std::string> readBinaryWatch(int num)
{
	std::vector<std::string> result;
	for (int h = 0; h < 12; ++h)
	{
		for (int m = 0; m < 60; ++m)
		{
			if (std::bitset<10>(h << 6 | m).count() == num)//hҪ����6λ
				result.emplace_back(std::to_string(h) + (m < 10 ? ":0" : ":") + std::to_string(m));
		}
	}
	return result;
}