import glob
import os

cpps = glob.glob("cpp/**/*.cpp")
for cpp in cpps:
    print(cpp)
    code = ["#include <bits/stdc++.h>\nusing namespace std;\n"]
    with open(cpp) as f:
        code += f.readlines()
    with open("a.cpp", "w") as f:
        f.writelines(code)
    cmd = "g++ a.cpp -std=c++20"
    os.system(cmd)
