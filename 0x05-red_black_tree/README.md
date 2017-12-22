# 0x05. C - Red-Black trees


* rb_trees.h - Header file inluding Data structure defination and funcitons declaration.

* 0-rb_tree_node.c -  Contains a function that creates a Red-Black Tree node

```
$gcc -Wall -Wextra -Werror -pedantic tests/0-main.c 0-rb_tree_node.c tests/rb_tree_print.c -o rb_tree_node
$./rb_tree_node
         .--------B(098)---------.
   .--R(012)---.           .--R(402)---.
B(006)      B(016)      B(256)      B(512)
$

```
* 1-rb_tree_is_valid.c - Contains a function that validates a Red-Black Tree

```
$gcc -Wall -Wextra -Werror -pedantic tests/1-main.c 1-rb_tree_is_valid.c 0-rb_tree_node.c  tests/rb_tree_print.c -o rb_tree_valid
$./rb_tree_valid
         .--------B(098)---.
   .--B(090)---.        B(120)
R(079)      R(095)
Is 98 valid: 1
         .--------------------B(098)---.
   .--R(090)---------.              R(120)---.
B(079)         .--B(095)---.              B(130)
            R(092)      R(096)
Is 98 valid: 0
         .--------------------R(098)---.
   .--R(090)---------.              R(120)---.
B(079)         .--B(095)---.              B(130)
            R(092)      R(096)
Is 98 valid: 0
$
```

* 2-rb_tree_insert.c - Contains a function that inserts a value in a Red-Black Tree

```
$gcc -Wall -Wextra -Werror -pedantic tests/2-main.c 0-rb_tree_node.c 2-rb_tree_insert.c tests/rb_tree_print.c -o rb_tree_insert
$./rb_tree_insert
Inserted: 98
B(098)
Inserted: 402
B(098)---.
      R(402)
Inserted: 512
   .--B(402)---.
R(098)      R(512)
Inserted: 12
         .--B(402)---.
   .--B(098)      B(512)
R(012)
Inserted: 46
         .--------B(402)---.
   .--B(046)---.        B(512)
R(012)      R(098)
Inserted: 128
         .--------------B(402)---.
   .--R(046)---.              B(512)
B(012)      B(098)---.
                  R(128)
Inserted: 256
         .--------------------B(402)---.
   .--R(046)---------.              B(512)
B(012)         .--B(128)---.
            R(098)      R(256)
Inserted: 1
               .--------------------B(402)---.
         .--R(046)---------.              B(512)
   .--B(012)         .--B(128)---.
R(001)            R(098)      R(256)
Node should be nil -> (nil)
Inserted: 624
               .--------------------B(402)---.
         .--R(046)---------.              B(512)---.
   .--B(012)         .--B(128)---.              R(624)
R(001)            R(098)      R(256)
Inserted: 780
               .--------------------B(402)---------.
         .--R(046)---------.                 .--B(624)---.
   .--B(012)         .--B(128)---.        R(512)      R(780)
R(001)            R(098)      R(256)
$

```

* 3-array_to_rb_tree.c - Contains a function that conversta an array to a Red-Black Tree

```
$gcc -Wall -Wextra -Werror -pedantic tests/3-main.c 0-rb_tree_node.c 2-rb_tree_insert.c 3-array_to_rb_tree.c tests/rb_tree_print.c -o rb_tree_array
$./rb_tree_array
                           .--------------B(068)---------.
         .--------------B(032)---------.           .--B(084)---.
   .--R(020)---.                 .--B(047)      B(079)      B(087)---.
B(002)      B(021)---.        R(034)                              R(091)
                  R(022)
$

```

* 4-rb_tree_remove.c - Contains a function that deletes a value in a Red-Black Tree

```
$gcc -Wall -Wextra -Werror -pedantic tests/4-main.c 0-rb_tree_node.c 1-rb_tree_is_valid.c 2-rb_tree_insert.c 3-array_to_rb_tree.c  4-rb_tree_remove.c tests/rb_tree_print.c -o rb_tree_remove
$./rb_tree_remove                .--------B(025)---------.
         .--R(010)---.           .--R(035)---.
   .--B(008)      B(020)      B(030)      B(089)---.
R(007)                                          R(250)

Deleted: 10
         .--------B(025)---------.
   .--R(008)---.           .--R(035)---.
B(007)      B(020)      B(030)      B(089)---.
                                          R(250)

Deleted: 25
         .--------B(030)---------.
   .--R(008)---.           .--R(089)---.
B(007)      B(020)      B(035)      B(250)
Red-Black Tree is valid

Deleted: 20
         .--B(030)---------.
   .--B(008)         .--R(089)---.
R(007)            B(035)      B(250)
Red-Black Tree is valid

Deleted: 250
         .--B(030)---------.
   .--B(008)         .--B(089)
R(007)            R(035)
Red-Black Tree is valid

Deleted: 89
         .--B(030)---.
   .--B(008)      B(035)
R(007)
Red-Black Tree is valid
$

```
Useful Links:

* [Red Black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)
* [Red Black tree Deletion](http://www.diusrex.com/2017/03/painless-red-black-tree-implementation-deletion/)
