/*
Name: Efraim Rahamim
T.Z. 315392621
Class: 09
*/

#include <iostream>
#include"targil5_dec.h"
#include<string.h>
using namespace std;

/*
Function Name: printMenu.
Inout: None.
Output: None.
Operation: The function prints the menu of the program.
*/
void printMenu()
{
	cout << "Welcome to Soccer League Management System" << endl;
	cout << "Choose one of the following options:" << endl;
	cout << "(1) Add a Player" << endl << "(2) Add a Team" << endl << "(3) Delete a Player" <<endl<< "(4) Delete a Team" << endl;
	cout << "(5) Team: Player Recommendations" << endl << "(6) Team: Buy a player" << endl << "(7) Team: Remove a player" << endl;
	cout << "(8) Print list of all Players sorted by their salary" << endl;
	cout << "(9) Print a list of all Teams sorted by their budget" << endl;
	cout << "(10) Print a list of players for a specific team" << endl;
	cout << "(11) Exit" << endl;
	cout << endl;
}

/*
Function Name: enlargePlayerArray.
Input: A pointer to a the 'Player' dynamic array and the length of the array.
output: None.
Operation: The function creates a new dynamic array, larger than 1 cell from the original arrray and copies all the 
data from the original array to the new one.
*/
void enlargePlayerArray(Player* &ptr, int &length)
{
	//creats a temporary pointer to a bigger "Player" dynamic array
	Player* temp = NULL;
	temp = new Player[length + 1];
	//if the original array is empty
	if (length == 0)
	{
		temp[0].playerName = NULL;
		temp[0].playerPrice = -1;
		temp[0].playerTeam = NULL;
		deletePlayerArray(ptr, length);
		delete[]ptr;
		ptr = temp;
	}
	else
	{
		int i;
		//copies the data from the old array to the new one
		for (i = 0; i < length; i++)
		{
			temp[i].playerName = ptr[i].playerName;
			temp[i].playerPrice = ptr[i].playerPrice;
			temp[i].playerTeam = ptr[i].playerTeam;
		}
		//resetting the last cell
		temp[i].playerPrice = -1;
		temp[i].playerName = NULL;
		temp[i].playerTeam = NULL;
		//delete the old array
		deletePlayerArray(ptr, length);
		delete[]ptr;
		ptr = temp;
	}
	length++;
}

/*
Function Name: enlargeTeamArray.
Input: A pointer to a the 'Team' dynamic array and the length of the array.
output: None.
Operation: The function creates a new dynamic array, larger than 1 cell from the original arrray and copies all the
data from the original array to the new one.
*/
void enlargeTeamArray(Team* &ptr, int &length)
{
	//creats a temporary pointer to a bigger "Team" dynamic array
	Team* temp = NULL;
	temp = new Team[length + 1];
	//if the original array is empty
	if (length == 0)
	{
		temp[0].SizeOfTeam = 0; 
		temp[0].TeamAccount = -1;
		temp[0].TeamName = NULL;
		temp[0].TeamPlayers = NULL;
		//delete[]ptr;
		deleteTeamArray(ptr, length);
		delete[]ptr;
		ptr = temp;
	}
	else
	{
		int i;
		//copies the data from the old array to the new one
		for (i = 0; i < length; i++)
		{
			temp[i].TeamAccount = ptr[i].TeamAccount;
			temp[i].TeamName = ptr[i].TeamName;
			temp[i].TeamPlayers = ptr[i].TeamPlayers;
			temp[i].SizeOfTeam = ptr[i].SizeOfTeam;
		}
		//resetting the last cell
		temp[i].TeamAccount = -1;
		temp[i].SizeOfTeam = 0;
		temp[i].TeamName = NULL;
		temp[i].TeamPlayers = NULL;
		//delete the old array
		deleteTeamArray(ptr, length);
		delete[]ptr;
		ptr = temp;
	}
	length++;
}

/*
Function Name: enlargeTeamPlayersArray.
Input: A "TeamPlayers" pointer of a certain team and the length of "TeamPlayers" array of the team.
Output: None.
Operation: The function enlarge the "TeamPlayers" array by 1 cell, using a temporary array. 
*/
void enlargeTeamPlayersArray (char** &ptr, int &length)
{
	if (length == 0)
	{
		//there are no players in the team
		ptr = new char* [1];
		ptr[0] = NULL;
	}
	else
	{
		//there is at least 1 player in the team
		//creating a temporary array the is bigger than 1 from the original array
		char** temp = NULL;
		temp = new char* [length + 1];
		int i;
		//coping the data between the arrays
		for (i = 0; i < length; i++)
		{
			temp[i] = ptr[i];
		}
		//reset the last pointer in the array
		temp[i] = NULL;
		//deleting the original array 
		for (int i = 0; i < length; i++)
		{
			delete[]ptr[i];
		}
		delete[] ptr;
		ptr = temp;
	}
	//growing the size of the team by 1
	length++;
}

