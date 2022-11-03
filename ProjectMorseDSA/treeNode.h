#include <iostream>
#include "data.h"

#ifndef treeNode_h
#define treeNode_h

using namespace std;
 
struct treeNode {
    data dat;
    struct treeNode* left;
    struct treeNode* right;
 
    // val is the key or the value that
    // has to be added to the data part
    treeNode(char val) {
        dat = val;
 
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

#endif // treeNode_h