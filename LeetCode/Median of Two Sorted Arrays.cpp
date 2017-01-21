#include<algorithm>
#include<vector>

//��Ŀ����:���������������飬�ҵ��������������λ����Ҫ��ʱ�临�Ӷ�ΪO(log(m+n))
//�ⷨ����:ת��Ϊ�ҵ���KС��Ԫ�����⣬kΪ�����������λ����������ָ��ֱ�ָ����������ĵ�k/2��Ԫ��(Ҫ�ж�
//        �����Ƿ�����ô��)

double find_kth(std::vector<int>& A, int m, std::vector<int>& B, int n, int k)
{
	if (A.size() > B.size())//Ĭ��A����ҪС
		return find_kth(B, n, A, m, k);
	if (m >= A.size())//A����Ϊ�գ�˵����KС��Ԫ��������B��
		return B[n + k - 1];
	if (n >= B.size())
		return A[m + k - 1];

	if (k == 1)//�ҵ�1С��Ԫ��
		return std::min(A[m], B[n]);

	int pa = std::min(k / 2, int(A.size() - m)), pb = k - pa;//ע��pb���㷨��k-pa����ʹpa��pb����������k
	if (A[m + pa - 1] < B[n + pb - 1])//���С�ڣ���ʾ����A��pa-1λ�����µ�Ԫ�ض����ǣ�����ɾ��
		return find_kth(A, m + pa, B, n, k - pa);
	else if (A[m + pa - 1] > B[n + pb - 1])//������ڣ���ʾ����B��pb - 1�±����µ�Ԫ�ض����ǵ�kС��Ԫ�أ�����ɾ��
		return find_kth(A, m, B, n + pb, k - pb);
	else//��ȣ���ʾ����ǵ�kС��Ԫ�أ���Ϊpa+pb����k
		return A[m + pa - 1];
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	const int total = nums1.size() + nums2.size();
	if (total % 2)//����
		return find_kth(nums1, 0, nums2, 0, total / 2 + 1);
	else//ż��
		return (find_kth(nums1, 0, nums2, 0, total / 2) + find_kth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
}