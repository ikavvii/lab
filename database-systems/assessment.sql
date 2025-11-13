-- (UniversityDB)

-- Departments Table
drop table faculty;
drop table courses;
drop table students;
drop table enrollments;
drop table departments;

create table departments (
   department_id   number primary key,
   department_name varchar2(50),
   hod             varchar2(50)
);

-- Students Table
create table students (
   student_id    number primary key,
   student_name  varchar2(50),
   department_id number
      references departments ( department_id ),
   year_of_study number(1),
   cgpa          decimal(3,2)
);


-- Courses Table
create table courses (
   course_id     char(5) primary key,
   course_name   varchar2(50),
   department_id number
      references departments ( department_id ),
   credits       number
);

-- Enrollments Table
create table enrollments (
   enroll_id  number primary key,
   student_id number
      references students ( student_id ),
   course_id  char(5)
      references courses ( course_id ),
   grade      char(2)
);

-- Faculty Table
create table faculty (
   faculty_id    number primary key,
   faculty_name  varchar2(50),
   department_id number
      references departments ( department_id ),
   designation   varchar2(30),
   salary        decimal(10,2)
);

-- Insert sample data for Departments
insert into departments (
   department_id,
   department_name,
   hod
) values ( 1,
           'Computer Science',
           'Dr. Nila' );
insert into departments (
   department_id,
   department_name,
   hod
) values ( 2,
           'Electronics',
           'Dr. Arun' );
insert into departments (
   department_id,
   department_name,
   hod
) values ( 3,
           'Mechanical',
           'Dr. Ravi' );
insert into departments (
   department_id,
   department_name,
   hod
) values ( 4,
           'Civil',
           'Dr. Sneha' );

-- Insert sample data for Students
insert into students (
   student_id,
   student_name,
   department_id,
   year_of_study,
   cgpa
) values ( 101,
           'Asha',
           1,
           2,
           8.7 );
insert into students (
   student_id,
   student_name,
   department_id,
   year_of_study,
   cgpa
) values ( 102,
           'Bala',
           1,
           3,
           9.1 );
insert into students (
   student_id,
   student_name,
   department_id,
   year_of_study,
   cgpa
) values ( 103,
           'Charan',
           2,
           1,
           7.8 );
insert into students (
   student_id,
   student_name,
   department_id,
   year_of_study,
   cgpa
) values ( 104,
           'Deepa',
           3,
           4,
           8.5 );
insert into students (
   student_id,
   student_name,
   department_id,
   year_of_study,
   cgpa
) values ( 105,
           'Esha',
           1,
           2,
           8.2 );
insert into students (
   student_id,
   student_name,
   department_id,
   year_of_study,
   cgpa
) values ( 106,
           'Farhan',
           4,
           3,
           7.6 );

-- Insert sample data for Courses
insert into courses (
   course_id,
   course_name,
   department_id,
   credits
) values ( 'C101',
           'DBMS',
           1,
           3 );
insert into courses (
   course_id,
   course_name,
   department_id,
   credits
) values ( 'C102',
           'Data Structures',
           1,
           4 );
insert into courses (
   course_id,
   course_name,
   department_id,
   credits
) values ( 'C103',
           'Microprocessors',
           2,
           3 );
insert into courses (
   course_id,
   course_name,
   department_id,
   credits
) values ( 'C104',
           'Thermodynamics',
           3,
           4 );
insert into courses (
   course_id,
   course_name,
   department_id,
   credits
) values ( 'C105',
           'Fluid Mechanics',
           4,
           3 );

-- Insert sample data for Enrollments
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 1,
           101,
           'C101',
           'A' );
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 2,
           101,
           'C102',
           'B' );
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 3,
           102,
           'C101',
           'A' );
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 4,
           103,
           'C103',
           'C' );
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 5,
           104,
           'C104',
           'A' );
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 6,
           105,
           'C101',
           'B' );
insert into enrollments (
   enroll_id,
   student_id,
   course_id,
   grade
) values ( 7,
           106,
           'C105',
           'B' );

-- Insert sample data for Faculty
insert into faculty (
   faculty_id,
   faculty_name,
   department_id,
   designation,
   salary
) values ( 201,
           'Dr. Meena',
           1,
           'Professor',
           120000 );
insert into faculty (
   faculty_id,
   faculty_name,
   department_id,
   designation,
   salary
) values ( 202,
           'Mr. Kumar',
           1,
           'Lecturer',
           80000 );
insert into faculty (
   faculty_id,
   faculty_name,
   department_id,
   designation,
   salary
) values ( 203,
           'Dr. Priya',
           2,
           'Professor',
           110000 );
