//Author: Rookie118
//Program's Propose: a simulation of a football tournament between two teams
//Completion time: 2017-12-15

#include "Football.h"

using namespace std;

string team_name[20] = { "Arsenal", "Liverpool", "Manchester United", "Chelsea", "Manchester City", "Tottenham Hotspur", "Everton", "Sunderland", "Fulham", "Birmingham City", "FC Barcelona", "Racing Santander", "Real Madrid CF", "AC Milan", "Roma", "Real Sociedad", "Atalanta", "Como", "Juventus", "Lazio"};
//队伍名数组
string fname[15] = { "Bob", "Alice", "John", "Bush", "Newman", "Edwiin", "Daniel", "Colin", "Ben", "Archer", "Patrick", "Quincy", "Robert", "Stanford", "Taylor"};
//姓数组
string lname[15] = { "Gipson", "Baron", "Christ", "Duncan", "Edison", "Frank", "George", "Herman", "Ingemar", "Joyce", "Kevin", "Lambert", "Marvin", "Norman", "Osborn"};
//名数组
char team_flag = 1;  //队伍标志

void Team::Ini_team_name()
{
	tname = team_name[rand() % 20];  //队伍名随机化
}

void Team::Calculate_ability()
{
	int i;
	for (i = 0; i < num_attacker + num_midfielder; ++i)
	{
		attack_ability += player[i]->skill * (player[i]->health / 100.0);
	}
	for (i = num_attacker; i < 10; ++i)
	{
		defend_ability += player[i]->skill * (player[i]->health / 100.0);
	}
}

ostream & operator << (ostream & output, Team & _team)
{
	int j;
	output << "The team's name: " << _team.tname << endl;

	output << "The coach's name: " << _team.staff[0]->name << endl;
	output << "The coach's age: " << _team.staff[0]->age << endl;
	output << "The coach's skill: " << _team.staff[0]->skill << endl;
	output << "The coach's salary: " << _team.staff[0]->salary << endl;

	output << "The physio's name: " << _team.staff[1]->name << endl;
	output << "The physio's age: " << _team.staff[1]->age << endl;
	output << "The physio's skill: " << _team.staff[1]->skill << endl;
	output << "The physio's salary: " << _team.staff[1]->salary << endl;

	output << "The accountant's name: " << _team.staff[2]->name << endl;
	output << "The accountant's age: " << _team.staff[2]->age << endl;
	output << "The accountant's skill: " << _team.staff[2]->skill << endl;
	output << "The accountant's salary: " << _team.staff[2]->salary << endl;

	for (j = 0; j < _team.num_attacker; ++j)
	{
		output << "The attacker" << j + 1 << "'s name: " << _team.player[j]->name << endl;
		output << "The attacker" << j + 1 << "'s age: " << _team.player[j]->age << endl;
		output << "The attacker" << j + 1 << "'s skill: " << _team.player[j]->skill << endl;
		output << "The attacker" << j + 1 << "'s salary: " << _team.player[j]->salary << endl;
		output << "The attacker" << j + 1 << "'s health: " << _team.player[j]->health << endl;
	}
	for (; j < _team.num_attacker + _team.num_midfielder; ++j)
	{
		output << "The midfielder" << j - _team.num_attacker + 1 << "'s name: " << _team.player[j]->name << endl;
		output << "The midfielder" << j - _team.num_attacker + 1 << "'s age: " << _team.player[j]->age << endl;
		output << "The midfielder" << j - _team.num_attacker + 1 << "'s skill: " << _team.player[j]->skill << endl;
		output << "The midfielder" << j - _team.num_attacker + 1 << "'s salary: " << _team.player[j]->salary << endl;
		output << "The midfielder" << j - _team.num_attacker + 1 << "'s health: " << _team.player[j]->health << endl;
	}
	for (;j < 10; ++j)
	{
		output << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s name: " << _team.player[j]->name << endl;
		output << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s age: " << _team.player[j]->age << endl;
		output << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s skill: " << _team.player[j]->skill << endl;
		output << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s salary: " << _team.player[j]->salary << endl;
		output << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s health: " << _team.player[j]->health << endl;
	}
	output << "The goalkeeper's name: " << _team.player[j]->name << endl;
	output << "The goalkeeper's age: " << _team.player[j]->age << endl;
	output << "The goalkeeper's skill: " << _team.player[j]->skill << endl;
	output << "The goalkeeper's salary: " << _team.player[j]->salary << endl;
	output << "The goalkeeper's health: " << _team.player[j]->health << endl;
	return output;
}


