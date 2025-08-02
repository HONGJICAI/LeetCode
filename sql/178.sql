-- Rank the scores in descending order
-- and assign a rank to each score.
-- If two scores are the same, they should have the same rank.
-- The next rank should be the next consecutive integer.
-- For example, if the scores are 100, 90, 90, and 80,
-- the ranks should be 1, 2, 2, and 3.
/* Write your T-SQL query statement below */

select Score, DENSE_RANK() over(order by Score desc) as Rank
from Scores