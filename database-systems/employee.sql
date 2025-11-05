drop table employee;

-- Table EMPLOYEE dropped.

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
--Table EMPLOYEE created.


desc employee;

--
--Name       Null?    Type         
------------ -------- ------------ 
--EMPID      NOT NULL NUMBER(4)    
--EMPNAME             VARCHAR2(50) 
--JOB                 VARCHAR2(30) 
--MANAGERID           NUMBER(4)    
--HIREDATE            DATE         
--SALARY              NUMBER(8,2)  
--COMMISSION          NUMBER(6,2)  
--DEPTID              NUMBER(2)    


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
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--
--
--1 row inserted.
--



-- A Basic select and filtering

-- 1 Display all records from the Employee table.

select * from employee;

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30
--
--10 rows selected. 

--2 Show employee names and job titles only.

select empname, job from employee;

--
--EMPNAME                                            JOB                           
---------------------------------------------------- ------------------------------
--John Smith                                         Manager                       
--Alice Brown                                        Analyst                       
--Robert King                                        Clerk                         
--Maria Garcia                                       Salesman                      
--David Lee                                          Salesman                      
--James Miller                                       Analyst                       
--Linda Johnson                                      Clerk                         
--Michael Scott                                      Manager                       
--Pam Beesly                                         Clerk                         
--Stanley Hudson                                     Salesman                      
--
--10 rows selected. 

--3 List all employees who are Salesmen.

select * from employee where job='Salesman';


--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30


--4 Find employees hired after 01-Jan-2018.
select * from employee where hiredate>='01-01-2018';
--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40


--5 Retrieve employees whose salary is greater than 50,000.
select * from employee where salary > 50000;

--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40


--6 Display employees with commission not null.
select * from employee where commission is not null;

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30


--7 Find employees in Department 20.
select * from employee where deptid=20;

--
--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--


--8 Show employees whose name starts with �M�.
select * from employee where empname like 'M%';


--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40


--9 Display employees hired in 2020.
select * from employee where hiredate like '%20';

--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30

--10 Retrieve employees where job is either Analyst or Clerk.
select * from employee where job='Analyst' or job='Clerk';

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40
--


--11 Display the name and salary of employees earning between 30,000 and 60,000.
select empname, salary from employee where salary between 30000 and 60000;

--
--
--EMPNAME                                                SALARY
---------------------------------------------------- ----------
--Alice Brown                                             60000
--Robert King                                             30000
--Maria Garcia                                            35000
--David Lee                                               32000
--Stanley Hudson                                          40000
--


--12 Show details of employees whose names contain the letter �a� (case-insensitive).
select * from employee where lower(empname) like '%a%';

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30
--
--8 rows selected. 


--13 Find employees who do not belong to department 30.
select * from employee where deptid!=30;
--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40
--
--7 rows selected. 

--14 Retrieve employees whose commission is greater than 1500.
select * from employee where commission>1500;

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30
--


--15 Display employees whose job is not Clerk and not Analyst.
select * from employee where job!='Clerk' and job!='Analyst';

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30


--16 Display all employees who belong to department 10 or 40.
select * from employee where deptid=10 or deptid=40;

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40


--17 Find employees whose salary is not between 25,000 and 50,000.
select * from employee where salary not between 25000 and 50000;


--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--


--18 Show employees whose name ends with �n�.
select * from employee where empname like '%n';

--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30

--19 List employees hired before 2018.
select * from employee where hiredate<'01-01-18';

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30


--20 Find employees who joined after their manager (use HireDate comparison).
select e.* 
from employee e
join employee m on e.managerid = m.empid
where e.hiredate > m.hiredate;


--21 Display employees with no commission.
select * from employee where commission is NULL;

--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40

--7 rows selected. 

--22 Show employees whose commission is at least 10% of their salary.
select * from employee where commission >= (salary/10);

-- no rows selected

-- 23 List all employees whose name has exactly 5 characters.

select * from employee where empname like '_____';

-- 24 Display employees where salary is a multiple of 5,000.

select * from employee where MOD(salary, 5000) = 0;
--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30
--
--7 rows selected. 
--

-- 25 Show employees whose job title contains the word �Manager�.
select * from employee where job like '%Manager%';


--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--

-- B. Sorting &amp; Expressions 


-- 26 List employees in ascending order of salary.

select * from employee order by salary;

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1009 Pam Beesly                                         Clerk                                1008 10-04-22      27000                    40
--      1007 Linda Johnson                                      Clerk                                1006 05-01-21      28000                    20
--      1003 Robert King                                        Clerk                                1002 01-07-19      30000                    20
--      1005 David Lee                                          Salesman                             1001 11-06-20      32000       1500         30
--      1004 Maria Garcia                                       Salesman                             1001 21-05-18      35000       2000         30
--      1010 Stanley Hudson                                     Salesman                             1008 12-12-15      40000       2500         30
--      1002 Alice Brown                                        Analyst                              1001 15-03-17      60000                    20
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--
--10 rows selected. 
--

-- 27 Display top 3 highest paid employees.
select * from (select * from employee order by salary desc) where rownum <= 3;

--
--     EMPID EMPNAME                                            JOB                             MANAGERID HIREDATE     SALARY COMMISSION     DEPTID
------------ -------------------------------------------------- ------------------------------ ---------- -------- ---------- ---------- ----------
--      1008 Michael Scott                                      Manager                                   25-09-14      90000                    40
--      1001 John Smith                                         Manager                                   10-01-15      80000                    10
--      1006 James Miller                                       Analyst                              1001 30-11-16      65000                    20
--

