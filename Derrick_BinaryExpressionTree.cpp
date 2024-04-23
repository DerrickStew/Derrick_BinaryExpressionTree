// Derrick_BinaryExpressionTree_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "binaryExpressionTree.h"
#include <string>

int main()
{
    ifstream inputFile("RpnData.txt");
    ofstream outputFile("results.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    binaryExpressionTree expressionTree;
    string postfixExpr;

    while (getline(inputFile, postfixExpr)) {
        expressionTree.buildExpressionTree(postfixExpr);
        double result = expressionTree.evaluateExpressionTree();
        outputFile << "Result: " << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

