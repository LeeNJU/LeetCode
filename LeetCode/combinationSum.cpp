#include<vector>
#include<algorithm>
//��Ŀ����������һ�������һ��ֵtarget�����������ҵ���Ϊtarget��������ϣ�����ÿһ��Ԫ�ؿ��Ա�ʹ�������Σ�����{2,3,
//         6,7}���Һ�Ϊ7����ϣ���Ϊ{7}��{2,2,3}
//�ⷨ���ȶ����������ٵݹ����

std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target)
{
	sort(candidates.begin(), candidates.end());//�Ƚ�������
	std::vector<std::vector<int>> result;
	std::vector<int> intermediate;
	dfs(result, intermediate, candidates, 0, target);
	return result;
}

void dfs(std::vector<std::vector<int>>& result, std::vector<int>& intermediate, std::vector<int> num, int index, int target)//indexΪ��ʼ���±꣬targetΪѰ�ҵ�ֵ����ֵ�𽥼���
{
	if (target == 0)//targetΪ0����ʾ�Ѿ��ҵ�һ�����ʵ�ֵ
	{
		result.push_back(intermediate);
		return;
	}
	for (int i = index; i < num.size(); ++i)//��index��ʼѭ����������
	{
		if (num[i] > target)//�ж�������С��ֵ�Ƿ��target�������Ļ���ֱ�ӷ��أ���Ϊ��ʱ�����ܴ��ں����
			return;
		intermediate.push_back(num[i]);
		dfs(result, intermediate, num, i, target - num[i]);//�ݹ���ã�����targetҪ��ȥ��ǰԪ�ص�ֵ
		intermediate.pop_back();//�������һ��Ԫ�أ���ʾ֮ǰѡ�е�Ԫ�ؾ�����һ���ĵݹ�û���ҵ���
	}	
}