/*
Function Name: reduceTeamArray.
Input: A pointer for the "Team" array and the length of the "Team" array.
Output: None.
Operation: The function copies the array to a new array without the empty cell.
the length of the new "Team" array would be updated.
*/
void reduceTeamArray(Team*& ptr, int& length)
{
	if (length == 1)
	{
		//there is only one team in the array
		delete[]ptr;
		ptr = new Team[0];
	}
	else
	{
		// "temp" is a pointer for the temporary "Team" array.
		Team* temp = NULL;
		// the new array is smaller by 1 cell from the original array
		temp = new Team[length - 1];
		//i and j are indexes for the data copying between to arrays.
		int i = 0;
		int j = 0;
		//running on the original array
		while (i < length)
		{
			//checking if the current cell is the empty one by checking the "TeamAccount" value.
			if (ptr[i].TeamAccount > -1)
			{
				//the currnet cell is not empty
				//copying the data from the original array to the new one
				temp[j].TeamAccount = ptr[i].TeamAccount;
				temp[j].TeamName = ptr[i].TeamName;
				temp[j].TeamPlayers = ptr[i].TeamPlayers;
				temp[j].SizeOfTeam = ptr[i].SizeOfTeam;
				//updating the index of the new array
				j++;
			}
			//updating the index of the original array
			i++;
		}
		//updating the new array's pointer
		delete[] ptr;
		ptr = temp;
	}
	//updating the length of the "Team" array
	length--;
}

/*
Function Name: reducePlayerArray.
Input: A pointer for the "Player" array and the length of the "Player" array.
Output: None.
Operation: The function copies the array to a new array without the empty cell.
the length of the new "Player" array would be updated.
*/
void reducePlayerArray(Player*& ptr, int& length)
{
	if (length == 1)
	{
		//this playes in the only player in the array
		delete[]ptr;
		ptr = new Player[0];
	}
	else
	{
		//there are at least 2 players in the array
		// "temp" is a pointer for the temporary "Player" array.
		Player* temp = NULL;
		// the new array is smaller by 1 cell from the original array
		temp = new Player[length - 1];
		//i and j are indexes for the data copying between the arrays.
		int i = 0;
		int j = 0;
		//running on the original array
		while (i < length)
		{
			//checking if the current cell is the empty one by checking the "playerPrice" value.
			if (ptr[i].playerPrice > -1)
			{
				//the currnet cell is not empty
				//copying the data from the original array to the new one
				temp[j].playerName = ptr[i].playerName;
				temp[j].playerPrice = ptr[i].playerPrice;
				temp[j].playerTeam = ptr[i].playerTeam;
				//updating the index of the new array
				j++;
			}
			//updating the index of the original array
			i++;
		}
		//updating the new array's pointer
		delete[]ptr;
		ptr = temp;
	}
	//updating the length of the "Player" array
	length--;
}

/*
Function Name: reduceTeamPlayesArray.
Input: A pointer for the "TeamPlayers" pointers array and the length of the "TeamPlayers" array.
Output: None.
Operation: The function copies the array to a new array without the empty cell.
the length of the new "TeamPlayers" pointers array would be updated.
*/
void reduceTeamPlayersArray(char**& ptr, int &length)
{
	if (length == 1)
	{
		delete[]ptr;
	}
	else
	{ 
		//creating a temporary pointer's array
		char** temp = NULL;
		temp = new char* [length - 1];
		int i = 0;
		int j = 0;
		//running on the original array
		while (i < length)
		{
			//checking if the current cell points to something
			if (ptr[i] != NULL)
			{
				//coping the pointing 
				temp[j] = ptr[i];
				j++;
			}
			i++;
		}
		//deleting the orignal array and updating the poiner to point to the new array
		for (int i = 0; i < length; i++)
		{
			delete[]ptr[i];
		}
		delete[]ptr;
		ptr = temp;
	}
	//updating the size of the array to be smaller by 1
	length--;
}

