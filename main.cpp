#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "Queue.h"

int main(int argc, char **argv) {
    Queue q;

    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "x") == 0) {
            // Dequeue: process next customer
            NodePtr node = q.dequeue();
            if (node != NULL) {
                delete node;
            }
            i++;
        } else {
            // Expect two values: order qty
            if (i + 1 < argc && strcmp(argv[i+1], "x") != 0) {
                int order = atoi(argv[i]);
                int qty   = atoi(argv[i+1]);
                q.enqueue(order, qty);
                i += 2;
            } else {
                // Only one value left, treat qty as 1
                int order = atoi(argv[i]);
                q.enqueue(order, 1);
                i++;
            }
        }
    }

    return 0;
}