E++ Language Documentation
E++ is a high-level, dynamically typed programming language implemented in standard C++17. Designed with beginner-friendly, English-like syntax inspired by Python, E++ strictly avoids standard garbage collection to give developers direct, predictable C++-style control over memory lifetimes.

Technical Overview
Standard Version: Standard executable environment. Requires strict entry point rules.

Type System: Dynamic typing with built-in support for Numbers, Strings, Booleans, and Arrays.

Memory Model: No garbage collector. Memory is explicitly standard C++ lifetime management.

Case Sensitivity: Flexible keyword parser allowing standard lower and uppercase variants for Boolean keywords.

Getting Started
Installation & Compilation
To build the E++ interpreter from source, compile using any standard C++17 compiler (such as GCC or Clang):

Bash
# Using GCC
g++ -std=c++17 eplusplus.cpp -o eplusplus

# Using Clang
clang++ -std=c++17 eplusplus.cpp -o eplusplus
File Requirements & Main Entry Point
E++ script files must use the .epp extension.

In standard E++, the compiler enforces an entry point check: the keyword main must appear on the very first line of your source file. Any file missing main on line 1 will throw a fatal compiler error.

Example File: app.epp
Plaintext
main
appName : "E++ System Engine"
version•
say'" E++ initialized successfully. "'
Executing Code
Pass your .epp file directly to the compiled E++ binary:

Bash
./eplusplus app.epp
Language Syntax & Features
Variables
Variables in E++ do not require keyword declarations (such as var or let). Use the name : value syntax:

Plaintext
age : 25
name : "Developer"
Booleans
Boolean values are case-insensitive and accept standard combinations of lowercase and uppercase letters:

Plaintext
isReady : true
isComplete : FALSE
isActive : True
Arrays
Arrays replace standard square brackets [] with curly braces {}:

Plaintext
scores : {10, 20, 30, 40}
items : {"apple", "banana", "cherry"}
Built-in Commands
say'" <message> "': Prints output to the standard output buffer.

version•: Prints the current compiler and runtime release version.

Plaintext
version•
say'" Hello, World! "'
Statements & Control Flow
E++ utilizes Python-style conditional structures with custom expression syntax:

If Statement: if ' condition ' = ()

Elif Statement: elif ' condition ' = ()

Else Statement: else

Plaintext
x : 10
if ' x > 5 ' = ()
    say'" X is greater than 5 "'
else
    say'" X is lower or equal "'
Loops
While Loop: while ' condition ' = ()

For Loop: for ' init, condition, step ' = ()

Plaintext
count : 0
while ' count < 5 ' = ()
    say'" Loop iteration "'
    count : count + 1
Functions
Functions are defined using the function keyword and square bracket syntax []:

Plaintext
function ' greet ' = [
    say'" Welcome to E++ "'
]
Memory Model & Compatibility
E++ eliminates background garbage collection. Variables and allocations exist directly in C++ stack/heap memory, following standard scoping lifetime rules.

If a developer attempts to call an undeclared variable or access an invalid reference, E++ throws an explicit runtime error:

Plaintext
[E++ Memory Error]: Variable 'myVar' is undeclared!

this code is under the license (MIT)
