# Levenstein Distance In Tries

Started a little project to see the impact of Levenstein Distance performance in a Trie (Recursive and iterative) vs a simple Set.

## C++

### Usage

The project is cut in three parts:
 * The LevensteinDictionaryInTries libraries, which contains the Tries and Set code
 * The LevensteinDictionaryInTriesTests executable, which contains all the tests
 * The LevensteinDictionaryInTriesBenchmarks executable, which contains some benchmark tests
 
It is possible to modify the benchmarks by going to the data folder in the benchmark folder. There are three files: 
 * words.txt: which are the dictionary words
 * words_to_search.txt: which are the well spelled words to search
 * words_to_search_wrong_spelling.txt: which are the wrongly spelled words. Each row starts with the wrongly spelled word, followed by the expected results (words with the same LV distance).

### Implementation

The Tries are implemented in such a way that they don't have leaf nodes in order to limit the memory use. However, this makes the algorithms a bit harder to understand.

The first version showed already that the Tries where ~3 times faster than the Set implementation (especially on the big dictionaries). Then, the get_potential_best methods was added 
on the LevensteinDistanceCalculator and it made the Tries ~3 times faster. The final implementation, on the RecursiveTrie, first sorts the children according to their potential best score.
This allow the prune even more the Trie. The sorting has not been added to the non-recursive Trie for code lisibility reasons. 

### Limitations

 * The code has not been tested on other platforms than windows. The benchmarks will for sure fail on other platforms.

## Benchmarks

### System

Run on a laptop with windows 10 Home:

 * Processor: Intel(R) Core(TM) i7-6700HQ CPU @ 2.60GHz

 * Installed Memory: 8,00 GB

 * System Type: 64-bit OS, x64-based processor

### C++ Results

=========== Set Dictionary benchmark tests ===========

----- Set Dictionary estimated times [4665 entries] -----

  Creation: 2.065 ms
  
  Used Memory: 568 kB
  
  Search (10000 times 10 findable words and 10 not found words): 21.917 ms
  
  Search best matches (10 words): 273.518 ms

----- Set Dictionary estimated times [46654 entries] -----

  Creation: 21.567 ms
  
  Used Memory: 2388 kB
  
  Search (10000 times 10 findable words and 10 not found words): 35.064 ms
  
  Search best matches (10 words): 2824.06 ms

----- Set Dictionary estimated times [466544 entries] -----

  Creation: 228.558 ms
  
  Used Memory: 34744 kB
  
  Search (10000 times 10 findable words and 10 not found words): 37.404 ms
  
  Search best matches (10 words): 28261.6 ms

=========== Set Dictionary benchmark tests ===========

=========== Trie Dictionary benchmark tests ===========

----- Trie Dictionary estimated times [4665 entries] -----

  Creation: 10.347 ms
  
  Used Memory: 6528 kB
  
  Search (10000 times 10 findable words and 10 not found words): 71.871 ms
  
  Search best matches (10 words): 101.748 ms

----- Trie Dictionary estimated times [46654 entries] -----

  Creation: 74.714 ms
  
  Used Memory: 36552 kB
  
  Search (10000 times 10 findable words and 10 not found words): 68.89 ms
  
  Search best matches (10 words): 572.583 ms

----- Trie Dictionary estimated times [466544 entries] -----

  Creation: 449.958 ms
  
  Used Memory: 187536 kB
  
  Search (10000 times 10 findable words and 10 not found words): 61.739 ms
  
  Search best matches (10 words): 2318.9 ms

=========== Trie Dictionary benchmark tests ===========

=========== Recursive Trie Dictionary benchmark tests ===========

----- Recursive Trie Dictionary estimated times [4665 entries] -----

  Creation: 11.658 ms
  
  Used Memory: 6668 kB
  
  Search (10000 times 10 findable words and 10 not found words): 62.928 ms
  
  Search best matches (10 words): 42.884 ms

----- Recursive Trie Dictionary estimated times [46654 entries] -----

  Creation: 80.477 ms
  
  Used Memory: 37808 kB
  
  Search (10000 times 10 findable words and 10 not found words): 68.882 ms
  
  Search best matches (10 words): 195.968 ms

----- Recursive Trie Dictionary estimated times [466544 entries] -----

  Creation: 533.413 ms
  
  Used Memory: 192856 kB
  
  Search (10000 times 10 findable words and 10 not found words): 85.026 ms
  
  Search best matches (10 words): 456.566 ms

=========== Recursive Trie Dictionary benchmark tests ===========