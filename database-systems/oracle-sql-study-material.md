# Oracle SQL — Study Material (Comprehensive Cheat Sheet + Examples + Exercises)

Target audience: developers or DBAs learning Oracle SQL features: queries, conditions, aggregates, GROUP BY/HAVING/ORDER BY, subqueries (ANY/ALL/IN/EXISTS), correlated subqueries, multi-table queries and joins, set operations, synonyms, sequences, views, indexes, SQL APIs and triggers. Examples use Oracle syntax.

---

Contents
- Quick reference schema (sample tables)
- Basic data retrieval & condition specification
- Aggregate functions
- GROUP BY / HAVING / ORDER BY
- Subqueries: types, ANY/ALL/IN, correlated subqueries, EXISTS / NOT EXISTS
- Multi-table queries & SQL JOINs
- Set operations
- Oracle-specific objects: synonyms, sequences, views, indexes
- SQL APIs (how to run SQL against Oracle)
- Triggers
- Tips & best practices
- Exercises (with solutions)

---

Sample schema (used in examples)
```sql
-- Departments
CREATE TABLE dept (
  dept_id NUMBER PRIMARY KEY,
  name VARCHAR2(50),
  location VARCHAR2(50)
);

-- Employees
CREATE TABLE emp (
  emp_id NUMBER PRIMARY KEY,
  first_name VARCHAR2(50),
  last_name VARCHAR2(50),
  dept_id NUMBER REFERENCES dept(dept_id),
  salary NUMBER(10,2),
  hire_date DATE,
  manager_id NUMBER  -- self reference to emp.emp_id
);

-- Sample data
INSERT INTO dept VALUES (10, 'ACCOUNTING','NEW YORK');
INSERT INTO dept VALUES (20, 'RESEARCH','DALLAS');
INSERT INTO dept VALUES (30, 'SALES','CHICAGO');

INSERT INTO emp VALUES (100, 'John', 'Doe', 10, 5000, TO_DATE('2015-03-01','YYYY-MM-DD'), NULL);
INSERT INTO emp VALUES (101, 'Jane', 'Smith', 20, 7000, TO_DATE('2012-07-15','YYYY-MM-DD'), 100);
INSERT INTO emp VALUES (102, 'Bob', 'Brown', 20, 6000, TO_DATE('2018-01-23','YYYY-MM-DD'), 100);
INSERT INTO emp VALUES (103, 'Alice', 'White', 30, 4500, TO_DATE('2019-05-10','YYYY-MM-DD'), 101);
COMMIT;
```

---

1) Basic data retrieval (SELECT) and condition specification
- Basic:
  - SELECT column_list FROM table;
  - SELECT * FROM emp;
- Filtering with WHERE:
  - Comparison operators: =, <>, !=, >, >=, <, <=
  - Logical: AND, OR, NOT
  - BETWEEN ... AND ...
  - IN (...), e.g. dept_id IN (10,20)
  - LIKE (case-sensitive in Oracle): '%' wildcard, '_' single char. Use UPPER() for case-insensitive matching.
  - NULL checks: IS NULL, IS NOT NULL
  - EXISTS with subquery (examples later)
- Example:
```sql
SELECT first_name, last_name, salary
FROM emp
WHERE dept_id = 20
  AND salary > 6000;
```
- Date/time comparisons:
```sql
SELECT * FROM emp WHERE hire_date >= DATE '2018-01-01';
-- or
SELECT * FROM emp WHERE hire_date >= TO_DATE('2018-01-01', 'YYYY-MM-DD');
```

---

2) Aggregate functions
- COUNT(expr), COUNT(*)
- SUM(expr), AVG(expr), MIN(expr), MAX(expr)
- NULLs: aggregates skip NULL values (except COUNT(*) counts rows).
- Examples:
```sql
SELECT COUNT(*) AS total_emps FROM emp;
SELECT AVG(salary) AS avg_sal FROM emp WHERE dept_id = 20;
SELECT MAX(salary) FROM emp;
```

---

