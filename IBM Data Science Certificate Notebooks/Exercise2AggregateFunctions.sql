--Exercise 2: Aggregate functions--
--Enter a function that calculates the total cost of all amnimal rescues in the PETRESCUE table.--
SELECT SUM(COST) FROM PETRESCUE;

--Enter a function that displays the total cost of all animal rescues in the PETRESCUE table in a column called SUM_OF_COST.
SELECT SUM(COST) AS SUM_OF_COST FROM PETRESCUE;

--Enter a function that displays the maximum quantity of animals rescued.--
SELECT MAX(QUANTITY) FROM PETRESCUE;

--Enter a function that displays the average cost of animals rescued.--
SELECT AVG(COST) FROM PETRESCUE;

--Enter a function that displays the average cost of rescuing a dog.--
SELECT AVG(COST) FROM PETRESCUE 
WHERE ANIMAL = 'Dog';

--Exercise 3: Scalar and String functions--
--Enter a function that displays the the rounded cost of each rescue.--
SELECT ROUND(COST) FROM PETRESCUE;

--Enter a function that displays the length of each animal name--
SELECT LENGTH(ANIMAL) FROM PETRESCUE;

--Enter a function that displays the animal name in each rescue in uppercase.--
SELECT UPPER(ANIMAL) FROM PETRESCUE;

--Enter a function that displays the animal name in each rescue in uppercase without duplications
SELECT DISTINCT UPPER(ANIMAL) FROM PETRESCUE;

--Enter a query that displays all the column from the PETRESCUE table, where the animals recued are cats. use cat in lower case in the query.
SELECT * FROM PETRESCUE 
WHERE LOWER(ANIMAL) = 'cat';

--Exercise 4; Date and time functions--
--Enter a function that displays the day of the month when cats have been rescued.--
SELECT DAY(RESCUEDATE) FROM PETRESCUE 
WHERE ANIMAL = 'Cat';

--Enter a function that displays the number of rescues on the 5th month.
SELECT COUNT(*) FROM PETRESCUE 
WHERE MONTH(RESCUEDATE) = 5;

--Enter a function that displays the number of rescues on the 14th day of the month.
SELECT * FROM PETRESCUE 
WHERE DAY(RESCUEDATE) = 14;

--Animals rescued should see the vet within three days of arrivals. Enter a function that displays the third day from each rescue.
SELECT (RESCUEDATE + 3 DAYS) FROM PETRESCUE;

--Enter a function that displays the length of time the animals have been rescued; the difference between today’s date and the rescue date.
SELECT (CURRENT_DATE - RESCUEDATE) FROM PETRESCUE;