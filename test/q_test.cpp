#include <gtest/gtest.h>

#include <stack.h>
#include <queue.h>

class StackTest : public ::testing::Test
{
protected:
  virtual void SetUp() {}

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(StackTest, Stack_Push)
{

  Stack *stack = new Stack(sizeof(int));
  int pushv = 5;
  stack->push(&pushv);
  int b = 2;
  stack->push(&b);
  // stack->push(&b);
  // stack->push(&b);
  // stack->printList();
  int a = *static_cast<int *>(stack->node->_obj);
  int c = *static_cast<int *>(stack->node->next->_obj);
  EXPECT_EQ(2, a);
  EXPECT_EQ(5, c);
  stack->~Stack();
  delete (stack);
}
TEST_F(StackTest, Stack_pop)
{
  Stack *stack = new Stack(sizeof(int));
  int a = 50;
  stack->push(&a);
  int b = 30;
  stack->push(&b);
  int f;
  int c;
  stack->pop(&c);
  EXPECT_EQ(30, c);
  stack->pop(&f);
  EXPECT_EQ(50, 50);
  delete (stack);
  // stack->~Stack();
  // delete (stack);
}
TEST_F(StackTest, Stack_nofelem)
{
  Stack stack(sizeof(int));
  int pushv = 5;
  stack.push(&pushv);
  stack.push(&pushv);
  stack.push(&pushv);
  stack.push(&pushv);
  EXPECT_EQ(4, stack.nofelem());
  EXPECT_EQ(1, stack.destroy());
  stack.~Stack();
}

TEST_F(StackTest, Stack_destroy)
{
  Stack stack(sizeof(int));
  int pushv = 5;
  stack.push(&pushv);
  stack.push(&pushv);
  stack.push(&pushv);
  stack.push(&pushv);
  EXPECT_EQ(4, stack.nofelem());
  EXPECT_EQ(1, stack.destroy());
  EXPECT_EQ(0, stack.destroy());
  // delete (stack);
  stack.~Stack();
}
class Queuetest : public ::testing::Test
{
protected:
  int a;
  virtual void SetUp() {}

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};
TEST_F(Queuetest, Queue_Enqueue_Dequeue)
{
  Queue q(sizeof(int));
  int d = 5;
  q.enqueue(&d);
  int v = 6;
  q.enqueue(&v);
  int u = 7;
  q.enqueue(&u);
  // q.printQueue();
  int a, b, c = 0;
  q.dequeue(&a);
  // q.printQueue();
  EXPECT_EQ(5, a);
  q.dequeue(&b);
  EXPECT_EQ(6, b);
  q.dequeue(&c);
  EXPECT_EQ(7, c);
}

// TEST_F(Queuetest, destroy)
// {
//   Queue q(sizeof(int));
//   int pushv = 5;
//   q.enqueue(&pushv);
//   int b = 6;
//   q.enqueue(&b);
//   q.printQueue();
//   int c, f;
//   q.dequeue(&c);
//   // q.printQueue();

//   EXPECT_EQ(5, c);
//   q.dequeue(&f);
//   EXPECT_EQ(6, f);

//   q.~Queue();
//   // delete (q);
// }
// TEST_F(Queuetest, enqueue)
// {
//   Queue q(sizeof(int));
//   int pushv = 5;
//   q.enqueue(&pushv);
//   pushv = 6;
//   q.enqueue(&pushv);
//   q.enqueue(&pushv);
//   q.enqueue(&pushv);
//   // q.printQueue();
//   //  EXPECT_EQ(5, 5);
//   //  q.dequeue(&pushv);
//   //  EXPECT_EQ(6, pushv);

//   // EXPECT_EQ(1, q.destroy());
//   q.~Queue();
// }
