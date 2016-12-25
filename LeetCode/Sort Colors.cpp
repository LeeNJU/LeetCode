#include<vector>
#include<algorithm>
//����һ�����飬����0,1,2��������������򣬲���ʹ��sort����
//�ⷨ����˫ָ�룬һ��ָ��ָ��ͷ��[0,red - 1]��ʾȫ��0�� һ��ָ��ָ����棬[blue + 1, n - 1]��ʾȫ��2�� �м�Ϊ1��ѭ���������飬��2���󽻻�����0��ǰ���������Ӷ�ΪO(n)
//ע�⣺��������Ԫ��֮�󣬲��ܽ���++i����Ϊ�������Ԫ�ؿ�����ͬ
void sortColors(int A[], int n)
{
	int red = 0, blue = n - 1;
	for (int i = 0; i < blue + 1;)//i�ķ�Χֻ��Ҫ��blue+1����
	{
		if (A[i] == 2)
			std::swap(A[i], A[blue--]);
		else if (A[i] == 0)
			std::swap(A[i++], A[red++]);//������ע������A[i++]
		else
			++i;
	}
}


//��Ŀ����:������k����ɫ����������
//�ⷨ����:��������ÿ����ɫ�������ȱ�֤���е�1����ߣ�Ȼ�������е�2���Դ����ơ�
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