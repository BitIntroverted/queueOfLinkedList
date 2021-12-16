/*
 *  Name: Lukas Friedrich
 *  exam 2
 *  Queue using linkedlist (doubly)
 */

#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include "string"
using std::cout;
using std::endl;
using std::string;

struct Data {
    int id;
    string information;
};

struct Node {
    Data data;
    Node* next;
    Node* prev;
};

class Queue {

public:

    Queue(); //constructor

    bool push(int, const string&);
    bool pull(Data&);

    bool peek(Data&);
    bool isEmpty();



private:
    
    Node* top, *bottom;
};

#endif //FIFO_H