/*Crowd Town
a game programmed with iGraphics
Date of completion: 11th April 2022
Project for 1-1 (CSE-102), CSE, BUET

Farriha Afnan
Roll: 2005061
Wahid Al Azad Navid
Roll: 2005089
Section: B1 */

# include "iGraphics.h"
# include <iostream>
# include <cstdlib>

#define screenwidth 1600
#define screenheight 800
#define rw 100

int x = 150, y = 0, r = 15;
int i,j,k,f_num,e_num,l,m,p=0,ik,jk,mk,nk,ok,s=1,q=1;
char str[100];
int num=1;
int num_fren=47,num_fren2=47;
int array_elements=94;
int num_enemy=7;
char position[8][15]= {"char1_user.bmp","char2.bmp","char3.bmp","char4.bmp"};
int index=0;
int time_rem=60;
char str_2[100],str_3[1000];
int final_num;
int h_score;
int x_e,y_e,x_e1,y_e1,x_e2,y_e2;
int index_en1=1,index_en2=2;
int ex1=350,ex2=850,ex3=760,ex4=330,ey1=600,ey2=330,ey3=10,ey4=10;
int dx1=3,dx2=2.75,dy3=3,dy4=2.75;

struct point
{
    int X;
    int Y;

};
struct point P[50];
struct point P1[10];
int point_array[94]= {150,150,150,275,150,400,150,525,150,650,150,775,360,150,360,275,360,400,360,525,260,458,60,458,450,180,450,625,450,360,550,125,550,250,550,375,550,500,550,625,650,330,650,720,650,625,750,125,750,250,750,375,750,625,850,625,
                      850,465,850,320,950,625,950,60,950,350,1050,350,1050,625,1050,60,1050,185,1150,625,1150,350,1150,750,1250,125,1250,250,1250,375,1250,500,1250,625,1350,70,1350,450
                     };//points to be declared
int point_array3[94]= {150,150,150,275,150,400,150,525,150,650,150,775,360,150,360,275,360,400,360,525,260,458,60,458,450,180,450,625,450,360,550,125,550,250,550,375,550,500,550,625,650,330,650,720,650,625,750,125,750,250,750,375,750,625,850,625,
                       850,465,850,320,950,625,950,60,950,350,1050,350,1050,625,1050,60,1050,185,1150,625,1150,350,1150,750,1250,125,1250,250,1250,375,1250,500,1250,625,1350,70,1350,450
                      };//points to be declared



int point_array2[14]= {320,600,550,175,900,380,1300,540,340,220,860,530,1060,260};
char position_enemy[8][15]= {"enemy1.bmp","enemy2.bmp","enemy3.bmp","enemy4.bmp"};
int index_en=0;

bool Music_on=true;
int GameState=0;

