#include<iostream>   //input and output stream(e,g cin, cout)
#include<limits>   //use limits for input validation
#include<string.h> //use string to take input without spaces(e.g place and name)
#include<conio.h> // It is used here for console-based input/output operations.
using namespace std;
const int Max_Candidates=5; //Limit of candiadtes
const int Max_Voters=100;//limit of voters 
//structure to contain different datatypes
struct Candidate{
	string name;
	string place;
	int votes;
};
//function to display the menu for choice 
int getMenuChoice(){
	// Display menu options
	 cout << "\n\t\t----- Voting System Menu-----\n";
    cout << "\t\t| 1. Vote                   |\n";
    cout << "\t\t| 2. Display Results        |\n";
    cout << "\t\t| 3. Exit                   |\n";
    cout << "\t\t-----------------------------";
   int choice;
    cout<<"\n\n\t\tMake a choice : ";
    while(true){
    	if(cin>>choice){//works as condition 
    		if(choice > 0 && choice <=3){
    			break;
			}
			else{
				cout<<"\n\t\tYou are entering a wrong number for choice. Please enter number from 1 to 3 to select the choice : ";
			}	
		}
		else{
			cout<<"\n\t\tPlease enter a number(int) to make a choice : ";//if user enter character instead of numeric value
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return choice;
}
//main body 
int main(){
		cout << "\n\n\n\n\t\t****************************************************************************************\n";
	cout << "\t\t^^|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |^^\n";
	cout << "\t\t^^|                                           		                             |^^\n";
	cout << "\t\t^^|                                           		                             |^^\n";
	cout << "\t\t^^|                                           		                             |^^\n";
	cout << "\t\t^^|                                           		                             |^^\n";
	cout << "\t\t^^|                                           		                             |^^\n";
	cout << "\t\t^^|                                           		                             |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                    WELCOME TO                                    |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                 E-Voting System                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|                                                                                  |^^\n";
	cout << "\t\t^^|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|^^\n";
	cout << "\t\t****************************************************************************************\n\n\t\t";
	_getch();
	system("cls");
	Candidate cand[Max_Candidates];
	int numCandidates;
	cout<<"\n\t\tEnter the number of candidates : ";     //takes the number of candidate
	while(true){                         //remains infinite until break condition appears
		if(cin>>numCandidates){
			if(numCandidates>0 && numCandidates <= Max_Candidates){
				break;
			}
			else{
				cout<<"\n\t\tYou are entering a wrong number. Please enter number greater than 1 and less than 5 : ";
			}
		}
		else{
			cout<<"\n\t\tPlease enter a number(int) to make a choice : ";
		}
		cin.clear();//use to clear the screen
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pre define (use for input validation)
	}
for(int i=0; i <numCandidates; i++){
	cout<<"\n\t\tEnter the  name of Candidate "<<i+1<<" : ";
     cin.ignore();
	getline(cin,cand[i].name);
	cout<<"\t\tEnter the  place of Candidate "<<i+1<<" : ";
	getline(cin,cand[i].place);
	cand[i].votes=0;	
}
	int numVoters;
		cout<<"\n\t\tEnter the number of voters : "; //takes the number of voters
	while(true){                 //remains infinite until break condition appears
		if(cin>>numVoters){     //condition checks here if the enter no is in int or not ,if not then it gives the else statement
			if(numVoters >0 && numVoters <= Max_Voters){
				break;
			}
			else{
				cout<<"\n\t\tYou are entering a wrong number. Please enter number from 1 to 100 : ";
			}
		}
		else{
			cout<<"\n\t\tPlease enter a number(int) to make a choice : ";//this is the else of outer if 
		}
		cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	bool hasVoted[Max_Voters] = {false};
	//voting process
	int result;
do{//first enter in the loop,then check the condition
	result=getMenuChoice();
	int CandidateID,VoterID;
	switch(result){
	case 1:{
	cout<<"\n\t\tEnter Voter Id : ";
	while(true){
		if(cin>>VoterID){
			if(VoterID > 0 && VoterID <= numVoters){
			break;
		}
		else{
			cout<<"\n\t\tYou are entering a wrong number. Please enter number greater than 0 and less than equal to Number of Voters : ";
		}
	}
		else{
			cout<<"\n\t\tPlease enter a number(int) to make a choice : ";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if(hasVoted[VoterID-1]){//condition to check if the user voted before or not 
	            cout<<"\n\n\t\t______________________________\n";
                cout<<"\t\t                              \n";
                cout<<"\t\t  YOU HAVE ALREADY VOTED...  \n";
                cout<<"\t\t______________________________\n";
                cout<<endl;
		break;
	}
	cout<<"\n\t\tCandidates list : \n";
	for(int i=0; i < numCandidates; i++){
		cout<<"\t\t"<<i+1<<") "<<cand[i].name<<" ("<<cand[i].place<<" )."<<endl;

	}
	cout<<"\n\t\tEnter number to choose the candidate for vote : ";
	while(true){
		if(cin>>CandidateID){
			if(CandidateID > 0 && CandidateID <= numCandidates){
			break;
		}
		else{
cout<<"\n\t\tYou are entering a wrong number. Please enetr number greater than \"0 \" and less than equal to number of candidates : ";
		}	
	}
	else{
		cout<<"\n\t\tPlease enter a number(int) to choose the candidate for vote : ";
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
cout<<endl<<endl;
    cand[CandidateID - 1].votes++;//count the record of votes
                cout<<"\t\t^^^^^^^^^^^^^^^^^^^^\n";
                cout<<"\t\t^                  ^\n";
                cout<<"\t\t^  VOTE RECORDED!  ^\n";
                cout<<"\t\t^                  ^\n";
                cout<<"\t\t^^^^^^^^^^^^^^^^^^^^";
                cout<<endl;
                hasVoted[VoterID - 1] = true;
                break;
            }	
	 case 2:{
			 	cout<<"\n\t\t~~~~~~~~~~~Voting Results~~~~~~~~~~~~~~";
			 	for(int i=0;i < numCandidates;i++){
			 		cout<<"\n\t\t Votes of CANDIDATES " << cand[i].name<<" ( "<< cand[i].place<<" ) are : "<<cand[i].votes;
				 }
				 cout<<"\n\t\t_____________________________________\n";
				break;
			 }			 
			 case 3:{
			 	cout<<"\n\t\t........ Exit the Program ........\n";
				break;
			 }
			 default:
			 	cout<<"\n\t\tEnterd choice is not in our CHoice list, so ,Please enter number from 1 to 3: ";
}
}

while(result!=3);
return 0;
}