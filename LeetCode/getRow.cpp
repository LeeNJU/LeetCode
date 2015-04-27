#include<vector>
//题目描述：给定一个整数n，返回帕斯卡三角形的第n行
//解法描述：根据generate方法可以产生帕斯卡三角形任意一行，保存上一行的值来计算下一行的值，为了节省空间，只保存一行的值，下一行的计算结果直接覆盖在当前
//数组上，由于从左往右计算会覆盖上一行的值，所以改成从右往左计算，不会覆盖上一行的值

std::vector<int> getRow(int rowIndex)
{
	std::vector<int> result;
	for (int i = 0; i <= rowIndex; i++) 
	{
		for (int j = i - 1; j > 0; j--)
		{
			result[j] = result[j - 1] + result[j];
		}
		result.push_back(1);//加入每一行末尾的1， 当i=0和1的时候，该行代码加入第一行和第二行的1
	}
	return result;
}
