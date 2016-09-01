#include<vector>
#include<algorithm>

//��Ŀ����:��n��Ӳ�ң�������������Ӳ�ң�ÿ����ÿ��ֻ����1������2������������Ӳ�ҵ���Ӯ���ʵ�һ���˻᲻��Ӯ
//�ⷨ����:���n��3�ı�������һ����һ�����䣬���򣬵�һ���˻�Ӯ
bool firstWillWin(int n) 
{
	return n % 3 != 0;
}

//��Ŀ����:����n����ͬ��Ӳ�ң�����ѡ������ȡ����ߵ�Ӳ�ң�ÿ��ֻ��ȡһ����������Ӳ�ң�˭��Ӳ��֮������Ӯ�ˡ�
//�ⷨ����:��̬�滮,dp[i]��ʾ��i��n-1�ķ�Χ�ڣ�ѡ����ȡ�õ�����Ӳ�Һͣ����ѡ��ȡvalues[i],��ô���ֿ��ܻ�
//        ѡvalues[i + 1],��ô�����ܵõ������ֵ����dp[i + 2],�������ѡvalues[i + 1]��values[i + 2],��ô
//        �����ܵõ������ֵ��dp[i + 3], ��ˣ�������ֻѡvalues[i]��ʱ����ȡ�õ����ֵ��values[i] + 
//        min(dp[i + 2], dp[i + 3]),ע��������min����Ϊ����ֻ��ʹ��������ѡ��ֵ��С��ͬ��ɵ��������ѡ
//        values[i]��values[i + 1],��ȡ�õ����ֵ��values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4])
//        ����ȡ��󣬾��ǵ�ǰdp[i]��ֵ

bool firstWillWin(std::vector<int>& values)
{
	if (values.size() < 3)
		return true;

	int sum = 0;
	for (int value : values)
		sum += value;

	int n = values.size();
	std::vector<int> dp(n + 1, 0);//ȡn+1����Ϊ�����i + 4
	dp[n - 1] = values[n - 1];
	dp[n - 2] = values[n - 2] + values[n - 1];
	dp[n - 3] = values[n - 3] + values[n - 2];

	for (int i = n - 4; i >= 0; --i)
	{
		int first_choice = values[i] + std::min(dp[i + 2], dp[i + 3]);
		int second_choice = values[i] + values[i + 1] + std::min(dp[i + 3], dp[i + 4]);
		dp[i] = std::max(dp[i], std::max(first_choice, second_choice));
	}

	return dp[0] > sum - dp[0];
}