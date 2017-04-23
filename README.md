## A small toy language compiler

We are implementing a small toy language for learning purposes in
C++ 11. 

The goal is to go in small steps, starting with a very small set of 
language features and growing bigger over time. 

The language shall be compiled to native assembly code for Intel 64Bit
machines. 

### Building and running
Download the source code:
```
git clone https://github.com/mateun/toylang2

```
Go into the source directory and create a build subdir:
```
cd toylang2
mkdir build
cd build
```
When you are in the "build" dir, just invoke cmake:
```
cmake ..
```
You will then have a binary called "tc" in your build dir, which you can invoke like this: 
```
./tc < mysourcefile.txt
```

Please note, that mysourcefile.txt is just a file which 
contains your sourcecode you want to send to the compiler. 

### Release notes

#### version 0.0.1 
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
  

#### version 0.0.2: 
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



