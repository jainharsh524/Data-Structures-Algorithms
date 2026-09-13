# Write your MySQL query statement below
-- select * from (
-- ) seat1
-- order by seat1.id
select s1.id, s2.student from seat s1 join seat s2 on s1.id + 1 = s2.id and s1.id % 2 = 1
union
select s1.id, s2.student from seat s1 join seat s2 on s1.id = s2.id + 1 and s1.id % 2 = 0
union 
SELECT id, student
FROM Seat
WHERE id = (
    SELECT MAX(id)
    FROM Seat
    HAVING MAX(id) % 2 = 1
) order by id
