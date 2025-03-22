SELECT Students.student_id , Students.student_name, Subjects.subject_name, COUNT(Examinations.subject_name) AS attended_exams 
FROM Students 
JOIN Subjects
LEFT JOIN Examinations on Students.student_id =  Examinations.student_id
AND Subjects.subject_name = Examinations.subject_name
GROUP BY subject_name,student_id,student_name
ORDER BY student_id,subject_name;