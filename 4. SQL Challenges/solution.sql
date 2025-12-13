-- Online SQL Editor to Run SQL Online.

create table students(
    student_id Int PRIMARY KEY,
    name VARCHAR(50),
	grade INT
);

-- insert some students data

Insert into students (student_id, name, grade) 
VALUES (1, 'Alice', 89);
Insert into students (student_id, name, grade) 
VALUES (3, 'Bob', 100);
Insert into students (student_id, name, grade) 
VALUES (5, 'Charlie', 92);
Insert into students (student_id, name, grade) 
VALUES (4, 'Luice', 50);

-- query 
select * from students where grade>=90 and grade<=100;




