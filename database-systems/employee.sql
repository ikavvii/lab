CREATE TABLE Employee (
EmpID NUMBER(4) PRIMARY KEY,
EmpName VARCHAR2(50),
Job VARCHAR2(30),
ManagerID NUMBER(4),
HireDate DATE,
Salary NUMBER(8,2),
Commission NUMBER(6,2),
DeptID NUMBER(2)
);

desc employee;


INSERT INTO Employee VALUES (1001, 'John Smith', 'Manager', NULL, DATE '2015-01-10', 80000, NULL, 10);
INSERT INTO Employee VALUES (1002, 'Alice Brown', 'Analyst', 1001, DATE '2017-03-15', 60000, NULL, 20);
INSERT INTO Employee VALUES (1003, 'Robert King', 'Clerk', 1002, DATE '2019-07-01', 30000, NULL, 20);
INSERT INTO Employee VALUES (1004, 'Maria Garcia', 'Salesman', 1001, DATE '2018-05-21', 35000, 2000, 30);
INSERT INTO Employee VALUES (1005, 'David Lee', 'Salesman', 1001, DATE '2020-06-11', 32000, 1500, 30);
INSERT INTO Employee VALUES (1006, 'James Miller', 'Analyst', 1001, DATE '2016-11-30', 65000, NULL, 20);
INSERT INTO Employee VALUES (1007, 'Linda Johnson', 'Clerk', 1006, DATE '2021-01-05', 28000, NULL, 20);
INSERT INTO Employee VALUES (1008, 'Michael Scott', 'Manager', NULL, DATE '2014-09-25', 90000, NULL, 40);
INSERT INTO Employee VALUES (1009, 'Pam Beesly', 'Clerk', 1008, DATE '2022-04-10', 27000, NULL, 40);
INSERT INTO Employee VALUES (1010, 'Stanley Hudson', 'Salesman', 1008, DATE '2015-12-12', 40000, 2500, 30);


-- A Basic select and filtering

-- 1 Display all records from the Employee table.

select * from employee;

--2 Show employee names and job titles only.

select empname, job from employee;

--3 List all employees who are Salesmen.

select * from employee where job='Salesman';

--4 Find employees hired after 01-Jan-2018.
select * from employee where hiredate>='01-01-2018';

--5 Retrieve employees whose salary is greater than 50,000.
select * from employee where salary > 50000;

--6 Display employees with commission not null.
select * from employee where commission is not null;

--7 Find employees in Department 20.
select * from employee where deptid=20;

--8 Show employees whose name starts with ‘M’.
select * from employee where empname like 'M%';

--9 Display employees hired in 2020.
select * from employee where hiredate like '%20';

--10 Retrieve employees where job is either Analyst or Clerk.
select * from employee where job='Analyst' or job='Clerk';

--11 Display the name and salary of employees earning between 30,000 and 60,000.
select empname, salary from employee where salary between 30000 and 60000;

--12 Show details of employees whose names contain the letter ‘a’ (case-insensitive).
select * from employee where lower(empname) like '%a%';

--13 Find employees who do not belong to department 30.
select * from employee where deptid!=30;

--14 Retrieve employees whose commission is greater than 1500.
select * from employee where commission>1500;

--15 Display employees whose job is not Clerk and not Analyst.
select * from employee where job!='Clerk' and job!='Analyst';

--16 Display all employees who belong to department 10 or 40.
select * from employee where deptid=10 or deptid=40;

--17 Find employees whose salary is not between 25,000 and 50,000.
select * from employee where salary not between 25000 and 50000;

--18 Show employees whose name ends with ‘n’.
select * from employee where empname like '%n';

--19 List employees hired before 2018.
select * from employee where hiredate<'01-01-18';

--20 Find employees who joined after their manager (use HireDate comparison).
select * from employee where 