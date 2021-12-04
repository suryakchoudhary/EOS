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

- OS like Linux divides the RAM in tow parts:
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

    - Fork: Ti is a traditional and most prominent API to create new child process.

        - Whem parent finishes its process first: Child is inherited by systemd process.

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


