#ifndef MYLINKEDLIST_HPP
#define MYLINKEDLIST_HPP
#include <iostream>
#include <stdexcept>

template<typename Data>
class MyLinkedList{

  
  private:  
    template<typename T>//variable type T will be filled with data variable type
    class Node{
      public:
        Node( const Data &d ) : data(d), next(nullptr) {}
        const Data data;
        Node<T>* next;
    };
		
		Node<Data>* head;
    Node<Data>* tail;
    int size;
		
  public:
	  //Default constructor
    MyLinkedList() : head(nullptr), tail(nullptr), size(0){}
    
		//Copy constructor
    MyLinkedList(const MyLinkedList<Data> &src){
      
		  if(src.head){
			  this->size = src.size;
				
			  Node<Data>* src_tmp = src.head;
			  this->head = new Node<Data>(src_tmp->data);
				this->tail = this->head;
        while( src_tmp != src.tail){
					
					src_tmp = src_tmp->next;
				  (this->tail)->next = new Node<Data>(src_tmp->data);
					this->tail = (this->tail)->next;
				}
      }
			else{// given an empty list list
        this->head = nullptr;
				this->tail = nullptr;
			  this->size = 0;
			}
		}
		

    virtual ~MyLinkedList(){ //virtual so that classes extending MyLinkedList
                             //can redefine the destructor
                             //i.e override the destructor

      if(head){   //size at least 1
        std::cout<<"destructing oll mll"<<std::endl; 
				std::cout<<size<<std::endl;
        while(head != tail){  //do not base end on whether or not tmp = null!!!!!!
          Node<Data>* tmp = head->next;
          delete head;
          head = tmp;
        }
        delete head;
      }
    }

    virtual const Data & access(int pos) const{//searches from head to tail

      if(pos >= (this -> size)){ //throw out of bounds exception
        throw std::out_of_range( "Given position is outside of the List's Size" );
      }

      if(pos == 0){
        return head -> data;
      }

      if(pos == (this -> size) - 1 ){
        return tail -> data;
      }

      Node<Data>* tmp = head;
      for(int i = 1 ; i <= pos ; ++i){
        tmp = tmp -> next;
      }

      return tmp -> data;
    }

    std::ostream & buildStream(std::ostream & stm) const{// const allows function to be called by const objects
      Node<Data>* start = (this -> head);
                                                         //i.e. tells the compiler that the function will
      stm << '[';                                        //     not change the const object
      for(int i = 0 ; i < (this -> size) ; ++i){

        if( i != ((this -> size) - 1) ){

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

    //adds to the back of the list
    virtual void add( const Data &data ){

      //since data field is const it must be initialized through the constructor!!!
      if(size == 0){ //if size = 0 set up head and adjust tail

        (this -> head) = new Node<Data>(data);
        (this -> tail) = (this -> head);
      }
      else{

        ((this -> tail) -> next) = new Node<Data>(data);// only adjust tail
        this->tail = (this -> tail)->next;
      }
      ++(this -> size);
    }


    virtual const Data removeFront(){

      const Data data = ((this -> head) -> data);//store heads data
      Node<Data>* tmp = (this -> head -> next); //find next node for head
      delete head;
      (this -> head) = tmp;
      --(this -> size);

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
      --(this -> size);
      return data;

    }


    virtual const Data & getFirstElement() const{

      return ((this -> head) -> data);
    }


    virtual const Data & getLastElement() const{

      return ((this -> tail) -> data);
    }
    
		//
		MyLinkedList<Data>& operator=(const MyLinkedList<Data> &src){
      if(this == &src){
			  return *this;		
			}
		 if(src.head){
		    this->~MyLinkedList<int>();
			  this->size = src.size;
				
			  Node<Data>* src_tmp = src.head;
			  this->head = new Node<Data>(src_tmp->data);
				this->tail = this->head;
        while( src_tmp != src.tail){
					
					src_tmp = src_tmp->next;
				  (this->tail)->next = new Node<Data>(src_tmp->data);
					this->tail = (this->tail)->next;
				}
				return *this;
				
      }
			else{// given an empty list list
        this->head = nullptr;
				this->tail = nullptr;
			  this->size = 0;
				return *this;
			}
		}

 };

template<typename Data>
std::ostream & operator<<(std::ostream &stm, const MyLinkedList<Data> &n ) {//no implicit 1st parameter
                                                                            //since this is not a mem func
   return n.buildStream(stm);

}

#endif
