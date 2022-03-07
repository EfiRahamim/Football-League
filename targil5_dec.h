/*
Name: Efraim Rahamim
T.Z. 315392621
Class: 09
*/

#define MAX_SIZE_NAME 25
typedef struct Player
{
    char* playerName;
    int playerPrice;
    char* playerTeam;
}Player;
typedef struct Team
{
    char* TeamName;
    char** TeamPlayers;
    int TeamAccount;
    int SizeOfTeam;
}Team;

void printMenu();
void enlargePlayerArray(Player* &ptr, int& length);
void enlargeTeamArray(Team* &ptr, int& length);
void enlargeTeamPlayersArray(char**& ptr, int &length);
void reduceTeamArray(Team*& ptr, int& length);
void reducePlayerArray(Player*& ptr, int& length);
void reduceTeamPlayersArray(char**& ptr, int& length);
int isTeamExist(Team* ptrTeam, char* teamName, int teamSize);
int isPlayerExist(Player* ptrPlayer, char* playerName, int playerSize);
void sortOfChoise(int choise, int &playerSize, int &teamSize, Player* &ptrPlayer, Team* &ptrTeam);
void addNewTeam(Team* &ptrTeam, char* newTeamName, int money, int teamSize);
int isStringIdentical(char* str1, char* str2);
int findTeamIndex(Team* ptr, char* teamName);
int findPlayerIndex(Player* ptr, char* playerName);
int findTeamPlayersIndex(char** ptr, char* playerName);
void deleteTeam(Team* &ptr, char* name);
void addNewPlayer(Player*& ptrPlayer, char* newPlayerName, int price, int playerSize);
void deletePlayer(Player* &ptrPlayer, Team* &ptrTeam, char* name);
int buyPlayer(Player*& ptrPlayer, Team*& ptrTeam, char* playerName, char* teamName);
void printReccomendation(Player* playerPtr, Team* teamPtr, char* teamName, int playerLength);
void removePlayer(Player*& playerPtr, Team*& teamPtr, char* playerName, char* teamName);
void printPlayersSalary(Player* playerPtr, int playerLength);
void printTeamesBudget(Team* teamPtr, int teamLength);
void printPlayersOfTeam(Team* teamPtr, char* teamName);
void deletePlayerArray(Player* &ptrPlayer,int playerSize);
void deleteTeamArray(Team* &ptrTeam, int teamSize);
void deleteArrays(Player*& playerPtr, Team*& teamPtr, int playerSize, int teamSize);



