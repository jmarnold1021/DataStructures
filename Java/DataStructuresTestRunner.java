
// All our files will be in this package 
// so no need to import them
package Java;

// For @Test annotations.
import org.junit.*;

// for Assert Methods
// http://junit.sourceforge.net/javadoc/org/junit/Assert.html
import static org.junit.Assert.*;

// for initial TestRunner...Testing without our stuff.
import java.util.Collection;
import java.util.ArrayList;



public class DataStructuresTestRunner 
{

    //Generic Tests for Functionality
    @Test
    public void testEmptyCollection() {
        Collection<String> collection = new ArrayList<String>();
        assertTrue(collection.isEmpty());
    }

    @Test
    public void testEmptyCollectionFail() {
        Collection<String> collection = new ArrayList<String>();
        collection.add("blah"); // no empty anymore...
        assertTrue(collection.isEmpty());
    }


    // Start Linked List Class Tests 1 Test has been implemented.

    @Test
    public void testEmptyLinkedList() {
        LinkedList<String> fixture = new LinkedList<String>();
        assertTrue(fixture.isEmpty());

    }

    
} 