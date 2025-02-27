# Write your MySQL query statement below

select mgr.employee_id  
from Employees mgr left join Employees emp on   mgr.manager_id = emp.employee_id 
where mgr.manager_id is not null and emp.employee_id is null and mgr.salary <30000
order by employee_id