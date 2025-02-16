## Background
The objective of this project was making a **parser** using **flex** and **bison** in order to pass a university course.
Basically, it recognizes a pseudo programming language using a context independent grammar.

## Example Input
```
CLASS_SECTION
class Person {
private:
    int a;
    int b;
    fn func(int a, int x, float b ) -> int {
        return 10;
    } 
}
GLOBAL_VARIABLES

int gx = 19;

GLOBAL_FUNCTIONS

fn rand() -> int {
    return 10;
}

MAIN_FUNCTION
fn main() { 

    int a [2][2][2][2][2];
    a[0][0][0][0] = [1,2];

    Person p(b:20);

    const int x = p.b;
    
    int f = p.func(1,2,1.2);

    typeof ( (x* p.b) <= 100 );
    eval ( (x* p.b) <= 100 + p.func(1,2,1.2));
    
    int sum = 0;
    for(int x = 10; x <100; ) {

        sum = sum + x;
    }
}
```

## Example Symbol Table
```
global
  class Person
    fn func(int a, int x, float b) -> int
    int b
    int a
  fn main() -> void
    for()#0
      int x = 10
    int sum = 10
    int f = 0
    const int x = 20
    Person p = (int a; int b = 20; )
    int[2][2][2][2][2] a = [[[[[1,2],[0,0]],[[0,0],[0,0]]],[[[0,0],[0,0]],[[0,0],[0,0]]]],[[[[0,0],[0,0]],[[0,0],[0,0]]],[[[0,0],[0,0]],[[0,0],[0,0]]]]]
  fn rand() -> int
  int gx = 19
```
The global scope contains the class Person, the global variable gx, and 2 function. Function main contains a for loop (it has its own scope), among other things.
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
