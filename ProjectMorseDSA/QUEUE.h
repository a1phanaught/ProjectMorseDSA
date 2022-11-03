#include <iostream>
#include "queueNode.h"
#include "HEAD.h"

#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class QUEUE{

    private: 
        HEAD queue; //queue head (metadata)

    public:
        QUEUE(); 
        bool isEmpty(void);
        bool fullQueue(void);
        int queueCount(void);
        bool enqueue(data dataIn);
        bool dequeue(data &item);
        bool queueFront(data &dataOut);
        bool queueRear(data &dataOut);
        void destroyQueue(void);
        void display(void);

};

QUEUE::QUEUE() {
    queue.front = NULL;
    queue.rear = NULL;
    queue.count = 0;
}

bool QUEUE::isEmpty(void) {
    return (queue.count==0);
}

int QUEUE::queueCount(void) {
    return queue.count;
}

bool QUEUE::fullQueue(void) {
    NODE *temp = new NODE;

    if (temp != NULL) {
        delete temp;
        return false;
    }
    else return true;
}

bool QUEUE::enqueue(data dataIn) {
    if (fullQueue()) return false;
    NODE *newPtr = new NODE;
    newPtr->dat = dataIn;
    newPtr->next = NULL;
    // if queue is empty add newPtr to queue
    if (queue.count == 0) queue.front = newPtr;
    // the back of the current queue now points to the new pointer instead of null
    else queue.rear->next = newPtr;
    // now the rear of the queue points at the new pointer
    queue.rear = newPtr;
    queue.count++;
    return true;
}

bool QUEUE::dequeue(data &item) {
    node *deleteLoc;

    if (queue.count == 0) return false;
    // store the dat in item to be passed to the user
    item = queue.front->dat;
    // stores the address of the location to be deleted
    deleteLoc = queue.front;
    if (queue.count == 1) queue.rear = NULL;
    // the front node is now being held by the node behind it
    queue.front = queue.front->next;
    queue.count = queue.count - 1;
    // delete anything in this address
    delete (deleteLoc);
    return true;
}

bool QUEUE::queueFront(data &dataOut) {
    if (queue.count == 0) return false;
    dataOut = queue.front->dat;
    return true;
}

bool QUEUE::queueRear(data &dataOut) {
    if (queue.count == 0) return false;
    dataOut = queue.rear->dat;
    return true;
}

void QUEUE::destroyQueue(void) {
    NODE *pWalker, *deletePtr;

    pWalker = queue.front;
    while (pWalker != NULL) {
        deletePtr = pWalker;
        pWalker = pWalker->next;
        delete(deletePtr);
    }
    queue.front = NULL;
    queue.rear = NULL;
    queue.count = 0;
    return;
}

void QUEUE::display() {
    if (isEmpty()) cout << "Can't display an empty queue!" << endl;
    // Copied destroyQueue() function (^_^;)
    else {
        NODE *pWalker = queue.front;

        cout << "Printing dat inside queue: \n\nFront -> || ";
        while(pWalker != NULL) {
            cout << pWalker->dat << " ";
            pWalker = pWalker->next;
        }
        cout << "|| <- Rear\n\nEnd dat print\n";
    }
    return;
}

#endif //QUEUE_H