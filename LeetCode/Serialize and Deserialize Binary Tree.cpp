#include "TreeNode.h"
#include<string>
#include<sstream>
//��Ŀ����:����һ�����������������л����ַ�����Ȼ�����ַ��������л��ɶ�����
//�ⷨ����:����������ķ����������л���#����nullptr,�ÿո���Ϊÿ���ڵ�֮��ķָ����������л���ʱ������
//        istringstream����ȡÿ���ڵ��ֵ��istringstream��һֱ��ȡֱ�������ո���߻��з���

class Codec 
{
private:
	TreeNode* Deserialize(const std::string& data, int& index)
	{
		if (index >= data.size()) 
			return nullptr;
		if (data[index] == '#')
		{
			index = index + 2;
			return nullptr;
		}

		int flag = 1;//�п����Ǹ���
		if (data[index] == '-')
		{
			flag = -1;
			++index;
		}

		int val = 0;
		while (data[index] != ' ')
		{
			val = val * 10 + data[index] - '0';
			++index;
		}

		TreeNode* node = new TreeNode(val * flag);
		node->left = Deserialize(data, ++index);
		node->right = Deserialize(data, index);
		return node;
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
		int index = 0;
		return Deserialize(data, index);
	}
};