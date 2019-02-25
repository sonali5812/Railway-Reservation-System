#include<stdio.h>
#include "conio2.h"
#include "rlyres.h"
#include<ctype.h>
#include<string.h>

int enterchoice()                                         //it return selected integer.
{
    int i;int choice;
    textcolor(YELLOW);
    gotoxy(45,2);
    printf("RAILWAY RESERVATION SYSTEM");
    printf("\n");
    for(i=0;i<=59;i++)
    {
        printf("_ ");
    }
    printf("\nSelect an option\n");
    printf("\n1- View train\n2- Book ticket\n3- View ticket\n4- Search ticket no.\n5- View all bookings\n6- View train booking\n7- Cancel ticket\n8- Cancel train\n9- Quit");
    printf("\n\nEnter choice:- ");//printf("      ");printf("\b\b\b\b\b\b");
    scanf("%d",&choice);
    return choice;
}


void add_train()                                          //to add trains in train.dat
{
    FILE *fp;
    fp=fopen("D:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[7]=
        {
        {"123","BPL","GWL",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1153},
        {"896","HBJ","MUM",4500,3360},
        {"786","JHS","BPL",1200,1000},
        {"555","PHB","BSB",1600,1400},
        {"167","GWL","BSB",2800,2200}
        };
    fp=fopen("D:\\myproject\\alltrains.dat","wb");
    fwrite(alltrains,7*sizeof(Train),1,fp);
    printf("File saved successfully\n");
    fclose(fp);
    }
    else
    {
        printf("File Already present\n");
        fclose(fp);
    }
}


void view_train()                                         // 1 option to view train
{
    int i;textcolor(YELLOW);
    gotoxy(45,2);
    printf("RAILWAY RESERVATION SYSTEM");printf("\n");
    for(i=0;i<=59;i++)
    {
        printf("__");
    }
    gotoxy(2,6);
    printf("TRAIN NO");
    gotoxy(27,6);
    printf("FROM");
    gotoxy(57,6);
    printf("TO");
    gotoxy(82,6);
    printf("FIRST AC FAIR");
    gotoxy(107,6);
    printf("SECOND AC FAIR\n");
    printf("\n\n");
    gotoxy(1,7);
    for(i=0;i<=59;i++)
    {
        printf("* ");
    }
    Train t;
    FILE *fp;
    int x=8;

    fp=fopen("D:\\myproject\\alltrains.dat","rb");
    while(fread(&t,sizeof(Train),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",t.train_no);
        gotoxy(28,x);
        printf("%s",t.from);
        gotoxy(57,x);
        printf("%s",t.to);
        gotoxy(85,x);
        printf("%d",t.fac_fare);
        gotoxy(115,x);
        printf("%d",t.sac_fare);
        x+=2;
    }
    printf("\n");
    gotoxy(1,30);
    textcolor(WHITE);
    printf("PRESS ANY KEY TO RETURN TO MAIN SCREEN");
    getch();clrscr();
    fclose(fp);
}


int*get_ticket_no(char*mob_no)                              //take mobile no.and show the respective ticket
{
    FILE *fp;
    int count=0;
    int flag=0;
    Passenger psn;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    gotoxy(1,2);
    while(fread(&psn,sizeof(psn),1,fp)==1)
    {

        if(strcmp(psn.mobile_no,mob_no)==0)
        {
            count++;
            flag=1;
            printf("\nTicket No. %d is : %d  ",count,psn.ticketno);
        }
    }
    if(flag==0)
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("No record found for this mobile no.");
        textcolor(YELLOW);
        getch();clrscr();
        return;
    }
    gotoxy(1,2);
    printf("You have total %d bookings for the mobile no. %s",count,mob_no);gotoxy(1,29);textcolor(WHITE);
    printf("PRESS ANY KEY TO ENTER ANOTHER MOBILE NO.");
    //gotoxy(1,count+3);
    getch();clrscr();
    fclose(fp);
}