/*
Function Name: isTeamExist.
Input: pointer to the team array, pointer to name of team, the size of the "Team" array.
Output: 1 - the team exists in the array. 0 - the team does not exist.
Operation: the function checkes on every team in the array if it is the requried team.
*/
int isTeamExist(Team* ptrTeam, char* teamName, int teamSize)
{
	//running on the "Team" array
	for (int i = 0; i < teamSize; i++)
	{
		//checkes if the current team is the required team
		if (isStringIdentical(ptrTeam[i].TeamName, teamName))
		{
			//the team exist in the array
			return 1;
			break;
		}
	}
	//the team does not exist
	return 0;
}

/*
Function Name: isPlayerExist.
Input: pointer to the player array, pointer to name of player, the size of the "Player" array.
Output: 1 - the player exists in the array. 0 - the player does not exist.
Operation: the function checkes on every player in the array if he is the requried player.
*/
int isPlayerExist(Player* ptrPlayer, char* playerName, int playerSize)
{
	//running on the "Player" array
	for (int i = 0; i < playerSize; i++)
	{
		//checkes if the current player is the required player
		if (isStringIdentical(ptrPlayer[i].playerName, playerName))
		{
			//the player exist in the array
			return 1;
			break;
		}
	}
	//the player does not exist
	return 0;
}

