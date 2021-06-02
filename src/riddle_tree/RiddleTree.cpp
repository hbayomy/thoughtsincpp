#include "RiddleTree.h"

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/

	int RiddleTree::treeDepth() {
        return numberOfNodes()/maxAllowedKeys;
	}

    bool RiddleTree::search(string targetKey) {
        vector<bool>* found = new vector<bool>(1);
        found->insert(found->begin(),false);
        auto searchVisitor = [targetKey,found] (NodeField<string,TreeNode<string>*>* field) -> bool {
            bool foundKey = field->key() == targetKey;
            if(foundKey) found->insert(found->begin(),foundKey);
            return foundKey; // stop visit when you found the key
        };
        visitNodeField(root(), searchVisitor);
        return found->front();
    }

	void RiddleTree::insert(string key)
	{
        if(search(key)) throw "The key "+ key +"is already exist";
		if( (root()->numberOfInsertedKeys()+1) <= root()->maxNumberOfAllowedKeys()){
		    root()->insert(key,NULL);
		}else{
		    if(key > root()->maxKey()){
                TreeNode<string>* newNode = new TreeNode<string>(maxAllowedKeys);
                newNode->insert(key,root());
                root(newNode);
		    }
		}
		nodeCount++;
	}

    void RiddleTree::moveFieldOfMaxKey(TreeNode <string> *fromNode, TreeNode <string> *toNode) {
        toNode->insert(fromNode->maxKey(), fromNode->nodeOfMaxKey());
        fromNode->remove(fromNode->maxKey());
    }

    vector<string>& RiddleTree::traverseInOrder()
	{
        vector<string>* keys = new vector<string>();
        auto extractKeyVisitor = [keys](NodeField<string,TreeNode<string>*>* field) -> bool {
            keys->push_back(field->key());
            return false; //do not stop and visit all nodes
        };
        visitNodeField(root(), extractKeyVisitor);
		return *keys;
	}

    void RiddleTree::visitNodeField(TreeNode<string>* node, function<bool(NodeField<string,TreeNode<string>*>*)> visit){
        if(node!=NULL){
            for (NodeField<string,TreeNode<string>*> field : node->fields()) {
                visitNodeField(field.node(), visit);
                bool endTreeVisit = visit(&field);
                if(endTreeVisit) break;
            }
        }
    }

    void RiddleTree::visitNode(TreeNode<string>* node, function<void(TreeNode<string>*)> visit){
        if(node!=NULL){
            for (NodeField<string,TreeNode<string>*> field : node->fields()) {
                visitNode(field.node(), visit);
            }
            visit(node);
        }
	}
}