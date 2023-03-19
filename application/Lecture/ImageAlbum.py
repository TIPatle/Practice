import tkinter as tk
import os
from PIL import ImageTk, Image

def jpgImage( filename ):

    image = Image.open(filename)
    image = image.resize((150, 100))
    return image

root = tk.Tk()

root.geometry('733x434')
root.minsize(550, 325)

directory = r"C:\Users\Tushar\Pictures\Saved Pictures"
imgFile = os.listdir(directory)

pictures = []
pictext = []

for img in imgFile:

    file_name = directory + '\\' + img
    if '.jpg' in img or '.jpeg' in img or '.png' in img:
        
        picture = ImageTk.PhotoImage(jpgImage(file_name))
        pictures.append(picture)
        pictext.append(img)

for i in range(len(pictext)):

    l1 = tk.Label( image=pictures[i])
    l2 = tk.Label( text = pictext[i])

    l1.pack()
    l2.pack()

if __name__ == '__main__':
    root.mainloop()