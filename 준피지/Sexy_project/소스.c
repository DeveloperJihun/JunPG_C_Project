#pragma warning (disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#define MAP_X 2
#define MAP_Y 1
#define MAP_WIDTH 100
#define MAP_HEIGHT 20
#define MAXBULLET 6

int MaxX = 79;
int MaxY = 24;
int hp[5] = { 1,1,1,1,1 };
int gun[2][4] = { {1, 1, 1, 1}, {1, 1, 3, 5} };
char gun1[30] = { "물총" };
char gun2[30] = { "스나이퍼" };
char gun3[30] = { "무지개총" };
char gun4[30] = { "고등어총" };
char sold[8] = { "SOLDOUT\0" };


int money = 1000;
int x = 30, y = 6;
int indun = 0;
void state(addhp, addmoney);
void gotoxy(int x, int y);
void breed();
void first();
void ereasebreed();
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;



void dunjun() {
    breed(10, 10);


}

void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void state(int addhp, int addmoney) {

    money = addmoney + money;
    int hpx = 1;
    int hpy = 22;


    gotoxy(hpx, hpy + 1);
    printf("MONEY : %d원", money);

}
void shop() {
    for (int i = 0; i <= 4; i++) {
        if (gun[0][i] == 0) {
            if (i == 0) {
                for (int i = 0; i <= 7; i++) {
                    gun1[i] = sold[i];
                }

            }
            if (i == 1) {
                for (int i = 0; i <= 7; i++) {
                    gun2[i] = sold[i];
                }
            }
            if (i == 2) {
                for (int i = 0; i <= 7; i++) {
                    gun3[i] = sold[i];
                }
            }
            if (i == 3) {
                for (int i = 0; i <= 7; i++) {
                    gun4[i] = sold[i];
                }
            }

        }
    }
    int itemx = 30;
    int itemy = 22;
    int isshop = 0;
    gotoxy(itemx, itemy);
    printf("1. 물건보기 2. 나간다");
    while (isshop == 0)
    {
        char in = _getch();




        switch (in)
        {
        case '1':
            gotoxy(itemx, itemy);
            printf("1. %s 2. %s 3. %s 4. %s", gun1, gun2, gun3, gun4);
            gotoxy(itemx, itemy + 1);
            printf("가격1       1         3          5");

            char in2 = _getch();
            switch (in2)
            {
            case '1':
                gun[0][0] = 0;
                isshop = 1;
                gotoxy(itemx, itemy);
                printf("                                                        ");
                gotoxy(itemx, itemy + 1);
                printf("                                                        ");
                state(0, -1);
                break;

            case '2':
                gun[0][1] = 0;
                isshop = 1;
                gotoxy(itemx, itemy);
                printf("                                                        ");
                gotoxy(itemx, itemy + 1);
                printf("                                                        ");
                state(0, -1);
                break;

            case '3':
                gun[0][2] = 0;
                isshop = 1;
                gotoxy(itemx, itemy);
                printf("                                                        ");
                gotoxy(itemx, itemy + 1);
                printf("                                                        ");
                state(0, -3);
                break;
            case '4':
                gun[0][3] = 0;
                isshop = 1;
                gotoxy(itemx, itemy);
                printf("                                                        ");
                gotoxy(itemx, itemy+1);
                printf("                                                        ");
                state(0, -5);
                break;
            }




            break;
        case '2':
            isshop = 1;
            gotoxy(itemx, itemy);
            printf("                                                        ");
            gotoxy(itemx, itemy + 1);
            printf("                                                        ");
            break;

        }




    }

}
//void fire(int bx, int by)
//{
//    gotoxy(bx - 1, by);
//    printf("<");
//    for (int i = (bx - 2); i >= MAP_X - 1; i--) {
//        gotoxy(i - 1, by);
//
//        printf("  ");
//
//        gotoxy(i, by);
//        printf("<");
//        Sleep(100);
//
//    }
//
//}
void draw_map(void) { 
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y);
        printf("■");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
        gotoxy(MAP_X, i);
        printf("■");
        gotoxy(MAP_X + MAP_WIDTH, i);
        printf("■");
    }
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1);
        printf("■");
    }
}

