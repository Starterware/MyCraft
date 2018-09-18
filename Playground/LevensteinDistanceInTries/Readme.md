[Home](https://github.com/Starterware/Training)

# Levenstein Distance In Tries

Started a little project to see the impact of Levenstein Distance performance in a Trie (Recursive and iterative) vs a simple Set.
The Tries are implemented in such a way that they don't have leaf nodes in order to limit the memory use. 

## Usage

Without parameters the program will run the unit test (googletests) and when adding --benchmarks, it will run the benchmarks.
At the moment, the program only works on Windows systems.

## Benchmarks

### System

Run on a laptop with windows 10 Home

Processor: Intel(R) Core(TM) i7-6700HQ CPU @ 2.60GHz

Installed Memory: 8,00 GB

System Type: 64-bit OS, x64-based processor

### Results

=========== Set Dictionary benchmark tests ===========

----- Set Dictionary estimated times [4665 entries] -----

  Creation: 2.665 ms
  
  Used Memory: 652 kB
  
  Search (10000 times 10 findable words and 10 not found words): 25.312 ms
  
  Search best matches (10 words): 344.104 ms

----- Set Dictionary estimated times [46654 entries] -----

  Creation: 24.084 ms
  
  Used Memory: 3376 kB
  
  Search (10000 times 10 findable words and 10 not found words): 28.543 ms
  
  Search best matches (10 words): 3219.26 ms

----- Set Dictionary estimated times [466544 entries] -----

  Creation: 220.751 ms
  
  Used Memory: 34884 kB
  
  Search (10000 times 10 findable words and 10 not found words): 35.691 ms
  
  Search best matches (10 words): 30175 ms

=========== Set Dictionary benchmark tests ===========

=========== Trie Dictionary benchmark tests ===========

----- Trie Dictionary estimated times [4665 entries] -----

  Creation: 7.995 ms
  
  Used Memory: 6644 kB
  
  Search (10000 times 10 findable words and 10 not found words): 53.091 ms
  
  Search best matches (10 words): 242.809 ms

----- Trie Dictionary estimated times [46654 entries] -----

  Creation: 78.708 ms
  
  Used Memory: 36316 kB
  
  Search (10000 times 10 findable words and 10 not found words): 54.636 ms
  
  Search best matches (10 words): 1933.24 ms

----- Trie Dictionary estimated times [466544 entries] -----

  Creation: 416.255 ms
  
  Used Memory: 187540 kB
  
  Search (10000 times 10 findable words and 10 not found words): 63.041 ms
  
  Search best matches (10 words): 11355 ms

=========== Trie Dictionary benchmark tests ===========

=========== Recursive Trie Dictionary benchmark tests ===========

----- Recursive Trie Dictionary estimated times [4665 entries] -----

  Creation: 9.391 ms
  
  Used Memory: 7524 kB
  
  Search (10000 times 10 findable words and 10 not found words): 66.191 ms
  
  Search best matches (10 words): 253.167 ms
  

----- Recursive Trie Dictionary estimated times [46654 entries] -----

  Creation: 90.01 ms
  
  Used Memory: 36384 kB
  
  Search (10000 times 10 findable words and 10 not found words): 69.567 ms
  
  Search best matches (10 words): 2055.03 ms

----- Recursive Trie Dictionary estimated times [466544 entries] -----

  Creation: 560.59 ms
  
  Used Memory: 193480 kB
  
  Search (10000 times 10 findable words and 10 not found words): 81.675 ms
  
  Search best matches (10 words): 12491.9 ms

=========== Recursive Trie Dictionary benchmark tests ===========
