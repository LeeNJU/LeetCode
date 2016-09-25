#include<vector>
#include<string>
#include<bitset>
//题目描述:给定两行数字，第一行为1，2，4，8,这一行用来表示小时，第二行为1，2，4，8，16，32，这一行表示分钟，
//        给定数字n，从第一行挑选a个数字，从第二行挑选b个数字，使得n = a + b，组成一个时间，求出所有的时间。
//        例如n = 1,返回["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//解法描述:利用位集，表示小时需要4位，表示分钟需要6位，所以需要10位，对应的位是1，表示选中该数字，
std::vector<std::string> readBinaryWatch(int num)
{
	std::vector<std::string> result;
	for (int h = 0; h < 12; ++h)
	{
		for (int m = 0; m < 60; ++m)
		{
			if (std::bitset<10>(h << 6 | m).count() == num)//h要左疑6位
				result.emplace_back(std::to_string(h) + (m < 10 ? ":0" : ":") + std::to_string(m));
		}
	}
	return result;
}