void view_booking(char *rr)                         //6
{
   int flag=0;
    FILE*fp;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fp==NULL)
    {
        gotoxy(1,30);
        textcolor(LIGHTGREEN);
        printf("No Bookings done in this train yet");getch();
        textcolor(YELLOW);clrscr();

        fclose(fp);
        return;
    }
    Passenger paa;

    while(fread(&paa,sizeof(paa),1,fp)==1)
    {
        if(strcmp(paa.train_no,rr)==0 )
        {   flag++;
            textcolor(YELLOW);
            printf("\nTICKET NO.: %d\n",paa.ticketno);
            printf("NAME: %s\n",paa.p_name);
            printf("GENDER: %c\n",paa.gender);
            printf("TRAIN NO.: %s\n",paa.train_no);
            printf("CLASS: %c\n",paa.p_class);
            printf("ADDRESS: %s\n",paa.address);
            printf("AGE: %d\n",paa.age);
            printf("MOBILE NO.: %s\n\n",paa.mobile_no);
        }

    }
    textcolor(WHITE);
    printf("ENTER ANY KEY FOR ANOTHER TRAIN NO.");

    if(flag==0)
    {
        gotoxy(1,3);printf("\t\t\t\t\t\t");     // this line is for removing above printf statment............
        gotoxy(1,29);
        textcolor(LIGHTRED);
        printf("TRAIN HAVE NOT BOOKING YET!\n");
        textcolor(WHITE);
        printf("ENTER ANY KEY FOR ANOTHER TRAIN NO."); textcolor(YELLOW);
    }
    fclose(fp);
    getch();clrscr();return;
}


void view_all_booking()              //5
{
    clrscr();
    Passenger paa;
    FILE*fp;int j=8;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fread(&paa,sizeof(paa),1,fp)==0)                     //if open
    {gotoxy(1,28);printf("NO BOOKING DONE YET!!");return;}
     int i;textcolor(YELLOW);
    gotoxy(45,2);
    printf("RAILWAY RESERVATION SYSTEM");printf("\n");
    for(i=0;i<=59;i++)
    {
        printf("__");
    }
    gotoxy(1,6);
    printf("Ticket no.");
    gotoxy(18,6);
    printf("NAME");
    gotoxy(40,6);
    printf("ADDRESS");
    gotoxy(60,6);
    printf("CLASS");gotoxy(80,6);
    printf("TRAIN NO.");
    gotoxy(107,6);
    printf("mobile no\n");
    printf("\n\n");
    gotoxy(1,7);
    for(i=0;i<=59;i++)
    {
        printf("* ");
    }


    if(fp==NULL)
    {
       gotoxy(1,29);
       textcolor(WHITE);
       printf("!!NO RESERVATION YET!!\n");
       printf("ENTER ANY KEY TO RETURN");fclose(fp);getch();clrscr();return;
    }
    textcolor(YELLOW);
        gotoxy(1,j);
        printf("%d",paa.ticketno);
        gotoxy(18,j);
        printf("%s",paa.p_name);
        gotoxy(33,j);
        printf("%s",paa.address);
        gotoxy(60,j);
        printf("%c",paa.p_class);
        gotoxy(80,j);
        printf("%s",paa.train_no);
        gotoxy(107,j);
        printf("%s",paa.mobile_no);
        printf("\n\n");j=j+2;
    while(fread(&paa,sizeof(paa),1,fp)==1)
    {

        textcolor(YELLOW);
        gotoxy(1,j);
        printf("%d",paa.ticketno);
        gotoxy(18,j);
        printf("%s",paa.p_name);
        gotoxy(33,j);
        printf("%s",paa.address);
        gotoxy(60,j);
        printf("%c",paa.p_class);
        gotoxy(80,j);
        printf("%s",paa.train_no);
        gotoxy(107,j);
        printf("%s",paa.mobile_no);
        printf("\n\n");
        j=j+2;
    }
    fclose(fp);
    return;
}

