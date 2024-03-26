/*
    Daniel Bennett 
    CSC-308
    Radix Sort Project

    Compiled with g++ compiler
    g++ main.cpp radixSort.cpp Timer.cpp -o RadixSort -std=c++11
*/


#include <iostream>
#include <fstream>
#include <string>
#include "timer.h"
#include "radixSort.h"

using namespace std;

const int wordListOneSize = 8000;
const int wordListTwoSize = 16000;
const int wordListThreeSize = 24000;
const int wordListFourSize = 32000;
const int wordListFiveSize = 40000;
const int wordSize = 8;

const string wordListOne= "8000_words.txt";
const string wordListTwo = "16000_words.txt";
const string wordListThree = "24000_words.txt";
const string wordListFour = "32000_words.txt";
const string wordListFive = "40000_words.txt";

void readWords(string file, string ar[], int size)
{
	// Open the text file using the file variable
    ifstream inputFile(file);

    // Check to see if the file is open. If open, ignore. Otherwise, throw error.
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
    }


    string line;
	getline(inputFile, line);
	line.clear();

    //This goes line by line and inputs each word into the array directly.
   for (int i = 0; i < size; ++i) {
        getline(inputFile, line);
        ar[i] = line;
    }

    inputFile.close();
}


int main() {
	//String List
    string* words = new string[wordListOneSize];

    //Array for each time so we can add it all up later.
    double* timeList = new double[5];

	// First wordlist
	readWords(wordListOne, words, wordListOneSize);
    
    radixSort sorter;
    //Time & sort first wordlist.
    cout << "Timer starting now." << endl;
    Timer* time = new Timer;
    sorter.sort(words, wordListOneSize, wordSize);
    double seconds= time->elapsed_time();
    time->reset();
    timeList[0] = seconds;
    cout << endl << "First list sorted in " << seconds << " seconds." << endl;

    
    delete[] words;
    delete time;

    // Second wordlist
    words = new string[wordListTwoSize];
	readWords(wordListTwo, words, wordListTwoSize);
    //Time & sort second wordlist
    cout << "Timer starting now." << endl;
    time = new Timer;
    sorter.sort(words, wordListTwoSize, wordSize);
    seconds= time->elapsed_time();
    time->reset();
    timeList[1] = seconds;
    cout << endl << "Second list sorted in " << seconds << " seconds." << endl;
    delete[] words;
    delete time;

    // Third wordlist
    words = new string[wordListThreeSize];
	readWords(wordListThree, words, wordListThreeSize);
    //Time & sort third wordlist
    cout << "Timer starting now." << endl;
    time = new Timer;
    sorter.sort(words, wordListThreeSize, wordSize);
    seconds= time->elapsed_time();
    time->reset();
    timeList[2] = seconds;
    cout << endl << "Third list sorted in " << seconds << " seconds." << endl;
    delete[] words;
    delete time;


    // Fourth wordlist
    words = new string[wordListFourSize];
	readWords(wordListFour, words, wordListFourSize);
    //Time & sort fourth wordlist
    cout << "Timer starting now." << endl;
    time = new Timer;
    sorter.sort(words, wordListFourSize, wordSize);
    seconds= time->elapsed_time();
    time->reset();
    timeList[3] = seconds;
    cout << endl << "Fourth list sorted in " << seconds << " seconds." << endl;
    delete[] words;
    delete time;


    // Fifth wordlist
    words = new string[wordListFiveSize];
	readWords(wordListFive, words, wordListFiveSize);
    //Time & sort fifth wordlist
    cout << "Timer starting now." << endl;
    time = new Timer;
    sorter.sort(words, wordListFiveSize, wordSize);
    seconds= time->elapsed_time();
    time->reset();
    timeList[4] = seconds;
    cout << endl << "Fitfh list sorted in " << seconds << " seconds." << endl;
    delete[] words;
    delete time;


    double totalTime = 0;
    for(int i = 0; i < 5; i++)
    {
        totalTime += timeList[i];
    }

    cout << "Total time for all lists:  " << totalTime << "seconds." << endl;

    return 0;
}

/*
    TIMES: 
    First list sorted in 0.005709 seconds.

    Second list sorted in 0.00703 seconds.

    Third list sorted in 0.010381 seconds.

    Fourth list sorted in 0.013841 seconds.

    Fitfh list sorted in 0.017297 seconds.
    Total time for all lists:  0.054258seconds.



*/

