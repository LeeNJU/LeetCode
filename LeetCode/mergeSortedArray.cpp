#include<iostream>
#include<algorithm>
//��Ŀ����������������������A��B������ϲ�,��������A�������㹻�Ŀռ���������B
//�ⷨ��������A��B�Ľ�β��ʼɨ�裬���ν�ֵ�ϴ�ķŵ�����A������棬��������Bʣ�µ����ݿ���������A��

void mergeSortedArray(int* a, int lenA, int* b, int lenB)
{
	if (a == nullptr || b == nullptr)
		return;

	int indexA = lenA - 1, indexB = lenB - 1, cur = lenA + lenB - 1;

	while (indexA >= 0 && indexB >= 0)
	{
		a[cur--] = a[indexA] <= b[indexB] ? b[indexB--] : a[indexA--];//���ν�ֵ�ϴ�ķŵ�����A�ĺ���
	}

	std::copy(b, b + indexB + 1, a);//��Bʣ�µĸ��Ƶ�Aǰ��
}

