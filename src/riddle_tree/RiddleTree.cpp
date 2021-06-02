#include "RiddleTree.h"

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/

    bool RiddleTree::search(string targetKey) {
        vector<bool>* found = new vector<bool>(1);
        found->insert(found->begin(),false);
        auto searchVisitor = [targetKey,found] (NodeField<string,TreeNode<string>*>* field) -> bool {
            bool foundKey = field->key() == targetKey;
            if(foundKey) found->insert(found->begin(),foundKey);
            return foundKey; // stop visit when you found the key
        };
        visitNode(root(), searchVisitor);
        return found->front();
    }

	void RiddleTree::insert(string key)
	{
		if( (root()->numberOfInsertedKeys()+1) <= root()->maxNumberOfAllowedKeys()){
		    root()->insert(key,NULL);
		}
	}

	vector<string>& RiddleTree::traverseInOrder()
	{
        vector<string>* keys = new vector<string>();
        auto extractKeyVisitor = [keys](NodeField<string,TreeNode<string>*>* field) -> bool {
            keys->push_back(field->key());
            return false; //do not stop visit
        };
        visitNode(root(), extractKeyVisitor );
		return *keys;
	}

    void RiddleTree::visitNode(TreeNode<string>* node,  function<bool(NodeField<string,TreeNode<string>*>*)> visit){
        if(node!=NULL){
            for (NodeField<string,TreeNode<string>*> field : node->fields()) {
                visitNode(field.node(), visit);
                bool endTreeVisit = visit(&field);
                if(endTreeVisit) break;
            }
        }
    }

}