3) GROUP BY, HAVING, ORDER BY
- GROUP BY groups rows for aggregates.
- HAVING filters groups (analogous to WHERE but for groups).
- ORDER BY sorts results. Can use column positions or expressions; add NULLS FIRST / NULLS LAST.
- Examples:
```sql
-- total salary by department
SELECT dept_id, COUNT(*) AS emp_count, SUM(salary) AS total_salary
FROM emp
GROUP BY dept_id
ORDER BY total_salary DESC;

-- filter groups
SELECT dept_id, AVG(salary) AS avg_sal
FROM emp
GROUP BY dept_id
HAVING AVG(salary) > 5000;
```

- Note: You cannot SELECT non-aggregated columns not in GROUP BY (unless using analytic functions).

---

4) ORDER BY with paging (Oracle 12c+)
- Modern:
```sql
SELECT * FROM emp
ORDER BY salary DESC
OFFSET 0 ROWS FETCH NEXT 10 ROWS ONLY;
```
- Legacy (ROWNUM):
```sql
SELECT * FROM (
  SELECT e.*, ROWNUM rnum FROM (
    SELECT * FROM emp ORDER BY salary DESC
  ) e WHERE ROWNUM <= 10
) WHERE rnum >= 1;
```

---

5) Subqueries
Types:
- Single-row subquery: returns one value; used with =, <, >.
- Multi-row subquery: returns multiple values; used with IN, ANY/SOME, ALL.
- Correlated subquery: references outer query columns; evaluated per row.
- Scalar subquery: returns single value (can be used in SELECT).

Examples:

- Single-row:
```sql
SELECT first_name, salary
FROM emp
WHERE salary > (SELECT AVG(salary) FROM emp);
```

- Multi-row with IN:
```sql
SELECT first_name FROM emp
WHERE dept_id IN (SELECT dept_id FROM dept WHERE location = 'DALLAS');
```

- ANY / ALL:
```sql
-- salary greater than ANY (i.e., greater than lowest? careful)
SELECT * FROM emp WHERE salary > ANY (SELECT salary FROM emp WHERE dept_id = 20);

-- salary greater than ALL salaries in dept 20
SELECT * FROM emp WHERE salary > ALL (SELECT salary FROM emp WHERE dept_id = 20);
```

- EXISTS / NOT EXISTS (preferred for correlated checks and null-safe membership):
```sql
SELECT d.name
FROM dept d
WHERE EXISTS (
  SELECT 1 FROM emp e WHERE e.dept_id = d.dept_id AND e.salary > 6000
);
```

- Correlated subquery example:
```sql
-- find employees earning more than their department average
SELECT e.emp_id, e.first_name, e.salary
FROM emp e
WHERE e.salary > (
  SELECT AVG(salary) FROM emp WHERE dept_id = e.dept_id
);
```

Notes on IN vs EXISTS vs JOIN:
- IN may behave unexpectedly with NULLs in subquery result. EXISTS is usually safer for existence tests.
- Performance differences depend on Oracle optimizer. For anti-joins, NOT EXISTS often preferred over NOT IN.

---

6) Multi-table queries and JOINs
- ANSI JOIN syntax (recommended):
  - INNER JOIN (only matching rows)
  - LEFT OUTER JOIN (all left rows, matched right or NULL)
  - RIGHT OUTER JOIN (all right rows)
  - FULL OUTER JOIN (all rows from either side)
  - CROSS JOIN (cartesian product)
  - NATURAL JOIN (joins on same-named columns — use with caution)
- Old Oracle syntax uses (+) for outer joins — avoid it; prefer ANSI joins.

Examples:
```sql
-- Inner join
SELECT e.first_name, e.last_name, d.name AS dept_name
FROM emp e
JOIN dept d ON e.dept_id = d.dept_id;

-- Left join
SELECT e.first_name, d.name
FROM emp e
LEFT JOIN dept d ON e.dept_id = d.dept_id;

-- Multiple joins
SELECT e.first_name, m.first_name AS manager_first_name
FROM emp e
LEFT JOIN emp m ON e.manager_id = m.emp_id;
```

