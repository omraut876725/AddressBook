#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
   for(int i=0;i<addressBook->contactCount;i++)
   {
    printf("%s\t",addressBook->contacts[i].name);
    printf("%s\t",addressBook->contacts[i].phone);
     printf("%s",addressBook->contacts[i].email);
     printf("\n");

   }
    

    
}

void initialize(AddressBook *addressBook) {
    //populateAddressBook(addressBook);
   loadContactsFromFile(addressBook);
  }

void saveAndExit(AddressBook *addressBook) {
  
      saveContactsToFile(addressBook);
}


void createContact(AddressBook *addressBook)
{
    int tem = 0;

    do
    {
        tem = 0;

        printf("-----------------------------------------\n");

        printf("Enter name: ");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

        printf("Enter phone: ");

        char ch[11];
        scanf("%s", ch);

        if(strlen(ch) != 10)
        {
            printf("Enter valid phone no\n");
            tem++;
            continue;
        }
        else
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone, ch);
        }

        printf("Enter email: ");

        char new_email[30];
        scanf(" %[^\n]", new_email);

        char right_email[] = "gmail.com";

        int j = 0;
        int len1 = strlen(new_email);

        if(len1 < 9)
        {
            printf("Enter valid email\n");
            tem++;
            continue;
        }

        int len2 = len1 - 9;

        for(int i = len2; i < len1; i++)
        {
            if(new_email[i] != right_email[j])
            {
                printf("Enter valid email\n");
                tem++;
                break;
            }

            j++;
        }
        

        if(tem == 0)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email,
                   new_email);

            addressBook->contactCount++;
        }

    } while(tem);
}
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int tem=0;
    do
    {
     int n;
     printf("-----------------------------------------------\n");
    printf("Enter choice to by  wich you want to search\n");
    printf("1.name\n");
    printf("2.phone\n");
    printf("3.Gmail\n");
   
   // printf("Enter choice\n");
    scanf("%d",&n);
    
    switch(n)
    {
      case 1:
                {
                  printf("\n-------------------------------------\n");
                  printf("Enter name\n");
                  char var[10];
                  scanf(" %[^\n]s",var);
                  int left=0;
                  int right=addressBook->contactCount-1;
                  int found_name=0;
                  while(left<right)
                  {
                    int cmp1=strcmp(addressBook->contacts[left].name,var);
                    if(cmp1==0)
                    {
                      printf("%s\t",addressBook->contacts[left].name);
                       printf("%s\t",addressBook->contacts[left].phone);
                        printf("%s",addressBook->contacts[left].email);
                        printf("\n");
                        tem++;
                        found_name++;
                    }
                    cmp1=strcmp(addressBook->contacts[right].name,var);
                    if(cmp1==0)
                    {
                      printf("%s\t",addressBook->contacts[right].name);
                       printf("%s\t",addressBook->contacts[right].phone);
                        printf("%s",addressBook->contacts[right].email);
                        found_name++;
                        tem++;
                        printf("\n");
                    }
                    left++;
                    right--;
                  }
                  if(found_name==0)
                  {
                    printf("Contact not found\n");
                  }

                  break;
                 
                }
      case 2:  {
                  printf("-------------------------------------\n");
                 printf("Enter phone\n");
                  char var[10];
                  scanf(" %[^\n]s",var);
                  int left=0;
                  int found_phone=0;
                  int right=addressBook->contactCount-1;
                    while(left<right)
                  {
                    int cmp1=strcmp(addressBook->contacts[left].phone,var);
                    if(cmp1==0)
                    {
                      printf("%s\t",addressBook->contacts[left].name);
                       printf("%s\t",addressBook->contacts[left].phone);
                        printf("%s",addressBook->contacts[left].email);
                         printf("\n");
                        found_phone++;
                        tem++;
                    }
                    cmp1=strcmp(addressBook->contacts[right].phone,var);
                    if(cmp1==0)
                    {
                      printf("%s\t",addressBook->contacts[right].name);
                       printf("%s\t",addressBook->contacts[right].phone);
                        printf("%s",addressBook->contacts[right].email);
                         printf("\n");
                        printf("\n");
                        found_phone++;
                        tem++;
                    }
                    left++;
                    right--;
                  }
                  if(found_phone==0)
                  {
                    printf("contact not found\n");
                  }
                  break;
               

                  }  
                  
      case 3:  {
                  printf("------------------------------------------\n");
                 printf("Enter email\n");
                  char var[50];
                  scanf(" %[^\n]s",var);
                  int left=0;
                  int right=addressBook->contactCount-1;
                  int found_email=0;
                    while(left<right)
                  {
                    int cmp1=strcmp(addressBook->contacts[left].email,var);
                    if(cmp1==0)
                    {
                      printf("%s\t",addressBook->contacts[left].name);
                       printf("%s\t",addressBook->contacts[left].phone);
                        printf("%s",addressBook->contacts[left].email);
                         printf("\n");
                        found_email++;
                        tem++;
                    }
                    cmp1=strcmp(addressBook->contacts[right].email,var);
                    if(cmp1==0)
                    {
                      printf("%s\t",addressBook->contacts[right].name);
                       printf("%s\t",addressBook->contacts[right].phone);
                        printf("%s",addressBook->contacts[right].email);
                         printf("\n");
                        found_email++;
                        tem++;
                        printf("\n");
                    }
                    left++;
                    right--;
                  }
                  if(found_email==0)
                  {
                    printf("contact not Found\n");
                    printf("Enter again\n");
                  }
                  break;
               

                  } 
        default :
                   {
                    printf("Enter valid choice\n");
                    
                   
                    
                   }               
                  

    }
  } 
  while(tem==0);
    
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
  int tem=0;
  do{

    int n;
    printf("-----------------------------------------------\n");
    printf("Enter choice to edit\n");
    printf("1.name\n");
    printf("2.phone\n");
    printf("3.Gmail\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1:   {
                  printf("Enter Name\n");
                  char check_contact[20];
                  scanf(" %[^\n]s",check_contact);
                  printf("Enter New name\n");
                  char new_name[20];
                  scanf(" %[^\n]",new_name);
                
                 
                  int left=0;
                  int right=addressBook->contactCount-1;
                   int found_contact=0;
                  while(left<=right)
                  {
                    int cmp1=strcmp(addressBook->contacts[left].name,check_contact);
                    if(cmp1==0)
                    {
                        strcpy(addressBook->contacts[left].name,new_name);
                     
                      found_contact++;
                      break;

                    }
                    cmp1=strcmp(addressBook->contacts[right].name,check_contact);
                    if(cmp1==0)
                    {
                       strcpy(addressBook->contacts[right].name,new_name);
                   
                       found_contact++;
                      break;
                    }
                    left++;
                    right--;
                  }
                  if(found_contact==0)
                  {
                    printf("contact not found\n");
                    tem++;
                  }
                   break;
                  }

      
      case 2:   {
                  printf("Enter phone\n");
                  char check_contact[20];
                  scanf(" %[^\n]s",check_contact);
                  printf("Enter New phone\n");
                  char new_phone[20];
                  scanf(" %[^\n]",new_phone);
                
                 if(strlen(new_phone)!=10)
                 {
                       printf("Enter valid phone no\n");
                       tem++;
                       continue;
                 }
                  int left=0;
                  int right=addressBook->contactCount-1;
                   int found_contact=0;
                  while(left<=right)
                  {
                    int cmp1=strcmp(addressBook->contacts[left].phone,check_contact);
                    if(cmp1==0)
                    {
                        strcpy(addressBook->contacts[left].phone,new_phone);
                     
                      found_contact++;
                      break;

                    }
                    cmp1=strcmp(addressBook->contacts[right].phone,check_contact);
                    if(cmp1==0)
                    {
                       strcpy(addressBook->contacts[right].phone,new_phone);
                   
                       found_contact++;
                      break;
                    }
                    left++;
                    right--;
                  }
                  if(found_contact==0)
                  {
                    printf("contact not found\n");
                    tem++;
                  }
                   break;
                  }
      
      case 3:   {
                  printf("Enter email\n");
                  char check_contact[30];
                  scanf(" %[^\n]s",check_contact);
                  printf("Enter New name\n");
                  char new_email[30];
                  scanf(" %[^\n]",new_email);
                  char right_email[10]="gmail.com";
                  int j=0;
                  int len1=strlen(new_email);
                  int len2=len1-9;
                  for(int i=len2;i<len1;i++)
                  {
                    if(new_email[i]!=right_email[j])
                    {
                      printf("Enter valid email\n");
                      
                      tem++;
                      break;
                    }
                    j++;
                  }
                 
                  int left=0;
                  int right=addressBook->contactCount-1;
                   int found_contact=0;
                  while(left<=right)
                  {
                    int cmp1=strcmp(addressBook->contacts[left].email,check_contact);
                    if(cmp1==0)
                    {
                        strcpy(addressBook->contacts[left].email,new_email);
                     
                      found_contact++;
                      break;

                    }
                    cmp1=strcmp(addressBook->contacts[right].email,check_contact);
                    if(cmp1==0)
                    {
                       strcpy(addressBook->contacts[right].email,new_email);
                   
                       found_contact++;
                      break;
                    }
                    left++;
                    right--;
                  }
                  if(found_contact==0)
                  {
                    printf("contact not found\n");
                    tem++;
                  }
                   break;
                  }            
          default :   {
                      printf("Enter valid Choice\n");
                      tem++;
                       break;

                     }            
      
                  }
      
      
                  } 
                  while(tem);             
         }



void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   int tem=0;
  do
  {
  printf("------------------------------------------\n");
  printf("Enter name\n");
  char check_name[50];
  scanf(" %[^\n]",check_name);
 int found_contact=-1;
  
  for(int i=0;i<addressBook->contactCount;i++)
  {
      found_contact=strcmp(addressBook->contacts[i].name,check_name);
    
      if(found_contact==0)
     {
       for(int j=i;j<addressBook->contactCount;j++)
       {
        strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
        strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
        strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
       }
       printf("Delete Contact sucessfully\n");
       addressBook->contactCount--;
       found_contact++;
       tem++;

            break;
      }
    
}
if(tem==0)
{
  printf("Contact not found\n");
  printf("Enter again\n");
}
  }
  while(tem==0);

 

   
}
