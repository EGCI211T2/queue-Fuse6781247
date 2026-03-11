
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};

Queue::Queue(){
    //initialize Queue
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}

void Queue::enqueue(int x){
  NodePtr new_node = new NODE(x);
if(new_node){ 
    /* Add head and tail for me please */
   //1. connect & Change tail
    if (size==0){
      //2. (may be) change head  when the queue is empty
        headPtr = new_node;
    }
     else {

        tailPtr->set_next(new_node);
    }
    tailPtr = new_node;
      //3. increase size 
    size++;
 }
}

int Queue::dequeue(){
  if(size>0){
    NodePtr t =  headPtr;
     int value = t->get_value();
    /* Add head and tail for me please */
    
    //Moev head to next node 

    headPtr = headPtr->get_next();
    //if quene become empty tail must be  NULL
    if (headPtr == NULL) tailPtr = NULL;
        
        delete t;
        size--;
        return value;
    }
    else{
         cout<<"Empty queue"<<endl;
         return -1;

    }  
    
  }




Queue::~Queue(){
      if(size>0) {
        cout<<"Clearing queue" <<endl;
    //delete all remaning Queue (i.e. DQ all) 
    
    while(size>0){

        int x = dequeue();

    
        if(x!= -1) cout<<"dequeing" <<x<<endl;
    }
    
}
}


#endif
