
// All our files will be in this package 
// so no need to import them
package Java;

// For @Test annotations.
import org.junit.*;

// for Assert Methods
// http://junit.sourceforge.net/javadoc/org/junit/Assert.html
// for exception handeling
// https://www.baeldung.com/junit-assert-exception
import static org.junit.Assert.*;

// for initial TestRunner...Testing without our stuff.
import java.util.Collection;
import java.util.ArrayList;

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
