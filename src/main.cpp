/**
 * @file main.cpp
 * @brief This is a heap code
 * @details This is the long brief of heap
 * @author Bona Tufa
 * @date 3/28/2021
 * 
 */

#include <iostream>
#include <random>
using namespace std;

/**
 * Add two integers (brief)
 * 
 * Adds a and b, two integers (long description)
 * @param a integer
 * @param b integer
 * @returns integer sum of a and b
 */

class BTNode{
public:
    BTNode* parent;
    BTNode* right;
    BTNode* left;
    int y;
    int count;
    BTNode* root = NULL;

    BTNode() {
        left = NULL;
        right = NULL;
        parent = NULL;
        y = 0;
        root = NULL;
        count = 0;
    }

int nodeData() {
        return(y);
    }

BTNode* merge(BTNode* h1, BTNode* h2){
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    if ((h2->y - h1->y) < 0)
        return merge(h2,h1);

    if (rand() % 2){
        h1->left = merge(h1->left, h2);
        if (h1->left != NULL)
            h1->left->parent = h1;
    }else{
        h1->right = merge(h1->right, h2);
        if (h1->right != NULL)
            h1->right->parent = h1;}
    return h1;
    }

bool add(int x){
    BTNode* u = new BTNode();
    u->left = u->right = u->parent = NULL;
    parent = NULL;
    u->y = x;
    root = merge(u, root);
    root->parent = NULL;
    count++;
    return true;
}

bool remove(){
    int y = root->y;
    BTNode* tmp = root;
    root = merge(root->left, root->right);
    delete tmp;
    if (root != NULL)
        root->parent = NULL;
    count--;
    return root;
}
void printBT(const string& prefix, BTNode* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        //cout << node->nodeName() << ':' << node->nodeData() << std::endl;
        cout << node->nodeData() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT()
{
    printBT("", root, false);
}

};

int main() {
    BTNode value;
    
    value.add(5);
    value.add(9);
    value.add(4);
    value.printBT();
    value.add(1);
    value.add(8);
    value.printBT();
    value.remove();
    value.remove();
    value.printBT();
    value.add(4);
    value.add(9);
    value.add(10);
    value.printBT();
    value.remove();
    value.remove();
    value.add(11);
    value.add(13);
    value.add(9);
    value.printBT();
    value.remove();
    value.remove();
    value.add(15);
    value.add(12);
    value.add(17);
    value.printBT();
    value.remove();
    value.remove();

}


