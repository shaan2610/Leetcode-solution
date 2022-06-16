<h2><a href="https://leetcode.com/problems/reducing-dishes/">1402. Reducing Dishes</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">A chef has collected data on the <code style="user-select: auto;">satisfaction</code> level of his <code style="user-select: auto;">n</code> dishes. Chef can cook any dish in 1 unit of time.</p>

<p style="user-select: auto;"><strong style="user-select: auto;">Like-time coefficient</strong> of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. <code style="user-select: auto;">time[i] * satisfaction[i]</code>.</p>

<p style="user-select: auto;">Return <em style="user-select: auto;">the maximum sum of <strong style="user-select: auto;">like-time coefficient</strong> that the chef can obtain after dishes preparation</em>.</p>

<p style="user-select: auto;">Dishes can be prepared in <strong style="user-select: auto;">any </strong>order and the chef can discard some dishes to get this maximum value.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> satisfaction = [-1,-8,0,5,-9]
<strong style="user-select: auto;">Output:</strong> 14
<strong style="user-select: auto;">Explanation:</strong> After Removing the second and last dish, the maximum total <strong style="user-select: auto;">like-time coefficient</strong> will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> satisfaction = [4,3,2]
<strong style="user-select: auto;">Output:</strong> 20
<strong style="user-select: auto;">Explanation:</strong> Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> satisfaction = [-1,-4,-5]
<strong style="user-select: auto;">Output:</strong> 0
<strong style="user-select: auto;">Explanation:</strong> People do not like the dishes. No dish is prepared.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">n == satisfaction.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 500</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">-1000 &lt;= satisfaction[i] &lt;= 1000</code></li>
</ul>
</div>