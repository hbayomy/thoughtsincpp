#include "RiddleTreeTest.h"

using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {
	
	namespace testing {

		void RiddleTreePrintInOrderTest::initializeRiddleTreeTestClassWithThreeNodes() {
			TreeNode* nodeA(new TreeNode());
			nodeA->insertData("A");
			TreeNode* nodeC(new TreeNode());
			nodeC->insertData("C");
			treeWithThreeNodes = new TreeNode();
			treeWithThreeNodes->insertNodePointer(nodeA);
			treeWithThreeNodes->insertData("B");
			treeWithThreeNodes->insertNodePointer(nodeC);
		}

		void RiddleTreePrintInOrderTest::initializeRiddleTreeTestClassWithFourNodes() {
			TreeNode* nodeAB(new TreeNode());
			nodeAB->insertData("A");
			nodeAB->insertData("B");
			TreeNode* nodeDE(new TreeNode());
			nodeDE->insertData("D");
			nodeDE->insertData("E");
			TreeNode* nodeGH(new TreeNode());
			nodeGH->insertData("G");
			nodeGH->insertData("H");
			treeWithFourNodes = new TreeNode();
			treeWithFourNodes->insertNodePointer(nodeAB);
			treeWithFourNodes->insertData("C");
			treeWithFourNodes->insertNodePointer(nodeDE);
			treeWithFourNodes->insertData("F");
			treeWithFourNodes->insertNodePointer(nodeGH);
		}

		TEST_F(RiddleTreePrintInOrderTest, PrintTreeWithThreeNodesWithhRootNodeB) {

			/*Arrange*/
			initializeRiddleTreeTestClassWithThreeNodes();
			
			/*  ACT  */
			vector<string> nodesInOrder =
				tree_fixture->traverseInOrder(treeWithThreeNodes);

			/*  ASSERT  */
			EXPECT_EQ("A, B, C", toString(nodesInOrder));
		}

		TEST_F(RiddleTreePrintInOrderTest, PrintTreeWithFourNodesWithhRootNodeCF) {

			/*Arrange*/
			initializeRiddleTreeTestClassWithFourNodes();


			/*  ACT  */
			vector<string> nodesInOrder =
				tree_fixture->traverseInOrder(treeWithFourNodes);

			/*  ASSERT  */
			EXPECT_EQ("A, B, C, D, E, F, G, H", toString(nodesInOrder));
		}

	}

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