insert into faculty (
   faculty_id,
   faculty_name,
   department_id,
   designation,
   salary
) values ( 204,
           'Mr. Suresh',
           3,
           'Assistant Prof',
           95000 );
insert into faculty (
   faculty_id,
   faculty_name,
   department_id,
   designation,
   salary
) values ( 205,
           'Ms. Latha',
           4,
           'Lecturer',
           70000 );

commit;

-- 1. List the names of students enrolled in courses offered by the 'Computer Science' department.

select *
  from students;

select s.student_name
  from students s
  join enrollments e
on s.student_id = e.student_id
  join courses c
on e.course_id = c.course_id
  join departments d
on c.department_id = d.department_id
 where d.department_name = 'Computer Science';

-- 2. Find students who have scored grade 'A' in any course belonging to the same department as 'Bala'.
select distinct s.student_name
  from students s
  join enrollments e
on s.student_id = e.student_id
  join courses c
on e.course_id = c.course_id
 where e.grade = 'A'
   and c.department_id = (
   select department_id
     from students
    where student_name = 'Bala'
);

-- 3. Display department names where the average CGPA of students is greater than the overall university average CGPA.
select d.department_name
  from students s
  join departments d
on s.department_id = d.department_id
 group by d.department_name
having avg(s.cgpa) > (
   select avg(cgpa)
     from students
);

-- 4. List the courses with maximum credits in each department.
select c.course_name,
       c.department_id,
       c.credits
  from courses c
 where c.credits = (
   select max(credits)
     from courses
    where department_id = c.department_id
);

-- 5. Find students whose CGPA is higher than the CGPA of all students in the Civil department.
select student_name
  from students
 where cgpa > all (
   select cgpa
     from students
    where department_id = (
      select department_id
        from departments
       where department_name = 'Civil'
   )
);

-- 6. Show department names that offer more courses than the Computer Science department.
select d.department_name
  from departments d
 where (
   select count(*)
     from courses
    where department_id = d.department_id
) > (
   select count(*)
     from courses
    where department_id = (
      select department_id
        from departments
       where department_name = 'Computer Science'
   )
);

-- 7. List the faculty members whose salary is greater than the average salary of all professors.
select faculty_name
  from faculty
 where salary > (
   select avg(salary)
     from faculty
    where designation = 'Professor'
);

-- 8. Retrieve student names who have enrolled in all courses of their department.
select s.student_name
  from students s
 where not exists (
   select c.course_id
     from courses c
    where c.department_id = s.department_id
      and not exists (
      select 1
        from enrollments e
       where e.student_id = s.student_id
         and e.course_id = c.course_id
   )
);


-- 9. Display courses where average grade (A > B > C) is higher than the average grade of DBMS course.

select sub.course_name
  from (
   select c.course_id,
          c.course_name,
          avg(
             case e.grade
                when 'A' then
                   3
                when 'B' then
                   2
                when 'C' then
                   1
                else
                   0
             end
          ) as avg_grade
     from enrollments e
     join courses c
   on e.course_id = c.course_id
    group by c.course_id,
             c.course_name
) sub
 where sub.avg_grade > (
   select avg(
      case e.grade
         when 'A' then
            3
         when 'B' then
            2
         when 'C' then
            1
         else
            0
      end
   )
     from enrollments e
    where e.course_id = 'C101'
);

-- 10. Find students who have not enrolled in any course yet.
select student_name
  from students s
 where not exists (
   select 1
     from enrollments e
    where e.student_id = s.student_id
);

-- 11. Get departments where no faculty member earns less than ₹80,000.
select department_name
  from departments d
 where not exists (
   select 1
     from faculty f
    where f.department_id = d.department_id
      and f.salary < 80000
);

-- 12. Retrieve the name of HODs of departments where average student CGPA exceeds 8.
select hod
  from departments d
 where (
   select avg(s.cgpa)
     from students s
    where s.department_id = d.department_id
) > 8;

-- 13. List students whose CGPA is greater than or equal to the department topper's CGPA of their department.
select s.student_name
  from students s
 where s.cgpa >= (
   select max(s2.cgpa)
     from students s2
    where s2.department_id = s.department_id
);

-- 14. Display department names having students enrolled in more than one course.
select distinct d.department_name
  from departments d
  join students s
on d.department_id = s.department_id
  join enrollments e
on s.student_id = e.student_id
 group by d.department_name,
          s.student_id
having count(e.course_id) > 1;

