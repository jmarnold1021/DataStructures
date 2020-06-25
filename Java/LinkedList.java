// Linked List Class that implements Javas List Interface
// https://docs.oracle.com/javase/8/docs/api/java/util/List.html
// The methods should be implemented as explained in the above documentation.
// DataStructuresTestRunner.java will be used to test THOSE implementations.

// Using underlying Node backing Structure.
// high level explanation of a LinkedList and why there is no
// Backing array...as one may see in a Stack or Queue.

package Java;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class LinkedList<E> implements List<E> {

    private Node<E> head = null;
    private Node<E> tail = head;
    private int size = 0;
   
    private Node<E> getHead(){
        return this.head;
    }

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean isEmpty() {

        if(this.size == 0){
            return true;
        }

        return false;
    }

    //https://docs.oracle.com/javase/8/docs/api/java/util/List.html#contains-java.lang.Object-
    @Override
    public boolean contains(Object o) {

        if( o == null ){
            throw new NullPointerException();
        }

        if( this.size == 0 ) {
            return true;
        }

        if( this.head.contains(o) ){
            return true;
        }
        
        Node<E> tmp = this.head.getNext();

        while( tmp != null ) {

            if( tmp.contains(o) ) {
                return true;
            }

            tmp = tmp.getNext();
        }
        return false;
    }

    public boolean containsRecursiveExample(Object o){

        if( o == null ) {
            throw new NullPointerException();
        }

        return containsRecursiveExample(this.head, o);
    }

    private boolean containsRecursiveExample(Node<E> n, Object o){
        
        if( n.contains(o) ){
            return true;
        }

        if( n.getNext() == null ){
            return false;
        }

        return containsRecursiveExample(n.getNext(), o);
    }

    @Override
    public Iterator<E> iterator() {

        // https://stackoverflow.com/questions/355167/how-are-anonymous-inner-classes-used-in-java
        return new Iterator<E>() {

            Node<E> current = getHead();

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public E next() {
                if( hasNext() ){
                    E data = current.getData();
                    current = current.getNext();
                    return data;
                }
                return null;
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException("Remove not implemented.");
            }
        };
    }

    @Override
    public Object[] toArray() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public <T> T[] toArray(T[] a) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public boolean add(E e) {
        
        if( e == null ) {
            throw new NullPointerException();
        }

        Node<E> tmp = new Node<E>(e);

        if( this.size == 0 ) {
            this.head = tmp;
            this.tail = this.head;
        } else {
            this.tail.setNext(tmp);
            this.tail = this.tail.getNext();
        }

        ++this.size;
        return true;
        
    }

    @Override
    public boolean remove(Object o) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean containsAll(Collection<?> c) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean addAll(Collection<? extends E> c) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean addAll(int index, Collection<? extends E> c) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean removeAll(Collection<?> c) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean retainAll(Collection<?> c) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void clear() {
        // TODO Auto-generated method stub

    }

    @Override
    public E get(int index) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public E set(int index, E element) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public void add(int index, E element) {
        // TODO Auto-generated method stub

    }

    @Override
    public E remove(int index) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public int indexOf(Object o) {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public int lastIndexOf(Object o) {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public ListIterator<E> listIterator() {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public ListIterator<E> listIterator(int index) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public List<E> subList(int fromIndex, int toIndex) {
        // TODO Auto-generated method stub
        return null;
    }

    private class Node<T> {

        private T data = null;
        private Node<T> next = null;

        private Node(T data) {
            this.data = data;
        }

        private Node<T> getNext() {
            return this.next;
        }

        private void setNext(Node<T> node) {
            this.next = node;
        }

        private T getData() {
            return this.data;
        }

        private void setData(T data) {
            this.data = data;
        }

        private boolean contains(Object o){
            return this.data.equals(data);
        }

        // read method is public
        public String toString() {
            return this.data.toString();
        }
    } 
}
