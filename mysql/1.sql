-- Active: 1697013083068@@127.0.0.1@3306
show databases;
use lianxi1;
show tables;


CREATE DATABASE lianxi1;
alter table wwb rename to student;

alter table student add id int;
alter table student add name varchar(10);

insert into student(id,name) values(1,"wwb");
desc student;
select * from student;

alter table student add age int;

insert into student(age) values(5);

select * from student;

update student set age = 5 WHERE name = "wwb";

drop table student;

create table  student(id int,name varchar(10));

insert into student(id,name) values(1,"王伟博");
alter table student add age int;
update student set age = 20 where id = 1;

DELETE from student WHERE age = 5;

insert  into student(id,name,age)  values(2,"薛皓匀",18);

DELETE FROM student WHERE name = "王伟博";

SELECT * FROM student;

insert  into student(id,name,age)  values(3,"李闫",18);
insert  into student(id,name,age)  values(4,"胡帅",18);
insert  into student(id,name,age)  values(5,"藤豪杰",18);
insert  into student(id,name,age)  values(6,"李宁",18);
insert  into student(id,name,age)  values(7,"韩高堃",18);
insert  into student(id,name,age)  values(8,"张哲旭",18);

SELECT age,name FROM student;

SELECT  
id,
name,
age ,
addre
FROM 
 student;

 ALTER TABLE student ADD addre VARCHAR(10);

UPDATE student SET addre = "山西";


SHOW DATABASES;
USE lianxi1;
SHOW TABLES;
CREATE TABLE STUDENT(ID INT,NAME VARCHAR(10),AGE INT,ADDER VARCHAR(30));

SELECT * FROM STUDENT;

ALTER TABLE STUDENT ADD SEX CHAR(3);

INSERT INTO STUDENT(ID,NAME,AGE) VALUES(1,"王伟博",20);

UPDATE STUDENT SET AGE=19 WHERE NAME = "王伟博";

UPDATE STUDENT SET AGE = 18;
UPDATE STUDENT SET ADDER = "山西";

UPDATE STUDENT  SET SEX = "男";

SHOW  DATABASES

USE LIANXI1;

SHOW TABLES;
SELECT * FROM STUDENT;
UPDATE STUDENT SET ADDER = "合肥" WHERE ID = 2;

UPDATE STUDENT SET ADDER = "西安" WHERE ID = 8;


ALTER  TABLE  STUDENT   ADD   C_TIME   VARCHAR(10) NOT NULL;

ALTER TABLE STUDENT  DROP  C_TIME;
INSERT INTO STUDENT (C_TIME) VALUES("5") ;

UPDATE STUDENT SET C_TIME = 5 WHERE ID = 2;

SELECT * FROM STUDENT ORDER BY ASC ;

























#查询操作；


SELECT
ID,
SEX,
NAME
FROM
student;

#条件查询

SELECT  * FROM student WHERE AGE >= 18;
SELECT * FROM student ORDER BY ID DESC ;

SELECT * FROM student ORDER BY AGE DESC,ID ASC;

SELECT COUNT(*) FROM student;

SELECT * FROM student;

SELECT MAX(AGE) FROM student;
SELECT SUM(AGE) FROM STUDENT;

UPDATE STUDENT SET AGE=18;


ALTER TABLE STUDENT DROP C_TIME;

ALTER TABLE STUDENT DROP ID;

ALTER TABLE STUDENT  ADD ID  INT   NOT  NULL PRIMARY KEY AUTO_INCREMENT;

DELETE FROM STUDENT WHERE ID = 9;
ALTER TABLE  STUDENT ADD C_TIME  INT  DEFAULT 0;
SELECT * FROM STUDENT;

CREATE TABLE CLASS(ID INT  NOT  NULL PRIMARY KEY AUTO_INCREMENT, NAME VARCHAR(10));
SELECT * FROM CLASS;

INSERT INTO CLASS(NAME) VALUES("341");

ALTER TABLE CLASS ADD C_ID INT NOT NULL;

ALTER TABLE STUDENT  ADD CONSTRAINT WWB FOREIGN  KEY(ID)  REFERENCES CLASS(ID);