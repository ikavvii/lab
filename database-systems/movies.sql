DROP TABLE movies;
-- Table MOVIES dropped.
CREATE TABLE movies (
    id INT PRIMARY KEY,
    title VARCHAR(20),
    director VARCHAR(20),
    year INT,
    length_minutes INT
);
-- Table MOVIES created.
--insert into movies
--values (
--        & id,
--        '&title',
--        '&director',
--        & year,
--        & length_minutes
--    );
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (1, 'Toy Story', 'John Lasseter', 1995, 81);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (2, 'A Bug''s Life', 'John Lasseter', 1998, 95);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (3, 'Toy Story 2', 'John Lasseter', 1999, 93);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (4, 'Monsters, Inc.', 'Pete Docter', 2001, 92);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (5, 'Finding Nemo', 'Andrew Stanton', 2003, 107);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (6, 'The Incredibles', 'Brad Bird', 2004, 116);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (7, 'Cars', 'John Lasseter', 2006, 117);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (8, 'Ratatouille', 'Brad Bird', 2007, 115);
INSERT INTO movies (id, title, director, year, length_minutes)
VALUES (9, 'WALL-E', 'Andrew Stanton', 2008, 104);
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
-- 1 row inserted.
select *
from movies;
-- SQL Exercise 1
-- 1 Find the title of the each film
select title
from movies;
-- TITLE               
-- --------------------
-- Toy Story
-- A Bug's Life
-- Toy Story 2
-- Monsters, Inc.
-- Finding Nemo
-- The Incredibles
-- Cars
-- Ratatouille
-- WALL-E
-- 9 rows selected. 
-- 2 find the director of each film
select director
from movies;
-- DIRECTOR            
-- --------------------
-- John Lasseter
-- John Lasseter
-- John Lasseter
-- Pete Docter
-- Andrew Stanton
-- Brad Bird
-- John Lasseter
-- Brad Bird
-- Andrew Stanton
-- 9 rows selected. 
-- 3 find the title and director of each film
select title,
    director
from movies;
-- TITLE                DIRECTOR            
-- -------------------- --------------------
-- Toy Story            John Lasseter       
-- A Bug's Life         John Lasseter       
-- Toy Story 2          John Lasseter       
-- Monsters, Inc.       Pete Docter         
-- Finding Nemo         Andrew Stanton      
-- The Incredibles      Brad Bird           
-- Cars                 John Lasseter       
-- Ratatouille          Brad Bird           
-- WALL-E               Andrew Stanton      
-- 9 rows selected. 
-- 4 find the title and year of each film
select title,
    year
from movies;
-- TITLE                      YEAR
-- -------------------- ----------
-- Toy Story                  1995
-- A Bug's Life               1998
-- Toy Story 2                1999
-- Monsters, Inc.             2001
-- Finding Nemo               2003
-- The Incredibles            2004
-- Cars                       2006
-- Ratatouille                2007
-- WALL-E                     2008
-- 9 rows selected. 
-- 5 find all the information about each film
select *
from movies;
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          1 Toy Story            John Lasseter              1995             81
--          2 A Bug's Life         John Lasseter              1998             95
--          3 Toy Story 2          John Lasseter              1999             93
--          4 Monsters, Inc.       Pete Docter                2001             92
--          5 Finding Nemo         Andrew Stanton             2003            107
--          6 The Incredibles      Brad Bird                  2004            116
--          7 Cars                 John Lasseter              2006            117
--          8 Ratatouille          Brad Bird                  2007            115
--          9 WALL-E               Andrew Stanton             2008            104
-- 9 rows selected. 
-- 6 find the movie with id of 6
select *
from movies
where id = 6;
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          6 The Incredibles      Brad Bird                  2004            116
-- 7 find the movie released in the years between 2000 and 2010
select *
from movies
where year between 2000 and 2010;
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          4 Monsters, Inc.       Pete Docter                2001             92
--          5 Finding Nemo         Andrew Stanton             2003            107
--          6 The Incredibles      Brad Bird                  2004            116
--          7 Cars                 John Lasseter              2006            117
--          8 Ratatouille          Brad Bird                  2007            115
--          9 WALL-E               Andrew Stanton             2008            104
-- 6 rows selected. 
-- 8 find the movies not released in the years between 2000 and 2010
select *
from movies
where year not between 2000 and 2010;
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          1 Toy Story            John Lasseter              1995             81
--          2 A Bug's Life         John Lasseter              1998             95
--          3 Toy Story 2          John Lasseter              1999             93
-- 9 find the first 5 pixar movies and their release year 
select title,
    year
from (
        select *
        from movies
        order by year
    )
