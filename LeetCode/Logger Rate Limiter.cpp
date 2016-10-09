#include<unordered_map>
#include<string>
//题目描述:设计一个logger，接受一个时间点和一个message，判断该message是否该打印，如果该message在10秒内打印过，
//        返回true，如果没有被打印过，返回false
//解法描述:用一个hash表来保存打印过的message，如果该message不存在，返回true，如果该message的时间点与当前时间
//        点的差小于10，也返回true，否则返回false

class Logger 
{
private:
	std::unordered_map<std::string, int> hash;
public:
	Logger() {}

	bool shouldPrintMessage(int timestamp, std::string message)
	{
		if (!hash.count(message)) 
		{
			hash[message] = timestamp;
			return true;
		}

		if (timestamp - hash[message] >= 10) 
		{
			hash[message] = timestamp;
			return true;
		}
		return false;
	}
};