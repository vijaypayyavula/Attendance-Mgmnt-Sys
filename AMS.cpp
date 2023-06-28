//HEADER FILES
#include<stdio.h>//Use for standard I/O Operation
#include<windows.h>
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<cstdio>

using namespace std;

char ans=0; 
int ok;
int b, valid=0;
int usnSearch(char[]);
//FUNCTION DECLERATIONS
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void AttendanceMenu(void);//AttendanceMenu function declaration
void MainMenu(void);//MainMenu function decleration
void StudentMenu(void);//StudentMenu function decleration
void OneMenu(void);//FirstMenu function decleration
void OneAttendanceMenu(void);//OneAttendanceMenu function decleration
void OneAttendance_Add(void);
void OneAttendance_List(void);
void OneAttendance_Search(void);
void OneAttendance_Edit(void);
void OneAttendance_Delete(void);
void LoginScreen(void);//LoginScreen function decleration
void One_Add(void);
void One_List(void);
void One_Search(void);
void One_Edit(void);
void One_Delete(void);
void ex_it(void);//exit function declaration
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y)
{
	COORD pos = {x, y};//sets co-ordinates in (x,y).
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//for Students
struct student
{
 char fname[20];//for student first name
 char lname[20];//for student last name
 char registration[20];//for Registration No number
 char gender;//gender of student
 int age;//for age info
 char phone[20];//phone no
 
}s;//Variable of student type

//for attendance
struct attendance
{
	char fname[20];
	char lname[20];
	char usn[20];
	char att1[20];
	char att2[20];
	char att3[20];
	char att4[20];
	char att5[20];
	char att6[20];
	char att7[20];
	char att8[20];
}a;

int main(void)
{
	
    WelcomeScreen();//Use to call WelcomeScreen function
    system("cls");
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
	return 0;

}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{
	gotoxy(25,6);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,7);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,8);
	printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(25,9);
	printf("        =                 WELCOME                   =");
	gotoxy(25,10);
	printf("        =                   TO                      =");
	gotoxy(25,11);
	printf("        =                  EWIT                     =");
	gotoxy(25,12);
	printf("        =             ISE DEPARTMENT                =");
	gotoxy(25,13);
	printf("        =               ATTENDANCE                  =");
	gotoxy(25,14);
	printf("        =            MANAGEMENT SYSTEM              =");
	gotoxy(25,15);
	printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(25,16);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,17);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(28,22);
	printf(" Enter any key to continue.....");
	getch();
	
}
/* ************************************************* Title Screen ********************************************* */
void Title(void)//function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t      	             ISE DEPARTMENT         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	
	printf("\n\n\n\n\t\t\t\t1. Student Information\n");
	printf("\n\t\t\t\t2. Attendance Information\n");
	printf("\n\t\t\t\t3. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 3:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	

    case 1:
    		StudentMenu();
    		break;
	case 2:
			AttendanceMenu();//View_rec function is call
    		break;
	case 3:
			ex_it();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option !");
		getch();//holds screen
	}//end of switch
		
	
}


