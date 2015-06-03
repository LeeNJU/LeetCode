#include"TreeNode.h"
//��Ŀ����������һ����������ÿһ���ڵ㶼����һ��ָ�룬��ָ��ָ��ͬһ������ڽڵ㣨��ͬһ������ڵ��ұ��Ǹ��ڵ㣩��������ڽڵ㲻���ڣ�ָ����Ϊnull
//�ⷨ�������ݹ飬������һ���ݹ麯��������һ������sibling����ʾ�ýڵ���ֵܽڵ�

void connects(TreeLinkNode* root, TreeLinkNode* sibling)//sibling��ʾroot���ֵܽڵ㣬�տ�ʼʱ��siblingΪnull����Ϊrootû���ֵܽڵ�
{
	if (root == nullptr)//����root��nextָ��
		return;
	else
		root->next = sibling;

	connects(root->left, root->right);//�ݹ�����������
	if (sibling)//��sibling��Ϊ�յ�ʱ�����ӽڵ���ֵܽڵ�Ϊsibling�����ӽڵ㣬����Ҫע��
		connects(root->right, sibling->left);
	else//siblingΪ�գ����ӽڵ��nextָ��ҲΪ��
		connects(root->right, nullptr);
}

void connect(TreeLinkNode* root)
{
	connects(root, nullptr);
}

//����
//��Ŀ��������һ��Ķ���������������������Ҫ���Ϊ����Ķ�����
//�ⷨ�������ݹ���⣬��ÿһ�������ߵĽڵ㿪ʼ������ͬһ��Ľڵ㣬����ͬһ��Ľڵ��nextָ�룬Ȼ��ݹ����������һ�㣬dummy�ڵ�������¼ÿһ��
//����ߵĽڵ�
void connect2(TreeLinkNode* root)
{
	if (root == nullptr) 
		return;

	TreeLinkNode dummy(-1);//dummy�ڵ����һ���ڵ���ÿһ�������ߵĽڵ�
	for (TreeLinkNode *curr = root, *prev = &dummy; curr; curr = curr->next)//����ͬһ��Ľڵ㣬���ýڵ��nextָ�� 
	{
		if (curr->left != nullptr)
		{
			prev->next = curr->left;
			prev = prev->next;
		}
		if (curr->right != nullptr)
		{
			prev->next = curr->right;
			prev = prev->next;
		}
	}
	connect(dummy.next);//�ݹ����
}