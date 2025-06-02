We are running programs where values of type int are 32 bits. They are repre-
sented in two’s complement, and they are right shifted arithmetically. Values of
type unsigned are also 32 bits.

We generate arbitrary values x and y, and convert them to unsigned values as
follows:
/* Create some arbitrary values */
int x = random();
int y = random();
/* Convert to unsigned */
unsigned ux = (unsigned) x;
unsigned uy = (unsigned) y;
For each of the following C expressions, you are to indicate whether or
not the expression always yields 1. If it always yields 1, describe the underlying
mathematical principles. Otherwise, give an example of arguments that make it
yield 0.
A. (x<y) == (-x>-y) 
B. ((x+y)<<4) + y-x == 17*y+15*x
C. ~x+~y+1 == ~(x+y)
D. (ux-uy) == -(unsigned)(y-x)
E. ((x >> 2) << 2) <= x

A. x = INT_MIN lead to false 
B.Correct
C. correct. ~x = -1 -x, transf0rm left and right == to the same 
D. Correct 
E.Correct