; mp2.asm
; Implement a stack calculator that can do the following operations:
; ADD, SUBTRACT, MULTIPLY, DIVIDE

; Inputs:
;   Console - postfix expression

; Outputs:
;   Console - [0 - F]{4}, evaluation of postfix expression
;   Register R5 - [0 - F]{4}, evaluation of postfix expression


;For my approach I built the operators add, divide, subtract and multiplicationg
;Then I nested them inside the evaluate subroutine which I based of the flow chart
;For the divide and multiplication rountine I used repeated subtraction and repeated addition respectively
;I used R0 to user input and output as well as pushing and popping from the stack as well as the output for other subrountines
;I used R1 to test the value in R0
;I used R2 to hold the value in R0 when it was temporarily being used for something else
; I used R3,R4 for input to the operator subrountines
;R6 was used as a throwaway register
;R7 was used to return control to the user program
;Partners: kalpitf2, marca4

.ORIG x3000
	
MAIN

AND R0,R0,#0 ;intialize register
AND R1,R1,#0
AND R2,R2,#0
AND R3,R3,#0
AND R4,R4,#0
AND R5,R5,#0
AND R6,R6,#0
AND R7,R7,#0


JSR EVALUATE ;CAlls the evalutate funciton inside the MAIN ROUNTINE

DONE
    HALT


; PRINT_HEX
;   Description: prints out the value in R3 to the console
;   Inputs: R3 - value in register to be printed out
;   Outputs: Value printed to the console

PRINT_HEX ST R0,STORE_0 ;Stores the registers to be recalled later
ST R1,STORE_1 ;
ST R2,STORE_2 ;
ST R3,STORE_3 ;
ST R4,STORE_4 ;
ST R5,STORE_5 ;
ST R6,STORE_6 ;
ST R7,STORE_PC ;
LD R0,LOWER_X
OUT;Prints out a space
AND R1,R1,#0;initialize digit count
OUTMOST_LOOP ADD R6,R1,#-4;Checkes to see if 4 digits have been printed out
BRzp STOP
AND R4,R4,#0; inititlizing digit to be printed
AND R2,R2,#0; initilizes bit counter
BIT_LOOP ADD R6,R2,#-4
BRzp DIGIT_LOOP
ADD R4,R4,R4; left shifts r4
ADD R3,R3,#0; checks condition codes on R3
BRzp SKIP_ADD ; Skips the addition if the mSB is 0
ADD R4,R4,#1;Adds 1 if MSB is 1
SKIP_ADD ADD R3,R3,R3; left shifts r3
ADD R2,R2,#1; increments bit counter
BRnzp BIT_LOOP ; loops back to bit_loop
DIGIT_LOOP ADD R6,R4,#-9 ;checks if in 0-9 or not
BRp LETTER ; skips if not
LD R5,NUM48 ; load offset 48 if 0-9
ADD R0,R4,R5;
BRnzp PRINT
LETTER LD R5,NUM55 ; load offset 55 if A-F  
ADD R0,R4,R5;
PRINT OUT;prints digit out
ADD R1,R1,#1;
BRnzp OUTMOST_LOOP ; goes to outermost loop
STOP AND R0,R0,#0;prints new line
ADD R0,R0,#10
OUT
LD R0,STORE_0
LD R1,STORE_1
LD R2,STORE_2
LD R3,STORE_3
LD R4,STORE_4
LD R5,STORE_5
LD R6,STORE_6
LD R7,STORE_PC
RET


; EVALUATE
;   Description: handles input from console
;   Inputs: Console - input
;   Outputs: Console - evaluation of expression or error
;	     R5 - evalution of expression  
EVALUATE

ST R7,STORE_PC_EVALUATE

INPUT_KEYBOARD GETC ;Gets the character from the input buffer
OUT ;Prints out the character the user tpyed in to the screen
LD R1,NEG_EQUAL ;Loads the value of the negative equal sign

ADD R1,R1,R0 ;tests if equal sign

BRz IS_EQUAL ;evaluate epxreesion as whole when = is found

LD R1,NEG_SPACE ;loads the negative space value

ADD R1,R1,R0 ; tests if space
BRz INPUT_KEYBOARD ;Jumps back to get another character if a space is found

