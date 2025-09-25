-- Keep a log of any SQL queries you execute as you solve the mystery.
--CREATE TABLE crime_scene_reports (
--    id INTEGER,
--    year INTEGER,
--    month INTEGER,
--    day INTEGER,
--    street TEXT,
--    description TEXT,
--    PRIMARY KEY(id)
--);
--CREATE TABLE interviews (
--    id INTEGER,
--    name TEXT,
--    year INTEGER,
--    month INTEGER,
--    day INTEGER,
--    transcript TEXT,
--    PRIMARY KEY(id)
--);
--CREATE TABLE atm_transactions (
--    id INTEGER,
--    account_number INTEGER,
--    year INTEGER,
--    month INTEGER,
--    day INTEGER,
--    atm_location TEXT,
--    transaction_type TEXT,
--    amount INTEGER,
--    PRIMARY KEY(id)
--);
--CREATE TABLE bank_accounts (
--    account_number INTEGER,
--    person_id INTEGER,
--    creation_year INTEGER,
--    FOREIGN KEY(person_id) REFERENCES people(id)
--);
--CREATE TABLE airports (
--    id INTEGER,
--    abbreviation TEXT,
--    full_name TEXT,
--    city TEXT,
--    PRIMARY KEY(id)
--);
--CREATE TABLE flights (
--    id INTEGER,
--    origin_airport_id INTEGER,
--    destination_airport_id INTEGER,
--    year INTEGER,
--    month INTEGER,
--    day INTEGER,
--    hour INTEGER,
--    minute INTEGER,
--    PRIMARY KEY(id),
--    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
--    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
--);
--CREATE TABLE passengers (
--    flight_id INTEGER,
--    passport_number INTEGER,
--    seat TEXT,
--    FOREIGN KEY(flight_id) REFERENCES flights(id)
--);
--CREATE TABLE phone_calls (
--    id INTEGER,
--    caller TEXT,
--    receiver TEXT,
--    year INTEGER,
--    month INTEGER,
--    day INTEGER,
--    duration INTEGER,
--    PRIMARY KEY(id)
--);
--CREATE TABLE people (
--    id INTEGER,
--    name TEXT,
--    phone_number TEXT,
--    passport_number INTEGER,
--    license_plate TEXT,
--    PRIMARY KEY(id)
--);
--CREATE TABLE bakery_security_logs (
--    id INTEGER,
--    year INTEGER,
--    month INTEGER,
--    day INTEGER,
--    hour INTEGER,
--    minute INTEGER,
--    activity TEXT,
--    license_plate TEXT,
--    PRIMARY KEY(id)
--);
SELECT id, description FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

SELECT transcript FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;

--“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
--“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.
--Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.
--Conclusion: The thief left between 10:15 and 10:25. He called someone after committing his crime, the call lasted less than a minute. Before the crime, the thief withdrew some money at Legget Street.

SELECT license_plate, id FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <= 25;
--+---------------+-----+
--| license_plate | id  |
--+---------------+-----+
--| 5P2BI95       | 260 |
--| 94KL13X       | 261 |
--| 6P58WS2       | 262 |
--| 4328GD8       | 263 |
--| G412CB7       | 264 |
--| L93JTIZ       | 265 |
--| 322W7JE       | 266 |
--| 0NTHK55       | 267 |
--+---------------+-----+

SELECT name, phone_number FROM people
WHERE license_plate IN(
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
);
--+---------+----------------+
--|  name   |  phone_number  |
--+---------+----------------+
--| Vanessa | (725) 555-4692 |
--| Barry   | (301) 555-4174 |
--| Iman    | (829) 555-5269 |
--| Sofia   | (130) 555-0289 |
--| Luca    | (389) 555-5198 |
--| Diana   | (770) 555-1861 |
--| Kelsey  | (499) 555-9472 |
--| Bruce   | (367) 555-5533 |
--+---------+----------------+
--people who left the bakery in 10 minutes.
SELECT caller, receiver FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60;
--+----------------+----------------+
--|     caller     |    receiver    |
--+----------------+----------------+
--| (130) 555-0289 sofia| (996) 555-8899 |
--| (499) 555-9472 kelsey| (892) 555-8872 |
--| (367) 555-5533 bruce| (375) 555-8161 |
--| (499) 555-9472 kelsey| (717) 555-1342 |
--| (286) 555-6063 | (676) 555-6554 |
--| (770) 555-1861 diana| (725) 555-3243 |
--| (031) 555-6622 | (910) 555-3251 |
--| (826) 555-1652 | (066) 555-9701 |
--| (338) 555-6650 | (704) 555-2131 |
------------------+----------------+

SELECT name FROM people
WHERE phone_number IN
(
    SELECT caller FROM phone_calls
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND duration < 60)

AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25);

--+--------+
--|  name  |
--+--------+
--| Sofia  |
--| Diana  |
--| Kelsey |
--| Bruce  |
--+--------+

SELECT account_number FROM atm_transactions
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

--+----------------+
--| account_number |
--+----------------+
--| 28500762       |
--| 28296815       |
--| 76054385       |
--| 49610011       |
--| 16153065       |
--| 25506511       |
--| 81061156       |
--| 26013199       |
--+----------------+

SELECT bank_accounts.account_number, people.name FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE people.name = 'Sofia'
OR people.name = 'Diana'
OR people.name = 'Kelsey'
OR people.name = 'Bruce';

--+----------------+-------+
--| account_number | name  |
--+----------------+-------+
--| 49610011       | Bruce |
--| 26013199       | Diana |
--+----------------+-------+

SELECT id, origin_airport_id, destination_airport_id FROM flights
WHERE year = 2023
AND month = 7
AND day = 29
ORDER BY hour ASC, minute ASC;
--+----+-------------------+------------------------+
--| id | origin_airport_id | destination_airport_id |
--+----+-------------------+------------------------+
--| 36 | 8                 | 4                      |
--| 43 | 8                 | 1                      |
--| 23 | 8                 | 11                     |
--| 53 | 8                 | 9                      |
--| 18 | 8                 | 6                      |
--+----+-------------------+------------------------+

SELECT people.name FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = 36;

--+--------+
--|  name  |
--+--------+
--| Doris  |
--| Sofia  |
--| Bruce  |
--| Edward |
--| Kelsey |
--| Taylor |
--| Kenny  |
--| Luca   |
--+--------+

SELECT name FROM people
WHERE phone_number = '(375) 555-8161';
--this number is linked with bruce's number (line 165)
--+-------+
--| name  |
--+-------+
--| Robin |
--+-------+
SELECT city FROM airports
WHERE id = 4;
--+---------------+
--|     city      |
--+---------------+
--| New York City |
--+---------------+
