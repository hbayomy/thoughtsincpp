#include "RiddleTreeTest.h"

using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {
	
	namespace testing {

        /************************************************************/
        /*   Test Cases Class for TreeNode Functions                */
        /************************************************************/

        TEST_F(TreeNodeTests, TreeNode_InsertKey_EmptyNode_Successfully){
            /* No Arrange */

            /* Act */
            treeNode_fixture->insert("B",NULL);

            /* ASSERT */
            EXPECT_EQ(1,treeNode_fixture->numberOfInsertedKeys());
        }

        TEST_F(TreeNodeTests, TreeNode_InsertKey_NodeWithOneKey_Successfully){
            /* Arrange */
            treeNode_fixture->insert("A",NULL);

            /* Act */
            treeNode_fixture->insert("B",NULL);

            /* ASSERT */
            EXPECT_EQ(2,treeNode_fixture->numberOfInsertedKeys());
        }

        TEST_F(TreeNodeTests, TreeNode_InsertKey_ChaneDefaultMaxNumberOfKeys_Successfully){
            /* Arrange */
            treeNode_fixture = new TreeNode<string>(3);
            treeNode_fixture->insert("A",NULL);
            treeNode_fixture->insert("B",NULL);

            /* Act */
            treeNode_fixture->insert("C",NULL);

            /* ASSERT */
            EXPECT_EQ(3,treeNode_fixture->numberOfInsertedKeys());
        }

	    TEST_F(TreeNodeTests, TreeNode_InsertKey_ExceedNumberOfMaxKeys){
	        /* Arrange */
            treeNode_fixture->insert("A",NULL);
            treeNode_fixture->insert("B",NULL);

	        /* ASSERT */                    /* Act */
            EXPECT_ANY_THROW(treeNode_fixture->insert("C",NULL));
	    }

        TEST_F(TreeNodeTests, Find_MaxKeyIndex_InTreeNode){
            /* Arrange */
            treeNode_fixture->insert("A",NULL);
            treeNode_fixture->insert("B",NULL);

            /* Act */
            int max_keyIndex = treeNode_fixture->maxKeyIndex();

            /* ASSERT */                    /* Act */
            EXPECT_EQ(1,max_keyIndex);
        }

        TEST_F(TreeNodeTests, Find_MaxKey_InTreeNode){
            /* Arrange */
            treeNode_fixture->insert("A",NULL);
            treeNode_fixture->insert("B",NULL);

            /* Act */
            string max_key = treeNode_fixture->maxKey();

            /* ASSERT */                    /* Act */
            EXPECT_EQ(string("B"),max_key);
        }

        TEST_F(TreeNodeTests, TreeNode_RemoveKey_Successfully){
            /* Arrange */
            treeNode_fixture->insert("A",NULL);
            treeNode_fixture->insert("B",NULL);

            /* Act */
            bool removed = treeNode_fixture->remove("A");

            /* ASSERT */
            EXPECT_EQ(1,treeNode_fixture->numberOfInsertedKeys());
            EXPECT_EQ(true, removed);
        }

        TEST_F(TreeNodeTests, TreeNode_RemoveKey_DoesNotExist){
            /* Arrange */
            treeNode_fixture->insert("A",NULL);
            treeNode_fixture->insert("B",NULL);

            /* Act */
            bool removed = treeNode_fixture->remove("C");

            /* ASSERT */
            EXPECT_EQ(2,treeNode_fixture->numberOfInsertedKeys());
            EXPECT_EQ(false, removed);
        }


        /******************************************************/
        /*   Test Cases Class for RiddleTree Functions        */
        /******************************************************/

		void RiddleTreeTestClass::initializeRiddleTreeTestClassWithThreeNodes() {
			TreeNode<string>* nodeAB(new TreeNode<string>());
			nodeAB->insert("A",NULL);
			nodeAB->insert("B",NULL);
			TreeNode<string>* nodeD(new TreeNode<string>());
			nodeD->insert("D",NULL);
			root()->insert("C",nodeAB);
			root()->insert("E", nodeD);
			
		}

		TEST_F(RiddleTreeTests, PrintTree_WithThreeNodes_WithhRootNodeB) {

			/*Arrange*/
			tree_fixture->initializeRiddleTreeTestClassWithThreeNodes();
			
			/*  ACT  */
			vector<string> nodesInOrder =
				tree_fixture->traverseInOrder();

			/*  ASSERT  */
			EXPECT_EQ("A, B, C, D, E", toString(nodesInOrder));
		}

		void RiddleTreeTestClass::initializeRiddleTreeTestClassWithFourNodes() {
			TreeNode<string>* nodeAB(new TreeNode<string>());
			nodeAB->insert("A",NULL);
			nodeAB->insert("B",NULL);
			TreeNode<string>* nodeEF(new TreeNode<string>());
			nodeEF->insert("E", NULL);
			nodeEF->insert("F", NULL);
			TreeNode<string>* nodeC(new TreeNode<string>());
			nodeC->insert("C",nodeAB);
			TreeNode<string>* nodeG(new TreeNode<string>());
			nodeG->insert("G", nodeEF);
			root()->insert("D", nodeC);
			root()->insert("H", nodeG);
		}

		TEST_F(RiddleTreeTests, PrintTreeWithFourNodesWithhRootNodeCF) {
			
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

		TEST_F(RiddleTreeTests, Insert_Value_B_IntoTreeWith_RootHasValue_A) {

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

		TEST_F(RiddleTreeTests, Insert_Value_C_IntoFullRootHasValues_A_and_B_TheRootMustSplit) {

			/*Arrange*/
			tree_fixture->initializeTreeWithOneNodeAndValuesAB();

			/*  ACT  */
			/*  The root node should be split */
			tree_fixture->insert("C");

			/*  ASSERT  */
			/*  The Tree will have three fields including its root */
			EXPECT_EQ("A, B, C", toString(tree_fixture->traverseInOrder()));

		}
	}

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
