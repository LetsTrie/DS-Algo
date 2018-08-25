An Eulerian trail (or Eulerian path) is a trail in a finite graph which visits every edge exactly once. Similarly, an Eulerian circuit or Eulerian cycle is an Eulerian trail which starts and ends on the same vertex.

Properties : 
------------
An undirected graph has an Eulerian cycle if and only if every vertex has even degree, and all of its vertices with nonzero degree belong to a single connected component.

An undirected graph can be decomposed into edge-disjoint cycles if and only if all of its vertices have even degree. So, a graph has an Eulerian cycle if and only if it can be decomposed into edge-disjoint cycles and its nonzero-degree vertices belong to a single connected component.

An undirected graph has an Eulerian trail if and only if exactly zero or two vertices have odd degree, and all of its vertices with nonzero degree belong to a single connected component.
******************************************************************************************************************************************
Check if it is an Euler Graph or Not..........

# Must Be A connected graph (Check it By doing One dfs)
# if (odd degree == 0) Graph Has Euler circuit
# if (odd degree == 2) Graph Has Euler Path
else It is Not A Euler Graph

******************************************************************************************************************************************
Euler Graph in a Directed Graph.............

A directed graph has an Eulerian cycle if and only if every vertex has equal in degree and out degree, and all of its vertices with nonzero degree belong to a single strongly connected component. Equivalently, a directed graph has an Eulerian cycle if and only if it can be decomposed into edge-disjoint directed cycles and all of its vertices with nonzero degree belong to a single strongly connected component. 
Write Kosaraju's For Finding SCC. if it is single && For all i , indeg[i] == outdegree[i] , So The Graph Has Euler Cycle. 

Application : Find if an array of strings can be chained to form a circle.
Input: arr[] = {"for", "geek", "rig", "kaf"}
Output: Yes, the given strings can be chained.
The strings can be chained as "for", "rig", "geek" 
and "kaf"

A directed graph has an Eulerian trail if and only if at most one vertex has (out-degree) − (in-degree) = 1, at most one vertex has (in-degree) − (out-degree) = 1, every other vertex has equal in-degree and out-degree, and all of its vertices with nonzero degree belong to a single connected component of the underlying undirected graph.

******************************************************************************************************************************************
