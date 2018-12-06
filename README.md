# HuffmanCodif. A project for Estrutura de Dados Básicas 2 (EDB II)

## Introduction

Programming project implementing a form of file compressing called [*Huffman Coding*](https://en.wikipedia.org/wiki/Huffman_coding). Largely used for [lossless data compression](https://en.wikipedia.org/wiki/Lossless_compression).
This code works by shrinking the most used data on certain file, so that these with more occurency, can have the lowest value, generating a well structured compression.

## TODO

- [ ] Detailed README
- [ ] Report
- [ ] Decompactor
- [x] Todo o fucking resto hehe

## How to compile

First of all, obviously this repository is needed to work as desired, so we must to download this repo. As we know that ```git``` is a tremendous tool for any programmer, then we must have git installed.

It is also expected for user to have installed [doxygen](https://en.wikipedia.org/wiki/Doxygen) program. This will automatically generate documentation for code.
Not a necessary package to compile and run program, but it is a tool to guide user through code functions. Some errors will appear when compiling if not installed, but complete binary will still generate.
To install `doxygen` on UBUNTU, for example:

```bash
$ sudo apt-get install doxygen
```
To compile we will use a makefile, so compilations may be more dynamic and automatic.
```bash
# Using 'git clone' to clone this repo into desired directory:
$ git clone https://github.com/Codigos-de-Guerra/HuffmanCodif.git

# Enter repo:
$ cd HuffmanCodif

# To compile the whole project and also generate documentation, insert 'make' inside path's root:
$ make

# To clean up all remaining trash data and files, such as the binary ones, insert 'make clean':
$ make clean
```

## How to execute

For execution, the main binary object is need alongside two others arguments, with the last being optional. When no 2º argument is given, it will be saved as "build/compressed.txt"
Now, we show how to run the program. 
```bash
# To execute program:
$ ./huff <input_file> <output_file>
```
- `<input_file>`: Refers to file containing text to be compressed.
- `<output_file>`: Refers to compacted file containg results of compression.

### Example

Let's say your information is stored in a file called $in.txt$, which is inside the directory $data$, and you want to store the results into a file named $out.txt$, also inside $data$ directory. The program should run like this:
```bash
$ ./huff data/in.txt data/out.txt
```
## GitHub Repository:

*https://github.com/Codigos-de-Guerra/HuffmanCodif*

## Report

Approach followed was ... using ...
Complexities below ...


## Authorship

Program developed by [_Daniel Oliveira Guerra_](https://github.com/Codigos-de-Guerra) (*daniel.guerra13@hotmail.com*), 2018.2

&copy; IMD/UFRN 2018.
