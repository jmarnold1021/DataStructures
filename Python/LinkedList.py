# Need this because python does not support inheritence
# very well natively
# https://docs.python.org/3.7/library/abc.html
# https://www.python-course.eu/python3_abstract_classes.php
from abc import ABCMeta, abstractmethod


# Base class (Basically defines an interface)
class List(metaclass=ABCMeta):

    def __init__(self):
        super().__init__()

    @abstractmethod
    def empty(self):
        pass

    @abstractmethod
    def size(self):
        pass

    @abstractmethod
    def add(self, data):
        pass

    @abstractmethod
    def contains(self, data):
        pass

    @abstractmethod
    def get(self, idx):
        pass

    @abstractmethod
    def remove(self, data):
        pass


# Derived class
class LinkedList(List):

    # Private class
    class Node:

        data = None
        next = None

        def __init__(self, data):
            self.data = data

        def get_data(self):
            return self.data

        def set_data(self, data):
            self.data = data

        def get_next(self):
            return self.next

        def set_next(self, node):
            self.next = node

        def contains(self, data):
            return (self.data == data)

    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0
        super().__init__()

    # Override
    def empty(self):
        if self.length == 0:
            return True

        return False

    # Override
    def size(self):
        return self.length

    # Override
    def add(self, data):

        if data is None:
            raise Exception("Cannot add None values to the List!")

        tmp = self.Node(data)

        if self.length == 0:
            self.head = tmp
            self.tail = self.head
        else:
            self.tail.set_next(tmp)
            self.tail = self.tail.get_next()

        self.length = self.length + 1

    # Override
    def contains(self, data):

        if data is None:
            raise Exception("Cannot add None values to the List!")

        if self.head.contains(data):
            return True

        tmp = self.head.get_next()
        while tmp is not None:
            if tmp.contains(data):
                return True
            tmp = tmp.get_next()

        return False

    def containsRecursive(self, data):

        # private helper method hides node objs
        def containsRecursive(node, data):

            if node.contains(data):
                return True

            if node.get_next() is None:
                return False

            return containsRecursive(node.get_next(), data)

        if data is None:
            raise Exception("Cannot add None values to the List!")

        return containsRecursive(self.head, data)

    def get(self, idx):
        pass

    def remove(self, data):
        pass
