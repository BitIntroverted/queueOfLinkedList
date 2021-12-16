/*
 * 	Name: Lukas Friedrich
 * 	exam 2
 * 	Integer queue class with linkedlist
 */

#include "fifo.h"

Queue::Queue() {
    top = bottom = nullptr;
}

bool Queue::push(int idVal, const string& val) {
    bool pushed = false;
    if (idVal > 0 || val != "") {
        Node* tempData = new Node;
        tempData->data.id = idVal;
        tempData->data.information = val;
        tempData->prev = nullptr;
        if (isEmpty()) {
            top = tempData;
            bottom = tempData;
            top->prev = nullptr;
            bottom->next = nullptr;
            pushed = true;
        }
        else {
            top->prev = tempData;
            tempData->next = top;
            top = tempData;
            pushed = true;
        }
    }
    return pushed;
}

bool Queue::pull(Data& slate) {
    bool popped = false;
    if (!isEmpty()) {
        Node* temp = bottom;
        slate.id = bottom->data.id;
        slate.information = bottom->data.information;
        if (top == bottom) {
            delete temp;
            top = bottom = nullptr;
        }
        else {
            bottom = bottom->prev;
            delete temp;
            bottom->next = nullptr;
        }
        popped = true;
    }
    else {
        slate.id = -1;
        slate.information = "none found";
    }
    return popped;
}

bool Queue::peek(Data& slate) {
    bool peeked = false;
    if (!isEmpty()) {
        slate.id = bottom->data.id;
        slate.information = bottom->data.information;
        peeked = true;
    }
    else {
        slate.id = -1;
        slate.information = "none found";
    }
    return peeked;
}

bool Queue::isEmpty() {
    return (top == nullptr);
}