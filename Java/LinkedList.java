// Linked List Class that implements Javas List Interface
// https://docs.oracle.com/javase/8/docs/api/java/util/List.html
// The methods should be implemented as explained in the above documentation.
// DataStructuresTestRunner.java will be used to test THOSE implementations.

// Using underlying Node backing Structure.

package Java;

import java.util.Collection;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;

public class LinkedList<E> implements List<E> {

    private Node<E> head = null;
    private Node<E> tail = head;
    private int modCount = 0;
    private int size = 0;
   
    private Node<E> getHead(){
        return this.head;
    }
    
    @Override
    public String toString(){

        Node<E> itr = this.head;
        StringBuilder listStr = new StringBuilder("[");

        while(itr != null){

            if(itr.next != null){
                listStr.append( itr.getData().toString() + ", " );
            } else {
                listStr.append( itr.getData().toString() );
            }

            itr = itr.getNext();
        }

        listStr.append(']');
        return listStr.toString();
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

        if( this.isEmpty() ) {
            return false;
        }

        if( this.head.contains(o) ){
            return true;
        }
        
        Node<E> itr = this.head.getNext();

        while( itr != null ) {

            if( itr.contains(o) ) {
                return true;
            }

            itr = itr.getNext();
        }

        return false;
    }

    public boolean containsRecursiveExample(Object o){

        if( this.isEmpty() ){
            return false;
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
        return new SinglyLinkedListIterator();
    }

    @Override
    public Object[] toArray() {

        Object[] array = new Object[this.size];        
        Node<E> itr = this.head;
        for(int i = 0; i < this.size; ++i) {

            array[i] = itr.getData();
            itr = itr.getNext();
        }
        return array;
    }

    @Override
    @SuppressWarnings("unchecked")
    public <T> T[] toArray(T[] a) {

        // best solution I could find for this one...plus java src uses it ;)
        if( this.size > a.length ){
            a = (T[]) java.lang.reflect.Array.newInstance(
                a.getClass().getComponentType(), this.size);
        }

        Node<E> itr = this.head;
        for(int i = 0; i < a.length; ++i) {

            a[i] = (T) itr.getData(); // has to at least be super for every elem.
            itr = itr.getNext();

            if( itr == null && a.length > this.size ){
                a[++i] = null;
                break;
            }
        }
        return a;
    }

    @Override
    public boolean add(E e) {
        
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

        if( this.isEmpty() ){
            return false;
        }

        Node<E> itr = this.head;
        
        // head contains
        if( this.head.contains(o) ){
            
            // head is final element set tail too.
            if( itr.getNext() == null ) {
                this.tail = null;
            }
            
            // adjust head
            this.head = itr.getNext();
            itr.setNext(null);
            --this.size;
            return true;
        }

        // 1 node left but did not contain
        if( itr.getNext() == null ){
            return false;
        }
        
        // find node before the one we are removing
        while( !itr.getNext().contains(o) ){

            if(itr.getNext().getNext() == null){
                return false;
            } 
            itr = itr.getNext();
        }

        // tail - use tail as next to unlink
        if( itr.getNext().getNext() == null ){
            this.tail = itr;
            itr.setNext(null);
            --this.size;
            return true;
        }

        // middle - use tmp as next to unlink
        Node<E> tmp = itr.getNext();
        itr.setNext(itr.getNext().getNext());
        tmp.setNext(null);
        --this.size;
        return true;
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
        return new SinglyLinkedListIterator();
    }

    @Override
    public ListIterator<E> listIterator(int index) {

        if( index < 0 || index > this.size ){
            throw new IndexOutOfBoundsException();
        }

        SinglyLinkedListIterator iterator = new SinglyLinkedListIterator();

        while( iterator.nextIndex() < index ) {
            iterator.next();
        }

        return iterator;
    }

    @Override
    public List<E> subList(int fromIndex, int toIndex) {
        // TODO Auto-generated method stub
        return null;
    }

    
    // https://docs.oracle.com/javase/7/docs/api/java/util/ListIterator.html#hasPrevious()
    // Decided to implement ListIterator in order to handle
    // all of List's iterator methods with a single class...

    // Whoa not sure why we cannot parameterize SinglyLinkedListIterator
    // but it works.
    // ...
    // update Java source does this Exactly :O...
    private class SinglyLinkedListIterator implements ListIterator<E> {

        // variable names should highlight that
        // ListIterator is always between nodes...
        // starts before 0/head...
        private Node<E> next = getHead();
        private int nxtIndex = 0;

        // https://docs.oracle.com/javase/8/docs/api/java/util/LinkedList.html
        private void failFastConcurrentModification(){
            throw new ConcurrentModificationException();
        }

        @Override
        public boolean hasNext() {
            return next != null;
        }

        @Override
        public E next() {

            if( !hasNext() ){
                throw new NoSuchElementException();
            }

            E data = next.getData();
            next = next.getNext();
            ++nxtIndex;
            return data;
        }

        @Override
        public int nextIndex() {
            return nxtIndex;
        }

        @Override
        public void remove() { //provided through List
            throw new UnsupportedOperationException();
        }

        @Override
        public void set(E e) { //provided through List
            throw new UnsupportedOperationException();
        }

        @Override
        public void add(E e) { //provided through List
            throw new UnsupportedOperationException();
        }

        @Override
        public boolean hasPrevious() { //single link
            throw new NoSuchElementException();
        }

        @Override
        public E previous() { //single link
            throw new NoSuchElementException();
        }

        @Override
        public int previousIndex() { //single link
            throw new NoSuchElementException();
        }   
    }

    private class Node<T> {

        private T data = null;
        private Node<T> next = null;

        private Node(T data) {

            if( data == null ) {
                throw new NullPointerException();
            }

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
            return o.equals(this.data);
        }

        // read method is public
        public String toString() {
            return this.data.toString();
        }
    } 
}
