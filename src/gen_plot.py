from itertools import permutations
import os

def genBinStr(sequence):
    binstr = ""
    for element in sequence:
        binstr += str(element)
    return binstr

command_list = set(list(permutations([1,0,0,0,0,0,0])))

command_header = "python3 src/plot.py"

default_params = [
   "1010", 
   "1001"
]

for order in command_list:
    binstr = genBinStr(order)
    for param in default_params:
        print()
        # print("Running:", command_header, binstr, param, "Nenhum Texto")
        os.system(command_header + " " + binstr + " " + param + " " + "Nenhum Texto")
