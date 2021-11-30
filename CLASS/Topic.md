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

    