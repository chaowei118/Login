//Author: Rookie118
//Program's Propose: a simulation of a football tournament between two teams
//Completion time: 2017-12-15

#ifndef _FOOTBALL_H
#define _FOOTBALL_H

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

class Team;
class Player;
class Person  //最高级别父类
{
public:
	std::string name;
	int age;
	double skill;
	double salary;
	Person() {}
	~Person() {}
	virtual void Ini_name() = 0;  //纯虚函数
	virtual void Ini_age() = 0;
};

class Staff: public Person  //第二级父类
{
public:
	Staff() {}
	virtual ~Staff() {}
	virtual void Ini_sta_skill() = 0;
	virtual void Ini_sta_salary() = 0;
	virtual void Inc_skill(Player *[]) {}  //教练增加球员技能函数
	virtual void Inc_health(Player *[]) {}  //理疗师增加球员健康值函数
	virtual void count_spend(Team &, std::string &) {}  //会计计算花费函数
};

class Player: public Person  //第二级父类
{
public:
	Player() {}
	virtual ~Player() {}
	virtual void Ini_pla_skill() = 0;
	virtual void Ini_pla_salary() = 0;
	virtual void Dec_health() = 0;
	double health = 100.0;  //每个球员最大健康值
};

class Coach: public Staff
{
public:
	Coach() {}
	~Coach() {}
	virtual void Ini_sta_skill();  //员工技能初始化函数
	virtual void Ini_sta_salary();  //员工薪水初始化函数
	virtual void Ini_name();  //名字初始化
	virtual void Ini_age();  //年龄初始化
	virtual void Inc_skill(Player *[]);
private:
};

class Physio : public Staff
{
public:
	Physio() {}
	~Physio() {}
	virtual void Ini_sta_skill();
	virtual void Ini_sta_salary();
	virtual void Ini_name();
	virtual void Ini_age();
	virtual void Inc_health(Player *[]);
private:
};

class Accountant : public Staff
{
public:
	Accountant() {}
	~Accountant() {}
	virtual void Ini_sta_skill();
	virtual void Ini_sta_salary();
	virtual void Ini_name();
	virtual void Ini_age();
	virtual void count_spend(Team &, std::string &);
private:
	double cost = 0.0;  //球队总花费初始值
};

class Attacker : public Player
{
public:
	Attacker() {}
	~Attacker() {}
	virtual void Ini_pla_skill();  //球员技能初始化
	virtual void Ini_pla_salary();  //球员薪水初始化
	virtual void Ini_name();
	virtual void Ini_age();
	void Dec_health();  //球员健康值减少函数
private:
};

class Midfielder : public Player
{
public:
	Midfielder() {}
	~Midfielder() {}
	virtual void Ini_pla_skill();
	virtual void Ini_pla_salary();
	virtual void Ini_name();
	virtual void Ini_age();
	void Dec_health();
private:

};

class Defender : public Player
{
public:
	Defender() {}
	~Defender() {}
	virtual void Ini_pla_skill();
	virtual void Ini_pla_salary();
	virtual void Ini_name();
	virtual void Ini_age();
	void Dec_health();
private:

};

class Goalkeeper : public Player
{
public:
	Goalkeeper() {}
	~Goalkeeper() {}
	virtual void Ini_pla_skill();
	virtual void Ini_pla_salary();
	virtual void Ini_name();
	virtual void Ini_age();
	void Dec_health();
private:
};

class Team
{
public:
	std::string tname;  //队伍名
	int num_game = 0;
	int win_game = 0;
	int drawn_game = 0;  //比赛平局数
	int goal = 0;  //总进球数
	int num_attacker;
	int num_midfielder;
	int num_defender;
	double attack_ability = 0.0;  //队伍总进攻能力
	double defend_ability = 0.0;  //队伍总防御能力
	bool Ball_possession = false;  //控球权标志
	std::vector<int> per_goal;  //每场比赛进球数
	Player *player[11];  //第二级父类指针数组
	Staff *staff[3];  //第二级父类指针数组
	Team() {}
	~Team() {}
	void Ini_team_name();
	void Calculate_ability();  //计算队伍能力函数
	friend std::ostream & operator << (std::ostream &, Team &);  //对输出运算符进行重载
};

void Init_team(Team &, const int &, const int &, const int &, const int &);  //队伍初始化
void Display_staff(Team &, const std::string &);  //显示员工信息
void Display_player(Team &, const std::string &);  //显示球员信息
void Game_result(Team &, Team&, const std::string &);  //显示比赛结果
void Display_result(Team &, Team &, const std::string &);  //显示赛程结果
void Game_play(Team &, Team &, const int &, const std::string &);

#endif // !"Football.h"

