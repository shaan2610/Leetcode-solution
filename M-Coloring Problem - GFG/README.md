# M-Coloring Problem
## Medium 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given an undirected graph and an integer&nbsp;<strong style="user-select: auto;">M</strong>. The task is to determine if the graph can be colored with at most M&nbsp;colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1&nbsp;if it is possible to colour vertices and 0&nbsp;otherwise.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
<strong style="user-select: auto;">Output: </strong>1<strong style="user-select: auto;">
Explanation: </strong>It is possible to colour the
given graph using 3 colours.</span>
</pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></span></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:
</strong>N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
<strong style="user-select: auto;">Output: </strong>0</span></pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong><br style="user-select: auto;">
Your task is to complete the function&nbsp;<strong style="user-select: auto;">graphColoring()</strong>&nbsp;which takes the 2d-array graph[], the number of colours and the number of nodes&nbsp;as inputs and returns <strong style="user-select: auto;">true</strong>&nbsp;if answer exists otherwise <strong style="user-select: auto;">false</strong>. 1 is printed if the returned value is&nbsp;<strong style="user-select: auto;">true,&nbsp;</strong>0 otherwise. The printing is done by the driver's code.<br style="user-select: auto;">
<strong style="user-select: auto;">Note</strong>: In Example there are Edges not the graph.Graph will be like, if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0.&nbsp;In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.Function will be contain 2-D graph not the edges.</span><br style="user-select: auto;">
<br style="user-select: auto;">
<strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Expected Time Complexity:</span></strong><span style="font-size: 18px; user-select: auto;">&nbsp;O(M</span><sup style="user-select: auto;">N</sup><span style="font-size: 18px; user-select: auto;">).</span><br style="user-select: auto;">
<strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Expected Auxiliary&nbsp;</span></strong><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Space:</strong>&nbsp;O(N).</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 ≤ N ≤ 20<br style="user-select: auto;">
1 ≤ E ≤ (N*(N-1))/2<br style="user-select: auto;">
1 ≤ M ≤ N</span></p>
 <p style="user-select: auto;"></p>
            </div>