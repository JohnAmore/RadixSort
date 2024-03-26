#include <string>
#include <array>
#include "radixSort.h"

using namespace std;

radixSort::radixSort()
{

}

radixSort::countSort(string A[], int n, int pos)
{
  int range = 26; // Range of letters. We know that there are 26 letters in the English Alphabet.
  int count[range] = {0}; // Instantiating array B(count)
  
  //Count each occurance of each letter
  for (int i = 0; i < size; ++i) {
        char ch = arr[i][exp];
        count[ch - 'A']++;
    }

}

radixSort::sort(string A[], int n, int d)
{
    for (int i = d - 1; i >= 0; --i) {
        countingSort(arr, i);
    }
}
