SELECT class
FROM (
    SELECT class, COUNT(student) AS student_count
    FROM courses
    GROUP BY class
) subquery
WHERE student_count >= 5;