int clock_1[8]= {800,400,450,200,2000,2000,3000,3000};
int clock_3[8]= {800,400,450,200,2000,2000,3000};
int clock_elements=8;

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    //place your drawing codes here
    iClear();
    FILE *fp;


    if(GameState==0)
    {

        Music_on=true;
        if(Music_on)
            PlaySound("Music.wav",NULL,SND_LOOP | SND_ASYNC);

        iShowBMP(0,0,"homemenu.bmp");

        iShowBMP(200,450,"Button1.bmp");

        iShowBMP(200, 370,"Button2.bmp");

        iShowBMP(200,290,"Button3.bmp");


        fp=fopen("HighestScore.txt","r");
        fscanf(fp,"%d",&h_score);
        fclose(fp);

        itoa(h_score,str_3,10);
        iSetColor(255,255,255);
        iText(450,310,str_3,GLUT_BITMAP_TIMES_ROMAN_24);


        iShowBMP(200,210,"Button4.bmp");
        iShowBMP(200,130,"Button5.bmp");



    }



    if(GameState==1 || GameState==7)
    {

        iShowBMP(0,0,"bg1.bmp");

        iShowBMP2(x,y,position[index],0);

        itoa(num,str,10);
        iSetColor(255,255,255);
        iFilledRectangle(1450,740,150,60);
        iSetColor(0,0,0);
        iText(1460,760,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(1530,760,str,GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,255,255);
        iFilledRectangle(1450,540,150,120);

        iSetColor(0,0,0);
        iText(1460,620,"Time left: ",GLUT_BITMAP_TIMES_ROMAN_24);

        itoa(time_rem,str_2,10);
        iText(1460,560,str_2,GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,255);
        iText(1460,400,"Press P to pause",GLUT_BITMAP_HELVETICA_12);
        iText(1460,350,"Press R to resume",GLUT_BITMAP_HELVETICA_12);
        iText(1460,300,"Press M to menu",GLUT_BITMAP_HELVETICA_12);
        iText(1460,250,"Press F to turn off music",GLUT_BITMAP_HELVETICA_10);
        iText(1460,200,"Press O to turn on music",GLUT_BITMAP_HELVETICA_10);

        int array_num=0;

        for(f_num=0; f_num<num_fren; f_num++)
        {
            P[f_num].X=point_array[array_num];
            P[f_num].Y=point_array[array_num+1];
            array_num+=2;
        }
        for(f_num=0; f_num<num_fren; f_num++)
        {
            iShowBMP(P[f_num].X,P[f_num].Y,"char1.bmp");
        }

        for(l=0; l< array_elements ; l=l+2)
        {
            if( (x >= point_array[l]-22.5 && x<= point_array[l]+30) && (y >= point_array[l+1]-33 && y<= point_array[l+1]+30) )
            {
                num++;
                for(m=l; m<array_elements; m=m+2)
                {
                    point_array[m]=point_array[m+2];
                    point_array[m+1]=point_array[m+3];
                }
                array_elements-=2;

            }
        }

        /* array_num=0;
         for(e_num=0; e_num<num_enemy; e_num++)
         {
             P1[e_num].X=point_array2[array_num];
             P1[e_num].Y=point_array2[array_num+1];
             array_num+=2;
         }

         if( (x >= P1[p].X-15 && x<= P1[p].X+40) && (y>=P1[p].Y-20 && y<=P1[p].Y+50))
         {
             num=num-10;
             x=150;
             y=450;

         }
        iShowBMP(P1[p].X,P1[p].Y,position_enemy[index_en]); */



        /*iShowBMP2(x_e,y_e,position_enemy[index_en],0);
        iShowBMP2(x_e1,y_e1,position_enemy[index_en1],0);
        iShowBMP2(x_e2,y_e2,position_enemy[index_en2],0);
        */

        iShowBMP2(ex1,ey1,"enemy1.bmp",0);
        iShowBMP2(ex2,ey2,"enemy2.bmp",0);
        iShowBMP2(ex3,ey3,"enemy3.bmp",0);
        iShowBMP2(ex4,ey4,"enemy4.bmp",0);


        if( ((x >= ex1-25 && x<=ex1+40)   && (y>=ey1-33 && y<=ey1+50)) || ((x >= ex2-25 && x<= ex2+40)   && (y>=ey2-33 && y<=ey2+50)) || ((x >= ex3-25 && x<= ex3+40)   && (y>=ey3-33 && y<=ey3+50))
                || ((x >= ex4-25 && x<= ex4+40)   && (y>=ey4-33 && y<=ey4+50)))
        {
            num=num-10;
            x=150;
            y=450;
            PlaySound("enemy.wav",NULL,SND_SYNC);
            PlaySound("Music.wav",NULL,SND_ASYNC | SND_LOOP);

        }

        iShowBMP2(clock_1[0],clock_1[1],"Clock.bmp",0);
        iShowBMP2(clock_1[2],clock_1[3],"Clock.bmp",0);

        for(mk=0; mk<clock_elements ; mk+=2)
        {
            if( (x >= clock_1[mk]-22.5 && x<= clock_1[mk]+30) && (y >= clock_1[mk+1]-33 && y<= clock_1[mk+1]+30) )
            {
                PlaySound("clock_music.wav",NULL,SND_SYNC);
                PlaySound("Music.wav",NULL,SND_ASYNC | SND_LOOP);

                time_rem+=3;
                for(nk=mk; nk<clock_elements; nk=nk+2)
                {
                    clock_1[nk]=clock_1[nk+2];
                    clock_1[nk+1]=clock_1[nk+3];
                }
                clock_elements-=2;

            }
        }



    }

    if(GameState==1)
    {


        Music_on=false;
        if(Music_on)
            PlaySound(0,0,0);
    }

    if(GameState==7)
    {

        Music_on=true;
        if(Music_on)
            PlaySound("Music.wav",NULL,SND_LOOP | SND_ASYNC);
    }


    if(time_rem==0)
    {
        GameState=6;

    }

    if(GameState==6)
    {


        iSetColor(203, 142, 140);
        iFilledRectangle(500,280,400,240);

        iSetColor(0,0,0);
        iText(600,460,"GAME OVER!",GLUT_BITMAP_HELVETICA_18);
        iText(600,400,"YOUR SCORE : ",GLUT_BITMAP_HELVETICA_18);
        iText(750,400,str,GLUT_BITMAP_HELVETICA_18);
        iText(600,340,"Press M for menu.",GLUT_BITMAP_HELVETICA_18);





        fp=fopen("HighestScore.txt","r");
        fscanf(fp,"%d",&h_score);
        fclose(fp);





        if(final_num > h_score)
        {
            fp=fopen("HighestScore.txt","w");
            fprintf(fp,"%d",final_num);
            fclose(fp);
        }
    }

    if(GameState==2)
    {
        iShowBMP(210,0,"instructions.bmp");
        iText(750,20,"Press 'B' to go back to the menu...",GLUT_BITMAP_HELVETICA_12);

         Music_on=true;
        if(Music_on)
            PlaySound("Music.wav",NULL,SND_LOOP | SND_ASYNC);
    }

    if(GameState==4)
    {
        iShowBMP(160,0,"Credits.bmp");
        iText(750,20,"Press 'B' to go back to the menu...",GLUT_BITMAP_HELVETICA_12);

         Music_on=true;
        if(Music_on)
            PlaySound("Music.wav",NULL,SND_LOOP | SND_ASYNC);
    }
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(GameState==0)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if((mx >= 200 && mx <=500) && (my>=450 && my<=510 ) )
            {
                GameState=1;
            }

            if((mx >= 200 && mx <=500) && (my>=370 && my<=430 ) )
            {
                GameState=2;
            }

            if((mx >= 200 && mx <=500) && (my>=210 && my<=270 ) )
            {
                GameState=4;
            }

            if((mx >= 200 && mx <=500) && (my>=130 && my<=190 ) )
            {
                exit(0);
            }

        }
    }

    if(GameState==1)

    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            //place your codes here
            //printf("x = %d, y= %d\n",mx,my);
            x -= 2;
            y-=2;


        }
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            //place your codes here
            x += 2;
            y +=2;

        }
        if(x<0)
            x=0;
        if(x>1400)
            x=1400;
        if(y<0)
            y=0;
        if(y>775)
            y=775;

    }
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

    if(GameState==6)
    {
        if(key=='m' || key=='M')
        {
            GameState=0;
        }


    }

    if(GameState==2 || GameState==4 )
    {
        if(key=='b' || key=='B')
        {
            GameState=0;
        }
    }

    if(GameState==1)
    {
        if(key=='p' || key=='P')
            GameState=7;

        if(key=='m' || key=='M')
            GameState=0;

        if(key=='o' || key=='O')
        {
            Music_on=true;
            if(Music_on)
            PlaySound("Music.wav",NULL,SND_LOOP | SND_ASYNC);
        }

        if(key=='f' || key=='F')
            {
        Music_on=true;
        if(Music_on)
            PlaySound(0,0,0);
            }
    }
    if(GameState==7)
    {
        if(key=='r' || key=='R')
            GameState=1;
    }

    //place your codes for other keys here
}


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(GameState==1)
    {


        if((x>=0 && x<=1400) && (y>=0 && y<=800))
        {

                if((x >= 100 && x<= 200) || ((x>=300 && x<=400) && (y>=0 && y<=660))  || ((x>=500 && x<=600) && (y>=0 && y<=660))  || ((x>=1230 && x<=1330) && (y>=0 && y<=660)) ||
                    ((x>=600 && x<=700) && ((y>=280 && y<=380) ||  (y>=560 && y<=800))) ||
                    ((x>=700 && x<=800) && ((y>=0 && y<=420) ||  (y>=560 && y<=660))) ||
                    ((x>=800 && x<=920) && (y>=280 && y<=660)) ||
                    ((x>=900 && x<=1000) && ((y>=0 && y<=140) || (y>=560 && y<=660) || (y>=320 && y<=420))) ||
                    ((x>=1000 && x<=1100) && ((y>=0 && y<=420) ||  (y>=560 && y<=660))) ||
                    ((x>=1100 && x<=1200) && ((y>=560 && y<=800) ||  (y>=320 && y<=420)) || ((y>=0 && y<= 140) && (x>=900 && x<=1100)) ||
                     ((y>=40 && y<= 140) && (x>=1200 && x<=1400)) ||
                     ( (y>=420 && y <=520) && (x>=0 && x<=400)) ||
                     ( (y>=560 && y<=660) && (x>=300 && x<=1300)) ||
                     ( (y>=420 && y<=520) && (x>=1200 && x<=1400)) ||
                     ( (y>=320 && y<=420) && (x>=700 && x<=1300)) ||
                     ( (y>=420 && y<=520) && (x>=1200 && x<=1400)) ||
                     ( (y>=330 && y<=430) && (x>=300 && x<=600)) ||
                     ( (y>=280 && y<=320) && (x>=500 && x<=900)) ||
                     ( (y>=320 && y<=330) && (x>=500 && x<=600)) ||
                     ( (y>=280 && y<=380) && (x>=600 && x<=700)) ||
                     ( (y>=140 && y<=240) && (x>=300 && x<=600)) ))


            {


                if(key == GLUT_KEY_UP)
                {
                    y +=5;
                    index=1;

                }


                if(key == GLUT_KEY_DOWN)
                {
                    y -= 5;
                    index=0;

                }

                if(key == GLUT_KEY_RIGHT)
                {
                    x +=5;
                    index=2;
                }

                if(key == GLUT_KEY_LEFT)
                {
                    x -= 5;
                    index=3;

                }

            }

        }

        if(x<0)
            x=0;
        if(x>1400)
            x=1400;
        if(y<0)
            y=0;
        if(y>800)
            y=800;
    }

}
//place your codes for other keys here

