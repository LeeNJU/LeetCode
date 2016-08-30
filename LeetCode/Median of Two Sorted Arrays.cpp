#include<algorithm>
//��Ŀ����:���������������飬�ҵ��������������λ����Ҫ��ʱ�临�Ӷ�ΪO(log(m+n))
//�ⷨ����:ת��Ϊ�ҵ���KС��Ԫ�����⣬kΪ�����������λ����������ָ��ֱ�ָ����������ĵ�k/2��Ԫ��(Ҫ�ж�
//        �����Ƿ�����ô��)

double find_kth(int A[], int m, int B[], int n, int k)
{
	if (m > n)//���Ǽ���mС��n��������ڣ�������A��B����
		return find_kth(B, n, A, m, k);
	if (m == 0)//A����Ϊ�գ�˵����KС��Ԫ��������B��
		return B[k - 1];
	if (k == 1)//�ҵ�1С��Ԫ��
		return std::min(A[0], B[0]);

	int pa = std::min(k / 2, m), pb = k - pa;//ע��pb���㷨��k-pa����ʹpa��pb����������k
	if (A[pa - 1] < B[pb - 1])//���С�ڣ���ʾ����A��pa-1λ�����µ�Ԫ�ض����ǣ�����ɾ��
		return find_kth(A + pa, m - pa, B, n, k - pa);
	else if (A[pa - 1] > B[pb - 1])//������ڣ���ʾ����B��pb - 1�±����µ�Ԫ�ض����ǵ�kС��Ԫ�أ�����ɾ��
		return find_kth(A, m, B + pb, n - pb, k - pb);
	else//��ȣ���ʾ����ǵ�kС��Ԫ�أ���Ϊpa+pb����k
		return A[pa - 1];
}

double findMedianSortedArrays(int A [], int m, int B [], int n)
{
	const int total = m + n;
	if (total % 2)//����
		return find_kth(A, m, B, n, total / 2 + 1);
	else//ż��
		return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2;
}

