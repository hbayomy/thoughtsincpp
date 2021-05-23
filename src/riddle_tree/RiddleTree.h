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
	/*				Types' Declarations					  */
	/******************************************************/
	class TreeNode;
	enum class FieldType  { DATA, POINTER };
	enum class NodeLevel { ROOT, LEAF, MIDDLE };

	/******************************************************/
	/*				Node Field Class					  */
	/******************************************************/
	class NodeField {
	private:
		FieldType fieldType;
		TreeNode* childNode;
		string nodeData;

	public:
		NodeField(FieldType type, TreeNode* node) { 
			fieldType = type;
			childNode = node;
			nodeData = string();
		}

		NodeField(FieldType type, string data) {
			fieldType = type;
			childNode = NULL;
			nodeData = data;
		}

		~NodeField() { if (childNode != NULL) delete childNode; }

		FieldType type() { return fieldType; }		
		TreeNode* node() { return childNode; }
		string data() { return nodeData; }

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

		TreeNode& insertNodePointer(TreeNode* nodePointer);
		TreeNode& insertData(string data);
	
	};

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/
	class RiddleTree {
	private:
		TreeNode* treeRoot;

		void visitNode(TreeNode* node, vector<string>* visitedNodes) {
			for (NodeField* field : node->nodeAsVector()) {
				pushNode(field, visitedNodes);
				pushData(field, visitedNodes);
			}			
		}

		void pushNode(ecc::NodeField* field, std::vector<string>* visitedNodes)
		{
			if (field->type() == FieldType::POINTER) {
				visitNode(field->node(), visitedNodes);
			}
		}

		void pushData(ecc::NodeField* field, std::vector<std::string>* visitedNodes)
		{
			if (field->type() == FieldType::DATA) {
				visitedNodes->push_back(field->data());
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

#endif _RIDDLE_TREE_
