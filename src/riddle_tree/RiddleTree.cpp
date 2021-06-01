#include "RiddleTree.h"

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/

    bool RiddleTree::search(string targetKey) {
        RiddleTreeNodeSearchVisitor* searchVisitor = new RiddleTreeNodeSearchVisitor(targetKey);
        visitNode(root(), (TreeNodeVisitor<NodeField<string,TreeNode<string>*>*>*) searchVisitor);
        return searchVisitor->found();
    }

	void RiddleTree::insert(string key)
	{
		if( (root()->numberOfInsertedKeys()+1) <= root()->maxNumberOfAllowedKeys()){
		    root()->insert(key,NULL);
		}
	}

	vector<string>& RiddleTree::traverseInOrder()
	{
        RiddleTreeNodeExtractKeyVisitor* extractKeyVisitor = new RiddleTreeNodeExtractKeyVisitor();
        visitNode(root(), (TreeNodeVisitor<NodeField<string,TreeNode<string>*>*>*) extractKeyVisitor );
		return extractKeyVisitor->treeNodes();
	}

    void RiddleTree::visitNode(TreeNode<string>* node,  TreeNodeVisitor<NodeField<string,TreeNode<string>*>*>* visitor){
        if(node!=NULL && !visitor->endTreeVisit()){
            for (NodeField<string,TreeNode<string>*> field : node->fields()) {
                visitNode(field.node(), visitor);
                visitor->visit(&field);
                if(visitor->endTreeVisit()) break;
            }
        }
    }

}