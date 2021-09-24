# Cipher ADFGVX.
\
This is the solution of a project for the lecture of System Programming Lab at Bachelor Degree in [Computer Science](https://computerscience.unicam.it) at
[University of Camerino](https://www.unicam.it). The goal of this project is to implement an adaptation of the
[ADFGVX's Cypher](https://en.wikipedia.org/wiki/ADFGVX_cipher). 
# Building
\
To build the project first of all you have to clone the repository from GitHub:

`git clone https://github.com/robertocesetti/adfgvx`

Then create the cmake file by using the `CMakeLists.txt` file. 

So go into `adfgvx` directory and then type `cmake CMakeLists.txt`

Now it's possible to compile the program by using cmake, `make all` command
will generate the executable called `adfgvx`

# Executing
## List of commands:

To generate a key for encoding

`genkey <keyfile> <s1> <k1> <s2> <k2> <s3> <k3>`

To encode a file (inputfile)

`encode <keyfile> <inputfile> <outputfile>`

To decode an encoded file (inputfile)

` decode <keyfile> <inputfile> <outputfile>`