void setcursortype(CURSOR_TYPE c)
{
    CONSOLE_CURSOR_INFO CurInfo;
    switch (c)
    {
    case NOCURSOR:
        CurInfo.dwSize = 1;
        CurInfo.bVisible = FALSE;
        break;
    case SOLIDCURSOR:
        CurInfo.dwSize = 100;
        CurInfo.bVisible = TRUE;
        break;
    case NORMALCURSOR:
        CurInfo.dwSize = 20;
        CurInfo.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}


void PlayerControl() {
    draw_map();
    setcursortype(NOCURSOR);

    char ch;
    first();
    int i;
    int bx;
    int by;
    state(0, 0);
    gotoxy(x, y);
    printf("\\()()/");
    gotoxy(x, y + 1);
    printf(" \\  /");
    gotoxy(x, y + 2);
    printf("  \\/");
    gotoxy(1, 26);
    printf("%d, %d", x, y);


    while (1)//플레이어 이동
    {
        if (hp[0] == 0 && hp[1] == 0 && hp[2] == 0 && hp[3] == 0 && hp[4] == 0) {
            for (int j = 0; j <= 100; j++) {
                state(0, 1137);
                Sleep(1);
            }

            for (int i = 0; i <= 4; i++) {
                hp[i] = 1;
            }
        }
        ch = '\0';
        bx = x - 1;
        by = y;
        if (kbhit())

        {
            bx = x - 1;
            by = y;
            ch = _getch();
            textcolor(15);
            gotoxy(x, y);
            printf("        ");
            gotoxy(x, y + 1);
            printf("      ");
            gotoxy(x, y + 2);
            printf("      ");


            switch (ch)
            {
            case 'w':

                if (y > 2) y--;

                break;
            case 's':
                if (y < MAP_HEIGHT - 4) y++;
                break;
            case 'a':
                if (x > 6) x--;
                break;
            case 'd':
                if (x < MAP_WIDTH - 6) x++;
                break;
            case 'n':


                if (gun[0][3] == 0) {
                    gotoxy(bx, by);
                    int a;
                    for (int i = bx; i >= MAP_X + 2; i--) {

                        textcolor(15);
                        drawplayer(x, y);
                        gotoxy(i + 1, by);
                        textcolor(15);
                        printf("          ");

                        gotoxy(i, by);
                        /*textcolor(i);*/
                        char cch[] = "<・)))><<";
                        printf("%s", cch);
                        if (i == 20 && by == 10) {
                            gotoxy(i, by);
                            textcolor(15);
                            printf("         ");
                            break;
                            ereasebreed(10, 10);
                        }
                        textcolor(15);
                        Sleep(2);




                    }
                    a = MAP_X + 2;
                    gotoxy(a, by);
                    textcolor(15);
                    printf("        ");

                }
                else if (gun[0][2] == 0) {
                    gotoxy(bx, by);
                    int a;

                    for (int i = bx; i >= MAP_X + 2; i--) {

                        textcolor(15);
                        drawplayer(x, y);
                        gotoxy(i + 1, by);
                        textcolor(15);
                        printf(" ");

                        gotoxy(i, by);
                        textcolor(i);
                        printf("<");
                        if (i == 20 && by == 10) {
                            gotoxy(i, by);
                            textcolor(15);
                            printf(" ");
                            break;
                            ereasebreed(10, 10);
                        }
                        textcolor(15);
                        Sleep(2);


                        a = i;

                    }
                    gotoxy(a, by);
                    textcolor(15);
                    printf("   ");

                }
                else if (gun[0][1] == 0) {
                    fire(bx, by, x, y, 111);

                }
                else if (gun[0][0] == 0) {
                    fire(bx, by, x, y, 95);

                }
                else {
                    fire(bx, by, x, y, 92);
                }
                if (by >= 10 && by <= 14) {
                    hp[by - 10] = 0;
                }

                break;
            }
            if (y <= 4 && x <= 8) {
                shop();
                x = 70; y = 6;
                first();
            }
            else if (y <= 4 && x >= 50 && x <= 57) {

                first();
                dunjun();
                x = 70; y = 6;

            }
            drawplayer(x, y);


            Sleep(5);

        }
    }


}
//void drawbullet(bx, by) {
//    gotoxy(bx, by);
//    putch(' ');
//    if (by == 0)
//    {
//        bx = -1;
//    }
//    else
//    {
//        bx--;
//        gotoxy(bx, by);
//        putch('<');
//    }
//}
int drawplayer(x, y) {
    gotoxy(x, y);
    printf("\\()()/");
    gotoxy(x, y + 1);
    printf(" \\  /");
    gotoxy(x, y + 2);
    printf("  \\/");
    gotoxy(1, 26);
    printf("%d, %d", x, y);

}

void breed(int hp, int dam) {
    int randomx = 0;
    int randomy = 0;
    randomy = 10;
    randomx = 20;
    char a = 'ｰ';
    gotoxy(randomx, randomy);
    printf("　_ ,,.,,,_");
    gotoxy(randomx, randomy + 1);
    printf("(:(　　　..)");
    gotoxy(randomx, randomy + 2);
    printf(" |:| 'ω' |");
    gotoxy(randomx, randomy + 3);
    printf(" |:|　　　|");
    gotoxy(randomx, randomy + 4);
    printf("　`''`----´");

}
void ereasebreed(int hp, int dam) {
    int randomx = 0;
    int randomy = 0;
    randomy = 10;
    randomx = 20;
    char a = 'ｰ';
    gotoxy(randomx, randomy);
    printf("         ");
    gotoxy(randomx, randomy + 1);
    printf("         ");
    gotoxy(randomx, randomy + 2);
    printf("          ");
    gotoxy(randomx, randomy + 3);
    printf("    　　　 ");
    gotoxy(randomx, randomy + 4);
    printf("　         ");
}

void gotoxy(int x, int y)
{
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}



void first() {
    if (indun == 0) {
        for (int i = 0; i <= 4; i++) {
            hp[i] = 1;
        }
        int shopx = 5;
        int shopy = 2;
        gotoxy(shopx, shopy);
        printf("--상 점--");
        gotoxy(shopx, shopy + 1);
        printf("|       |");
        gotoxy(shopx, shopy + 2);
        printf("|  ( )  |");
        int denx = 50;
        int deny = 2;
        gotoxy(denx, deny);
        printf("--던 준--");

        gotoxy(denx, deny + 1);
        printf("|       |");
        gotoxy(denx, deny + 2);
        printf("|  ( )  |");
    }
}

int main() {
    PlayerControl();

}