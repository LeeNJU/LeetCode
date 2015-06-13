#include<algorithm>
//题目描述：给定两个长方形的左下顶点和右上顶点的坐标，求这两个长方形的面积
//解法描述：算重合的面积

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int res = (D - B) * (C - A) + (H - F) * (G - E);
	return res - std::max(std::min(C, G) - std::max(A, E), 0) * std::max(std::min(D, H) - std::max(B, F), 0);
}