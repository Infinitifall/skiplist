# SkipList

A [skip list](https://en.wikipedia.org/wiki/Skip_list) is a probabilistic data structure that is efficient, compact and concurrency friendly.

- $O(\log n)$ insertion, deletion and search on average
- $O(n)$ space on average
- $O(1)$ predecessor and successor

## Setup

```bash
# clone repo
git clone git@github.com:Infinitifall/skiplist.git
cd skiplist
```

## C implementation

```bash
# build
cd c
make
```

- `example_simple` creates a skiplist, inserts 100000 random integers and then pretty prints it

    ```bash
    $ ./example_simple
    Creating skiplist and populating with 100000 random numbers
                -999997, __
                -999941, _
                -999919, _
                -999882, ______
                -999877, _
                -999766, __
                ...
                999889, ____
                999906, _
                999926, __
                999930, _____
                999932, ____
                999946, _
    ```

- `example_cli` provides a cli interface to insert/delete, bulk random insert/delete, search, print/pretty print every level of a created skiplist
  
    ```
    $ ./example_cli
    A new skiplist has been created

    i <val>         : Insert the element <val> into list
    r <val>         : Remove the element <val> from list
    s <val>         : Search for element <val> in list
    p <val>         : Print all list elements at level <val>
    P <val>         : Pretty print all list elements at level <val>
    I <num> <max>   : Insert <num> random numbers from range (-<max>, <max>) to list
    R <num> <max>   : Remove <num> random numbers from range (-<max>, <max>) to list

    > I 1000 1000000
    Inserted 1000 random numbers from range (-1000000, 1000000)
    > P 20
    Pretty printing list
    No elements!
    > P 7
    Pretty printing list
              -845909, ________
              -550701, __________
              -131736, ___________
              -107562, _________
               -47074, _________
                45063, __________
                51735, ________
               258051, ________
               390358, __________
               438146, ________
               489210, ________
               809451, ________
               966848, ________
    > s 258051
    Found 258051, 8
    >
    ```
  
  