/*
Function Name: sortOfChoise.
Input: the choise of the user from the menu.
Output: None.
Operation: the function activate the required functions according to the choise of the user.
*/
void sortOfChoise(int choise, int& playerSize, int& teamSize, Player*& ptrPlayer, Team*& ptrTeam)
{
	char* playerName = NULL;
	char* teamName = NULL;
	char buffer[MAX_SIZE_NAME];
	int playerPrice;
	int teamBudget;
	switch (choise)
	{
		//Add a player
	case 1:
		do
		{
			cout << "Enter name of Player: ";
			cin >> buffer;
			playerName = new char[strlen(buffer) + 1];
			strcpy(playerName, buffer);
			//for check: strcpy_s(playerName, strlen(buffer) + 1, buffer);
			cout << endl;
			cout << "Enter player salary: ";
			cin >> playerPrice;
			cout << endl;
		} while (playerPrice < 0);
		//enlarg the "Player" array by 1
		enlargePlayerArray(ptrPlayer, playerSize);
		//adding the player
		addNewPlayer(ptrPlayer, playerName, playerPrice, playerSize);
		cout << endl;
		break;
		
		//Add a team
	case 2:
		do
		{
			cout << "Enter name of Team: ";
			cin >> buffer;
			teamName = new char[strlen(buffer) + 1];
			strcpy(teamName,buffer);
			//for check: strcpy_s(teamName, strlen(buffer)+1, buffer);
			cout << endl;
			cout << "Enter starting budget: ";
			cin >> teamBudget;
			cout << endl;
		} while (teamBudget < 0);
		//enlarge the "Team" array by 1
		enlargeTeamArray(ptrTeam, teamSize);
		//addint the team
		addNewTeam(ptrTeam, teamName, teamBudget, teamSize);
		cout << endl;
		break;

	case 3:
		//delete a player
		cout << "Enter name of Player: ";
		cin >> buffer;
		playerName = new char[strlen(buffer) + 1];
		strcpy(playerName,buffer);
		//for check: strcpy_s(playerName, strlen(buffer)+1, buffer);
		cout << endl;
		//checking if the player exist in the array
		if (isPlayerExist(ptrPlayer, playerName, playerSize))
		{
			//the player exist
			//deleting the player
			deletePlayer(ptrPlayer, ptrTeam, playerName);
			cout << playerName << " has been deleted from the database." << endl;
			reducePlayerArray(ptrPlayer, playerSize);
		}
		else
		{
			//the player does not exist
			cout << playerName << " does not exist in the database." << endl;
		}
		cout << endl;
		delete[]playerName;
		break;

	case 4:
		//delete a team
		cout << "Enter name of Team: ";
		cin >> buffer;
		teamName = new char[strlen(buffer) + 1];
		strcpy(teamName,buffer);
		//for check: strcpy_s(teamName, strlen(buffer)+1, buffer);
		cout << endl;
		//checking if the team exist
		if (isTeamExist(ptrTeam, teamName, teamSize))
		{
			//the team exist - delete the team
			deleteTeam(ptrTeam, teamName);
			cout << teamName << " team has been deleted from the database." << endl;
			reduceTeamArray(ptrTeam, teamSize);
		}
		else
		{
			//the team does not exist
			cout <<teamName << " does not exist in the database." << endl;
		}
		cout << endl;
		delete[]teamName;
		break;

	case 5:
		//player recommendation
		cout << "Enter name of Team: ";
		cin >> buffer;
		teamName = new char[strlen(buffer) + 1];
		strcpy(teamName,buffer);
		//for check: strcpy_s(teamName,strlen(buffer)+1, buffer);
		cout << endl;
		//checking if the team exist
		if (isTeamExist(ptrTeam,teamName,teamSize))
		{
			//the team exist
			printReccomendation(ptrPlayer, ptrTeam, teamName, playerSize);
		}
		else
		{
			//team does not exist
			cout << "Team " << teamName << " does not exist in the database." << endl;
		}
		cout << endl;
		delete[]teamName;
		break;

		//Buy a player
	case 6:
		cout << "Enter name of Team:" ;
		cin >> buffer;
		teamName = new char[strlen(buffer) + 1];
		strcpy(teamName,buffer);
		//for check: strcpy_s(teamName,strlen(buffer)+1, buffer);
		cout << endl;
		cout << "Enter name of Player: ";
		cin >> buffer;
		playerName = new char[strlen(buffer) + 1];
		strcpy(playerName,buffer);
		//for check: strcpy_s(playerName,strlen(buffer)+1, buffer);
		cout << endl;
		//cheking if the team exist in the database
		if (isTeamExist(ptrTeam, teamName, teamSize))
		{
			//checking if the player exist
			if (isPlayerExist(ptrPlayer, playerName, playerSize))
			{
				//the player exist in the database
				//checking if the player does not belong to any team
				if (ptrPlayer[findPlayerIndex(ptrPlayer, playerName)].playerTeam == NULL)
				{
					//the player does not belong to any team
					buyPlayer(ptrPlayer, ptrTeam, playerName, teamName);
				}
				else
				{
					//the player belongs to a team
					cout << playerName << " is already belong to a team." << endl;
				}
			}
			else
			{
				//the player does not exist in the database
				cout << playerName << " does not exist in the database." << endl;

			}
		}
		else
		{
			//the team does not exist in the database
			cout << "Team " << teamName << " does not exist in the database." << endl;
		}
		cout << endl;
		delete[]teamName;
		delete[]playerName;
		break;

	case 7:
		//Remove a player
		cout << "Enter name of Team: ";
		cin >> buffer;
		teamName = new char[strlen(buffer) + 1];
		strcpy(teamName,buffer);
		//for check: strcpy_s(teamName,strlen(buffer)+1, buffer);
		cout << endl;
		cout << "Enter name of Player: ";
		cin >> buffer;
		playerName = new char[strlen(buffer) + 1];
		strcpy(playerName, buffer);
		//for check: strcpy_s(playerName,strlen(buffer)+1, buffer);
		cout << endl;
		//checking if team exist
		if (isTeamExist(ptrTeam, teamName, teamSize))
		{
			//team exist in the database
			//checking if the team has any players
			if (ptrTeam[findTeamIndex(ptrTeam, teamName)].SizeOfTeam > 0)
			{
				//the team has at least 1 player
				//checking if the player exist
				if (isPlayerExist(ptrPlayer, playerName, playerSize))
				{
					//the player exist
					//checking if the player belongs to this team
					if (isStringIdentical(ptrPlayer[findPlayerIndex(ptrPlayer, playerName)].playerTeam, teamName))
					{
						//the player belong to this team
						removePlayer(ptrPlayer, ptrTeam, playerName, teamName);
					}
					else
					{
						//the player does not belong to this team
						cout <<"No player named "<< playerName << " on " << teamName <<" team."<< endl;
					}
				}
				else
				{
					//the player does not exist in the database
					cout << playerName << " does not exist in the database." << endl;
				}
			}
			else
			{
				//the team has no players
				cout << "No player named " << playerName << " on " << teamName << " team." << endl;
			}
		}
		else
		{
			//team does not exist
			cout << "Team " << teamName << " does not exist in the database." << endl;
		}
		cout << endl;
		delete[] teamName;
		delete[]playerName;
		break;

	case 8: 
		//Print a list of all players sorted by their salary
		//checking if there are any players
		if (playerSize == 0)
		{
			cout << "There are not Players in the database." << endl;
		}
		else
		{
			printPlayersSalary(ptrPlayer, playerSize);
		}
		cout << endl;
		break;

	case 9:
		//Print a list of all teames sorted by their budget
		//checking if there are any teames in the array
		if (teamSize == 1)
		{
			cout << "There are no teames in the database." << endl;
		}
		else
		{
			printTeamesBudget(ptrTeam, teamSize);
		}
		cout << endl;
		break;

	case 10: 
		//Print a list of players in a speceific team
		cout << "Enter name of Team: ";
		cin >> buffer;
		teamName = new char[strlen(buffer) + 1];
		strcpy(teamName,buffer);
		//for check: strcpy_s(teamName,strlen(buffer)+1, buffer);
		cout<<endl;
		//checking if the team exist in the array
		if (isTeamExist(ptrTeam,teamName,teamSize))
		{
			//the team exist
			printPlayersOfTeam(ptrTeam, teamName);
		}
		else
		{
			//team does not exist
			cout << "Team " <<teamName << " does not exist in the database." << endl;
		}
		cout << endl;
		delete[]teamName;
		break;

	case 11:
		//exit the program
		//delete the data
		deleteArrays(ptrPlayer, ptrTeam, playerSize, teamSize);
		delete[]ptrPlayer;
		delete[]ptrTeam;
		cout << "Goodbye!";
		cout << endl << endl;
		break;

	}
}

