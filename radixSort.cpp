#include <string>
#include <array>
#include "radixSort.h"

using namespace std;

radixSort::radixSort()
{

}

void radixSort::countSort(string A[], int n, int pos)
{
  int range = 26; // Range of letters. We know that there are 26 letters in the English Alphabet.
  int count[range]; // Instantiating array B(count)
  
  //Count each occurance of each letter
  for (int i = 0; i < n; ++i) 
  {
        char ch = A[i][pos];
        count[ch]++;
  }
  //Convert occurrences to the index positions
  for (int i = 1; i < range; ++i) 
  {
        count[i] += count[i - 1];
  }
  //Output Array building. 
  for (int i = size - 1; i >= 0; --i) 
  {
        char ch = A[i][pos];
        output[count[ch] - 1] = A[i];
        count[ch]--;
  }
  //Replace A[] with sorted output array.
  for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
  
}

void radixSort::sort(string A[], int n, int d)
{
    for (int i = d - 1; i >= 0; --i) {
        radixSort::countSort(A, n, i);
    }
}
