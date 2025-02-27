# Write your MySQL query statement below
select customer_id, count(ifnull(transaction_id,1)) as count_no_trans  
from visits V left join transactions T on V.visit_id=T.visit_id
where transaction_id is null 
group by customer_id