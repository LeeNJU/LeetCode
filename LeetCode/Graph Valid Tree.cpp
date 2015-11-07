#include<vector>
//��Ŀ����:����һ��ͼ���ж����ͼ�ǲ���һ����
//�ⷨ����:һ��ͼ�ǲ���һ����������û�л������ұ�֤ÿ���㶼�������ġ���union-find��������ÿһ���߽���union
int findRoot(const std::vector<int>& nums, int i) //�ҵ����ڵ�
{
	while (nums[i] != i) 
		i = nums[i];
	return i;
}

bool validTree(int n, std::vector<std::pair<int, int>>& edges) 
{
	std::vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) //��union���г�ʼ��
		nums[i] = i;
	
	for (int i = 0; i < edges.size(); ++i)
	{
		int r1 = findRoot(nums, edges[i].first);//�Ҹ��ڵ�
		int r2 = findRoot(nums, edges[i].second);

		if (r1 == r2) //���ڵ���ȣ�˵���л�
			return false;

		nums[r1] = r2;//���ø��ڵ�
	}

	return edges.size() == n - 1;//����жϱ����ǲ��ǵ���n-1
}