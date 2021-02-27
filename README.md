# FibonacciCoder_Sequencial
For this project, I create a sequencial Fibonacci code generator using the tools such as link list.

In mathematics and computing, Fibonacci coding is a universal code that encodes positive integers into binary code words. It is one example of representations of integers based on Fibonacci numbers. Each codeword ends with "11" and contains no other instances of "11" before the end. (https://en.wikipedia.org/wiki/Fibonacci_coding)

I take these steps to implement Fibonacci code generator:

Read the alphabet of the original message (string) and the name of the input file (string) from STDIN.
Calculate the frequency of the symbols in the alphabet in the input file. 
Sort the alphabet in decreasing order based on the frequency of the symbols. If two or more symbols have the same frequency, I use the symbol's ASCII value to break the tie (the higher the value, the higher the priority).
Assign a positive integer value (starting from 1) to the symbols in the sorted alphabet. 
Print the codes of the symbols in the alphabet sorted in increasing order by their ASCII value.
Example:
STDIN input:
aeiou 
input1.txt
input1.txt content:
aaaeeeiiiooouuuuuuuuuuuuuuuuaaeeeeeeeiiiiiiiiiiiiiiiiiiiiiiiiiiiiaaaaa
Expected output:
Symbol: a, Frequency: 10, Code: 1011
Symbol: e, Frequency: 10, Code: 0011
Symbol: i, Frequency: 31, Code: 11
Symbol: o, Frequency: 3, Code: 00011
Symbol: u, Frequency: 16, Code: 011
