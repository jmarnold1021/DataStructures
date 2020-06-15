#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename Data>
class LinkedList{


  private:  
    template<typename T>//variable type T will be filled with data variable type
    class Node{

      public:
        Node( const Data &d ) : data(d), next(nullptr) {}

        Data getData() const {
          return this->data; 
        }

        Node<T>* getNext() const {
          return this->next;
        }

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
      cout<<"Created List: "<<this<<endl;
    }

    //Copy constructor
    LinkedList(const LinkedList<Data> &src){

      if( !src.isEmpty() ){

        this->head = new Node<Data>(src.getHead()->getData());
        this->tail = this->head;
        ++(this -> length);

        Node<Data>* src_tmp = src.getHead();
        while( src_tmp != src.getTail() ){
					
          src_tmp = src_tmp->getNext();
          (this->tail)->next = new Node<Data>(src_tmp->getData());
          this->tail = (this->tail)->next;
          ++(this -> length);
        }
      } else { // given an empty list

        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
      }

      cout<<"Created List: "<<this<<endl;
    }

    virtual ~LinkedList(){ //virtual so that classes extending LinkedList
                           //can redefine the destructor
                           //i.e override the destructor

      cout<<"Destructing List: "<<this<<endl;

      if(this->head){  //length at least 1

        while(this->head != this->tail){  //do not base end on whether or not tmp = null!!!!!!
          Node<Data>* tmp = (this->head)->next;
          delete this->head;
          this->head = tmp;
        }

        delete this->head;
      }

      this -> length = 0;
      this -> head = nullptr;
      this -> tail = nullptr;
    }

    
    
    virtual const Data & access(int pos) const{  //searches from head to tail

      if(pos >= (this -> length)){ //throw out of bounds exception
        throw std::out_of_range( "Given position is outside of the List's Size" );
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

    std::ostream & buildStream(std::ostream & stm) const{// const allows function to be called by const objects
      Node<Data>* start = (this -> head);
                                                         //i.e. tells the compiler that the function will
      stm << '[';                                        //     not change the const object
      for(int i = 0 ; i < (this -> length) ; ++i){

        if( i != ((this -> length) - 1) ){

         stm<<(start -> data);
         stm<<", ";
        }
        else{

         stm<<(start -> data);
        }
        start = (start -> next);
      }

      stm << ']';
      return stm;
    }

    virtual bool isEmpty() const {
      if( this -> length == 0 ) {
        return true;
      }
      return false;
    }

    virtual int size() const {
      return this -> length;
    }

    //adds to the back of the list
    virtual void add( const Data &data ){

      //since data field is const it must be initialized through the constructor!!!
      if( !(this -> head) ){

        (this -> head) = new Node<Data>(data);
        (this -> tail) = (this -> head);
      } else {

        ((this -> tail) -> next) = new Node<Data>(data);// only adjust tail
        this->tail = (this -> tail)->next;
      }
      ++(this -> length);
    }


    virtual const Data removeFront(){

      const Data data = ((this -> head) -> data);//store heads data
      Node<Data>* tmp = (this -> head -> next); //find next node for head
      delete head;
      (this -> head) = tmp;
      --(this -> length);

      return data;

    }


    virtual const Data removeBack(){

      const Data data = (this -> tail) -> data; //store tails data

      Node<Data>* prev = (this -> head); //find next node for tail
      while( (prev -> next) != tail){

        prev = prev -> next;
      }
      
      delete tail;
      this -> tail = prev;
      --(this -> length);
      return data;

    }


    virtual const Data & getFirstElement() const{

      return (this -> head) -> data;
    }


    virtual const Data & getLastElement() const{

      return (this -> tail) -> data;
    }
    
    LinkedList<Data>& operator=(const LinkedList<Data> &src){

      if(this == &src){
        return *this;
      }

      cout<<"Created List: "<<this<<endl;

      if( !src.isEmpty() ){

        this->~LinkedList<Data>();
        this->head = new Node<Data>( src.getHead()->getData() );
        this->tail = this->head;
        ++(this -> length);

        Node<Data>* src_tmp = src.getHead();
        while( src_tmp != src.getTail() ){
					
          src_tmp = src_tmp->getNext();
          (this->tail)->next = new Node<Data>(src_tmp->getData());
          this->tail = (this->tail)->next;
          ++(this -> length);
        }

        return *this;
      }

      this->head = nullptr;
      this->tail = nullptr;
      this->length = 0;
      return *this;  
    }
    
  };

template<typename Data>
std::ostream & operator<<(std::ostream &stm, const LinkedList<Data> &n ) {//no implicit 1st parameter
                                                                            //since this is not a mem func
   return n.buildStream(stm);

}

#endif
