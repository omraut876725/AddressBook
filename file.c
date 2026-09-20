#include <stdio.h>
#include "file.h"
#include<string.h>
 //int count=0;
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr;
    fptr=fopen("file.txt","w");
   
 
     fprintf(fptr,"%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    { 
        fprintf(fptr,"%s,",addressBook->contacts[i].name);
        fprintf(fptr,"%s,",addressBook->contacts[i].phone);
        fprintf(fptr,"%s",addressBook->contacts[i].email);
        fprintf(fptr,"\n");
        
    }
      //rewind(fptr);
      fclose(fptr);
    printf("save Contact Succesfully\n");
   
  
}

void loadContactsFromFile(AddressBook *addressBook) {
    //addressBook->contactCount=0;
      FILE *fptr;
    fptr=fopen("file.txt","r");
           char line[150];

        int count=0;
         fscanf(fptr,"%d",&count); //move fptr from count
         fgetc(fptr);  //new line  fptr->
         addressBook->contactCount=0;
       for(int i=0;i<count;i++)
       {
              fgets(line, sizeof(line), fptr);     
            char *a=strtok(line,",");
          char *b=strtok(NULL,",");
           char *c=strtok(NULL,"\n");

       strcpy(addressBook->contacts[i].name,a);
        strcpy(addressBook->contacts[i].phone,b);
         strcpy(addressBook->contacts[i].email,c);

         addressBook->contactCount++;
                                        
       } 
       fclose(fptr);  
}
