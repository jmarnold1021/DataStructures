#!/usr/bin/env python3.7

# https://docs.python.org/3/library/unittest.html
import unittest

from LinkedList import LinkedList


class test_LinkedList(unittest.TestCase):

    def test_add_contains(self):

        ll = LinkedList()
        self.assertEqual(ll.empty(), True)

        ll.add("s0")
        ll.add("s1")

        self.assertTrue(ll.contains("s1"))
        self.assertTrue(ll.containsRecursive("s1"))
        
        self.assertFalse(ll.contains("s2"))
        self.assertFalse(ll.containsRecursive("s2"))


if __name__ == '__main__':
    unittest.main()
