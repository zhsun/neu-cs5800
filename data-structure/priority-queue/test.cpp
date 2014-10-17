#include "data-structure/priority-queue/priority_queue.hpp"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(PriorityQueueTest, EmptyQueue) {
  PriorityQueue<int> empty_q;
  EXPECT_THAT(empty_q.IsEmpty(), Eq(true));
}

TEST(PriorityQueueTest, LessThanComparator) {
  PriorityQueue<char,less<char>> q;
  q.Insert('d',4);
  q.Insert('b',2);
  q.Insert('a',1);
  q.Insert('f',6);
  q.Insert('e',5);
  q.Insert('c',3);
  EXPECT_THAT(q.IsEmpty(), Eq(false));
  EXPECT_THAT(q.GetMax(), Eq('f'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('e'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('d'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('c'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('b'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('a'));
  q.Delete();
  EXPECT_THAT(q.IsEmpty(), Eq(true));
}

TEST(PriorityQueueTest, GreaterThanComparator) {
  PriorityQueue<char,greater<char>> q;
  q.Insert('d',4);
  q.Insert('b',2);
  q.Insert('a',1);
  q.Insert('f',6);
  q.Insert('e',5);
  q.Insert('c',3);
  EXPECT_THAT(q.IsEmpty(), Eq(false));
  EXPECT_THAT(q.GetMax(), Eq('a'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('b'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('c'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('d'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('e'));
  q.Delete();
  EXPECT_THAT(q.GetMax(), Eq('f'));
  q.Delete();
  EXPECT_THAT(q.IsEmpty(), Eq(true));
}
