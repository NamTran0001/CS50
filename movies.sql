-- 1. Titles of all movies from 2008
select title from movies where year = 2008;

-- 2. Birth year of Emma Stone
select birth from people where name = 'Emma Stone';

-- 3. Titles of all movies since 2018, in alphabetical order
select title from movies where year >= 2018 order by title;

-- 4. Number of movies with a 10.0 rating
select count(*) as n from movies join ratings on ratings.movie_id = movies.id where rating = 10.0;

-- 5. Titles and years of all Harry Potter movies, in chronological order (title beginning with "Harry Potter and the ...")
select title, year from movies where title like 'Harry Potter and the %' order by year;

-- 6. Average rating of movies in 2012
select avg(rating) from ratings join movies on id = movie_id where year = 2012;

-- 7. All movies and ratings from 2010, in decreasing order by rating (alphabetical for those with same rating)
select title, rating from movies join ratings on id = movie_id where year = 2010 order by rating DESC, title limit 10;

-- 8. Names of people who starred in Toy Story
select p.name from people p
join stars s on s.person_id = p.id
join movies m on m.id = s.movie_id
where m.title = 'Toy Story';

-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
select  p.id  , p.name from people p
join stars s on s.person_id = p.id
join movies m on m.id = s.movie_id
where m.year = 2004
order by p.birth;

-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
select p.name from people p
join directors d on d.person_id = p.id
join movies m on m.id = d.movie_id
join ratings r on r.movie_id = m.id
where rating >= 9;

-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
select distinct m.title from movies m
join stars s on s.movie_id = m.id
join people p on p.id = s.person_id
join ratings r on r.movie_id = m.id
where p.name = 'Chadwick Boseman'
order by rating desc limit 5;

-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
select distinct m.title from movies m
join stars s on s.movie_id = m.id
join people p on p.id = s.person_id
JOIN stars s2 ON s2.movie_id = m.id
JOIN people p2 ON p2.id = s2.person_id
where p.name == 'Jennifer Lawrence' and p2.name == 'Bradley Cooper'
and p.name is not null and p2.name is not null;

-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred
select p.name from people p
where p.id in (select s.person_id from stars s
                where s.movie_id in(select s2.movie_id from stars s2
                                    join people p2 on p2.id = s2.person_id
                                    where p2.name = 'Kevin Bacon')) and p.name <> 'Kevin Bacon';







