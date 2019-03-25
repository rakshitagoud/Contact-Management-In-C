/**
Project on Contact Management System.
Created by:RajaShekar.
Date:13/3/2016.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[20];
	char number[15];
}Contact;

void addContact();
void deleteContact();
void searchContact();
void displayContact();

//Global Variables
Contact contact;
FILE *fp;
int i;

int main()
{
	int choice;
	
	while(1)
	{
		printf("======================Welcome to PhoneBook===========================\n\n");
		printf("\t[1]Add a Contact\n");
		printf("\t[2]Search a Contact\n");
		printf("\t[3]Display all Contacts\n");
		printf("\t[4]Exit\n");
	
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		
		if(choice==4)
		{
			printf("*****Thank you for using the phonebook*****\n");
			printf("\t****All records are saved****\n\n");
			getch();
			exit(1);
		}
		switch(choice)
		{
			case 1:
				addContact();
				break;
			case 2:
				searchContact();
				break;
			case 3:
				displayContact();
				break;	
		   default:
		   	printf("\t****Invalid choice,Please try again****\n");
		   	getch();
		   	break;
		}
		system("cls");
	}
}

/*Add Contact Function*/
void addContact()
{
	system("cls");
	fp=fopen("contacts.txt","a+");

	if(fp==NULL)
	{
		printf("\t***Oops,The file does'nt exist***\n\n");
		exit(0);

	}
	else
	{

		printf("\t================Welcome to the add Menu:=================\n\n");
			printf("Enter the name of the Contact:\n");
			scanf("%s",contact.name);

			printf("Enter the phone number:\n");
			scanf("%s",contact.number);

			fprintf(fp,"%s\t\t %s\n",contact.name,contact.number);

	}
	fclose(fp);
}

/*Search Contact Function*/
void searchContact()
{
	char sname[15];
	char fname[8];
	Contact contact;
	int compare;
	system("cls");
	
	printf("\n\n\t**********Welcome to search screen************\n\n");
	
	fp=fopen("contacts.txt","r+");
	
	rewind(fp);
	
	printf("Enter the full name of the contact to search:\n");	
	scanf("%s",sname);
	while((fscanf(fp,"%s\t\t %s\n",contact.name,contact.number))!=EOF){
		compare=strcmp(sname,contact.name);
		if(compare==0)
		{
			printf("\t***Match Found***\n\n");
			printf("%s  =  %s\n\n",sname,contact.name);
			printf("Contact Details:\n\n");
			printf("Name:%s\n",contact.name);
			printf("Phone No:%s\n\n",contact.number);
			break;
		}
		else
		{
			printf("\t****Did not match****\n\n");
			printf("%s\t=%s\n",sname,contact.name);
		}
	}
	fclose(fp);
	getch();
}


/*Display Contact Function*/
void displayContact()
{
	system("cls");
	printf("\t********All the Contacts are displayed here***********\n\n");
	FILE *fp;
	char ch;

	fp=fopen("contacts.txt","r");
	while((fscanf(fp,"%s\t\t %s\n",contact.name,contact.number))!=EOF){
	printf("Name:%s\n",contact.name);
	printf("Phone:%s\n\n",contact.number);
	}
	fclose(fp);
	getch();
}

