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

* 7) Huffman coding - Step 2: Extract

Once we have our priority queue initialized, the next step is to build the Huffman tree. First we need to understand the process of building such a tree. We need to extract the two least frequent symbols from our priority queue, add their frequencies, and store this new frequency back in our priority queue.

Remember that in our priority queue, each node stores a leaf node that stores our symbol_t \*. The goal here, is to make the two extracted nodes(containing the symbol_t \*) the children of the new node we will create (the one that will store the the sum of the two frequencies). The first extracted node will be the left child, and the second one will be the right child. Then this node will be stored (inside a node) in our priority queue.

So, at the end of this process, our priority queue will see its size decreased by one (we extract two, we insert back one). Note that we will use the value -1 as the char data for the new symbol we will create. (In the example below, we print it as a dollar sign)

huffman_extract_and_insert.c - Contains  a function that extracts the two nodes of the priority queue and insert a new one
```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 7-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c binary_tree_print.c -o extract
$ ./extract
         .--------(a/6)---------.
   .--(b/11)---.          .--(c/12)
(d/13)      (e/16)     (f/36)

         .--------(c/12)---.
   .--(d/13)---.        (e/16)
(f/36)      ($/17)

         .--(e/16)---.
   .--($/17)      (f/36)
($/25)
$
```

* 8) Huffman coding - Step 3: Build Huffman tree

Following the previous step, we now have to iterate the same operation until there is only one node remaining in our priority queue. This final node will store the root node of our Huffman tree.

huffman_tree.c - Contains a function that builds the Huffman tree

```
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 8-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c binary_tree_print.c -o huffman_tree
$ ./huffman_tree
   .--($/94)---------------------.
(f/36)               .--------($/58)---------.
               .--($/25)---.           .--($/33)--------.
            (c/12)      (d/13)      (e/16)        .--($/17)---.
                                                (a/6)      (b/11)
$
```

* 9) Huffman coding - Step 4: Huffman codes

Now that we have our Huffman tree, we are able to get the Huffman codes for each letter. This process is pretty straight forward: go through the Huffman tree starting at the root node. Each time you go to the left node, append a 0 to the code. Each time you go to the right, append a 0 to the code. When you hit a leaf node, get the letter and print its corresponding Huffman code.

huffman_codes.c - Contains a function that build the Huffman tree and print the resulting Huffman codes for each symbol

```
$gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 9-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c huffman_codes.c binary_tree_print.c -o huffman_codes
$./huffman_codes
f: 0
c: 100
d: 101
e: 110
a: 1110
b: 1111
$
```

### Usefull Resources:
* [Binary Heap](https://en.wikipedia.org/wiki/Binary_heap)
* [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding)
* [Enumerated Types](http://www.cs.utah.edu/~germain/PPS/Topics/C_Language/enumerated_types.html)
* [Huffman Coding and Huffman Trees](https://www.youtube.com/watch?v=JsTptu56GM8)
