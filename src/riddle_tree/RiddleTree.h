#ifndef _RIDDLE_TREE_
#define _RIDDLE_TREE_

#include <string>
#include <memory>
#include<iterator>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {
	/******************************************************/
	/*				Forward Declarations				  */
	/******************************************************/
	class TreeNode;

	/******************************************************/
	/*				Node Field Class					  */
	/******************************************************/
	class NodeField {
	private:
		TreeNode* childNode;
		string nodeKey;

	public:
		NodeField(string theKey, TreeNode* node) { 
			childNode = node;
			nodeKey = theKey;
		}

		~NodeField() { if (childNode != NULL) delete childNode; }

		TreeNode* node() { return childNode; }
		string key() { return nodeKey; }

	};

	/******************************************************/
	/*				Tree Node Class						  */
	/******************************************************/
	class TreeNode {
	private:
		const short MAX_NO_OF_VALUES = 2;
		
		vector<NodeField*>* tuple;

	public:
		TreeNode() {
			tuple = new vector<NodeField*>();
		}

		vector<NodeField*>& nodeAsVector() { 
			return *tuple;
		}

		void insert(string theKey, TreeNode* nodePointer) {
			tuple->push_back(
				new NodeField(theKey, nodePointer)
			);
		}
	
	};

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/
	class RiddleTree {
	private:
		TreeNode* treeRoot;

		void visitNode(TreeNode* node, vector<string>* visitedNodes) {
			if (node != NULL) {
				for (NodeField* field : node->nodeAsVector()) {
					visitNode(field->node(), visitedNodes);
					visitedNodes->push_back(field->key());
				}			
			}
		}

	protected:
		TreeNode* root() { return treeRoot; }		

	public:
		RiddleTree() { treeRoot = new TreeNode(); }
		~RiddleTree() { delete treeRoot; }

		void insert(string data);

		vector<string>& traverseInOrder();
	};

}

#endif //_RIDDLE_TREE_
