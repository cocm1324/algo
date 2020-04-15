def strsft(s, shift):
	sftAmount = 0

	for el in shift:
		if el[0] == 0:
			sftAmount += el[1]
		else:
			sftAmount -= el[1]
	
	sftAmount %= len(s)
	return s[sftAmount:] + s[:sftAmount]

s = "ifjqiwoeqg"
sft=[[1,3],[0,4],[1,1],[1,3]]
r = strsft(s, sft)
print(r)
