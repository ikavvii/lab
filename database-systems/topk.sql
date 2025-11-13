create table sales (
   sale_id   number primary key,
   customer  varchar2(100),
   amount    number,
   sale_date date
);

-- Check Oracle version
select *
  from v$version;

-- Sample data
insert into sales (
   sale_id,
   customer,
   amount,
   sale_date
) values ( 1,
           'Alice',
           500,
           date '2024-01-01' );
insert into sales (
   sale_id,
   customer,
   amount,
   sale_date
) values ( 2,
           'Bob',
           250,
           date '2024-01-02' );
insert into sales (
   sale_id,
   customer,
   amount,
   sale_date
) values ( 3,
           'Carol',
           800,
           date '2024-01-03' );
insert into sales (
   sale_id,
   customer,
   amount,
   sale_date
) values ( 4,
           'Dave',
           800,
           date '2024-01-04' );
insert into sales (
   sale_id,
   customer,
   amount,
   sale_date
) values ( 5,
           'Eve',
           300,
           date '2024-01-05' );

commit;


-- Using ROWNUM to get top 3 sales by amount
select *
  from (
   select *
     from sales
    order by amount desc
)
 where rownum <= 3;

-- Using FETCH FIRST n ROWS ONLY to get top 3 sales by amount
-- Only available in Oracle 12c and later
select *
  from sales
 order by amount desc
 fetch first 3 rows only;

-- Window functions

select * from (
   select s.*, rank() over (order by amount desc) as sales_rank
     from sales s
) where sales_rank <= 3
order by amount desc, sale_id;