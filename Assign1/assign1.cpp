/***********************************************************
CSCI 241 - Assignment 1 - Fall 2018

Progammer: Kenneth Harris
Purpose: This  program counts the number of times the 
	words in an input text file occur. 
************************************************************/ 

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

using namespace std;

struct WordCount
   {
   char word[31];
   int count;
   };


int countWords(const char*, WordCount[]);
void stripPunctuation(char*);
void stringToUpper(char*);
int searchForWord(const char*, const WordCount[], int);
void sortWords(WordCount[], int);
void printWords(const WordCount[], int);

int main(int argc, char* argv[])
   {
	WordCount wordArray[200];
	int numWords = 0;
	ifstream in;

   if (argc == 1)
      {
      cout << "Usage: assign1 [file-name]\n";
      exit(1);
      }
   
	else
	{

   numWords = countWords(argv[1], wordArray);
   printWords(wordArray, numWords);
	
	}
   return 0;
   }

int countWords(const char* fileName, WordCount wordArray[])
	{
  
	ifstream inFile;
	inFile.open(fileName,ios::in);
	char word[31];
	int numWords = 0;
	inFile>>word;

	if(!inFile)
{	
	cout << "Error opening file";
	exit(1);
}

   while (inFile >> word)
      {
      	stringToUpper(word);
      	stripPunctuation(word);

      	int found = searchForWord(word, wordArray, numWords);

	  	if(found == -1)
      	{
      		strcpy(wordArray[numWords].word,word);
      		wordArray[numWords].count = 1;
      		numWords++;
		  }
		  else

		wordArray[found].count+=1;
		inFile>>word;
      }

   inFile.close();

	return numWords;
	}

void stripPunctuation(char* s)
  {
   int pos=0;
   for (char *p = s; *p; ++p)
       if (isalpha(*p))
           s[pos++] = *p;
   s[pos] = '\0';
}

void stringToUpper(char* s)
  
{
   	for(int i=0;s[i]!='\0';i++)
   {
       if(*(s+i)>=97 && *(s+i)<=122)
           *(s+i)=*(s+i)-32;
   }

	}

int searchForWord(const char* word, const WordCount wordArray[], int numWords)
	{
	 int i;

	 for(i=0;i<numWords;i++)
       if(strcmp(wordArray[i].word,word)==0)
           return i;

   return -1;

	}

void sortWords(WordCount wordArray[], int numWords)
{
	int i, j;
	int min = 0;

   for(i=0;i<numWords-1;i++)
       for(j=0;j<numWords-i-1;j++)
       {
           if(strcmp(wordArray[j].word,wordArray[min].word)==0)
           {

               WordCount temp=wordArray[j];
               wordArray[j]=wordArray[min];
               wordArray[min]=temp;
           }
       }
}


void printWords(const WordCount wordArray[], int numWords)
	{
		int i;

		cout << "Word" << setw(10) << "Count\n" <<endl;
		for(i=0; i < numWords; i++)
		{
			cout << wordArray[i].word << setw(10) << wordArray[i].count << endl;

		}

		cout << "\n\n\nNumber of words:" << setw(10) << numWords << endl;


	}
