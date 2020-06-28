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
import java.util.NoSuchElementException;

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

        return new SinglyLinkedListIterator();
    }

    @Override
    public Object[] toArray() {

        ListIterator<E> sllIterator= this.listIterator();
        Object[] array = new Object[this.size()];
        while(sllIterator.hasNext()){
            array[sllIterator.nextIndex()] = sllIterator.next();
        }
        return array;
    }

    @Override
    @SuppressWarnings("unchecked") // we check it...has to atleast be a super class
    public <T> T[] toArray(T[] a) { //no idea on this one really but here goes...
        // https://stackoverflow.com/questions/6522284/convert-a-generic-list-to-an-array
        if( a == null) {
            throw new NullPointerException();
        }
        // some more things have to happen in the event of a larger
        // passed array...but ya know getting there.
        // also if array.length < this.size allocate new T[] of that size...
        try{
            Node<E> tmp = this.head;
            for(int i = 0; i < a.length; ++i){
                a[i] = (T) tmp.getData(); // has to at least be super.
                tmp = tmp.getNext();
            }
            return a;
        }
        catch(ArrayStoreException e){
            throw e;
        }
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
        return new SinglyLinkedListIterator();
    }

    @Override
    public ListIterator<E> listIterator(int index) {

        if( index < 0 || index > this.size() ){
            throw new IndexOutOfBoundsException();
        }

        ListIterator<E> sllIterator = new SinglyLinkedListIterator();

        while( sllIterator.nextIndex() != index ){
            sllIterator.next();
        }

        return sllIterator;
    }

    @Override
    public List<E> subList(int fromIndex, int toIndex) {
        // TODO Auto-generated method stub
        return null;
    }

    
    // https://docs.oracle.com/javase/7/docs/api/java/util/ListIterator.html#hasPrevious()
    // Decided to implement ListIterator in order to handle
    // all of List's iterator methods with a single class...

    // Whoa not sure why we cannot parameterize LinkedListIterator
    // but it works.
    private class SinglyLinkedListIterator implements ListIterator<E> {

        // variable names should highlight that
        // ListIterator is always between nodes...
        private Node<E> next = getHead();
        private int nxtIndex = 0;

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