void Coach::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];  //姓名随机化
}

void Coach::Ini_age()
{
	if (rand() % 2 == 0)
		age = 40 - (rand() % 10 + 1);  //年龄在30到50岁之间浮动
	else
		age = 40 + (rand() % 10 + 1);
}

void Coach::Ini_sta_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);  //技能在50到70之间浮动
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Coach::Ini_sta_salary()
{
	salary = 7000.0 + skill / 100.0 * 3500.0;  //员工薪水在3500到10500浮动
}

void Coach::Inc_skill(Player *_player[])
{
		for (int i = 0; i < 11; ++i)
		{
			if ((double)rand() / RAND_MAX < skill / 100.0)  //根据教练技能值判断是否增加球员技能值
			{
				_player[i]->skill += skill * 0.015;
				if (_player[i]->skill > 100.0)  //球员技能最大值为100
				{
					_player[i]->skill = 100.0;
				}
			}
		}
}

void Physio::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];
}

void Physio::Ini_age()
{
	if (rand() % 2 == 0)
		age = 35 - (rand() % 10 + 1);  //年龄在25到45岁之间浮动
	else
		age = 35 + (rand() % 10 + 1);
}

void Physio::Ini_sta_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Physio::Ini_sta_salary()
{
	salary = 6000.0 + skill / 100.0 * 3000.0;  //员工薪水在3000到9000浮动
}

void Physio::Inc_health(Player *_player[])
{
	for (int i = 0; i < 11; ++i)
	{
		_player[i]->health += skill / 10.0;  //根据理疗师技能值增加球员健康值
		if (_player[i]->health > 100.0)  //球员最大健康值为100
			_player[i]->health = 100.0;
	}
}

void Accountant::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];
}

void Accountant::Ini_age()
{
	if (rand() % 2 == 0)
		age = 35 - (rand() % 10 + 1);
	else
		age = 35 + (rand() % 10 + 1);
}

void Accountant::Ini_sta_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Accountant::Ini_sta_salary()
{
	salary = 5000.0 + skill / 100.0 * 2500.0;  //员工薪水在2500到7500浮动
}

void Accountant::count_spend(Team &_team, string &_output_file)
{
	for (int i=0; i<3; ++i)
	{
		cost += _team.staff[i]->salary;
	}
	for (int j=0; j<11; ++j)
	{
		cost += _team.player[j]->salary;
	}
	cout << "The cost of " << _team.tname << " : " << cost << endl;

	ofstream fout(_output_file, ios_base::app);
	fout << "The cost of " << _team.tname << " : " << cost << endl;
	fout.close();
}

void Attacker::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];
}

void Attacker::Ini_age()
{
	if (rand() % 2 == 0)
		age = 28 - (rand() % 10 + 1);  //年龄在18到38岁浮动
	else
		age = 28 + (rand() % 10 + 1);
}

void Attacker::Ini_pla_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Attacker::Ini_pla_salary()
{
	salary = 4000.0 + skill / 100.0 * 2000.0;  //球员薪水在2000到6000浮动
}

void Attacker::Dec_health()
{
	health -= 20.0 ;
	if (health < 0.0)  //球员最低健康值为0
	{
		health = 0.0;
	}
}

void Midfielder::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];
}

void Midfielder::Ini_age()
{
	if (rand() % 2 == 0)
		age = 28 - (rand() % 10 + 1);
	else
		age = 28 + (rand() % 10 + 1);
}

