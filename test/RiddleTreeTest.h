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
		/*   Test Cases Class for In Order Traverse to Print Tree   */
		/************************************************************/
		class RiddleTreePrintInOrderTest : public BaseTest {

		protected:
			TreeNode* treeWithThreeNodes;
			TreeNode* treeWithFourNodes;
			RiddleTree* tree_fixture;

			void initializeRiddleTreeTestClassWithThreeNodes();
			void initializeRiddleTreeTestClassWithFourNodes();

			void SetUp() override {
				tree_fixture = new RiddleTree();
			}

		public:
			RiddleTreePrintInOrderTest() : BaseTest() {
				treeWithThreeNodes = nullptr;
				treeWithFourNodes = nullptr;
				tree_fixture = nullptr;
			}
		};

		/******************************************************/
		/*   Test Cases Class for Insert method               */
		/******************************************************/
		class RiddleTreeInsertTest : public BaseTest {
			
		protected:
			RiddleTree tree; 
			
			void SetUp() override {
				//TODO
			}

			void TearDown() override{
				//TODO
			}

		public:
			RiddleTreeInsertTest() : BaseTest() {}
		};
	}
}

#endif _RIDDLE_TREE_TEST_
