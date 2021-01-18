# PROCESSES IN LINUX

## Fundamental Concepts 
* Processes
	* Runs single program and single thread of control. E.i., one program counter. Linux allows creation of additional threads once a process starts executing.
	* Fork system call 
		* Created an exact copy of the process. The forking process is called the parent process. The new process is called the child process. 
		* The parent and child each have their own, private memory images. If the child/parent changes one of its variables, the changes are not visible for the counter part. 
		* Open files are shared between parent and child. E.i., if a file is open to the parent before forking, it will be open for both the child and parent after. 
		* Everything is identical in the parents and child, how does the process know which one should run the parent code and which one should run the child code?
			* Fork system call returns a 0 to the child and a nonzero value (the child´s PID, to the parent

	* PID (Process identifier)
		* Names the process 
		* system call, getpid, provides the PID
		* When a child terminates, the parent is given the PID of the child that just finished. This can be important because a parent may have many children.  
		
* Daemons
	* Background processes
	* Started by shell script when the system is booted 
	* Typical one is _cron daemon_
		* Wakes up once every minute
		* Used for calendars, scheduled events


* Inter-process communication 
	* pipes
		* A channel between to processes where one of the processes can write a stream of bytes for the other to read.
		* Synchronization is possible because when a process tries to read from an empty pipe it is blocked until data are available.
		* e.g., Shell pipelines are implementetd with pipes. When the shell sees a line like _sort <f | head_ it creates two processes, sort and head, and sets up a pipe between them in such a way that sorts´s standard output is connected to head´s standard input. All the data that _sort_ writes go directly to _head_, instead of going to a file.
			* If the pipe fills, the system stops running _sort_ until _head_ has removed some data from it
	* Software interupts 
		* signal, a process can send a one to another process. A process can tell the system what they want to happen when a signal arrives. 
			1. Ignore it. 
			2. Catch it.
				* If a process chooses to catch signals sent to it, it must specify a signal-handling procedure.
				* When signal arrives, control will abruptly switch to the handler. When the handler is finished and returns, control goes back to where it came from, analogus to hardware I/O interrupts.  	
			3. Let the signal kill the process (the default for most processes).
			
			* process group, a process can only send signals to members of its process group, which consists of its parent (and further ancestors), siblings and children (and further descendants). A process may also send a signal to all members of its process group with a single system call

## Process Managment System Calls in Linux
* Zomibie state  

## Implementation of Processes and Threads in Linux
* Scheduling parameters, memory image, signals, machine registers, system call state, file dsriptor table, accounting, kernel stack, miscellaneous, copy on write

## Threads in Linux
	 

## Scheduling in Linux 
* Jiffy, runqueue, waitqueue, big kernal lock (BLK)

## Booting Linux 
* MBR (Master Boot Record), GRUB (GRand Unified Bootloader)
