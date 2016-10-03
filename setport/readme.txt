INSTRUCTIONS:

To run ./portsetter.cpp.0 as setport from anywhere in the file system:
    Open Terminal
    Type in terminal:
        nano ~/.bashrc
    Type at bottom of terminal:
        alias setport='[FULL PATH]'
    Example:
        alias setport='/home/ubuntu/workspace/cs3370/portsetter.cpp.o'
    Press Ctrl + x to exit nano, then y to save, then Enter.
    Exit terminal then open terminal again and setport will work.
    
After setport is set, setport will work anywhere in the file system. To get all the files used in setport to run properly, make 
sure to be in the right directoy.
    
Use the flag -h, --help, or -? after setport to get usage on how to use commands in portsetter.
    
To run the test program type:
    ./testsetport.cpp.o
The tests will output for both english and spanish tests if setport was successful, if the output was expected, and if the test
passed for each test case.