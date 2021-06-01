#ifndef _RIDDLE_TREE_
#define _RIDDLE_TREE_

#include <algorithm>
#include <cmath>
#include <string>
#include <memory>
#include <iterator>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <functional>

using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	/******************************************************/
	/*				Node Field Class					  */
	/******************************************************/
	template<typename Key, typename Address>
	class NodeField {
	private:
		Address childNode;
		Key nodeKey;

	public:
		NodeField(Key theKey, Address node) {
			childNode = node;
			nodeKey = theKey;
		}

		~NodeField() { if (hasChildren()) delete childNode; }

		Address node() { return childNode; }
		string key() { return nodeKey; }

		bool operator==(const NodeField& field) const {
            return nodeKey == field.nodeKey;
		}

        bool operator!=(const NodeField& field) const {
            return nodeKey != field.nodeKey;
        }

        bool operator<(const NodeField& field) const {
            return nodeKey < field.nodeKey;
        }

        bool operator<=(const NodeField& field) const {
            return nodeKey <= field.nodeKey;
        }

        bool operator>(const NodeField& field) const {
            return nodeKey > field.nodeKey;
        }

        bool operator>=(const NodeField& field) const {
            return nodeKey >= field.nodeKey;
        }

        void operator=(const NodeField& field){
		    childNode = field.childNode;
		    nodeKey = field.nodeKey;
		}

        bool hasChildren() { return childNode==NULL; }
	};

	/******************************************************/
	/*				Tree Node Class						  */
	/******************************************************/
    template<typename TreeNodeFieldType>
    class TreeNodeVisitor {
    public:
        virtual void visit(TreeNodeFieldType field) = 0;
        virtual bool endTreeVisit() = 0;
    };

	template<typename Key>
	class TreeNode {
	private:
        typedef NodeField<Key,TreeNode<Key>*> GenericNodeField;
        typedef typename vector<GenericNodeField>::iterator NodeFieldIterator;

	    const short MAX_NO_OF_KEYS = 2;
		short maxNumOfKeys;
		vector<GenericNodeField>* tuple;

		void assertThatNodeDoesNotExceedMaxNumberOfKeys(){
		    if((tuple->size() + 1) > maxNumberOfAllowedKeys())
		        throw "Max Number of Keys is exceeded";
		}

        bool removeFoundFieldIfNoChildren(int foundIndex) {
            GenericNodeField foundField = tuple->at(foundIndex);
            bool removed = false;
            if(foundField.hasChildren()){
                tuple->erase(tuple->begin() + foundIndex);
                removed = true;
            }
            return removed;
        }

        int findFieldIndexByKey(Key key){
            vector<GenericNodeField> nodeFields = fields();
            GenericNodeField target(key,NULL);
            NodeFieldIterator found =
                    find(nodeFields.begin(), nodeFields.end(), target);
            return distance(nodeFields.begin(),found);
		}

	public:
		TreeNode() {
            maxNumOfKeys = MAX_NO_OF_KEYS;
			tuple =  new vector<GenericNodeField>();
		}

        TreeNode(int maxNoOfKeys) {
            maxNumOfKeys = maxNoOfKeys;
            tuple = new vector<GenericNodeField>();
        }

        TreeNode(TreeNode<Key>& targetNode){
            maxNumOfKeys = targetNode.maxNumOfKeys;
            if(!merge(targetNode)) throw "This node must be empty to initialize with copy of targetNode";
		}

        TreeNode(TreeNode<Key>* node){
		    if(node !=NULL){
                this(*node);
		    }
        }

        ~TreeNode() { delete tuple; }

        vector<GenericNodeField>& fields() {
            vector<GenericNodeField>* copy = new vector<GenericNodeField>(*tuple);
			return *copy;
		}

        vector<Key>& keys() {
		    vector<Key>* keys = new vector<Key>();
		    for(GenericNodeField node: *tuple){
		        keys->push_back(node.key());
		    }
            return *keys;
        }

		void insert(Key theKey, TreeNode<Key>* nodeAddress) {
		    assertThatNodeDoesNotExceedMaxNumberOfKeys();
            NodeField<Key,TreeNode<Key>*>* newField = new NodeField<Key,TreeNode<Key>*>(theKey, nodeAddress);
			tuple->push_back(*newField);
		}

		int numberOfInsertedKeys(){ return tuple->size(); }

		int maxNumberOfAllowedKeys(){ return maxNumOfKeys; }

		int maxKeyIndex(){
            return distance(
                    tuple->begin(),
                    max_element(tuple->begin(),tuple->end())
                    );
		}

		string maxKey(){
            return tuple->at(maxKeyIndex()).key();
		}

        bool remove(string key) {
            int foundIndex = findFieldIndexByKey(key);
            bool removed = false;
            if(foundIndex < tuple->size()){
                removed = removeFoundFieldIfNoChildren(foundIndex);
            }
            return removed;
        }

        bool hasKey(Key key){
            return findFieldIndexByKey(key) < tuple->size();
		}

		bool split(TreeNode<Key>& newNode) {
            bool split = false;

		}

		bool merge(TreeNode<Key>& node) {
		    bool merged = false;
            if(node.numberOfInsertedKeys()+numberOfInsertedKeys() <= maxNumberOfAllowedKeys()){
                tuple->insert(tuple->end(), node.fields().begin(), node.fields().end());
            }
            return merged;
		}

        int indexOfKey(string key) {
		    int indexOfKey = findFieldIndexByKey(key);
            return indexOfKey < tuple->size() ? indexOfKey : -1 ;
        }

    };

	/******************************************************/
	/*				Riddle Tree Class					  */
	/******************************************************/

	class RiddleTree {
	private:
        typedef TreeNode<string> StringTreeNode;
        typedef NodeField<string, TreeNode<string>*> StringNodeField;

        TreeNode<string>* treeRoot;

        void visitNode(TreeNode<string>* node,  TreeNodeVisitor<NodeField<string,TreeNode<string>*>*>* visitor);


	protected:
        StringTreeNode* root() { return treeRoot; }

	public:
		RiddleTree() {  treeRoot = new TreeNode<string>(); }
		~RiddleTree() { delete treeRoot; }

		void insert(string data);
        bool search(string targetKey);
		vector<string>& traverseInOrder();
	};

    class RiddleTreeNodeSearchVisitor : TreeNodeVisitor<NodeField<string,TreeNode<string>*>*> {
    private:
        string targetKey;
        bool theKeyIsFound;

    public:
        RiddleTreeNodeSearchVisitor(string targetKey) {
            this->targetKey = targetKey;
            theKeyIsFound = false;
        }

        bool found(){ return theKeyIsFound; }

        void visit(NodeField<string,TreeNode<string>*>* field){
            if(!found())
                theKeyIsFound = (targetKey == field->key());
        }

        bool endTreeVisit(){
            return found();
        }


    };

    class RiddleTreeNodeExtractKeyVisitor : TreeNodeVisitor<NodeField<string,TreeNode<string>*>*> {
    private:
        vector<string>* theTreeNodes;

    public:
        RiddleTreeNodeExtractKeyVisitor() {
            theTreeNodes = new vector<string>();
        }

        void visit(NodeField<string,TreeNode<string>*>* field){
            theTreeNodes->push_back(field->key());
        }

        bool endTreeVisit(){
            return false;
        }

        vector<string>& treeNodes(){ return *theTreeNodes; }
    };
}

#endif //_RIDDLE_TREE_
