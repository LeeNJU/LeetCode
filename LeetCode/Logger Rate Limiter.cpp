#include<unordered_map>
#include<string>
//��Ŀ����:���һ��logger������һ��ʱ����һ��message���жϸ�message�Ƿ�ô�ӡ�������message��10���ڴ�ӡ����
//        ����true�����û�б���ӡ��������false
//�ⷨ����:��һ��hash���������ӡ����message�������message�����ڣ�����true�������message��ʱ����뵱ǰʱ��
//        ��Ĳ�С��10��Ҳ����true�����򷵻�false

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