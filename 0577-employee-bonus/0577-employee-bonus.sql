select em.name ,b.bonus as bonus from
     employee em left join bonus b on em.empId = b.empId
     where b.bonus < 1000 or b.bonus is null ;
