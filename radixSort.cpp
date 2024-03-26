#include <string>
#include <array>
#include <iostream>
#include "radixSort.h"

using namespace std;

radixSort::radixSort()
{

}

void radixSort::countSort(string A[], int n, int pos)
{
  const int range = 26; // 26 Letters in English Alphabet.
  int count[range] = {0}; // C array from textbook. 

  //Fill C with number of character occurences.
  for (int i = 0; i < n; i++) 
  {
      int occurance = A[i][pos] - 'A'; // We need to remove an A or face a memory leak.
      count[occurance]+ 1;
  }

  //translate C into the index positions.
  for (int i = 1; i < range; i++) 
  {
    count[i] += count[i - 1];
  }

  string output[n]; //Instantiating B, the "output" array.
    
  //Build B in sorted order.
  for (int i = n - 1; i >= 0; i--) 
  {
    int occurance = A[i][pos] - 'A';
    output[count[occurance] - 1] = A[i];
    count[occurance] - 1;
  }

  //Change A into sorted result.
  for (int i = 0; i < n; ++i) 
  {
    A[i] = output[i];
  }
  // Future Reference: output & count should be dynamically allocated for garbage collection reasons.
}

void radixSort::sort(string A[], int n, int d)
{
    for (int i = d - 1; i >= 0; i--) {
        radixSort::countSort(A, n, i);
    }
}
