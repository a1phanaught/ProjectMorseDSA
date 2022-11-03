#include <iostream>
#include "treeNode.h"
#include "data.h"
#include "QUEUE.h"

#ifndef MORSE_h
#define MORSE_h

class MORSE {

    // Looks a bit messy, and I know there's a better way to
    // actually initialise these
    private:
        // Alphabetical
        treeNode *nodeA = new treeNode('A'), *nodeB = new treeNode('B');
        treeNode *nodeC = new treeNode('C'), *nodeD = new treeNode('D');
        treeNode *nodeE = new treeNode('E'), *nodeF = new treeNode('F');
        treeNode *nodeG = new treeNode('G'), *nodeH = new treeNode('H');
        treeNode *nodeI = new treeNode('I'), *nodeJ = new treeNode('J');
        treeNode *nodeK = new treeNode('K'), *nodeL = new treeNode('L');
        treeNode *nodeM = new treeNode('M'), *nodeN = new treeNode('N');
        treeNode *nodeO = new treeNode('O'), *nodeP = new treeNode('P');
        treeNode *nodeQ = new treeNode('Q'), *nodeR = new treeNode('R');
        treeNode *nodeS = new treeNode('S'), *nodeT = new treeNode('T');
        treeNode *nodeU = new treeNode('U'), *nodeV = new treeNode('V');
        treeNode *nodeW = new treeNode('W'), *nodeX = new treeNode('X');
        treeNode *nodeY = new treeNode('Y'), *nodeZ = new treeNode('Z');

        // Numerical and symbols
        treeNode *node0 = new treeNode('0'), *node1 = new treeNode('1');
        treeNode *node2 = new treeNode('2'), *node3 = new treeNode('3');
        treeNode *node4 = new treeNode('4'), *node5 = new treeNode('5');
        treeNode *node6 = new treeNode('6'), *node7 = new treeNode('7');
        treeNode *node8 = new treeNode('8'), *node9 = new treeNode('9');
        treeNode *nodeEQ = new treeNode('='), *nodeSL = new treeNode('/');
        treeNode *nodePL = new treeNode('+'), *nodeDt = new treeNode('.');
        treeNode *nodeCmm = new treeNode(','), *nodeCln = new treeNode(':');
        treeNode *nodeQt = new treeNode('\"'), *nodeAps = new treeNode('\'');
        treeNode *nodeXclm = new treeNode('!'), *nodeQstn = new treeNode('?');
        treeNode *nodeAt = new treeNode('@'), *nodeDsh = new treeNode('-');
        treeNode *nodeSmcln = new treeNode(';'), *nodeOBrack = new treeNode('(');
        treeNode *nodeCBrack = new treeNode(')');
        
        // Placeholder nodes
        treeNode *nodeStart = new treeNode('\0'), *nodeNa1 = new treeNode('\0');
        treeNode *nodeNa2 = new treeNode('\0'), *nodeNa3 = new treeNode('\0');
        treeNode *nodeNa4 = new treeNode('\0'), *nodeNa5 = new treeNode('\0');
        treeNode *nodeNa6 = new treeNode('\0'), *nodeNa7 = new treeNode('\0');
        treeNode *nodeNa8 = new treeNode('\0'), *nodeNa9 = new treeNode('\0');
    
    public:
        MORSE() {

            nodeStart->left = nodeE, nodeStart->right = nodeT;
            
            nodeE->left = nodeI, nodeE->right = nodeA;
            // I subtree
            nodeI->left = nodeS, nodeI->right = nodeU;
            nodeS->left = nodeH, nodeS->right = nodeV;
            nodeH->left = node5, nodeH->right = node4;
            nodeV->right = node3;
            nodeU->left = nodeF, nodeU->right = nodeNa1;
            nodeNa1->right = node2, nodeNa1->left = nodeNa8;
            nodeNa8->left = nodeQstn;
            // A subtree
            nodeA->left = nodeR, nodeA->right = nodeW;
            nodeR->left = nodeL, nodeR->right = nodeNa2;
            nodeL-> right = nodeNa6;
            nodeNa6->left = nodeQt;
            nodeNa2->left = nodePL;
            nodePL->right = nodeDt;
            nodeW->left = nodeP, nodeW->right = nodeJ;
            nodeP->right = nodeNa9;
            nodeNa9->left = nodeAt;
            nodeJ->right = node1;
            node1->left = nodeAps;

            nodeT->left = nodeN, nodeT->right = nodeM;
            // N subtree
            nodeN->left = nodeD, nodeN->right = nodeK;
            nodeD->left = nodeB, nodeD->right = nodeX;
            nodeB->left = node6, nodeB->right = nodeEQ;
            node6->right = nodeDsh;
            nodeX->left = nodeSL;
            nodeK->left = nodeC, nodeK->right = nodeY;
            nodeY->left = nodeOBrack;
            nodeOBrack->right = nodeCBrack;
            nodeC->right = nodeNa7;
            nodeNa7->left = nodeSmcln,nodeNa7->right = nodeXclm;
            // M subtree
            nodeM->left = nodeG, nodeM->right = nodeO;
            nodeG->left = nodeZ, nodeG->right = nodeQ;
            nodeZ->left = node7, nodeZ->right = nodeNa5;
            nodeNa5->right = nodeCmm;
            nodeO->left = nodeNa3, nodeO->right = nodeNa4;
            nodeNa3->left = node8;
            node8->left = nodeCln;
            nodeNa4->left = node9, nodeNa4->right = node0;

        }

        data morseEval(QUEUE &q) {
            data temp;
            treeNode *curr = nodeStart;
            while (!q.isEmpty()) {
                q.dequeue(temp);
                if (temp == '.')
                    curr = curr->left;
                else if (temp == '-')
                    curr = curr->right;
            }
            return curr->dat;
        }

};

#endif