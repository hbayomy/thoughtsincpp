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
		NodeField(FieldType type) { 
			fieldType = type;
			childNode = nullptr;
			nodeData = string();
		}
		FieldType type() { return fieldType; }
		
		NodeField& node(TreeNode* treeNode) { childNode = treeNode; return (*this); }
		TreeNode* node() { return childNode; }

		NodeField& data(string data) { nodeData = data; return (*this); }
		string data() { return nodeData; }

	};

	/******************************************************/
	/*				Tree Node Class						  */
	/******************************************************/
	class TreeNode {
	private:
		vector<NodeField> tuple;

	public:

		vector<NodeField>& nodeAsVector() { 
			return tuple;
		}

		TreeNode& insertNodePointer(TreeNode* nodePointer);
		TreeNode& insertData(string data);
	
	};

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/
	class RiddleTree {
	private:
		void visitNode(TreeNode* node, vector<string>* visitedNodes) {
			for (NodeField field : node->nodeAsVector()) {
				pushNode(field, visitedNodes);
				pushData(field, visitedNodes);
			}			
		}

		void pushNode(ecc::NodeField& field, std::vector<string>* visitedNodes)
		{
			if (field.type() == FieldType::POINTER) {
				visitNode(field.node(), visitedNodes);
			}
		}

		void pushData(ecc::NodeField& field, std::vector<std::string>* visitedNodes)
		{
			if (field.type() == FieldType::DATA) {
				visitedNodes->push_back(field.data());
			}
		}

	public:
		RiddleTree() { }

		void insert(shared_ptr<TreeNode> treeRoot, string data);

		vector<string>& traverseInOrder(TreeNode* treeRoot);
	};

}

#endif _RIDDLE_TREE_
