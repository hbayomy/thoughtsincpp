#include "RiddleTreeTest.h"

using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {
	
	namespace testing {

		void RiddleTreeTestClass::initializeRiddleTreeTestClassWithThreeNodes() {
			TreeNode* nodeA(new TreeNode());
			nodeA->insertData("A");
			TreeNode* nodeC(new TreeNode());
			nodeC->insertData("C");
			root()->insertNodePointer(nodeA);
			root()->insertData("B");
			root()->insertNodePointer(nodeC);
		}

		TEST_F(RiddleTreePrintInOrderTest, PrintTreeWithThreeNodesWithhRootNodeB) {

			/*Arrange*/
			tree_fixture->initializeRiddleTreeTestClassWithThreeNodes();
			
			/*  ACT  */
			vector<string> nodesInOrder =
				tree_fixture->traverseInOrder();

			/*  ASSERT  */
			EXPECT_EQ("A, B, C", toString(nodesInOrder));
		}

		void RiddleTreeTestClass::initializeRiddleTreeTestClassWithFourNodes() {
			TreeNode* nodeAB(new TreeNode());
			nodeAB->insertData("A");
			nodeAB->insertData("B");
			TreeNode* nodeDE(new TreeNode());
			nodeDE->insertData("D");
			nodeDE->insertData("E");
			TreeNode* nodeGH(new TreeNode());
			nodeGH->insertData("G");
			nodeGH->insertData("H");
			root()->insertNodePointer(nodeAB);
			root()->insertData("C");
			root()->insertNodePointer(nodeDE);
			root()->insertData("F");
			root()->insertNodePointer(nodeGH);
		}

		TEST_F(RiddleTreePrintInOrderTest, PrintTreeWithFourNodesWithhRootNodeCF) {
			
			/*Arrange*/
			tree_fixture->initializeRiddleTreeTestClassWithFourNodes();

			/*  ACT  */
			vector<string> nodesInOrder =
				tree_fixture->traverseInOrder();

			/*  ASSERT  */
			EXPECT_EQ("A, B, C, D, E, F, G, H", toString(nodesInOrder));
		}


		void RiddleTreeTestClass::initializeTreeWithRootHasAValue() {
			root()->insertData("A");
		}

		TEST_F(RiddleTreeInsertTest, InsertNode_B_Into_TreeWith_RootHas_A) {

			/*Arrange*/
			tree_fixture->initializeTreeWithRootHasAValue();

			/*  ACT  */
			tree_fixture->insert("B");

			/*  ASSERT  */
			EXPECT_EQ("A, B", toString(tree_fixture->traverseInOrder()));
		
		}


		void RiddleTreeTestClass::initializeTreeWithOneNodeAndValuesAB() {
		
		}

		TEST_F(RiddleTreeInsertTest, INSERT) {

			/*Arrange*/
			tree_fixture->initializeTreeWithOneNodeAndValuesAB();

			/*  ACT  */
			tree_fixture->insert("B");

			/*  ASSERT  */
			EXPECT_EQ("A, B, C", toString(tree_fixture->traverseInOrder()));

		}
	}

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
