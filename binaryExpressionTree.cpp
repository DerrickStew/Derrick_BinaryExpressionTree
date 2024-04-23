#include "binaryExpressionTree.h"
#include <stack>
#include <cstring>
#include <string>

void binaryExpressionTree::parseAndBuildTree(const string& postfixExpr)
{
    char* nextToken;
    char* token = strtok_s(const_cast<char*>(postfixExpr.c_str()), " ", &nextToken);
    while (token != nullptr)
    {
        // check if the token is a number (operand)
        if (isdigit(token[0]))
        {
            // create a new node for the operand and push it onto the stack
            nodeType<string>* newNode = createNode(token);
            nodeStack.push(newNode);
        }
        else
        {
            // create a new node for the operator
            nodeType<string>* newNode = createNode(string(token));
            if (!nodeStack.empty())
            {
                newNode->rLink = nodeStack.top();
                nodeStack.pop();
            }
            else
            {
                cout << "Error: Stack is empty!" << endl;
                return;
            }
            if (!nodeStack.empty())
            {
                newNode->lLink = nodeStack.top();
                nodeStack.pop();
            }
            else
            {
                cout << "Error: Stack is empty!" << endl;
                return;
            }
            nodeStack.push(newNode);
        }
        token = strtok_s(nullptr, " ", &nextToken);
    }
    root = nodeStack.top();
    nodeStack.pop();
}

void binaryExpressionTree::buildExpressionTree(const string& postfixExpr)
{
    destroyTree();
    parseAndBuildTree(postfixExpr);
}

double binaryExpressionTree::evaluateExpressionTree()
{
    return evaluateExpressionTree(root);
}

double binaryExpressionTree::evaluateExpressionTree(nodeType<string>* p)
{
    // check if the node is valid
    if (p == nullptr)
    {
        cout << "Error: Invalid expression tree!" << endl;
        return 0.0;
    }
    if (isdigit(p->info[0]))
        return stod(p->info);
    // recursively evaluate the left & right subtrees & apply the operator
    double leftValue = evaluateExpressionTree(p->lLink);
    double rightValue = evaluateExpressionTree(p->rLink);
    if (p->info == "+")
        return leftValue + rightValue;
    else if (p->info == "-")
        return leftValue - rightValue;
    else if (p->info == "*")
        return leftValue * rightValue;
    else if (p->info == "/")
    {
        if (rightValue != 0)
            return leftValue / rightValue;
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 0.0;
        }
    }
    else
    {
        cout << "Error: Invalid operator!" << endl;
        return 0.0;
    }
}
