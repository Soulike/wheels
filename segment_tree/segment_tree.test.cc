//
// Created by Soulike on 2025/8/6.
//

#include "segment_tree.h"
#include <gtest/gtest.h>
#include <vector>
#include <optional>

class SegmentTreeTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Test constructor with empty vector
TEST_F(SegmentTreeTest, ConstructorWithEmptyVector) {
    std::vector<int> empty_vec;
    SegmentTree<int> tree(empty_vec);

    // Should return nullopt for any search on empty tree
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1), std::nullopt);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), std::nullopt);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(-1), std::nullopt);

    // Update on empty tree should not crash
    tree.UpdateElement(0, 5);
}

// Test constructor with single element
TEST_F(SegmentTreeTest, ConstructorWithSingleElement) {
    std::vector<int> single_vec = {42};
    SegmentTree<int> tree(single_vec);

    // Should find the element when searching for values <= 42
    EXPECT_EQ(tree.FindFirstElementGreaterThan(42), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(41), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 0);

    // Should not find element when searching for values > 42
    EXPECT_EQ(tree.FindFirstElementGreaterThan(43), std::nullopt);
}

// Test constructor with multiple elements
TEST_F(SegmentTreeTest, ConstructorWithMultipleElements) {
    std::vector<int> vec = {1, 5, 3, 9, 2, 7};
    SegmentTree<int> tree(vec);

    // Test various search values
    // Note: FindFirstElementGreaterThan actually finds first element >= target
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 0);  // Should find 1 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1), 0);  // Should find 1 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2), 1);  // Should find 5 at index 1 (first >= 2)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(3), 1);  // Should find 5 at index 1 (first >= 3)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 1);  // Should find 5 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5), 1);  // Should find 5 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(6), 3);  // Should find 9 at index 3 (first >= 6)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(7), 3);  // Should find 9 at index 3 (first >= 7)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(8), 3);  // Should find 9 at index 3
    EXPECT_EQ(tree.FindFirstElementGreaterThan(9), 3);  // Should find 9 at index 3
    EXPECT_EQ(tree.FindFirstElementGreaterThan(10), std::nullopt);  // No element >= 10
}

// Test with sorted ascending array
TEST_F(SegmentTreeTest, SortedAscendingArray) {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11};
    SegmentTree<int> tree(vec);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2), 1);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(3), 1);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 2);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5), 2);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(6), 3);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(11), 5);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(12), std::nullopt);
}

// Test with sorted descending array
TEST_F(SegmentTreeTest, SortedDescendingArray) {
    std::vector<int> vec = {11, 9, 7, 5, 3, 1};
    SegmentTree<int> tree(vec);

    // For array {11, 9, 7, 5, 3, 1}, find first element >= target
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 0);   // Find 11 at index 0 (first >= 0)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1), 0);   // Find 11 at index 0 (first >= 1)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2), 0);   // Find 11 at index 0 (first >= 2)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(3), 0);   // Find 11 at index 0 (first >= 3)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 0);   // Find 11 at index 0 (first >= 4)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5), 0);   // Find 11 at index 0 (first >= 5)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(6), 0);   // Find 11 at index 0 (first >= 6)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(7), 0);   // Find 11 at index 0 (first >= 7)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(8), 0);   // Find 11 at index 0 (first >= 8)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(9), 0);   // Find 11 at index 0 (first >= 9)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(10), 0);  // Find 11 at index 0 (first >= 10)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(11), 0);  // Find 11 at index 0 (first >= 11)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(12), std::nullopt);
}

// Test with duplicate elements
TEST_F(SegmentTreeTest, DuplicateElements) {
    std::vector<int> vec = {5, 5, 5, 5, 5};
    SegmentTree<int> tree(vec);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(6), std::nullopt);
}

// Test UpdateElement functionality
TEST_F(SegmentTreeTest, UpdateElement) {
    std::vector<int> vec = {1, 5, 3, 9, 2};
    SegmentTree<int> tree(vec);

    // Initial state verification
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 0);   // Should find 1 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2), 1);   // Should find 5 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 1);   // Should find 5 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(8), 3);   // Should find 9 at index 3

    // Update element at index 4 from 2 to 6 - array becomes {1, 5, 3, 9, 6}
    tree.UpdateElement(4, 6);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5), 1);   // Should still find 5 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(6), 3);   // Should now find 6 at index 4

    // Update element at index 2 from 3 to 7 - array becomes {1, 5, 7, 9, 6}
    tree.UpdateElement(2, 7);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(6), 2);   // Should now find 7 at index 2
    EXPECT_EQ(tree.FindFirstElementGreaterThan(7), 2);   // Should find 7 at index 2

    // Update element at index 0 from 1 to 4 - array becomes {4, 5, 7, 9, 6}
    tree.UpdateElement(0, 4);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(3), 0);   // Should find 4 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 0);   // Should find 4 at index 0

    // Update element at index 3 from 9 to 0 - array becomes {4, 5, 7, 0, 6}
    tree.UpdateElement(3, 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(8), std::nullopt);  // No element >= 8
    EXPECT_EQ(tree.FindFirstElementGreaterThan(7), 2);   // Should find 7 at index 2
}

