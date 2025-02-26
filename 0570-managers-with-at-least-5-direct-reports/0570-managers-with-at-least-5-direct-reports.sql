# Write your MySQL query statement below


SELECT  MGR.name
FROM EMPLOYEE MGR INNER JOIN EMPLOYEE EMP ON EMP.MANAGERID = MGR.ID 
GROUP BY MGR.ID
HAVING COUNT(EMP.ID)>=5