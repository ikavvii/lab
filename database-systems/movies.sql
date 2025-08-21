CREATE TABLE movies (
id INT PRIMARY KEY,
title VARCHAR(20),
director VARCHAR(20),
year INT,
length_minutes INT);


insert into movies values (&id, '&title', '&director', &year, &length_minutes);

select * from movies;

-- SQL Exercise 1

-- 1 Find the title of the each film
select title from movies;

-- 2 find the director of each film
select director from movies;

-- 3 find the title and director of each film
select title, director from movies;

-- 4 find the title and year of each film
select title, year from movies;

-- 5 find all the information about each film
select * from movies;

-- 6 find the movie with id of 6
select * from movies where id=6;

-- 7 find the movie released in the years between 2000 and 2010
select * from movies where year between 2000 and 2010;

-- 8 find the movies not released in the years between 2000 and 2010
select * from movies where year not between 2000 and 2010;

-- 9 find the first 5 pixar movies and their release year 
select title, year from movies order by year limit 5;

--select * from movies limit 5;

-- 10 find all the toy story movies
select * from movies where title like 'Toy Story%';

-- 11 find all the movies dirrected by John Lasseter
select * from movies where director='John Lasseter';

-- 12 find all the movies (and director) not directed by the John Lasseter
select * from movies where director!='John Lasseter';

-- 13 find all the wall-* movies
select * from movies where title like 'WALL-%';

-- 14 List all the directors of Pixar movies (alphabetically) without duplicates
select distinct director from movies order by director;

-- 15 List the last four pixar movies released(order from most recent to least)
select * from movies order by year desc limit 4;

-- 16 List the first five pixar movies sorted alphabetically
select * from movies order by title limit 5;

-- 17 List the next five pixar movies sorted alphabetically
select * from movies order by title limit 5 offset 5;

-- SQL Exercise 2

-- 1 Add the studio's new production, Toy Story 4 to the list of movies (you can use any director)
insert into movies values (10, 'Toy Story 4', 'Josh Cooley', 2019, 100);

-- 2 The director for A Bug's Life is incorrect, it was actually directed by John Lasseter
update movies set director='John Lasseter' where title='A Bugs Life';

-- 3 The year that Toy Story 2 was released is incorrect, it was actually released in 1999
update movies set year=1999 where title='Toy Story 2';

-- 4 Both the title and director for Toy Story 8 is incorrect! 
-- 	 The title should be Toy Story 3 and it was directed by Lee Unkrich
update movies set title='Toy Story 3', director='Lee Unkrich' where title='Toy Story 8';

-- 5 Add a column named Aspect_ratio with a FLOAT data type to store the aspect-ratio each movie was released in.
alter table movies add Aspect_ratio FLOAT;

-- 6 Add another column named Language with a TEXT data type to store the language that the movie was released in.
--   Ensure that the default for this language is English.
alter table movies add language TEXT default 'English';
