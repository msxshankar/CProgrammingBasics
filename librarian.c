#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "librarian.h"
#include "utility.h"

////
// Code module for librarian
// They can list the books and see what is borrowed


// List the borrowed books on the screen
// Format should be "author - title" on each line

void listBorrowedBooks( Book *bookList, int numBooks ) {

  // TO DO :
  //
  // list the books in format "name - title"
  
  return;
}


// List the books on the screen
// Format should be "author - title" on each line

void listBooks( Book *bookList, int numBooks ) {

  // TO DO :
  //
  // list the books in format "name - title"
  for (int i = 0; i < 7; i++) {
  	//printf("%s - %s", (bookList+i)->author, (bookList+i)->title);
	//for (int j = 0; j < sizeof(bookList->author)
  	printf("\n%s", bookList->author);
        //fflush(stdout);
  	printf("-%s", "happy\0");
  } 
  return;
}


// DO NOT ALTER THIS CODE

// Menu system for the librarian

void librarianCLI( Library *theLibrary ) {
    int librarianLoggedIn = 1;
    int option;

    while( librarianLoggedIn ){
        printf("\n Librarian options\n 1 List books\n 2 List borrowed books\n 3 Log out\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nList of books:\n");
            listBooks( theLibrary->bookList, theLibrary->numBooks );
        }
        else if( option == 2 ) {
            printf("\nList of borrowed books:\n");
            listBorrowedBooks( theLibrary->bookList, theLibrary->numBooks );
        }
        else if( option == 3 ) {
            librarianLoggedIn = 0;
            printf("\nLogging out\n");
        }
        else
            printf("\nUnknown option\n");
    }
    return;
}

