'''
Write out the Base64 table mapping, in string form, to a file.
Map syntax aligns with the initializer list syntax for a C++ std::map<std::string,std::string>.
Usage should pretty much be copy/paste from the file into C++ source.
https://en.wikipedia.org/wiki/Base64#Base64_table
writer.py
'''

f=open('out.txt','w')
i = 0
ctr = 1
mult = 4

for j in [k for k in range(ord('A'), ord('Z') + 1)]:
  f.write("{"+f'"{i:06b}",\"'+str(chr(j))+"\"},")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i += 1

for j in [k for k in range(ord('a'), ord('z') + 1)]:
  f.write("{"+f'"{i:06b}",\"'+str(chr(j))+"\"},")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i += 1

for j in range(0, 10):
  f.write("{"+f'"{i:06b}",\"'+str(j)+"\"},")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i += 1

f.write("{"+f'"{i:06b}"'+',"+"'+"},")
i += 1
f.write("{"+f'"{i:06b}"'+',"/"'+"}")

f.flush()
f.close()
