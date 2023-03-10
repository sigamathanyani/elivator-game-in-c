#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ESD.h"

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

#define SPECIAL_KEY -32

void drawBox(int posX, int posY, int width, int height);
void aboutClear();

int main()
{
    FILE *fp;
    char buff[50];
    int value,value1;
    int arr1[50];
    int arr2[50];
    int c=9;

    int btmBlock[100];

    int block1[200][200];
    int water[200][200];

    int top_passenger = 0;
    int bottom_passenger = 0;

    int i,j=1,r=0;
    int x,y;

    int insideBt[6] = {95,95,95,95,95};
    int btIndex = 0;
    int index=0;

    int dive_mode = 1;
    int load_mode = 1;

    int offsetX = 6;
    int offsetY = 4;

    char userI;

    fp = fopen("data.txt","rt");
    int run=1;

    do
    {
        drawBox(10,6,60,9);
        gotoxy(34,7);printf("Pond demo.");
        gotoxy(22,9);printf("Option A - About");
        gotoxy(22,10);printf("Option P - Pond");
        gotoxy(22,11);printf("Option E - Exit");
        gotoxy(22,13);printf("Please type your option : ");

        userI = getche();

        if(userI == 'A' || userI == 'a')
        {
            aboutClear();
            gotoxy(12,9);printf("In the pond demo:");
            gotoxy(12,11);printf("Use the e-, r, d and the f-keys to add remove frogs");
            gotoxy(12,12);printf("from the pond floor or river bank");
            gotoxy(12,14);printf("Press any key to continue...");
            userI=getch();
            if(userI==SPECIAL_KEY)getch();
            aboutClear();
            gotoxy(12,9);printf("In the pond demo:");
            gotoxy(12,10);printf("The s- and l keys select dive or load mode");
            gotoxy(12,11);printf("In ");setColor(0*16+12); printf("load mode mode ");setColor(0*16+15); printf("the arrow keys load and unload paxes");
            gotoxy(12,12);printf("In ");setColor(0*16+12); printf("dive mode ");setColor(0*16+15); printf("the arrow keys move up/down");
            gotoxy(12,14);printf("Press any key to continue...");
            userI=getch();
            if(userI==SPECIAL_KEY)getch();
            clrscr();
        }
        else if((userI == 'P' || userI == 'p') && userI != DOWN_ARROW)
        {
            clrscr();
            drawBox(0, 0, 78,23);
            drawBox(offsetX-1, offsetY-1, 62,18);
            gotoxy(35,1);printf("Pond Demo");
            for(i=0;i<4;i++)
            {
                fgets(buff,7,fp);

                if(strpbrk(buff," "))
                {
                    int leN=strpbrk(buff," ")-buff;
                    buff[leN]=NULL;
                    value = atoi(buff);
                    value1 = atoi(&buff[leN+1]);

                    arr1[i]=value;
                    arr2[i]=value1;

                }

            }

            setColor(arr1[3]+arr2[3]);

            for(y=0;y<13;y++)
            {
                for(x=0;x<8;x++)
                {
                        fgets(buff,5,fp);
                        value = atoi(buff);
                        block1[x][y] = value;
                        gotoxy(arr1[2]+x+offsetX,arr2[2]+y+offsetY);
                        printf("%c",block1[x][y]);
                }

            }

            fgets(buff,5,fp);

            for(i=4;i<6;i++)
            {

                    fgets(buff,7,fp);
                    if(strpbrk(buff," "))
                    {
                        int leN=strpbrk(buff," ")-buff;
                        buff[leN]=NULL;
                        value = atoi(buff);
                        value1 = atoi(&buff[leN+1]);

                        arr1[i]=value;
                        arr2[i]=value1;

                    }
            }

            for(i=0;i<59;i++)
            {
                fgets(buff,5,fp);
                value = atoi(buff);
                btmBlock[i] = value;
                gotoxy(arr1[4]+i+offsetX,arr2[4]+offsetY);
                printf("%c",btmBlock[i]);
            }


            fgets(buff,5,fp);

            for(i=6;i<8;i++)
            {

                    fgets(buff,7,fp);
                    if(strpbrk(buff," "))
                    {
                        int leN=strpbrk(buff," ")-buff;
                        buff[leN]=NULL;
                        value = atoi(buff);
                        value1 = atoi(&buff[leN+1]);

                        arr1[i]=value;
                        arr2[i]=value1;

                    }
            }

            setColor(arr1[7]+arr2[7]);
            for(y=0;y<13;y++)
            {
                for(x=0;x<51;x++)
                {
                        fgets(buff,5,fp);
                        value = atoi(buff);
                        water[x][y] = value;
                        gotoxy(arr1[6]+x+offsetX,arr2[6]+y+offsetY);
                        printf("%c",water[x][y]);
                }

            }

                gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);
                printf("|_____|");

                int t_pass=1; int max_t_pass;
                int b_pass=1;

                do
                {
                    while(dive_mode)
                    {
                        setColor(arr1[7]+arr2[7]);
                        gotoxy(2,2);
                        printf("Dive Mode");
                        gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);
                        if(arr2[0]==arr1[1])
                        {setColor(arr1[7]+c);
                        printf("|");
                        for(index=0;index<5;index++){printf("%c",insideBt[index]);}
                        printf("|");}
                        userI = getch();

                        switch(userI)
                        {
                            case SPECIAL_KEY:

                                userI = getch();

                                if(userI == UP_ARROW && arr2[0] > arr1[1])
                                {
                                    arr2[0]--;

                                    for(y=0;y<13;y++)
                                    {
                                        for(x=0;x<7;x++)
                                        {
                                            setColor(arr1[7]+arr2[7]);
                                            gotoxy(arr1[6]+x+offsetX,arr2[6]+y+offsetY);
                                            printf("%c",water[x][y]);
                                        }

                                    }

                                    gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);

                                    if(arr2[0]==arr1[1])setColor(arr1[7]+c);
                                    else setColor(arr1[7]+arr2[7]);
                                    printf("|");
                                    for(index=0;index<5;index++){printf("%c",insideBt[index]);}
                                    printf("|");
                                }


                                else if(userI == DOWN_ARROW && arr2[0] < arr2[1])
                                {
                                        arr2[0]++;

                                            for(y=0;y<13;y++)
                                            {
                                                for(x=0;x<7;x++)
                                                {
                                                    setColor(arr1[7]+arr2[7]);
                                                    gotoxy(arr1[6]+x+offsetX,arr2[6]+y+offsetY);
                                                    printf("%c",water[x][y]);
                                                }

                                            }

                                        if(arr2[0]==arr1[1])setColor(arr1[7]+c);
                                        else setColor(arr1[7]+arr2[7]);
                                        gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);
                                        printf("|");
                                        for(index=0;index<5;index++){printf("%c",insideBt[index]);}
                                        printf("|");

                                    }
                                break;

                        }
                        if(userI == 27 || userI == 'l' || userI == 'L') break;
                    }

                    if(userI == 27) break;

                    //LOAD MODE START

                    while(load_mode)
                    {
                        setColor(arr1[7]+arr2[7]);
                        gotoxy(2,2);
                        printf("Load Mode ");
                        if(arr2[0]==arr1[1])setColor(arr1[7]+c);
                        if(arr2[0]==arr1[1]){}
                        else if(arr2[0]==arr2[1]){}
                        else break;

                        userI = getch();

                        switch(userI)
                        {
                            case 'e':
                                if(top_passenger < 7 && arr2[0]==arr1[1])
                                {
                                    top_passenger++;
                                    if(t_pass == 0)t_pass=0;
                                    gotoxy(arr1[0]-t_pass+offsetX,arr2[0]-1+offsetY);
                                    printf("%c",142);
                                    t_pass++;
                                    gotoxy(arr1[0]-t_pass+offsetX,arr2[0]-1+offsetY);
                                    max_t_pass = top_passenger;
                                }
                                break;

                            case 'r':
                                if(top_passenger > 0 && arr2[0]==arr1[1])
                                {
                                    t_pass--;
                                    gotoxy(arr1[0]-t_pass+offsetX,arr2[0]-1+offsetY);
                                    printf(" ");
                                    top_passenger--;
                                    gotoxy(arr1[0]-t_pass+offsetX,arr2[0]-1+offsetY);
                                }
                                    break;

                            case 'd':
                                if(bottom_passenger < 7 && arr2[0]==arr2[1])
                                {
                                    gotoxy(15+b_pass+offsetX,arr2[1]+offsetY);
                                    printf("%c",142);
                                    b_pass++;
                                    bottom_passenger++;
                                    gotoxy(15+b_pass+offsetX,arr2[1]+offsetY);
                                }
                                break;

                            case 'f':
                                if(bottom_passenger > 0 && arr2[1]==arr2[1])
                                {
                                    b_pass--;
                                    gotoxy(15+b_pass+offsetX,arr2[1]+offsetY);
                                    printf(" ");
                                    bottom_passenger--;
                                    gotoxy(15+b_pass+offsetX,arr2[1]+offsetY);
                                }
                                    break;

                            case SPECIAL_KEY:

                                if(kbhit())
                                {
                                    userI = getch();

                                    //LEFT SIDE OF THE POND START

                                    if(arr2[0] == arr1[1])
                                    {
                                        if(userI == RIGHT_ARROW)
                                        {

                                            if(top_passenger > 0 && btIndex != 5)
                                            {
                                                t_pass--;
                                                gotoxy(arr1[0]-t_pass+offsetX,arr2[0]-1+offsetY);
                                                printf(" ");

                                                insideBt[btIndex] = 153;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]+btIndex+1+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex++;
                                                top_passenger--;
                                            }

                                        }
                                        else if(userI == LEFT_ARROW) //start of left key
                                        {
                                            if(top_passenger < 7 && btIndex != 0)
                                            {
                                                t_pass++;
                                                gotoxy(arr1[0]-t_pass+1+offsetX,arr2[0]-1+offsetY);
                                                printf("%c",142);

                                                if(btIndex==0)btIndex=0;
                                                if(btIndex == 5)insideBt[btIndex] = 95;
                                                insideBt[btIndex-1] = 95;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]+btIndex+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex--;
                                                top_passenger++;
                                            }


                                        } // End of letf key

                                    }
                                    //LEFT SIDE OF THE POND END

                                    //RIGHT SIDE OF THE POND START

                                    if(arr2[0] == arr2[1])
                                    {
                                        if(userI == RIGHT_ARROW)
                                        {

                                            if(bottom_passenger > 0 && btIndex != 5)
                                            {

                                                b_pass--;
                                                gotoxy(15+b_pass+offsetX,arr2[1]+offsetY);
                                                printf(" ");

                                                insideBt[btIndex] = 153;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]-btIndex+5+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex++;
                                                bottom_passenger--;
                                            }
                                        }
                                        else if(userI == LEFT_ARROW)
                                        {
                                            if(bottom_passenger < 7 && btIndex != 0)
                                            {

                                                b_pass++;
                                                gotoxy(15+b_pass-1+offsetX,arr2[1]+offsetY);
                                                printf("%c",142);

                                                if(btIndex==5)insideBt[btIndex] = 95;;
                                                if(btIndex == 0)insideBt[btIndex] = 95;
                                                insideBt[btIndex-1] = 95;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]-btIndex+6+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex--;
                                                bottom_passenger++;
                                            }

                                        }

                                    //RIGHT SIDE OF THE POND END

                                    }

                                break;
                                }
                        }
                        if(userI == 27 || userI == 's' || userI == 'S') break;
                    }

                    if(userI == 27) break;

                    //LOAD MODE END

                }while(userI != 27);
        }
        else if(userI == 'E' || userI == 'e')
        {
            run = 0;
            Sleep(1000);
        }
        clrscr();setColor(0*16+15);

    }while(run);


    return 0;
}

void drawBox(int posX, int posY, int width, int height)
{
    int i;
    gotoxy(posX,posY);
    printf("\xDA");
    gotoxy(posX+width,posY);
    printf("\xBF");
    gotoxy(posX,posY+height);
    printf("\xC0");
    gotoxy(posX+width,posY+height);
    printf("\xD9");
    for(i=1;i<width;i++)
    {
        gotoxy(posX+i,posY);
        printf("\xC4");

        gotoxy(posX+i,posY+height);
        printf("\xC4");
    }

    for(i=1;i<height;i++)
    {
        gotoxy(posX,posY+i);
        printf("\xB3");

        gotoxy(posX+width,posY+i);
        printf("\xB3");
    }
}

void aboutClear()
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<48;j++)
        {
            gotoxy(22+j,9+i);
            printf(" ");
        }
    }
}
