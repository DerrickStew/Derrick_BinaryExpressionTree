#include "binaryExpressionTree.h"

// Default constructor
binaryExpressionTree::binaryExpressionTree() : binaryTreeType<string>() {}

// Function to create a node with the given info
nodeType<string>* binaryExpressionTree::createNode(const string& info) {
    nodeType<string>* newNode = new nodeType<string>;
    newNode->info = info;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    return newNode;
}

// Function to parse the postfix expression and build the tree
void binaryExpressionTree::parseAndBuildTree(const string& postfixExpr) {
    char* token = strtok(const_cast<char*>(postfixExpr.c_str()), " ");
    while (token != nullptr) {
        if (isdigit(token[0])) {
            nodeType<string>* newNode = createNode(token);
            nodeStack.push(newNode);
        }
        else {
            nodeType<string>* newNode = createNode(string(token));
            if (!nodeStack.empty()) {
                newNode->rLink = nodeStack.top();
                nodeStack.pop();
            }
            else {
                cout << "Error: Stack is empty!" << endl;
                return;
            }
            if (!nodeStack.empty()) {
                newNode->lLink = nodeStack.top();
                nodeStack.pop();
            }
            else {
                cout << "Error: Stack is empty!" << endl;
                return;
            }
            nodeStack.push(newNode);
        }
        token = strtok(nullptr, " ");
    }
    root = nodeStack.top();
    nodeStack.pop();
}

// Function to build an expression tree from a postfix expression
void binaryExpressionTree::buildExpressionTree(const string& postfixExpr) {
    destroyTree();
    parseAndBuildTree(postfixExpr);
}

// Function to evaluate the expression tree
double binaryExpressionTree::evaluateExpressionTree() {
    return evaluateExpressionTree(root);
}

// Recursive function to evaluate the expression tree
double binaryExpressionTree::evaluateExpressionTree(nodeType<string>* p) {
    if (p == nullptr) {
        cout << "Error: Invalid expression tree!" << endl;
        return 0.0;
    }
    if (isdigit(p->info[0])) {
        return stod(p->info);
    }
    double leftValue = evaluateExpressionTree(p->lLink);
    double rightValue = evaluateExpressionTree(p->rLink);
    if (p->info == "+") {
        return leftValue + rightValue;
    }
    else if (p->info == "-") {
        return leftValue - rightValue;
    }
    else if (p->info == "*") {
        return leftValue * rightValue;
    }
    else if (p->info == "/") {
        if (rightValue != 0) {
            return leftValue / rightValue;
        }
        else {
            cout << "Error: Division by zero!" << endl;
            return 0.0;
        }
    }
    else {
        cout << "Error: Invalid operator!" << endl;
        return 0.0;
    }
}

