Library Hierarchy
-----------------

  - **Graph.cpp**
    - [x] SCC (Tarjan)
    - [x] TopSort
    - [x] Minimum Spanning Tree
    - [x] Dijkstra
    - [x] Articulation Point, Bridge, Biconnected Components [partially tested]
    - [x] Hofcroft-Karp Matching + Minimum Vertex Cover (Maximum Independent Set)
    - [x] Stable Matching
    - [x] Euler Tour
    - [x] Push Relabel Flow
    - [ ] 2-Connected Component
    - [ ] Min Cost Max Flow
    - [ ] Global Min Cut
    - [ ] Edmond's Blossom Algorithm
    - [ ] Bellman-Ford
    - [ ] Heavy-Light Decomposition
    - [ ] Suurballe's Algorithm
    - [ ] Directed MST
    - [ ] Array Represtation Of Adj. List


  - **Geometry.cpp**
    - [x] Common Geometry Routines
    - [x] Fraction
    - [x] Convex Hull
    - [ ] Triangulation
    - [ ] Closest Pair of Points
    - [ ] Rotating Calipers
    
  - **Math.cpp**
    - [x] FFT
    - [ ] Simplex
    - [ ] Gauss-Jordan
    - [ ] Extended Euclid
    - [ ] Diophantine Equation
    - [ ] Reduced Row Echelon Form
    - [ ] Matrix Class
    
  - **String.cpp**
    - [x] Lexicographically Smallest Rotation (Booth's Algorithm)
    - [ ] Longest palindromic substring
    - [ ] Suffix Array
    - [ ] Automata
    - [ ] KMP
    
  - **DS.cpp**
    - [x] LIS
    - [x] Union Find
    - [x] Trie [#TODO: Implement delete function]
    - [x] Static Trie
    - [ ] BIT
    - [ ] Segment Tree
    - [ ] 2D Segment Tree
    - [ ] Sparse Segment Tree
    - [ ] LCA
    - [ ] Dates
    - [ ] BigInt
    - [ ] RMQ, RMedianQ
    - [ ] Splay Tree
    - [ ] Link/Cut Tree
    - [ ] Treap
    - [ ] AVL Tree

  - **DP.cpp**
    - [ ] Monotonous Queue [ min (j < i) { a[j] + b[j] * c[i] } ]
    - [ ] Dynamic Monotonous Queue
    - [ ] Knuth Optimization [ dp[i][j] = C[i][j] + min (i < k < j) { dp[i][k] + dp[k][j] }, C concave ]
    - [ ] Divide and Conquer [ dp[i][j] = min (k < j) { dp[i - 1][k] + C[k][j] } ]
    - [ ] dp[i] = min (j < i) { f( dp[j] ) + C[i][j] }, C concave, f = O(1)

  - **Parser.cpp**
    - [ ] Postfix, Infix, Prefix Converter
    - [ ] Context-Free Grammer
    - [ ] RegEx
    
  - **Misc.cpp**
    - [x] lambda functions
    - [x] STL cheatsheet
    - [x] Kahan Summation Algorithm
    - [ ] Hacks, Tweaks, Tips and Formulas
    - [ ] Write down usefull templates
