# HuffmanCodif. A project for Estrutura de Dados Básicas 2 (EDB II)

## Introduction

This programming project implements the BARES, Basic Arithmetic Expression Evaluator based on Stacks. Using the [EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form) grammar, the [recursive descendent parsing](https://en.wikipedia.org/wiki/Recursive_descent_parser) strategy for the expressionsn, and utilizing the [Tokenization method](https://en.wikipedia.org/wiki/Lexical_analysis#Tokenization) for separation.

## Algorithms

Functions implemented for:

1. Converting an expression received into a sequence of tokens, using a `recursive descendent parsing` strategy.
2. Converting an infix tokenized expression into its corresponding postfix representation, using a stack of Tokens.
3. Evaluating an postfix expression using a stack, therefore returning it's mathematical accurate value.

## How to compile

First of all, obviously this repository is needed to work as desired, so we must to download this repo. As we know that ```git``` is a tremendous tool for any programmer, then we must have git installed.

It is also expected for user to have installed [doxygen](https://en.wikipedia.org/wiki/Doxygen) program. This will automatically generate documentation for code. Not a necessary package to compile and run program, but it is a tool to guide user through code functions. To install `doxygen` on UBUNTU, for example:

```bash
$ sudo apt-get install doxygen
```
To compile we will use a makefile, so compilations may be more dynamic and automatic.
```bash
# Using 'git clone' to clone this repo into desired directory:
$ git clone https://github.com/ozielalves/Bares.git

# Enter repo:
$ cd Bares

# To compile the whole project and also generate documentation, insert 'make' inside root of path:
$ make

# To clean up all remaining trash data and files, such as the binary ones, insert 'make clean':
$ make clean
```

## How to execute

Now, we show how to run the program. 
```bash
# To execute program:
$ ./bares <input_file> <output_file>
```
- `<input_file>`: Represents the file containing all the expressions wished to be tested.
- `<output_file>`: File where the results obtained through parsing and calculations are written.

### Example

Let's say your information is stored in a file called $in.txt$, which is inside the directory $data$, and you want to store the results into a file named $out.txt$, also inside $data$ directory. The program should run like this:
```bash
$ ./bares data/in.txt data/out.txt
```
## GitHub Repository:

*https://github.com/Codigos-de-Guerra/HuffmanCodif*

## Report

Approach followed was ... using ...
Complexities below ...


## Authorship

Program developed by [_Daniel Oliveira Guerra_](https://github.com/Codigos-de-Guerra) (*daniel.guerra13@hotmail.com*), 2018.2

&copy; IMD/UFRN 2018.
