create table dept (
   deptcode char(4) primary key,
   deptname varchar(20)
);

create table emply (
   empcode   char(4) primary key,
   empname   varchar(50),
   address   varchar(50),
   age       number(2),
   dept_code char(4)
      references dept ( deptcode )
         on delete cascade
);

create table payslip (
   empcode char(4),
   basic   number(10,2) check ( basic >= 0 ),
   hra     number(8,2) check ( hra >= 0 ),
   da      number(6,2) check ( da >= 0 ),
   foreign key ( empcode )
      references emply ( empcode )
);

-- Oracle doesn't support on update cascade clause. Why?

insert into dept (
   deptcode,
   deptname
) values ( 'D301',
           'Sales' );
insert into dept (
   deptcode,
   deptname
) values ( 'D302',
           'Account' );
insert into dept (
   deptcode,
   deptname
) values ( 'D707',
           'Research' );
insert into dept (
   deptcode,
   deptname
) values ( 'D909',
           'Advertising' );
insert into dept (
   deptcode,
   deptname
) values ( 'D202',
           'Stock' );
insert into dept (
   deptcode,
   deptname
) values ( 'D110',
           'Computer' );
insert into dept (
   deptcode,
   deptname
) values ( 'D305',
           'Marketing' );


insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E101',
           'Anjaly',
           'Anjaly Nivas, Thiruvalla',
           25,
           'D301' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E102',
           'Bobby',
           'Alapuzha',
           28,
           'D305' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E103',
           'Aravind',
           'Chennai',
           31,
           'D305' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E104',
           'Lakshmi',
           'Mannar',
           55,
           'D707' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E105',
           'Daisy',
           'Chaithram, Angamaly',
           35,
           'D707' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E106',
           'Esha',
           'Mumbai',
           23,
           'D707' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E107',
           'Georgy',
           'Pala',
           45,
           'D909' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E108',
           'Prakash',
           'Vennikulam',
           36,
           'D110' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E109',
           'Madhavan',
           'Mynakum, Kottayam',
           46,
           'D202' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E110',
           'Anugraha',
           'Aparna, Angamaly',
           47,
           'D301' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E111',
           'Deva',
           'Trichy',
           38,
           'D301' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E112',
           'Saju',
           'Dhanya, Ernakulam',
           27,
           'D202' );
insert into emply (
   empcode,
   empname,
   address,
   age,
   dept_code
) values ( 'E113',
           'Priyesh',
           'Priya Nivas, Kottayam',
           26,
           'D302' );


insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E101',
           4000.00,
           1900.00,
           1500.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E102',
           4500.00,
           2200.00,
           2000.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E103',
           5000.00,
           2800.00,
           2200.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E104',
           7000.00,
           3000.00,
           2700.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E105',
           3000.00,
           1500.00,
           1200.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E106',
           5700.00,
           3000.00,
           2900.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E107',
           6200.00,
           3300.00,
           3000.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E108',
           5700.00,
           3700.00,
           3000.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E109',
           7500.00,
           4660.00,
           545.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E110',
           5000.00,
           300.00,
           100.00 );
insert into payslip (
   empcode,
   basic,
   hra,
   da
) values ( 'E111',
           6000.00,
           200.00,
           120.00 );

commit;

-- 1. Update table EMPLY, add 15 years of age to employee with EMPCODE 'E107'.
update emply
   set
   age = age + 15
 where empcode = 'E107';
select *
  from emply;

-- 2. Create a view which shows details of employees whose age is between 35 and 45.

create view age_bw_35and45 as
   select *
     from emply
    where age between 35 and 45;

select *
  from age_bw_35and45;

-- 3. Retrieve empcode, empname, address, Netpay from EMPLY and PAYSLIP. Display in ascending order of empcode.

create or replace view payslip_new as
   select empcode,
          basic + hra + da as netpay
     from payslip;

select e.empcode,
       empname,
       address,
       netpay
  from emply e
  left join payslip_new p
on e.empcode = p.empcode
 order by e.empcode;


-- 4. Create an English like sentence to display the following output from payslip table. Employees with empcode E101 draws a basic salary 4000.

select ('Employee with empcode ' || empcode || ' draws a basic salary ' || basic) as output from payslip;