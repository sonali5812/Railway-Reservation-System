#include <stdio.h>
#include <stdlib.h>
#include"rlyres.h"
#include"conio2.h"
#include<string.h>

int main()
{
    int choice;int  ticket_number;
    int ticket_no1;
    add_train();
    Passenger *ptr;
    Passenger psn;
    int i;
    while(1)
    {
       // fflush(stdin);       //
        clrscr();
        choice= enterchoice();
    switch(choice)
    {
    case 1:
        clrscr();
        view_train();
        break;
    case 2:
        clrscr();
        ptr=get_passenger_details();
        if(ptr!=NULL)
        {
        ticket_no1=book_ticket(*ptr);
        if(ticket_no1==0)
        {
            gotoxy(1,29);textcolor(GREEN);
            printf("SEATS NOT AVAILABLE\n");
            textcolor(WHITE);printf("ENTER ANY TO RETURN TO MAIN SCREEN");
            getch();clrscr();break;
        }
        gotoxy(1,28);textcolor(GREEN);
        printf("!!BOOKING SUCCESSFULL!!\n");
        printf("Ticket no. is:%d\n",ticket_no1);textcolor(WHITE);
        printf("ENTER ANY TO RETURN TO MAIN SCREEN");
        getch();
        clrscr();
        }
        break;
    case 3:

        while(1)
        {   char arr[10];
            clrscr();
            gotoxy(95,2);
            textcolor(LIGHTGREEN);
            printf("Press 0 to exit");
             textcolor(YELLOW);
             gotoxy(1,2);printf("ENTER TICKET NO. TO SEE THE DETAILS:");
             scanf("%s",arr);ticket_number=atoi(arr);
             if(arr[0]=='0')
              {
                  gotoxy(1,30);
                  textcolor(GREEN);
                  printf("!!ENTER ANY KEY TO RETURN TO  MAIN SCREEN!!");
                  getch();
                  textcolor(YELLOW);clrscr();
                  break;
              }
             else if(1<=ticket_number && ticket_number<=20)
                {view_ticket(ticket_number);}
             else
                {  gotoxy(1,30);
                  textcolor(GREEN);
                  printf("!!ENTER ANY VALID INTEGER ONLY!!");getch();clrscr();
                }

        }
        break;

    case 4:              //take mobile no...........................
        clrscr();
        while(1)
        {
            gotoxy(100,2);
            textcolor(LIGHTGREEN);
            printf("Press 0 to exit");
            char ss[11];
            textcolor(YELLOW);  gotoxy(1,2);
            printf("Enter mobile no:");t:
            fflush(stdin);
            fgets(ss,11,stdin);
            char*s=strchr(ss,'\n');
            if(s!=NULL)
            *s='\0';
            if(strcmp(ss,"0")==0)
            {
                gotoxy(1,30);
                textcolor(GREEN);
                printf("!!ENTER ANY KEY TO RETURN TO  MAIN SCREEN!!");
                getch();
                textcolor(YELLOW);clrscr();
                break;
            }
            if(!check_mobile_no(ss))
            {
                gotoxy(1,30);printf("please enter valid mobile no only");
                getch();gotoxy(1,30);printf("\t\t\t\t\t");
                gotoxy(17,2);printf("\t\t\t"); gotoxy(17,2);
                goto t;
            }
            get_ticket_no(ss);
        }
        break;
    case 5:
        clrscr();
        textcolor(YELLOW);
        view_all_booking();
        textcolor(WHITE);gotoxy(1,29);
        printf("Press any key to navigate to main screen");
        textcolor(YELLOW);
        getch();
        break;
    case 6:
        clrscr();
        while(1)
        {
        gotoxy(100,2);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);  gotoxy(1,2);
        char r[10];printf("ENTER THE TRAIN NO.: ");b:
        scanf("%s",r);
        if(r[0]==48)
            {
                gotoxy(1,30);
                textcolor(LIGHTGREEN);
                printf("!!ENTER ANY KEY TO RETURN TO  MAIN SCREEN!!");
                getch();
                textcolor(YELLOW);clrscr();
                break;
            }
        if(!check_train_no(r))
            {
                 gotoxy(1,30);printf("please enter valid train no only");
                getch();gotoxy(1,30);printf("\t\t\t\t\t");
                gotoxy(21,2);printf("\t\t\t"); gotoxy(21,2);goto b;
            }

        view_booking(r);
        }
        break;
    case 7:
        clrscr();
        while(1)
        {
        textcolor(YELLOW);int i,tk;
        gotoxy(100,2);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);
        gotoxy(1,2);
        printf("Enter the ticket you wants to cancel=");printf("\t\t\t\t");gotoxy(38,2);scanf("%d",&tk);
        if(tk==0)
        {
             gotoxy(1,29);
               textcolor(LIGHTGREEN);
               printf("!!ENTER ANY KEY TO RETURN TO  MAIN SCREEN!!");
               getch();clrscr();
            break;
        }
        i=cancel_ticket(tk);
        if(i==0)
           {
                gotoxy(1,29);
               textcolor(LIGHTGREEN);
               printf("No bookings done yet");textcolor(WHITE);
               printf("PRESS ANY KEY TO ENTER ANOTHER TICKET NO..");
               getch();clrscr();
           }
        else if(i==1)
           {
               gotoxy(1,3);
               textcolor(LIGHTGREEN);gotoxy(1,29);
               printf("Cancellation Successful");textcolor(WHITE);
               printf("PRESS ANY KEY TO ENTER ANOTHER TICKET NO..");
               getch();clrscr();
           }
        else
           {
                gotoxy(1,29);
               textcolor(LIGHTGREEN);
               printf("No such Ticket No. Found!");textcolor(WHITE);
               printf("PRESS ANY KEY TO ENTER ANOTHER TICKET NO..");
               textcolor(YELLOW);
               getch();clrscr();
           }
        }
        break;
    case 8:
        clrscr();
        while(1)
        {
        char train[10];
        gotoxy(100,2);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);bm:
        gotoxy(1,2);  printf("ENTER THE TRAIN NO.: ");
        scanf("%s",train);
         if(train[0]==48)
            {
                gotoxy(1,30);
                textcolor(LIGHTGREEN);
                printf("!!ENTER ANY KEY TO RETURN TO  MAIN SCREEN!!");
                getch();
                textcolor(YELLOW);clrscr();
                break;
            }
        if(!check_train_no(train))
        {
                gotoxy(1,30);textcolor(WHITE);printf("please enter valid train no only");textcolor(YELLOW);
                getch();gotoxy(1,30);printf("\t\t\t\t\t");
                gotoxy(21,2);printf("\t\t\t\t\t\t"); gotoxy(21,2);goto bm;
        }
        if(train==NULL)
            break;
        else
        {
            i=cancel_train(train);
            if(i==0)
            {
                textcolor(LIGHTGREEN);gotoxy(1,29);
                printf("!!No Bookings Done Yet!!");
                getch();clrscr();
            }
            else
            {
                textcolor(LIGHTGREEN);gotoxy(1,29);
                printf("!!!Cancellation Successful!!");
                getch();clrscr();
                textcolor(YELLOW);
            }
        }
        }
        break;
    case 9:
        exit(0);
    default:
        gotoxy(1,30);
        textcolor(WHITE);
        printf("Please enter the correct no.");getch();
    }
    }
    return 0;
}