void Midfielder::Ini_pla_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Midfielder::Ini_pla_salary()
{
	salary = 4000.0 + skill / 100.0 * 2000.0;
}

void Midfielder::Dec_health()
{
	health -= 25.0 ; //* (1 - skill * 0.2 / 100.0)
	if (health < 0.0)
	{
		health = 0.0;
	}
}

void Defender::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];
}

void Defender::Ini_age()
{
	if (rand() % 2 == 0)
		age = 28 - (rand() % 10 + 1);
	else
		age = 28 + (rand() % 10 + 1);
}

void Defender::Ini_pla_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Defender::Ini_pla_salary()
{
	salary = 4000.0 + skill / 100.0 * 2000.0;
}

void Defender::Dec_health()
{
	health -= 20.0 ;
	if (health < 0.0)
	{
		health = 0.0;
	}
}

void Goalkeeper::Ini_name()
{
	name = fname[rand() % 15] + " " + lname[rand() % 15];
}

void Goalkeeper::Ini_age()
{
	if (rand() % 2 == 0)
		age = 28 - (rand() % 10 + 1);
	else
		age = 28 + (rand() % 10 + 1);
}

void Goalkeeper::Ini_pla_skill()
{
	if (rand() % 2 == 0)
		skill = 60.0 - (double)(rand() % 11);
	else
		skill = 60.0 + (double)(rand() % 11);
}

void Goalkeeper::Ini_pla_salary()
{
	salary = 4000.0 + skill / 100.0 * 2000.0;
}

void Goalkeeper::Dec_health()
{
	health -= 15.0 ;
	if (health < 0.0)
	{
		health = 0.0;
	}
}

void Init_team(Team &_team, int &a, int &m, int &d, int &n)
{
	int i, j;
	cout.setf(ios::fixed, ios::floatfield);  //设置输出格式
	cout.precision(2);
	_team.Ini_team_name();
	_team.num_attacker = a;
	_team.num_midfielder = m;
	_team.num_defender = d;
	_team.num_game = n;
	_team.staff[0] = new Coach();  //调用Coach类构造函数创建Coach对象
	_team.staff[1] = new Physio();
	_team.staff[2] = new Accountant();
	for (i = 0; i < 3; ++i)
	{
		_team.staff[i]->Ini_name();  //用父类指针调用子类成员函数
		_team.staff[i]->Ini_age();
		_team.staff[i]->Ini_sta_skill();
		_team.staff[i]->Ini_sta_salary();
	}
	for (j = 0; j < _team.num_attacker; ++j)
	{
		_team.player[j] = new Attacker();
		_team.player[j]->Ini_name();  //用父类指针调用子类成员函数
		_team.player[j]->Ini_age();
		_team.player[j]->Ini_pla_skill();
		_team.player[j]->Ini_pla_salary();
	}
	for (; j < _team.num_attacker + _team.num_midfielder; ++j)
	{
		_team.player[j] = new Midfielder();
		_team.player[j]->Ini_name();
		_team.player[j]->Ini_age();
		_team.player[j]->Ini_pla_skill();
		_team.player[j]->Ini_pla_salary();
	}
	for (; j < 10; ++j)
	{
		_team.player[j] = new Defender();
		_team.player[j]->Ini_name();
		_team.player[j]->Ini_age();
		_team.player[j]->Ini_pla_skill();
		_team.player[j]->Ini_pla_salary();
	}
	_team.player[j] = new Goalkeeper();
	_team.player[j]->Ini_name();
	_team.player[j]->Ini_age();
	_team.player[j]->Ini_pla_skill();
	_team.player[j]->Ini_pla_salary();
	//_team.Calculate_ability();
	if (team_flag == 1)
	{
		cout << "The team1's informations as following:" << endl << _team;
		++team_flag;
	}
	else
	{
		cout << "The team2's informations as following:" << endl << _team;
	}
}

