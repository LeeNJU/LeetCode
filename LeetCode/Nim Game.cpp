//题目描述:给定一个数n，代表n个石头，有两个人轮流从中取走1到3个石头，拿走最后一个石头的人获胜，假设a先拿石头，
//        给定n，求a能否获胜
//解法描述:n是4的倍数，先手会输，n不是4的倍数，先手会赢
bool canWinNim(int n) 
{
	return n % 4 != 0;
}