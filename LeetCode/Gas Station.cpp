#include<vector>
//题目描述:给定一个数组gas，gas[i]表示第i个加气站中气的含量，再给定一个数组cost，cost[i]表示从i站到i+1站所消
//         耗的气,要求找到加气站的下标，使得汽车可以通过所有的加气站（汽车通过加气站加气的总量要大于消耗的量),
//         返回该加气站的下标，如果没有就返回-1
//解法描述：考虑一下情况：
//a.最开始，站0是始发站，假设车开到p站后油箱空了，sum1=diff[0]+diff[1]+……+diff[p]<0,此时站0，站1一直到站p都
//        不是最终结果
//b.再把p+1站作为始发站，开出q站后油箱又空了，sum2=diff[p+1]+diff[p+2]+……diff[q]<0，同上
//c.再把q+1站作为始发站，假设一直开到结尾，油箱没空，sum3=diff[q+1]+diff[q+2]+……+diff[size-1]>=0
//要想开回q+1站，其实就看sum3加上diff[0]到diff[q]的过程中有没有小于0。看sum3+sum1是否大于0就能知道能否开回p+1
//    站，看sum3+sum1+sum2是否大于0就能知道能否开回q+1

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
	int sum = 0, total = 0, index = -1;//index表示最终的结果
	for (int i = 0; i < gas.size(); ++i)
	{
		sum += (gas[i] - cost[i]);//sum表示当前一段的差值和，用来判断解是否存在于当前一段中
		total += (gas[i] - cost[i]);//始终都要把差值加到total上，total保持总的差值，判断是否有解
		if (sum < 0)//小于0，说明解不在当前一段中
		{
			sum = 0;
			index = i;//index的赋值其实可以用i+1然后取模得到，index = (i + 1) % gas.size(),这样index的初值不用赋值为-1，最后返回时也不用加1了
		}
	}

	return total >= 0 ? index + 1 : -1;
}