void Display_staff(Team &_team, string &_output_file)
{
	cout << "The staffs' informations of " << _team.tname << " : " << endl;

	cout << "The coach's name: " << _team.staff[0]->name << endl;
	cout << "The coach's age: " << _team.staff[0]->age << endl;
	cout << "The coach's skill: " << _team.staff[0]->skill << endl;
	cout << "The coach's salary: " << _team.staff[0]->salary << endl;

	cout << "The physio's name: " << _team.staff[1]->name << endl;
	cout << "The physio's age: " << _team.staff[1]->age << endl;
	cout << "The physio's skill: " << _team.staff[1]->skill << endl;
	cout << "The physio's salary: " << _team.staff[1]->salary << endl;

	cout << "The accountant's name: " << _team.staff[2]->name << endl;
	cout << "The accountant's age: " << _team.staff[2]->age << endl;
	cout << "The accountant's skill: " << _team.staff[2]->skill << endl;
	cout << "The accountant's salary: " << _team.staff[2]->salary << endl;

	ofstream fout(_output_file, ios_base::app);
	fout << "The staffs' informations of " << _team.tname << " : " << endl;

	fout << "The coach's name: " << _team.staff[0]->name << endl;
	fout << "The coach's age: " << _team.staff[0]->age << endl;
	fout << "The coach's skill: " << _team.staff[0]->skill << endl;
	fout << "The coach's salary: " << _team.staff[0]->salary << endl;

	fout << "The physio's name: " << _team.staff[1]->name << endl;
	fout << "The physio's age: " << _team.staff[1]->age << endl;
	fout << "The physio's skill: " << _team.staff[1]->skill << endl;
	fout << "The physio's salary: " << _team.staff[1]->salary << endl;

	fout << "The accountant's name: " << _team.staff[2]->name << endl;
	fout << "The accountant's age: " << _team.staff[2]->age << endl;
	fout << "The accountant's skill: " << _team.staff[2]->skill << endl;
	fout << "The accountant's salary: " << _team.staff[2]->salary << endl;
	fout.close();
}

void Display_player(Team &_team, string &_output_file)
{
	int j;
	ofstream fout(_output_file, ios_base::app);

	cout << "The players' informations of " << _team.tname << " : " << endl;
	fout << "The players' informations of " << _team.tname << " : " << endl;
	for (j = 0; j < _team.num_attacker; ++j)
	{
		cout << "The attacker" << j + 1 << "'s name: " << _team.player[j]->name << endl;
		cout << "The attacker" << j + 1 << "'s age: " << _team.player[j]->age << endl;
		cout << "The attacker" << j + 1 << "'s skill: " << _team.player[j]->skill << endl;
		cout << "The attacker" << j + 1 << "'s salary: " << _team.player[j]->salary << endl;
		cout << "The attacker" << j + 1 << "'s health: " << _team.player[j]->health << endl;
		fout << "The attacker" << j + 1 << "'s name: " << _team.player[j]->name << endl;
		fout << "The attacker" << j + 1 << "'s age: " << _team.player[j]->age << endl;
		fout << "The attacker" << j + 1 << "'s skill: " << _team.player[j]->skill << endl;
		fout << "The attacker" << j + 1 << "'s salary: " << _team.player[j]->salary << endl;
		fout << "The attacker" << j + 1 << "'s health: " << _team.player[j]->health << endl;
	}
	for (; j < _team.num_attacker + _team.num_midfielder; ++j)
	{
		cout << "The midfielder" << j - _team.num_attacker + 1 << "'s name: " << _team.player[j]->name << endl;
		cout << "The midfielder" << j - _team.num_attacker + 1 << "'s age: " << _team.player[j]->age << endl;
		cout << "The midfielder" << j - _team.num_attacker + 1 << "'s skill: " << _team.player[j]->skill << endl;
		cout << "The midfielder" << j - _team.num_attacker + 1 << "'s salary: " << _team.player[j]->salary << endl;
		cout << "The midfielder" << j - _team.num_attacker + 1 << "'s health: " << _team.player[j]->health << endl;
		fout << "The midfielder" << j - _team.num_attacker + 1 << "'s name: " << _team.player[j]->name << endl;
		fout << "The midfielder" << j - _team.num_attacker + 1 << "'s age: " << _team.player[j]->age << endl;
		fout << "The midfielder" << j - _team.num_attacker + 1 << "'s skill: " << _team.player[j]->skill << endl;
		fout << "The midfielder" << j - _team.num_attacker + 1 << "'s salary: " << _team.player[j]->salary << endl;
		fout << "The midfielder" << j - _team.num_attacker + 1 << "'s health: " << _team.player[j]->health << endl;
	}
	for (; j < 10; ++j)
	{
		cout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s name: " << _team.player[j]->name << endl;
		cout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s age: " << _team.player[j]->age << endl;
		cout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s skill: " << _team.player[j]->skill << endl;
		cout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s salary: " << _team.player[j]->salary << endl;
		cout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s health: " << _team.player[j]->health << endl;
		fout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s name: " << _team.player[j]->name << endl;
		fout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s age: " << _team.player[j]->age << endl;
		fout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s skill: " << _team.player[j]->skill << endl;
		fout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s salary: " << _team.player[j]->salary << endl;
		fout << "The defender" << j - _team.num_attacker - _team.num_midfielder + 1 << "'s health: " << _team.player[j]->health << endl;
	}
	cout << "The goalkeeper's name: " << _team.player[j]->name << endl;
	cout << "The goalkeeper's age: " << _team.player[j]->age << endl;
	cout << "The goalkeeper's skill: " << _team.player[j]->skill << endl;
	cout << "The goalkeeper's salary: " << _team.player[j]->salary << endl;
	cout << "The goalkeeper's health: " << _team.player[j]->health << endl;
	fout << "The goalkeeper's name: " << _team.player[j]->name << endl;
	fout << "The goalkeeper's age: " << _team.player[j]->age << endl;
	fout << "The goalkeeper's skill: " << _team.player[j]->skill << endl;
	fout << "The goalkeeper's salary: " << _team.player[j]->salary << endl;
	fout << "The goalkeeper's health: " << _team.player[j]->health << endl;
	fout.close();
}

