## A small toy language compiler

We are implementing a small toy language for learning purposes in
C++ 11. 

The goal is to go in small steps, starting with a very small set of 
language features and growing bigger over time. 

The language shall be compiled to native assembly code for Intel 64Bit
machines. 

Release notes:

### version 0.0.1 
  * lexer which recognises arithmetic expressions 
    * add, mulitply, divide, subtract
  * lexer recognises variable assignment
    * e.g. ```x=12```, ```foobar=89```
	* programs generally look like this:

   ```C++
	x = 12
	y = 88
	z = x + y / 9
  ```   

### version 0.0.2: 
  * lexer recognises function declaration and function implementation, e.g. ```fn doThis(a, b)```
	* lexer recognises control flow statements, e.g. if-then-else
	* programs generally look like this: 
  ```javascript
	def sum(a, b)

	x = sum(12, 99)
	z = 0
	y = 0

	if (x < 120) then
		z = -1
	else
		z = 9999
	endif	
  ```



