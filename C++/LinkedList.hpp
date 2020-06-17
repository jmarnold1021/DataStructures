#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <stdexcept>


using namespace std;

template<typename Data>
class LinkedList {


  private:  
    template<typename T> // variable type T will be filled with Data variable type
    class Node{

      public:
        Node( const Data &d ) : data(d), next(nullptr) {}
        const Data data;
        Node<T>* next;
    };

    Node<Data>* head;
    Node<Data>* tail;
    int length;

    Node<Data>* getHead() const {
      return this -> head;
    }

    Node<Data>* getTail() const {
      return this -> tail;
    }
		
  public:

    //Default constructor
    LinkedList() : head(nullptr), tail(nullptr), length(0){
      cout<<"Created List(default): "<<this<<endl;
    }


    //Copy constructor
    LinkedList(const LinkedList<Data> &src) {

      // this->* may have garbage values hence the explict defaults
      // before building the list.
      // https://www.quora.com/What-do-you-mean-by-a-garbage-value-in-a-variable#:~:text=Allocating%20a%20variable%20implies%20reserving,piece%20of%20the%20computer's%20memory.
      this -> head = nullptr;
      this -> tail = nullptr;
      this -> length = 0;

      if( !src.isEmpty() ){
        
        // 1st element
        Node<Data>* itr = src.getHead();
        this -> tail = new Node<Data>(itr -> data);
        this -> head = this -> tail;
        ++(this -> length);
        itr = itr -> next;

        // rest of elements
        while( itr != nullptr ){
          (this -> tail) -> next = new Node<Data>(itr -> data);
          this -> tail = (this -> tail) -> next;
          ++(this -> length);
          itr = itr -> next;
        }
      }
      cout<<"Created List(copy): "<<this<<endl;
    }



    virtual ~LinkedList(){ //virtual so that classes extending LinkedList
                           //can redefine the destructor
                           //i.e override the destructor

      cout<<"Destructing List: "<<this<<endl;
      this -> empty();
    }

    

    virtual void empty() {

      while(this->head != nullptr){  
        Node<Data>* tmp = (this -> head) -> next;
        delete this->head;
        this->head = tmp;
      }

      this -> length = 0;
      this -> head = nullptr;
      this -> tail = nullptr;
    }



    virtual const Data access(int pos) const{  //searches from head to tail O(n - 1)

      // https://en.cppreference.com/w/cpp/language/ub
      // https://stackoverflow.com/questions/60943480/what-does-c-stdlistfront-return-with-an-empty-list
      // https://en.wiktionary.org/wiki/PEBCAK
      // atm this check is a place holder for nice TestSuite Functionality
      if( pos >= (this -> length) ){
        throw out_of_range( "Given position is outside of the List's Size" );
      }

      if(pos == 0){
        return (this -> head) -> data;
      }

      if( pos == (this -> length) - 1 ){
        return (this -> tail) -> data;
      }

      Node<Data>* tmp = this -> head;
      for(int i = 1 ; i <= pos ; ++i){
        tmp = tmp -> next;
      }

      return tmp -> data;
    }



    ostream & buildStream(ostream & stm) const{// const allows function to be called by const objects
                                                         // i.e. tells the compiler that the function will
                                                         // not change the const object

      // empty
      if( this -> head == nullptr){
        return stm << "[]";
      }

      // more than 1 element
      stm << '[';
      Node<Data>* itr = this -> head;
      while( itr -> next != nullptr ){
        
        stm << itr -> data;
        stm << ", ";
        itr = itr -> next;
      }

      // 1 or last element
      stm << itr -> data;
      stm << ']';
      return stm;
    }



    virtual bool isEmpty() const {
      if( this -> head == nullptr ) {
        return true;
      }
      return false;
    }



    virtual int size() const {
      return this -> length;
    }



    virtual void add( const Data &data ){ // O(1)

      // since data field is const it must be initialized through the constructor!!!

      Node<Data>* newNode = new Node<Data>(data);

      if( this -> head == nullptr ) {

        this -> tail = newNode;
        this -> head = this -> tail;
      } else {

        (this -> tail) -> next = newNode;
        this -> tail = (this -> tail) -> next;
      }
      ++(this -> length);
    }



    virtual const Data removeFront(){ // O(1)

      // https://en.cppreference.com/w/cpp/language/ub
      // https://stackoverflow.com/questions/60943480/what-does-c-stdlistfront-return-with-an-empty-list
      // https://en.wiktionary.org/wiki/PEBCAK
      // atm this check is a place holder for nice TestSuite Functionality
      if( this -> head == nullptr ) {
        throw out_of_range( "Cannot retrieve front of an Empty List" );
      }

      const Data data = (this -> head) -> data; //store heads data
      Node<Data>* tmp = (this -> head) -> next; //find next node for head
      delete this -> head;
      this -> head = tmp;
      --(this -> length);

      return data;
    }


    // this one is hard.
    virtual const Data removeBack(){ // O(n)

      // https://en.cppreference.com/w/cpp/language/ub
      // https://stackoverflow.com/questions/60943480/what-does-c-stdlistfront-return-with-an-empty-list
      // https://en.wiktionary.org/wiki/PEBCAK
      // ATM this check is a place holder for nice TestSuite Functionality
      if( this -> head == nullptr ) {
        throw out_of_range( "Cannot retrieve back of an Empty List" );
      }

      const Data data = (this -> tail) -> data; //store tails data

      if( this -> head == this -> tail){
        delete this -> tail;
        this -> head = nullptr;
        this -> tail = nullptr;
        --(this -> length);
        return data;

      }

      Node<Data>* itr = this -> head; //find next node for tail
      while( itr -> next != this -> tail ){
        itr = itr -> next;
      }
      itr -> next = nullptr; // need to explicitly break this link
                             // or future iterators(aka destructor) will
                             // follow it.

      delete this -> tail;
      this -> tail = itr;
      --(this -> length);
      return data;
    }



    virtual const Data front() const{ // O(1)

      return (this -> head) -> data;
    }



    virtual const Data back() const{ // O(1)

      return (this -> tail) -> data;
    }



    LinkedList<Data>& operator=(const LinkedList<Data> &src){

      // pretty sure we should build a new list with same elements
      // and reassign it to the same ref but...could go either way.
      if(this == &src){
        cout<<"Return/Assign duplicate list: "<<this<<endl;
        return *this;
      }

      // this operator function is only called if "this" is not empty
      // but to be safe going to check anyway
      if( !this -> isEmpty() ){
        cout<<"Empty/Assign new list: "<<this<<endl;
        this -> empty();
      }

      if( !src.isEmpty() ){
        
        Node<Data>* itr = src.getHead();

        // 1st element
        this -> tail = new Node<Data>(itr -> data);
        this -> head = this -> tail;
        ++(this -> length);
        itr = itr -> next;

        // rest of elements
        while( itr != nullptr ){
          (this -> tail) -> next = new Node<Data>(itr -> data);
          this -> tail = (this -> tail) -> next;
          ++(this -> length);
          itr = itr -> next;
        }
      }
      return *this;
    }
  };

template<typename Data>
ostream & operator<<(ostream &stm, const LinkedList<Data> &n ) {//no implicit 1st parameter
                                                                //since this is not a mem func
   return n.buildStream(stm);

}

#endif
