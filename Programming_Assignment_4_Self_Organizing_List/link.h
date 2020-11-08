#ifndef LINK_H
#define	LINK_H

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> class Link {
public:
  Link(const E& elemval, Link* prevval = NULL, Link* nextval = NULL) {
      element = elemval;  
      next = nextval; 
      prev = prevval;
      count = 0;
  }
  Link() {
      element = NULL;
      next = NULL;
      prev = NULL;
      count = 0;
  }
  E element;
  int count;
  Link* next;
  Link* prev;
};

#endif