#ifndef _RIDDLE_TREE_TEST_
#define _RIDDLE_TREE_TEST_

#include <gtest/gtest.h>
#include <sstream>

#include "../src/riddle_tree/RiddleTree.h"


using namespace std;

/******************************************************/
/*				Egyptian Clean Coders (ECC)			  */
/******************************************************/
namespace ecc {

	namespace testing {

		/************************************************************/
		/*   Riddle Tree Test Class									*/
		/************************************************************/
		class RiddleTreeTestClass : public RiddleTree {
		public:
			RiddleTreeTestClass() : RiddleTree() {}
			void initializeRiddleTreeTestClassWithThreeNodes();
			void initializeRiddleTreeTestClassWithFourNodes();
			void initializeTreeWithRootHasAValue();
			void initializeTreeWithOneNodeAndValuesAB();
        };

		/************************************************************/
		/*   Base Test Case Class									*/
		/************************************************************/
		class BaseTest : public ::testing::Test {

		public:
			BaseTest() : Test() {}

			string toString(vector<string>& vec) {
				std::ostringstream oss;
				std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<std::string>(oss, ", "));
				oss << vec.back();
				return oss.str();
			}

		};

		/************************************************************/
		/*   Test Cases Class for TreeNode Functions                */
		/************************************************************/
		class TreeNodeTests : public BaseTest {

		protected:
			TreeNode<string>* treeNode_fixture;

			void SetUp() override {
				treeNode_fixture = new TreeNode<string>();
			}

			void TearDown() override {
				delete treeNode_fixture;
                treeNode_fixture = NULL;
			}

		public:
            TreeNodeTests() : BaseTest() {
				treeNode_fixture = NULL;
			}
		};

		/******************************************************/
		/*   Test Cases Class for RiddleTree Functions        */
		/******************************************************/
		class RiddleTreeTests : public BaseTest {
			
		protected:
			RiddleTreeTestClass* tree_fixture;

			void SetUp() override {
				tree_fixture = new RiddleTreeTestClass();
			}

			void TearDown() override {
				delete tree_fixture;
                tree_fixture = NULL;
			}

		public:
            RiddleTreeTests() : BaseTest() {
				tree_fixture = NULL;
			}
		};
	}
}

#endif //_RIDDLE_TREE_TEST_
