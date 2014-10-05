Family Vacation Problem
=======================

### Problem
Design and code several algorithms for the planning of a family vacation. As input, there is given a predefinted route from city *P_1* (Santa Barbara) to city *P_n* (Boston), where *n* is a positive integer greater than one and each city has a cost and a distance from the previous city. The route starts in Santa Barbara and ends in Boston and passes through cities *P_2*, *P_3*, ..., *P_n-1*. There are several versions of this problem that differ only in the objective function. The problem demonstrates how greedy methods can be used to provide solutions to different versions of this problem. 
##### Version 1
Minimize cost, then days spent driving
##### Version 2
Minimize days spent driving, then cost
##### Version 3
Given at most *t* days spent driving, minimize cost
##### Version 4
Given at most *t* cost, minimize days spent driving
##### Version 5
Given at most *t* days spent driving, maximize cost

### Implementation
All procedures DP1, DP2, ... DP8 use dynamic programming algorithms to provide optimal solutions to the different versions of the problem. Some implementations use recursion and some avoid recomputation by using additional memory.
