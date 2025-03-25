WITH RankedQueue AS (
    SELECT person_name, Weight, 
           SUM(Weight) OVER (ORDER BY turn) AS running_sum
    FROM Queue
)
SELECT person_name 
FROM RankedQueue
WHERE running_sum <= 1000
ORDER BY running_sum DESC 
LIMIT 1;
