#pragma once

#include "binaryTree.h" 
#include <stack>

class binaryExpressionTree : public binaryTreeType<string>
{
private:
    // create a new node with the given info
    // precondition - info is a valid string
    // postcondition - a new node with the provided info is created and returned
    nodeType<string>* createNode(const string& info);

    // parse the postfix expression and build the tree
    // precondition - postfixExpr is a valid postfix expression string
    // postcondition - The expression tree representing the postfix expression is built
    void parseAndBuildTree(const string& postfixExpr);

protected:
    // Stack to store intermediate nodes during tree construction
    stack<nodeType<string>*> nodeStack;

public:
    // default constructor
    binaryExpressionTree();

    // build an expression tree from a postfix expression
    // precondition - postfixExpr is a valid postfix expression string
    // postcondition - expression tree representing the postfix expression is built
    void buildExpressionTree(const string& postfixExpr);

    // evaluate the expression tree
    // precondition - expression tree has been built
    // postcondition - result of the expression tree evaluation is returned
    double evaluateExpressionTree();

    // recursive function to evaluate the expression tree
    // precondition - p points to a valid node in the expression tree
    // postcondition - The result of evaluating the subtree rooted at p is returned
    double evaluateExpressionTree(nodeType<string>* p);

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
};
