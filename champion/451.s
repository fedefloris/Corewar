.name "451"
.comment "Unavailable For Legal Reasons"

start:	sti r1, %:live, %1
		sti r1, %:live, %6
		sti r1, %:live, %11
		sti r1, %:live, %16
		sti r1, %:live, %21
		sti r1, %:live, %26
		sti r1, %:live, %31
		sti r1, %:live, %36
		sti r1, %:live, %41
		sti r1, %:live, %46

live:	live %451
		live %451
		live %451
		live %451
		live %451
		live %451
		live %451
		live %451
		live %451
		live %451
		zjmp %:live