/*
Function Name: addNewTeam.
Input: the name of the team and the starting amount of money it has.
Output: None.
Operation: the function adds a new team to the "Team" array.
*/
void addNewTeam(Team* &ptrTeam, char* newTeamName, int money, int teamSize)
{
	// copying the new team detail's to the available cell
	ptrTeam[teamSize-1].TeamName = newTeamName;
	ptrTeam[teamSize - 1].TeamAccount = money;
	ptrTeam[teamSize - 1].TeamPlayers = new char*[1];
	ptrTeam[teamSize - 1].TeamPlayers[0] = NULL;
	ptrTeam[teamSize - 1].SizeOfTeam = 0;
}

/*
Function Name: isStringIdentical.
Input: Pointers for the two strings we want to check.
Output: 0 - the strings are not identical. 
		1- the strings are identical.
Operation: The function check on every char from the first string is it equals
			to the parallel char in the second string
*/
int isStringIdentical(char* str1, char* str2)
{
	//running on the first string
	for (int i = 0; str1[i] != '\0'; i++)
	{
		//check if the chars are identical
		if (str1[i] != str2[i])
		{
			//the chars are not identical
			//thr strings are not identical
			return 0;
		}
	}
	//the strings are identical
	return 1;
}

/*
Function Name: findTeamIndex.
Input: A pointer to the "Team" array and a pointer to the name of the team that we are looking for.
Output: the index of the cell of the required team in the "Team" array .
Operation: The function runs on the "Team" array and looks for the required team by compering the name of every team 
in the array to the rquired team.
*/
int findTeamIndex(Team* ptr, char* teamName)
{
	//run on the "Team" array
	for (int i = 0; ptr[i].TeamAccount >= 0; i++)
	{
		//checking if the current team is the required team
		if (isStringIdentical(ptr[i].TeamName, teamName))
		{
			//the current team is the required team
			//return the current index 
			return i;
		}
	}
}

/*
Function Name: findPlayerIndex.
Input: A pointer to the "Player" array and a pointer to the name of the player that we are looking for.
Output: the index of the cell of the required player in the "Player" array .
Operation: The function runs on the "Player" array and looks for the required player by compering the name of every player
in the array to the required player.
*/
int findPlayerIndex(Player* ptr, char* playerName)
{
	//run on the "Player" array
	for (int i = 0; ptr[i].playerPrice >= 0; i++)
	{
		//checking if the current player is the required player
		if (isStringIdentical(ptr[i].playerName, playerName))
		{
			//the current player is the required player
			//return the current index 
			return i;
		}
	}

}

/*
Function Name: findTeamPlayersIndex.
Input: A pointer for a certain "TeamPlayers" array in a certain "Team" cell and a pointer for a name of a player.
Output: The index of the player in the "TeamPlayers" array.
Operation: The function runs on the "TeamPlayers" array and check for every pointer if it points to the requred player.
*/
int findTeamPlayersIndex(char** ptr, char* playerName)
{
	//run on the "TeamPlayers" array
	for (int i = 0; ptr[i] != NULL; i++)
	{
		//checking if the current pointer points to the required player
		if (isStringIdentical(ptr[i], playerName))
		{
			//return the index of the current pointer in the "TeamPlayers" array
			return i;
		}
	}
}

