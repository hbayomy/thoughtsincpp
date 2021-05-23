#include "RiddleTree.h"

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	/******************************************************/
	/*				Tree Node Class						  */
	/******************************************************/

	TreeNode& TreeNode::insertNodePointer(TreeNode* nodePointer)
	{
		tuple.push_back(
			NodeField(FieldType::POINTER)
			.node(nodePointer)
		);
		return (*this);
	}

	TreeNode& TreeNode::insertData(string data)
	{
		tuple.push_back(
			NodeField(FieldType::DATA)
			.data(data)
		);
		return (*this);
	}


	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/
	void RiddleTree::insert(shared_ptr<TreeNode> treeRoot, string data)
	{
		//TODO 
	}

	vector<string>& RiddleTree::traverseInOrder(TreeNode* treeRoot)
	{
		vector<string>* nodes = new vector<string>();
		visitNode(treeRoot, nodes);
		return *nodes;
	}

}