//Author: Rookie118
//Program's Propose: a simulation of a football tournament between two teams
//Completion time: 2017-12-15

#include "Football.h"
#include <windows.h>

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));  //按时间设置随机化种子
	Team t1, t2;
	int ngame = atoi(argv[7]);  //比赛次数变量
	int a1 = atoi(argv[1]), m1 = atoi(argv[2]), d1 = atoi(argv[3]);  //a1，m1，d1分别是队伍1的进攻队员，中场队员，防守队员数量
	int a2 = atoi(argv[4]), m2 = atoi(argv[5]), d2 = atoi(argv[6]);  //同上是队伍2的队员分配
	std::string output_file = argv[8];  //比赛结果输出文件名

	Init_team(t1, a1, m1, d1, ngame);  //队伍初始化
	Init_team(t2, a2, m2, d2, ngame);
	Game_play(t1, t2, ngame, output_file);  //比赛进行函数
	Display_result(t1, t2, output_file);  //输出结果函数

	Sleep(1000);  //延迟1s
	system("pause");
	return 0;
}


