#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
void ceaseFire();
void pirateShipRearrange1 (int);
void pirateShipRearrange2 (int);
void pirateShipRearrange3 (int);
void pirateShipIntro (int);
void player1Shoot (int);
void player2Shoot (int);

string p1Name;
string p2Name;
int p1Score= 100;
int p2Score=100;
int p1Turn = 1;
int p2Turn = 1;
int p1Guess = 0;
int p2Guess = 0;

const int ARRAY_SIZE = 5;
string names[ARRAY_SIZE];
        

int main(int argc, char *argv[])
{
    int count2 = 0;
    cout << "                                Previous Ships!!" << endl;
    ifstream highScore2;
    highScore2.open("scores.txt");
    while (count2 < ARRAY_SIZE) 
    {
      highScore2 >> names[count2];    
      count2++;
      
    }
    /*string name;
    highScore2 >> name;
    cout << name << endl;
    cout << name << endl;*/
    highScore2.close();
    cout <<"                          ------------------------------" << endl;
    cout <<"                                 1. S.S " << names[0] << endl;
    cout <<"                                 2. S.S " << names[1] << endl;
    cout <<"                                 3. S.S " << names[2] << endl;
    cout <<"                                 4. S.S " << names[3] << endl;
    cout <<"                          ------------------------------"<< endl;
    
    
    
    
    
    
    unsigned seed = time(0);
    int guess = 0;
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;
    int number4 = 0;// where actual random nuber will be stored
    int count = 0;
    string takeguess= "Guess a number.";
    string tooLow= "Too low guess again.";
    string tooHigh= "Too high guess again.";
 
    char name_enter2;
    char name_enter1;
    
    cout << "Pirate ship battle game." << endl;
    cout << "Two players take turns guessing the correct distance to fire cannon. Each player starts with 100 points. Direct hit is -15 points. First to zero is the loser." << endl;  
    cout << "There are four levels. Five turns per level." << endl;
    cout << "Enter 0 as guess to skip level" << endl;
    cout << "Player 1, Enter 'n' for new ship name or enter previous ship number from table above" << endl;
    cin >> name_enter1;
    
    switch (name_enter1)
    {
           
    case 'n':  cout << "Please enter the name of ship number 1(player 1):" << endl;
               cin >>p1Name;
               cout << "Welcome S.S. " << p1Name << endl;
               break;
    
    case '1': p1Name = names[0];
              cout << "You have chosen S.S " << p1Name << endl;
              break;
    case '2': p1Name = names[1];
              cout << "You have chosen S.S " << p1Name << endl;
              break;
    case '3': p1Name = names[2];
              cout << "You have chosen S.S " << p1Name<< endl;
              break;
    case '4': p1Name = names[3];
              cout << "You have chosen S.S " << p1Name << endl;;
              break;
    default: string def = "Poop";
             cout << "Oops! You did not enter a valid option." << endl;
             cout << "Your ship name is S.S Poop." << endl;
             p1Name = def;

              
               
    }
    
    
cout << "Player 2, Enter 'n' for new ship name or enter previous ship number from table above" << endl;
cin >> name_enter2;    
    
    switch (name_enter2)
    {
    case 'n':  cout << "Please enter the name of ship number 2(player 2):" << endl;
               cin >>p2Name;
               cout << "Welcome S.S. " << p2Name << endl;
               break;
    
    case '1': p2Name = names[0];
              cout << "You have chosen S.S " << p2Name << endl;
              break;
    case '2': p2Name = names[1];
              cout << "You have chosen S.S " << p2Name << endl;
              break;
    case '3': p2Name = names[2];
              cout << "You have chosen S.S " << p2Name<<endl;
              break;
    case '4': p2Name = names[3];
              cout << "You have chosen S.S " << p2Name << endl;
              break;
    default: string def = "Toilet";
             cout << "Oops! You did not enter a valid option." << endl;
             cout << "Your ship name is S.S Toilet." << endl;
             p1Name = def;
             break;
    
    
     }
    srand(seed);//specify seed value for rand () function
    number1 = 1 + rand () % 100; // specify  max range of number to 100 
    number2 = 1 + rand () % 100; // specify  max range of number to 100 
    number3 = 1 + rand () % 100; // specify  max range of number to 100 
    number4 = 1 + rand () % 100; // specify  max range of number to 100 
    
    //level 1
    //cout << number1 << endl;
    pirateShipIntro (number1);
    //level 2
    cout << "----->Level 2<-----" << endl;
    pirateShipRearrange1 (number2);
    //level 3
    if (p1Score > 0)
    {
      if (p2Score > 0)
      {
      cout << "----->Level 3<-----" << endl;
      pirateShipRearrange2 (number3);
      }
    } 
    
    if (p1Score > 0)
    {
       if (p2Score > 0)
       {
        //level 4
        cout << "----->Level 4<-----" << endl;
        pirateShipRearrange3 (number4);
        }
    }
    //end of game
    ceaseFire();
   
      string prev1;
      string prev2;
      int count4= 0;
      prev1=names[0];
      prev2=names[1];      
      
      names[3] = prev2;
      names[2] = prev1;
      names[1] = p2Name;      
      names[0] = p1Name;
      
       
       
      //names[4] = 
      
      
      ofstream highScore;
      highScore.open ("scores.txt");
      //highScore << p1Name << endl;
    while (count4 < ARRAY_SIZE)
     {
      highScore << names[count4] << endl;
      ++count4;
     }     
      
    
      cout << "successful write to file" << endl;
    
    
      highScore.close();
      //}    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}


void ceaseFire()
{
    cout<<"CEASE FIRE!!! " << endl;  
    cout << "Final Scores: " << endl; 
    cout << "S.S "<< p1Name << " Score: " << p1Score << endl; 
    cout << "S.S "<< p2Name << " Score: " << p2Score << endl; 
    if (p1Score > p2Score)
    {
       cout << "S.S " << p1Name << " wins!!" << endl;
    }
    if (p1Score < p2Score)
    {
       cout << "S.S " << p2Name << " wins!!" << endl;
    }
    if (p1Score == p2Score)
    {
       cout << "Its a tie. Shame =( " << endl;
    } 
    
     
 }

void pirateShipIntro (int number)
{
     //cout << number << endl;
     cout << "----->Level 1<-----" << endl;
     cout << "Two ships meet on the open sea." << endl;
     cout << "S.S " << p1Name << " fires first" << endl;
     int distance = number;
     
   while (p1Turn <= 5 && p2Turn <= 5)
     {
     
           
         cout << "                                         Volley " << p1Turn << endl;
         cout << "                                         Player 1 Score: " << p1Score << endl;
         cout << "                                         Player 2 Score: " << p2Score << endl;  
         player1Shoot ( distance );
         if (p1Guess == 0)
         {
         break;
         }
         else
         {
         player2Shoot ( distance );
         }
     }
     
}

void pirateShipRearrange1 (int number2)
{
   int distance = number2;
   //cout << number2;
   cout << "The two ships rearrange positions." << endl; 
   cout << "S.S " << p2Name << " fires first!" << endl;
   while (p1Turn <= 10 && p2Turn <= 10)
   {
    if (p1Score > 0 && p2Score > 0)
    {
    cout << "                                     Volley " << p1Turn << endl;
    cout << "                                     Player 1 Score: " << p1Score << endl;
    cout << "                                     Player 2 Score: " << p2Score << endl;
    player2Shoot (distance);
    if (p2Guess == 0)
    {
    break;
    }
    else
    {
    player1Shoot (distance);
    }
    }     
   } 
     
 }
 
 void pirateShipRearrange2 (int number3)
{
   int distance = number3;
   //cout<< number3;
   cout << "The two ships rearrange positions." << endl; 
   cout << "S.S " << p1Name << " fires first!" << endl;
   while (p1Turn <= 15 && p2Turn <= 15)
   {
    cout << "                                     Volley " << p1Turn << endl;
    cout << "                                     Player 1 Score: " << p1Score << endl;
    cout << "                                     Player 2 Score: " << p2Score << endl;
    player1Shoot (distance);
    if (p1Guess == 0)
    {
    break;
    }
    else
    {
    player2Shoot (distance);
    }     
   } 
     
 }
 
 void pirateShipRearrange3 (int number4)
{
   int distance = number4;
   //cout << number4;
   cout << "The two ships rearrange positions." << endl; 
   cout << "S.S " << p2Name << " fires first!" << endl;
   while (p1Turn <= 20 && p2Turn <= 20)
   {
    cout << "                                     Volley " << p1Turn << endl;
    cout << "                                     Player 1 Score: " << p1Score << endl;
    cout << "                                     Player 2 Score: " << p2Score << endl;
    player2Shoot (distance);
    if (p2Guess == 0)
    {
    break;
    }
    else
    {
    player1Shoot (distance);
    }     
   } 
     
 }
     
void player1Shoot (int distance)
{
     int distance1 = distance;

     cout << "S.S " << p1Name << " set distance for cannon to fire" << endl;
     cin >> p1Guess;
     cout << "FIRE!!!" << endl;
     if (p1Guess == distance)
      {
          cout << "Direct hit! -15 to S.S " << p2Name << endl;
          p2Score -= 15;
          p1Turn++;
      }       
     if (p1Guess < distance)
     {
          cout << "Cannon ball fell short. Try again" << endl;
          p1Turn++;       
     }
     if (p1Guess > distance)
     {
          cout << "Overshoot! Too high!" << endl;
          p1Turn++;       
     }
    
  
}

void player2Shoot (int distance)
{
  cout << "S.S " << p2Name << " returns fire!" << endl;
     cout << "S.S. "<< p2Name << " set distance for cannon to fire!" << endl;
     cin >> p2Guess;
     cout << "FIRE!!!" << endl;
      if (p2Guess == distance)
      {
          cout << "Direct hit! -15 to S.S " << p1Name << endl;
          p1Score -= 15;
          p2Turn++;
      }       
     if (p1Guess < distance)
     {
          cout << "Cannon ball fell short. Try again" << endl;
          p2Turn++;       
     }
     if (p1Guess > distance)
     {
          cout << "Overshoot! Too high!" << endl;
          p2Turn++;       
     }   
     
 }
     
     
     


