
// All our files will be in this package 
// so no need to import them
package Java;

// For @Test annotations.
import org.junit.*;

// for Assert Methods
// http://junit.sourceforge.net/javadoc/org/junit/Assert.html
// for exception handleing...
// https://www.baeldung.com/junit-assert-exception
// hooks...
// https://stackoverflow.com/questions/82949/before-and-after-suite-execution-hook-in-junit-4-x
import static org.junit.Assert.*;

// for initial TestRunner...Testing without our stuff.
import java.util.Collection;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.ArrayList;
import java.util.NoSuchElementException;

// Utilities
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;


public class DataStructuresTestRunner 
{
    public static LocalDateTime START_TIME = LocalDateTime.now();
    public static ChronoUnit TIME_UNIT = ChronoUnit.MILLIS;

    @BeforeClass
    public static void INITIALIZE(){
        START_TIME = LocalDateTime.now();
        System.out.print("Starting... ");
        System.out.println(START_TIME);
    }

    //Generic Tests for Functionality
    @Test
    public void testEmptyCollection() {

        Collection<String> collection = new ArrayList<String>();
        assertTrue(collection.isEmpty());
    }

    @Test
    public void testEmptyCollectionFail() {

        Collection<String> collection = new ArrayList<String>();
        collection.add("blah");
        assertFalse(collection.isEmpty());
    }


    // Start Linked List Class
    public void testLinkedListIsEmpty() {

        LinkedList<String> fixture = new LinkedList<String>();
        assertTrue(fixture.isEmpty());
    }

    @Test
    public void testLinkedListSize() {

        LinkedList<String> fixture = new LinkedList<String>();
        assertEquals(fixture.size(), 0);
    }

    
    @Test(expected = NullPointerException.class)
    public void testLinkedListNullPointerException() {

        LinkedList<String> fixture = new LinkedList<String>();
        fixture.add(null);
    }

    @Test
    public void testLinkedListAdd() {

        LinkedList<String> fixture = new LinkedList<String>();
        assertTrue(fixture.isEmpty());
        assertEquals(fixture.size(), 0);
    
        boolean added0 = fixture.add("String0");
        assertTrue(added0);
        assertFalse(fixture.isEmpty());
        assertEquals(fixture.size(), 1);
    }

    @Test
    public void testLinkedListContains() {

        LinkedList<String> fixture = new LinkedList<String>();
        assertEquals(fixture.size(), 0);
    
        boolean added0 = fixture.add("String0");
        assertTrue(added0);
        assertEquals(fixture.size(), 1);
        assertTrue(fixture.contains("String0"));

        boolean added1 = fixture.add("String1");
        assertTrue(added1);
        assertEquals(fixture.size(), 2);
        assertTrue(fixture.contains("String1"));

        boolean added2 = fixture.add("String2");
        assertTrue(added2);
        assertEquals(fixture.size(), 3);
        assertTrue(fixture.contains("String2"));
    }

    @Test
    public void testLinkedListContainsRecursive() {

        LinkedList<String> fixture = new LinkedList<String>();
        assertEquals(fixture.size(), 0);
    
        boolean added0 = fixture.add("String0");
        assertTrue(added0);
        assertEquals(fixture.size(), 1);
        assertTrue(fixture.containsRecursiveExample("String0"));

        boolean added1 = fixture.add("String1");
        assertTrue(added1);
        assertEquals(fixture.size(), 2);
        assertTrue(fixture.containsRecursiveExample("String1"));

        boolean added2 = fixture.add("String2");
        assertTrue(added2);
        assertEquals(fixture.size(), 3);
        assertTrue(fixture.containsRecursiveExample("String2"));
    }

    @Test
    public void testIterator() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);

        Iterator<Integer> itr = fixture.iterator();
        int idx = 0;
        while( itr.hasNext() ){
            assertEquals(itr.next().intValue(), idx);
            ++idx;
        }
    }

    @Test
    public void testListIterator() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);
        fixture.add(3);
        fixture.add(4);
        fixture.add(5);

        ListIterator<Integer> itr = fixture.listIterator();
        assertEquals(itr.nextIndex(), 0);
        assertEquals(itr.next().intValue(), 0);

        int idx = 1;
        while( itr.hasNext() ){
            assertEquals(itr.nextIndex(), idx);
            assertEquals(itr.next().intValue(), idx);
            ++idx;
        }

        assertEquals(itr.nextIndex(), fixture.size());
    }

    @Test
    public void testListIteratorIndex() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);
        fixture.add(3);
        fixture.add(4);
        fixture.add(5);

        ListIterator<Integer> itr = fixture.listIterator(2);
        assertEquals(itr.nextIndex(), 2);
        assertEquals(itr.next().intValue(), 2);

        int idx = 3;
        while( itr.hasNext() ){
            assertEquals(itr.nextIndex(), idx);
            assertEquals(itr.next().intValue(), idx);
            ++idx;
        }

        assertEquals(itr.nextIndex(), fixture.size());
    }

    @Test(expected = IndexOutOfBoundsException.class)
    public void testListIteratorIndexOutOfBoundsException() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);

        ListIterator<Integer> ib = fixture.listIterator(3);
        assertEquals(ib.hasNext(), false);
        // 3 is still a valid position where a subsequent call to
        // next throws a NoSuchElementException...see below test.
        // 4 however is out of bounds since no element exists
        // between 3 and 4...head scramble...!!!

        ListIterator<Integer> oob = fixture.listIterator(4);
    }

    @Test(expected = NoSuchElementException.class)
    public void testListIteratorNoSuchElementException() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);

        ListIterator<Integer> itr = fixture.listIterator();
        while( itr.hasNext() ){
            itr.next();
        }

        itr.next();
    }

    @Test
    public void testToArray() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);

        Object[] array = fixture.toArray();

        for(int i = 0; i < fixture.size(); ++i){
            assertEquals(array[i], i);
        }
    }

    @Test
    public void testToArrayWTFIsGoingOn() {

        LinkedList<Integer> fixture = new LinkedList<Integer>();
        fixture.add(0);
        fixture.add(1);
        fixture.add(2);

        Number[] array = fixture.toArray(new Number[4]);
        assertEquals(array[0],0);
        assertEquals(array[1],1);
        assertEquals(array[2],2);
        assertEquals(array[3],null);

        Number[] array2 = fixture.toArray(new Number[1]);
        assertEquals(array2[0],0);
        assertEquals(array2[1],1);
        assertEquals(array2[2],2);
    }


    @AfterClass
    public static void TEARDOWN() {

        LocalDateTime endTime = LocalDateTime.now();
        System.out.print("Finished... ");
        System.out.println(endTime);

        long suiteTime = START_TIME.until(endTime, TIME_UNIT);
        System.out.print("Total Suite Time in Milli-Seconds... ");
        System.out.println(suiteTime);
    }
} 
