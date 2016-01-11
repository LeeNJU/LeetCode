#include<vector>
//��Ŀ����:����һ������������������������ж��ǲ�����Ч���������
//�ⷨ����:���ö�������������������������ģ��ջ���������򣬰�Ԫ�طŵ�ջ�У���������Ԫ�أ�������������������
//        ĳ���ҽڵ㣬��ջ���ҵ��ȵ�ǰԪ��С��Ԫ����ΪlowerBound����Ϊ֮���Ԫ�ض�Ҫ��lowerBound�����ĳ��
//        Ԫ�ر�lowerBoundС��˵�������������

bool verifyPreorder(std::vector<int>& preorder) 
{
	if (preorder.empty()) 
		return true;
	
	int lowerBound = INT_MIN;
	int stackTopPosition = 0;
	for (int pos = 1; pos < preorder.size(); ++pos) 
	{
		if (preorder[pos] < lowerBound) 
			return false;
		while (stackTopPosition >= 0 && preorder[pos] > preorder[stackTopPosition]) 
			lowerBound = preorder[stackTopPosition--];  //����lowerBound
		
		preorder[++stackTopPosition] = preorder[pos];  //����ѹ��ջ��
	}
	return true;
}