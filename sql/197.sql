# Write your MySQL query statement below
select w2.Id
from Weather w1 inner join Weather w2
where adddate(w1.recordDate, 1) = w2.recordDate and w1.temperature < w2.temperature