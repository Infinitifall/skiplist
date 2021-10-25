# SkipList
C implementation of a [skip list](https://en.wikipedia.org/wiki/Skip_list), a probabilistic data structure that is efficient, compact and concurrency friendly. The header file [skiplist.h](skiplist.h) provides docstrings for all functions.

Skip lists provide `O(logn)` insertion, deletion and search on average, `O(1)` predecessor and successor and `O(n)` space on average. 

![](https://www.osa.fu-berlin.de/bioinformatics_msc/en/_media/bild_beispielaufgabe_i1/Skip_list.png)

## Use skiplist in your own project
Add files [skiplist.c](skiplist.c), [skiplist.h](skiplist.h) to your project and `#include "skiplist.h"` where necessary.

## Example
Compile and run the example programs provided

```
make example_simple
./example_simple
```
This creates a skiplist and inserts 10000 random integers and prints the entire skiplist.

```
make example_cli
./example_cli
```
This creates a skiplist and then allows you to insert, bulk random insert, delete, bulk random delete, search and print every level of the skiplist.