-- 15. List courses whose credits are less than the average credits of all courses.
select course_name
  from courses
 where credits < (
   select avg(credits)
     from courses
);

-- 16. Find students who have enrolled in a course also taken by 'Asha'.
select distinct s.student_name
  from students s
  join enrollments e
on s.student_id = e.student_id
 where e.course_id in (
   select course_id
     from enrollments
    where student_id = (
      select student_id
        from students
       where student_name = 'Asha'
   )
)
   and s.student_name <> 'Asha';

-- 17. Retrieve faculty members teaching in departments with at least one student having CGPA > 9.
select f.faculty_name
  from faculty f
 where exists (
   select 1
     from students s
    where s.department_id = f.department_id
      and s.cgpa > 9
);

-- 18. Show students from departments where average faculty salary is greater than ₹90,000.
select s.student_name
  from students s
 where (
   select avg(salary)
     from faculty f
    where f.department_id = s.department_id
) > 90000;

-- 19. List department names where the number of students > average number of students per department.
select department_name
  from departments d
 where (
   select count(*)
     from students s
    where s.department_id = d.department_id
) > (
   select avg(cnt)
     from (
      select count(*) cnt
        from students
       group by department_id
   )
);

-- 20. Display courses that belong to the department of the highest paid faculty.
select c.course_name
  from courses c
 where c.department_id = (
   select department_id
     from faculty
    where salary = (
      select max(salary)
        from faculty
   )
);

-- 21. Find students who have the same CGPA as someone from another department.
select distinct s1.student_name
  from students s1
 where exists (
   select 1
     from students s2
    where s1.cgpa = s2.cgpa
      and s1.department_id <> s2.department_id
);

-- 22. List faculty whose salary equals the minimum salary in their department.
select faculty_name
  from faculty f
 where salary = (
   select min(salary)
     from faculty
    where department_id = f.department_id
);

-- 23. Display departments with no courses below 3 credits.
select department_name
  from departments d
 where not exists (
   select 1
     from courses c
    where c.department_id = d.department_id
      and c.credits < 3
);

-- 24. Retrieve students who have the highest CGPA in their year of study.
select student_name
  from students s
 where s.cgpa = (
   select max(s2.cgpa)
     from students s2
    where s2.year_of_study = s.year_of_study
);

-- 25. Find departments where no student has a grade 'C' in any course.
select d.department_name
  from departments d
 where not exists (
   select 1
     from students s
     join enrollments e
   on s.student_id = e.student_id
    where s.department_id = d.department_id
      and e.grade = 'C'
);

-- Correlated Subqueries


-- 1. Display students whose CGPA is above the average CGPA of their own department.
select student_name,
       cgpa
  from students s
 where cgpa > (
   select avg(cgpa)
     from students
    where department_id = s.department_id
);

-- 2. Show faculty who earn more than the average salary in their department.
select faculty_name,
       salary
  from faculty f
 where salary > (
   select avg(salary)
     from faculty
    where department_id = f.department_id
);

-- 3. List departments that have more students than any other department.
select department_name
  from departments d
 where (
   select count(*)
     from students s
    where s.department_id = d.department_id
) > all (
   select count(*)
     from students s2
    group by s2.department_id
);

-- 4. Find students who have scored grade 'A' in at least one course.
select distinct s.student_name
  from students s
  join enrollments e
on s.student_id = e.student_id
 where e.grade = 'A';

-- 5. Display student names and CGPA where CGPA is greater than the CGPA of another student in the same year.
select s.student_name,
       s.cgpa
  from students s
 where exists (
   select 1
     from students s2
    where s2.year_of_study = s.year_of_study
      and s2.student_id <> s.student_id
      and s2.cgpa < s.cgpa
);

-- 6. Find courses with credits greater than the department's average credits.
select c.course_name,
       c.credits
  from courses c
 where c.credits > (
   select avg(credits)
     from courses
    where department_id = c.department_id
);

-- 7. List students enrolled in fewer courses than the average number of courses per student.
select s.student_name
  from students s
 where (
   select count(*)
     from enrollments e
    where e.student_id = s.student_id
) < (
   select avg(enroll_count)
     from (
      select count(*) as enroll_count
        from enrollments
       group by student_id
   )
);

-- 8. Show departments where every student's CGPA is above 8.
select department_name
  from departments d
 where not exists (
   select 1
     from students s
    where s.department_id = d.department_id
      and s.cgpa <= 8
);

-- 9. Retrieve faculty whose salary is less than the maximum salary in their department.
select faculty_name,
       salary
  from faculty f
 where salary < (
   select max(salary)
     from faculty
    where department_id = f.department_id
);

