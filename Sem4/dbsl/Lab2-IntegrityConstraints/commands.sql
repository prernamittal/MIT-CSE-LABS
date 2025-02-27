--ques1-Create Employee table
create table employee(
EmpNo number(10) primary key,
EmpName varchar (30) not null,
gender varchar(10) not null check(gender='male' or gender='female'),
salary number(20) not null,
address varchar(30) not null,
dNo number(7));

--ques2-Create Department table
create table department(
DeptNo number(7) primary key,
DeptName varchar (30) unique);

--ques3-Make DNo of Employee as foreign key which refers to DeptNo of Department.
alter table employee add constraint fdNo foreign key(dNo) references department(DeptNo);

--ques4-Insert few tuples into Employee and Department which satisfies the above constraints
insert into department values(123,'compscience');
insert into department values(456,'datascience');
insert into employee values(123,'prerna','female',12000,'noida',21090);
insert into employee values(456,'preet','male',11000,'mumbai',53280);

--ques5-Try to insert few tuples into Employee and Department which violates some of the 
above constraints
insert into department values(123,'compengg');
insert into employee values(174,'prerz','female',null,'delhi',21091);
insert into employee values(214,'preetam','zzz',150000,'manipal',20091);

--ques6-Try to modify/delete a tuple which violates a constraint.
delete from department where DeptNo in (
select dNo from employee group by dNo having count(*) > 1);

--ques7-Modify the foreign key constraint of Employee table such that whenever a department 
tuple is deleted, the employees belonging to that department will also be deleted.
alter table employee drop constraint fdNo;
alter table employee add constraint fdNo foreign key(dNo) references department(DeptNo) on delete cascade;

--ques8-Create a named constraint to set the default salary to 10000 and test the constraint by 
 inserting a new record.
alter table employee
modify(salary default 10000);
insert into employee values(5,'pree','male',default,'udupi',2332);

--ques9
select name, dept_name from student;

--ques10
select name from instructor where dept_name='Comp. Sci.';

--ques11
select title from course
where dept_name='Comp. Sci.'
and credits=3;

--ques12
select course_id, title from course where course_id in(
select course_id from takes where id=12345);

--ques13
select name from instructor where salary between 40000 and 90000;

--ques18
select name from instructor where dept_name like '%ch%'; 

--ques19
SELECT length(name) from student;

--ques20
select dept_name, substr(dept_name,3,3) from department;

--ques21
SELECT upper(name) from instructor;

--ques22- Replace NULL with value1(say 0) for a column in any of the tabl
select nvl(grade,'A++') from takes;

--ques23-Display the salary and salary/3 rounded to nearest hundred from Instructor
select salary, round(salary/3, 2) from instructor;

--ques24-. Display the birth date of all the employees in the following format
--‘DD-MON-YYYY’
select to_char(birthdate, 'DD/MON/YYYY') as birthdate
from members;
--'DD-MON-YY'
select to_char(birthdate, 'DD/MON/YY') as birthdate
from members;
--‘DD-MM-YY’
select to_char(birthdate, 'DD/MM/YY') as birthdate
from members;

--add.ques7-Find all the instructors with the courses they taught.
select name, course_id
from instructor i, teaches t
where i.id=t.id;
