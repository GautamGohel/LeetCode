# Write your MySQL query statement below
select today.id
from Weather yesterday
cross join Weather today
WHERE DATEDIFF(today.recordDate,yesterday.recordDate)=1 AND today.temperature>yesterday.temperature;