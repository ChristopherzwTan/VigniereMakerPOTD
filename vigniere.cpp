#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>

#define letterBase 26

using namespace std;

string stringToUpper(string s);
int letterToint(char c);
char numberTochar(int j);

int main()
{
  //Variables  
  string key;
  string message;
  int arraySize;
  int* keyNum;
  int* messageNum;

  //Get the inputs
  cout << "Please input a key: ";
  cin >> key;

  key = stringToUpper(key); 
 
  cout << "Your key is: " +  key + "\n";

  cout << "Now input your message: ";
  cin >> message;

  message = stringToUpper(message);

  cout << "Your message is: " +  message + "\n";

  
  //Populate these arrays
  keyNum = new int [key.length()];
  messageNum = new int [message.length()];

  for (int i = 0; i < key.length(); i++)
  {
    keyNum[i] = letterToint(key[i]);
  }

  cout << endl;

  for (int i = 0; i < message.length(); i++)
  {
    messageNum[i] = letterToint(message[i]);
  }

  int * finalAnswer = new int[message.length()];

  // Add the arays 
  for (int i = 0; i < message.length(); i++)
  {
    finalAnswer[i] = (messageNum[i] + keyNum[i%key.length()]) % letterBase;
  }  


  cout << "The message is: ";

  for (int i = 0; i < message.length(); i++)
  {
    cout << numberTochar(finalAnswer[i]);
  }

  cout << endl;

  return 0;
}

//Converts a whole string to upper case
string stringToUpper(string s) 
{
  for (int i = 0; i < s.length(); i++) 
  {
    s[i] = toupper(s[i]);
  }

  return s;
}

//Converts an upper case letter into a number of base 26
//i.e. A = 0, B = 1, C = 1, etc..
int letterToint(char c)
{
  return ((int)c - 65); 
}

//Converts a number back to the letter, opposite of letterToint
char numberTochar(int j)
{
  return ((char)(j+=65)); 
}