/*
Function Name: deleteTeam.
Input: A pointer to the "Team" array and a pointer to the name of the team.
Output: None.
Operation: The function delete the team from the array.
*/
void deleteTeam(Team* &ptr, char* name)
{
	//finding the index of the requred team in the "Team" array by using "findTeamIndex" function
	int index = findTeamIndex(ptr, name);
	//marking the account of the team as a deleted team
	ptr[index].TeamAccount = -1;
	//the actual deleting of this team would happen in the "reduceTeamArray" function
}

/*
Function Name: addNewPlayer.
Input: a pointer to the "Player" array, the name of the new player and it's price.
Output: None.
Operation: The function add the new player to the "Player" array.
*/
void addNewPlayer(Player* &ptrPlayer, char* newPlayerName, int price, int playerSize)
{
	//coping the details of the new player to the avaiable cell in the array
	ptrPlayer[playerSize-1].playerName = newPlayerName;
	ptrPlayer[playerSize-1].playerPrice = price;
	ptrPlayer[playerSize-1].playerTeam = NULL;
}

/*
Function Name: deletePlayer.
Input: Pointers to the "Player" and "Team" array and the name of the player the user wants to delete.
Output: None.
Operation: The function delete the player from the "Player" array and transfer his price to the account of his team
			(if he belongs to one).
*/
void deletePlayer(Player* &ptrPlayer,Team* &ptrTeam, char* name)
{
	//finding the index of the required player in the "Player" array by using "findPlayerIndex" function
	int playerIndex = findPlayerIndex(ptrPlayer, name);
	int teamIndex;
	int TeamPlayersIndex;
	//checking if the player belongs to a certain team
	if (ptrPlayer[playerIndex].playerTeam != NULL)
	{
		//the player does belong to a certain team
		//finding the player's team index in the "Team" array
		teamIndex = findTeamIndex(ptrTeam, ptrPlayer[playerIndex].playerTeam);
		//adding the player's price to his team account
		ptrTeam[teamIndex].TeamAccount += ptrPlayer[playerIndex].playerPrice;
		//reset the pointer of this player in the "TeamPlayers" array
		TeamPlayersIndex = findTeamPlayersIndex(ptrTeam[teamIndex].TeamPlayers, ptrPlayer[playerIndex].playerName);
		ptrTeam[teamIndex].TeamPlayers[TeamPlayersIndex] = NULL;
		//reducing the array of "TeamPlayers" by 1
		reduceTeamPlayersArray(ptrTeam[teamIndex].TeamPlayers, ptrTeam[teamIndex].SizeOfTeam);
	}
	//marking the player's price as a deleted player
	ptrPlayer[playerIndex].playerPrice = -1;
	//the actual deleteing of this player would happen in the "reducePlayerArray" function
}

/*
Function Name: buyPlayer
Input: Pointers to the "Team" and "Player" array, the name of the required player 
		and the name of the team who wants to buy the player.
Output: (-1) - the team can't by the player. 1 - the team bougth the player.
Operation: the function checks if the team has enough money to buy the player. if so, the function moves the player 
to his new team and updates the team's account.
*/
int buyPlayer(Player*& ptrPlayer, Team*& ptrTeam, char* playerName, char* teamName)
{
	//finding the idexes of the player and the team in their arrays
	int playerIndex = findPlayerIndex(ptrPlayer, playerName);
	int teamIndex = findTeamIndex(ptrTeam, teamName);
	//checking if the team has enough money to buy the player
	if (ptrTeam[teamIndex].TeamAccount < ptrPlayer[playerIndex].playerPrice)
	{
		//the team doesn't have enough money to buy the player
		cout << ptrTeam[teamIndex].TeamName << " is unable to afford " << ptrPlayer[playerIndex].playerName << endl;
		return -1;
	}
	else
	{
		//the team has enough money to buy the player
		//updating the player's team
		ptrPlayer[playerIndex].playerTeam = ptrTeam[teamIndex].TeamName;
		//updating the account of the team
		ptrTeam[teamIndex].TeamAccount -= ptrPlayer[playerIndex].playerPrice;
		//adding the player to the "TeamPlayers" array
		enlargeTeamPlayersArray(ptrTeam[teamIndex].TeamPlayers, ptrTeam[teamIndex].SizeOfTeam);
		ptrTeam[teamIndex].TeamPlayers[(ptrTeam[teamIndex].SizeOfTeam)-1] = ptrPlayer[playerIndex].playerName;
		cout << playerName << " has been added to the " << teamName << " team." << endl;
		cout << teamName << " remaining budget: " << ptrTeam[teamIndex].TeamAccount << endl;
		return 1;
	}
}

