# Write your MySQL query statement below
select Email
from
(select Email, count(*) as C
from Person
group by email) P
where C > 1