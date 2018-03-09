# 0x07. C - Pathfinding
##  System programming & Algorithm ― Data structures and Algorithms

0. Backtracking - Array  

0-backtracking_array.c -
 Contains a function that searches for the first path from a starting point to a target point within a two-dimensional array

I have used recursive backtracking to find the first working path from start to target

Algorithm used:
Initially a copy of map is made which is later deallocated at the end
```
FIND-PATH(x, y)

1. if (x,y outside maze) return false
2. if (x,y is goal) add to stack and return true
3. if (x,y not open) return false
4. mark x,y as part of solution path and add to stack
5. if (FIND-PATH(RIGHT of x,y) == true) return true
6. if (FIND-PATH(BELOW of x,y) == true) return true
7. if (FIND-PATH(LEFT of x,y) == true) return true
8. if (FIND-PATH(TOP of x,y) == true) return true
9. unmark x,y as part of solution path and pop the stack then return false
```

Useful Resources:
* [Algorithm for recursive back tracking of a maze](https://www.cs.bu.edu/teaching/alg/maze)
