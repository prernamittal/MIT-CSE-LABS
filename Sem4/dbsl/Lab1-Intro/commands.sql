--ques1:Create a table employee with ( emp_no, emp_name, emp_address)
CREATE table employee(
emp_no number (5),
emp_name varchar (20),
emp_address varchar(30));

--ques2:Insert five employees information
INSERT into employee values(1,'prerna','noida');
INSERT into employee values(2,'priya','mangalore');
INSERT into employee values(3,'priyanka','manipal');
INSERT into employee values(4,'preet','delhi');
INSERT into employee values(5,'priyank','mumbai');

--ques3:Display names of all employees
SELECT * from employee;

--ques4:Display all the employees from ‘MANIPAL’
SELECT * from employee WHERE emp_address='manipal';

--ques5:Add a column named salary to employee table
ALTER table employee ADD(salary number(10));

--ques6:Assign the salary for all employees
UPDATE employee SET salary=100000;

--ques7:View the structure of the table employee using describe
DESC employee;

--ques8:Delete all the employees from ‘MANGALORE’
DELETE from employee WHERE emp_address='mangalore';

--ques9:Rename employee as employee1
ALTER table employee RENAME to employee1;

--ques10:Drop the table employee1
DROP table employee1;

