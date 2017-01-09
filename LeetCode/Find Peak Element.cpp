#include <vector>
//��Ŀ����������һ�����飬��������Ԫ�ز��ȣ��ҵ�һ��peak element��ʹ�����������ڵ�����Ԫ�ض��󣬼���n[0]��n[n]�����ڸ�����
//�ⷨ���������ֲ��ң���СpeakԪ�صķ�Χ

int findPeakElement(const std::vector<int>& nums) 
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int middle = (right + left) / 2;
		if (nums[middle] < nums[middle + 1])//˵����middle + 1��right��Χ����peakԪ��
			left = middle + 1;
		else
			right = middle;
	}

	return left;
}


//��Ŀ����:����һ����ά���飬����ĵڶ��е�Ԫ�رȵ�һ�еĴ󣬵����ڶ��е�Ԫ�رȵ�����һ�е�Ԫ�ش󣬵ڶ��е�Ԫ
//        �رȵ�һ�е�Ԫ�ش󣬵����ڶ��е�Ԫ�رȵ�����һ�е�Ԫ�ش�����Ҫ�ҵ�һ��Ԫ�أ�ʹ�����Ԫ�ر�����
//        ����4��Ԫ�ض���,����
//        [
//      	[1, 2, 3, 6, 5],
//      	[16, 41, 23, 22, 6],
//      	[15, 17, 24, 21, 7],
//      	[14, 18, 19, 20, 10],
//      	[13, 14, 11, 10, 9]
//        ]
//�ⷨ����:���н��ж��ֲ��ң��ҵ�middle�е����Ԫ�أ�Ȼ�������ڵ���������Ԫ�ؽ��бȽϣ���������Ԫ�ش���
//        ���ϰ벿�ֱ�Ȼ����һ��peakԪ�أ��������A[middle][x]��A[middle]�е����Ԫ�أ�����A[middle][x - 1]
//        ��A[middle][x]����ô������A[middle]��������Ԫ��A[middle][y]��ʹ�����Ԫ�ر�A[middle][y + 1],
//        A[middle][y - 1]��A[middle + 1][y - 1]Ҫ���������Ǳ�֤�ڶ��е�Ԫ�رȵ�һ�е�Ԫ�ش����һֱ
//        �ƶ�middle�еĻ���һ�������ҵ�peakԪ�أ�ͬ����������Ԫ�ش���ô���°벿��Ҳ��Ȼ����һ��peakԪ��

int findPeak(std::vector<int>& v) 
{
	int res = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > v[res])
			res = i;
	}
	
	return res;
}

std::vector<int> findPeakII(std::vector<std::vector<int>> A) 
{
	std::vector<int> res;
	int left = 0, right = A.size() - 1;
	while (left <= right) 
	{
		int mid = left + ((right - left) >> 1);
		int col = findPeak(A[mid]); //�ҵ���һ�е����Ԫ��
		if (A[mid][col] < A[mid + 1][col]) 
			left = mid + 1;
		else if (A[mid][col] < A[mid - 1][col]) 
			right = mid - 1;
		else 
			return{ mid, col };
	}
	return res;
}