# Write your MySQL query statement below
SELECT P.PROJECT_ID , ROUND(AVG(E.EXPERIENCE_YEARS),2) AS average_years   
FROM PROJECT P, EMPLOYEE E WHERE E.EMPLOYEE_ID = P.EMPLOYEE_ID 
GROUP BY P.PROJECT_ID