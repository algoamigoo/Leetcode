SELECT contest_id, ROUND(100*COUNT(Register.user_id)/(SELECT COUNT(*) FROM Users),2) AS percentage
FROM Users
RIGHT JOIN Register ON Users.user_id= Register.user_id
GROUP BY contest_id
ORDER BY  percentage DESC,contest_id;
