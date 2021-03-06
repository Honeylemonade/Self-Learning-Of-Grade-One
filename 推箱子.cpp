// 推箱子.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<conio.h>//接受按键
#include<graphics.h>//图形库
#include<mmsystem.h>//背景音乐的
#pragma comment(lib, "winmm.lib")
using namespace std;//0空地 1墙壁 3终点 4箱子 5人 7目的地的箱子 8人在箱子终点中
IMAGE Blank, Wall, End, Box, Player, DoneBox, DoneP;

int map[8][8] ={
{0,0,0,1,1,1,0,0},
{0,0,0,1,3,1,0,0},
{1,1,1,1,4,1,0,0},
{1,3,0,4,5,1,1,1},
{1,1,1,4,0,4,3,1},
{0,0,1,0,1,1,1,1},
{0,0,1,3,1,0,0,0},
{0,0,1,1,1,0,0,0} };
void D_map()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (map[i][j])
			{
			case 0:putimage(j * 90, i * 90, &Blank);
				break;
			case 1:putimage(j * 90, i * 90, &Wall);
				break;
			case 3:putimage(j * 90, i * 90, &End);
				break;
			case 4:putimage(j * 90, i * 90, &Box);
				break;
			case 5:putimage(j * 90, i * 90, &Player);
				break;
			case 7:putimage(j * 90, i * 90, &DoneBox);
				break;
			case 8:putimage(j * 90, i * 90, &DoneP);
				break;
			}
		}
		cout << endl;
	}
	
}
void play()
{

	int x, y;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				x = i;
				y = j;
			}
		}
	}
	int ch;
	ch=_getch();//不回显的输入一个字符
	switch (ch)
	{
	case 'A':
	case 'a':
		if (map[x][y - 1] == 0||map[x][y-1]==3)
		{
			map[x][y] -= 5;
			map[x][y - 1] += 5;
		}
		else if(map[x][y - 1]==4||map[x][y - 1]==7)
		{ 
			if(map[x][y-2]==0|| map[x][y - 2] ==3)
		    {
			map[x][y] -= 5;
			map[x][y - 1] += 1;
			map[x][y - 2] += 4;
	 	    }
		}
		break;
	case 'W':
	case 'w':
		if (map[x-1][y] == 0 || map[x-1][y] == 3)
		{
			map[x][y] -= 5;
			map[x-1][y] += 5;
		}
		else if (map[x-1][y] == 4 || map[x-1][y] == 7)
		{
			if (map[x-2][y] == 0 || map[x-2][y] == 3)
			{
				map[x][y] -= 5;
				map[x-1][y] += 1;
				map[x-2][y] += 4;
			}
		}
		break;
	case 'S':
	case 's':
		if (map[x+1][y] == 0 || map[x+1][y] == 3)
		{
			map[x][y] -= 5;
			map[x+1][y] += 5;
		}
		else if (map[x+1][y] == 4 || map[x+1][y] == 7)
		{
			if (map[x+2][y] == 0 || map[x+2][y] == 3)
			{
				map[x][y] -= 5;
				map[x+1][y] += 1;
				map[x+2][y] += 4;
			}
		}
		break;
	case 'D':
	case 'd':
		if (map[x][y+1] == 0 || map[x][y+1] == 3)
		{
			map[x][y] -= 5;
			map[x][y+1] += 5;
		}
		else if (map[x][y+1] == 4 || map[x][y+1] == 7)
		{
			if (map[x][y+2] == 0 || map[x][y+2] == 3)
			{
				map[x][y] -= 5;
				map[x][y+1] += 1;
				map[x][y+2] += 4;
			}
		}
		break;
	}
}
void loadpicture()
{
	loadimage(&Blank, L"./image/Blank.jpg",90, 90);
	loadimage(&Wall, L"./image/Wall.jpg", 90, 90);
	loadimage(&End, L"./image/End.jpg", 90, 90);
	loadimage(&Box, L"./image/Box.jpg", 90, 90);
	loadimage(&Player, L"./image/Player.jpg", 90, 90);
	loadimage(&DoneBox, L"./image/DoneBox.jpg", 90, 90);
	loadimage(&DoneP, L"./image/DoneP.jpg", 90, 90);
}
int win()
{
	int num=0;
	for(int i=0;i<8;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 7)
				num++;
		}
	}
	if (num == 4)
	{
		MessageBox(NULL, L"你真棒！！！！", L"恭喜", MB_OK);
		return 1;
	}
}
int main()
{
	mciSendString(L"open ./image/Fragments.mp3 alias music",0,0,0);
	mciSendString(L"play music", 0, 0, 0);
	initgraph(720, 720);
	loadpicture();
	cleardevice();
	while (1)
	{
		system("cls");//功能是清屏，清除所有显示的信息
		D_map();int Win=win();
		if (Win == 1)
			break;
		play();
	}
	getchar();//和system（“pause”）作用基本一致，要求输入一个字符；
	return 0;
}