int book_ticket(Passenger pp)                 //2
{
    int v;int rohanjain;
    v=get_booked_ticket_count(pp.train_no,pp.p_class);
    FILE*fp=fopen("D:\\myproject\\ticketbookingdetails.txt","ab+");
    if(v==-1)
    {
        pp.ticketno=1;
        fwrite(&pp,sizeof(Passenger),1,fp);
        fclose(fp);
        return 1;
    }
    else if(v==0)
    {
        fclose(fp);
        return 0;
    }
    else
    {
        int ticket;
        ticket=last_ticket_no();
        pp.ticketno=ticket+1;
        fwrite(&pp,sizeof(Passenger),1,fp);
        fclose(fp);
        return ticket+1;
    }
}


int last_ticket_no()                        //2
{
    Passenger psn;
    FILE *fp;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,-1*sizeof(Passenger),SEEK_END);
    fread(&psn,sizeof(Passenger),1,fp);
    int last_ticket;
    last_ticket=psn.ticketno;
    fclose(fp);
    return last_ticket;
}


int get_booked_ticket_count(char *trainnoo,char classs)                 //2
{
    int count=0;
    FILE*fp; Passenger passen;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fp==NULL || fread(&passen,sizeof(passen),1,fp)==0)
    {
        fclose(fp);
        return -1;
    }

    while(fread(&passen,sizeof(passen),1,fp)==1)
    {
        if(strcmp(passen.train_no,trainnoo)==0 && classs==passen.p_class)
        {
            count++;
        }
    }
    if(count>=2)
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}


int check_train_no(char*trainno)                                  //CAN VERIFY THE TRAIN NO.
{
    FILE*fp;
    fp=fopen("D:\\myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);return 1;
        }
    }
    fclose(fp);
    return 0;
}

void view_ticket(int ss)                                          //3 option to view
{
    int w;Passenger paa;
    FILE*fp;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fp==NULL)
    {
       gotoxy(1,29);
       textcolor(WHITE);
       printf("!!NO RESERVATION YET!!\n");
       printf("ENTER ANY KEY TO RETURN");getch();
       clrscr();return;

    }
    while(fread(&paa,sizeof(paa),1,fp)==1)
    {
        if(paa.ticketno==ss)
        {
            gotoxy(1,4);
            textcolor(YELLOW);
            printf("NAME: %s\n",paa.p_name);
            printf("GENDER: %c\n",paa.gender);
            printf("TRAIN NO.: %s\n",paa.train_no);
            printf("CLASS: %c\n",paa.p_class);
            printf("ADDRESS: %s\n",paa.address) ;
            printf("AGE: %d\n",paa.age);
            printf("MOBILE NO.: %s\n",paa.mobile_no);
            printf("TICKET NO.: %d\n",paa.ticketno);

            FILE*fpp;
            fpp=fopen("D:\\myproject\\alltrains.dat","rb");
            Train trr;
            while(fread(&trr,sizeof(trr),1,fpp)==1)
            {
            if(strcmp(trr.train_no,paa.train_no)==0&&paa.p_class=='f')
            {
                printf("FROM: %s\n",trr.from);
                printf("TO: %s\n",trr.to);
                printf("FARE: %d\n",trr.fac_fare);
                fclose(fpp);
            }
            else if(strcmp(trr.train_no,paa.train_no)==0&&paa.p_class=='s')
            {
                printf("FROM: %s\n",trr.from);
                printf("TO: %s\n",trr.to);
                printf("FARE: %d\n",trr.sac_fare);
                fclose(fpp);
            }
            }
            fclose(fpp);
            gotoxy(1,30);
            textcolor(WHITE);
            printf("PRESS ENTER TO VIEW THE DETAILS OF ANOTHER TICKET");getch();clrscr();

            fclose(fp);
            return;
        }
    }
        gotoxy(1,29);
        textcolor(WHITE);
        printf("!!NO RESERVATION YET!!\n");
        printf("ENTER ANY KEY TO RETURN");getch(); gotoxy(1,29);printf("\t\t\t\t\t\t\n");
        printf("\t\t\t\t");gotoxy(37,2);printf("\t\t\t\t\t");gotoxy(37,2);
        d:fclose(fp);
}


