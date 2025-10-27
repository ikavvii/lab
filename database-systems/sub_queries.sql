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
      references dept ( deptcode ) on delete cascade
);

create table payslip (
   empcode char(4),
   basic   number(10,2) check ( basic >= 0 ),
   hra     number(8,2) check ( hra >= 0 ),
   da      number(6,2) check ( da >= 0 ),
   foreign key (empcode) references emply ( empcode ) on update cascade
);

-- Oracle doesn't support on update cascade clause. Why?