#include "RiddleTree.h"

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

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