Passenger* get_passenger_details()
{
   // static int pa=0;
    int i;static Passenger psn;
    gotoxy(100,2);
    textcolor(WHITE);
    printf("PREES 0 TO EXIT");
    gotoxy(1,2);
    textcolor(YELLOW);
    printf("ENTER PASSENGER NAME:");r:
    fflush(stdin);
    fgets(psn.p_name,30,stdin);
    char*p=strchr(psn.p_name,'\n');
    *p='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,30);
        textcolor(GREEN);
        printf("RESERVATION CANCELLED!");
        getch();
        textcolor(YELLOW);clrscr();
        return NULL;
    }
   if(psn.p_name[0]<=65)                     //   \n\n-------\0\n by strchr()
    {
        gotoxy(1,30);printf("please enter some character");getch();gotoxy(1,30);printf("\t\t\t\t");
        gotoxy(22,2);printf("\t\t\t"); gotoxy(22,2);
        goto r;
    }
    for(i=0;i<30;i++)
    {
        if(1<=psn.p_name[i]&&psn.p_name[i]<=57)
        {   gotoxy(1,30);printf("please enter character only");getch();gotoxy(1,30);printf("\t\t\t\t");
            gotoxy(22,2);printf("\t\t\t"); gotoxy(22,2);
            goto r;
        }
    }

    gotoxy(1,4);
    printf("ENTER GENDER:");
    a:
    fflush(stdin);
    scanf("%c",&psn.gender);
    if(psn.gender=='0')
    {
    gotoxy(1,30);
    textcolor(GREEN);
    printf("RESERVATION CANCELLED!");
    getch();
    textcolor(YELLOW);clrscr();
    return NULL;
}
if(psn.gender!='m' && psn.gender!='M' && psn.gender!='f' && psn.gender!='F')  //if character is not equals to any of them.....
{
    gotoxy(1,30);printf("please enter valid character only!");getch();gotoxy(1,30);
    printf("\t\t\t\t\t");
    gotoxy(14,4);printf("\t\t\t"); gotoxy(14,4);
    goto a;
}

    gotoxy(1,6);
    textcolor(YELLOW);
    printf("ENTER ADDRESS OF PASSENGER:");m:
    fflush(stdin);
    fgets(psn.address,30,stdin);
    char*q=strchr(psn.address,'\n');
    *q='\0';
    if(strcmp(psn.address,"0")==0)
    {
        gotoxy(1,30);
        textcolor(GREEN);
        printf("RESERVATION CANCELLED!");
        getch();
        textcolor(YELLOW);clrscr();
        return NULL;
    }
    if(psn.address[0]<=48)                         //   \n\n----\0\n by strchr()
    {
        gotoxy(1,30);printf("please enter valid address");getch();gotoxy(1,30);printf("\t\t\t\t");
        gotoxy(28,6);printf("\t\t\t"); gotoxy(28,6);
        goto m;
    }


    int e;char rohan[30];
    gotoxy(1,8);
    textcolor(YELLOW);
    printf("ENTER AGE OF PASSENGER:");y:

    fflush(stdin);
    fgets(rohan,30,stdin);
    char*s=strchr(rohan,'\n');
    *s='\0';
    if(strcmp(rohan,"0")==0)
    {
        gotoxy(1,30);
        textcolor(GREEN);
        printf("RESERVATION CANCELLED!");
        getch();
        textcolor(YELLOW);clrscr();
        return NULL;
    }
    if(rohan[0]>=65||rohan[1]>=65||rohan[2]!='\0')
    {
        gotoxy(1,30);printf("please enter valid integer only");getch();gotoxy(1,30);printf("\t\t\t\t");
        gotoxy(24,8);printf("\t\t\t"); gotoxy(24,8);
        goto y;
    }
    psn.age=atoi(rohan);


    gotoxy(1,10);
    textcolor(YELLOW);
    printf("ENTER TRIAN NO.:");z:
    fflush(stdin);
    fgets(psn.train_no,20,stdin);
    char*r=strchr(psn.train_no,'\n');
    *r='\0';

    if(strcmp(psn.train_no,"0")==0)
    {
        gotoxy(1,30);
        textcolor(GREEN);
        printf("RESERVATION CANCELLED!");
        getch();
        textcolor(YELLOW);clrscr();
        return NULL;
    }
    if(!check_train_no(psn.train_no))
    {
        gotoxy(1,30);printf("please enter valid train no only");getch();gotoxy(1,30);printf("\t\t\t\t");
        gotoxy(17,10);printf("\t\t\t"); gotoxy(17,10);
        goto z;
    }


    gotoxy(1,12);
    printf("ENTER CLASS:");aa:fflush(stdin);
    scanf("%c",&psn.p_class);
    if(psn.p_class=='0')
    {
        gotoxy(1,30);
        textcolor(GREEN);
        printf("RESERVATION CANCELLED!");
        getch();
        textcolor(YELLOW);clrscr();
        return NULL;
    }

    if(psn.p_class!='s' && psn.p_class!='S' && psn.p_class!='f' && psn.p_class!='F')
    {
        gotoxy(1,30);printf("please enter valid class F and S only!");getch();gotoxy(1,30);
        printf("\t\t\t\t\t");
        gotoxy(13,12);printf("\t\t\t"); gotoxy(13,12);
        goto aa;
    }


    gotoxy(1,14);
    textcolor(YELLOW);
    printf("Enter mobile no:");t:
    fflush(stdin);
    fgets(psn.mobile_no,11,stdin);
    char*ss=strchr(psn.mobile_no,'\n');
    if(ss!=NULL)
        *ss='\0';
    if(strcmp(psn.mobile_no,"0")==0)
    {
        gotoxy(1,30);
        textcolor(GREEN);
        printf("RESERVATION CANCELLED!");
        getch();
        textcolor(YELLOW);clrscr();
        return NULL;
    }
    if(!check_mobile_no(psn.mobile_no))
    {
        gotoxy(1,30);printf("please enter valid mobile no only");getch();gotoxy(1,30);printf("\t\t\t\t\t");
        gotoxy(17,14);printf("\t\t\t"); gotoxy(17,14);
        goto t;
    }
