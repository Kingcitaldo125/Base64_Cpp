'''
Write out the Base64 table mapping, in string form, to a file.
Map syntax aligns with the initializer list syntax for a C++ std::map<std::string,std::string>.
Usage should pretty much be copy/paste from the file into C++ source.
https://en.wikipedia.org/wiki/Base64#Base64_table
writer.py
'''

f=open('encode.txt','w')
i = 0
ctr = 1
mult = 4

mapping = {}

for j in [k for k in range(ord('A'), ord('Z') + 1)]:
  key = f'{i:06b}'
  val = str(chr(j))
  mapping[key] = val

  f.write("{"+f'"{i:06b}",\"'+val+"\"},")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i += 1

for j in [k for k in range(ord('a'), ord('z') + 1)]:
  key = f'{i:06b}'
  val = str(chr(j))
  mapping[key] = val

  f.write("{"+f'"{i:06b}",\"'+str(chr(j))+"\"},")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i += 1

for j in range(0, 10):
  key = f'{i:06b}'
  val = str(j)
  mapping[key] = val

  f.write("{"+f'"{i:06b}",\"'+str(j)+"\"},")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i += 1

key = f'{i:06b}'
f.write("{"+f'"{i:06b}"'+',"+"'+"},")
mapping[key] = '+'

i += 1

key = f'{i:06b}'
f.write("{"+f'"{i:06b}"'+',"/"'+"}")
mapping[key] = '/'

f.write("\n")
f.flush()
f.close()

# Write out the reverse mapping (for decoding Base64)
f=open('decode.txt','w')
mapping_decode = {v:k for k,v in mapping.items()}

ctr = 1
mult = 4
i=0
for k,v in mapping_decode.items():
  f.write("{"+f'"{k}",\"'+v+"\"}," if i < len(mapping_decode)-1 else "{"+f'"{k}",\"'+v+"\"}")
  if ctr == mult:
    f.write("\n")
    ctr = 0
  ctr += 1
  i+=1

f.flush()
f.close()
