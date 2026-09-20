/*
Name    : Om Siddheshwar Raut
Date    : 30-Aug-2026
Batch Id: 26019f_009

  Address Book Project
  --------------------
  This project is a menu-driven C program designed to manage a collection of contacts.
  It provides users with options to add, search, edit, delete, display, and save
  their personal or professional contact details in a simple and organized way.

  Project Overview:
    - Each contact contains three fields: Name, Phone Number, and Email ID.
    - Contacts are stored in memory during the program's execution.
    - File handling is used so that contacts can be saved into a file (CSV format)
      and reloaded the next time the program runs.
    - Input validation is applied to ensure the correctness of data:
        * Name must contain only valid characters
        * Phone number must be exactly 10 digits
        * Email must follow the correct format and end with ".com"
    - Duplicate entries for phone and  email are not allowed.

  Main Features:
    1. Create Contact   : Add a new contact after validating user input.
    2. Search Contact   : Find a contact by Name, Phone Number, or Email ID.
    3. Edit Contact     : Update the details of an existing contact.
    4. Delete Contact   : Remove a contact permanently from the address book.
    5. List Contacts    : Display all contacts in a table with sorting options
                          (by Name, Phone, or Email).
    6. Save Contacts    : Store all the contacts into a CSV file for future use.
    7. Exit             : Exit the program safely (with option to save).

  How It Works:
    - When the program starts, it automatically loads contacts from the file.
    - Users interact through a menu that guides them step by step.
    - Any changes made (add, edit, delete) are kept in memory until saved.
    - By choosing the "Save" option, data is written permanently to the file.
    - This makes the program both interactive and persistent.

  File Structure:
    - main.c       : Contains the main menu and user interaction loop.
    - contact.c/h  : Handles creation, searching, editing, deleting, validation,
                     and listing of contacts.
    - file.c/h     : Manages reading from and writing to the "contacts.csv" file.

  Extensibility:
    - The project is modular, so more fields (like address, date of birth, notes)
      can be added easily.
    - Future upgrades can include importing/exporting contacts, grouping them,
      or even creating a graphical user interface (GUI).

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
