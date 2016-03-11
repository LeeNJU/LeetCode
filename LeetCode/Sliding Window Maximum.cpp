#include<vector>
#include<deque>
//��Ŀ����������һ�������һ�����ڣ���СΪk���ô������������ƶ�һ���õ�һ���µĴ�СΪk�Ĵ��ڣ���¼ÿ�����ڵ����ֵ
//�ⷨ��������һ��˫�˶��б��滬������Ԫ�أ����ֶ���Ԫ���ǻ��������е����ֵ��ÿ��һ��Ԫ�أ����βԪ�رȽϣ����
//         ��βԪ��С��ɾ����βԪ�أ������ڲ������򣬶����е�Ԫ���ǽ������С�
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
	std::vector<int> res;
	std::deque<int> q;
	for (int i = 0; i < nums.size(); ++i) 
	{
		if (!q.empty() && q.front() == i - k)//�ƶ��������ڣ���������Ԫ�� 
			q.pop_front();
		while (!q.empty() && nums[q.back()] < nums[i]) 
			q.pop_back();
		q.push_back(i);
		if (i >= k - 1) 
			res.push_back(nums[q.front()]);
	}
	return res;
}
