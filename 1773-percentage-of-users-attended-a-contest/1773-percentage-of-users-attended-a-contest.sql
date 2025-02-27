# Write your MySQL query statement belows

select contest_id, round(count(user_id)/(select count(*) from users)*100,2) as percentage 
from register
group by contest_id
order by 2 desc, 1 asc