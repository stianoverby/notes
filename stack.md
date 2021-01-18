Stack: A continuous array of memory locations 

	- Current stack is referenced by the SS register 
	- ESP register - stack pointer 
	- EBP register - Stack frame base pointer (fixed reference) 
	- PUSH - stack grows, add item (ESP decrement) 
	- POP - remove item, stack shrinks (ESP increment) 


C function Calls & Stack 
	
	The call stack/ execution stack/ machine stack/ stack

	Be aware that several calling conventions exsists 
		cdecl (unix/ms) - caller cleanup 
		stdcall (ms) - callee cleanup 
		fastcall (ms) - callee cleanup 
		vectorcall (ms) - caller cleanup 
		Sys V AMD64 ABI (linux, bsd)- caller cleanup 

	CPU registers 
		Intel arcitechture 32-bits all registers are prefixed with the letter E ( stands for extended). 
			- ESP register, stack pointer stores the address of the top of the stack. 
			- EBP register, base pointer stores the address of the stack base (other name: EFP/frame pointer).
			- EIP register, instruction pinter that controls the flow of the program. 
			- EAX register, data register used for logical, arithmetical and other operations. Used to save value from function call.  

	Heap vs stack 
		 - Stack memory allotion is much faster than heap, but not as capacious. 

	High addresses
		----------------------------
		|                          |
		|                          |
		----------------------------
		|       Stack              |	- Local variables and program arguments 
		|                          |	- Grows down 
		----------------------------    - Every function call adds a chunk of memory to the stack. Arguments expected, return address, local variables etc. 
		|                          |	- Stack frame, represent a single function call  
		|                          |
		|                          |
		|                          |
		|                          |
		|                          |
		----------------------------
		|        Heap              |   - Grows upward 
		|                          |   - It is here we allocate memory manualy 
		----------------------------
		----------------------------
		|       Globals            |
		|                          |
		----------------------------
		----------------------------
		|        Code              |
		|                          |
		----------------------------
		|                          |
		|                          |
		----------------------------
	Low addresses 

	Example program 
		
		int add(int a, int b) 
		{
			return a + b;
		}

		main (void) 
		{
			int c = 0;
			c = add(4, 2);
		}

	A calling function (main) does 
		- push the parameteres into stack in reverse order 
		- push return address (current EIP value) onto stack 

	When called, a C function (add) does 
		- Push frame pointer (EBP) into stack, saves frame pointer register and gives easy return if necessary 
		- let frame pointer point at the stack top. i.e, point at the saved stack pointer (EBP = ESP) 
		- Shift stack pointer (ESP) upward (to lower addresses) to allocate space for local variables 
		

	When return, a C function (add) does 
		- Put return value in the return value register (EAX) 
		- Copy frame pointer into stack pointer 
			Stac top now contains the saved frame pointer 
		- pop stack into frame pointer (restore), leaving the reurn program pointer on top of the stack 
		- the RET instruction pops the stack top into the program counter register (EIP), causing the CPU to execute from the "return address" saved earlier 

	When returner to calling function, (main) does 
		- copy the reurn value (EAX) into right place 
		- pop perameteres - restore stack  
