#ifndef node_h
#define node_h

class NODE {
    int order;
    int qty;
    NODE *nextPtr;
public:
    NODE(int, int);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    int get_order();
    int get_qty();
};
typedef NODE* NodePtr;

NODE::NODE(int o, int q) {
    order = o;
    qty = q;
    nextPtr = NULL;
}

NODE* NODE::get_next() {
    return nextPtr;
}

int NODE::get_order() {
    return order;
}

int NODE::get_qty() {
    return qty;
}

void NODE::set_next(NODE *t) {
    nextPtr = t;
}

NODE::~NODE() {}

#endif