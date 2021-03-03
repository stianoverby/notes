# MEMORY MANAGEMENT

Technology does not provite a private, infinitely large, infinitely fast memory that is also nonvolatile ( does not loose its contents when the power is switched off )

Alternative:
- Memory hierarchy of different kind of memory that posseses various grades of these attributes.
	- The OS abstracts this hierarchy into a useful model and then manage the abstraction.

- Memory manager
	- Manages part of the memory hierarchy. Keep track of which parts of memory are in use, allocate memory to processes when they need it, and deallocate it when they are done.

The perspective on memory is that of the programer´s model of main memory and how it can be managed well, and not on managing the lowest level of cache memory which is normally done by the hardware. 


## Different kind of alternatives of interacting with memory 

## 3.1 NO MEMORY ABSTRACTION
- The simplest memory abstraction is no abstraction is no abstraction at all. 
- Every program interacted directly with physical memory.
- A set of addresses from 0 to some maximum, each address corresponding to a cell containing some number of bits, commonly eight.
- Not possible to run two programs at the same time. 
	- the programs could over-write something that the other program had saved for later.

Three variations: 
1. The OS at the bottom of RAM, with user programs beeing in the top of RAM.
	- Formerly used in mainframes and minicomputers.

2. The OS in ROM (Read Only Memory) at the top of memory.
	- Handheld computers and embedded systems (remember that this book is old)

3. Device drivers at the top of memory in a ROM, and the rest of the system in RAM down below.
	- Used by early personal computers (e.g., runnin MS-DOS), where the partion of the system in the ROM is called BIOS (Basic Input Output System).

For advantages and disadvatages of these variations do read the book.

Parallelism in a system with no memory abstraction can some-what be achieved with threads. Furthermore, any system that is so primitive as to provide no memory abstraction is unlikely to provede a threads abstraction.

### Running Multiple Programs Without a Memory Abstraction 
- It is possible to run multiple programs at the same time even without memory abstractions. They can however only be run concurrently with special hardware..

Swapping
- Save the entire contents of memory to a disk file, then bring in the next program. 	

## 3.2 A MEMORY ABSTRACTION: ADDRESS SPACES 

### 3.2.1 The Notion of an Address Space

### Base and Limit Registers 


### 3.2.2 Swapping

### 3.2.3 Managing Free Memory 

### Memory Managemenet with Bitmaps 

### Memory Management with Linked Lists 


## 3.3 VIRITUAL MEMORY 
