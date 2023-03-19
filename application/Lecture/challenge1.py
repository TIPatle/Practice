import tkinter as tk
from PIL import ImageTk, Image

def jpgImage():

    image = Image.open("D:/Program/CPP/application/Lecture/pycharm.png")
    return image

root = tk.Tk()

root.geometry('733x434')
root.minsize(550, 325)

# logo = ImageTk.PhotoImage(file = "D:/Program/CPP/application/Lecture/pycharm.png")
logo = ImageTk.PhotoImage(jpgImage())

l1 = tk.Label(image=logo)
l2 = tk.Label(text='Pycharm')

l1.pack()
l2.pack()

if __name__ == '__main__':
    root.mainloop()