-- 28 Show employees sorted by department and then by name.

select * from employee order by deptid, empname;

-- "EMPID"                       "EMPNAME"                     "JOB"                         "MANAGERID"                   "HIREDATE"                    "SALARY"                      "COMMISSION"                  "DEPTID"                      
-- "1001"                        "John Smith"                  "Manager"                     ""                            "10/01/15"                    "80000"                       ""                            "10"                          
-- "1002"                        "Alice Brown"                 "Analyst"                     "1001"                        "15/03/17"                    "60000"                       ""                            "20"                          
-- "1006"                        "James Miller"                "Analyst"                     "1001"                        "30/11/16"                    "65000"                       ""                            "20"                          
-- "1007"                        "Linda Johnson"               "Clerk"                       "1006"                        "05/01/21"                    "28000"                       ""                            "20"                          
-- "1003"                        "Robert King"                 "Clerk"                       "1002"                        "01/07/19"                    "30000"                       ""                            "20"                          
-- "1005"                        "David Lee"                   "Salesman"                    "1001"                        "11/06/20"                    "32000"                       "1500"                        "30"                          
-- "1004"                        "Maria Garcia"                "Salesman"                    "1001"                        "21/05/18"                    "35000"                       "2000"                        "30"                          
-- "1010"                        "Stanley Hudson"              "Salesman"                    "1008"                        "12/12/15"                    "40000"                       "2500"                        "30"                          
-- "1008"                        "Michael Scott"               "Manager"                     ""                            "25/09/14"                    "90000"                       ""                            "40"                          
-- "1009"                        "Pam Beesly"                  "Clerk"                       "1008"                        "10/04/22"                    "27000"                       ""                            "40"                          


-- 29 Display employee name, annual salary (Salary*12).
select empname, salary*12 from employee; 

-- "EMPNAME"                     "SALARY*12"                   
-- "John Smith"                  "960000"                      
-- "Alice Brown"                 "720000"                      
-- "Robert King"                 "360000"                      
-- "Maria Garcia"                "420000"                      
-- "David Lee"                   "384000"                      
-- "James Miller"                "780000"                      
-- "Linda Johnson"               "336000"                      
-- "Michael Scott"               "1080000"                     
-- "Pam Beesly"                  "324000"                      
-- "Stanley Hudson"              "480000"                      


-- 30 Display employee name, total earning (Salary + NVL(Commission,0)).
select empname, salary + NVL(commission, 0) as total_earnings from EMPLOYEE;


-- EMPNAME                                            TOTAL_EARNINGS
-- -------------------------------------------------- --------------
-- John Smith                                                  80000
-- Alice Brown                                                 60000
-- Robert King                                                 30000
-- Maria Garcia                                                37000
-- David Lee                                                   33500
-- James Miller                                                65000
-- Linda Johnson                                               28000
-- Michael Scott                                               90000
-- Pam Beesly                                                  27000
-- Stanley Hudson                                              42500

-- 10 rows selected. 


-- 31 Show employees sorted by hire date in descending order.
select empname, hiredate from EMPLOYEE order by HIREDATE desc;


-- EMPNAME                                            HIREDATE
-- -------------------------------------------------- --------
-- Pam Beesly                                         10/04/22
-- Linda Johnson                                      05/01/21
-- David Lee                                          11/06/20
-- Robert King                                        01/07/19
-- Maria Garcia                                       21/05/18
-- Alice Brown                                        15/03/17
-- James Miller                                       30/11/16
-- Stanley Hudson                                     12/12/15
-- John Smith                                         10/01/15
-- Michael Scott                                      25/09/14

-- 10 rows selected. 

-- 32. Display employees sorted first by Job, then by Salary (descending).
SELECT EMPNAME, JOB, SALARY FROM employee order BY JOB, SALARY desc;

-- 33. Find the sum of salaries for department 30.
SELECT EMPNAME, DEPTID, SALARY FROM EMPLOYEE WHERE DEPTID=30;
SELECT SUM(SALARY) FROM EMPLOYEE WHERE DEPTID=30;

-- 34. Display the highest commission paid to any employee.
SELECT MAX(COMMISSION) FROM EMPLOYEE;

-- 35. Find the department with the maximum number of employees (using GROUP BY + ORDER BY).
 

-- 84 Find employees whose salary is greater than their manager’s salary.

-- updates a employee to have salary greater than his manager
UPDATE EMPLOYEE SET SALARY = 90000 WHERE EMPID=1002;
SELECT * FROM EMPLOYEE E WHERE SALARY > (SELECT SALARY FROM EMPLOYEE WHERE EMPID = E.MANAGERID);


commit;

desc EMPLOYEE;

-- selects the max salaried employee
-- single value sub query
select EMPNAME, SALARY from EMPLOYEE where salary = (select MAX(salary) from EMPLOYEE);

-- multi value sub query 


-- multi column sub query
select EMPID, EMPNAME, DEPTID, SALARY from EMPLOYEE where (deptid, salary) in (select deptid,  MAX(SALARY) from EMPLOYEE group by DEPTID);

-- not working 
select EMPID, EMPNAME, DEPTID, SALARY FROM EMPLOYEE e JOIN (SELECT DEPTID, MAX(SALARY) FROM EMPLOYEE GROUP BY DEPTID) f on f.deptid = e.deptid;

-- corelated sub query 
select empid, empname, deptid, salary from employee e where e.salary = (select max(salary) from employee where DEPTID = e.DEPTID);