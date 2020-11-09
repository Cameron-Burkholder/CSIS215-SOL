// Programming_Assignment_4_Self_Organizing_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CountSelfOrderedList.h"
#include "MoveToFrontSelfOrderedList.h"
#include "TransposeSelfOrderedList.h"

int main() {

    std::cout << "Cameron Burkholder - Lab 4" << std::endl << std::endl;
    char adds[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int addsLength = 8;

    char finds[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };
    int findsLength = 14;

    // Count heuristic
    std::cout << "COUNT HEURISTIC" << std::endl;
    std::cout << "Chars" << std::endl;
    CountSelfOrderedList<char>* clist = new CountSelfOrderedList<char>();
    for (int i = 0; i < addsLength; i++) {
        clist->add(adds[i]);
    }
    for (int i = 0; i < findsLength; i++) {
        clist->find(finds[i]);
    }
    std::cout << "Size: " << clist->size() << std::endl;
    std::cout << "Compares: " << clist->getCompares() << std::endl;
    clist->printlist();

    std::cout << std::endl << std::endl;

    std::cout << "MOVE TO FRONT HEURISTIC" << std::endl;
    std::cout << "Chars" << std::endl;
    MoveToFrontSelfOrderedList<char>* mtflist = new MoveToFrontSelfOrderedList<char>();
    for (int i = 0; i < addsLength; i++) {
        mtflist->add(adds[i]);
    }
    for (int i = 0; i < findsLength; i++) {
        mtflist->find(finds[i]);
    }
    std::cout << "Size: " << mtflist->size() << std::endl;
    std::cout << "Compares: " << mtflist->getCompares() << std::endl;
    mtflist->printlist();

    std::cout << std::endl << std::endl; 

    std::cout << "TRANSPOSE HEURISTIC" << std::endl; 
    std::cout << "Chars" << std::endl;
    TransposeSelfOrderedList<char>* tlist = new TransposeSelfOrderedList<char>();
    for (int i = 0; i < addsLength; i++) {
        tlist->add(adds[i]);
    }
    for (int i = 0; i < findsLength; i++) {
        tlist->find(finds[i]);
    }
    std::cout << "Size: " << tlist->size() << std::endl;
    std::cout << "Compares: " << tlist->getCompares() << std::endl;
    tlist->printlist();

    system("pause");
    return 0;
}
