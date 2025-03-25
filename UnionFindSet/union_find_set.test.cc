#include "union_find_set.h"
#include <gtest/gtest.h>

TEST(UnionFindSetTest, Initialization) {
  UnionFindSet ufs(10);
  EXPECT_EQ(ufs.ElementNumber(), 10);
  EXPECT_EQ(ufs.SetNumber(), 10);
}

TEST(UnionFindSetTest, AddSet) {
  UnionFindSet ufs(5);
  ufs.AddSet();
  EXPECT_EQ(ufs.ElementNumber(), 6);
  EXPECT_EQ(ufs.SetNumber(), 6);
}

TEST(UnionFindSetTest, UnionTheSameElement) {
  UnionFindSet ufs(5);
  ufs.Union(2, 2);
  EXPECT_EQ(ufs.Find(2), ufs.Find(2));
  EXPECT_EQ(ufs.SetNumber(), 5);
}

TEST(UnionFindSetTest, UnionAndFind) {
  UnionFindSet ufs(5);
  ufs.Union(0, 1);
  EXPECT_EQ(ufs.Find(0), ufs.Find(1));
  EXPECT_EQ(ufs.SetNumber(), 4);
}

TEST(UnionFindSetTest, UnionMultiple) {
  UnionFindSet ufs(5);
  ufs.Union(0, 1);
  ufs.Union(1, 2);
  EXPECT_EQ(ufs.Find(0), ufs.Find(2));
  EXPECT_EQ(ufs.SetNumber(), 3);
}

TEST(UnionFindSetTest, SetSizeOfElement) {
  UnionFindSet ufs(5);
  ufs.Union(0, 1);
  ufs.Union(1, 2);
  EXPECT_EQ(ufs.SetSizeOfElement(0), 3);
  EXPECT_EQ(ufs.SetSizeOfElement(3), 1);
}

TEST(UnionFindSetTest, IsInOneSet) {
  UnionFindSet ufs(5);
  ufs.Union(0, 1);
  EXPECT_TRUE(ufs.IsInOneSet(0, 1));
  EXPECT_FALSE(ufs.IsInOneSet(0, 2));
}

TEST(UnionFindSetTest, IsSetRootElement) {
  UnionFindSet ufs(5);
  ufs.Union(0, 1);
  EXPECT_TRUE(ufs.IsSetRootElement(ufs.Find(0)));
  EXPECT_FALSE(ufs.IsSetRootElement(1));
}

TEST(UnionFindSetTest, FindNonExistentElement) {
  UnionFindSet ufs(5);
  EXPECT_EXIT(ufs.Find(10), ::testing::KilledBySignal(SIGABRT), ".*");
}

TEST(UnionFindSetTest, UnionNonExistentElements) {
  UnionFindSet ufs(5);
  EXPECT_EXIT(ufs.Union(0, 10), ::testing::KilledBySignal(SIGABRT), ".*");
  EXPECT_EXIT(ufs.Union(10, 0), ::testing::KilledBySignal(SIGABRT), ".*");
}

TEST(UnionFindSetTest, SetSizeOfNonExistentElement) {
  UnionFindSet ufs(5);
  EXPECT_EXIT(ufs.SetSizeOfElement(10), ::testing::KilledBySignal(SIGABRT), ".*");
}

TEST(UnionFindSetTest, IsInOneSetNonExistentElements) {
  UnionFindSet ufs(5);
  EXPECT_EXIT(ufs.IsInOneSet(0, 10), ::testing::KilledBySignal(SIGABRT), ".*");
  EXPECT_EXIT(ufs.IsInOneSet(10, 0), ::testing::KilledBySignal(SIGABRT), ".*");
}

TEST(UnionFindSetTest, IsSetRootElementNonExistentElement) {
  UnionFindSet ufs(5);
  EXPECT_EXIT(ufs.IsSetRootElement(10), ::testing::KilledBySignal(SIGABRT), ".*");
}

TEST(UnionFindSetTest, EmptyUnionFindSet) {
  UnionFindSet ufs(0);
  EXPECT_EQ(ufs.ElementNumber(), 0);
  EXPECT_EQ(ufs.SetNumber(), 0);
  EXPECT_EXIT(ufs.Find(0), ::testing::KilledBySignal(SIGABRT), ".*");
  EXPECT_EXIT(ufs.Union(0, 1), ::testing::KilledBySignal(SIGABRT), ".*");
  EXPECT_EXIT(ufs.SetSizeOfElement(0), ::testing::KilledBySignal(SIGABRT), ".*");
  EXPECT_EXIT(ufs.IsInOneSet(0, 1), ::testing::KilledBySignal(SIGABRT), ".*");
  EXPECT_EXIT(ufs.IsSetRootElement(0), ::testing::KilledBySignal(SIGABRT), ".*");
}
