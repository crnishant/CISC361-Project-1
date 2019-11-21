# CISC361-Project-1
MP3 List in C
Objective
The primary objective of this assignment is to practice/review C coding, including the use of C structs and pointers for later use in the programming assignments.

Details
Write a C program that will allow the user to enter MP3 data into a doubly linked list, remove MP3 entries and view the contents of the list. Your program will be graded based on its correctness, code structure and documentation.

You should have a .h file that declares function prototypes, structs, etc. Your .c file(s) should #include only .h files and contain all the actual C code. You need to make a C struct to hold information of an MP3. In this struct you should have:

The name of the artist stored in a char*
The title of the song stored in a char*
The year that the song is from stored in a method of your choice
The run time in seconds stored as an int
A "next" pointer to another one of these structs (so you can make a linked list)
A "prev" pointer to another one of these structs (so you can make it a doubly linked list)
 

Once you have your struct, write a program to use it that will prompt the user to (1) add an MP3 to the list, (2) delete MP3(s) from the list, (3) print the list from beginning to end, (4) print the list from end to beginning, and (5) exit the program. When adding an MP3, your program prompts for each piece of information, and adds the MP3 to the end/tail of the list. When deleting, your program prompts for the name of the artist and deletes all the entries with that artist. When printing, start at one end of the list, traverse and print each MP3 until reaching the other end. When exiting the program, free all dynamically allocated memory to leave no memory leak. You may use fgets() to input character strings (for artist name and song title).  Read the man page of fgets() for details.

Your input and output should make sense to the user.

Remember to always allocate memory for all your pointers to point at valid memory with malloc() or calloc(). Avoid trying to dereference NULL pointers which will result in segmentation faults unless you happen to get lucky! Also, check out C tutorial on call-by-value and call-by-reference (Links to an external site.).
