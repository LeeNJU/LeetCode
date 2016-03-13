#include<vector>
#include<algorithm>
#include<limits.h>
#include<numeric>
//��Ŀ����:����һ�������һ��kֵ����ʾ��ӡÿ�����ʱ�䣬���ڰ���Щ��ָ�k����ȥ��ӡ��ÿ���˷ֵ������ļ����飬
//        ��ӡ��ʱ��Ϊÿ����ĸ�ӡʱ��ĺ͡�����Ҫ��ӡ������ʱ��
//�ⷨ����:��̬�滮��dp[i][j]��ʾ���±�0��j����ָ�i����ȥ��ӡ�����ʱ�䡣dp[i][j] = min(dp[i - 1][j - 1],
//        m),m��ʾ�ѵ�j��Ԫ�ؼ���֮������Ž⡣ͨ����Ҫ��һ��ѭ�����ҵ�������Ž⡣���ǿ��Խ����Ż���

int copyBooks(std::vector<int>& pages, int k) 
{
	int n = pages.size();
	k = std::min(n, k); //k����Զ����n
	std::vector<int> sum_from_start(n, 0);//sum_from_start[i]��ʾ������±�0��i�ĺ�
	partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
	std::vector<std::vector<int> > minutes(k + 1, std::vector<int>(n, INT_MAX));
	
	for (int i = 0; i < n; ++i) //��ʼ��
		minutes[1][i] = sum_from_start[i];
	
	for (int i = 2; i <= k; i++) 
	{
		minutes[i][0] = sum_from_start[1];
		int left = 0, right = 1;
		while (right < n) 
		{
			int curr = sum_from_start[right] - sum_from_start[left];
			minutes[i][right] = std::min(std::max(curr, minutes[i - 1][left]), minutes[i][right]);
			if (left < right && minutes[i - 1][left] < curr)//�������ܵ�left���ҵ���ǰ�����Ž�
				++left;
			else 
			{
				++right;//��ǰ���Ž��ҵ���right�����ƶ�
				if (left > 0) 
					--left;
			}
		}
	}
	return minutes[k][n - 1];
}