void Game_result(Team &_t1, Team &_t2, string &_output_file)
{
	int count_pass = 0;  //传球次数计数
	int t1_goal = 0;  //队伍1得分
	int t2_goal = 0;  //队伍2得分
	ofstream fout(_output_file, ios_base::app);

	if (rand()%2 == 0)  //队伍控球权随机化
	{
		_t1.Ball_possession = true;
	}
	else
	{
		_t2.Ball_possession = true;
	}

	double t1_pass_ball_probablity = (_t1.attack_ability - _t2.defend_ability) * 0.3 / 100.0 ;  //计算队伍传球概率
	double t2_pass_ball_probablity = (_t2.attack_ability - _t1.defend_ability) * 0.3 / 100.0 ;
	if (t1_pass_ball_probablity < 0.3)  //最低控球概率为30%
	{
		t1_pass_ball_probablity = 0.3;
	}
	if (t2_pass_ball_probablity < 0.3)
	{
		t2_pass_ball_probablity = 0.3;
	}

	for (int i = 0; i < 100; ++i)
	{
		if (_t1.Ball_possession && count_pass < 6)  //设定传球次数最多6次
		{
			if ((double)rand()/RAND_MAX < t1_pass_ball_probablity)
			{
				cout << _t1.tname << " passes the ball successfully!" << endl;
				fout << _t1.tname << " passes the ball successfully!" << endl;
				++count_pass;
			}
			else
			{
				cout << _t1.tname << " loses the ball!" << endl;
				fout << _t1.tname << " loses the ball!" << endl;
				count_pass = 0;
				_t1.Ball_possession = !_t1.Ball_possession;  //传球失败控球权改变
				_t2.Ball_possession = !_t2.Ball_possession;
			}
		}
		if (_t1.Ball_possession && count_pass == 6)  //第7次传球即是射门
		{
			int num = rand() % (_t1.num_attacker + _t1.num_midfielder);  //射门球员在进攻球员和中场球员中随机选取
			double shot_success_probablity = (_t1.player[num]->skill * (_t1.player[num]->health / 100.0) - _t2.player[10]->skill * (_t2.player[10]->health / 100.0)) / 100.0;  //计算射门成功概率
			if (shot_success_probablity < 0.2)  //最低射门成功概率为20%
			{
				shot_success_probablity = 0.2;
			}
			if ((double)rand()/RAND_MAX < shot_success_probablity)
			{
				cout << _t1.tname << " gets a goal!" << endl;
				fout << _t1.tname << " gets a goal!" << endl;
				++t1_goal;
				count_pass = 0;
				_t1.Ball_possession = !_t1.Ball_possession;  //射门成功控球权改变
				_t2.Ball_possession = !_t2.Ball_possession;
			}
			else
			{
				cout << _t1.tname << " shots unsuccessfully!" << endl;
				fout << _t1.tname << " shots unsuccessfully!" << endl;
				count_pass = 0;
				_t1.Ball_possession = !_t1.Ball_possession;  //射门失败控球权改变
				_t2.Ball_possession = !_t2.Ball_possession;
			}
		}
		if (_t2.Ball_possession && count_pass < 6)
		{
			if ((double)rand() / RAND_MAX < t2_pass_ball_probablity)
			{
				cout << _t2.tname << " passes the ball successfully!" << endl;
				fout << _t2.tname << " passes the ball successfully!" << endl;
				++count_pass;
			}
			else
			{
				cout << _t2.tname << " loses the ball!" << endl;
				fout << _t2.tname << " loses the ball!" << endl;
				count_pass = 0;
				_t1.Ball_possession = !_t1.Ball_possession;
				_t2.Ball_possession = !_t2.Ball_possession;
			}
		}
		if (_t2.Ball_possession && count_pass == 6)
		{
			int num = rand() % (_t2.num_attacker + _t2.num_midfielder);
			double shot_success_probablity = (_t2.player[num]->skill * (_t2.player[num]->health / 100.0) - _t1.player[10]->skill * (_t1.player[10]->health / 100.0)) / 100.0;
			if (shot_success_probablity < 0.2)
			{
				shot_success_probablity = 0.2;
			}
			if ((double)rand() / RAND_MAX < shot_success_probablity)
			{
				cout << _t2.tname << " gets a goal!" << endl;
				fout << _t2.tname << " gets a goal!" << endl;
				++t2_goal;
				count_pass = 0;
				_t1.Ball_possession = !_t1.Ball_possession;
				_t2.Ball_possession = !_t2.Ball_possession;
			}
			else
			{
				cout << _t2.tname << " shots unsuccessfully!" << endl;
				fout << _t2.tname << " shots unsuccessfully!" << endl;
				_t1.Ball_possession = !_t1.Ball_possession;
				_t2.Ball_possession = !_t2.Ball_possession;
				count_pass = 0;
			}
		}
	}

	_t1.Ball_possession = false;  //控球权重置
	_t2.Ball_possession = false;

	for (int j = 0; j < 11; ++j)
	{
		_t1.player[j]->Dec_health();  //球员健康值减少
		_t2.player[j]->Dec_health();
	}

	_t1.goal += t1_goal;  //计算总进球数
	_t2.goal += t2_goal;
	_t1.per_goal.push_back(t1_goal);  //记录每场比赛进球数
	_t2.per_goal.push_back(t2_goal);

	if (t1_goal == t2_goal)  //本次比赛平局
	{
		++_t1.drawn_game;
		++_t2.drawn_game;
		cout << "This game ends in a tie!" << endl;
		fout << "This game ends in a tie!" << endl;
	}
	else if (t1_goal < t2_goal)  //本次比赛队伍2获胜
	{
		++_t2.win_game;
		cout << _t2.tname << " wins this game!" << endl;
		fout << _t2.tname << " wins this game!" << endl;
	}
	else  //本次比赛队伍1获胜
	{
		++_t1.win_game;
		cout << _t1.tname << " wins this game!" << endl;
		fout << _t1.tname << " wins this game!" << endl;
	}
	fout.close();
}

