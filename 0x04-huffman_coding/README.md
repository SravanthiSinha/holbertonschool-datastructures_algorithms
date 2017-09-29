# 0x04. C - Huffman coding
### System programming & Algorithm ― Data structures and Algorithms

* 0) Min Binary Heap - Create heap

heap/heap_create.c -  Contains a function that creates a Heap data structure

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 0-main.c -o heap_create
$ ./heap_create
Heap size: 0
Heap root: (nil)
$
```

* 1) Min Binary Heap - Create node

heap/binary_tree_node.c - Contains a function that creates a generic Binary Tree node

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 1-main.c -o binary_tree_node
$ ./binary_tree_node
Node(0x17e9010): data(5) left((nil)) right((nil)) parent((nil))
Node(0x17e9040): data(10) left((nil)) right((nil)) parent(0x17e9010)
$
```

* 2) Min Binary Heap - Insert node

heap/heap_insert.c - Contains a function that inserts a value in a Min Binary Heap
```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 2-main.c binary_tree_print.c -o heap_insert
$ ./heap_insert
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

       .-------(002)-------.
  .--(023)--.         .--(045)
(034)     (076)     (048)

       .-------(002)-------.
  .--(023)--.         .--(045)--.
(034)     (076)     (048)     (098)

            .-------(002)-------.
       .--(023)--.         .--(045)--.
  .--(034)     (076)     (048)     (098)
(047)

Heap size: 8
$
```

* 3) Min Binary Heap - Extract

heap/heap_extract.c - Contains a function that extracts the root value of a Min Binary Heap

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 3-main.c binary_tree_print.c -o heap_extract
$ ./heap_extract
Heap size: 0
Heap root: (nil)
                 .------------(001)-------.
       .-------(002)-------.         .--(028)--.
  .--(011)--.         .--(003)     (076)     (033)
(045)     (023)     (034)
Heap size: 10

Extracted: 1
                 .-------(002)-------.
       .-------(003)--.         .--(028)--.
  .--(011)--.       (034)     (076)     (033)
(045)     (023)
Heap size: 9
$
```

* 4) Min Binary Heap - Delete heap

heap/heap_delete.c - Contains a function that deallocates a heap

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 4-main.c binary_tree_print.c -o heap_delete
$ valgrind ./heap_delete
==102349== Memcheck, a memory error detector
==102349== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==102349== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==102349== Command: ./heap_delete
==102349==
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

Heap size: 5
==102349==
==102349== HEAP SUMMARY:
==102349==     in use at exit: 0 bytes in 0 blocks
==102349==   total heap usage: 30 allocs, 30 frees, 3,373 bytes allocated
==102349==
==102349== All heap blocks were freed -- no leaks are possible
==102349==
==102349== For counts of detected and suppressed errors, rerun with: -v
==102349== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$
```

* 5) Symbols: Create symbol

symbol.c - Contains a function that creates a symbol_t data structure

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 5-main.c symbol.c -o symbol_create
$ ./symbol_create
Symbol: data(d) frequency(3)
Symbol: data(H) frequency(98)
$
```

* 6) Huffman coding - Step 1: Priority queue

The first step to get the Huffman codes of our letters is to build a priority queue. The value of frequency field will be used to compare two nodes in this min heap. Once built, the least frequent character will be stored in the root node of our priority queue.

huffman_priority_queue.c - Contains a function that creates a priority queue for the Huffman coding algorithm

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 6-main.c symbol.c huffman_priority_queue.c binary_tree_print.c -o prio
$ ./prio
         .--------(a/6)---------.
   .--(b/11)---.          .--(c/12)
(d/13)      (e/16)     (f/36)
$
```
### Usefull Resources:
* [Binary Heap](https://en.wikipedia.org/wiki/Binary_heap)
* [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding)
* [Enumerated Types](http://www.cs.utah.edu/~germain/PPS/Topics/C_Language/enumerated_types.html)
* [Huffman Coding and Huffman Trees](https://www.youtube.com/watch?v=JsTptu56GM8)
