/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
       //bangs x. If x is 0 it becomes 1 for true, if it is any other # banging it returns 0
  return !x;
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
  /*should return 1 any time y is 1. Bang x and or with y to make x 0 in the case that x is 1 and yis 0. Or with regular y so it is always 1 if y is 1.*/ 
 return (!x) | y;

}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  //When you & x with its 2's complement it returns the least positive bit
  x = x & (~x + 1);
  return x;
}
/* 
 * evenOddSwap -- switch every bit with its buddy bit.  Bits 0 and 1 are buddies, bits 2 and 3 are buddies, and so on  
 *   Example: evenOddSwap(0) = 0;
 *            evenOddSwap(16) = 32;
              evenOddSwap(0x12345678) = 0x2138a9b4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int evenOddSwap(int x) {
  /*creates a mask for the even bits then one for the odd bits by flipping the bits of the even mask.  Get just the even bits and the odd bits of x by storing each in a variable with x & either mask. Shift the evens right 1 and the odds left by 1(also masking with tmax to kill sign extended bit). Or them together to combine bits to complete swap. */
  int evenMask = (0xAA << 24)|(0xAA << 16) | (0xAA << 8) | (0xAA);
  int oddMask = ~evenMask;
  int evens = x & evenMask;
  int odds = x & oddMask;
  return ((evens >> 1)&(~(1<<31)))|(odds << 1);
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) { 
  //shifts x by 32-n positions in order to get n bits to the front of the number. Creates a mask of tmax and shifts that right by n-1 to create a mask that will remove the bits where the new bits will go. shift x by n to move the number over and and with mask to leave space for shifted 'rotated' bits. or the two together to get result
  int movingPart = x << (32 + (~n +1));
  int tmax = ~(1 << 31);
  tmax = tmax >> (n+((~1)+1));
  x = x >> n;
  x = x & tmax;
  return x | movingPart;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  //cuts the number into halves and xors them. repeats for 16, 8, 4, 2, and 1 bit chunks till it gets the final answer
  int mask = (0xFF << 8) | (0xFF);
  int x1 = x & mask;
  int x2 = (x >> 16) & mask;
  int answer = x1 ^ x2;
  x1 = answer & 0xFF;
  x2 = (answer >> 8) & 0xFF;
  answer = x1 ^ x2;
  x1 = answer & 0x0F;
  x2 = (answer >> 4) & 0x0F;
  answer = x1 ^ x2;
  x1 = answer & 0x03;
  x2 = (answer >> 2) & 0x03;
  answer = x1 ^ x2;
  x1 = answer & 0x01;
  x2 = (answer >> 1) & 0x01;
  return x1 ^ x2;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //creates i = x plus 1 then makes x = that number plus x. then flips the bits of x and bangs i, adds them and returns. this effectively checks if the number was tmax because if it was adding 1 would result in a leading 1. you flips the bits to get 1 and add either 0 or 1 and return the opposite of that by banging x to get 1 for true or 0 for flase
  int i = x+1; 
  x = x+i;
  x = ~x;
  i= !i;
  x = x+i;
  return !x;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  //creates a mask of tmax and another which is all the leading bit of x so either all 0s for positive or all 1s for negative.  returns either x and the tmax mask banged twice to return either 1 or 0 depending on if the number was 0 or some psotive value, or returns mask2 which would be -1 for a negative number or 0 for a positive or 0
  int mask = ~(1 << 31);
  int posOrOther = !!(x & mask);
  int mask2 = x >> 31;
  return (posOrOther | mask2);
}
/*
 * minOfThree - Returns the minimum of three integers.
 * NOTE: x, y, z are all in the range [0, TMax].
 *
 * Examples: minOfThree(1, 2, 3) = 1
 *           minOfThree(4, 4, 4) = 4
 *
 * Legal Ops: ! ~ & ^ | + << >>
 * Max Ops: 20
 * Rating: 3
 */