where rownum between 1 and 5;
-- TITLE                      YEAR
-- -------------------- ----------
-- Toy Story                  1995
-- A Bug's Life               1998
-- Toy Story 2                1999
-- Monsters, Inc.             2001
-- Finding Nemo               2003
-- 10 find all the toy story movies
select *
from movies
where title like 'Toy Story%';
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          1 Toy Story            John Lasseter              1995             81
--          3 Toy Story 2          John Lasseter              1999             93
-- 11 find all the movies dirrected by John Lasseter
select *
from movies
where director = 'John Lasseter';
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          1 Toy Story            John Lasseter              1995             81
--          2 A Bug's Life         John Lasseter              1998             95
--          3 Toy Story 2          John Lasseter              1999             93
--          7 Cars                 John Lasseter              2006            117
-- 12 find all the movies (and director) not directed by the John Lasseter
select *
from movies
where director != 'John Lasseter';
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          4 Monsters, Inc.       Pete Docter                2001             92
--          5 Finding Nemo         Andrew Stanton             2003            107
--          6 The Incredibles      Brad Bird                  2004            116
--          8 Ratatouille          Brad Bird                  2007            115
--          9 WALL-E               Andrew Stanton             2008            104
-- 13 find all the wall-* movies
select *
from movies
where title like 'WALL-%';
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          9 WALL-E               Andrew Stanton             2008            104
-- 14 List all the directors of Pixar movies (alphabetically) without duplicates
select distinct director
from movies
order by director;
-- DIRECTOR            
-- --------------------
-- Andrew Stanton
-- Brad Bird
-- John Lasseter
-- Pete Docter
-- 15 List the last four pixar movies released(order from most recent to least)
select *
from (
        select *
        from movies
        order by year desc
    )
where rownum between 1 and 4;
--         ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          9 WALL-E               Andrew Stanton             2008            104
--          8 Ratatouille          Brad Bird                  2007            115
--          7 Cars                 John Lasseter              2006            117
--          6 The Incredibles      Brad Bird                  2004            116
-- 16 List the first five pixar movies sorted alphabetically
select *
from (
        select *
        from movies
        order by year
    )
where rownum <= 5
order by title;
--     ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES
-- ---------- -------------------- -------------------- ---------- --------------
--          2 A Bug's Life         John Lasseter              1998             95
--          5 Finding Nemo         Andrew Stanton             2003            107
--          4 Monsters, Inc.       Pete Docter                2001             92
--          1 Toy Story            John Lasseter              1995             81
--          3 Toy Story 2          John Lasseter              1999             93
-- 17 List the next five pixar movies sorted alphabetically
SELECT *
FROM (
        SELECT m.*,
            ROWNUM AS rn
        FROM (
                SELECT *
                FROM movies
                ORDER BY year
            ) m
        WHERE ROWNUM <= 10
        order by title -- OFFSET (5) + FETCH (5)
    )
WHERE rn > 5;
-- OFFSET (5)
--        ID TITLE                DIRECTOR                   YEAR LENGTH_MINUTES         RN
-- ---------- -------------------- -------------------- ---------- -------------- ----------
--          7 Cars                 John Lasseter              2006            117          7
--          8 Ratatouille          Brad Bird                  2007            115          8
--          6 The Incredibles      Brad Bird                  2004            116          6
--          9 WALL-E               Andrew Stanton             2008            104          9
-- SQL Exercise 2
-- 1 Add the studio's new production, Toy Story 4 to the list of movies (you can use any director)
insert into movies
values (10, 'Toy Story 4', 'Josh Cooley', 2019, 100);
-- 1 row inserted.
-- 2 The director for A Bug's Life is incorrect, it was actually directed by John Lasseter
update movies
set director = 'John Lasseter'
where title = 'A Bug''s Life';
-- 1 row updated.
-- 3 The year that Toy Story 2 was released is incorrect, it was actually released in 1999
update movies
set year = 1999
where title = 'Toy Story 2';
--1 row updated.
-- 4 Both the title and director for Toy Story 8 is incorrect! 
-- 	 The title should be Toy Story 3 and it was directed by Lee Unkrich
update movies
set title = 'Toy Story 3',
    director = 'Lee Unkrich'
where title = 'Toy Story 8';
-- 0 rows updated.
-- 5 Add a column named Aspect_ratio with a FLOAT data type to store the aspect-ratio each movie was released in.
alter table movies
add Aspect_ratio FLOAT;
-- Table MOVIES altered.
-- 6 Add another column named Language with a TEXT data type to store the language that the movie was released in.
--   Ensure that the default for this language is English.
alter table movies
add language VARCHAR2(50) default 'English';
-- Table MOVIES altered.