WITH majdoor AS (
    SELECT employee_id, manager_id
    FROM Employees
    WHERE salary < 30000
),
malik AS (
    SELECT majdoor.employee_id, majdoor.manager_id
    FROM majdoor
    JOIN Employees ON Employees.employee_id = majdoor.manager_id
)
SELECT majdoor.employee_id 
FROM majdoor 
WHERE majdoor.employee_id NOT IN (
    SELECT employee_id 
    FROM malik 
    WHERE manager_id IS NOT NULL
)
AND majdoor.manager_id IS NOT NULL
ORDER BY majdoor.employee_id;