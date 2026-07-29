-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Crime scene to seek out Time: July 28, 2025, Place: Humphrey Street.
select id, description from crime_scene_reports
where year = 2025 and month = 7 and day = 28 and street = 'Humphrey Street';

--295 | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present at the
--time – each of their interview transcripts mentions the bakery.

-- See interview log
select transcript from interviews
where year = 2025 and month = 7 and day = 28;

--| Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot
--and drive away. If you have security footage from the bakery parking lot, you might want to look for
--cars that left the parking lot in that time frame.
-- See bakery security log at 10:15am - 10:25am
select license_plate from bakery_security_logs
where year = 2025 and month = 7 and day = 28 and hour = 10 and minute >= 15 and minute <= 25 and activity = 'exit';

--| I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived
--at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Check transaction
select account_number from atm_transactions
where year = 2025 and month = 7 and day = 28 and atm_location = 'Leggett Street';

--| As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville
--tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

--Phone call less than a minute
select caller, receiver, duration from phone_calls
where year = 2025 and month = 7 and day = 28 and duration <= 60;

--Take a take a flight from Fiftyville on 29/7/2025, latest
select passport_number from passengers p
join flights f on f.id = p.flight_id
join airports a on a.id = f.origin_airport_id
where f.year = 2025 and f.month = 7 and f.day = 29 and a.city = 'Fiftyville'
order by hour, minute limit 5;

--Find the thief
select pe.name, pe.phone_number, pe.passport_number from people pe
join bank_accounts b on b.person_id = pe.id
where pe.phone_number in(select caller from phone_calls
                        where year = 2025 and month = 7 and day = 28 and duration <= 60)
and passport_number in(select passport_number from passengers p
                        join flights f on f.id = p.flight_id
                        join airports a on a.id = f.origin_airport_id
                        where f.year = 2025 and f.month = 7 and f.day = 29 and a.city = 'Fiftyville'
                        order by hour, minute limit 5)
and license_plate in(select license_plate from bakery_security_logs
where year = 2025 and month = 7 and day = 28 and hour = 10 and minute >= 15 and minute <= 25 and activity = 'exit')
and b.account_number in (select account_number from atm_transactions
                        where year = 2025 and month = 7 and day = 28 and atm_location = 'Leggett Street');
--+-------+----------------+-----------------+
--| name  |  phone_number  | passport_number |
--+--------+----------------+-----------------+
--| Bruce | (367) 555-5533 | 5773159633      |
--+-------+----------------+-----------------+

--City
select a.city from airports a
join flights f on f.destination_airport_id = a.id
join passengers p on p.flight_id = f.id
where f.year = 2025 and f.month = 7 and f.day = 29 and p.passport_number = '5773159633';

-- the Accomplish:
select receiver from phone_calls
where year = 2025 and month = 7 and day = 28 and duration <= 60 and caller = '(367) 555-5533';

--(375) 555-8161

select name from people
where phone_number = '(375) 555-8161';

--The THIEF is: Bruce
--The city the thief ESCAPED TO: New York City
--The ACCOMPLICE is: Robin

