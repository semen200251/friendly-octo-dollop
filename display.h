#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
extern struct auxiliary_variable auvar;
extern struct info_for_game info_game;
struct auxiliary_variable
{
	int num_button;
	int k;
	int back_keys;
	int count_keys;
	int status_botton;
	int d;
	int g;
};
struct info_for_game
{
	int restart;
	int x;
	int y;
	int time1;
	int time2;
	int count_block;
	float speed;
	int score;
	int napravlenie;
	float kef;
};
typedef struct
{
	int x;
	int y;
	char Name[20];
	int Color[3];
	int HihlightColor[3];
	int status;
	int count_key;
}PNT;
PNT button[40];
void display();
void renderBitmapString2(int x, int y, int h);
void renderBitmapString(int h);
