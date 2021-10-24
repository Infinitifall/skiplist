# SkipList
C implementation of [skip list](https://en.wikipedia.org/wiki/Skip_list), a probabilistic data structure that is efficient, compact and concurrency friendly.

- O(logn) insertion, deletion and search, O(1) predecessor and successor, O(n) space
- Header file [skiplist.h](skiplist.h) provides a documented interface

## Use skip lists in your own project
Add files [skiplist.c](skiplist.c), [skiplist.h](skiplist.h) to your project and `#include "skiplist.h"` where necessary.

## Examples
Compile and run the example programs provided

```
make example_simple
./example_simple
```

```
make example_cli
./example_cli
```