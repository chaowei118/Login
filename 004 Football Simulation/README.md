# 004 Football Simulation
## 1. Functional Description
This assignment is to be implemented using object oriented programming.
It involves implementing a simulation of a football tournament between two teams.

The structure of the simulation is such that two football teams will play **n** games against each other
during the lifetime of the program. The value of **n** must be between 1 and 99 inclusive. There are only two teams and they will be referred to as team1 and
team2 in this specification. The program will store information about the records of the teams and the games they have played, specifically:  

(1) The team names. These will be randomly generated.  
(2) The number of games played.  
(3) Games won by each team.  
(4) Games drawn.  
(5) Goals by each team.  
(6) A record of all games played.  
(7) Spending by each team. Initially $0.
  
Every person has a name and an age, these can be randomly generated, with the age being in a sensible range. People have various
skills, as specified below. Each skill is in the range 1 to 100, with 100 the best and 1 the worst, and can never go outside those ranges.  

There are three different support staff associated with each team:  
(1) A **coach** who trains players between games. Based on their skill rating they will have a chance
to increase player skills.  
(2) A **physio** who is responsible for helping players to recover health in between games, to a degree
dependent on their skill and the gap between games.  
(3) An **accountant** who updates the overall financial information of the team day by day.   

Players themselves have a skill associated with their health, and start the tournament with health 100.
There are four different types of players: **attackers**, **midfielders**, **defenders** and **goalkeepers**.
**Attackers** and **midfielders** contribute to the attack of a team and may score, while **midfielders**, **defenders**
and **goalkeepers** contribute to the defense of a team. 

Each team has exactly 1 **goalkeeper** and a total of 11 **players**. The number of players of different types
for each team are as specified by the command line parameters; so **a1**, **m1**, **d1** as the number of **attackers**,
**midfielders** and **defenders**, respectively, for team one; and **a2**, **m2**, **d2** as the analogous fields for team two.

Initial skills ratings for staff and players will be randomly chosen in appropriate range, other than
health. Daily salaries don’t change, and will also be randomly chosen in suitable range.

These teams play **n** games but the games are seperated by 2-5 days each. There will always be a game
on Day 1 of the simulation. On each non-playing day there are the following events:  
(1) **Accountants** add the daily salaries of staff and players to the team spending.  
(2) **Coaches** attempt to improve the skill of their players.  
(3) **Physios** help improve the health of their players.  

On a playing day a game is played. The result will be determined by the skill, including the health, of the players.
Besides, there are the following events:  
(1) **Accountants** add the daily salaries of **staff** and **players** to the team spending.  
(2) Each **player** loses some health through playing. They will be losing enough that it will typically
take 3 or 4 days of rest to recover completely, although a good **physio** will help with this. If there is
a long tournament **players** will likely be run down by the end.  
(3) Each **player** has a small chance of increasing their skill. Increases will be appropriately rare.  

## 2. File Specification
Output.txt will include the following content:  
(1) At the start of the tournament, the file will list the staff's skills of each team.  
(2) The day number on every day.  
(3) The players in each team before the game starts; including ratings of the players.  
(4) The outcome of the game, and the in-game action.  
(5) The players in each team after the game finishes; including ratings of the players.  
(6) The summary of the team1 vs team2 tournament to date.  
(7) The financial spending of each team at the end of any day.  
(8) The overall result of the tournament and a list of all game results at the end of the simulation.

## 3. How to run this program
Using CodeBlocks software to creat a project which includes main.cpp, Football.cpp and Football.h, then building it and using command lines to pass arguments for running.


