The process of compiling 


	Compilation is the process of translating the code you write into a language that is native to the machine you are targeting. 

	When compiling C we use a compiler like GCC (the GNU Compiler collection) or Clang. 

	The compilation process
		---programmer writes--->	 					Higher level language, scource code(.c)  
		---preprocessing---> 	/*resolves macros and removes comments	*/	Pre-processed File(.i)   
		---compiling---> 	/*translation to assembler		*/	Assembely scource (.s)
		---assemble--->		/*translation to machine code		*/	object file, binary (.o, .obj) 
		---linking---> 		/*Combining object files and library files*/	executable (.out, .exe)


	Do parts of the compilation to see how the files look 
		
		Preprocessing
			gcc -E test.c ---> test.i

		Compile to assembly 
			gcc -S test.c ---> test.s
		
		Compile and assemble to object file 
			gcc -c test.c ---> test.o


	Makefiles 
		You should not be doing the compilation manually in the terminal. You should be automating the build with some kind of build-tool like the program make.
		
		What to name your makefile 
			Makefile, makefile, GNUmakefile. The first one is recommended.

		Rules
			Rules normally contains targets, prerequisites and then a recepie what to do.

			Abstract example
			targets : prerequisites 
				recepie
			
			Example 
			foo.o : foo.c defs.h
				gcc -c -g foo.c


			Comments on example 
				This rules says two things:
					1. How to decide wether foo.o is out of date:
						It is out of date if it does not exist, or if either foo.c or defs.h is more recent than it.

					2. How to update the file foo.o:
						By running gcc as stated. 
						(The recipe does not explicity mention defs.h, but we presume that foo.c includes it, and that is why defs.h was added to the prerequisites.)	 

		Compiling several .c files	
			If we want to create a c-program containing several .c files, we deliberately make them all into object files before linking them together.
			If we would do the whole compilation process with all the files combined every time, we would have to create all files into object files again if we 
			make a change in one single .c file. Then we would waste time and rescources on compiling things that does not need to be re-compiled.	
