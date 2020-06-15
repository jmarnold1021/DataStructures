#!/usr/bin/env python3.7

# https://docs.python.org/3/library/unittest.html
import unittest

# to import our custom libraries without warnings the following
# env configs must be applied as stated here...
#
# https://github.com/microsoft/vscode-python/issues/3840#issuecomment-468980544
#
# Add .env to top level repo folder
# add the following line, note no spaces or quotes, to .env
# PYTHONPATH=Python
# SHIFT-CMD-P to reload window
from LinkedList import LinkedList


class test_LinkedList(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        print("Setting up LinkedList Test")

    def test_add_contains(self):
        print("Running Test Add/Contains")

        ll = LinkedList()
        self.assertEqual(ll.empty(), True)

        ll.add("s0")
        ll.add("s1")

        self.assertTrue(ll.contains("s1"))
        self.assertTrue(ll.containsRecursive("s1"))

        self.assertFalse(ll.contains("s2"))
        self.assertFalse(ll.containsRecursive("s2"))

    @classmethod
    def tearDownClass(cls):
        print("")  # for weird period output that I can't find atm
        print("Tearing down LinkedList Test")


if __name__ == '__main__':
    unittest.main()
