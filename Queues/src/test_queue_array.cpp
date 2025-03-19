#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <string>
#include "QueueArray.h"
using namespace std;

/* TEST_CASE("Test basic queue operations on queue of strings") {
    Queue<string> queue;
    CHECK(queue.empty() == true);
    queue.insert("first");
    CHECK(queue.empty() == false);
    queue.insert("second");
    queue.insert("third");
    CHECK(queue.remove() == "first");
    queue.insert("forth");
    queue.insert("fifth");
    queue.insert("sixth");
    queue.insert("seventh");
    queue.insert("eight");
    queue.insert("nineth");
    CHECK(queue.remove() == "second");
    CHECK(queue.remove() == "third");
    queue.insert("tenth");
    queue.insert("eleventh");
    CHECK(queue.remove() == "forth");
    queue.insert("twelfth");
    queue.insert("thirteenth");
    CHECK(queue.remove() == "fifth");
}
*/

TEST_CASE("Test can create empty PriorityQueue") {
    Queue<string> pq;
    CHECK(pq.empty() == true);
}
TEST_CASE("Test can insert and remove items in PriorityQueue") {
    Queue<int> pq;
    pq.insert(10);
    CHECK(pq.empty() == false);
    CHECK(pq.remove() == 10);
    CHECK(pq.empty() == true);
    pq.insert(12);
    pq.insert(8);
    CHECK(pq.remove() == 12);
    CHECK(pq.remove() == 8);
    CHECK(pq.empty() == true);
    pq.insert(9);
    pq.insert(6);
    pq.insert(7);
    CHECK(pq.remove() == 9);
    CHECK(pq.remove() == 7);
    CHECK(pq.remove() == 6);
    CHECK(pq.empty() == true);
    pq.insert(14);
    pq.insert(11);
    pq.insert(42);
    CHECK(pq.remove() == 42);
    CHECK(pq.remove() == 14);
    CHECK(pq.remove() == 11);
    CHECK(pq.empty() == true);
    pq.insert(14);
    pq.insert(11);
    pq.insert(42);
    pq.insert(6);
    CHECK(pq.remove() == 42);
    CHECK(pq.remove() == 14);
    CHECK(pq.remove() == 11);
    CHECK(pq.remove() == 6);
    CHECK(pq.empty() == true);
    pq.insert(14);
    pq.insert(11);
    pq.insert(42);
    pq.insert(6);
    pq.insert(16);
    CHECK(pq.remove() == 42);
    CHECK(pq.remove() == 16);
    CHECK(pq.remove() == 14);
    CHECK(pq.remove() == 11);
    CHECK(pq.remove() == 6);
    CHECK(pq.empty() == true);
    pq.insert(14);
    pq.insert(11);
    pq.insert(42);
    pq.insert(6);
    pq.insert(16);
    pq.insert(8);
    pq.insert(2);
    CHECK(pq.remove() == 42);
    CHECK(pq.remove() == 16);
    CHECK(pq.remove() == 14);
    CHECK(pq.remove() == 11);
    CHECK(pq.remove() == 8);
    CHECK(pq.remove() == 6);
    CHECK(pq.remove() == 2);
    CHECK(pq.empty() == true);
}