Joining with subqueries or derived tables:
```sql
SELECT t.dept_id, t.avg_sal
FROM (
  SELECT dept_id, AVG(salary) avg_sal FROM emp GROUP BY dept_id
) t
JOIN dept d ON t.dept_id = d.dept_id;
```

---

7) Set operations
- UNION — removes duplicates (like DISTINCT)
- UNION ALL — keeps duplicates (faster)
- INTERSECT — returns rows present in both
- MINUS — returns rows in first not in second (Oracle-specific; called EXCEPT in other DBs)
Rules:
- Number and types of columns must match and be compatible
- ORDER BY applies to final result only, use column positions or aliases

Examples:
```sql
SELECT first_name, last_name FROM emp WHERE dept_id = 10
UNION
SELECT first_name, last_name FROM emp WHERE dept_id = 30
ORDER BY last_name;

-- INTERSECT example
SELECT last_name FROM emp WHERE salary > 6000
INTERSECT
SELECT last_name FROM emp WHERE hire_date > DATE '2010-01-01';
```

---

8) Synonyms (Oracle)
- Purpose: provide alternate names for schema objects (tables, views, sequences, procedures).
- Private synonym: visible to the creating user only.
- Public synonym: visible to all users (requires CREATE PUBLIC SYNONYM privilege).
- Syntax:
```sql
-- Private
CREATE SYNONYM my_emp FOR hr.emp;

-- Public
CREATE PUBLIC SYNONYM emp FOR hr.emp;
```
- Use-cases: hide schema prefix, simplify object access, support refactoring.

---

9) Sequences (Oracle)
- Used to generate unique numeric values (commonly for primary keys).
- CREATE SEQUENCE syntax:
```sql
CREATE SEQUENCE emp_seq
  START WITH 1000
  INCREMENT BY 1
  NOCACHE
  NOCYCLE;
```
- Use NEXTVAL and CURRVAL:
```sql
INSERT INTO emp(emp_id, first_name, ...)
VALUES (emp_seq.NEXTVAL, 'Sam', ...);

-- CURRVAL returns last NEXTVAL in session
SELECT emp_seq.CURRVAL FROM DUAL;
```
- Notes: CURRVAL raises error if NEXTVAL not yet referenced in session. CACHE improves performance but may lose numbers on crash.

---

10) Views
- Virtual tables: stored SELECT statements.
- CREATE VIEW view_name AS SELECT ...
- WITH CHECK OPTION: prevents changes that would make rows disappear from view.
- Materialized views: store results physically (good for performance, support refresh).
Examples:
```sql
-- Simple view
CREATE OR REPLACE VIEW v_emp_summary AS
SELECT dept_id, COUNT(*) AS emp_count, AVG(salary) AS avg_salary
FROM emp GROUP BY dept_id;

-- Materialized view (basic)
CREATE MATERIALIZED VIEW mv_emp_summary
REFRESH FAST ON DEMAND
AS SELECT dept_id, COUNT(*) cnt, AVG(salary) avg_salary FROM emp GROUP BY dept_id;
```
- Use-case: encapsulate business logic, simplify queries, provide security (limit columns).

---

11) Indexes (performance)
- Create index to speed lookups on columns used in WHERE, JOIN, ORDER BY.
- CREATE INDEX idx_emp_dept ON emp(dept_id);
- Unique index / unique constraint ensure uniqueness.
- Function-based index (Oracle): create index on expression, e.g., UPPER(last_name)
```sql
CREATE INDEX idx_emp_lastname_upper ON emp (UPPER(last_name));
```
- Bitmap indexes: efficient for low-cardinality columns in DSS/OLAP scenarios — not ideal in OLTP with frequent DML.
- Index maintenance: inserts/updates/deletes pay overhead. Use selective columns. Use EXPLAIN PLAN to check usage.

---

12) SQL API / How to run SQL against Oracle
- Tools:
  - SQL*Plus (command-line)
  - SQLcl (modern command-line)
  - SQL Developer (GUI)
  - JDBC (Java) — use oracle.jdbc.OracleDriver and connection URL jdbc:oracle:thin:@//host:port/service
  - ODBC — use Oracle ODBC driver
  - Oracle Call Interface (OCI) — native C API
  - Oracle REST Data Services (ORDS) — expose REST endpoints for SQL/PLSQL/RESTful services
