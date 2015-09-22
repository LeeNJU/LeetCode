//题目描述:判断你的系统是大端存储integer还是小端存储integer. 例如1的二进制存储为Ox00000001,这是大端存储，小端存储
//        为Ox10000000
//解法描述：用一个unsigned integer 1, 把它的地址转换成char*, 然后解引用，char*解引用只得到第一个字节，如果是大端
//         存储，结果应该是0， 小端存储结果是1

bool isBigEndian()
{
	unsigned int i = 1;
	char *c = (char*) &i;
	if (!*c)
		return true;
	else
		return false;
}