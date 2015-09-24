//题目描述：给定一个无符号整数，求出这个整数的二进制表示里面有没有连续的1，例如12表示成01100，有连续的1，就不是sparse
//解法描述：n向右移动一位，在和n进行与操作，如果不等于0说明有连续的1，如果等于0说明没有连续的1
bool checkSparse(unsigned n)
{
	if (n & (n >> 1))
		return false;
	return true;
}