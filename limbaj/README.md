## Background
The objective of this project was making a **parser** using **flex** and **bison** in order to pass a university course.
Basically, it recognizes a pseudo programming language using a context independent grammar.


## Quality of the code
- Obvious memory leaks, I just focused on making it work
- Hard to read and modify, I didn't use POO so much in the past

## Meeting requirements
- It met all the requirements of the laboratory, I even got a bonus for the arrays and symbol table (see **Features below**)
- Many inputs won't be parsed correctly/can crush the program

## Features
- The symbol table, that is structured as a **tree**:
The **root** of the symbol table has functions (the main function as well), classes and global variables as **children**. These children are in turn **symbol tables themselves**, which can contain for, while, do while loops as children, as well as other variables.
This way I don't have to remember all the path of a scope in which a variable is visible. It also looks good, children scopes being indented with a number of tabs equal to the number of edges to the root.
- Arrays that can have **more than 2 dimensions**. It was interesting to program.

## Conclusions
- We had too little guidance to make such a project, because of which it is almost useless. Just experience implementing a tricky system
- I realize how important it is to spend much time in the beginning building the architecture of the program 

## Other
In **prog.txt** man you can find an input example, and in **table.txt** you can see an example of a symbol table.



You can run it from the main directory using **make ; clear; ./limbaj prog.txt**