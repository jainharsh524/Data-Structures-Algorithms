# Write your MySQL query statement below
select Employee.name, Bonus.bonus from Employee left join Bonus on Employee.empId = bonus.empID where Bonus.bonus<1000 or bonus.bonus is null
