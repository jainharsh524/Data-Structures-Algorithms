SELECT
    students.student_id,
    students.student_name,
    subjects.subject_name,
    COUNT(examinations.student_id) AS attended_exams
FROM students
CROSS JOIN subjects
LEFT JOIN examinations
    ON examinations.student_id = students.student_id
    AND examinations.subject_name = subjects.subject_name
GROUP BY
    students.student_id,
    students.student_name,
    subjects.subject_name
ORDER BY
    students.student_id,
    subjects.subject_name;
