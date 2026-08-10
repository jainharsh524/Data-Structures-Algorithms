Select E.name
from Employee E JOIN Employee E1
ON E.id = E1.managerId
group by E.name, E.id
having count(*) >= 5;
