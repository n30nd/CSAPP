Consider numbers having a binary representation consisting of an infinite string
of the form 0.y y y y y y . . . , where y is a k-bit sequence. For example, the binary
representation of 31 is 0.01010101 . . . (y = 01), while the representation of 51 is
0.001100110011 . . . (y = 0011).
A. Let Y = B2U k (y), that is, the number having binary representation y. Give
a formula in terms of Y and k for the value represented by the infinite string.
Hint: Consider the effect of shifting the binary point k positions to the right.
B. What is the numeric value of the string for the following values of y?
(a) 101
(b) 0110
(c) 010011

A. let X = 2^k-1 * y_k-1 + ... + 2^0*k_0
value of 0.yyyy... = X*2^-k + X*2^-2k + ...
= sigma of (2^-ik) with i from 1 to inf 
= X/(2^k-1)

B.
101 -> X = 5, k = 3 => 5/7
0110 -> X = 6, k=4 => 6/15 = 2/5
010011 -> X = 1 + 2 + 16 = 19, k = 6 => 19/63
