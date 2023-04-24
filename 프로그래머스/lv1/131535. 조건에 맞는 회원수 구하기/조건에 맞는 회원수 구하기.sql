-- 코드를 입력하세요
SELECT COUNT(
    case
        when age >= 20 and age <= 29 then 1
    end
) as USERS
FROM USER_INFO
where YEAR(JOINED) = 2021