;tests if invalid character
LD R1, LOWER_RANGE_INVALID ;tests if less than (
ADD R1,R0,R1
BRn PRINT_INVALID

LD R1, UPPER_RANGE_INVALID ;tests if greater than 9
ADD R1,R0,R1
BRp PRINT_INVALID

LD R1,INVALID_NUM1 ; tests if character is ,
ADD R1,R1, R0
BRz PRINT_INVALID

LD R1,INVALID_NUM2 ; test if character is /
ADD R1,R1,R0
BRz PRINT_INVALID

LD R1, NUM_0 ;CHECKS if more than zero or =
ADD R1,R1,R0
BRzp OPERAND

ADD R2,R0,#0 ;Saves operand value to check

JSR POP
ADD R5,R5,#0 ;checks if popped once sucessfully
BRp PRINT_INVALID
ADD R4,R0,#0

JSR POP
ADD R5,R5,#0 ;checks if popped twice sucessfully
BRp PRINT_INVALID
ADD R3,R0,#0

;CHecks which operator

LD R1, PLUS_SIGN ;checks if +
ADD R1,R1,R2
BRz PLUS_OPERATOR

LD R1,SUBTRACT_SIGN ;checks if -
ADD R1,R1,R2
BRz SUBTRACT_OPERATOR

LD R1, MULTIPLY_SIGN ; checks if *
ADD R1,R1,R2
BRz MULTIPLY_OPERATOR

LD R1, DIVIDE_SIGN ;checks if /
ADD R1,R1,R2
BRz DIVISION_OPERATOR

;pushs the result onto the stack and gets next character
PLUS_OPERATOR JSR PLUS ;adds if plus sign
JSR PUSH
BRnzp INPUT_KEYBOARD

SUBTRACT_OPERATOR JSR MIN ;subtracts if minus sign
JSR PUSH
BRnzp INPUT_KEYBOARD

MULTIPLY_OPERATOR JSR MUL ;multiplies if multiplicationg sign
JSR PUSH
BRnzp INPUT_KEYBOARD

DIVISION_OPERATOR JSR DIV ;dividies if division sign
JSR PUSH
BRnzp INPUT_KEYBOARD

;pushes the charactr onto the stack if it is an operand

OPERAND LD R1, NEG_ZERO
ADD R0,R0,R1 ;COnverts the ASCII to digit
JSR PUSH
BRnzp INPUT_KEYBOARD





IS_EQUAL 

JSR POP ;checks to see if stack can be popped only once sucessfully

ADD R5,R5,#0
BRnp PRINT_INVALID ; prints invalid if it cannot be popped

JSR POP

ADD R5,R5,#0 ;checks to see that the stack cannot be popped >1
BRz PRINT_INVALID ;prints invalid if it cannot be popped 

ADD R5,R0,#0 ;places popped value into R5
ADD R3,R5,#0 ;prints the value in R5 as a hex

JSR PRINT_HEX ; prints the hexedecimal if applicable
LD R7,STORE_PC_EVALUATE ; returns control to the user program
RET

PRINT_INVALID LEA R0, INVALID_STRING
PUTS
LD R7,STORE_PC_EVALUATE ;prints invalid string and returns
RET








; PLUS
;   Description: adds two numbers (R0 = R3 + R4)
;   Inputs: R3 - addend
;	    R4 - addend
;   Outputs: R0 - sum
PLUS	

ADD R0,R3,R4 ;adds two numbers and returns

RET
	
; MIN
;   Description: subtracts two numbers (R0 = R3 - R4)
;   Inputs: R3 - minuend
;	    R4 - subtrahend
;   Outputs: R0 - difference
MIN	

NOT R4,R4
ADD R4,R4,#1
ADD R0,R3,R4 ; subtracts two numbers and reutrns the diferenc

RET

	
; MUL
;   Description: multiplies two numbers (R0 = R3 * R4)
;   Inputs: R3 - factor
;	    R4 - factor
;   Outputs: R0 - product
MUL	
	
AND R0,R0,#0 ;Initilizes the future output t0 0
ADD R3,R3,#0 
ADD_LOOP BRnz RETURN_MUL ;uses repeated addition to multiply
ADD R0,R0,R4
ADD R3,R3,#-1
BRnzp ADD_LOOP 

RETURN_MUL RET

; DIV
;   Description: divides two numbers (R0 = R3 / R4)
;   Inputs: R3 - numerator
;	    R4 - denominator
;   Outputs: R0 - quotient
DIV	

AND R0,R0,#0 ;intiilizes output
NOT R4,R4
ADD R4,R4,#1
ADD R3,R3,R4
SUBTRACTION_LOOP BRn RETURN_DIV ;uses repeated subtraction to divide
ADD R0,R0,#1
ADD R3,R3,R4
BRnzp SUBTRACTION_LOOP 

RETURN_DIV RET	
	
; PUSH
;   Description: Pushes a charcter unto the stack
;   Inputs: R0 - character to push unto the stack
;   Outputs: R5 - 0 (success) or 1 (failure/overflow)
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACK_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


; POP
;   Description: Pops a character off the stack
;   Inputs: 
;   Outputs: R0 - character popped off the stack
;	     R5 - 0 (success) or 1 (failure/underflow)
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP

POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET

POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;

NUM48 .FILL #48 ;Gives the offset if 0-9 to print the character
NUM55 .FILL #55 ;Gives the offset if A-F to print the character
LOWER_X .FILL #120; Gives the space character
STORE_0 .BLKW #1; Stores register R0-R7
STORE_1 .BLKW #1
STORE_2 .BLKW #1
STORE_3 .BLKW #1
STORE_4 .BLKW #1
STORE_5 .BLKW #1
STORE_6 .BLKW #1
STORE_PC .BLKW #1
NEG_EQUAL .FILL #-61 ;stores the negative value for '='
NEG_SPACE .FILL #-32 ;sotres the negative value for ' '
INVALID_STRING .STRINGZ "\nInvalid Expression" ;prints the invalid expression
LOWER_RANGE_INVALID .FILL #-42 ;checks to see if below valid range
UPPER_RANGE_INVALID .FILL #-57 ;checks to see if above valid range
INVALID_NUM1 .FILL #-44 ;checks if ,
INVALID_NUM2 .FILL #-46 ;checks if .
NUM_0 .FILL #-48 ;Redundant
MULTIPLY_SIGN .FILL #-42 ;neg ascii of multipilication
DIVIDE_SIGN .FILL #-47 ;neg ascii of division
PLUS_SIGN .FILL #-43 ;neg ascii of plus sign
SUBTRACT_SIGN .FILL #-45 ;negative ascii of '-'
NEG_ZERO .FILL #-48 ;negative ascii of '0'
STORE_PC_EVALUATE .BLKW #1 ;stores pc so the evaluate subrountine can return back to the user program 

.END
