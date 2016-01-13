#include<vector>
#include<queue>
#include<algorithm>
//��Ŀ����:����һ����ά�ַ����飬ֵΪ0��1�����е�1���������ģ����ڸ���һ��1������x��y�������С�Ĳ��Ұ�������1
//        �ĳ����ε����
//�ⷨ����:bfs���������нڵ㣬������1������У���С�У�����к���С�е��±�
int minArea(std::vector<std::vector<char>>& image, int x, int y)
{
	if (image.empty())
		return 0;

	int min_row = 0, min_col = 0, max_row = image.size() - 1, max_col = image[0].size() - 1;
	std::queue<int> q;
	q.push(x);
	q.push(y);

	while (!q.empty())
	{
		int row = q.front();
		q.pop();
		int col = q.front();
		q.pop();
		if (image[row][col] == '0')//����image���������б�ǣ��ѷ��ʹ�
			continue;
		image[row][col] = '0';

		min_row = std::max(min_row, x);
		min_col = std::max(min_col, y);
		max_row = std::min(max_row, x);
		max_col = std::min(max_col, y);

		if (row + 1 < image.size() && image[row + 1][col] == '1')
		{
			q.push(row + 1);
			q.push(col);
		}

		if (row - 1 >= 0 && image[row - 1][col] == '1')
		{
			q.push(row - 1);
			q.push(col);
		}

		if (col + 1 && image[row][col + 1] == '1')
		{
			q.push(row);
			q.push(col + 1);
		}

		if (col - 1 >= 0 && image[row][col - 1])
		{
			q.push(row);
			q.push(col - 1);
		}
	}

	return (max_row - min_row + 1) * (max_col - min_col + 1);
}