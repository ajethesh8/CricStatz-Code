#include<stdio.h>
struct details //structure to store venue details
{
    char city[15],stadium[50],pitch[25];
    int seatcap,matplay,winsb1,winsb2,draws,avgblength;
};
int main()
{
    FILE *fp1;
    int j;
    float k;
    struct details i[8] = {{"Visakhapatnam","Dr.Y.S. Rajasekhara Reddy ACA-VDCA Stadium","Dry",50000,113,57,55,1,75},
                           {"Chennai","M.A.Chidambaram Stadium, Chepauk","Wet",45000,250,131,111,8,70},
                           {"Bengaluru","Chinnaswamy Stadium","Belter",50000,157,74,80,3,75},
                           {"Mumbai","Wankhede Stadium","Consistent bounce",58000,300,130,151,19,76},
                           {"Hyderabad","Rajiv Gandhi International Stadium","Good for batting",55000,300,171,120,9,80},
                           {"Delhi","Feroz Shah Kotla Stadium","Good for pacers",48000,270,135,125,10,74},
                           {"Jaipur","Sawai Mansingh Stadium","Good for spinners",30000,100,61,38,1,69},
                           {"Kolkata","Eden Gardens","Big outfield",40000,225,100,120,5,74}};
    fp1=fopen("VenueDetails.dat","w");
    for(j=0;j<8;j++)
    {
        fwrite(&i[j],sizeof(struct details),1,fp1);
    }
    fclose(fp1);
    struct details d;
    fp1=fopen("VenueDetails.dat","r");
    if(fp1==NULL)
        printf("\nFile not found");
    else
    {
        while(fread(&d,sizeof(struct details),1,fp1))
        {
            printf("\nWelcome to %s Cricket Stadium!",d.stadium);
                printf("\nPitch:%s",d.pitch);
                printf("\nSeating Capacity:%d",d.seatcap);
                printf("\nTotal Matches Played:%d",d.matplay);
                printf("\nwins batting first:%d",d.winsb1);
                       printf("\nwins batting 2nd:%d",d.winsb2);
                printf("\nDraws:%d",d.draws);
                           printf("\nAverage boundary length:%d yards",d.avgblength);
                       k = ((d.winsb1)*100.0/d.matplay);
                printf("\nPerwinsbf:%f",k);
        }
    }
    fclose(fp1);
    return 0;
}
