;
; The code given to you here implements the histogram calculation that 
; we developed in class.  In programming lab, we will add code that
; prints a number in hexadecimal to the monitor.
;
; Your assignment for this program is to combine these two pieces of 
; code to print the histogram to the monitor.
;
; If you finish your program, 
;    ** commit a working version to your repository  **
;    ** (and make a note of the repository version)! **


	.ORIG	x3000		; starting address is x3000


;
; Count the occurrences of each letter (A to Z) in an ASCII string 
; terminated by a NUL character.  Lower case and upper case should 
; be counted together, and a count also kept of all non-alphabetic 
; characters (not counting the terminal NUL).
;
; The string starts at x4000.
;
; The resulting histogram (which will NOT be initialized in advance) 
; should be stored starting at x3F00, with the non-alphabetic count 
; at x3F00, and the count for each letter in x3F01 (A) through x3F1A (Z).
;
; table of register use in this part of the code
;    R0 holds a pointer to the histogram (x3F00)
;    R1 holds a pointer to the current position in the string
;       and as the loop count during histogram initialization
;    R2 holds the current character being counted
;       and is also used to point to the histogram entry
;    R3 holds the additive inverse of ASCII '@' (xFFC0)
;    R4 holds the difference between ASCII '@' and 'Z' (xFFE6)
;    R5 holds the difference between ASCII '@' and '`' (xFFE0)
;    R6 is used as a temporary register
;

	LD R0,HIST_ADDR      	; point R0 to the start of the histogram
	
	; fill the histogram with zeroes 
	AND R6,R6,#0		; put a zero into R6
	LD R1,NUM_BINS		; initialize loop count to 27
	ADD R2,R0,#0		; copy start of histogram into R2

	; loop to fill histogram starts here
HFLOOP	STR R6,R2,#0		; write a zero into histogram
	ADD R2,R2,#1		; point to next histogram entry
	ADD R1,R1,#-1		; decrement loop count
	BRp HFLOOP		; continue until loop count reaches zero

	; initialize R1, R3, R4, and R5 from memory
	LD R3,NEG_AT		; set R3 to additive inverse of ASCII '@'
	LD R4,AT_MIN_Z		; set R4 to difference between ASCII '@' and 'Z'
	LD R5,AT_MIN_BQ		; set R5 to difference between ASCII '@' and '`'
	LD R1,STR_START		; point R1 to start of string

	; the counting loop starts here
COUNTLOOP
	LDR R2,R1,#0		; read the next character from the string
	BRz PRINT_HIST		; found the end of the string

	ADD R2,R2,R3		; subtract '@' from the character
	BRp AT_LEAST_A		; branch if > '@', i.e., >= 'A'
NON_ALPHA
	LDR R6,R0,#0		; load the non-alpha count
	ADD R6,R6,#1		; add one to it
	STR R6,R0,#0		; store the new non-alpha count
	BRnzp GET_NEXT		; branch to end of conditional structure
AT_LEAST_A
	ADD R6,R2,R4		; compare with 'Z'
	BRp MORE_THAN_Z         ; branch if > 'Z'

; note that we no longer need the current character
; so we can reuse R2 for the pointer to the correct
; histogram entry for incrementing
ALPHA	ADD R2,R2,R0		; point to correct histogram entry
	LDR R6,R2,#0		; load the count
	ADD R6,R6,#1		; add one to it
	STR R6,R2,#0		; store the new count
	BRnzp GET_NEXT		; branch to end of conditional structure

; subtracting as below yields the original character minus '`'
MORE_THAN_Z
	ADD R2,R2,R5		; subtract '`' - '@' from the character
	BRnz NON_ALPHA		; if <= '`', i.e., < 'a', go increment non-alpha
	ADD R6,R2,R4		; compare with 'z'
	BRnz ALPHA		; if <= 'z', go increment alpha count
	BRnzp NON_ALPHA		; otherwise, go increment non-alpha

GET_NEXT
	ADD R1,R1,#1		; point to next character in string
	BRnzp COUNTLOOP		; go to start of counting loop



PRINT_HIST

; you will need to insert your code to print the histogram here

; do not forget to write a brief description of the approach/algorithm
; for your implementation, list registers used in this part of the code,
; and provide sufficient comments
;I packed the code to print an individual number into a subrountine
;then I looped through the histogram and printed each 1 out individually
;I used R1 to make sure I only looped through 27 and as the digit counter
;I used R2 to contain the adress of the histogram
;I used R0 to out put the character using out
;R7 was used to keep track of the PC
;R2 was the bit counter too
;R3 was conatined the number to print
;R4 gets only four digits to print
;R5 gets offest
;R6 throw away variable


LD R1,NUM_BINS; contains length 27
LD R2, HIST_ADDR; starting adress of histogram
LD R0,CHARACTER; prints characters from @-Z
LENGTH_LOOP LDR R3,R2,#0;loads number to print
OUT
JSR HISTOGRAM; subrountine to print histogram
ADD R0,R0,#1;increments character
ADD R2,R2,#1;increments histogram adress
ADD R1,R1,#-1;decrements length;
BRp LENGTH_LOOP



DONE	HALT			; done

HISTOGRAM ST R0,STORE_0;Stores the registers to be recalled later
ST R1,STORE_1;
ST R2,STORE_2;
ST R3,STORE_3;
ST R4,STORE_4;
ST R5,STORE_5;
ST R6,STORE_6;
ST R7,STORE_PC;
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
BRzp SKIP_ADD; Skips the addition if the mSB is 0
ADD R4,R4,#1;Adds 1 if MSB is 1
SKIP_ADD ADD R3,R3,R3; left shifts r3
ADD R2,R2,#1; increments bit counter
BRnzp BIT_LOOP; loops back to bit_loop
DIGIT_LOOP ADD R6,R4,#-9 ;checks if in 0-9 or not
BRp LETTER; skips if not
LD R5,NUM48; load offset 48 if 0-9
ADD R0,R4,R5;
BRnzp PRINT
LETTER LD R5,NUM55; load offset 55 if A-F  
ADD R0,R4,R5;
PRINT OUT;prints digit out
ADD R1,R1,#1;
BRnzp OUTMOST_LOOP; goes to outermost loop
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


; the data needed by the program
NUM_BINS	.FILL #27	; 27 loop iterations
NEG_AT		.FILL xFFC0	; the additive inverse of ASCII '@'
AT_MIN_Z	.FILL xFFE6	; the difference between ASCII '@' and 'Z'
AT_MIN_BQ	.FILL xFFE0	; the difference between ASCII '@' and '`'
HIST_ADDR	.FILL x3F00     ; histogram starting address
STR_START	.FILL x4000	; string starting address
CHARACTER       .FILL #64       ;Starts the character at '@'

;data needed by subroutine
NUM48 .FILL #48 ;Gives the offset if 0-9 to print the character
NUM55 .FILL #55 ;Gives the offset if A-F to print the character
LOWER_X .FILL #32; Gives the space character
STORE_0 .BLKW #1; Stores register R0-R7
STORE_1 .BLKW #1
STORE_2 .BLKW #1
STORE_3 .BLKW #1
STORE_4 .BLKW #1
STORE_5 .BLKW #1
STORE_6 .BLKW #1
STORE_PC .BLKW #1

; for testing, you can use the lines below to include the string in this
; program...
; STR_START	.FILL STRING	; string starting address
; STRING		.STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."



	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END