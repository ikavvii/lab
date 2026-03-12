CREATE TABLE products (
    id NUMBER PRIMARY KEY,
    name VARCHAR2(20) NOT NULL UNIQUE,
    category VARCHAR2(50),
    price NUMBER NOT NULL
);

CREATE TABLE customers (
    id NUMBER PRIMARY KEY,
    name VARCHAR2(20) NOT NULL,
    city VARCHAR2(20) NOT NULL
);

CREATE TABLE orders (
    id NUMBER PRIMARY KEY,
    customer_id NUMBER NOT NULL,
    product_id NUMBER NOT NULL,
    quantity NUMBER NOT NULL,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT fk_customer FOREIGN KEY (customer_id) REFERENCES customers(id),
    CONSTRAINT fk_product FOREIGN KEY (product_id) REFERENCES products(id)
);

CREATE SEQUENCE products_seq START WITH 1 INCREMENT BY 1;
CREATE SEQUENCE customers_seq START WITH 1 INCREMENT BY 1;
CREATE SEQUENCE orders_seq START WITH 1 INCREMENT BY 1;

CREATE OR REPLACE TRIGGER products_trigger
BEFORE INSERT ON products
FOR EACH ROW
BEGIN
    :NEW.id := products_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER customers_trigger
BEFORE INSERT ON customers
FOR EACH ROW
BEGIN
    :NEW.id := customers_seq.NEXTVAL;
END;
/

CREATE OR REPLACE TRIGGER orders_trigger
BEFORE INSERT ON orders
FOR EACH ROW
BEGIN
    :NEW.id := orders_seq.NEXTVAL;
END;
/

--- 

DROP TRIGGER products_trigger;
DROP TRIGGER customers_trigger;
DROP TRIGGER orders_trigger;

DROP TABLE products;
drop table customers;
drop table orders;

commit;