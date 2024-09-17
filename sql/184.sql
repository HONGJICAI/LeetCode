# Write your MySQL query statement below
select dname as Department, e.name as Employee, e.salary
from Employee e
inner join
(select d.name as dname, d.Id as did, max(e.Salary) as MaxSalary
from Employee e inner join Department d
on departmentId = d.id
group by d.name, d.id) DepartmentMaxSalary
on e.departmentId = did and e.salary = MaxSalary