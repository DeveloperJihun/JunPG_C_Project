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




void fire(bx, by, x, y, ch) {
    gotoxy(bx, by);
    int a;
    for (int i = bx; i >= MAP_X + 2; i--) {

        textcolor(15);
        drawplayer(x, y);
        gotoxy(i + 1, by);
        textcolor(15);
        printf(" ");

        gotoxy(i, by);
        /*textcolor(i);*/
        printf("%c", ch);
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

//
//int firechoice(bx, by, x, y) {
//    if (gun[0][3] == 0) {
//        fire(bx, by, x, y, 62);
//        return 3;
//    }
//    else if (gun[0][2] == 0) {
//        gotoxy(bx, by);
//        int a;
//        
//        for (int i = bx; i >= MAP_X + 2; i--) {
//
//            textcolor(15);
//            drawplayer(x, y);
//            gotoxy(i + 1, by);
//            textcolor(15);
//            printf(" ");
//
//            gotoxy(i, by);
//            textcolor(i);
//            printf("<");
//            if (i == 20 && by == 10) {
//                gotoxy(i, by);
//                textcolor(15);
//                printf(" ");
//                break;
//                ereasebreed(10, 10);
//            }
//            textcolor(15);
//            Sleep(2);
//
//
//            a = i;
//
//        }
//        gotoxy(a, by);
//        textcolor(15);
//        printf("   ");
//        return 2;
//    }
//    else if (gun[0][1] == 0) {
//        fire(bx, by, x, y, 111);
//        return 1;
//    }
//    else if (gun[0][0] == 0) {
//        fire(bx, by, x, y, 95);
//        return 0;
//    }
//    else {
//        return -1;
//    }
//
//}
