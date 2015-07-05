#include<vector>
//����һ���������飬���Ǹ�������ĳһ��λ�ñ���ת�ˣ��ڸ������в���ָ����Ԫ�أ�����array={4,5,6,1,2,3}����2
//�ⷨ�����ַ�,ע��߽磡��������target��A[middle]��A[first]�ıȽϣ���

int search(int A[], int n, int target)
{
	int first = 0, last = n - 1, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (A[middle] == target)
			return middle;
		if (A[middle] >= A[first])//middle����first�Ƚ�
		{
			if (A[middle] > target && target >= A[first])//ȷ��target����middle��߻����ұ�
				last = middle - 1;
			else
				first = middle + 1;
		}
		else
		{
			if (A[middle] < target && target <= A[last])//ȷ��target����middle��߻����ұ�
				first = middle + 1;
			else
				last = middle - 1;
		}
	}
	return -1;
}

//�汾����������ظ�Ԫ����
bool search2(std::vector<int>& nums, int target) 
{
	int left = 0, right = nums.size() - 1, middle  = 0;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (nums[middle] == target)
			return true;
		else if (nums[left] == nums[right]) //������������������ĳ��λ�ñ���ת���⣬�ȱȽ�left��right�Ƿ����
			++left;
		else if (nums[middle] >= nums[left])
		{
			if (target >= nums[left] && nums[middle] > target)
				right = middle - 1;
			else
				left = middle + 1;
		}
		else
		{
			if (target <= nums[right] && target > nums[middle])
				left = middle + 1;
			else
				right = middle - 1;
		}
	}
	return false;
}