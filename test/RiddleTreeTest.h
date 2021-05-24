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
		/*   Test Cases Class for In Order Traverse to Print Tree   */
		/************************************************************/
		class RiddleTreePrintInOrderTest : public BaseTest {

		protected:
			RiddleTreeTestClass* tree_fixture;

			void SetUp() override {
				tree_fixture = new RiddleTreeTestClass();
			}

			void TearDown() override {
				delete tree_fixture;
			}

		public:
			RiddleTreePrintInOrderTest() : BaseTest() {
				tree_fixture = NULL;
			}
		};

		/******************************************************/
		/*   Test Cases Class for Insert method               */
		/******************************************************/
		class RiddleTreeInsertTest : public BaseTest {
			
		protected:
			RiddleTreeTestClass* tree_fixture;

			void SetUp() override {
				tree_fixture = new RiddleTreeTestClass();
			}

			void TearDown() override {
				delete tree_fixture;
			}

		public:
			RiddleTreeInsertTest() : BaseTest() {
				tree_fixture = NULL;
			}
		};
	}
}

#endif //_RIDDLE_TREE_TEST_
