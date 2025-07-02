# Write your MySQL query statement below
SELECT product_name,year,price 
from Sales 
join Product
where Sales.product_id=Product.product_id;