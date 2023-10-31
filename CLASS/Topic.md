# EMBEDDED OPERATING SYSTEM

- Embedded system vs general purpose system

- Two and three layered enbedded system

- Modularize project and code

- Build

- Makefile

- Hex dump vs Execution under embedded linux

- ELF(Executable & Linkable File)
    - Stack
    - Heap
    - .bss
    - .data
    - .txt

- Parallelism
    - True Parallelism
    - Psedu Parallelism

- Uniprocessor
    
- Multiprocessor

- Process
    - Something present in RAM
    - Active entity

- Program
    - Something present in HDD
    - Dormat(inactive) entity

- In any CPU
    - Program Counter
    - Stack Pointer
    - General Purpose Register
    - Flags

- Cross Compiler

- Bare Metal Programming : When coad is loaded to hardware.

- Common in Embedded Systems
    - Bootloader
    - Kernal/OS
    - FS(File System) > App

- $: For normal user.

- #: For priviledge user

- Declaration vs Definition.

- Libraries ; Collection of object files, library is a reusable componant which has object file inside it.
    - Static lib.
    - Dymanic lib.

- Header(.h file contain declaration) vs Library.

- Fork : It is a traditional API. It creats a child process and continues the present process. "man 2 fork".

- PID : Process ID
    - getpid()

- PPID : Parent Process ID
    - getppid()

- Opeque Datatype : Actually, we don't know which datatype or returntyoe is inside it. We should only know its usage and purpose.

- OS like Linux divides the RAM in two parts:
    - User Space: When system boots up, it takes the OS(which is a program) which is in HDD or from network and load it to the kernal address space.

    - Kernal Space: It is the core part of the linux and is responsible for the major activities of OS. It consist of various module and interacts directly with underlying hardware. It has access to full resourses of thecomputer.

- Segmentation fault: If we try to make a pointer in A1 to dereference it to A2(from A1 reading the value from A2). OS will check for the address range of A1 and of the pointer range beyond that then it will show segmentation fault.

- Device Driver: It is abstraction between software consept and hardware circuitary, as such it needs too talk to both of them.

- System calls : We can access and control files and devices using a small number of functions, called system calls. It is implemented inside kernal space.

- Library calls: The functions which are a part of standard C library are known as Library functions. It is implemented inside the user space.

- Mode Bits: Read            Write               Execute

- File Descriptor: A file descriptor is an integer in user space which denotes the detail of file opened in kernal space.

    - Standard Input    | 0 | Keyboard
    - Standard Output   | 1 | Display
    - Standard Error    | 2 |

## Day- 6

- Process Management: Manage CPU effectively across multiple processes, by sudo or true parallelism.

    - Fork: It is a traditional and most prominent API to create new child process.

        - When parent finishes its process first: Child is inherited by systemd process.

            - systemd process: systemd process is one of the 1st processes to be created when linux is booted and it ic created by kernal.

        - When child finished its process first: child process is put in ZOMBIE STATE by the OS.

    - Appilcations: Two ways searching means from top as well as from bottom.

    - Web servers: Parent process for listening and child creating multiple chile processes for connection multiple clients.

- IPC (Inter Process Communication)

    - Pipes: Communication between two related processes.

    - FIFO: Communication between two unrelated processes. "mkfifo -m600 fifo_name" is the mediun of communication.

- Process State (Diagram)

    - Create

    - Ready State

    - Running State

    - Waiting State

    - Exit

## Day- 7

- Buffer: A variabe which holds a set of bytes which we want to write/read to/from file.

- Switching between pricesses without loosing previous process's data.

    - Basic register in CPU

        1. IP: Instruction Pointer

        2. SP: Stack Pointer

        3. GPR: General Purpose Register

        4. Flags

    - Context Switching

        - Context Saving: Taking physical copy of context to make a logical copy.

        - Context Restoring: Taking logical copy of context to make a physical copy.

    - Processes Demonstration

        - PID: Unique Identifier

        - Address Space

        - PCB: Logical copy is saved here.

        - Context (IP, SP, GPR, Flags)

- Terminologies

    - Batch: Collecting file of same type ang executing each of them. Only one program(compiler) can be loaded at a time.

    - Multiprogramming: Multiple programs loaded on a single storage system. Poor response time.

    - Multitasking: An extension to multiprogramming. Multiple programs loaded on a single storage system. Better resoponse time. Psudo parallelism achieved.

    - Multiprocessing: A system with multiple Processor. True parallelism is achieved.

    - Multithreading: Multiple threads inside a process. We can say that thread is a sub- division of processes.

