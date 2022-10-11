
import os
a = input()
b = input()


prefix = os.path.commonprefix([a,b])

print( len(a) + len(b) - 2*len(prefix)  )