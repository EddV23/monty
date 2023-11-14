Monty Project
This project is an implementation of a simple programming language interpreter called Monty. The interpreter supports various stack and queue operations and is written in C. It includes a set of Brainf*ck scripts to perform basic arithmetic operations.

Table of Contents
Project Overview
File Structure
Building and Running
Brainf*ck Scripts
Contributing
License
Project Overview
Monty is a stack-based language interpreter that supports both LIFO (Last-In, First-Out) stack and FIFO (First-In, First-Out) queue operations. The interpreter reads Monty bytecode files and executes the specified operations.

Supported Opcodes
The project implements various stack and queue operations, including:

push: Pushes an element onto the stack.
pall: Prints all the values on the stack.
pint: Prints the value at the top of the stack.
pop: Removes the top element of the stack.
swap: Swaps the top two elements of the stack.
add: Adds the top two elements of the stack.
nop: No operation; does nothing.
sub: Subtracts the top element from the second top element of the stack.
div: Divides the second top element by the top element of the stack.
mul: Multiplies the second top element by the top element of the stack.
mod: Computes the remainder of the division of the second top element by the top element of the stack.
comments: Ignores the rest of the line (comments start with #).
pchar: Prints the character at the top of the stack.
pstr: Prints the string starting at the top of the stack.
rotl: Rotates the stack to the top.
rotr: Rotates the stack to the bottom.
stack: Sets the format of the data to a stack (LIFO).
queue: Sets the format of the data to a queue (FIFO).
Compilation & Output
The code is compiled using the following command:

bash
Copy code
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
The interpreter reads Monty bytecode files with the .m extension. Each line in the bytecode file represents a Monty instruction.

File Structure
The project file structure is organized as follows:

monty.c: Main file responsible for reading and interpreting Monty bytecode files.
monty.h: Header file containing function prototypes and necessary data structures.
opcodes_x.c: Files containing the implementation of each opcode, where x corresponds to the opcode number.
bf: Directory containing Brainf*ck scripts.
1000-school.bf: Brainf*ck script to print "School".
1001-add.bf: Brainf*ck script to add two digits.
1002-mul.bf: Brainf*ck script to multiply two digits.
1003-mul.bf: Brainf*ck script to multiply two digits (level up).
Building and Running
To build the Monty interpreter, use the following command:

bash
Copy code
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
To run the interpreter with a Monty bytecode file:

bash
Copy code
$ ./monty path/to/bytecode_file.m
To run the Brainf*ck scripts, use the bf interpreter:

bash
Copy code
$ bf bf/1000-school.bf
$ bf bf/1001-add.bf
$ bf bf/1002-mul.bf
$ bf bf/1003-mul.bf
Brainf*ck Scripts
1000-school.bf: Brainf*ck script to print "School".
1001-add.bf: Brainf*ck script to add two digits.
1002-mul.bf: Brainf*ck script to multiply two digits.
1003-mul.bf: Brainf*ck script to multiply two digits (level up).
Contributing
Contributions are welcome! If you have any suggestions, improvements, or additional features to add, feel free to create an issue or submit a pull request.

License
This project is licensed under the MIT License.
