# Subset Sums
## Easy
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><div class="entry-content" style="user-select: auto;">
<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Given a&nbsp;list <strong style="user-select: auto;">arr</strong>&nbsp;of <strong style="user-select: auto;">N</strong> integers, print sums of all subsets in it.</span></p>

<p style="user-select: auto;">&nbsp;</p>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 1:</span></strong></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:</strong>
N = 2
arr[] = {2, 3}</span>
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Output:</strong>
0 2 3 5</span>
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Explanation:</strong>
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.</span></pre>

<p style="user-select: auto;"><strong style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">Example 2:</span></strong></p>

<pre style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:</strong>
N = 3
arr = {5, 2, 1}</span>
<span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Output:</strong>
0 1 2 3 5 6 7 8</span>
</pre>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Your Task:</strong>&nbsp;&nbsp;<br style="user-select: auto;">
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong style="user-select: auto;">subsetSums</strong>()&nbsp;which takes a list/vector and an integer <strong style="user-select: auto;">N</strong> as an input parameter and return the list/vector of all the subset sums.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Expected Time Complexity:</strong>&nbsp;O(2<sup style="user-select: auto;">N</sup>)<br style="user-select: auto;">
<strong style="user-select: auto;">Expected Auxiliary Space:</strong>&nbsp;O(2<sup style="user-select: auto;">N</sup>)</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1 &lt;= N &lt;= 15<br style="user-select: auto;">
0 &lt;= arr[i] &lt;= 10<sup style="user-select: auto;">4</sup></span></p>
</div>
 <p style="user-select: auto;"></p>
            </div>