void Display_result(Team &_t1, Team &_t2, string &_output_file)
{
	cout << "There are " << _t1.num_game << " games in the tournament." << endl;
	cout << "There are " << _t1.drawn_game << " drawn games in the tournament." << endl;
	cout << _t1.tname << " wins the number of games: " << _t1.win_game << endl;
	cout << _t1.tname << " gets the number of goals: " << _t1.goal << endl;
	cout << _t2.tname << " wins the number of games: " << _t2.win_game << endl;
	cout << _t2.tname << " gets the number of goals: " << _t2.goal << endl;
	for (int i = 0; i < _t1.num_game; ++i)
	{
		cout << "The result of game " << i + 1 << ":" << endl;
		cout << _t1.tname << " " << _t1.per_goal[i] << " VS " << _t2.per_goal[i] << " " << _t2.tname << endl;
	}

	ofstream fout(_output_file, ios_base::app);
	fout << "There are " << _t1.num_game << " games in the tournament." << endl;
	fout << "There are " << _t1.drawn_game << " drawn games in the tournament." << endl;
	fout << _t1.tname << " wins the number of games: " << _t1.win_game << endl;
	fout << _t1.tname << " gets the number of goals: " << _t1.goal << endl;
	fout << _t2.tname << " wins the number of games: " << _t2.win_game << endl;
	fout << _t2.tname << " gets the number of goals: " << _t2.goal << endl;
	for (int i = 0; i < _t1.num_game; ++i)
	{
		fout << "The result of game " << i + 1 << ":" << endl;
		fout << _t1.tname << " " << _t1.per_goal[i] << " VS " << _t2.per_goal[i] << " " << _t2.tname << endl;
	}
	fout.close();
}

