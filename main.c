/*
 * =========================================================
 *                  ADDRESS BOOK PROJECT
 * =========================================================
 *
 * Description:
 * This project is developed in C programming language to
 * manage and maintain contact information in an address book.
 *
 * The project allows the user to:
 * 1. Add a new contact.
 * 2. Display all contacts.
 * 3. Search for a contact.
 * 4. Edit or update contact details.
 * 5. Delete a contact.
 * 6. Store information such as name, phone number and email.
 *
 * Purpose:
 * The main purpose of this project is to provide a simple
 * and user-friendly system for managing contact details.
 *
 * Concepts Used:
 * - Structures
 * - Functions
 * - Arrays
 * - Strings
 * - File handling
 * - Searching and sorting
 *
 * =========================================================
 */



#include <stdio.h>
#include "contact.h"
#include<string.h>
int main() {
   AddressBook addressBook;
  initialize(&addressBook);
   
    int choice ;
  do {
     printf("------------------Address book--------------------------\n");
      printf("1.create contact\n");
         printf("2.search  contact\n");
          printf("3.Edit contact\n");
           printf("4.Delete contact\n");
            printf("5.List all  contact\n");
             printf("6.Save contact\n");
             printf("7.exit\n");
             printf("Enter your choice\n");
             scanf("%d",&choice);

             switch(choice)
   {

           case 1:{
                        //  printf("seleted create contact\n");
                         createContact(&addressBook);
                          break;

                  }


           case 2:{
                          //printf("seleted search contact\n");
                          searchContact(&addressBook);
                          break;

                  }

           case 3:{
                          //printf("seleted edit contact\n");
                          editContact(&addressBook);
                          break;
           }  
           
           case 4:{
                          //printf("seleted delete contact\n");
                          deleteContact(&addressBook);
                          break;

                  }

           case 5:{
                          //printf("seleted list of contact\n");
                          listContacts(&addressBook);
                          break;

                  }

           case 6:{
                          //printf("seleted save contact\n");
                           saveAndExit(&addressBook);
                          break;

                  }

           case 7:{
                          printf("Thank you\n");

                          return 0;
                          break;
                  }

                   
           default:
             {
                     printf("Enter valid choice\n");


             }
  }
          
}
while(choice!=7);
return 0;
}
