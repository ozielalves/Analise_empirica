import matplotlib.pyplot as plt     # For plotting the data
import os   # For getting files inside the directory
import sys  # Same

datadir = "data/"
filenames = os.listdir(datadir)
filenames.sort()

print("Dir order:")
print(filenames)
x_label = "Número de Elementos"
y_label = "Tempo em Nanosegundos"

# ======================================= BEGIN OF FUNCTION SECTION ============

def makeTitle(sequence):
    # Unites a list of words into one
    final_string = ""
    for word in sequence:
        print("word:", word, "obtained")
        final_string += " " + str(word)
        print("Final string now is:", final_string)

    print("returning:",final_string)
    return final_string

def convertBin(binstr):
    # Convert the binary string into indexes
    files_list = []
    counter = range(len(binstr))
    for char, index in zip(binstr, counter):
        if(int(char) == True):
            files_list.append(str(index+1))
    return files_list


def readData(filename):
    # Read all the data from <filename> into lists
    data = open(filename, 'r')
    data_filtered = []
    for line in data:
        line = line.split(" ")
        line_filtered = []
        for number in line:
           line_filtered.append(float(number))
        data_filtered.append(line_filtered)
    return data_filtered

def HaveToRead(filename, process_files):
    # Tells if we have to read that file or not
    index_of_filename = int(filename[0])
    if index_of_filename in process_files:
        return True
    else:
        return False


# ======================================= END OF FUNCTION SECTION ============

try:
    files_to_work = str(sys.argv[1])
    columns_to_work = str(sys.argv[2])
    plot_title = sys.argv[3:]

except IndexError:
    print("Error, please read the documentation")
    exit()

process_files = convertBin(files_to_work)
process_columns = convertBin(columns_to_work)

if len(process_columns) > 2:
    # If the user wants to plot more than 2 axis (columns)
    print("Sorry, you have to choose one two columns on parameter 2.")
    print("Ex: 1010, 1100, 1001..")
    print("Please, try again.")

# Starting to create a plot figure
fig = plt.figure()
ax1 = plt.subplot2grid((1, 1), (0, 0))
ax1.grid(True, color="#E1E1E1", linewidth=1)

for file in filenames:
    if file[0] in process_files:
        print("Reading data from:", file)
        filedata = readData(datadir + file)

        # Corrects the index and makes things pretty
        x = int(process_columns[0]) - 1
        y = int(process_columns[1]) - 1

        plot_x = []
        plot_y = []

        for line in filedata:
            plot_x.append(float(line[x]))
            plot_y.append(float(line[y]))

        # And then, finally plot
        ax1.plot(plot_x, plot_y, label=file[2:-4])

# Some configs to the figure
plt.title(makeTitle(plot_title))
plt.subplots_adjust(left=0.17, bottom=0.13, right=0.93, top=0.93)
# If you want to change x_label and y_label titles, just type gg (vim power)
plt.ylabel(y_label)
plt.xlabel(x_label)

plt.legend()
try:
    plt.show()
    print("Showing Graphics")
except KeyboardInterrupt:
    exit()