void Game_play(Team &_t1, Team &_t2, int &n, string &_output_file)
{
	bool gameday_flag = true;  //比赛日标志
	int num_day = 1;  //总天数
	int rest_day;  //休息日
	ofstream fout(_output_file, ios_base::app);
	fout.setf(ios::fixed, ios::floatfield);  //输出格式设置
	fout.precision(2);

	Display_staff(_t1, _output_file);
	Display_staff(_t2, _output_file);

	for (int i = 0; i < n;)
	{
		cout << "Day " << num_day << endl;
		fout << "Day " << num_day << endl;
		if (gameday_flag)  //比赛开始
		{
			_t1.Calculate_ability();
			_t2.Calculate_ability();
			Display_player(_t1, _output_file);
			Display_player(_t2, _output_file);
			Game_result(_t1, _t2, _output_file);  //计算本次比赛结果
			Display_player(_t1, _output_file);
			Display_player(_t2, _output_file);
			cout << _t1.tname << " " << _t1.per_goal[i] << " VS " << _t2.per_goal[i] << " " << _t2.tname << endl;
			fout << _t1.tname << " " << _t1.per_goal[i] << " VS " << _t2.per_goal[i] << " " << _t2.tname << endl;
			_t1.staff[2]->count_spend(_t1, _output_file);  //会计计算总花费
			_t2.staff[2]->count_spend(_t2, _output_file);
			rest_day = rand() % 4 + 2;  //休息天数随机化
			++i;
			++num_day;
			gameday_flag = !gameday_flag;
		}
		else if (rest_day)  //休息时间
		{
			_t1.staff[0]->Inc_skill(_t1.player);  //教练增加球员技能值
			_t2.staff[0]->Inc_skill(_t2.player);
			_t1.staff[1]->Inc_health(_t1.player);  //理疗师增加球员健康值
			_t2.staff[1]->Inc_health(_t2.player);
			_t1.staff[2]->count_spend(_t1, _output_file);  //会计计算总花费
			_t2.staff[2]->count_spend(_t2, _output_file);
			++num_day;
			--rest_day;
		}
		if (!rest_day)  //休息结束
		{
			gameday_flag = !gameday_flag;
		}
	}
	fout.close();
}
