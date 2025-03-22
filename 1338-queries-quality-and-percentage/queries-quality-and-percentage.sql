SELECT 
    query_name, 
    ROUND(AVG(rating / position), 2) AS quality, 
    ROUND(100 * (SELECT COUNT(*) FROM Queries Q WHERE Q.query_name = Queries.query_name AND rating < 3) / COUNT(*), 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;