- Example JDBC snippet (conceptual):
```java
Connection conn = DriverManager.getConnection(
  "jdbc:oracle:thin:@//dbhost:1521/ORCLPDB1", "user", "pass");
PreparedStatement ps = conn.prepareStatement(
  "SELECT * FROM emp WHERE dept_id = ?");
ps.setInt(1, 20);
ResultSet rs = ps.executeQuery();
```
- Security: use bind variables (prevents SQL injection, improves parsing/reuse).
- Use SQL*Plus for quick ad-hoc; SQL Developer for development and query building.

---

13) Triggers (Oracle)
- Trigger types: BEFORE/AFTER, FOR EACH ROW (row-level) or statement-level.
- Use :NEW and :OLD in row triggers to access changed values.
- Common uses: populate primary key using sequence, audit changes, enforce complex constraints.
- Example: auto-generate emp_id using sequence
```sql
CREATE SEQUENCE emp_seq START WITH 1000 INCREMENT BY 1;

CREATE OR REPLACE TRIGGER trg_emp_bi
BEFORE INSERT ON emp
FOR EACH ROW
BEGIN
  IF :NEW.emp_id IS NULL THEN
    :NEW.emp_id := emp_seq.NEXTVAL;
  END IF;
END;
/
```
- Audit trigger example (row-level AFTER INSERT):
```sql
CREATE TABLE emp_audit (
  aud_id NUMBER PRIMARY KEY,
  emp_id NUMBER,
  operation VARCHAR2(10),
  op_date DATE,
  changed_by VARCHAR2(30)
);

CREATE SEQUENCE aud_seq START WITH 1;

CREATE OR REPLACE TRIGGER trg_emp_audit
AFTER INSERT OR UPDATE OR DELETE ON emp
FOR EACH ROW
BEGIN
  IF INSERTING THEN
    INSERT INTO emp_audit (aud_id, emp_id, operation, op_date, changed_by)
    VALUES (aud_seq.NEXTVAL, :NEW.emp_id, 'INSERT', SYSDATE, USER);
  ELSIF UPDATING THEN
    INSERT INTO emp_audit (aud_id, emp_id, operation, op_date, changed_by)
    VALUES (aud_seq.NEXTVAL, :NEW.emp_id, 'UPDATE', SYSDATE, USER);
  ELSIF DELETING THEN
    INSERT INTO emp_audit (aud_id, emp_id, operation, op_date, changed_by)
    VALUES (aud_seq.NEXTVAL, :OLD.emp_id, 'DELETE', SYSDATE, USER);
  END IF;
END;
/
```
- Caution: avoid expensive logic inside row-level triggers. Triggers can complicate debugging and performance.

---

14) Additional Oracle features worth knowing
- Analytic functions (OVER(): ROW_NUMBER, RANK, SUM() OVER()): useful for "grouped" computations without collapsing rows.
```sql
SELECT emp_id, first_name, salary,
       AVG(salary) OVER (PARTITION BY dept_id) AS dept_avg,
       ROW_NUMBER() OVER (PARTITION BY dept_id ORDER BY salary DESC) AS rn
FROM emp;
```
- WITH clause (common table expressions — CTEs):
```sql
WITH dept_avg AS (
  SELECT dept_id, AVG(salary) avg_sal FROM emp GROUP BY dept_id
)
SELECT e.first_name, e.salary, d.avg_sal
FROM emp e JOIN dept_avg d ON e.dept_id = d.dept_id;
```
- Flashback query, RMAN, partitioning, etc. are advanced topics.

---

15) Tips & best practices
- Always use bind variables in application code.
- Prefer ANSI JOIN syntax over Oracle (+) syntax.
- Use EXISTS for correlated-existence tests; NOT EXISTS over NOT IN when subquery might return NULLs.
- Use explain plan / autotrace to check query plans.
- Create indexes on selective columns and for columns used in JOINs/WHERE/ORDER BY.
- Avoid SELECT * in production queries; list only needed columns.
- Keep logic deterministic in triggers; they execute on every row or statement.

