#include "RiddleTreeTest.h"

using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {
	
	namespace testing {

		void RiddleTreeTestClass::initializeRiddleTreeTestClassWithThreeNodes() {
			TreeNode* nodeAB(new TreeNode());
			nodeAB->insert("A",NULL);
			nodeAB->insert("B",NULL);
			TreeNode* nodeD(new TreeNode());
			nodeD->insert("D",NULL);
			root()->insert("C",nodeAB);
			root()->insert("E", nodeD);
			
		}

		TEST_F(RiddleTreePrintInOrderTest, PrintTree_WithThreeNodes_WithhRootNodeB) {

			/*Arrange*/
			tree_fixture->initializeRiddleTreeTestClassWithThreeNodes();
			
			/*  ACT  */
			vector<string> nodesInOrder =
				tree_fixture->traverseInOrder();

			/*  ASSERT  */
			EXPECT_EQ("A, B, C, D, E", toString(nodesInOrder));
		}

		void RiddleTreeTestClass::initializeRiddleTreeTestClassWithFourNodes() {
			TreeNode* nodeAB(new TreeNode());
			nodeAB->insert("A",NULL);
			nodeAB->insert("B",NULL);
			TreeNode* nodeEF(new TreeNode());
			nodeEF->insert("E", NULL);
			nodeEF->insert("F", NULL);
			TreeNode* nodeC(new TreeNode());
			nodeC->insert("C",nodeAB);
			TreeNode* nodeG(new TreeNode());
			nodeG->insert("G", nodeEF);
			root()->insert("D", nodeC);
			root()->insert("H", nodeG);
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
			root()->insert("A",NULL);
		}

		TEST_F(RiddleTreeInsertTest, Insert_Value_B_IntoTreeWith_RootHasValue_A) {

			/*Arrange*/
			tree_fixture->initializeTreeWithRootHasAValue();

			/*  ACT  */
			tree_fixture->insert("B");

			/*  ASSERT  */
			EXPECT_EQ("A, B", toString(tree_fixture->traverseInOrder()));
		
		}


		void RiddleTreeTestClass::initializeTreeWithOneNodeAndValuesAB() {
			root()->insert("A",NULL);
			root()->insert("B",NULL);
		}

		TEST_F(RiddleTreeInsertTest, Insert_Value_C_InTreeWith_RootHasValues_A_and_B) {

			/*Arrange*/
			tree_fixture->initializeTreeWithOneNodeAndValuesAB();

			/*  ACT  */
			tree_fixture->insert("C");

			/*  ASSERT  */
			EXPECT_EQ("A, B, C", toString(tree_fixture->traverseInOrder()));

		}
	}

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
