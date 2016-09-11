#include "TreeNode.h"
#include<string>
#include<sstream>
//��Ŀ����:����һ�����������������л����ַ�����Ȼ�����ַ��������л��ɶ�����
//�ⷨ����:����������ķ����������л���#����nullptr,�ÿո���Ϊÿ���ڵ�֮��ķָ����������л���ʱ������
//        istringstream����ȡÿ���ڵ��ֵ��istringstream��һֱ��ȡֱ�������ո���߻��з���

class Codec 
{
private:
	TreeNode* deserialize(std::istringstream& in)
	{
		std::string value;
		in >> value;
		if (value == "#")
			return nullptr;
		else
		{
			TreeNode* root = new TreeNode(stoi(value));
			root->left = deserialize(in);
			root->right = deserialize(in);
			return root;
		}
	}
public:
	std::string serialize(TreeNode* root) 
	{
		if (root == nullptr)
			return "# ";

		std::string left = serialize(root->left);
		std::string right = serialize(root->right);
		return std::to_string(root->val) + " " + left + right;
	}

	TreeNode* deserialize(std::string data) 
	{
		std::istringstream in(data);
		return deserialize(in);
	}
};