/*
Function Name: printReccomendation.
Input: Pointers to the "Team" and "Player" arrays, pointer to name of a team and a length of the "Player" array.
Output: None.
Operation: the function prints all the players that the team can afford.
*/
void printReccomendation(Player* playerPtr, Team* teamPtr, char* teamName, int playerLength)
{
	int teamIndex = findTeamIndex(teamPtr, teamName);
	int budget = teamPtr[teamIndex].TeamAccount;
	int flag = 0;
	//running on the "Player" array
	for (int i = 0; i < playerLength; i++)
	{
		//check if the team can afford the current player
		if (playerPtr[i].playerPrice <= budget)
		{
			//printing only before the fist player
			if (flag == 0)
			{
				cout << "The players " << teamName << " can acquire:" << endl;
			}
			cout << playerPtr[i].playerName << endl;
			flag = 1;
		}
	}
	//there is no player that the team can afford
	if (flag == 0)
	{
		cout << "Team " << teamName << " is unable to afford any players in the database." << endl;
	}

}

/*
Function Name: removePlayer
Input: Pointers to the "Team" and "Player" arrays, pointers to the names of the player and the team.
Output: None.
Operation: The function remove the player from the team and update the team's account 
*/
void removePlayer(Player* &playerPtr, Team* &teamPtr, char* playerName, char* teamName)
{
	//getting the indexes of the player, the team and the pointer to the player from the team array.
	int playerIndex = findPlayerIndex(playerPtr, playerName);
	int teamIndex = findTeamIndex(teamPtr, teamName);
	int teamPlayersIndex = findTeamPlayersIndex(teamPtr[teamIndex].TeamPlayers, playerName);
	//updating the team account
	teamPtr[teamIndex].TeamAccount += playerPtr[playerIndex].playerPrice;
	//updating "TeamPlayers" array in the team array
	teamPtr[teamIndex].TeamPlayers[teamPlayersIndex] = NULL;
	reduceTeamPlayersArray(teamPtr[teamIndex].TeamPlayers, teamPtr[teamIndex].SizeOfTeam);
	//updating the pointer of the team of the player
	playerPtr[playerIndex].playerTeam = NULL;
	cout << playerName << " has been removed from the " << teamName << " team." << endl;
}

/*
Function Name: printPlayersSalary.
Input: A pointer to the "Player" array and the length of this array.
Output: None.
Operation: The function prints list of all the players, sorted by their salary.
*/
void printPlayersSalary(Player* playerPtr, int playerLength)
{
	//if there is only 1 player
	if (playerLength == 1)
	{
		cout << "Player Budget" << endl;
		cout << playerPtr[0].playerName << " " << playerPtr[0].playerPrice << endl;
	}
	else
	{
		//there are at least 2 players
		int temp1, temp2;
		int* tempArr = NULL, * indexArr = NULL;
		tempArr = new int[playerLength];
		indexArr = new int[playerLength];
		//resetting the indexes array and placing the prices in the temp array
		for (int i = 0; i < playerLength; i++)
		{
			tempArr[i] = playerPtr[i].playerPrice;
			indexArr[i] = i;
		}
		//sotring the indexes array according to the temp array
		for (int i = 0; i < playerLength - 1; i++)
		{
			for (int j = i + 1; j < playerLength; j++)
			{
				//checking which price if biggers
				if (tempArr[j] < tempArr[i])
				{
					//replacing the indexes of the prices
					temp1 = indexArr[i];
					indexArr[i] = indexArr[j];
					indexArr[j] = temp1;
					//replacing the prices in the temp array
					temp2 = tempArr[i];
					tempArr[i] = tempArr[j];
					tempArr[j] = temp2;
				}
			}
		}
		//printing the sorted array
		cout << "Player Budget" << endl;
		for (int i = 0; i < playerLength; i++)
		{
			cout << playerPtr[indexArr[i]].playerName << " " << playerPtr[indexArr[i]].playerPrice << endl;
		}
		//deleting the temp and indexes arrays
		delete[]tempArr;
		delete[]indexArr;

	}
}


