SELECT name
FROM Customer
WHERE referee_id!= 2 OR referee_id is null;

/*where IFNULL(referee_id,0)!=2 */