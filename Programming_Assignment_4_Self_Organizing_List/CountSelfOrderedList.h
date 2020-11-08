/*#pragma once

#include "SelfOrderedList.h"
#include "link.h"
#include <iostream>

template <typename E>
class CountSelfOrderedList : public SelfOrderedListADT<E> {
protected:
    // *** CHECK TO SEE IF COMPARES SHOULD BE UPDATED HERE ***
    void updateList(Link<E>* el) {
        Link<E>* temp;
        el->count++;
        while (el->prev != head && el->count > el->prev->count) {
            updateCompares();
            temp = el->prev;

            el->prev = temp->prev;
            temp->prev = el;
            temp->next = el->next;
            el->next = temp;
            el->prev->next = el;

            if (tail == el) {
                tail = temp;
            }
        }
        updateCompares();
    }
    void printElement(Link<E>* el) {
        std::cout << el->element << "-" << el->count;
    }

public:
    CountSelfOrderedList() {
        SelfOrderedList::SelfOrderedList();
    }
    ~CountSelfOrderedList() {
        SelfOrderedList::~SelfOrderedList();
    }
};*/

#pragma once

#include "SelfOrderedListADT.h"
#include "link.h"
#include <iostream>

template <typename E>
class CountSelfOrderedList : public SelfOrderedListADT<E> {
private:
    Link<E>* head;
    Link<E>* tail;
    int sz;
    int compares;

    void init() {
        head = tail = new Link<E>;
        sz = 0;
    }
    void removeAll() {
        while (head->next != NULL) {
            head = head->next;
            delete head->prev;
        }
        delete head;
    }

protected:

    // These should be overridden in each implementation
    void updateList(Link<E>* el) {
        //new
        Link<E>* temp = el->prev;
        el->count++;
        while (temp != head && el->count > temp->count) {
            temp = temp->prev;
        }
        if (tail == el) {
            tail = el->prev;
        }
        else {
            el->next->prev = el->prev;
        }
        el->prev->next = el->next;
        el->prev = temp;
        el->next = temp->next;
        temp->next = el;
        el->next->prev = el;
    }
    void printElement(Link<E>* el, bool printLine = false) {
        std::cout << el->element << "-" << el->count << " ";
        if (printLine) {
            std::cout << std::endl;
        }
    }
    void updateCompares() {
        compares++;
    }

public:
    CountSelfOrderedList() {
        this->init();
        compares = 0;
    }
    ~CountSelfOrderedList() {
        this->removeAll();
    }

    //Look for 'it'.  If found return true and execute the self-ordering
    //heuristic used for ordering the list: count, move-to-front, or transpose.
    //Increments the compare instance variable every time it compares 'it' to
    //other members of the list. Returns true if 'it' is found.
    bool find(const E& it) {
        bool isFound = false;
        Link<E>* curr = head;
        while (curr->next != NULL && !isFound) {
            curr = curr->next;
            compares++;
            if (curr->element == it) {
                isFound = true;
                this->updateList(curr);
                break;
            }
        }
        if (!isFound) {
            add(it);
        }
        return isFound;
    }

    //Called by find if 'it' is not in the list. Adds the new 'it' to the list
    //Can also be called independently when initially loading the list with
    //unique values and when you want to load the list in the order 'it' is 
    //read without your re-order method being called (or the number of compares
    //being incremented.
    void add(const E& it) {
        Link<E>* link = new Link<E>(it, tail, tail->next);
        // check if link is first item in list 
        if (head == tail) {
            head->next = link;
        }
        else {
            tail->next = link;
        }
        tail = link;
        sz++;
    }

    int getCompares() const {
        return compares;
    }
    int size() const {
        return sz;
    }

    //Print the list
    //In order print of the list.  printlist() prints the entire list
    //whereas printlist(n) prints n nodes.
    void printlist() {
        Link<E>* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
            this->printElement(curr);
        }
        std::cout << std::endl;
     }
    void printlist(int n) {
        Link<E>* curr = head;
        int i = 0;
        while (curr->next != NULL && i < n) {
            i++;
            curr = curr->next;
            this->printElement(curr);
        }
        std::cout << std::endl;
    }
};