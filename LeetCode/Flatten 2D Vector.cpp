#include<vector>
//��Ŀ����:����һ����ά���飬ʵ��next��hashNext����
//�ⷨ����:x��y�ֱ�����к��У�hashNext��ʱ��ҪС��y���ܳ�����ǰ�е��±ꡣҪע�⿼��ĳһ���ǿյ����
class Vector2D 
{
private:
	std::vector<std::vector<int>> vec;
	int x, y;

public:
	Vector2D(std::vector<std::vector<int>>& vec2d) 
	{
		vec = vec2d;
		x = y = 0;
	}

	int next() 
	{
		return vec[x][y++];
	}

	bool hasNext() 
	{
		while (x < vec.size() && y == vec[x].size()) //��whileѭ����Ϊ�˷�ֹ���������Ŀ���
		{
			++x;
			y = 0;
		}
		return x < vec.size();
	}
};