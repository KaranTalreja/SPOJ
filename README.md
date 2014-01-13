N persons are standing in a line. Height of each person is between 1 and N and height of each person is distinct. 

You are  given an array A where A[i] denotes how many persons are there before the i_th person having heights greater than the height of the ith person. For a person i, all the persons from 1 to i - 1 are considered to be before him. eg, For person 2, person 1 is considered before him.

You have to find out whether this array can be valid for some arrangement of persons. If you can uniquely do so then output "YES" Otherwise output "NO".

Instructions:
1.To build run command
    make
2.To run testcases run command in current directory
    ./runCases.sh

3.Maintain Testcases

List of all the failed testcases is entered into TestResult/failedCases.
Analyze the failiures by looking at TEST files in the respective directory. Regold the testcases by running the following command.

./reGold.sh TestResult/failedCases

