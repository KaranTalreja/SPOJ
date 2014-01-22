Binary trees can sometimes be very difficult to work with. Fortunately, there is a class of trees with some really nice properties. A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.

The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.

Given the pre-order traversal of a nice binary tree, you are required to find the depth of the tree.

Notes : 

1. The depth of a tree is defined as the length of the longest path with one end at the root.

2. The pre-order traversal of the tree in the first image above produces the string “nlnnlll”.
Instructions:
1.To build run command
    make
2.To run testcases run command in current directory
    ./runCases.sh

3.Maintain Testcases

List of all the failed testcases is entered into TestResult/failedCases.
Analyze the failiures by looking at TEST files in the respective directory. Regold the testcases by running the following command.

./reGold.sh TestResult/failedCases

