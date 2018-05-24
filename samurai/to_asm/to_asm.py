f_in = open("in", "r")
f_out = open("out", "w")
lines = f_in.readlines()

for line in lines:
	if line == "specialsetup:\n":
		f_out.write('void setup(){\n')
	elif line == "specialsetup}\n":
		f_out.write('}\n')
	elif line == "specialloop:\n":
		f_out.write('void loop(){\n')
	elif line == "specialloop}\n":
		f_out.write('}\n')
	elif line == "\n":
		f_out.write('\n')
	else:
		f_out.write('asm("' + line[:-1] + '");\n')

# print(lines)

f_in.close()
f_out.close()
