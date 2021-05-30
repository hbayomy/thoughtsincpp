#include "RiddleTree.h"

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/
	void RiddleTree::insert(string key)
	{
		if( (root()->numberOfInsertedKeys()+1) <= root()->maxNumberOfAllowedKeys()){
		    root()->insert(key,NULL);
		}
	}

	vector<string>& RiddleTree::traverseInOrder()
	{
		vector<string>* nodes = new vector<string>();
		visitNode(root(), nodes);
		return *nodes;
	}

}