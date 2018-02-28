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
class Person  //��߼�����
{
public:
	std::string name;
	int age;
	double skill;
	double salary;
	Person() {}
	~Person() {}
	virtual void Ini_name() = 0;  //���麯��
	virtual void Ini_age() = 0;
};

class Staff: public Person  //�ڶ�������
{
public:
	Staff() {}
	virtual ~Staff() {}
	virtual void Ini_sta_skill() = 0;
	virtual void Ini_sta_salary() = 0;
	virtual void Inc_skill(Player *[]) {}  //����������Ա���ܺ���
	virtual void Inc_health(Player *[]) {}  //����ʦ������Ա����ֵ����
	virtual void count_spend(Team &, std::string &) {}  //��Ƽ��㻨�Ѻ���
};

class Player: public Person  //�ڶ�������
{
public:
	Player() {}
	virtual ~Player() {}
	virtual void Ini_pla_skill() = 0;
	virtual void Ini_pla_salary() = 0;
	virtual void Dec_health() = 0;
	double health = 100.0;  //ÿ����Ա��󽡿�ֵ
};

class Coach: public Staff
{
public:
	Coach() {}
	~Coach() {}
	virtual void Ini_sta_skill();  //Ա�����ܳ�ʼ������
	virtual void Ini_sta_salary();  //Ա��нˮ��ʼ������
	virtual void Ini_name();  //���ֳ�ʼ��
	virtual void Ini_age();  //�����ʼ��
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
	double cost = 0.0;  //����ܻ��ѳ�ʼֵ
};

class Attacker : public Player
{
public:
	Attacker() {}
	~Attacker() {}
	virtual void Ini_pla_skill();  //��Ա���ܳ�ʼ��
	virtual void Ini_pla_salary();  //��Աнˮ��ʼ��
	virtual void Ini_name();
	virtual void Ini_age();
	void Dec_health();  //��Ա����ֵ���ٺ���
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
	std::string tname;  //������
	int num_game = 0;
	int win_game = 0;
	int drawn_game = 0;  //����ƽ����
	int goal = 0;  //�ܽ�����
	int num_attacker;
	int num_midfielder;
	int num_defender;
	double attack_ability = 0.0;  //�����ܽ�������
	double defend_ability = 0.0;  //�����ܷ�������
	bool Ball_possession = false;  //����Ȩ��־
	std::vector<int> per_goal;  //ÿ������������
	Player *player[11];  //�ڶ�������ָ������
	Staff *staff[3];  //�ڶ�������ָ������
	Team() {}
	~Team() {}
	void Ini_team_name();
	void Calculate_ability();  //���������������
	friend std::ostream & operator << (std::ostream &, Team &);  //������������������
};

void Init_team(Team &, const int &, const int &, const int &, const int &);  //�����ʼ��
void Display_staff(Team &, const std::string &);  //��ʾԱ����Ϣ
void Display_player(Team &, const std::string &);  //��ʾ��Ա��Ϣ
void Game_result(Team &, Team&, const std::string &);  //��ʾ�������
void Display_result(Team &, Team &, const std::string &);  //��ʾ���̽��
void Game_play(Team &, Team &, const int &, const std::string &);

#endif // !"Football.h"

