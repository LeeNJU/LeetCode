#include <vector>
//题目描述:给定一个已序数组和a,b,c三个值，对数组中的每一个元素进行如下变换:y=ax^2+bx+c,然后从小到达返回结果。
//解法描述:首尾两个指针，根据抛物线的方程，如果a>0，则两端的值比中间的大，则从后往前放入结果数组，如果a<0,中间的值比
//                两端的大，那么从前往后放入结果数组，如果a=0，可以被a>0的情况结合。

int cal(int x, int a, int b, int c) 
{
    return a * x * x + b * x + c;
}

std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c) 
{
    int n = nums.size();
    int i = 0, j = n - 1;
    std::vector<int> res(n);
    int index = a >= 0 ? n - 1 : 0;
    while (i <= j) 
    {
            if (a >= 0) 
                res[index--] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c) ? cal(nums[i++], a, b, c) : cal(nums[j--], a, b, c);
            else 
                res[index++] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c) ? cal(nums[j--], a, b, c) : cal(nums[i++], a, b, c);
    }
    return res;
}
