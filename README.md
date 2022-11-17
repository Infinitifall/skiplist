# SkipList

A [skip list](https://en.wikipedia.org/wiki/Skip_list) is a probabilistic data structure that is efficient, compact and concurrency friendly.

- $O(\log n)$ insertion, deletion and search on average
- $O(n)$ space on average
- $O(1)$ predecessor and successor

<figure>
  <img
  src="https://upload.wikimedia.org/wikipedia/commons/2/2c/Skip_list_add_element-en.gif"
  alt="Skiplist">
  <figcaption>Artyom Kalinin, CC BY-SA 3.0 <https://creativecommons.org/licenses/by-sa/3.0>, via Wikimedia Commons</figcaption>
</figure>

## C implementation

```
make example_simple
./example_simple
```

This creates a skiplist, inserts 100000 random integers and pretty prints it.

```
make example_cli
./example_cli
```

This creates a skiplist and then provides a cli interface that allows you to insert, delete, bulk random insert, bulk random delete, search and print every level of the skiplist.

