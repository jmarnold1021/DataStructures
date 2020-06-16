#define CATCH_CONFIG_MAIN

// Native Deps...if needed
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

TEST_CASE( "LinkedList Add, Access, Copy" ) {

    // notice the difference in destruction depending on ptr vs reference usage
    LinkedList<string>* fixture = new LinkedList<string>();
    fixture->add("s0");
    fixture->add("s1");
    REQUIRE( fixture->access(0) == "s0" );
    REQUIRE( fixture->access(1) == "s1" );

    REQUIRE_THROWS_AS(fixture->access(2), std::out_of_range);

    cout<<"Fixture: "<<*fixture<<endl;

    LinkedList<string> copy = LinkedList<string>(*fixture); // automatically destructs due to end of function scope
    REQUIRE( copy.access(0) == "s0" );
    REQUIRE( copy.access(1) == "s1" );
    cout<<"Copy: "<<copy<<endl;

    delete fixture; // explicitly destructed since fixture is a heap address and exists outside of the function scope
}

TEST_CASE( "LinkedList Assignment/Implicit Copy" ){

    LinkedList<int> fixture = LinkedList<int>();
    fixture.add(0);
    fixture.add(1);
    cout<<fixture<<endl;

    // since copy has not been initialized the copy
    // constructor is called implicitly
    LinkedList<int> copy = fixture;
    REQUIRE( copy.size() == 2 );
    REQUIRE( copy.access(0) == 0 );
    REQUIRE( copy.access(1) == 1 );

    cout<<"Copy : "<<copy<<endl;

    LinkedList<int> fixture2 = LinkedList<int>();
    fixture2.add(1);
    fixture2.add(2);
    cout<<fixture2<<endl;

    // Since copy has been initialized above the
    // assignment operator function will be called
    copy = fixture2;
    REQUIRE( copy.size() == 2 );
    REQUIRE( copy.access(0) == 1 );
    REQUIRE( copy.access(1) == 2 );
    cout<<"Copy :"<<copy<<endl;

    // will call assignment operator
    // but since they are the same reference
    // will just return copy.
    copy = copy;
    REQUIRE( copy.size() == 2 );
    REQUIRE( copy.access(0) == 1 );
    REQUIRE( copy.access(1) == 2 );
    cout<<"Duplicate :"<<copy<<endl;

    // now empty the copy by assigning an empty
    // list to it.
    LinkedList<int> empty = LinkedList<int>();
    copy = empty;
    REQUIRE( copy.size() == 0 );
    REQUIRE( copy.isEmpty() == 1 );
    cout<<"Empty :"<<copy<<endl;
}

