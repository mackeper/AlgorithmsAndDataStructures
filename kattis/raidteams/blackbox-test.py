# dotnet publish -c Release -r ubuntu.18.04-x64
import os
import random
import string
import subprocess

script_dir = os.path.dirname(__file__) #<-- absolute dir the script is in
tmp_test_file = "test.in"
exe1 = os.path.join(script_dir, "bin/Release/netcoreapp3.1/ubuntu.18.04-x64/raidteams")
exe2 = os.path.join(script_dir, "a.out")



N = random.randint(3, 100000)
name_length = random.randint(1, 10)
used_names = {}
for i in range(100):
    print("[{}%] {}\r".format(round((i/100)*100), ['-','\\', '|', '/'][i%4]), end="")
    with open(tmp_test_file, 'w') as f:
        f.write(f"{N}\n")
        for n in range(N):

            name = ''.join(random.choices(string.ascii_uppercase + string.digits, k=name_length))
            while name in used_names:
                name = ''.join(random.choices(string.ascii_uppercase + string.digits, k=name_length))
            used_names[name] = 1

            a = random.randint(0, 2000000000)
            b = random.randint(0, 2000000000)
            c = random.randint(0, 2000000000)
            f.write(f"{name} {a} {b} {c}\n")

    os.system(f'./{exe2} < test.in > 1.out')
    os.system(f'./{exe1} < test.in > 2.out')
    cmd = ["diff", "1.out", "2.out"]
    subprocess.check_output(["diff", "1.out", "2.out"])
