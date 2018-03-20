import matplotlib.pyplot as plt     # For plotting the data
import os   # For getting files inside the directory
import sys  # Same

showGraphic = False

datadir = "data/"
imagedir = "images/"
os.system("mkdir " + imagedir)

filenames = os.listdir(datadir)
filenames.sort()

if ".DS_Store" == filenames[0]:
    del filenames[0]

print("Dir order:")
print(filenames)

# ===================================== BEGIN OF FUNCTION SECTION ============


def genFileName(names, bin_columns, extension):
    final_filename = ""

    for name in names:
        final_filename += str(name[:-4]) + "_"
    for char in bin_columns:
        final_filename += str(char)

    final_filename += str(extension)

    return final_filename

#  def genPlotTitle(bin_files, filenames):
#

def makeTitle(sequence):
    # Unites a list of words into one
    final_string = ""

    for word in sequence:
        final_string += " " + str(word)

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

def setName(number):
    number = int(number)
    names = [
        "buf",
        "Número de Elementos",
        "Número de vezes testadas",
        "Tempo médio gasto (em segundos)",
        "Iterações"
    ]
    return names[number]


# ======================================= END OF FUNCTION SECTION ============

try:
    files_to_work = str(sys.argv[1])
    columns_to_work = str(sys.argv[2])
    save_path = str(sys.argv[3])
    plot_title = sys.argv[4:]

except IndexError:
    print("Error, please read the documentation")
    exit()

process_files = convertBin(files_to_work)
#  print("~ Debug Print:")
#  print("\tfiles_to_work:")
#  print("\t", files_to_work)
#  print("\tprocess_files:")
#  print("\t", process_files)

process_columns = convertBin(columns_to_work)
#  print("\tprocess_columns:")
#  print("\t", process_columns)

if len(process_columns) > 2:
    # If the user wants to plot more than 2 axis (columns)
    print("Sorry, you have to choose one two columns on parameter 2.")
    print("Ex: 1010, 1100, 1001..")
    print("Please, try again.")

# Starting to create a plot figure
fig = plt.figure()
ax1 = plt.subplot2grid((1, 1), (0, 0))
ax1.grid(True, color="#E1E1E1", linewidth=1)

names_worked = []
files_worked = []

for file in filenames:
    if file[0] in process_files:
        print("Reading data from:", file)

        names_worked.append(file)
        files_worked.append(file[2:-4])

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
#  if(len(plot_title) > 1):
    #  plt.title(makeTitle(plot_title))
#  else:
    #  plt.title(makeTitle(plot_title))

plt.subplots_adjust(left=0.17, bottom=0.13, right=0.93, top=0.93)

plt.xlabel(setName(process_columns[0]))
plt.ylabel(setName(process_columns[1]))

outFilename = genFileName(names_worked, process_columns, ".png")
plt.legend()

try:
    print("Showing Graphics")
    plt.savefig(imagedir + outFilename, dpi=300, bbox_inches='tight')
    if showGraphic is True:
        plt.show()

except KeyboardInterrupt:
    exit()
