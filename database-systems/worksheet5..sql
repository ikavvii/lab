-- 1. Which students were born in 1985?
select *
  from students
 where substr(
   pnbr,
   1,
   2
) = 86;

-- 2. What are the names of the female students, and which are their person numbers?
-- Hint : The next-to-last digit in the person number is even for females. Use substr(str,m,n) and
-- mod(m,n) function.
select *
  from students
 where mod(
   substr(
      pnbr,
      10,
      1
   ),
   2
) = 0;

-- 3. How many students are registered in the database?
select count(*)
  from students;

-- 4. Which courses are offered by the department of Mathematics (course codes FMAxxx)?
select *
  from courses
 where substr(
   coursecode,
   0,
   3
) = 'FMA';

-- 5. Which courses give more than 7.5 credits?
select *
  from courses
 where credits > 7.5;

-- 6. How many courses are there on each level G1, G2 and A?
select count(*),
       courselevel
  from courses
 group by courselevel;
-- 7. Which courses (course codes only) have been taken by the student with person number
-- 910101-1234?
select coursecode
  from takencourses
 where pnbr = '861103-2438';

-- 8. What are the names of these courses, and how many credits do they give?
select coursename,
       credits
  from courses;

-- 9. Which is the student’s grade average (arithmetic mean, not weighted) on the courses?
select avg(grade),
       coursecode
  from takencourses
 group by coursecode;

-- 10. Which students have taken 0 credits?

select *
  from students
 where pnbr not in (
   select distinct pnbr
     from takencourses
);

-- 11. Which students have the highest grade average? Advice: define and use a view that gives the
-- person number and grade average for each student.

create view overall_grade as
   select avg(grade) as grade_avg,
          pnbr
     from takencourses
    group by pnbr;

select students.pnbr,
       students.firstname,
       students.lastname,
       overall_grade.grade_avg
  from students
 inner join overall_grade
on students.pnbr = overall_grade.pnbr;

-- 12. List the person number and total number of credits for all students. Students with no credits
-- should be included with 0 credits, not null. If you do this with an outer join you might want to use
-- the function coalesce(v1, v2, ...); it returns the first value which is not null.

select students.pnbr,
       studentcredits.total_credits
  from students
  left outer join (
   select takencourses.pnbr,
          sum(courses.credits) as total_credits
     from takencourses
     join courses
   on takencourses.coursecode = courses.coursecode
    group by takencourses.pnbr
) studentcredits
on students.pnbr = studentcredits.pnbr;

-- 13. Is there more than one student with the same name? If so, who are these students and what are
-- their person numbers?

select students.name, count(*) from students group by students.name;