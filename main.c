#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void inititate();void functoss();int setbatsman(char *);void choosebatsman();void boundarycount();void overinprogress();void entries();void update(int);
void changestrike();void reqrunrate();void currentrunrate(int);void fallofwickets(int,int);void displayfow();void venuedetails();
void battingcard_aus();void battingcard_ind();void bowlingcard_aus();void bowlingcard_ind();void display();void superover();void end();
int choice,t1,overnumber=0,striker,nonstriker,bowler,option,temp,austotal=0,indtotal=0,innings,score,total,wkc,bcount,indbcount=0,ausbcount=0,balls;
float rrr;//variable to store current run rate
struct player//structure to store player information
{
    char name[25],onfield,ONO[6],MOD[20];
    int overs,extras,wickets,maidens,runsconceded,runsscored,ballsfaced,boundaries,ballsbowled;
    float eco,SR;
}P[22],c1,c2,c3,b1;
struct over//structure to store runs/wickets ball by ball
{
    int eachball[7];
}o[4];
struct fow //structure to store fall of wickets
{
    int runs,wkts;
}ind[10],aus[10];
struct details //structure to store venue details
{
char city[15],stadium[50],pitch[25];
    int seatcap,matplay,winsb1,winsb2,draws,avgblength;
};
void initiate()//function to initiate player details at the start of normal match and super over
{
    int i;
    strcpy(P[0].name,"Rohit Sharma");
    strcpy(P[1].name,"Shikhar Dhawan");
    strcpy(P[2].name,"Virat Kohli(c)");
    strcpy(P[3].name,"Shreyas Iyer");
    strcpy(P[4].name,"MS Dhoni(wk)");
    strcpy(P[5].name,"Kedhar Jadhav");
    strcpy(P[6].name,"Hardik Pandya");
    strcpy(P[7].name,"Ravindra Jadeja");
    strcpy(P[8].name,"Bhuvneshwar Kumar");
    strcpy(P[9].name,"Kuldeep Yadav");
    strcpy(P[10].name,"Jasprit Bumrah");
    strcpy(P[11].name,"David Warner");
    strcpy(P[12].name,"Aaron Finch");
    strcpy(P[13].name,"Usman Khawaja");
    strcpy(P[14].name,"Steven Smith(c)");
    strcpy(P[15].name,"Mathew Wade");
    strcpy(P[16].name,"Glenn Maxwell");
    strcpy(P[17].name,"Marcus Stoinis");
    strcpy(P[18].name,"Pat Cummins");
    strcpy(P[19].name,"Josh Hazlewood");
    strcpy(P[20].name,"Adam Zampa");
    strcpy(P[21].name,"Mitchell Starc");
    for(i=0;i<22;i++)
    {
        P[i].overs=P[i].ballsbowled=P[i].extras=P[i].wickets=P[i].maidens=P[i].runsconceded=P[i].runsscored=P[i].ballsfaced=P[i].boundaries=0;
        P[i].eco=P[i].SR=0;
        P[i].onfield='N';strcpy(P[i].ONO,"DNB");strcpy(P[i].MOD,"");
    }
}
void functoss()//function for toss
{
    char weather[10],x;
    int hour,i,toss,t,j,attendance;
    printf("\nWELCOME TO THE CricStatz MATCH SCORING SYSTEM\n");
    venuedetails();
    printf("\nENTER WEATHER CONDITIONS(SUNNY, RAINY, OVERCAST, WINDY, DUSTY)\n");
    scanf("\n%s",weather);
    if((strcmp(weather,"RAINY")==0)||(strcmp(weather,"rainy")==0)||(strcmp(weather,"Rainy")==0))
    {
        printf("\nMATCH ABANDONED DUE TO RAIN");
        exit(0);
    }
    printf("\nENTER TIME OF MATCH IN 24 HR FORMAT(EXAMPLE 1600 FOR 4PM)\n");
    scanf("\n%d",&hour);
    attendance=(rand()%10001)+30000;
    printf("\nSTEVE WAUGH : WELCOME FOLKS.");
    printf("\n              IT'S A %s DAY AND WE HAVE THE MOST AWAITED 2-OVER-PER-SIDE MATCH BETWEEN INDIA AND AUSTRALIA AT %d HOURS.",weather,hour);
    printf("\n              I'M STEVE WAUGH AND JOINING ME TODAY IN THE COMMENTARY PANEL IS HARSHA BHOGLE AND BRETT LEE.");
    printf("\n              THE STADIUM IS PACKED WITH A CROWD OF %d, WHO ARE EAGER THAN EVER TO SEE THIS MATCH GET UNDER WAY.",attendance);
    printf("\n              SURE IS A DEAFENING SOUND FROM ALL THE BUZZING AND VUVUZELAS !!!");
    printf("\n              OVER TO BRETT NOW WHO'S GOING TO TAKE US THROUGH TODAY'S SPONSORS FOR THE MATCH");
    printf("\n");
    printf("\nBRETT LEE : THANKS STEVE. A VERY GOOD DAY LADIES AND GENTLEMEN. SUCH AN HONOUR TO SIT IN THE BOX FOR A NERVE WRECKING MATCH TO FOLLOW");
    printf("\n            WE'VE GOT A COUPLE OF SPONSORS FOR THIS MATCH : ");
    printf("\n            GLOBAL PARTNERS");
    printf("\n            1. OPPO");
    printf("\n            2. MRF TYRES");
    printf("\n            3. EMIRATES");
    printf("\n            OFFICIAL PARTNERS");
    printf("\n            1. COCA-COLA");
    printf("\n            CATEGORY PARTNERS");
    printf("\n            1. CRICBUZZ");
    printf("\n            2. DREAM11");
    printf("\n");
    printf("\n            IN ADDITION, CricStatz, A NEW SCORING SYSTEM FOR ALL KINDS OF CRICKET MATCHES ACROSS THE GLOBE, BE IT GULLY OR INTERNATIONAL,");
    printf("\n            HAS OPENED UP PARTNERSHIP WITH ICC AND THEIR CEO IS HERE TODAY TO WITNESS THE USE OF THE NEW SYSTEM FOR THE FIRST TIME");
    printf("\n            SOUNDS EXCITING !!!");
    printf("\nSTEVE WAUGH : THANK YOU SO MUCH BRETT.");
    printf("\n              DOWN ON THE PITCH IS PITCH ANALYST DANNY MORRISON.");
    printf("\n              WE SHOULD BE GOING IN FOR THE TOSS SHORTLY. OVER TO YOU DANNY.");
    printf("\n");
    printf("\nDANNY MORRISON : THANK YOU SO MUCH STEVE. ALONGSIDE ME I'VE GOT THE INDIAN CAPTAIN VIRAT(YOU) AND THE AUSTRALIAN CAPTAIN STEVEN. IT'S TIME FOR TOSS.");
    printf("\n                 STEVEN'S GOT THE COIN.");
    printf("\n");
    printf("\n            TOSS");
    printf("\nCHOOSE EITHER HEADS OR TAILS");
    printf("\nENTER 0 FOR HEADS AND 1 FOR TAILS\n");
    scanf("\n%d",&toss);
    if(toss==0)
    {
        printf("\nHEADS IS THE CALL");
        printf("\n");
    }
    else
    {
        printf("\nTAILS IS THE CALL");
        printf("\n");
    }
    srand(time(0));
    t=rand()%2;
    if(t!=toss)
    {
        srand(time(0));
        t1=rand()%2;
        if(t1==0)
        {   printf("\nDANNY MORRISON : AUSTRALIA HAVE WON THE TOSS AND HAVE DECIDED TO BAT FIRST");
            printf("\n                 STEVEN'S MEN WILL BE BATTING FIRST. LET'S SEE IF THEY CAN POST A COMPETITIVE TOTAL.");
            option=2;
        }
        else
        {
            printf("\nDANNY MORRISON : AUSTRALIA HAVE WON THE TOSS AND HAVE DECIDED TO BOWL FIRST");
            printf("\n                 STEVEN'S MEN WILL BE BOWLING FIRST. LET'S SEE IF THEY CAN RESTRICT THE OPPOSITION TO A LOW TOTAL");
            option=1;
        }
    }
    else
    {
        printf("\nDANNY MORRISON : INDIA(YOU) HAVE WON THE TOSS");
        printf("\n                 VIRAT(YOU), WHAT'S YOUR DECISION. DO YOU WISH TO BAT OR BOWL?");
        printf("\n");
        printf("\nENTER 1 FOR BATTING AND 2 FOR BOWLING\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nDANNY MORRISON : VIRAT'S MEN WILL BE BATTING FIRST. LET'S SEE IF THEY CAN POST A COMPETITIVE TOTAL.");
            option=1;
        }
        else
        {
            printf("\nDANNY MORRISON : VIRAT'S MEN WILL BE BOWLING FIRST. LET'S SEE IF THEY CAN RESTRICT THE OPPOSITION TO A LOW TOTAL.");
            option=2;
        }
    }
    printf("\n                 THESE ARE THE PLAYING XI OF BOTH SIDES. I CAN ALREADY TELL THIS IS GONNA BE A FANTASTIC CLASH OFF. THE NEXT 4 OVERS WILL TESTIFY THE SAME.");
    printf("\n                 OVER TO YOU STEVE !");
    printf("\n");
    printf("\nINDIA(HOME)\t\t\t\t\t\t\t\tAUSTRALIA(AWAY)\n");
    for(i=0,j=11;i<11;i++,j++)
    {
        printf("\n%-22s\t\t\t\t\t\t\t%s",P[i].name,P[j].name);
    }
    printf("\n");
    printf("\nOVERS PER SIDE : %d",2);
    printf("\nONFIELD UMPIRES : BRUCE OXENFORD AND BILLY BOWDEN");
    printf("\nTHIRD UMPIRE : KUMAR DHARMASENA");
    printf("\nMATCH REFEREE : JAVAGAL SRINATH\n");
}
void venuedetails()
{
    FILE *fp1;
    char city[15];
    float k;
    venue_entry:
    printf("\nEnter city:");
    printf("\n1.Visakhapatnam\n2.Chennai\n3.Bengaluru\n4.Mumbai\n5.Hyderabad\n6.Delhi\n7.Jaipur\n8.Kolkata\n\n");
    scanf("\n%s",city);
    struct details d;
    fp1=fopen("VenueDetails.dat","r");
    if(fp1==NULL)
    {
        printf("\nFile not found");
    }
    else
    {
        int z=0;
        while(fread(&d,sizeof(struct details),1,fp1))
{
   if(strcmp(d.city,city)==0)
            {
                z=1;
                printf("\nWelcome to %s Cricket Stadium!",d.stadium);
                printf("\nGeneral pitch condition : %s",d.pitch);
                printf("\nSeating Capacity : %d",d.seatcap);
                printf("\nTotal Matches Played : %d",d.matplay);
                printf("\nWins batting 1st : %d",d.winsb1);
                printf("\nWins batting 2nd : %d",d.winsb2);
                printf("\nDraws : %d",d.draws);
                printf("\nAverage boundary length : %d yards",d.avgblength);
                k = ((d.winsb1)*100.0/d.matplay);
                printf("\nPercentage wins batting first : %0.2f",k);
                printf("\n");
                break;
            }
        }
        if(z!=1)
        {
            printf("\nEnter venue from given list\n");
            goto venue_entry;
        }
    }
    fclose(fp1);
}
int setbatsman(char *bstriker)
{
    int r,j,compare;
    if(option==1)
    {
        for(j=0;j<11;j++)
        {
            compare=strcmp(bstriker,P[j].name);
            if(compare==0)
            {
                if(P[j].onfield=='N')
                {
                    P[j].onfield='Y';
                    strcpy(P[j].ONO,"N/OUT");
                    r=j;
                    break;
                }
                else
                {
                    printf("\nBatsman already dismissed/on field");
                    r=-1;
                    break;
                }
            }
        }
        if(j==11)
        {
            printf("\nInvalid batsman name");
            r=-1;
        }
    }
    else
    {
        for(j=11;j<22;j++)
        {
            compare=strcmp(bstriker,P[j].name);
            if(compare==0)
            {
                if(P[j].onfield=='N')
                {
                    P[j].onfield='Y';
                    strcpy(P[j].ONO,"N/OUT");
                    r=j;
                    break;
                }
                else
                {
                    printf("\nBatsman already dismissed/onfield");
                    r=-1;
                    break;
                }
            }
        }
        if(j==22)
        {
             printf("\nInvalid Batsman Name");
            r=-1;
        }
    }
    return r;
}
void choosebatsman()
{
    char batname[25];
  input:
    printf("\nEnter Striker name:");
    scanf("\n%[^\n]s",batname);
    striker=setbatsman(batname);
    P[striker].onfield='Y';
    strcpy(P[striker].ONO,"N/OUT");
    if(striker==-1)
        goto input;
    else
        c1=P[striker];
    input1:
        printf("\nEnter non striker name:");
        scanf("\n%[^\n]s",batname);
        nonstriker=setbatsman(batname);
        P[nonstriker].onfield='Y';
        strcpy(P[nonstriker].ONO,"N/OUT");
    if(nonstriker==-1)
        goto input1;
    else
        c2=P[nonstriker];
}
void boundarycount()//function to calculate boundary count
{
    if(option==1)
        indbcount+=bcount;
    else
        ausbcount+=bcount;
}
void overinprogress()//function to choose bowler for a particular over and call entries() function
{
    char bname[25];
    input:
    printf("\nEnter new bowler name:");
    scanf("\n%[^\n]s",bname);
    int i,compare;
    if(option==1)
    {
        for(i=11;i<22;i++)
    {
        compare=strcmp(bname,P[i].name);
        if(compare==0)
        {
            if(P[i].overs==0)
            {
                b1=P[i];
                bowler=i;
                break;
            }
            else
            {
                printf("\nBowler already completed quota of overs");
                goto input;
            }
        }
    }
    if(i==22)
    {
        printf("\nInvalid bowler name");
        goto input;
    }
    }
    else
    {
        for(i=0;i<11;i++)
        {
            compare=strcmp(bname,P[i].name);
            if(compare==0)
            {
                if(P[i].overs==0)
                {
                   b1=P[i];
                   bowler=i;
                   break;
                }
                else
                {
                   printf("\nBowler already completed quota of overs");
                   goto input;
                }
            }
         }
         if(i==11)
         {
             printf("\nInvalid bowler name");
             goto input;
         }
    }
    entries();
    P[bowler]=b1;
    if(overnumber==0||overnumber==2)
    {
        printf("\n\t\t\t\tDRINKS BREAK");
    }
}
void entries()//function to input and store runs/wickets in each ball of a particular over
{
    int count=0,i=1,j,compare,c,x;
    char bstriker[25];
    while(i<=6)
    {
        if(innings==2||innings==4)
            reqrunrate();
        else
            currentrunrate(score);
        printf("\nOn strike:%s",c1.name);
        input:
        printf("\nBall No %d:",i);
        scanf("%d",&o[overnumber].eachball[i]);
        c=o[overnumber].eachball[i];
        if((o[overnumber].eachball[i]<-1)||(o[overnumber].eachball[i]>7))
           {
               printf("\nInvalid input");
               goto input;
           }
        else if(o[overnumber].eachball[i]==-1)
           {
               printf("\nENTER MODE OF DISMISSAL IN SPECIFIED FORMAT");
               printf("\nIf caught by a player, enter C(fielder's first/last name) B(bowler's first/last name)");
               printf("\nIf caught leg before wicket, enter lbw(bowler's first/last name)");
               printf("\nIf bowled, enter B(bowler's first/last name)");
               printf("\nIf hit wicket, enter \"H/W\"");
               printf("\nIf stumped, enter stmpd(wicket keeper's first/last name)");
               scanf("\n%[^\n]s",c1.MOD);
               b1.wickets+=1;
               balls++;
               fallofwickets(score,wkc);
               wkc++;
               b1.ballsbowled++;
               c1.ballsfaced+=1;
               printf("\n%s HAS BEEN DISMISSED BY %s FOR %d(%d)",c1.name,b1.name,c1.runsscored,c1.ballsfaced);
               c1.SR=((float)c1.runsscored/c1.ballsfaced)*100;
               strcpy(c1.ONO,"OUT");
               P[striker]=c1;
               if(overnumber==3&&i==6)
               {
                   i++;
                   goto abc1;
               }
               if(overnumber==1&&i==6)
               {
                   i++;
                   goto abc;
               }
               if(wkc==10)//general case
               {
                   if(innings==1)
                    {   i++;
                        goto abc;
                    }
                   else
                   {
                        i++;
                        goto abc1;
                   }
               }
                if((innings==3||innings==4)&& i==6)//for super over
                {
                    i++;
                    goto abc1;
                }
                if((innings==3||innings==4) && i!=6 && wkc==2)
                {
                    if(innings==3)
                    {
                        i++;
                        goto abc;
                    }
                    if(innings==4)
                    {
                        i++;
                        goto abc1;
                    }
                }
               input1:
               printf("\nEnter new batsman:");
               scanf("\n%[^\n]s",bstriker);
               x=setbatsman(bstriker);
               if(x==-1)
                goto input1;
               else
               {
                   c1=P[x];
                   striker=x;
               }
               if(i==6)
                {
                    changestrike();
                }
               i++;
           }
        else if(o[overnumber].eachball[i]==7)
            {
                count+=1;
                b1.runsconceded+=1;
                b1.extras+=1;
                score+=1;
            }
        else if(o[overnumber].eachball[i]==1||o[overnumber].eachball[i]==3||o[overnumber].eachball[i]==5)
            {
                count+=o[overnumber].eachball[i];
                balls++;
                b1.runsconceded+=o[overnumber].eachball[i];
                b1.ballsbowled++;
                c1.runsscored+=c;
                c1.ballsfaced+=1;
                score+=c;
                if(i!=6)
                {
                    changestrike();
                }
                i++;
            }
        else
            {
                count+=o[overnumber].eachball[i];
                balls++;
                b1.runsconceded+=o[overnumber].eachball[i];
                b1.ballsbowled++;
                c1.runsscored+=c;
                c1.ballsfaced+=1;
                score+=c;
                if(c==4||c==6)
                {
                   c1.boundaries++;
                   bcount++;
                }
                if(c==6)
                {
                    int dist=(rand()%31)+80;
                    printf("\nHARSHA BHOGLE : GOING GOING GONE !!!");
                    printf("\nSix Distance:%d metres",dist);
                }
                if(c==4)
                printf("\nHARSHA BHOGLE : THE BALL HAS FOUND THE FENCE !!!");
                if(i==6)
                {
                    changestrike();
                }
                i++;
            }
            abc1:
            if((innings==2||innings==4) && option==2)
            {
                if(indtotal<score)
                {
                    update(count);
                    if(innings==2)
                        printf("\nSECOND INNINGS SCORECARD");
                    if(innings==4)
                        printf("\nFOURTH INNINGS SCORECARD");
                    display();
                    printf("\nAUSTRALIA WON THE MATCH BY %d WICKETS",10-wkc);
                    printf("\nSTEVE WAUGH : THERE YOU HAVE IT FOLKS. A DEFINITIVE END TO A THRILLER. AUSTRALIA HAVE SHOWN THAT THEY'RE INDEED THE BETTER SIDE.");
                    end();
                }
            }
            if((innings==2||innings==4) && option==1)
            {
                if(austotal<score)
                {
                    update(count);
                    if(innings==2)
                        printf("\nSECOND INNINGS SCORECARD");
                    if(innings==4)
                        printf("\nFOURTH INNINGS SCORECARD");
                    display();
                    printf("\nINDIA WON THE MATCH BY %d WICKETS",10-wkc);
                    printf("\nSTEVE WAUGH : THERE YOU HAVE IT FOLKS. A DEFINITIVE END TO A THRILLER. INDIA HAVE SHOWN THAT THEY'RE INDEED THE BETTER SIDE.");
                    end();
                }
            }
            if(innings==2&&(balls==12||wkc==10))
            {
                if((score==austotal && option==1)||(score==indtotal && option==2))
                {
                    update(count);
                    printf("\nSECOND INNINGS SCORECARD");
                    display();
                    printf("\nMATCH TIED !");
                    printf("\nHARSHA BHOGLE : WE'RE HEADING INTO SUPEROVER SHORTLY. BOY THIS IS GOING TO BE A REALLY EXCITING MATCH. A MEMORABLE ONE FOR THE FANS WATCHING GLOBALLY ESPECIALLY.");
                    printf("\n                THIS IS THE FIRST TIME INDIA AND AUSTRALIA ARE HEADING INTO SUPEROVER IN THE HISTORY OF THE GAME !!!");
                    printf("\n                ANOTHER 10 MINUTES AND WE'LL HAVE A DEFINITIVE WINNER.");
                    superover();
                }
            }
             if((innings==2&&wkc==10)||(innings==4&&wkc==2))
                goto abc;
    }
    abc:
    update(count);
}
void update(int c)
{
    b1.eco=((float)b1.runsconceded/b1.ballsbowled)*6;
    if(c1.ballsfaced!=0)
       c1.SR=((float)c1.runsscored/c1.ballsfaced)*100;
    if(c2.ballsfaced!=0)
       c2.SR=((float)c2.runsscored/c2.ballsfaced)*100;
    P[striker]=c1;
    P[nonstriker]=c2;
    if(b1.ballsbowled==6)
    {
        if(c==0)
            b1.maidens++;
        b1.overs++;
    }
    P[bowler]=b1;
}
void changestrike()//function to interchange striker and non-striker as per requirement
{
    c3=c1;
    c1=c2;
    c2=c3;
    temp=striker;
    striker=nonstriker;
    nonstriker=temp;
}
void reqrunrate()//function to calculate required run rate
{
    int runsrem;
    float x;
    if(option==1)
    {
        runsrem=austotal+1-score;
        if(innings==2)
        x=((float)runsrem/(12-balls))*6;
        if(innings==4)
        x=((float)runsrem/(6-balls))*6;
    }
    else
    {
        runsrem=indtotal+1-score;
        if(innings==2)
        x=((float)runsrem/(12-balls))*6;
        if(innings==4)
        x=((float)runsrem/(6-balls))*6;
    }
    printf("\nRequired Run Rate:%0.2f",x);
}
void currentrunrate(int r)//function to calculate current run rate
{
    float x=0;
    int projscore;
    if(balls!=0)
    x=((float)r/balls)*6;
    if(innings==1)
    projscore=x*2;
    if(innings==3)
        projscore=x*1;
    printf("\nProjected Score:%d",projscore);
}
void fallofwickets(int s,int w)//function to store fall of wickets in structure declared above
{
    if(option==1)
    {
        ind[w].runs=s;
        ind[w].wkts=w+1;
    }
    else
    {
        aus[w].runs=s;
        aus[w].wkts=w+1;
    }
}
void displayfow()//function to display fall of wickets in a particular innings
{
    int i;
    printf("\nFall of wickets:");
    for(i=0;i<wkc;i++)
    {
        if(option==1)
            printf("\n%d/%d",ind[i].runs,ind[i].wkts);
        else
            printf("\n%d/%d",aus[i].runs,aus[i].wkts);
    }
}
void battingcard_ind()//function to display batting performance of India
{
    int i,j;
    printf("\nINDIA");
    printf("\n");
    printf("%-22s%-14s%-20s%-9s%-10s%-15s%s\n","NAME","DISMISSED","MODE OF DISMISSAL","RUNS","BALLS","BOUNDARIES","SR");
    for(i=0,j=11;i<11;i++,j++)
    {
        total+=(P[i].runsscored+P[j].extras);
        indtotal=total;
        printf("%-22s%-14s%-20s%-9d%-10d%-15d%0.2f",P[i].name,P[i].ONO,P[i].MOD,P[i].runsscored,P[i].ballsfaced,P[i].boundaries,P[i].SR);
        printf("\n");
    }
    printf("\n%-90s%d-%d","TOTAL",indtotal,wkc);
    float crr=((float)indtotal/12)*6;
    printf("\nCurrent Run Rate:%0.2f",crr);
    boundarycount();
    printf("\nBOUNDARY COUNT:%d",indbcount);
    displayfow();
}
void battingcard_aus()//function to display batting performance of Australia
{
    int i,j;
    printf("\nAUSTRALIA");
    printf("\n");
    printf("%-22s%-14s%-20s%-9s%-10s%-15s%s\n","NAME","DISMISSED","MODE OF DISMISSAL","RUNS","BALLS","BOUNDARIES","SR");
    for(i=11,j=0;i<22;i++,j++)
    {
        total+=(P[i].runsscored+P[j].extras);
        austotal=total;
        printf("%-22s%-14s%-20s%-9d%-10d%-15d%0.2f",P[i].name,P[i].ONO,P[i].MOD,P[i].runsscored,P[i].ballsfaced,P[i].boundaries,P[i].SR);
        printf("\n");
    }
    printf("\n%-90s%d-%d","TOTAL",austotal,wkc);
    float crr=((float)austotal/12)*6;
    printf("\nCurrent Run Rate:%0.2f",crr);
    boundarycount();
    printf("\nBOUNDARY COUNT:%d",ausbcount);
    displayfow();
    printf("\n");
}
void bowlingcard_ind()//function to display bowling performance of India
{
    printf("\n\nINDIA");
    printf("\n");
    printf("%-22s%-10s%-18s%-12s%-12s%-11s%s\n","NAME","OVERS","RUNS CONCEDED","MAIDENS","WICKETS","EXTRAS","ECO");
    int i;
    for(i=10;i>=0;i--)
    {
        printf("%-22s%-10d%-18d%-12d%-12d%-11d%0.2f",P[i].name,P[i].overs,P[i].runsconceded,P[i].maidens,P[i].wickets,P[i].extras,P[i].eco);
        printf("\n");
    }
}
void bowlingcard_aus()//function to display bowling performance of Australia
{
    printf("\n\nAUSTRALIA");
    printf("\n%-22s%-10s%-18s%-12s%-12s%-11s%s\n","NAME","OVERS","RUNS CONCEDED","MAIDENS","WICKETS","EXTRAS","ECO");
    int i;
    for(i=21;i>=11;i--)
    {
        printf("%-22s%-10d%-18d%-12d%-12d%-11d%0.2f",P[i].name,P[i].overs,P[i].runsconceded,P[i].maidens,P[i].wickets,P[i].extras,P[i].eco);
        printf("\n");
    }
}
void display()//function to display innings scorecard
{
    if(option==1)
    {
        battingcard_ind();
        bowlingcard_aus();
        option=2;
    }
    else
    {
        battingcard_aus();
        bowlingcard_ind();
        option=1;
    }
}
void superover()//function for superover
{
    initiate();
    overnumber=0;
    if(option==2)
        option=1;
    else
        option=2;
    if(option==1)
        printf("\nINDIA WILL HAVE TO PAD UP AND HEAD OUT AGAIN");
    else
        printf("\nAUSTRALIA WILL HAVE TO PAD UP AND HEAD OUT AGAIN");
    innings=3;
    printf("\nSTART OF INNINGS III(Superover innings 1)");
    total=bcount=score=wkc=balls=0;
    choosebatsman();
    overinprogress();
    overnumber++;
    printf("\nTHIRD INNINGS SCORECARD\n");
    display();
    printf("\n");
    printf("\nTARGET = %d",total+1);
    printf("\n");
    if(option==2)
        printf("\nINDIA ARE GOING TO COMPLETELY RELY ON THEIR BOWLER NOW TO FINISH THINGS OFF");
    else
        printf("\nAUSTRALIA ARE GOING TO COMPLETELY RELY ON THEIR BOWLER NOW TO FINISH THINGS OFF");
    innings=4;
    printf("\nSTART OF INNINGS IV(Superover innings 2)");
    score=total=bcount=wkc=balls=0;
    choosebatsman();
    overinprogress();
    if(option==1 && austotal>indtotal)
    {
        printf("\nFOURTH INNINGS SCORECARD\n");
        display();
        printf("\nAUSTRALIA WON BY %d RUNS",austotal-indtotal);
        printf("\nSTEVE WAUGH : THERE YOU HAVE IT FOLKS. A DEFINITIVE END TO A THRILLER. AUSTRALIA HAVE SHOWN THAT THEY'RE INDEED THE BETTER SIDE.");
        end();
    }
    else if(option==2 && indtotal>austotal)
    {
        printf("\nFOURTH INNINGS SCORECARD\n");
        display();
        printf("\nINDIA WON BY %d RUNS",indtotal-austotal);
        printf("\nSTEVE WAUGH : THERE YOU HAVE IT FOLKS. A DEFINITIVE END TO A THRILLER. INDIA HAVE SHOWN THAT THEY'RE INDEED THE BETTER SIDE.");
        end();
    }
    else
    {
        printf("\nFOURTH INNINGS SCORECARD\n");
        display();
        if(ausbcount>indbcount)
        {
            printf("\nINDIA BOUNDARY COUNT : %d",indbcount);
            printf("\nAUSTRALIA BOUNDARY COUNT : %d",ausbcount);
            printf("\nSTEVE WAUGH : LUCK, SHEAR LUCK !!! THE LOOK ON THE INDIAN FACES SAY IT ALL. AUSTRALIA HAVE WON BY THE SHEAR MARGIN OF BOUNDARY COUNT.");
        }
        else if(ausbcount<indbcount)
        {
            printf("\nINDIA BOUNDARY COUNT : %d",indbcount);
            printf("\nAUSTRALIA BOUNDARY COUNT : %d",ausbcount);
            printf("\nSTEVE WAUGH : LUCK, SHEAR LUCK !!! THE LOOK ON THE AUSTRALIAN FACES SAY IT ALL. INDIA HAVE WON BY THE SHEAR MARGIN OF BOUNDARY COUNT.");
        }
        else
            printf("\nMATCH TIED");
        end();
    }
}
void end()//function to display closing commentary
{
    printf("\nSTEVE WAUGH : A HUGE THANKS TO ALL OF YOU FOR JOINING US ON THIS TELECAST.");
    printf("\n              A VERY BIG THANKS TO ALL OUR PARTNERS FOR TODAYS'S MATCH");
    printf("\n              HOPE YOU LIKED THE NEW CricStatz SYSTEM WHICH IN MY OPINION WAS FABULOUS IN ITS INITIAL YEARS OF DEVELOPMENT");
    printf("\n              ON BEHALF OF THE COMMENTARY PANEL, THIS IS STEVE WAUGH SIGNING OFF AND LOOKING FORWARD TO SEEING YOU FOR THE NEXT MATCH.");
    printf("\n");
    printf("\n~ADIOS AMIGOS~");
    exit(0);
}
int main()
{
    initiate();
    functoss();
    innings=1;
    printf("\nSTART OF INNINGS I");
    total=bcount=score=wkc=balls=0;
    choosebatsman();
    overinprogress();
    overnumber++;
    overinprogress();
    overnumber++;
    printf("\nFIRST INNINGS SCORECARD\n");
    display();
    printf("\n");
    printf("\nTARGET = %d",total+1);
    printf("\n");
    innings=2;
    printf("\nSTART OF INNINGS II");
    score=total=bcount=wkc=balls=0;
    choosebatsman();
    overinprogress();
    overnumber++;
    overinprogress();
    if(option==1 && austotal>indtotal)
    {
        printf("\nSECOND INNINGS SCORECARD\n");
        display();
        printf("\nAUSTRALIA WON BY %d RUNS",austotal-indtotal);
        printf("\nSTEVE WAUGH : THERE YOU HAVE IT FOLKS. A DEFINITIVE END TO A THRILLER. INDIA HAVE SHOWN THAT THEY'RE INDEED THE BETTER SIDE.");
    }
    else if(option==2 && indtotal>austotal)
    {
        printf("\nSECOND INNINGS SCORECARD\n");
        display();
        printf("\nINDIA WON BY %d RUNS",indtotal-austotal );
        printf("\nSTEVE WAUGH : THERE YOU HAVE IT FOLKS. A DEFINITIVE END TO A THRILLER. AUSTRALIA HAVE SHOWN THAT THEY'RE INDEED THE BETTER SIDE.");
    }
    end();
    return 0;
}
