drop table actors;

create table actors (
    id number(6) primary key,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    gender char(1) check (gender in ('M', 'F'))
);
drop table movies;
create table movies (
    id number(6) primary key,
    name VARCHAR(50),
    year number(4)
);

drop table roles;
create table roles (
    actor_id number(6) REFERENCES actors(id),
    movie_id number(6) REFERENCES movies(id),
    role VARCHAR(50),
    PRIMARY key(actor_id, movie_id)
);

SELECT * FROM v$version; -- checks oracle version
SELECT * from ROLES;
-- Insert data into actors
INSERT INTO actors (id, first_name, last_name, gender) VALUES (433259, 'William', 'Shatner', 'M');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (797926, 'Britney', 'Spears', 'F');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (831289, 'Sigourney', 'Weaver', 'F');

-- Insert data into movies
INSERT INTO movies (id, name, year) VALUES (112290, 'Fight Club', 1999);
INSERT INTO movies (id, name, year) VALUES (209658, 'Meet the Parents', 2000);
INSERT INTO movies (id, name, year) VALUES (210511, 'Memento', 2000);
INSERT INTO movies (id, name, year) VALUES (313398, 'Star Trek', 1966);       
INSERT INTO movies (id, name, year) VALUES (407323, 'T.J. Hooker', 1982);      
INSERT INTO movies (id, name, year) VALUES (342189, 'Britney Spears: Herself', 2002); 

-- Insert data into roles
INSERT INTO roles (actor_id, movie_id, role) VALUES (433259, 313398, 'Capt. James T. Kirk');
INSERT INTO roles (actor_id, movie_id, role) VALUES (433259, 407323, 'Sgt. T.J. Hooker');
INSERT INTO roles (actor_id, movie_id, role) VALUES (797926, 342189, 'Herself');


-- Extra data
-- Actors
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101101, 'Julia', 'Roberts', 'F');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101102, 'Julia', 'Stiles', 'F');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101103, 'Julia', 'Louis-Dreyfus', 'F');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101104, 'John', 'Travolta', 'M');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101105, 'Uma', 'Thurman', 'F');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101106, 'David', 'Carradine', 'M');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101107, 'Bruce', 'Willis', 'M');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101108, 'Williams', 'Smith', 'M');
INSERT INTO actors (id, first_name, last_name, gender) VALUES (101109, 'Williams', 'Jones', 'M');


-- Movies
INSERT INTO movies (id, name, year) VALUES (300001, 'Pi', 1998);
INSERT INTO movies (id, name, year) VALUES (300002, 'Kill Bill: Vol. 1', 2003);
INSERT INTO movies (id, name, year) VALUES (300003, 'Kill Bill: Vol. 2', 2004);
INSERT INTO movies (id, name, year) VALUES (300004, 'Pulp Fiction', 1994);
INSERT INTO movies (id, name, year) VALUES (300005, 'Horror Nights', 1999);
INSERT INTO movies (id, name, year) VALUES (300006, 'Horror Mansion', 2001);

-- Roles for Julia
INSERT INTO roles (actor_id, movie_id, role) VALUES (101101, 209658, 'Pam Byrnes'); -- Julia Roberts in Meet the Parents
INSERT INTO roles (actor_id, movie_id, role) VALUES (101102, 300001, 'Max Cohen');  -- Julia Stiles in Pi
INSERT INTO roles (actor_id, movie_id, role) VALUES (101103, 112290, 'Marla Singer'); -- Julia Louis-Dreyfus in Fight Club

-- Roles for Williams as Capt%
INSERT INTO roles (actor_id, movie_id, role) VALUES (101108, 313398, 'Capt. Kirk Williams'); -- Williams Smith in Star Trek
INSERT INTO roles (actor_id, movie_id, role) VALUES (101109, 313398, 'Capt. Williams Jones'); -- Williams Jones in Star Trek

-- Roles for Pi
INSERT INTO roles (actor_id, movie_id, role) VALUES (831289, 300001, 'Herself'); -- Sigourney Weaver in Pi

-- Roles for Kill Bill
INSERT INTO roles (actor_id, movie_id, role) VALUES (101105, 300002, 'The Bride'); -- Uma Thurman in Kill Bill Vol. 1
INSERT INTO roles (actor_id, movie_id, role) VALUES (101105, 300003, 'The Bride'); -- Uma Thurman in Kill Bill Vol. 2
INSERT INTO roles (actor_id, movie_id, role) VALUES (101106, 300002, 'Bill'); -- David Carradine in Kill Bill Vol. 1
INSERT INTO roles (actor_id, movie_id, role) VALUES (101106, 300003, 'Bill'); -- David Carradine in Kill Bill Vol. 2

-- Fight Club roles
INSERT INTO roles (actor_id, movie_id, role) VALUES (101104, 112290, 'Tyler Durden'); -- John Travolta in Fight Club

-- More for horror queries
INSERT INTO roles (actor_id, movie_id, role) VALUES (101107, 300005, 'Ghost'); -- Bruce Willis in Horror Nights
INSERT INTO roles (actor_id, movie_id, role) VALUES (101107, 300006, 'Ghost'); -- Bruce Willis in Horror Mansion



-- 1. Show all columns of all actors who have the first name Julia.

SELECT * FROM ACTORS WHERE FIRST_NAME='Julia';

-- 2. Show just the IDs and names of all movies released between 1995 -2000 inclusive.
SELECT id, name FROM MOVIES WHERE YEAR BETWEEN 1995 and 2000;

-- 3. Show the IDs of all actors who appeared in the movie Fight Club.
select r.ACTOR_ID from roles r join MOVIES m on m.id = r.movie_id where m.name = 'Fight Club';

-- 4. Show the first/last names of all actors who appeared in Pi, along with their roles.