int minOfThree(int x, int y, int z) {
  //creates a multiplexor that checks if x or y is smaller by subtracting, adding y's 2s complement, from x. uses this to create a mask by shifting 31 bits to the right to get a mask of all 1s or 0s. if the mask is all 1s the answer was negative meaning y was larger. if it is all 0s for positive y was smaller. use this mask in the multiplexor to choose x and the mask or y and not the mask. repeat the same steps to create a multiplexor to choose between the answer of that and what is smaller between that and z
  int xOrY = x +(~y+1);
  int orZ;
  xOrY = xOrY  >> 31;
  xOrY = (x & xOrY) | (y & ~xOrY);
  orZ = xOrY + (~z+1);
  orZ = orZ >> 31;
  return (z & ~orZ) | (xOrY & orZ); 
}
/*
 * ezSevenEighths - multiplies by 7/8 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*7/8),
 *   including overflow behavior.
 *   Examples: ezSevenEighths(11) = 9
 *             ezSevenEighths(-9) = -7
 *             ezSevenEighths(1000000000) = -198741824 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezSevenEighths(int x) {
  //saves ops by creating threex then six x through addition then adding one more x to create 7 times x through addition. shifts that over by 31 to get a mask of all 1s for a negative value and all 0s for a positive value to determine how to do bit shift division. for positives, simply shifts by 3 to create division of 2 to the power 3 which equals 8 and ands with not the mask to create a mask of all 1s. for negatives it adds 7 to account for the 3 bits that fall off which make the number lose positive weight then shifts by three to simulate divide by 8 and ands with the mask which will be all 1s in the case that the number is negative
  int threeX = x+x+x;
  int sixX = threeX+threeX;
  int sevenX = sixX+x;
  int mask = (sevenX >>31);
  return  (((sevenX + 7)  >> 3) & mask) | ((sevenX >> 3)  & (~mask));
}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
  //shifts the value right by 31 to create mask of all 1s or 0s. creates multiplexor to return x if the number is positive by anding with not mask which will be all 0s if the number is positive. noting it makes it all 1s so it returns x. we return x in this instance because positive tc is the same in sm. for negatives it subtracts 1 by adding 1s 2scomplement then flips the bits and puts a 1 in the sign bit position by oring with 1 shifted left by 31. ands with mask which would be all 1s for a negative
  int mask = x >> 31;
  return (x & ~mask) | ((~(x+((~1)+1))|(1<<31))& mask);
}
/*
 * binarylog - return floor(binary log of x), where x > 0
 *   Example: binarylog(16) = 4
 *   Example: binarylog(7) = 2;
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int binarylog(int x) {
  //the log is equal to the bit position of the most significant bit. this is found by keeping count of how many bits have been shifted out till x = 0; repeatedly shift then add the count with x banged twice to return 0 if x is 0 and 1 if there are still bits left
  int bitPosition = 0;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
  x = x >> 1;
  bitPosition = bitPosition + !!x;
 return bitPosition;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  //returns uf and tmax in order to drop the sign bit to effectively just make the number positive
  return uf & ~(1<<31);
}
/* 
 * float_isNormalized - Return 1 if the floating point number is normalized, otherwise 0
 *   floating point argument f.
 *   argument is to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 8
 *   Rating: 2
 */
int float_isNormalized(unsigned uf) {
  //creates a mask of all 1s for the 8 bits designated for the exponent part. ands uf and the mask to create a number that is only the exponent part. uses if statement to check if this equals either all 1s for the exponent which would be infitniy or if it equals 0 which would be denormalized. this returns 0 anything else returns 1
  int mask = 0x7F800000;
  uf = uf & mask;
  if(uf == 0x7F800000 || uf == 0){
    return 0;
  }
   else{
    return 1;
  }
}
/* 
 * float_triple - Return bit-level equivalent of expression 3*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 50
 *   Rating: 4
 */
unsigned float_triple(unsigned uf) {
  /*  int checkNoarmalized = 0x7F800000;
  if((uf & checkNormalized) == 0x7F800000){
    return uf;
  }
  else if((uf & checkNormalized) == 0){
    */
  return 2;
}
