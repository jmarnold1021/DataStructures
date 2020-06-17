#define CATCH_CONFIG_MAIN

// Native Deps...if needed
// #include <iostream>
// #include <vector>
// #include <string>
 #include <sstream>

// The testing framework
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
// ton of cool stuff in here...
#include "catch.hpp"

// Our stuff
#include "LinkedList.hpp"

using namespace std;


TEST_CASE( "LinkedList Add, Stream" ) {

    stringstream buffer;

    LinkedList<string> l0 = LinkedList<string>();
    buffer<<l0;
    REQUIRE( buffer.str() == "[]" );

    buffer.str(""); // http://www.cplusplus.com/forum/general/51686/
                    // clearing may be necessary also in the event of
                    // and error in the stream. i.e. buffer.clear();

    LinkedList<string> l1 = LinkedList<string>();
    l1.add("s0");
    buffer<<l1;
    REQUIRE( buffer.str() == "[s0]" );

    buffer.str("");

    LinkedList<string> l2 = LinkedList<string>();
    l2.add("s0");
    l2.add("s1");
    buffer<<l2;
    REQUIRE( buffer.str() == "[s0, s1]" );
       
    buffer.str("");
}

TEST_CASE( "LinkedList Add, Access, Copy" ) {

    // notice the difference in destruction depending on ptr vs reference usage
    LinkedList<string>* fixture = new LinkedList<string>();
    fixture->add("s0");
    fixture->add("s1");
    REQUIRE( fixture->access(0) == "s0" );
    REQUIRE( fixture->access(1) == "s1" );

    REQUIRE_THROWS_AS(fixture->access(2), out_of_range);

    //cout<<"Fixture: "<<*fixture<<endl;

    LinkedList<string> copy = LinkedList<string>(*fixture); // automatically destructs due to end of function scope
    REQUIRE( copy.access(0) == "s0" );
    REQUIRE( copy.access(1) == "s1" );
    //cout<<"Copy: "<<copy<<endl;

    delete fixture; // explicitly destructed since fixture is a heap address and exists outside of the function scope
}

TEST_CASE( "LinkedList Assignment/Implicit Copy" ){

    LinkedList<int> fixture = LinkedList<int>();
    fixture.add(0);
    fixture.add(1);
    //cout<<fixture<<endl;

    // since copy has not been initialized the copy
    // constructor is called implicitly
    LinkedList<int> copy = fixture;
    REQUIRE( copy.size() == 2 );
    REQUIRE( copy.access(0) == 0 );
    REQUIRE( copy.access(1) == 1 );
    //cout<<"Copy : "<<copy<<endl;

    LinkedList<int> fixture2 = LinkedList<int>();
    fixture2.add(1);
    fixture2.add(2);
    //cout<<fixture2<<endl;

    // Since copy has been initialized above the
    // assignment operator function will be called
    copy = fixture2;
    REQUIRE( copy.size() == 2 );
    REQUIRE( copy.access(0) == 1 );
    REQUIRE( copy.access(1) == 2 );
    //cout<<"Copy :"<<copy<<endl;

    // will call assignment operator
    // but since they are the same reference
    // will just return copy.
    copy = copy;
    REQUIRE( copy.size() == 2 );
    REQUIRE( copy.access(0) == 1 );
    REQUIRE( copy.access(1) == 2 );
    //cout<<"Duplicate :"<<copy<<endl;

    // now empty the copy by assigning an empty
    // list to it.
    copy = LinkedList<int>();
    REQUIRE( copy.size() == 0 );
    REQUIRE( copy.isEmpty() == 1 );
    //cout<<"Empty :"<<copy<<endl;
}

TEST_CASE( "LinkedList removeFront" ) {

    LinkedList<int> fixture = LinkedList<int>();
    fixture.add(0);
    fixture.add(1);
    fixture.add(2);

    cout<<fixture<<endl;
    
    int front = fixture.removeFront();
    cout<<"Front Element: "<<front<<endl;
    cout<<fixture<<endl;

    front = fixture.removeFront();
    cout<<"Front Element: "<<front<<endl;
    cout<<fixture<<endl;

    front = fixture.removeFront();
    cout<<"Front Element: "<<front<<endl;
    cout<<fixture<<endl;

    cout<<"Empty?: "<<fixture.isEmpty()<<endl;

    REQUIRE_THROWS_AS(fixture.removeFront(), out_of_range);
}

TEST_CASE( "LinkedList removeBack" ) {

    LinkedList<int> fixture = LinkedList<int>();
    fixture.add(0);
    fixture.add(1);
    fixture.add(2);

    cout<<fixture<<endl;
    
    int back = fixture.removeBack();
    cout<<"Back Element: "<<back<<endl;
    cout<<fixture<<endl;

    back = fixture.removeBack();
    cout<<"Back Element: "<<back<<endl;
    cout<<fixture<<endl;

    back = fixture.removeBack();
    cout<<"Back Element: "<<back<<endl;
    cout<<fixture<<endl;

    cout<<"Empty?: "<<fixture.isEmpty()<<endl;

    REQUIRE_THROWS_AS(fixture.removeBack(), out_of_range);
}

TEST_CASE( "hmmm" ){
    LinkedList<int> l1 = LinkedList<int>();
    l1.add(0);
    l1.add(1);
    l1.add(2);

    LinkedList<int> l2 = LinkedList<int>();
    l2.add(0);
    l2.add(1);
    l2.add(2);

    LinkedList<LinkedList<int>> fixture = LinkedList<LinkedList<int>>();
    fixture.add(l1);
    fixture.add(l2);

    cout<<fixture.access(0)<<endl;
}

TEST_CASE( "triple down!" ){
    LinkedList<int> l1 = LinkedList<int>();
    l1.add(0);
    l1.add(1);
    l1.add(2);

    LinkedList<LinkedList<int>> l2 = LinkedList<LinkedList<int>>();
    l2.add(l1);

    LinkedList<LinkedList<LinkedList<int>>> fixture = LinkedList<LinkedList<LinkedList<int>>>();
    fixture.add(l2);

    cout<<fixture.access(0).access(0).access(0)<<endl;

}

