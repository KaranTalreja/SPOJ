#!/bin/bash
# Script to run all the testCases in TestCases directory

for dir in ./TestCases/*; do
touch $dir/TEST
cat $dir/TestCase | ./bin/LIFE > $dir/TEST
NEW=`diff $dir/GOLD $dir/TEST`
if [ -z "$NEW" ]; then
    echo "PASSED $dir"
else
    echo "FAILED $dir"
fi
done;
