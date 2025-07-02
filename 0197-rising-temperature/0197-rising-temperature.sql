# Write your MySQL query statement below
select today.id
from Weather yesterday
cross join Weather today
ON DATEDIFF(today.recordDate,yesterday.recordDate)=1 where today.temperature>yesterday.temperature;