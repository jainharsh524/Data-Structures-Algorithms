# Write your MySQL query statement below
select Visits.customer_id, Count(Visits.customer_id) as count_no_trans from Visits left join Transactions on Visits.visit_id = transactions.visit_id where transactions.transaction_id is null group by Visits.customer_id;