/* ************************************************* Student Menu ********************************************* */
void StudentMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. 1st Sem\n");
	printf("\n\t\t\t\t2. Back to main menu\n");
	scanf("%i", &choose);
	
	switch(choose)//switch to different case
	{
	
	case 1:
			OneMenu();//Add_rec function is called
    		break;
    case 2:
			MainMenu();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option !");
		getch();//holds screen
	}//end of switch
		
	
}
/* ************************************************* First Sem Menu ********************************************* */
void OneMenu(void)//function decleration
{
	int choice;
	system("cls");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,2);
		printf("First Sem Records");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,5);
		printf("1. Add Students");
		gotoxy(20,7);
		printf("2. View Students");
		gotoxy(20,9);
		printf("3. Search Students");
		gotoxy(20,11);
		printf("4. Edit Students Record");
		gotoxy(20,13);
		printf("5. Delete Students");
		gotoxy(20,15);
		printf("6. Back to Student Main menu");
		gotoxy(20,17);
		printf("Please Enter a choice[1-6]:");
		scanf("%i",&choice);
		switch(choice)
			{
				case 1:
						One_Add();
						break;
				case 2:
			    		One_List();
						break;
				case 3:
						One_Search();
						break;
				case 4:
						One_Edit();
						break;
				case 5:
						One_Delete();
						break;
				case 6:
						StudentMenu();
						break;
				
				default:
					printf("Wrong Entry!!");
					exit(0);
					
						
			}
}
void One_Add(void)
{
	system("cls");
	Title();
	char ans;
	FILE*ek;
	ek=fopen("one.txt","a");
	printf("\n\t\t*******************************************************");
	printf("\n\t                     ADD NEW STUDENT                     ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:"); 

	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",s.fname);
	s.fname[0]=toupper(s.fname[0]);
	if(strlen(s.fname)>20||strlen(s.fname)<2)
	{
		printf("\n\t Invalid ! \t The max range for first name is 20 and min range is 2 !");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(s.fname);b++)
		{
			if (isalpha(s.fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character !  Enter again !");
			goto A;
		}
	}
	    
	printf("\n\t\t\tLast Name: ");
    scanf("%s",s.lname);
    

    	do
		{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&s.gender);
		if(toupper(s.gender)=='M'|| toupper(s.gender)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character !  Enter either F or M !");
    	}
	 }	while(!ok);

    printf("\n\t\t\tAge:");
    scanf(" %i",&s.age);

do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",s.phone);
    if(strlen(s.phone)>10||strlen(s.phone)!=10)
	{
		printf("\n\t Sorry ! Invalid. Contact no. must contain 10 numbers. Enter again !");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(s.phone);b++)
		{
			if (!isalpha(s.phone[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character !  Enter again !");
			goto D;
		}
	}
}while(!valid);

	fprintf(ek," %s %s %c %i %s %s \n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	One_Add();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you ! !");
    	getch();
    	OneMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
void One_List(void)
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("one.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!1st Sem Students Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(25,15);
		printf("Gender");
		gotoxy(38,15);
		printf("Age");
		gotoxy(46,15);
		printf("Registration No.");
		gotoxy(70,15);
		printf("Phone No.");
		gotoxy(1,16);
		printf("=================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s  \n",s.fname,s.lname,&s.gender,&s.age,s.registration,s.phone)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",s.fname,s.lname);
			gotoxy(25,row);
			printf("%c",s.gender);
			gotoxy(38,row);
			printf("%i",s.age);
			gotoxy(46,row);
			printf("%s",s.registration);
			gotoxy(70,row);
			printf("%s",s.phone);
			row++;
		}
		fclose(ek);
		getch();
		OneMenu();
}

void One_Search(void)
{
	int row;
	char regNo[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("one.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Students Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Student Registration No to be searched:");
	scanf("%s",regNo);
	fflush(stdin);
	regNo[0]=toupper(regNo[0]);
	while(fscanf(ek,"%s %s %c %i %s %s \n",s.fname,s.lname,&s.gender,&s.age,s.registration,s.phone)!=EOF)
	{
		if(strcmp(s.registration,regNo)==0)
		{
			gotoxy(1,15);
		printf("Full Name");
		gotoxy(25,15);
		printf("Gender");
		gotoxy(38,15);
		printf("Age");
		gotoxy(46,15);
		printf("Registration No.");
		gotoxy(70,15);
		printf("Phone No.");
		gotoxy(1,16);
		printf("=================================================================================================================");
		row=17;
			gotoxy(1,row);
			printf("%s %s",s.fname,s.lname);
			gotoxy(25,row);
			printf("%c",s.gender);
			gotoxy(38,row);
			printf("%i",s.age);
			gotoxy(46,row);
			printf("%s",s.registration);
			gotoxy(70,row);
			printf("%s",s.phone);
			break;
		}
	   }
	   if(strcmp(s.registration,regNo)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        One_Search();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you ! !");
    	getch();
		OneMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}

void One_Edit(void)
{
	FILE *ek, *ft;
  	int i,b, valid=0;
  	char ch;
  	char regNo[20];

  	system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("one.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		OneMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Students Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the Registration No of the Student : ");
	   	scanf(" %s",regNo);
	   	fflush(stdin);
	   	regNo[0]=toupper(regNo[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			OneMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s\n",s.fname,s.lname,&s.gender,&s.age,s.registration,s.phone)!=EOF)
		{
			if(strcmp(s.registration, regNo)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s\n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",s.fname);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",s.lname);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&s.gender);
				s.gender=toupper(s.gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&s.age);
				gotoxy(12,30);
				printf("Enter New Registration Number: ");
				scanf(" %s",s.registration);
				gotoxy(12,32);
				printf("Enter Contact no: ");
				scanf("%s",s.phone);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s\n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);
				printf("\n\n\t\t\tStudent record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s \n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	    fclose(ft);
	    fclose(ek);
	    remove("one.txt");
   	    rename("temp2.txt","one.txt");
		getch();
		OneMenu();		
}

void One_Delete()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("one.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Students Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Student Name to delete: ");
	fflush(stdin);
	// gets(name);
	cin >> name;
	name[0]=toupper(name[0]);
	int count=0;
	char regNo[20];
	
	while (fscanf(ek,"%s %s %c %i %s %s \n",s.fname,s.lname,&s.gender,&s.age,s.registration,s.phone)!=EOF)
	{
		if (strcmp(s.fname,name)==0)
		{
			printf("%s %s %c %i %s %s \n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);
			count++;
		}
	}//while loop ends
	fclose(ek);
	ek=fopen("one.txt","r");

	if(count>0){
		printf("Multiple records found! Enter the registration number to delete: ");
		fflush(stdin);
		cin >> regNo;
		while (fscanf(ek,"%s %s %c %i %s %s \n",s.fname,s.lname,&s.gender,&s.age,s.registration,s.phone)!=EOF)
		{
			if (strcmp(s.registration,regNo)!=0)
				fprintf(ft,"%s %s %c %i %s %s \n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);
			else 
			{
				printf("%s %s %c %i %s %s \n",s.fname,s.lname,s.gender,s.age,s.registration,s.phone);
				found=1;
			}
		}

	}
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		OneMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("one.txt");
		rename("temp.txt","one.txt");
		printf("\n\n\t\t\t Record deleted successfully ! ");
		getch();
		OneMenu();
	}
}	

/* ************************************************* Attendance Menu ********************************************* */

void AttendanceMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. 1st Sem\n");
	printf("\n\t\t\t\t2. Back to main menu\n");
	scanf("%i", &choose);
	
	switch(choose)//switch to different case
	{
	
	case 1:
			OneAttendanceMenu();
    		break;
    case 2:
			MainMenu();
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option !");
		getch();//holds screen
	}//end of switch
		
	
}

/* ************************************************* First Sem Attendance Menu ********************************************* */
void OneAttendanceMenu(void)//function decleration
{
	int choice;
	system("cls");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,2);
		printf("First Sem Attendance Records");
		printf("\n------------------------------------------------------------------------------------------------");
		gotoxy(20,5);
		printf("1. Add Student Attendance");
		gotoxy(20,7);
		printf("2. View Students Attendance");
		gotoxy(20,9);
		printf("3. Search Students Attendance");
		gotoxy(20,11);
		printf("4. Edit Students Attendance");
		gotoxy(20,13);
		printf("5. Delete Students Attendance");
		gotoxy(20,15);
		printf("6. Back to Student Main menu");
		gotoxy(20,17);
		printf("Please Enter a choice[1-6]:");
		scanf("%i",&choice);
		switch(choice)
			{
				case 1:
						OneAttendance_Add();
						break;
				case 2:
			    		OneAttendance_List();
						break;
				case 3:
						OneAttendance_Search();
						break;
				case 4:
						OneAttendance_Edit();
						break;
				case 5:
						OneAttendance_Delete();
						break;
				case 6:
						AttendanceMenu();
						break;
				
				default:
					printf("Wrong Entry!!");
					exit(0);
					
						
			}
}
void OneAttendance_Add(void)
{
	system("cls");
	Title();// call Title function
	char ans;
	FILE*ek;//file pointer
	ek=fopen("attendance1.txt","a");//open file in write mode
	printf("\n\t\t*******************************************************");
	printf("\n\t                     ADD ATTENDANCE                      ");
	printf("\n\t\t*******************************************************");
	printf("\n\n\t\t  ENTER THE DETAILS BELOW:");
/* ******************************************* First Name ************************************************************** */	    

	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",a.fname);
	a.fname[0]=toupper(a.fname[0]);
	if(strlen(a.fname)>20||strlen(a.fname)<2)
	{
		printf("\n\t Invalid ! \t The max range for first name is 20 and min range is 2 !");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(a.fname);b++)
		{
			if (isalpha(a.fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character !  Enter again !");
			goto A;
		}
	}
/* ******************************************* Last Name ************************************************************** */	    
	printf("\n\t\t\tLast Name: ");
    scanf("%s",a.lname);

/* ***************************************** Registration ********************************************************************** */	
     
    printf("\n\t\t\tRegistration number:");
    scanf(" %s",a.usn);
  
/* ***************************************** SUBJECT1 ATTENDANCE   ********************************************************************** */	
    printf("\n\t\t\tSubject 1 Attendance:");
    scanf(" %s",a.att1);
/* ***************************************** SUBJECT2 ATTENDANCE  ********************************************************************** */	
    printf("\n\t\t\tSubject 2 Attendance:");
    scanf(" %s",a.att2);
/* ***************************************** SUBJECT3 ATTENDANCE  ********************************************************************** */	
    printf("\n\t\t\tSubject 3 Attendance:");
    scanf(" %s",a.att3);
/* ***************************************** SUBJECT4 ATTENDANCE   ********************************************************************** */	
    printf("\n\t\t\tSubject 4 Attendance:");
    scanf(" %s",a.att4);
/* ***************************************** SUBJECT5 ATTENDANCE  ********************************************************************** */	
    printf("\n\t\t\tSubject 5 Attendance:");
    scanf(" %s",a.att5);
/* ***************************************** SUBJECT6 ATTENDANCE  ********************************************************************** */	
    printf("\n\t\t\tSubject 6 Attendance:");
    scanf(" %s",a.att6);
/* ***************************************** SUBJECT7 ATTENDANCE  ********************************************************************** */	
    printf("\n\t\t\tSubject 7 Attendance:");
    scanf(" %s",a.att7);
/* ***************************************** SUBJECT8 ATTENDANCE  ********************************************************************** */	
    printf("\n\t\t\tSubject 8 Attendance:");
    scanf(" %s",a.att8);

	fprintf(ek," %s %s %s %s %s %s %s %s %s %s %s \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8);
    printf("\n\n\t\t\t.... Attendance Recorded Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	OneAttendance_Add();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you ! !");
    	getch();
    	OneAttendanceMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
void OneAttendance_List(void)
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("attendance1.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!1st Sem Students Attendance !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Name");
		gotoxy(20,15);
		printf("USN");
		gotoxy(36,15);
		printf("SUB1");
		gotoxy(44,15);
		printf("SUB2");
		gotoxy(52,15);
		printf("SUB3");
		gotoxy(60,15);
		printf("SUB4");
		gotoxy(68,15);
		printf("SUB5");
		gotoxy(76,15);
		printf("SUB6");
		gotoxy(84,15);
		printf("SUB7");
		gotoxy(92,15);
		printf("SUB8");
		gotoxy(1,16);
		printf("=================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s %s   \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",a.fname,a.lname);
			gotoxy(20,row);
			printf("%s",a.usn);
			gotoxy(36,row);
			printf("%s",a.att1);
			gotoxy(44,row);
			printf("%s",a.att2);
			gotoxy(52,row);
			printf("%s",a.att3);
			gotoxy(60,row);
			printf("%s",a.att4);
			gotoxy(68,row);
			printf("%s",a.att5);
			gotoxy(76,row);
			printf("%s",a.att6);
			gotoxy(84,row);
			printf("%s",a.att7);
			gotoxy(92,row);
			printf("%s",a.att8);
			
			row++;
		}
		fclose(ek);
		getch();
		OneAttendanceMenu();
}
void OneAttendance_Search(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("attendance1.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Students Attendance !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Students Name to be searched:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s %s   \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8)!=EOF)
	{
		if(strcmp(a.fname,name)==0)
		{
		gotoxy(1,15);
		printf("Name");
		gotoxy(20,15);
		printf("USN");
		gotoxy(36,15);
		printf("SUB1");
		gotoxy(44,15);
		printf("SUB2");
		gotoxy(52,15);
		printf("SUB3");
		gotoxy(60,15);
		printf("SUB4");
		gotoxy(68,15);
		printf("SUB5");
		gotoxy(76,15);
		printf("SUB6");
		gotoxy(84,15);
		printf("SUB7");
		gotoxy(92,15);
		printf("SUB8");
		gotoxy(1,16);
		printf("=================================================================================================================");
		row=17;
			gotoxy(1,row);
			printf("%s %s",a.fname,a.lname);
			gotoxy(20,row);
			printf("%s",a.usn);
			gotoxy(36,row);
			printf("%s",a.att1);
			gotoxy(44,row);
			printf("%s",a.att2);
			gotoxy(52,row);
			printf("%s",a.att3);
			gotoxy(60,row);
			printf("%s",a.att4);
			gotoxy(68,row);
			printf("%s",a.att5);
			gotoxy(76,row);
			printf("%s",a.att6);
			gotoxy(84,row);
			printf("%s",a.att7);
			gotoxy(92,row);
			printf("%s",a.att8);
			break;
		}
	   }
	   if(strcmp(a.fname,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        OneAttendance_Search();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you ! !");
    	getch();
		OneAttendanceMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
void OneAttendance_Edit(void)
{
	FILE *ek, *ft;
  	int i,b, valid=0;
  	char ch;
  	char name[20];

  	system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("attendance1.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		OneAttendanceMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Students Attendance !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Student : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			OneAttendanceMenu();
		}
		while(fscanf(ek,"%s %s %s %s %s %s %s %s %s %s %s   \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8)!=EOF)
		{
			if(strcmp(a.fname, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s %s %s %s %s %s %s %s %s %s %s   \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",a.fname);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",a.lname);
				gotoxy(12,26);
				printf("Enter USN: ");
				scanf(" %s",a.usn);
				gotoxy(12,28);
				printf("Enter Subject1 Attendance : ");
				scanf(" %s",a.att1);
				gotoxy(12,30);
				printf("Enter Subject2 Attendance : ");
				scanf(" %s",a.att2);
				gotoxy(12,32);
				printf("Enter Subject3 Attendance : ");
				scanf(" %s",a.att3);
				gotoxy(12,34);
				printf("Enter Subject4 Attendance : ");
				scanf(" %s",a.att4);
				gotoxy(12,36);
				printf("Enter Subject5 Attendance : ");
				scanf(" %s",a.att5);
				gotoxy(12,38);
				printf("Enter Subject6 Attendance : ");
				scanf(" %s",a.att6);
				gotoxy(12,40);
				printf("Enter Subject7 Attendance : ");
				scanf(" %s",a.att7);
				gotoxy(12,42);
				printf("Enter Subject8 Attendance : ");
				scanf(" %s",a.att8);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %s %s %s %s %s %s %s %s %s   \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8);
				printf("\n\n\t\t\tStudent Attendance updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %s %s %s %s %s %s %s %s %s   \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	    fclose(ft);
	    fclose(ek);
	    remove("attendance1.txt");
   	    rename("temp2.txt","attendance1.txt");
		getch();
		OneAttendanceMenu();		
}
void OneAttendance_Delete()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("attendance1.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Students Attendance !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Student Name to delete: ");
	fflush(stdin);
	// gets(name);
	cin >> name;
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %s %s %s %s %s %s %s %s %s \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8)!=EOF)
	{
		if (strcmp(a.fname,name)!=0)
		fprintf(ft,"%s %s %s %s %s %s %s %s %s %s %s \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8);
		else 
		{
			printf("%s %s %s %s %s %s %s %s %s %s %s \n",a.fname,a.lname,a.usn,a.att1,a.att2,a.att3,a.att4,a.att5,a.att6,a.att7,a.att8);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		OneAttendanceMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("attendance1.txt");
		rename("temp.txt","attendance1.txt");
		printf("\n\n\t\t\t Record deleted successfully ! ");
		getch();
		OneAttendanceMenu();
	}
}	



/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING !");
	getch();//holds screen
	
}
/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)//function for login screen
{
//list of variables	
int i=0,e=0	;
char Username[15];
char Password[15];
char c= ' ';
char original_Username[25]="ewit";
char original_Password[15]="ewit";

	do
	{
		printf("\n\n\n\n\t\t\t\tEnter your Username and Password !");
		printf("\n\n\n\t\t\t\t\tUSERNAME:");
		scanf("%s",&Username);
	
		printf("\n\n\t\t\t\t\tPASSWORD:");
		while(i<10)
		{
	    	Password[i]=getch();
	    	c=Password[i];
	    	if(c==13) break;
	    	else printf("*");
	    	i++;
		}
		Password[i]='\0';
		if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
		{
			printf("\n\n\n\t\t\t\t\t...Login Successfull...");
			getch();
			MainMenu();//call MainMenu function
			break;
		}
		else
		{
			printf("\n\t\t\tPassword in incorrect! Try Again !");
			e++;
			system("cls");
			Title();
			LoginScreen();
		}

	}
	while(e<=2);
	system("cls");
}	

int usnSearch(char usn[20]){
	FILE *ek;
	ek=fopen("one.txt","r"); 
	while(fscanf(ek,"%s %s %c %i %s %s \n",s.fname,s.lname,&s.gender,&s.age,s.registration,s.phone)!=EOF){
		if(strcmp(usn,s.registration)==0){
			return 1;
		}
	}
	return 0;
}




