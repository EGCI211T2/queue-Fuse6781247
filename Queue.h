#ifndef queue_h
#define queue_h
#include "Node.h"
#include <iostream>
using namespace std;

// Menu items: 1=Ramen(200), 2=Fried Chicken(100), 3=Spaghetti(150)
string getMenuName(int order) {
    switch(order) {
        case 1: return "Ramen";
        case 2: return "Fried Chicken";
        case 3: return "Spaghetti";
        default: return "Unknown";
    }
}

int getMenuPrice(int order) {
    switch(order) {
        case 1: return 200;
        case 2: return 100;
        case 3: return 150;
        default: return 0;
    }
}

class Queue {
    NodePtr headPtr, tailPtr;
    int size;
    int customerCount;
public:
    void enqueue(int order, int qty);
    NodePtr dequeue();
    int getSize();
    Queue();
    ~Queue();
};

Queue::Queue() {
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    customerCount = 0;
}

int Queue::getSize() {
    return size;
}

void Queue::enqueue(int order, int qty) {
    NodePtr new_node = new NODE(order, qty);
    if (new_node) {
        if (size == 0) {
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
        cout << "My order is " << order << endl;
    }
}

NodePtr Queue::dequeue() {
    if (size > 0) {
        customerCount++;
        NodePtr t = headPtr;

        cout << "Cutomer no: " << customerCount << endl;
        cout << getMenuName(t->get_order()) << endl;

        int price = getMenuPrice(t->get_order()) * t->get_qty();
        cout << "You have to pay " << price << endl;

        int cash;
        cout << ":Cash:";
        cin >> cash;

        if (cash >= price) {
            cout << "Cash:" << cash << endl;
            cout << "Thank you" << endl;
            if (cash > price) {
                cout << "Change is:" << (cash - price) << endl;
            }
        } else {
            cout << "Not enough cash!" << endl;
        }

        headPtr = headPtr->get_next();
        if (headPtr == NULL) tailPtr = NULL;

        size--;
        return t;
    } else {
        cout << "Empty Queue" << endl;
        return NULL;
    }
}

Queue::~Queue() {
    if (size > 0) {
        cout << string(50, '=') << endl;
        cout << " There are " << size << " ppl left in the queue" << endl;
        while (size > 0) {
            NodePtr t = headPtr;
            headPtr = headPtr->get_next();
            if (headPtr == NULL) tailPtr = NULL;
            delete t;
            size--;
        }
    }
}

#endif