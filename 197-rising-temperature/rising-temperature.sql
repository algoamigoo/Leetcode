SELECT w2.id
FROM Weather as w1 JOIN Weather as w2
WHERE DATEDIFF(w2.recordDate,w1.recordDate)=1 AND w2.temperature > w1.temperature; 