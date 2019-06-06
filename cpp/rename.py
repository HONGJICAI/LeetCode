import shutil
import os


files = os.listdir(os.path.dirname(__file__))
files = list(filter(lambda f:" " in f,files))

for f in files:
	newname = "".join(f.title().split(" "))
	if not newname.endswith(".cpp"):
		newname += ".cpp"
	print(f,"=>",newname)
	shutil.move(f,newname)