-- 10. Display students who have at least one course enrollment with grade 'A'.
select distinct s.student_name
  from students s
 where exists (
   select 1
     from enrollments e
    where e.student_id = s.student_id
      and e.grade = 'A'
);

-- 11. Find departments where at least one student has CGPA < 7.5.
select department_name
  from departments d
 where exists (
   select 1
     from students s
    where s.department_id = d.department_id
      and s.cgpa < 7.5
);

-- 12. Show students who are toppers of their department (highest CGPA).
select s.student_name,
       s.cgpa
  from students s
 where s.cgpa = (
   select max(s2.cgpa)
     from students s2
    where s2.department_id = s.department_id
);

-- 13. List faculty whose salary is within 10% of the department's average salary.
select faculty_name,
       salary
  from faculty f
 where salary between (
   select avg(salary) * 0.9
     from faculty
    where department_id = f.department_id
) and (
   select avg(salary) * 1.1
     from faculty
    where department_id = f.department_id
);

-- 14. Find courses where the number of enrollments > average enrollments of other courses.

with enrollments_per_course as (
   select course_id,
          count(*) as enroll_count
     from enrollments
    group by course_id
)
select c.course_name
  from courses c
  join enrollments_per_course epc
on c.course_id = epc.course_id
 where epc.enroll_count > (
   select avg(enroll_count)
     from enrollments_per_course
    where course_id <> c.course_id
);

-- 15. Retrieve students who have not taken any course offered by their own department.
select s.student_name
  from students s
 where not exists (
   select 1
     from enrollments e
     join courses c
   on e.course_id = c.course_id
    where e.student_id = s.student_id
      and c.department_id = s.department_id
);

-- 16. List departments where no student has failed (grade C or lower).
select department_name
  from departments d
 where not exists (
   select 1
     from students s
     join enrollments e
   on s.student_id = e.student_id
    where s.department_id = d.department_id
      and e.grade in ( 'C' )
);

-- 17. Find students whose CGPA equals the maximum CGPA in their year.
select student_name,
       cgpa
  from students s
 where cgpa = (
   select max(s2.cgpa)
     from students s2
    where s2.year_of_study = s.year_of_study
);

-- 18. Display faculty who earn more than any lecturer in the same department.
select f.faculty_name,
       f.salary
  from faculty f
 where f.salary > (
   select max(salary)
     from faculty
    where department_id = f.department_id
      and designation = 'Lecturer'
);

-- 19. Retrieve departments whose number of enrollments is greater than average enrollments per student.
select d.department_name
  from departments d
 where (
   select count(*)
     from enrollments e
     join students s
   on e.student_id = s.student_id
    where s.department_id = d.department_id
) > (
   select avg(enroll_count)
     from (
      select count(*) as enroll_count
        from enrollments
       group by student_id
   )
);

-- 20. Show departments where average faculty salary is higher than the average faculty salary of all departments.
select department_name
  from departments d
 where (
   select avg(salary)
     from faculty f
    where f.department_id = d.department_id
) > (
   select avg(salary)
     from faculty
);

-- 21. Find students who have taken a course also taken by someone in another department.
select distinct s1.student_name
  from students s1
 where exists (
   select 1
     from enrollments e1
    where e1.student_id = s1.student_id
      and exists (
      select 1
        from enrollments e2
        join students s2
      on e2.student_id = s2.student_id
       where e2.course_id = e1.course_id
         and s2.department_id <> s1.department_id
   )
);

-- 22. List faculty whose salary is below the department's minimum professor salary.
select faculty_name,
       salary
  from faculty f
 where salary < (
   select min(salary)
     from faculty
    where department_id = f.department_id
      and designation = 'Professor'
);

-- 23. Show students who have the same CGPA as another student in their department.
select distinct s1.student_name
  from students s1
 where exists (
   select 1
     from students s2
    where s2.department_id = s1.department_id
      and s2.student_id <> s1.student_id
      and s2.cgpa = s1.cgpa
);

-- 24. Retrieve students whose enrollments earn more than ₹75,000 overall.
-- Assuming "earn more than ₹75,000" refers to total salary of all faculty in a student's department.
select s.student_name
  from students s
 where (
   select sum(f.salary)
     from faculty f
    where f.department_id = s.department_id
) > 75000;

-- 25. Show students who have scored grade 'B'.
select distinct s.student_name
  from students s
  join enrollments e
on s.student_id = e.student_id
 where e.grade = 'B';