- Thread: Sub- division of processes. Share the alloted CPU time for a process between threads.

    - POSIX: Portable OS Interfaces UNICES. POSIX lib used for thread.

- Creating threat in POSIX

    - POSIX for every datatype it will have two functions

        - set(): To set value of opeaue datatype.

        - get(): To set value of opeaue datatype.

- API: Application Programming Intreface: These are interfaces which allows us to invoke functionality in specific module. API's are defined as functions most of the time.

    - Blocking API: If we make function call to thise API's, if will be in waiting state untill its condition is satisfied or need fullfilled and will block itself.

    - Non- Blocking API: It will not wait either condition is satisfied or not, unlike blocking API's, it will respond back immediately and give its status. 

- CoW: Copy on Write: When we write any change in process data of either of parent or child then at that moment the copy of the address space is created to separate the address space of the child and parent process. This is called CoW.

## Day- 8

- Memory Leakage: When memory is dynamically allocated in the RAM but it is not freed or we loose pointer location to that memory location.

    - valgrind: A tool to check the memoty leakage(in our programs).

- EXEC API(man exec): Used to execute file in active process. When exec is called, the new program is overwritten on thr pervious program present in address space and the PID will be same.    EXEC is used when user wants to launch a new program in the same process.

- Stack Pointer: It always points to the top of the stack.

- Stack Frame: The area in stack allocated for the function, called stack frame.

    - Arguments 

    - Retufn Type

    - Local Variables

- Frame Pointer: Points only to a perticular frame, argument, local variables and everything of the function will be accessed by frame pointer.

- Recursive function should not be called too many times as it will fill the stack with stack frames & it go and hit the heap and then it will corrupt(address space) data on heap.

## Day- 9

- Synchronization: To solve the problem of race condition in accessing the shared resourses, the the resources should be shared in synchronized way by the help of mutual exclution.

- Race Condition: Race to access the the shared resource, causes reace condition.

- Mutual Exclution: A any given instance of time, their will be only onr threat/process, will be accessing the shared resource.

- Race Condition is solved by mutual exclution.

- Resource: Any entity which is used br threat/process. Eg- CPU, serial port, memory location.

- Shared Resource: If same resource is shared between multi[le threat/process.

- Critical Region/Section: The region where we are accessing the shared resource, called Critical Region/Section.

## Day- 10

- Mutex: Provides mutual exclution, which is solution to race condition.

    - Fast Mutex(futex): When their only one resource to access.

    - Recursive Mutex: Allows same thread to lock mutex multiple times before it is unlocked. It maintains the count of locks that will be released if the number of unlocks and unlocks are equal. No othre threads can unlock the mutex.

    - Error Checking Mutex: Locked exactly once like normal mutex. If a thread tries to lock the mutex again without unlocking it, thread receives an error.

    - Adaptive Mutex: Mutex in busy loop not in waiting state.

- Thumb Rule 

    - If their is shared resource, their must be mutual exclution.

    - Critical region should be as small as possible.

- Deadlock: Two threads/processes go into the situation where they both go in waiting stage, waiting for each other. Neither of the thread/process is ececuted.

- Process Management

    - Create/Destroy Threat/Process

    - Synchronization

    - Inter Process Communocation

- Semaphore: An integer variable shared among multiple thread/process. Initial value depends on number of resourcces available. (int pshate=0 -> thread   /  int pshate=1 -> Process)

- Signallin Semaphone: When the input/output of one thread/process depends on other thread/process, signalling semaphone is used.

## Day- 11

- Counting Semaphore: In many process there are limited resources, it makes sure that each process get an exclusive access to the resource & once it gets it, uses it & returs the resource so that some other process can use it.

- IPC

    - Shared Memory: An IPC mechanism. It is the memory allocated by OS in user space and is accessed by multiple processes.

    - Message Queue: An IPC mechanism. It is a linked list of messages stored within the kernal & identified by a message queue identifier.

- Barrier Synchronization: In cases where you must wait for a number of tasks to be completed before an overall task can proceed, barrier synchronization can be used. POSIX threads specifies a synchronization object called a barrier, along with barrier functions. The functions create the barrier, specifying the number of threads that are synchronizing on the barrier, and set up threads to perform tasks and wait at the barrier until all the threads reach the barrier. When the last thread arrives at the barrier, all the threads resume execution

- Variadic Functions: Variadic functions are functions that can take a variable number of arguments. In C programming, a variadic function adds flexibility to the program. It takes one fixed argument and then any number of arguments can be passed. The variadic function consists of at least one fixed variable and then an ellipsis(…) as the last parameter.

