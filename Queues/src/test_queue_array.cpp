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

TEST_CASE("looking to see if my function actually kinda works"){
    Queue<int> queue;
    queue.insert(5);
    queue.insert(3);
    queue.insert(7);
    CHECK(queue.remove() == 7);
    CHECK(queue.remove() == 5);
    CHECK(queue.remove() == 3);
}