SELECT COALESCE(
    (SELECT num 
     FROM MyNumbers
     GROUP BY num
     HAVING COUNT(*) < 2
     ORDER BY num DESC
     LIMIT 1), 
    NULL) AS num;
