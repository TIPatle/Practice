from tkinter import *

root = Tk()

# Gui Logic

# Width X Height -- starting area of the gui window
root.geometry("1000x500")

# width, height -- minimize are of the gui window
root.minsize(500, 250)

# label and packing the label in gui
l1 = Label(text="This is the first GUI made by Tushar")
l1.pack()

# Event loop
if __name__ == '__main__':
    root.mainloop()