"""
This is a little program write in Python3, it needs those libs (imports)
to function correcly.

His objectives are to plot the data generated by his C++ friends

MIT License
"""

import matplotlib.pyplot as plt     # For plotting the data
import glob                         # for discovering files inside some folder
import os                           # ''
import sys                          # getting argc and argv parameters
import re                           # using regex to extract names


def treatName(filepath):
    """
    A function to extract only the name of the file from the filepath
    """
    name = re.split(r'\.*', filepath)
    return name[0]


def indexFinder(element, cameFrom):
    """
    A function to find the correspondent index from a <element>
    inside a <cameFrom> list
    """
    i = 0
    while element != cameFrom[i]:
        i += 1
    return i


def indexToPick(string):
    """
    This function interpretates a given binary string, and tells wich indexes
    were selected
    """
    indexes = []
    for i, char in zip(range(len(string)), string):
        if(char == '1' and len(indexes) < 2):
            indexes.append(i)
    return indexes


def cjoin(sequence):
    """
    This function just join a x: elements from a array
    onto one string
    """
    final_string = ""
    for word in sequence:
        final_string += " " + str(word)
    return final_string


try:
    files_to_work = str(sys.argv[1])
    work_columns = str(sys.argv[2])
    plot_title = cjoin(sys.argv[3:])
except IndexError:
    print("Please, use:")
    print("python3 src/plot.py <param1> <param2> <plot_title>")
    print()
    print("param1/param2 are binary strings, that tells witch ")
    print("algorithms/columns will be processed.")
    print()
    exit()

selected_columns = indexToPick(work_columns)  # Converts binary string to index

data = {}
os.chdir("data/")

extension = '*'

for file in glob.glob(extension):
    # Collect data from $extension files
    if files_to_work[indexFinder(file, glob.glob(extension))] == str(1):
        # finds if the user wants this file to be processed or nah
        with open(file, 'r') as content:
            for dat in content:
                # Throw brute data (all columns) to the $data variable
                try:
                    data[str(file)].append(dat[:-1].split(' '))
                except KeyError:
                    data[str(file)] = []
                    data[str(file)].append(dat[:-1].split(' '))

fil_data = {}  # filtered data

for filename in data:
    # here, the data get's converted to the correct types
    fil_data[filename] = {'x': [], 'y': []}
    for lines in data[filename]:
        fil_data[filename]['x'].append(float(lines[selected_columns[0]]))
        fil_data[filename]['y'].append(float(lines[selected_columns[1]]))

fig = plt.figure()
ax1 = plt.subplot2grid((1, 1), (0, 0))
ax1.grid(True, color="#E1E1E1", linewidth=1)

for file in fil_data:

    x_axis = fil_data[file]['x']  # x indices
    y_axis = fil_data[file]['y']  # y indices

    # Add these axis to the plot
    ax1.plot(x_axis, y_axis, label=str(treatName(file)))

# then set the variables
if(len(plot_title) > 0):
    plt.title(plot_title)
else:
    plt.title('Visual comparison of the Algorithms')

plt.subplots_adjust(left=0.17, bottom=0.13, right=0.93, top=0.93)
plt.ylabel('Time (in nanoseconds)')
plt.xlabel('Elements of the array')
plt.legend()
plt.show()
