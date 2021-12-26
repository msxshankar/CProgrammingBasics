#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

////
// Code module for main library menu and file management
// Reads the book and initialises the problem data

// Initialise library data
// Input: 
// bookfile - name of book file
// theLibrary - library data structure

void initLibrary( char *bookFile, Library *theLibrary ) {

  theLibrary->maxBooks = 12;
  theLibrary->maxBorrowed = 4;

  // TO DO :
  
  // dynamically allocate the bookList array for storing books
  theLibrary->bookList = (Book*)malloc (theLibrary->maxBooks * sizeof(Book));
  
  // check the book file exists 
  // use the error message and exit the program if it does not
  if (strcmp (bookFile, "books.txt") != 0) {
	  printf("Error\nBook file does not exist: %s\n",bookFile);
	  exit(0);
  }
  // open it if it exists
  FILE *fp;
  fp = fopen (bookFile, "r");

  // use the readBooks function to read in the file and add the book records into the bookList array
  theLibrary->numBooks = readBooks (fp, theLibrary->bookList );

  // remember to close the file
  fclose (fp);

  // Initialise the User data
  for (int i = 0; i < theLibrary->maxBorrowed; i++) {
  	theLibrary->theUser.borrowed[i] = NULL;
  }
  theLibrary->theUser.numBorrowed = 0;

  return;
}

// Read in book file and create the books data structure
// the book file is in a fixed format:
// * book author
// * book title
// * blank line
// Input:
//   books - file pointer to text input file
//   bookList - alocated array for storing Book structures
// Output:
//   numBooks - number of books read

int readBooks( FILE *books, Book *bookList ) {

  int numBooks = 0;
  // TO DO:
  
  // read from the book file pointer
  
  // assign values to a Book structure in the bookList array for each complete record
  
  // read data until the file ends

  int count_author = 0;
  int count_title = 0;
  
  while (fgets((bookList + count_author)->author, 40, books) != NULL) {
	numBooks++;
	if ((bookList + count_author)->author[0] != '\n') {
	  fgets((bookList+count_title)->title, 40, books);
	  count_title++;
	count_author++;
	}
	else {
	 	continue;
	}
  }
  numBooks /= 2;

  for (int i = 0; i < numBooks; i++) {
	  removeNewLine(bookList[i].author);
          bookList[i].available = 1;
  }

  printf("%d", numBooks); 
  printf("%d", bookList[6].available);
  printf("%s""\n", bookList[1].author);
  printf("%s", (bookList+0)->author);
  printf("%s", (bookList+0)->title);
  printf("%s", (bookList+1)->author);
  printf("%s", (bookList+1)->title);
  printf("%s", (bookList+2)->author);
  printf("%s", (bookList+2)->title);
  printf("%s", (bookList+3)->author);
  printf("%s", (bookList+3)->title);
  printf("%s", (bookList+4)->author);
  printf("%s", (bookList+4)->title);
  printf("%s", (bookList+5)->author);
  printf("%s", (bookList+5)->title);
  printf("%s", (bookList+6)->author);
  printf("%s", (bookList+6)->title);

  return numBooks;
}

// Free any allocated library data
// Input: 
// theLibrary - library data structure

void exitLibrary( Library *theLibrary ) {

  // TO DO:

  // free the allocated lists
  free(theLibrary->bookList);
  return;
}

// DO NOT ALTER THIS FUNCTION
// Library menu system

void libraryCLI( char *bookFile ) {
    int libraryOpen = 1;
    int option;

    // create the library structure
    Library *theLibrary = (Library *)malloc( sizeof(Library) );

    initLibrary( bookFile, theLibrary );
   
    while( libraryOpen ){
        printf("\n Main menu options\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nUser login\n");
            userCLI( theLibrary );
        }
        else if( option == 2 ) {
            printf("\nLibrarian login\n");
            librarianCLI( theLibrary );
        }
        else if( option == 3 ) {
            libraryOpen = 0;
            printf("\nClosing\n");
        }
        else
            printf("\nUnknown option\n");
    }

    exitLibrary( theLibrary );

    // free the library structure
    free( theLibrary );

    return;
}

