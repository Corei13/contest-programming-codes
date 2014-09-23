#!/usr/bin/env python
import os, sys, shutil
if len(sys.argv) >= 2:
	fname = 'UVA/'+sys.argv[1]+'.cpp'
else:
	print 'Problem?',
	fname = 'UVA/'+raw_input()+'.cpp'

if os.path.isfile(fname):
	print fname, 'exists!'
	if len(sys.argv) >= 3 and sys.argv[2] == '-f':
		print 'overriding..'
	else:
		sys.exit()

shutil.copyfile('A.cpp', fname)