return &psn;
}


int check_mobile_no(char*ro)
{
    if(strlen(ro)!=10)
    return 0;
    int i;
    for(i=0;i<10;i++)
    {
        if(!isdigit(ro[i]))
        return 0;
    }
    return 1;
}



int cancel_ticket(int ticket)
{
    FILE *fp,*t_file;
    Passenger psn;
    int flag=0;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    t_file=fopen("D:\\myproject\\temp.dat","wb");
    while(fread(&psn,sizeof(Passenger),1,fp)==1)
    {
        if(ticket!=psn.ticketno)
        {
            fwrite(&psn,sizeof(Passenger),1,t_file);
        }
        else
        {
           flag=1;
        }
    }
            fclose(fp);
            fclose(t_file);
    if(flag==1)
    {
            remove("D:\\myproject\\ticketbookingdetails.txt");
            rename("D:\\myproject\\temp.dat","D:\\myproject\\ticketbookingdetails.txt");
            return 1;
    }
    else
        {
            remove("D:\\myproject\\temp.dat");
            return -1;
        }
}



int cancel_train(char *train_no)
{
    FILE *fp,*t_file;
    Passenger psn;
    int flag=0;
    fp=fopen("D:\\myproject\\ticketbookingdetails.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    t_file=fopen("D:\\myproject\\temp.dat","wb");
    while(fread(&psn,sizeof(Passenger),1,fp)==1)
    {
        if(strcmp(psn.train_no,train_no)!=0)
        {
            fwrite(&psn,sizeof(Passenger),1,t_file);
        }
        else
        {
           flag=1;
        }
    }
            fclose(fp);
            fclose(t_file);
    if(flag==1)
    {
            remove("D:\\myproject\\ticketbookingdetails.txt");
            rename("D:\\myproject\\temp.dat","D:\\myproject\\ticketbookingdetails.txt");
            return 1;
    }
    else
        {
            remove("D:\\myproject\\temp.dat");
            return 0;
        }
}










