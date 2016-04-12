#include "gmock/gmock.h"
#include "data_structure/disjoint_set.h"

using namespace testing;

TEST(DisjointSetTest, GeneralCase) {
  DisjointSet ds(5);
  EXPECT_THAT(ds.Find(0), Ne(ds.Find(3)));

  ds.Union(1,2);
  EXPECT_THAT(ds.Find(1), Eq(ds.Find(2)));
  EXPECT_THAT(ds.Find(1), Ne(ds.Find(3)));

  ds.Union(3,4);
  EXPECT_THAT(ds.Find(3), Eq(ds.Find(4)));
  EXPECT_THAT(ds.Find(3), Ne(ds.Find(1)));

  ds.Union(2,4);
  EXPECT_THAT(ds.Find(1), Eq(ds.Find(2)));
  EXPECT_THAT(ds.Find(2), Eq(ds.Find(3)));
  EXPECT_THAT(ds.Find(3), Eq(ds.Find(4)));
  EXPECT_THAT(ds.Find(0), Ne(ds.Find(1)));
}
