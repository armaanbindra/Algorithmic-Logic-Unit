Sample Output
F0=0, F1=0, F2=0
alu2(0, 0, 0, 0, 0, 0) --> 0
alu2(0, 0, 0, 0, 0, 1) --> 0
alu2(0, 0, 0, 0, 1, 0) --> 0
alu2(0, 0, 0, 0, 1, 1) --> 2
alu2(0, 0, 0, 1, 0, 0) --> 0
alu2(0, 0, 0, 1, 0, 1) --> 0
alu2(0, 0, 0, 1, 1, 0) --> 0
alu2(0, 0, 0, 1, 1, 1) --> 2

F0=0, F1=0, F2=1
alu2(0, 0, 1, 0, 0, 0) --> 0
alu2(0, 0, 1, 0, 0, 1) --> 2
alu2(0, 0, 1, 0, 1, 0) --> 2
alu2(0, 0, 1, 0, 1, 1) --> 0
alu2(0, 0, 1, 1, 0, 0) --> 0
alu2(0, 0, 1, 1, 0, 1) --> 2
alu2(0, 0, 1, 1, 1, 0) --> 2
alu2(0, 0, 1, 1, 1, 1) --> 0

F0=0, F1=1, F2=0
alu2(0, 1, 0, 0, 0, 0) --> 0
alu2(0, 1, 0, 0, 0, 1) --> 2
alu2(0, 1, 0, 0, 1, 0) --> 2
alu2(0, 1, 0, 0, 1, 1) --> 2
alu2(0, 1, 0, 1, 0, 0) --> 0
alu2(0, 1, 0, 1, 0, 1) --> 2
alu2(0, 1, 0, 1, 1, 0) --> 2
alu2(0, 1, 0, 1, 1, 1) --> 2

F0=0, F1=1, F2=1
alu2(0, 1, 1, 0, 0, 0) --> 2
alu2(0, 1, 1, 0, 0, 1) --> 2
alu2(0, 1, 1, 0, 1, 0) --> 2
alu2(0, 1, 1, 0, 1, 1) --> 0
alu2(0, 1, 1, 1, 0, 0) --> 2
alu2(0, 1, 1, 1, 0, 1) --> 2
alu2(0, 1, 1, 1, 1, 0) --> 2
alu2(0, 1, 1, 1, 1, 1) --> 0

F0=1, F1=0, F2=0
alu2(1, 0, 0, 0, 0, 0) --> 2
alu2(1, 0, 0, 0, 0, 1) --> 0
alu2(1, 0, 0, 0, 1, 0) --> 2
alu2(1, 0, 0, 0, 1, 1) --> 0
alu2(1, 0, 0, 1, 0, 0) --> 2
alu2(1, 0, 0, 1, 0, 1) --> 0
alu2(1, 0, 0, 1, 1, 0) --> 2
alu2(1, 0, 0, 1, 1, 1) --> 0

F0=1, F1=0, F2=1
alu2(1, 0, 1, 0, 0, 0) --> 2
alu2(1, 0, 1, 0, 0, 1) --> 0
alu2(1, 0, 1, 0, 1, 0) --> 0
alu2(1, 0, 1, 0, 1, 1) --> 0
alu2(1, 0, 1, 1, 0, 0) --> 2
alu2(1, 0, 1, 1, 0, 1) --> 0
alu2(1, 0, 1, 1, 1, 0) --> 0
alu2(1, 0, 1, 1, 1, 1) --> 0

F0=1, F1=1, F2=0
alu2(1, 1, 0, 0, 0, 0) --> 0
alu2(1, 1, 0, 0, 0, 1) --> 2
alu2(1, 1, 0, 0, 1, 0) --> 2
alu2(1, 1, 0, 0, 1, 1) --> 1
alu2(1, 1, 0, 1, 0, 0) --> 2
alu2(1, 1, 0, 1, 0, 1) --> 1
alu2(1, 1, 0, 1, 1, 0) --> 1
alu2(1, 1, 0, 1, 1, 1) --> 3

F0=1, F1=1, F2=1
alu2(1, 1, 1, 0, 0, 0) --> 2
alu2(1, 1, 1, 0, 0, 1) --> 2
alu2(1, 1, 1, 0, 1, 0) --> 0
alu2(1, 1, 1, 0, 1, 1) --> 0
alu2(1, 1, 1, 1, 0, 0) --> 2
alu2(1, 1, 1, 1, 0, 1) --> 2
alu2(1, 1, 1, 1, 1, 0) --> 0
alu2(1, 1, 1, 1, 1, 1) --> 0

Documentation on Extra Features

This program simulates a more functional version of the 1 Bit ALU from the Basic Assignment but with a simpler interface

The alu2(…) function takes in 6 arguments, which are:

F_0          //First Control Line
F_1          //Second Control Line
F_2          //Third Control Line
CarryIn // The  Carry In 
A             //  The First Variable     
B             //  The Second Variable

There are 8 possible combinations of the three control lines F0, F1 and F3 that each carry out the following different functions on different combinations of the CarryIn, A and B:

F0=0, F1=0, F2=0: A AND B
F0=0, F1=0, F2=1: A XOR B
F0=0, F1=1, F2=0: A OR B
F0=0, F1=1, F2=1: A NAND B
F0=1, F1=0, F2=0: NOT B
F0=1, F1=0, F2=1: A NOR B
F0=1, F1=1, F2=0: A + B (Arithmetic Sum)
F0=1, F1=1, F2=1: NOT A 
