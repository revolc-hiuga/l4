#include "doctest.h"
#include "..\include\str.h"

TEST_CASE("check_normal_string") {
    CHECK(trim("123") == "123");
    CHECK(trim("123  123") == "123  123");
}

TEST_CASE("check_string_with_space") {
    CHECK(trim("  123  ") == "123");
    CHECK(trim("  123  123  ") == "123  123");
    CHECK(trim("123  123  ") == "123  123");
    CHECK(trim("  123  123") == "123  123");
}