// Test UpdateElement with multiple updates
TEST_F(SegmentTreeTest, MultipleUpdates) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    SegmentTree<int> tree(vec);

    // Update all elements to same value
    for (size_t i = 0; i < vec.size(); ++i) {
        tree.UpdateElement(i, 10);
    }

    EXPECT_EQ(tree.FindFirstElementGreaterThan(9), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(10), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(11), std::nullopt);

    // Update elements to different values - array becomes {1, 10, 5, 10, 15}
    tree.UpdateElement(0, 1);
    tree.UpdateElement(2, 5);
    tree.UpdateElement(4, 15);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 0);   // Find 1 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(4), 1);   // Find 10 at index 1 (first >= 4)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(10), 1);  // Find 10 at index 1 (first >= 10)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(12), 4);  // Find 15 at index 4
}

// Test with negative numbers
TEST_F(SegmentTreeTest, NegativeNumbers) {
    std::vector<int> vec = {-5, -1, -3, 2, 0};
    SegmentTree<int> tree(vec);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(-6), 0);  // Find -5 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(-5), 0);  // Find -5 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(-4), 1);  // Find -1 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(-1), 1);  // Find -1 at index 1
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0), 3);   // Find 0 at index 3
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1), 3);   // Find 2 at index 3
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2), 3);   // Find 2 at index 3
    EXPECT_EQ(tree.FindFirstElementGreaterThan(3), std::nullopt);
}

// Test with floating point numbers
TEST_F(SegmentTreeTest, FloatingPointNumbers) {
    std::vector<double> vec = {1.5, 3.7, 2.1, 4.9, 0.8};
    SegmentTree<double> tree(vec);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(0.0), 0);   // Find 1.5 at index 0 (first >= 0.0)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(0.8), 0);   // Find 1.5 at index 0 (first >= 0.8)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1.0), 0);   // Find 1.5 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1.5), 0);   // Find 1.5 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2.0), 1);   // Find 3.7 at index 1 (first >= 2.0)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(3.0), 1);   // Find 3.7 at index 1 (first >= 3.0)
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5.0), std::nullopt);

    // Test update with floating point
    tree.UpdateElement(0, 6.0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(5.5), 0);   // Find 6.0 at index 0
}

// Test edge cases
TEST_F(SegmentTreeTest, EdgeCases) {
    // Large single element
    std::vector<int> vec = {INT_MAX};
    SegmentTree<int> tree(vec);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(INT_MAX), 0);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(INT_MAX - 1), 0);

    // Small single element
    std::vector<int> vec2 = {INT_MIN};
    SegmentTree<int> tree2(vec2);

    EXPECT_EQ(tree2.FindFirstElementGreaterThan(INT_MIN), 0);
    EXPECT_EQ(tree2.FindFirstElementGreaterThan(INT_MIN + 1), std::nullopt);
}

// Test with large array
TEST_F(SegmentTreeTest, LargeArray) {
    std::vector<int> vec;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(i * 2);  // 0, 2, 4, 6, 8, ... 1998
    }
    SegmentTree<int> tree(vec);

    EXPECT_EQ(tree.FindFirstElementGreaterThan(-1), 0);    // Find 0 at index 0
    EXPECT_EQ(tree.FindFirstElementGreaterThan(100), 50);  // Find 100 at index 50
    EXPECT_EQ(tree.FindFirstElementGreaterThan(999), 500); // Find 1000 at index 500
    EXPECT_EQ(tree.FindFirstElementGreaterThan(1998), 999); // Find 1998 at index 999
    EXPECT_EQ(tree.FindFirstElementGreaterThan(2000), std::nullopt);

    // Test update in large array
    tree.UpdateElement(500, 50);
    EXPECT_EQ(tree.FindFirstElementGreaterThan(49), 25);  // Should find 50 at index 25 (value=50), not index 500
}
