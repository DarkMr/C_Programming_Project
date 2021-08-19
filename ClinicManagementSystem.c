#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define MAXQUEUE 10
int front=0;
int rear=MAXQUEUE-1;
int count = 0;
int queue[MAXQUEUE];
int item;
char ch;
int count2=1;
int i=0;
char name[100][100];
float price[100];
int capsule[100];
struct address
{
    char addr[100],state[20];
    int postcode;
};
struct emergency
{
    char name[50],phone[11];
};
struct information1
{
    int patientID;
    char name[100],mobile[12],dob[15],sex,race[10],email[30],status[13];
    int NoIc,age;
    struct address  ptient;
    struct emergency  mother;
    struct emergency  father;
};
struct link
{
    struct information1 patient;
    struct link *ptrnext;
};
struct link *ptrhead,*currentptr,*newptr,*ptrprev,*ptrassist;
void enqueue(int);
void dequeue();
void display();
void insert();
void deleteinfo();
void update();
void displaypatient();
void displayInformation(void);
void appointment();
void sortID();
void sortNAME();
void display1();
void medicine();
void amt_medicine(int);
void display_receipt(int);
int
main(void)
{
    char ch;
    int choice=TRUE;
    ptrhead=NULL;
    while(choice==TRUE)
    {
        printf("\n******** CLINIC PATIENT RECORDS AND APPOINTMENT MANAGEMENT SYSTEM ********");
        printf("\n\n\t\tR- RECORD NEW PATIENT INFORMATION");
        printf("\n\t\tU- UPDATE PATIENT INFORMATION");
        printf("\n\t\tD- DELETE PATIENT INFORMATION");
        printf("\n\t\tT- DISPLAY ALL PATIENT INFORMATION");
        printf("\n\t\tA- APPOINTMENT SCHEDULE");
        printf("\n\t\tM- MEDICINE INFORMATION");
        printf("\n\t\tX- EXIT");
        printf("\n\nPLEASE ENTER YOUR CHOICE:");
        scanf(" %c", &ch);
        ch=toupper(ch);
        switch(ch)
        {
            case'R':insert();break;
            case'U':update();break;
            case'D':deleteinfo();break;
            case'T':displayInformation();break;
            case'A':appointment();break;
            case'X':choice=FALSE;break;
            case'M':medicine();break;
            default:printf("\n\nENTER ONE ONLY FROM ABOVE !!\n");
        }
    }
    return 0;
}
void insert()
{
    newptr=(struct link *)malloc(sizeof(struct link));
    newptr->patient.patientID=count2;
    printf("\nPatient ID: %d", count2);
    printf("\nEnter Patient Name:");
    scanf(" %[^\n]s", newptr->patient.name);
    printf("\nEnter No.IC:");
    scanf(" %d", &newptr->patient.NoIc);
    printf("\nEnter Age:");
    scanf(" %d", &newptr->patient.age);
    printf("\nEnter Date of Birth:");
    scanf(" %s", &newptr->patient.dob);
    printf("\nEnter Sex (M-male or F- female):");
    scanf(" %c", &newptr->patient.sex);
    printf("\nEnter Status:");
    scanf(" %s", &newptr->patient.status);
    printf("\nEnter Race:");
    scanf(" %s", &newptr->patient.race);
    printf("\nEnter No.Mobilephone:");
    scanf(" %s", &newptr->patient.mobile);
    printf("\nThe address :");
    printf("\n");
    printf("\n\tEnter you address:");
    scanf(" %[^\n]s", &newptr->patient.ptient.addr);
    printf("\n\tEnter you state:");
    scanf(" %[^\n]s", &newptr->patient.ptient.state);
    printf("\n\tEnter postcode :");
    scanf(" %d", &newptr->patient.ptient.postcode);
    printf("\n");
    printf("\nFor Emergency Information");
    printf("\nEnter you father name:");
    scanf(" %[^\n]s", &newptr->patient.father.name);
    printf("\nEnter you father no phone:");
    scanf(" %s", &newptr->patient.father.phone);
    printf("\nEnter you mother name:");
    scanf(" %[^\n]s", &newptr->patient.mother.name);
    printf("\nEnter your mother no phone:");
    scanf(" %s", &newptr->patient.mother.phone);
    count2++;
    if(ptrhead==NULL)
    {
        ptrhead=newptr;
        newptr->ptrnext=NULL;
    }
    else
    {
        currentptr=ptrhead;
        while(currentptr!=NULL)
        {
            if(currentptr->ptrnext==NULL)
                break;
            else
            {
                currentptr=currentptr->ptrnext;
            }
        }
         if(currentptr!=NULL)
        {
            currentptr->ptrnext=newptr;
            newptr->ptrnext=NULL;
        }
    }
    displaypatient();
}
void displayInformation()
{
    char ch;
    int choice=TRUE;
    if(ptrhead==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    while(choice==TRUE)
    {
        printf("PLEASE CHOOSE THE WAY OF SORTING PATIENT INFORMATION: \n\n");
        printf("A- SORT BY PATIENT ID\n");
        printf("B- SORT BY PATIENT NAME\n");
        printf("X- EXIT\n");
        scanf(" %c", &ch);
        ch=toupper(ch);
        switch(ch)
        {
            case'A':sortID();display1();break;
            case'B':sortNAME();display1();break;
            case'X':choice=FALSE;break;
            default:printf("\n\nENTER ONE ONLY FROM ABOVE !!\n");
        }
    }
}
 void sortID()
 {
     int i;
     int count3=1;
     currentptr=ptrhead;
     while(currentptr->ptrnext!=NULL)
     {
        count3++;
        currentptr=currentptr->ptrnext;
     }
        for(i=1;i<count3;i++)
        {
                currentptr=ptrhead;
                ptrprev=currentptr;
                ptrassist=currentptr->ptrnext;
            if(ptrassist->patient.patientID<currentptr->patient.patientID)
            {
                currentptr->ptrnext=ptrassist->ptrnext;
                ptrhead=ptrassist;
                ptrassist->ptrnext=currentptr;
            }
            currentptr=ptrhead->ptrnext;
            ptrassist=currentptr->ptrnext;
            ptrprev=ptrhead;
            while(currentptr->ptrnext!=NULL)
            {
                if(ptrassist->patient.patientID<currentptr->patient.patientID)
                {
                    currentptr->ptrnext=ptrassist->ptrnext;
                    ptrprev->ptrnext=ptrassist;
                    ptrassist->ptrnext=currentptr;
                }
                ptrprev=ptrprev->ptrnext;
                currentptr=ptrprev->ptrnext;
                ptrassist=currentptr->ptrnext;
            }
        }
 }
 void sortNAME()
 {
     int i;
     int count3=1;
     currentptr=ptrhead;
     while(currentptr->ptrnext!=NULL)
     {
        count3++;
        currentptr=currentptr->ptrnext;
     }
        for(i=1;i<count3;i++)
        {
            currentptr=ptrhead;
            ptrprev=currentptr;
            ptrassist=currentptr->ptrnext;
            if(strcmp(currentptr->patient.name,ptrassist->patient.name)>0)
            {
                currentptr->ptrnext=ptrassist->ptrnext;
                ptrhead=ptrassist;
                ptrassist->ptrnext=currentptr;
            }
            currentptr=ptrhead->ptrnext;
            ptrassist=currentptr->ptrnext;
            ptrprev=ptrhead;
            while(currentptr->ptrnext!=NULL)
            {
                if(strcmp(currentptr->patient.name,ptrassist->patient.name)>0)
                {
                    currentptr->ptrnext=ptrassist->ptrnext;
                    ptrprev->ptrnext=ptrassist;
                    ptrassist->ptrnext=currentptr;
                }
                ptrprev=ptrprev->ptrnext;
                currentptr=ptrprev->ptrnext;
                ptrassist=currentptr->ptrnext;
            }
        }
 }
 void display1()
 {
    currentptr=ptrhead;
        printf("\n\n");
        printf("\n------------------------------------------------------");
        printf("\n\t\tPATIENT INFORMATION");
        printf("\n------------------------------------------------------");
   do
    {
        printf("\n\nPatient ID:%d",currentptr->patient.patientID);
        printf("\n\nNAME:%s", currentptr->patient.name);
        printf("\n\nNO IC:%d",currentptr->patient.NoIc);
        printf("\n\nAGE:%d", currentptr->patient.age);
        printf("\n\nBIRTH OF DATE:%s", currentptr->patient.dob);
        printf("\n\nRACE:%s", currentptr->patient.race);
        printf("\n\nSEX:%c", currentptr->patient.sex);
        printf("\n\nSTATUS:%s", currentptr->patient.status);
        printf("\n\nEMAIL:%s", currentptr->patient.email);
        printf("\n\nADDRESS:%s", currentptr->patient.ptient.addr);
        printf("\n\nPOSTCODE:%d", currentptr->patient.ptient.postcode);
        printf("\n\nSTATE:%s", currentptr->patient.ptient.state);
        printf("\n\nFor Emergency:");
        printf("\n\nFATHER NAME:%s",currentptr->patient.father.name);
        printf("\n\nFATHER NO PHONE:%s", currentptr->patient.father.phone);
        printf("\n\nMOTHER NAME:%s", currentptr->patient.mother.name);
        printf("\n\nMOTHER NO PHONE:%s", currentptr->patient.mother.phone);
        printf("\n");
        printf("\n\n------------------------------------------------------\n");
        currentptr=currentptr->ptrnext;
    }while(currentptr!=NULL);
    printf("\n\n");
}
void displaypatient()
{
        printf("\n\n");
        printf("\n------------------------------------------------------");
        printf("\n\t\tPATIENT INFORMATION");
        printf("\n------------------------------------------------------");
        printf("\nPatient ID:%d", newptr->patient.patientID);
        printf("\n\nNAME:%s", newptr->patient.name);
        printf("\n\nNO IC:%d", newptr->patient.NoIc);
        printf("\n\nAGE:%d", newptr->patient.age);
        printf("\n\nBIRYH OF DATE:%s", newptr->patient.dob);
        printf("\n\nRACE:%s", newptr->patient.race);
        printf("\n\nSEX:%c", newptr->patient.sex);
        printf("\n\nSTATUS:%s", newptr->patient.status);
        printf("\n\nEMAIL:%s", newptr->patient.email);
        printf("\n\nADDRESS:%s", newptr->patient.ptient.addr);
        printf("\n\nPOSTCODE:%d", newptr->patient.ptient.postcode);
        printf("\n\nSTATE:%s", newptr->patient.ptient.state);
        printf("\n\nFor Emergency:");
        printf("\n\nFATHER NAME:%s", newptr->patient.father.name);
        printf("\n\nFATHER NO PHONE:%s", newptr->patient.father.phone);
        printf("\n\nMOTHER NAME:%s", newptr->patient.mother.name);
        printf("\n\nMOTHER NO PHONE:%s", newptr->patient.mother.phone);
        printf("\n");
        printf("------------------------------------------------------\n");
}
void update ()
{
    int searchId;
    char choice;
    printf("Enter you patient ID:");
    scanf("%d", &searchId);
    currentptr=ptrhead;
    while(currentptr!=NULL)
    {
        if(currentptr->patient.patientID==searchId)
        {
            while(choice!='X')
            {
                printf("\n\n******** CHOOSE TO UPDATE ITEM BELOW ******** ");
                printf("\n\nN- NAME");
                printf("\nP- PHONE NUMBER");
                printf("\nT- ADDRESS");
                printf("\nX- EXIT");
                printf("\nEnter your choice:");
                scanf(" %c", &choice);
                ch=toupper(ch);
                switch(choice)
                {
                    case'N':    printf("\nEnter your name:");
                                scanf(" %[^\n]s", currentptr->patient.name);
                                printf("Updated successful!\n\n");
                                break;
                    case'T':
                        printf("\nEnter your address:");
                        scanf(" %[^\n]s", currentptr->patient.ptient.addr);
                        printf("\nEnter you state:");
                        scanf(" %[^\n]s", currentptr->patient.ptient.state);
                        printf("\nEnter postcode :");
                        scanf(" %d", &currentptr->patient.ptient.postcode);
                        printf("Updated successfully!\n\n");
                        break;
                    case'P':
                        printf("\nEnter your No telephone:");
                        scanf(" %s", currentptr->patient.mobile);
                        printf("Updated successful!\n\n");
                        break;
                    case'X':break;
                }
            }
            return;
        }
        else currentptr=currentptr->ptrnext;
    }
    if(currentptr==NULL)
        printf("No search found! \n");
}
void deleteinfo()
{
    int searchDelete;
    if (ptrhead==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nEnter Patient ID:");
        scanf(" %d", &searchDelete);
        currentptr=ptrhead;
        ptrprev=ptrhead;
        if(currentptr->patient.patientID==searchDelete)
        {
            ptrhead=currentptr->ptrnext;
            free(currentptr);
            printf("Patient Information Deleted Successfully!\n\n");
        }
        else
        {
            while(currentptr->ptrnext!=NULL)
            {
                ptrprev=currentptr;
                currentptr=currentptr->ptrnext;
                if(currentptr->patient.patientID==searchDelete)
                {
                    ptrprev->ptrnext=currentptr->ptrnext;
                    free(currentptr);
                    printf("Patient Information Deleted Successfully!\n\n");
                    break;
                }
            }
         if(currentptr->ptrnext=NULL)
            printf("No search found!\n\n");
        }
    }
}
void appointment()
{
	do
	{
		printf("\n\n********** QUEUE MENU **********");
		printf("\nA - ENQUEUE");
		printf("\nB - DEQUEUE");
		printf("\nD - DISPLAY APPOINTMENT QUEUE CONTENT");
		printf("\nX - EXIT MENU");
		printf("\nPLEASE ENTER YOUR CHOICE: ");
		scanf(" %c",&ch);
		ch=toupper(ch);
		switch (ch)
		{
		case 'A':printf("\nPlease enter the patient ID to insert into appointment queue: ");
				  scanf("%d",&item);
				  enqueue(item);
				  break;
		case 'B':printf("\nDelete the queue");
				  dequeue();
				  break;
		case 'D':display();
				  break;
		case 'X':printf("\nExit queue menu");
				  break;
		default: printf("\nInvalid entry. Please select 'A','B','C','D','X'\n");
		}
	}while (ch!='X');
}
void enqueue(int item)
{
	if(count==MAXQUEUE)
	{
	printf("\n!!! Appointment Queue OVERFLOW - can't insert into queue !!!");
	}
	else
	{
        currentptr=ptrhead;
        while(currentptr!=NULL)
        {
               if(currentptr->patient.patientID==item)
                    {
                        rear=(rear+1)%MAXQUEUE;
                        count++;
                        queue[rear]=item;
                        display();
                        break;
                    }
                else currentptr=currentptr->ptrnext;
        }
        if(currentptr==NULL)
            printf("No patient ID found! \n\n");
	}
}
void dequeue()
{
	if (count==0)
	{
	printf("\n!!! Appointment Queue UNDERFLOW - can't delete queue !!!");
	}
	else
	{
		front=(front+1)%MAXQUEUE;
		count--;
	}
   display();
}
void display()
{
	int i=front;
	int j=count;
	printf("\n\nContent of appointment queue: ");
	if(count==0)
	printf("\nThe queue is empty");
	else
	{
		while (j!=0)
		{
			printf("%d \t",queue[i]);
			i=(i+1)%MAXQUEUE;
			j--;
		}
	}
}
void medicine()
{
    int searchId;
    int sizemedicine;
    printf("\nEnter Patient ID:");
    scanf(" %d", &searchId);
    currentptr=ptrhead;
    while(currentptr!=NULL)
    {
        if(currentptr->patient.patientID==searchId)
        {

            printf("\nEnter  the amount of different type medicine:");
            scanf("%d", &sizemedicine);
            amt_medicine(sizemedicine);
            display_receipt(sizemedicine);
            return;
        }
        else currentptr=currentptr->ptrnext;
    }

    if(currentptr==NULL)
        printf("No search found! \n");
}
void amt_medicine(int sizeM)
{
    if(i<sizeM)
    {
        printf("\n%d)", i+1);
        printf("\nEnter medicine name:");
        scanf(" %[^\n]s", &name[i]);
        printf("\n\nEnter price the medicine:");
        scanf("%f", &price[i]);
        printf("\n\nEnter how many capsule:");
        scanf(" %d", &capsule[i]);
        i++;
        return(amt_medicine(sizeM));
    }
}
void display_receipt(int sizemedicine)
{
    float totalprice=0,total[100];
    int j=0, k=0;

    FILE *receipt= fopen("Receipt Medicine.txt", "w");
    fprintf(receipt,"\n");
    fprintf(receipt,"\n----------------------------------------------------------------------------");
    fprintf(receipt,"\n\t\tThe Receipt Of Medicine");
    fprintf(receipt,"\n----------------------------------------------------------------------------");
    fprintf(receipt,"\nNo\tItem\t\tQty\t\t\tPrice");
    while(j<sizemedicine)
        {
            fprintf(receipt,"\n%d", j+1);
            fprintf(receipt,"\t%s", name[j]);
            fprintf(receipt,"\t\t%d", capsule[j]);
            total[j]=price[j]*capsule[j];
            fprintf(receipt,"\t\t\t%.2f", total[j]);
            totalprice=totalprice+total[j];
            j++;
        }
    fprintf(receipt,"\n-----------------------------------------------------------------------------");
    fprintf(receipt,"\nTotal:\t\t\t\t\t %.2f", totalprice);

    printf("\n");
    printf("\n----------------------------------------------------------------------------");
    printf("\n\t\tThe Receipt Of Medicine");
    printf("\n----------------------------------------------------------------------------");
    printf("\nNo\tItem\t\tQty\t\t\tPrice");
    while(j<sizemedicine)
        {
            printf("\n%d", j+1);
            printf("\t%s", name[j]);
            printf("\t\t%d", capsule[j]);
            total[j]=price[j]*capsule[j];
            printf("\t\t\t%.2f", total[j]);
            totalprice=totalprice+total[j];
            j++;
        }
    printf("\n-----------------------------------------------------------------------------");
    printf("\nTotal:\t\t\t\t\t %.2f", totalprice);
    printf("\n\n");
    fclose(receipt);
}
