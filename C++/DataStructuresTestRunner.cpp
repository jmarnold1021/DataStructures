#define CATCH_CONFIG_MAIN

// Native Deps...
//#include <iostream>
//#include <vector>
//#include <string>

// The testing framework
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
#include "catch.hpp"

// Our stuff
#include "LinkedList.hpp"

using namespace std;


TEST_CASE( "LinkedList Add and Access" ) {
    LinkedList<string> fixture = LinkedList<string>();
    fixture.add("s0");
    fixture.add("s1");
    REQUIRE( fixture.access(0) == "s0" );
    REQUIRE( fixture.access(1) == "s1" );
}