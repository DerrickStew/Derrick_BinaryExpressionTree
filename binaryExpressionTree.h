#pragma once

#include "binaryTree.h"
#include <stack>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:
    // Default constructor
    binaryExpressionTree();

    // Function to build an expression tree from a postfix expression
    void buildExpressionTree(const string& postfixExpr);

    // Function to evaluate the expression tree
    double evaluateExpressionTree();

    // Function to determine if searchItem is in the binary tree.
    // Postcondition: Returns true if searchItem is found in the binary tree; otherwise, returns false.
    bool search(const string& searchItem) const override;

    // Function to insert insertItem in the binary tree.
    // Postcondition: If there is no node in the binary tree that has the same info as insertItem, 
    // a node with the info insertItem is created and inserted in the binary search tree.
    void insert(const string& insertItem) override;

    // Function to delete deleteItem from the binary tree
    // Postcondition: If a node with the same info as deleteItem is found, 
    // it is deleted from the binary tree. If the binary tree is empty or deleteItem is not in the binary tree, 
    // an appropriate message is printed.
    void deleteNode(const string& deleteItem) override;


protected:
    // Helper function to create a node with the given info
    nodeType<string>* createNode(const string& info);

    // Helper function to parse the postfix expression and build the tree
    void parseAndBuildTree(const string& postfixExpr);

    // Recursive function to evaluate the expression tree
    double evaluateExpressionTree(nodeType<string>* p);

private:
    // Stack to store tree nodes during tree construction
    stack<nodeType<string>*> nodeStack;
};