---

16) Exercises (with answers)


Exercise 1:
- Query: List employees earning more than department average.
Solution:
```sql
SELECT e.*
FROM emp e
WHERE e.salary > (SELECT AVG(salary) FROM emp WHERE dept_id = e.dept_id);
```

Exercise 2:
- Query: Count employees by department and show only depts with >1 employee, ordered by count desc.
Solution:
```sql
SELECT dept_id, COUNT(*) cnt
FROM emp
GROUP BY dept_id
HAVING COUNT(*) > 1
ORDER BY cnt DESC;
```

Exercise 3:
- Query: Return departments that have no employees (use NOT EXISTS).
Solution:
```sql
SELECT d.*
FROM dept d
WHERE NOT EXISTS (SELECT 1 FROM emp e WHERE e.dept_id = d.dept_id);
```

Exercise 4:
- Query: Get top 3 highest-paid employees per department (use analytic functions).
Solution:
```sql
SELECT emp_id, first_name, dept_id, salary
FROM (
  SELECT e.*,
         ROW_NUMBER() OVER (PARTITION BY dept_id ORDER BY salary DESC) rn
  FROM emp e
) WHERE rn <= 3;
```

Exercise 5:
- Create a sequence for order IDs starting at 10000 and use it in insert.
Solution:
```sql
CREATE SEQUENCE order_seq START WITH 10000 INCREMENT BY 1 CACHE 20;
INSERT INTO orders (order_id, ...) VALUES (order_seq.NEXTVAL, ...);
```

Exercise 6:
- Create view showing department name and its average salary.
Solution:
```sql
CREATE OR REPLACE VIEW v_dept_avg AS
SELECT d.dept_id, d.name, NVL(AVG(e.salary),0) avg_salary
FROM dept d
LEFT JOIN emp e ON d.dept_id = e.dept_id
GROUP BY d.dept_id, d.name;
```

Exercise 7:
- Explain difference between UNION and UNION ALL.
Solution:
- UNION removes duplicates (performs implicit DISTINCT). UNION ALL keeps duplicates and is faster.

Exercise 8:
- Write a trigger to set emp.hire_date to SYSDATE when inserting if not provided.
Solution:
```sql
CREATE OR REPLACE TRIGGER trg_emp_bi_hiredate
BEFORE INSERT ON emp
FOR EACH ROW
BEGIN
  IF :NEW.hire_date IS NULL THEN
    :NEW.hire_date := SYSDATE;
  END IF;
END;
/
```

Exercise 9:
- Show how to create a function-based index on upper(last_name).
Solution:
```sql
CREATE INDEX idx_emp_upper_lastname ON emp (UPPER(last_name));
```

Exercise 10:
- Using EXISTS vs IN: which is safer when subquery may return NULLs?
Solution:
- EXISTS is safer. IN may fail to match results if subquery returns NULL (e.g., val IN (1, NULL) yields unknown).

---

17) Quick reference: common patterns & pitfalls
- Paginate: OFFSET ... FETCH (12c+) or ROWNUM-based subquery for older versions.
- Avoid "WHERE column = (SELECT ...)" if subquery returns multiple rows — use IN or aggregation to force single value.
- NULL handling: comparisons with NULL return UNKNOWN; use IS NULL.
- Be careful with NOT IN: if subquery returns NULL, NOT IN returns no rows; NOT EXISTS is null-safe.

---

Further study recommendations
- Oracle SQL Language Reference (official docs)
- Oracle Database Performance Tuning Guide — for index and optimizer behavior
- Practice with EXPLAIN PLAN / DBMS_XPLAN.DISPLAY_CURSOR
- Learn analytic functions in depth (RANK, DENSE_RANK, LAG, LEAD, SUM() OVER())

---

If you want:
- Generate printable cheat-sheet PDF from this content.
- Create a set of SQL scripts you can load into an Oracle instance to practice (DDL + test data + answers).
- Provide more advanced examples: partitioning, materialized view refresh strategies, optimizer hints, or PL/SQL to wrap complex logic.
