#include "Football.h"
#include <windows.h>


int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	Team t1, t2;
	int ngame = atoi(argv[7]);
	int a1 = atoi(argv[1]), m1 = atoi(argv[2]), d1 = atoi(argv[3]);
	int a2 = atoi(argv[4]), m2 = atoi(argv[5]), d2 = atoi(argv[6]);
	std::string output_file = argv[8];

	Init_team(t1, a1, m1, d1, ngame);
	Init_team(t2, a2, m2, d2, ngame);
	Game_play(t1, t2, ngame, output_file);
	Display_result(t1, t2, output_file);

	Sleep(1000);
	system("pause");
	return 0;
}


