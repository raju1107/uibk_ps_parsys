#include "n_queens_problem_seq.cpp"
#include "gtest/gtest.h"
#include <map>

map<int, int> nQueensResults = {{1, 1}, {2, 0}, {3, 0}, 
		{4, 2}, {5, 10}, {6, 4}, {7, 40}, {8, 92}, {9, 352},
		{10, 724}, {11, 2680}, {12, 14200}, {13, 73712}, {14, 365596}, 
		{15, 2279184}, {16, 14772512}, {17, 95815104}};

TEST (NQueensTest, VerifyResult) { 
	int x = 4;	
    ASSERT_EQ (nQueensResults.find(x)->second, solveNQ(x));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
