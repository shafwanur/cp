# Shaf's Competitive Programming Setup

I'm updating this repo after 6 years to make it more human readable. It's an accumulation of files and templates I used when I used to do competitive programming back in high school. 

You can see my competitive programming history on CodeForces on the following accounts: [shafwanur](https://codeforces.com/profile/shafwanur) and [69iq](https://codeforces.com/profile/69iq) (I was in high school, give me a break.)

The repo contains a collection of C++ (and Python) implementations for common data structures, graph algorithms, mathematical utilities, required for competitive programming. It also includes stress testing utilities, where the idea was to test the correctness of your solution by comparing it to a slower, brute force solution. 

The files where I wrote code, like code.cpp, main.cpp, code.py and test.cpp are currently empty or non-sensical. To see the code I wrote during that time you can see my [submissions](https://codeforces.com/submissions/69iq) in my competitive programming profiles.  

## Project Structure

```
.
├── code.cpp                 # General C++ source file 
├── main.cpp                 # Another General C++ entry point
├── code.py                  # General Python source file
├── debug.h                  # Debugging macros and utilities header
├── in                       # Input file 
├── out                      # Output file 
├── precompile.bat           # Windows batch script to precompile headers (I was a cringe Windows user back then, yes)
├── README.md                # Project documentation
├── src                      # Source code folder
│   ├── ds-algo              # Data structure implementations
│   │   ├── dsu.cpp                           # Disjoint Set Union (Union-Find)
│   │   ├── merge-sort-tree.cpp               # Merge Sort Tree data structure
│   │   ├── segment-tree.cpp                  # Segment Tree
│   │   ├── segment-tree-lazy-propagation.cpp # Segment Tree with Lazy Propagation
│   │   ├── sparse-table.cpp                  # Sparse Table for RMQ/static queries
│   │   └── trie.cpp                          # Trie (prefix tree)
│   ├── graph                # Graph algorithms
│   │   ├── articulation-point.cpp            # Finds articulation points
│   │   ├── bellman-ford.cpp                  # Bellman-Ford shortest path
│   │   ├── bridge.cpp                        # Finds bridges in graph
│   │   ├── dijkstra.cpp                      # Dijkstra shortest path
│   │   ├── euler-path.cpp                    # Euler path (general)
│   │   ├── euler-path-directed.cpp           # Euler path for directed graphs
│   │   ├── euler-path-undirected-graph.cpp   # Euler path for undirected graphs
│   │   ├── floyd-warshall.cpp                # Floyd-Warshall all-pairs shortest path
│   │   ├── lca.cpp                           # Lowest Common Ancestor
│   │   ├── maximum-bipartite-matching.cpp    # Bipartite matching algorithm
│   │   ├── mst.cpp                           # Minimum Spanning Tree (Prim/Kruskal)
│   │   └── scc.cpp                           # Strongly Connected Components
│   ├── math                 # Math utilities
│   │   ├── bigmod.cpp                        # Modular exponentiation
│   │   ├── bigpow.cpp                        # Fast exponentiation
│   │   ├── gcd.cpp                           # Greatest Common Divisor
│   │   ├── linear-sieve.cpp                  # Linear sieve for prime generation
│   │   └── ncr.cpp                           # Combinations (nCr)
│   ├── snippets             # Common reusable code snippets
│   │   ├── basic.cpp                         # Basic I/O template
│   │   ├── debug.cpp                         # Debugging functions
│   │   ├── main.cpp                          # Contest-ready main template
│   │   ├── ordered-set.cpp                   # Ordered set using PBDS
│   │   └── printer.h                         # Printing helpers
│   └── string               # String algorithms
│       └── hashing.cpp                       # String hashing (e.g., rolling hash)
├── stress-testing           # Stress testing utilities
│   ├── ac-check                             # Output file for accepted runs
│   ├── ac-out                               # Output file for accepted program output
│   ├── checker.cpp                          # Custom output checker
│   ├── gen.cpp                              # Test case generator
│   ├── stress.bat                           # Windows batch for stress testing
│   ├── testing.bat                          # Windows batch for running tests
│   ├── wa-check                             # Output file for wrong answer runs
│   └── wa-out                               # Output file for wrong answer output
├── test.cpp                # Test C++ program
├── test.py                 # Test Python script
```
---