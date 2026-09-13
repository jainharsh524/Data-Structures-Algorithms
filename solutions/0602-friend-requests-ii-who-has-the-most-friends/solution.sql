SELECT 
    t1.id1 AS id,
    t1.num1 + COALESCE(t2.num2, 0) AS num
FROM (
    SELECT 
        requester_id AS id1,
        COUNT(accepter_id) AS num1
    FROM RequestAccepted
    GROUP BY requester_id
) t1
LEFT JOIN (
    SELECT 
        accepter_id AS id2,
        COUNT(requester_id) AS num2
    FROM RequestAccepted
    GROUP BY accepter_id
) t2
ON t1.id1 = t2.id2

UNION ALL

SELECT 
    t2.id2 AS id,
    COALESCE(t1.num1, 0) + t2.num2 AS num
FROM (
    SELECT 
        requester_id AS id1,
        COUNT(accepter_id) AS num1
    FROM RequestAccepted
    GROUP BY requester_id
) t1
RIGHT JOIN (
    SELECT 
        accepter_id AS id2,
        COUNT(requester_id) AS num2
    FROM RequestAccepted
    GROUP BY accepter_id
) t2
ON t1.id1 = t2.id2
WHERE t1.id1 IS NULL

ORDER BY num DESC
LIMIT 1;
