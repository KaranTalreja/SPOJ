Little Willy just took a compilers course and is trying to implement his own compiler. First he wants to build a table with all the possible ids that a program could have. He knows that his language supports up to N different characters and any id can be up to L characters long. For example, when N = 2 (lets say characters can be 0 or 1), and L = 3, he could have the following ids: {0, 1, 00, 01, 10, 11, 000, 001, 010, 011, 100, 101, 110, 111}.

You have to write a program that can help Willy find out the size of the table. Since the answer can be really big, you must print it modulo 1000000007 (10^9+7).

Credits:http://comeoncodeon.wordpress.com/2011/10/09/modular-multiplicative-inverse/

Instructions:
1.To build run command
    make
2.To run testcases run command in current directory
    ./runCases.sh

3.Maintain Testcases

List of all the failed testcases is entered into TestResult/failedCases.
Analyze the failiures by looking at TEST files in the respective directory. Regold the testcases by running the following command.

./reGold.sh TestResult/failedCases