/*
Function Name: printTeamesBudget.
Input: A pointer to the "Team" array and the length of this array.
Output: None.
Operation: The function prints list of all the teames, sorted by their budget.
*/
void printTeamesBudget(Team* teamPtr, int teamLength)
{
	//if there is only 1 team
	if (teamLength == 1)
	{
		cout << "Team Budget" << endl;
		cout << teamPtr[0].TeamName << " " << teamPtr[0].TeamAccount << endl;
	}
	else
	{
		//there are at least 2 teams 
		int temp1, temp2;
		int* tempArr = NULL, * indexArr = NULL;
		tempArr = new int[teamLength];
		indexArr = new int[teamLength];
		//resetting the indexes array and placing the accounts in the temp array
		for (int i = 0; i < teamLength; i++)
		{
			tempArr[i] = teamPtr[i].TeamAccount;
			indexArr[i] = i;
		}
		//sotring the indexes array according to the temp array
		for (int i = 0; i < teamLength - 1; i++)
		{
			for (int j = i + 1; j < teamLength; j++)
			{
				//checking which account if biggers
				if (tempArr[j] < tempArr[i])
				{
					//replacing the indexes of the accounts
					temp1 = indexArr[i];
					indexArr[i] = indexArr[j];
					indexArr[j] = temp1;
					//replacing the accounts in the temp array
					temp2 = tempArr[i];
					tempArr[i] = tempArr[j];
					tempArr[j] = temp2;
				}
			}
		}
		//printing the sorted array
		cout << "Team Budget" << endl;
		for (int i = 0; i < teamLength; i++)
		{
			cout << teamPtr[indexArr[i]].TeamName << " " << teamPtr[indexArr[i]].TeamAccount << endl;
		}
		//delete the temp and indexes arrays
		delete[]tempArr;
		delete[]indexArr;

	}
}

/*
Function Name: printPlayersOfTeam.
Input: A pointer to the "Team" array and a pointer to the name of a team.
Output: None.
Operation: The function prints all the players that belong to this team.
*/
void printPlayersOfTeam(Team* teamPtr, char* teamName)
{
	//getting the index of the team in the "Team" array
	int teamIndex = findTeamIndex(teamPtr, teamName);
	//checking if the team has any player
	if (teamPtr[teamIndex].SizeOfTeam == 0)
	{
		cout << "Team " << teamName << " has no players." << endl;
	}
	else
	{
		//printing the players of the team
		cout << "The players on the " << teamName << " Team:" << endl;
		for (int i = 0; i < teamPtr[teamIndex].SizeOfTeam; i++)
		{
			cout << teamPtr[teamIndex].TeamPlayers[i] << endl;
		}
	}
}


/*
Function Name: deletePlayerArray.
Input: Pointer to the "Player" array and length of this arrays.
Output: None.
Operation: The function delete the data in "Player" array.
*/
void deletePlayerArray(Player*& playerPtr,int playerLength)
{
	//deleting the "Player" array data
	for (int i = 0; i < playerLength; i++)
	{
		delete[] playerPtr[i].playerName;
		delete[]playerPtr[i].playerTeam;
	}
}

/*
Function Name: deleteTeamArray.
Input: Pointer to the "Team" array and length of this arrays.
Output: None.
Operation: The function delete the data in "Team" array.
*/
void deleteTeamArray(Team*&teamPtr, int teamLength)
{
	//deleting the "Team" array data
	for (int i = 0; i < teamLength; i++)
	{
		delete[]teamPtr[i].TeamName;
		//delete the "TeamPlayers" pointers array
		for (int j = 0; j < teamPtr[i].SizeOfTeam; j++)
		{
			delete[] teamPtr[i].TeamPlayers[j];
		}
		delete[]teamPtr[i].TeamPlayers;
	}
}

/*
Function Name: deleteArrays.
Input: Pointer to the "Team" and "Player" arrays and length of those arrays.
Output: None.
Operation: The function delete the data in the arrays.
*/
void deleteArrays(Player*& playerPtr, Team*& teamPtr, int playerSize, int teamSize)
{
	//deleting the "Player" array data
	for (int i = 0; i < playerSize; i++)
	{
		delete[] playerPtr[i].playerName;
		//delete[]playerPtr[i].playerTeam;
	}
	//deleting the "Team" array data
	for (int i = 0; i < teamSize; i++)
	{
		delete[] teamPtr[i].TeamName;
		delete[]teamPtr[i].TeamPlayers;
	}
}







