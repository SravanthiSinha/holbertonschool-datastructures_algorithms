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

### Usefull Resources:
* [Binary Heap](https://en.wikipedia.org/wiki/Binary_heap)
* [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding)
* [Enumerated Types](http://www.cs.utah.edu/~germain/PPS/Topics/C_Language/enumerated_types.html)
* [Huffman Coding and Huffman Trees](https://www.youtube.com/watch?v=JsTptu56GM8)
