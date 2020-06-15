#define CATCH_CONFIG_MAIN

// Native Deps...
// #include <iostream>
// #include <vector>
// #include <string>

// The testing framework
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
// ton of cool stuff in here...
#include "catch.hpp"

// Our stuff
#include "LinkedList.hpp"

using namespace std;

TEST_CASE( "LinkedList Add and Access" ) {

    // notice the difference in destruction depending on ptr vs reference usage
    LinkedList<string>* fixture = new LinkedList<string>();
    fixture->add("s0");
    fixture->add("s1");
    REQUIRE( fixture->access(0) == "s0" );
    REQUIRE( fixture->access(1) == "s1" );
    cout<<"Fixture: "<<*fixture<<endl;

    LinkedList<string> copy = LinkedList<string>(*fixture); // automatically destructs due to end of function scope
    REQUIRE( copy.access(0) == "s0" );
    REQUIRE( copy.access(1) == "s1" );
    cout<<"Copy: "<<copy<<endl;

    delete fixture; // explicitly destructed since fixture is a heap address and exists outside of the function scope

    LinkedList<int> fixture2 = LinkedList<int>();
    fixture2.add(0);
    fixture2.add(1);
    LinkedList<int> assign = fixture2;
    cout<<"Fixture 2: "<<fixture2<<endl;
    cout<<"Assign : "<<assign<<endl;
    

    LinkedList<bool> empty = LinkedList<bool>();
    LinkedList<bool> emptyAssign = empty;
    cout<<"Empty : "<<empty<<endl;
    cout<<"EmptyAssign : "<<emptyAssign<<endl;
}

