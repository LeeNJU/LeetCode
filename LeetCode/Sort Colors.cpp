#include<vector>
#include<algorithm>
//给定一个数组，包含0,1,2，给数组进行排序，不能使用sort方法
//解法：用双指针，一个指针指向开头，[0,red - 1]表示全是0， 一个指针指向后面，[blue + 1, n - 1]表示全是2， 中间为1，循环整个数组，把2往后交换，把0往前交换，复杂度为O(n)
//注意：交换两个元素之后，不能进行++i，因为交换后的元素可能相同
void sortColors(int A[], int n)
{
	int red = 0, blue = n - 1;
	for (int i = 0; i < blue + 1;)//i的范围只需要到blue+1即可
	{
		if (A[i] == 2)
			std::swap(A[i], A[blue--]);
		else if (A[i] == 0)
			std::swap(A[i++], A[red++]);//！！！注意这里A[i++]
		else
			++i;
	}
}


//题目描述:假设有k个颜色，进行排序
//解法描述:依次排列每种颜色，例如先保证所有的1在左边，然后是所有的2，以此类推。
void sortColors2(std::vector<int> &colors, int k) 
{
	int index = -1;
	for (int i = 0; i < k; ++i)
	{
		int number = i + 1;
		for (int j = index + 1; j < colors.size(); ++j)
		{
			if (colors[j] == number)
				std::swap(colors[++index], colors[j]);
		}
	}
}

//
/*
void sortColors2(std::vector<int>& colors, int k) 
{
	int left = -1, right = colors.size();
        int color1 = 1, color2 = k;
        
        while(color1 < color2 && left < right)
        {
            for(int i = left + 1; i < right; )
            {
                if(colors[i] == color2)
					swap(colors[i], colors[--right]);
                else if(colors[i] == color1)
					swap(colors[i++], colors[++left]);
                else
					++i;
            }
            ++color1;
            --color2;
        }
}
*/