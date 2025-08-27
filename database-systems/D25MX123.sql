-- oldest movie
select * from movies;
select * from movies where year = (select min(year) from movies);
select * from (select * from movies order by year) where rownum = 1 ;
--longest length movie
select * from (select * from movies order by length_minutes )where rownum = 1 ;
-- no of movies directed by each director
select director, count(title) from movies group by director;

-- two or more movies
select director, count(*) from movies group by director having count(*)>=2;
