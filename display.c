#include "display.h"
#define SIZE_OF_ARRAY 60
#pragma warning(disable:4996)
struct auxiliary_variable auvar = { 0,0,0,1,0,0,0 };
struct info_for_game info_game = { 0,240,240,0,0,100,3,0,3,1 };
struct info_for_apple
{
	int count_apple;
	int count_red;
	int count_green;
	int count_blue;
};
struct info_for_apple info_apple = { 0, 0, 0, 0 };

typedef struct
{
	int ax;
	int ay;
	int status;
	int color[3];
}PNT1;
PNT1 apple[SIZE_OF_ARRAY];

typedef struct
{
	float ax;
	float ay;
}PNT2;
PNT2 snake[61];

void renderBitmapString(int h)
{
	int i;
	char simbol[100];
	_itoa(h, simbol, 10);
	char str1[] = "SCORE";
	char str2[] = "YOUR SCORE";
	if (auvar.status_botton != 3 && auvar.status_botton != 0)
	{
		glRasterPos2f(5, 460);
		for (i = 0;str1[i] != '\0';i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
		}
		glRasterPos2f(100, 460);
		for (i = 0;simbol[i] != '\0';i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, simbol[i]);
		}
	}
	if (auvar.status_botton == 3)
	{
		glRasterPos2f(125, 260);
		for (i = 0;str2[i] != '\0';i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);
		}
		glRasterPos2f(305, 260);
		for (i = 0;simbol[i] != '\0';i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, simbol[i]);
		}
	}
}
void renderBitmapString2(int x, int y, int h)
{
	glColor3d(button[h].HihlightColor[0], button[h].HihlightColor[1], button[h].HihlightColor[2]);
	glRasterPos2f(x, y);
	for (int i = 0;button[h].Name[i] != '\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, button[h].Name[i]);
}
void display()
{
	if (info_game.restart == 1)
	{
		info_game.restart = 0;
		info_game.x = 240, info_game.y = 240;
		info_game.time1 = 0;
		info_game.time2 = 0;
		info_game.count_block = SIZE_OF_ARRAY;
		info_apple.count_apple = 0;
		info_apple.count_red = 0;
		info_apple.count_blue = 0;
		info_apple.count_green = 0;
		info_game.speed = 3;
		info_game.score = 0;
		info_game.napravlenie = 1;
		info_game.kef = 1;
		for (int i = 0; i < info_game.count_block;i++)
		{
			snake[i].ax = info_game.x - 8 * i;
			snake[i].ay = info_game.y;
		}
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (auvar.status_botton != 1)
	{
		glColor3f(255, 255, 255);
		glBegin(GL_POLYGON);
		glVertex2f(button[auvar.count_keys - 1].x - 155, button[auvar.count_keys - 1].y + 35);
		glVertex2f(button[auvar.count_keys - 1].x - 155, button[auvar.count_keys - 1].y - 35);
		glVertex2f(button[auvar.count_keys - 1].x + 155, button[auvar.count_keys - 1].y - 35);
		glVertex2f(button[auvar.count_keys - 1].x + 155, button[auvar.count_keys - 1].y + 35);
		glEnd();
		for (int i = 0;i < auvar.num_button;i++)
		{
			if (auvar.status_botton == button[i].status)
			{
				glColor3f(button[i].Color[0], button[i].Color[1], button[i].Color[2]);
				glBegin(GL_POLYGON);
				glVertex2f(button[i].x - 150, button[i].y + 30);
				glVertex2f(button[i].x - 150, button[i].y - 30);
				glVertex2f(button[i].x + 150, button[i].y - 30);
				glVertex2f(button[i].x + 150, button[i].y + 30);
				glColor3d(button[i].HihlightColor[0], button[i].HihlightColor[1], button[i].HihlightColor[2]);
				glEnd();
			}
		}
		for (int i = 0;i < auvar.num_button;i++)
		{
			if (auvar.status_botton == button[i].status)
			{
				renderBitmapString2(button[i].x - 50, button[i].y, i);
			}
		}
	}
	if (auvar.status_botton == 1)
	{
		renderBitmapString(info_game.score);
		if (info_game.napravlenie == 1)
		{
			for (int i = SIZE_OF_ARRAY - 2;i >= 0;i--)
			{
				snake[i + 1].ax = snake[i].ax;
				snake[i + 1].ay = snake[i].ay;
			}
			snake[0].ax += info_game.speed;
		}
		if (info_game.napravlenie == 2)
		{
			for (int i = SIZE_OF_ARRAY - 2;i >= 0;i--)
			{
				snake[i + 1].ax = snake[i].ax;
				snake[i + 1].ay = snake[i].ay;
			}
			snake[0].ax -= info_game.speed;
		}
		if (info_game.napravlenie == 3)
		{
			for (int i = SIZE_OF_ARRAY - 2;i >= 0;i--)
			{
				snake[i + 1].ax = snake[i].ax;
				snake[i + 1].ay = snake[i].ay;
			}
			snake[0].ay += info_game.speed;
		}
		if (info_game.napravlenie == 4)
		{
			for (int i = SIZE_OF_ARRAY - 2;i >= 0;i--)
			{
				snake[i + 1].ax = snake[i].ax;
				snake[i + 1].ay = snake[i].ay;
			}
			snake[0].ay -= info_game.speed;
		}
		if (snake[0].ax >= 480 || snake[0].ay >= 480 || snake[0].ax <= 0 || snake[0].ay <= 0)
		{
			auvar.status_botton = 3;
		}

		for (int d = 1;d < SIZE_OF_ARRAY;d++)
		{
			if (abs(snake[0].ax - snake[d].ax) < info_game.speed - 1 && abs(snake[0].ay - snake[d].ay) < info_game.speed - 1)
			{
				auvar.status_botton = 3;
			}
		}
		for (int i = 0;i < info_apple.count_apple;i++)
		{

			if (abs(snake[0].ax - apple[i].ax) < 10 && abs(snake[0].ay - apple[i].ay) < 10)
			{
				if (apple[i].status == 0)
				{
					info_game.kef += 0.1;
					for (int d = i;d < info_apple.count_apple;d++)
					{
						apple[d] = apple[d + 1];
					}
					info_apple.count_apple--;
					info_apple.count_green--;
					info_game.speed += 0.05;
					//info_game.count_block+=3;
					info_game.score++;
					break;
				}
				if (apple[i].status == 1)
				{
					info_game.kef += 0.3;
					for (int d = i;d < info_apple.count_apple;d++)
					{
						apple[d] = apple[d + 1];
					}
					info_apple.count_apple--;
					info_apple.count_red--;
					info_game.speed += 3;
					break;
				}
				if (apple[i].status == 2)
				{
					//info_game.count_block++;
					for (int d = i;d < info_apple.count_apple;d++)
					{
						apple[d] = apple[d + 1];
					}
					info_apple.count_apple--;
					info_apple.count_blue--;
					info_game.speed -= 0.5;
					break;
				}
			}
		}
		if (info_game.time1 % 107 == 0 && info_game.time1 != info_game.time2)
		{
			info_game.time2 = info_game.time1;
			int polozhenie_nuzhnogo_apple = 0;
			//polozhenie_apple_ax = rand() % 480;
			//polozhenie_apple_ay = rand() % 480;
			apple[info_apple.count_apple].ax = rand() % 480;
			apple[info_apple.count_apple].ay = rand() % 480;
			apple[info_apple.count_apple].status = 0;
			apple[info_apple.count_apple].color[0] = 0;
			apple[info_apple.count_apple].color[1] = 1;
			apple[info_apple.count_apple].color[2] = 0;
			info_apple.count_apple++;
			info_apple.count_green++;
			if (info_apple.count_green > 4)
			{
				for (int i = 0;i < info_apple.count_apple;i++)
				{
					if (apple[i].status == 0)
					{
						polozhenie_nuzhnogo_apple = i;
						break;
					}

				}
				for (int i = polozhenie_nuzhnogo_apple;i < info_apple.count_apple;i++)
				{
					apple[i] = apple[i + 1];
				}
			}
			info_game.speed += 0.01;
		}
		if (info_game.time1 % 383 == 0 && info_game.time1 != info_game.time2)
		{
			info_game.time2 = info_game.time1;
			int polozhenie_nuzhnogo_apple = 0;
			//polozhenie_apple_ax = rand() % 480;
			//polozhenie_apple_ay = rand() % 480;
			apple[info_apple.count_apple].ax = rand() % 480;
			apple[info_apple.count_apple].ay = rand() % 480;
			apple[info_apple.count_apple].status = 1;
			apple[info_apple.count_apple].color[0] = 1;
			apple[info_apple.count_apple].color[1] = 0;
			apple[info_apple.count_apple].color[2] = 0;
			info_apple.count_apple++;
			info_apple.count_red++;
			if (info_apple.count_red > 3)
			{
				for (int i = 0;i < info_apple.count_apple;i++)
				{
					if (apple[i].status == 1)
					{
						polozhenie_nuzhnogo_apple = i;
						break;
					}

				}
				for (int i = polozhenie_nuzhnogo_apple;i < info_apple.count_apple;i++)
				{
					apple[i] = apple[i + 1];
				}
			}
		}
		if (info_game.time1 % 1327 == 0 && info_game.time1 != info_game.time2)
		{
			info_game.time2 = info_game.time1;
			int polozhenie_nuzhnogo_apple = 0;
			//polozhenie_apple_ax = rand() % 480;
			//polozhenie_apple_ay = rand() % 480;
			apple[info_apple.count_apple].ax = rand() % 480;
			apple[info_apple.count_apple].ay = rand() % 480;
			apple[info_apple.count_apple].status = 2;
			apple[info_apple.count_apple].color[0] = 0;
			apple[info_apple.count_apple].color[1] = 0;
			apple[info_apple.count_apple].color[2] = 1;
			info_apple.count_apple++;
			info_apple.count_blue++;
			if (info_apple.count_blue > 3)
			{
				for (int i = 0;i < info_apple.count_apple;i++)
				{
					if (apple[i].status == 2)
					{
						polozhenie_nuzhnogo_apple = i;
						break;
					}

				}
				for (int i = polozhenie_nuzhnogo_apple;i < info_apple.count_apple;i++)
				{
					apple[i] = apple[i + 1];
				}
			}
		}
		for (int i = 0;i < info_apple.count_apple;i++)
		{
			glPointSize(10);
			glColor3f(apple[i].color[0], apple[i].color[1], apple[i].color[2]);
			glBegin(GL_POINTS);
			glVertex2f(apple[i].ax, apple[i].ay);
			glEnd();
		}
		glPointSize(16);
		glColor3f(1, 0, 0);
		for (int i = 0;i < info_game.count_block;i++)
		{
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
			glVertex2f(snake[i].ax + 8, snake[i].ay + 8);
			glVertex2f(snake[i].ax - 8, snake[i].ay + 8);
			glVertex2f(snake[i].ax - 8, snake[i].ay - 8);
			glVertex2f(snake[i].ax + 8, snake[i].ay - 8);
			glEnd();
		}
	}
	renderBitmapString(info_game.score);
	glutSwapBuffers();

}