void change()
{
    if(GameState==1)
    {



        /* index_en++;
         index_en1++;
         index_en2++;
         if(p==7)
             p=0;

         x_e=rand()%1200+100;
         y_e=rand()%600+100;

         x_e1=rand()%1200+100;
         y_e1=rand()%600+100;

         x_e2=rand()%1200+100;
         y_e2=rand()%600+100;

         if(index_en==4)
             index_en=0;
         if(index_en1==4)
             index_en1=0;
         if(index_en2==4)
             index_en2=0;

             */

        ex1=ex1+dx1;
        ex2=ex2+dx2;
        ey3=ey3+dy3;
        ey4=ey4+dy4;

        if(ex1 < 350 || ex1 >1200)
        {
            dx1=dx1*(-1);
        }

        if(ex2<850 || ex2>1200)
        {
            dx2=dx2*(-1);
        }

        if(ey3 <10 || ey3 > 350)
        {
            dy3=dy3*(-1);
        }
        if(ey4 <10 || ey4 > 550)
        {
            dy4=dy4*(-1);
        }
    }
}


void Time_change()
{
    if(GameState==1)
    {


        if(time_rem>0)
        {
            time_rem--;

        }

        if(time_rem==0)
        {
            GameState=6;
            time_rem=60;
            final_num=num;
            num=1;

            x=150;
            y=0;
            array_elements=94;
            for(jk=0; jk<94; jk++)
            {
                point_array[jk]=point_array3[jk];
            }

            clock_elements=8;
            for(ok=0; ok<8; ok++)
            {
                clock_1[ok]=clock_3[ok];
            }
        }


    }

}

int main()
{
    if(Music_on)
        PlaySound("Music.wav",NULL,SND_LOOP | SND_ASYNC);

    iSetTimer(5,change);
    iSetTimer(1000,Time_change);
    //place your own initialization codes here.
    iInitialize(screenwidth,screenheight, "Crowd Town");
    return 0;
}
