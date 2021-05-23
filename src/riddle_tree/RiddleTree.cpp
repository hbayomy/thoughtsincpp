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
		tuple->push_back(
			new NodeField(FieldType::POINTER, nodePointer)
		);
		return (*this);
	}

	TreeNode& TreeNode::insertData(string data)
	{
		tuple->push_back(
			new NodeField(FieldType::DATA, data)
		);
		return (*this);
	}


	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/
	void RiddleTree::insert(string data)
	{
		//TODO 
	}

	vector<string>& RiddleTree::traverseInOrder()
	{
		vector<string>* nodes = new vector<string>();
		visitNode(root(), nodes);
		return *nodes;
	}

}