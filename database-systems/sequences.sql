create table employees (
   emp_id     number primary key,
   first_name varchar2(50),
   last_name  varchar2(50),
   hire_date  date default sysdate
);

DESC employees;

create sequence emp_seq start with 1000 increment by 1 nocache nocycle;

select emp_seq.nextval
  from dual;

insert into employees (
   emp_id,
   first_name,
   last_name
) values ( emp_seq.nextval,
           'John',
           'Doe' );

insert into employees (
   emp_id,
   first_name,
   last_name
) values ( emp_seq.nextval,
           'Jane',
           'Smith' );

select *
  from employees;

select sequence_name,
       min_value,
       max_value,
       increment_by,
       last_number
  from user_sequences
 where sequence_name = 'EMP_SEQ';

alter sequence emp_seq
    increment by 10;

--    start with 2000;  -- Note: start with is only effective when the sequence is recreated

drop sequence emp_seq;

drop table employees;

desc departments;
drop table departments purge;

select * from USER_CONSTRAINTS where table_name = 'DEPARTMENTS';


create table departments (
   dept_id     number primary key,
   dept_name   varchar2(50)
);

create sequence dept_seq 
    start with 1
    increment by 1
    nocache
    nocycle;

