#define CATCH_CONFIG_MAIN

// Native Deps...if needed
// #include <iostream>
// #include <vector>
// #include <string>
#include <sstream>
#include <vector>

// The testing framework
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
// ton of cool stuff in here...
#include "catch.hpp"

// Our stuff
#include "LinkedList.hpp"
#include "TernaryTrie.hpp"

using namespace std;


TEST_CASE( "LinkedList Add, Stream" ) {

    stringstream buffer;

    LinkedList<string> l0 = LinkedList<string>();
    buffer<<l0;
    REQUIRE( buffer.str() == "[]" );

    buffer.str(""); // http://www.cplusplus.com/forum/general/51686/
    buffer.clear(); // clearing may be necessary also in the event of
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

/** TERNARY TRIE */
TEST_CASE( "Word Constuctor" ) {


    Trie dict = Trie("aba");
    REQUIRE( dict.contains("aba") == true );

    dict.add("baa");
    dict.add("bab");
    
    dict.add("aaab");
    dict.add("aaa");
    dict.add("aaaa");
    
    dict.add("aaba");

    REQUIRE( dict.contains("baa") == true );
    REQUIRE( dict.contains("bab") == true );
    REQUIRE( dict.contains("aaab") == true );
    REQUIRE( dict.contains("aaa") == true );
    REQUIRE( dict.contains("aaaa") == true );
    REQUIRE( dict.contains("aaba") == true );

    REQUIRE( dict.starts_with("aa") == true );

    REQUIRE( dict.contains("aa") == false );
    dict.add("aa");
    REQUIRE( dict.contains("aa") == true );

    dict.add("c");
    REQUIRE( dict.contains("c") == true );
    REQUIRE( dict.starts_with("c") == true );

   REQUIRE( dict.starts_with("cc") == false );
   dict.add("ccc");
   REQUIRE( dict.starts_with("cc") == true );
   dict.add("cc");
   REQUIRE( dict.starts_with("cc") == true );
   REQUIRE( dict.contains("cc") == true );

   REQUIRE( dict.contains("cccccc") == false );


}

TEST_CASE( "Default Constructor" ) {
    Trie dict = Trie();
    dict.add("aba");
    REQUIRE( dict.contains("aba") == true );

    dict.add("baa");
    dict.add("bab");
    
    dict.add("aaab");
    dict.add("aaa");
    dict.add("aaaa");
    
    dict.add("aaba");

    REQUIRE( dict.contains("baa") == true );
    REQUIRE( dict.contains("bab") == true );
    REQUIRE( dict.contains("aaab") == true );
    REQUIRE( dict.contains("aaa") == true );
    REQUIRE( dict.contains("aaaa") == true );
    REQUIRE( dict.contains("aaba") == true );

    REQUIRE( dict.starts_with("aa") == true );

    REQUIRE( dict.contains("aa") == false );
    dict.add("aa");
    REQUIRE( dict.contains("aa") == true );

    dict.add("c");
    REQUIRE( dict.contains("c") == true );
    REQUIRE( dict.starts_with("c") == true );

   REQUIRE( dict.starts_with("cc") == false );
   dict.add("ccc");
   REQUIRE( dict.starts_with("cc") == true );
   dict.add("cc");
   REQUIRE( dict.starts_with("cc") == true );
   REQUIRE( dict.contains("cc") == true );
}


/*void find_words( Trie &dict, vector<vector<char>> &board, vector<vector<bool>> &visited, int m, int n, string branch_acc, vector<string> &acc ){
    
    branch_acc+=board[m][n];

    if( dict.contains(branch_acc) ){
        acc.push_back(branch_acc);
    }

    visited[m][n] = true;

    if( m - 1 >= 0 && !visited[m-1][n]){
        find_words(dict, board, visited, m-1, n, branch_acc, acc);    
    }

    if( n - 1 >= 0 && !visited[m][n-1] ) {
        find_words(dict, board, visited, m, n-1 , branch_acc, acc);    
    }

    if( m + 1 < board.size() && !visited[m+1][n]) {
        find_words(dict, board, visited, m+1, n, branch_acc, acc);    
  
    }
    if( n + 1 < board[0].size() && !visited[m][n+1]){
        find_words(dict, board, visited, m, n+1, branch_acc, acc);    
    }

    branch_acc.erase(branch_acc.length() - 1); 
    visited[m][n] = false; 
}*/



/*TEST_CASE( "LEET Word Search" ){
   //["oath","pea","eat","rain"]

   //[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]

    vector<string> words;
    words.push_back("oath");
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");

    vector<char> r1;
    r1.push_back('o');
    r1.push_back('a');
    r1.push_back('a');
    r1.push_back('n');

    vector<char> r2;
    r2.push_back('e');
    r2.push_back('t');
    r2.push_back('a');
    r2.push_back('e');

    vector<char> r3;
    r3.push_back('i');
    r3.push_back('h');
    r3.push_back('k');
    r3.push_back('r');

    vector<char> r4;
    r4.push_back('i');
    r4.push_back('f');
    r4.push_back('l');
    r4.push_back('v');

    vector<vector<char>> board;
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);
    board.push_back(r4);

    
    sort(words.begin(), words.end());

    Trie dict = Trie(words[0]);
    for( int i = 1; i < words.size(); ++i ){
        dict.add(words[i]);
    }
   
    REQUIRE( dict.contains("oath") == true );
    REQUIRE( dict.contains("pea") == true );
    REQUIRE( dict.contains("eat") == true );
    REQUIRE( dict.contains("rain") == true );

    

    vector<bool> v(board[0].size());
    vector<vector<bool>> visited(board.size(),v);
    vector<string> acc;

    for(int i = 0; i < board.size(); ++i ) {
        for( int j = 0 ; j < board[i].size(); ++j ){            
            find_words(dict, board, visited, i, j, "", acc);
        }
    }

    for( int i = 0; i < acc.size(); ++i ){
        cout<<acc[i]<<endl;
    }
}*/
