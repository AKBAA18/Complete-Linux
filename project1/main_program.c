#include<stdio.h>
#include"functions.h"


int main() {
  int choice = 1;

  struct book book_lib;
  struct user user_lib;
  // allocating the space for library
  book_lib.name = (char **)calloc(15, sizeof(char));
  book_lib.author = (char **)calloc(15, sizeof(char));
  book_lib.username = (char **)calloc(15, sizeof(char));
  book_lib.bookid = (char **)calloc(15, sizeof(char));
  book_lib.index = (int **)calloc(20, sizeof(int));

  // allocating the space for user
  user_lib.uname = (char **)malloc(15 * sizeof(char));
  user_lib.uid = (char **)malloc(15 * sizeof(char));
  user_lib.size = 0;

  while (1) {
    printf("\n1 Book addition \n2 Book deletion \n3 Display books \n4 Search book \n5 Add customer \n6 Display customer \n7 Search customer \n8 Delete customer \n9 Exit \nEnter your choice ");
    scanf("%d", &choice);
    if (choice == 1) {
      add(&book_lib);
    }
    if (choice == 2) {
      delete (&book_lib);
    }
    if (choice == 3) {
      display(&book_lib);
    }
    if (choice == 4) {
      search(&book_lib);
    }
    if (choice == 5) {
      add_customer(&user_lib);
    }
    if (choice == 6) {
      display_customer(&user_lib);
    }
    if (choice == 7) {
      search_customer(&user_lib);
    }
    if (choice == 8) {
      delete_customer(&user_lib);
    }
    if(choice ==9)
    {
        break;
    }

    printf("\n");
  }

  return 0;
}
