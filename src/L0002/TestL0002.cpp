#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "L0002.h"

TEST_CASE("L0002", "[L]")
{
    Solution solution;

    SECTION("Example")
    {
        string l1, l2, output;
        std::tie(l1, l2, output) = GENERATE(
            make_tuple("[2, 4, 3]", "[5, 6, 4]", "[7, 0, 8]"),
            make_tuple("[0, 1]", "[0, 1, 2]", "[0, 2, 2]"),
            make_tuple("[]", "[0, 1]", "[0, 1]"),
            make_tuple("[9, 9]", "[1]", "[0, 0, 1]"));
        auto ret = listNodeToString(solution.addTwoNumbers(stringToListNode(l1), stringToListNode(l2)));
        REQUIRE(ret == output);
    }
}
