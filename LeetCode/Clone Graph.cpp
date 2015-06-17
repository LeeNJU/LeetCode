#include"TreeNode.h"
#include<unordered_map>
//题目描述：给定一个图，复制这个图
//解法描述：dfs,用一个hashtable记录每一个node和对应的复制node

UndirectedGraphNode* clone(const UndirectedGraphNode* node, std::unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*>& copied)
{
	if (copied.find(node) != copied.end()) //该节点已经复制过了
		return copied[node];

	UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
	copied[node] = new_node;
	for (auto nbr : node->neighbors)
		new_node->neighbors.push_back(clone(nbr, copied));
	return new_node;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (node == nullptr) // key is original node，value is copied node
		return nullptr;
	std::unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copied;
	clone(node, copied);
	return copied[node];
}