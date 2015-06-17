#include"TreeNode.h"
#include<unordered_map>
//��Ŀ����������һ��ͼ���������ͼ
//�ⷨ������dfs,��һ��hashtable��¼ÿһ��node�Ͷ�Ӧ�ĸ���node

UndirectedGraphNode* clone(const UndirectedGraphNode* node, std::unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*>& copied)
{
	if (copied.find(node) != copied.end()) //�ýڵ��Ѿ����ƹ���
		return copied[node];

	UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
	copied[node] = new_node;
	for (auto nbr : node->neighbors)
		new_node->neighbors.push_back(clone(nbr, copied));
	return new_node;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (node == nullptr) // key is original node��value is copied node
		return nullptr;
	std::unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copied;
	clone(node, copied);
	return copied[node];
}