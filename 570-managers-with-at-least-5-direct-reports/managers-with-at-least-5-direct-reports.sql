SELECT m.name
FROM Employee AS e
JOIN Employee AS m 
WHERE m.id=e.managerID
GROUP BY e.managerID
HAVING COUNT(e.managerID)>=5;
