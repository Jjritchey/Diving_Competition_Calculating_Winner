//Justin Ritchey. 7/15/2020. Machine problem 7 - Structures. 
//I will be desiginig a program that takes 9 dives from each contestant and subtracts the highest and lowest scores then adding up the remaining scores and multiplying by the difficulty. Then it will determing the winner of the compeittion


#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <array>



using namespace std;


int main()
{
	ifstream file;
	file.open("m6dive.txt");

	int contestents = 0;                                      //number of contestents
    file >> contestents;                                      //reading amount of contestents from file
	double scoreArray[9];                                     //creating arrays to hold the scores for each contestent
	string name = "";                                         //will hold the value of the divers name
	double difficulty = 0;                                    //will hold the diffuclity for each diver
	double check = 0;                                         //uses to sort array into ascending order
	double add = 0;                                           //used to add up total score of all dives
	double final = 0;                                         //holds the final score for each diver after multiplying by difficulty
	ofstream finalScores;                                     //adjancent file that has same output as the screen
	finalScores.open("finalScores.txt");                     
	string champion = " ";                                    //holds the name of the winner of the competetion
	double highestScore = 0;                                  //holds the score of the winner of the competetion
	int counter1 = 0;                                         //used for formatting
	int counter2 = 0;                                         //used for formatting
	
	

	
	cout << fixed;
	cout << setprecision(1);                                  //printing out all doubles with 1 decimal place and some formatting
	finalScores << fixed << setprecision(1); 
	 
	cout << "Names      Dif.    Dive Scores                              Final Score";
	cout << "\n\n";
	finalScores << "Names      Dif.    Dive Scores                              Final Score";
	finalScores << "\n\n";


	for (int i = 0; i < contestents; i++)                     //loop to gather all names, difficulty and scores
	{
		file >> name >> difficulty;

		cout << name << " ";                                  //printing out name of diver to screen and output file
		finalScores << name << " ";                           

		counter1 = name.length();                             //getting length of name for formatting
		counter2 = 10 - counter1;

		for (int i = 0; i < counter2; i++)                    //loop to add in spaced for formatting
		{
			cout << " ";
			finalScores << " ";
		}


		cout << difficulty << " ";                            //formatting
		finalScores << difficulty << " ";
		

		for (int j = 0; j < 9; j++)                           //loop to assign all 9 dives into an array
		{
			file >> scoreArray[j];
		}
		
		for (int l = 0; l < 9;l++)                            //loop to sort the scores in ascending order
		{
			for (int m = l + 1;m < 9; m++)
			{
				if (scoreArray[l] > scoreArray[m])
				{
					check = scoreArray[l];
					scoreArray[l] = scoreArray[m];
					scoreArray[m] = check;

				}
			}
		}


		for (int i = 0; i < 4; i++)                           //loop to add in spaces for formatting
		{
			cout << " ";
			finalScores << " ";
		}

		for (int i = 0; i < 9; i++)                           //loop to print out the sorted dive scores into both the screen and output file
		{
			cout << scoreArray[i] << " ";
			finalScores << scoreArray[i] << " ";
		}

		cout << "     | ";                                    //formatting
		finalScores << "     | ";

		for (int y = 1;y < 8;y++)                             //adding up 7 values excluding the best and worst dive of each competitor
		{
			add = scoreArray[y] + add;
		}
		
		final = add * difficulty;                             //multiplying the difficulity onto the total score of the 7 dives
		

		cout << final;                                        //printing out the final score of each competitor
		finalScores << final;

		if (final > highestScore)                             //checking who has the highest score of all of the competeitors
		{
			highestScore = final;
			champion = name;
		}

		final = 0;                                            //resetting values back to 0 for next loop
		add = 0;


		cout << "\n";                                         //formatting
		finalScores << "\n";
	}

	//printing off the winner and their score

	cout << "\n\n" << "The Champion is: " << champion << "! With a total score of: " << highestScore << "\n\n";
	finalScores << "\n\n" << "The Champion is: " << champion << "! With a total score of: " << highestScore << "\n\n";


	return 0;
}



