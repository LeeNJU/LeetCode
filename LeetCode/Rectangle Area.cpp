#include<algorithm>
//��Ŀ�������������������ε����¶�������϶�������꣬�������������ε����
//�ⷨ���������غϵ����

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int res = (D - B) * (C - A) + (H - F) * (G - E);
	return res - std::max(std::min(C, G) - std::max(A, E), 0) * std::max(std::min(D, H) - std::max(B, F), 0);
}