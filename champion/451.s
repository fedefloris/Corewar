.name "451"
.comment "Unavailable For Legal Reasons"

		aff r1
		sti r1, %:legal, %1
		and r1, %0, r1

legal:	live %1
		zjmp %:legal
