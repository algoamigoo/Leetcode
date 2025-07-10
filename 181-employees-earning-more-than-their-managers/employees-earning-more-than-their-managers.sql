
SELECT e.name as Employee
FROM Employee e
LEFT JOIN Employee m
ON e.managerID = m.ID
WHERE e.salary > m.salary
AND e.managerID IS NOT NULL