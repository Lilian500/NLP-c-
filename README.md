# Programming Probability Collector [26pts]:

You must make sure your C++ program compiles with g++ and runs on empress.csusm.edu or 0pts.

Your language alphabet is A, B, C.   You want to be able to later compute P(any word).
A program already went through the training corpus to collect trigram probabilities for:
P(A | nothing before)
P(A | only A before)
P(A | only B before)
P(A | only C before)
P(A | AA)
P(A | AB)
P(A | AC)
P(A | BA)
…
P(B | nothing before)
P(B | only A before)
,,,,
P(C | nothing before)
P(C | only A before)
…
Q1) How many probabilities did it have to collect? Why? [3]
39 probabilities. 
First, we will have the probabilities of a letter with 2 letters before it(p(letter|two letters before). We have 3 letters already which are A, B and C. Each of these letters must have probabilities with 2 letters before them starting from AA to CC. This will give 9 probabilities for each and 9 * 3 = 27 for all of them. Then we have the probabilities with just a single letter before each of the letters A, B and C. This will give 3 for each and 3 * 3 = 9 for all of them. Finally we have probabilities for each letter having nothing before them. This just give 1 probability for each letter and  3 probabilities for all three leteers. Adding all of these probabilities, we’ll get 27 + 9 + 3 = 39 probabilities.
After answering this question, write a C++ program to read a file containing these probabilities and store them in some data structure.   Make sure it displays the content of the data structure in an easy to read format. You have to prepare your own input file with made-up numbers. Name it nlpProb.txt [10]

Q2) How do you compute P(“abca”)? Give the equation.  [3]
P(“abca”) =  P(a|null) * P(b|a) * P(c|ab) * P(a|bc)

After answering this question, extend your program so that it will allow the user to enter any word made up of A, B, and/or C and it will compute and output its probability.
Make sure it displays all the P’s that were used to compute the answer.  [10]

Test your program on “abbca” “baac”  and “cab” (you should test more but these are required to be submitted).
