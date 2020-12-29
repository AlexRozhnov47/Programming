from tkinter import *
import json
import requests


def reload_data():
    answer = requests.get('http://localhost:3000/raw').content.decode("utf8")
    if answer:
        infa = json.loads(answer)
        text3.config(text=str(infa["description"]))
        text2.config(text=str(infa["temp"]) + "°C")
    else:
        print('Error')


root = Tk()
l1 = Frame(root, bg='#0000ff')
l2 = Frame(root, bg='#ffffff')
l3 = Frame(root, bg='#0000ff')

l1.pack(fill=X)
l2.pack(fill=BOTH)
l3.pack(fill=X)

text1 = Label(l1, text="Simferopol",
              font=("Impact",
                    14, "bold"))
text1.config(bd=5, bg='#0000ff')

text2 = Label(l2, text="13",
              font=("Impact",
                    48, "bold"))
text2.config(bd=5, bg='#ffffff')

text3 = Label(l3, text="Sunny",
              font=("Arial", 10, "bold"))
text3.config(bd=5, bg='#0000ff')

text1.pack(pady=0)
text2.pack(expand=True)
text3.pack(pady=0)

reload_data()
mainloop()

