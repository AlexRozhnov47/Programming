<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<<<<<<< HEAD
<h3 align="center">Отчёт по лабораторной работе № 2<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ИВТ-б-о-202(2)<br>
Рожнова Александра Вячеславовича<br>
направления подготовки 09.03.01 "Информатика и вычислительная техника"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
<hr>

<h3 align="left">Постнановка задачи<br><h3>

</h3>
<p align="left">Разработать приложение для написания навыков в Яндекс. Диалогах и перевод результата из Json в Exel формат.  В качестве источника данных для работы с навыком используйте: ngrok.exe, Яндекс. Диалоги. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.<br>
<p align="left">Серверное приложение (далее Сервер) предназначенное для обработки навыка работы с сервисом "Яндекс.Диалоги". Сервер должен обеспечивать возможность получения данных в формате JSON и обрабоки информации в виде webhooks.<br>
<p align="left">Клиентское приложение должно получать запрос с сервера Яндекс.Диалогов по требованию пользователя.<br>
<h3 align="left">Ход работы</h3>
<h2 align="center">Пункт 1. Написание программы на Python.</h2>
<p align="left">После был использован код для написания первой части программы, используемый в основном тексте лабораторной работы. </p>

```python

from tkinter import*
from tkinter import ttk
from tkinter import font
from random import randint

from tkinter import messagebox
import inspect
import winsound
key='' 
fragm=[-1,0,0]
row_count=10 
col_count=10 
cell_size=30 
canv_width=cell_size*col_count 
canv_height=cell_size*row_count 
cells=[] 

fon_color='white'
colors=[fon_color,'red','blue','green','yellow','brown','violet']
flg_game=0 

def print_funcname():
 print(inspect.stack()[1][3])

def draf_field():
 for x_num in range(row_count):
     for y_num in range(col_count):
       canv.create_line(0,y_num*cell_size, canv_width, y_num*cell_size)
       canv.create_line(x_num*cell_size, 0, x_num*cell_size,canv_height)

def clear_cell(row,col):
 global cells
 cells[row][col][0]=0
 oval=cells[row][col][1]
 canv.itemconfig(oval,fill=fon_color, outline=fon_color)
def set_cell(fragm):
 global cells
 color_num,row,col=fragm
 cells[row][col][0]=color_num
 color=colors[color_num]
 oval=cells[row][col][1]
 canv.itemconfig(oval,fill=color, outline=color)
def get_cell(row,col):
 global cells

 color_num=cells[row][col][0]
 return [color_num,row,col]
def select_cell(row,col):
 global cells
 #print_funcname()
 oval=cells[row][col][1]
 canv.itemconfig(oval,outline='black') 
def unselect_cell(row, col):
 global cells
 #print_funcname()
 color_num=cells[row][col][0]
 color=colors[color_num]
 oval=cells[row][col][1]
 canv.itemconfig(oval, outline=color) 

def move_fragm(step_row, step_col):
 global cells, fragm, flg_game
 #print_funcname()
 if flg_game !=2:
    return 0
 color_num, fragm_row, fragm_col=fragm
 if color_num<=0:
    return 0
 new_row=fragm_row+step_row
 new_col=fragm_col+step_col
 if new_row<0 or new_row>=row_count or new_col<0 or new_col>=col_count:
     return 0

 val,oval=cells[new_row][new_col]
 if val !=0:
    return 0
 clear_cell(fragm_row, fragm_col)
 fragm=[color_num, new_row, new_col]
 set_cell(fragm)
 select_cell(new_row, new_col)
 return 1
def add_balls(balls_count):
 global cells
 #print_funcname()

 empty_cells=[]
 for row_num in range(row_count):
   for col_num in range(col_count):
    if cells[row_num][col_num][0]==0:
      empty_cells.append((row_num,col_num))

 empty_count=len(empty_cells)
 if empty_count<balls_count:
    return 3 
 for num in range(balls_count):
   empty_num=randint(0,len(empty_cells)-1)
 row_num, col_num=empty_cells.pop(empty_num)
 color_num=randint(1,len(colors)-1)
 fragm=[color_num, row_num, col_num]
 set_cell(fragm)
 test_five(fragm)
 return 1

def get_dircells(row,col,d_row,d_col):
 color_num=cells[row][col][0]
 if color_num<=0:
   return [] 
 loc_cells=[(row,col)]
 row_cur=row + d_row
 col_cur=col + d_col
 while 0<=row_cur<row_count and 0<=col_cur<col_count:
    if cells[row_cur][col_cur][0] !=color_num:
      break
    loc_cells.append((row_cur,col_cur))
    row_cur +=d_row
    col_cur +=d_col
 row_cur=row - d_row
 col_cur=col - d_col
 while 0<=row_cur<row_count and 0<=col_cur<col_count:
     if cells[row_cur][col_cur][0] !=color_num:
       break
     loc_cells.append((row_cur,col_cur))
     row_cur -=d_row
     col_cur -=d_col
 return loc_cells
def test_five(fragm):
 global flg_game, cells,var_score
 #print_funcname()
 color_num,row,col=fragm 
 res=0
 cells_vert=get_dircells(row,col,-1,0) 
 if len(cells_vert)>4:
   res=1
 cells_hor=get_dircells(row,col,0,-1) 
 if len(cells_hor)>4:
   res=1
 cells_horup=get_dircells(row,col,-1,-1) 
 if len(cells_horup)>4:
    res=1
 cells_hordown=get_dircells(row,col,+1,-1) 
 if len(cells_hordown)>4:
    res=1
 if res==0:
    return 0
 cells_group=[cells_vert, cells_hor, cells_horup, cells_hordown]
 for cells_loc in cells_group:
   if len(cells_loc)>=5:
    for (row,col) in cells_loc:
      clear_cell(row,col)
    score=var_score.get()
    var_score.set(score+len(cells_loc))
 return 1
def test_jump(cell1, cell2):
 #print_funcname()
 row1, col1 = cell1
 #print('row1=',row1,' col1=',col1)
 row2, col2 =cell2
 #print('row2=',row2,' col2=',col2)
 if row1==row2 and col1==col2:
    return 0
 lst_base=[(row1,col1)]
 while True:
    lst_add=[]
    for (rowb,colb) in lst_base:
      lst_tmp=[(rowb-1, colb),(rowb+1, colb),(rowb,colb-1),(rowb,colb+1)]
      lst_near=[(row,col) for (row,col) in lst_tmp if -1<row<row_count and -1<col<col_count and cells[row][col][0]==0]
      if (row2,col2) in lst_near:
        return 1
      for (row,col) in lst_near:
         if (row,col) in lst_base:
           continue
         if len(lst_add)>0 and (row,col) in lst_add:
           continue
         lst_add.append((row,col))

 if len(lst_add)<1:
    return 0
 lst_base +=lst_add

root=Tk()
root.title('Lines')
stl=ttk.Style()
clr_root='lime'
dFont=font.Font(family='helvetica', size=14)
stl.configure('.', font=dFont, background=clr_root, foreground='black')
btn_width=14 
pnl_top=Frame(root)
pnl_top.grid(row=2,column=0, columnspan=3)
canv=Canvas(pnl_top, width=canv_width, height=canv_height, background='pink')
canv.pack()


def mouse_hndl(event):
 global flg_game, fragm, cells

 if flg_game in [0,3]:
    return 

 row=event.y//cell_size
 col=event.x//cell_size
 #print('row=',row,' col=',col)
 val, oval=cells[row][col]
 #print('val=',val,' oval=',oval)
 if flg_game==1:

    if val>0:
       fragm=[val,row,col]
       select_cell(row,col)
       flg_game=2
       return
 if flg_game==2:
   fragm_color, fragm_row, fragm_col=fragm
   unselect_cell(fragm_row, fragm_col)
   flg_game=1
   if test_jump((fragm_row, fragm_col),(row,col)):
    clear_cell(fragm_row, fragm_col)
    fragm=fragm_color,row, col
    set_cell(fragm)
   if not test_five(fragm):
     flg_game=add_balls(3) 
     if flg_game==3:
       messagebox.showinfo('','Over')
   else:
       flg_game=1

canv.bind('<ButtonRelease-1>',mouse_hndl)
def fnc_newgame():
 global cells, flg_game, var_score, fragm
 print_funcname()

 if flg_game==0:
   canv.delete('all')
   canv['background']=fon_color
   draf_field()
   cells=[]
   for row_num in range(row_count):
      row=[]
      for col_num in range(col_count):
        x_beg=col_num*cell_size
        x_end=x_beg+cell_size
        y_beg=row_num*cell_size
        y_end=y_beg+cell_size
        oval=canv.create_oval(x_beg+1, y_beg+1, x_end-1, y_end-1,fill=fon_color, outline=fon_color)
        row.append([0,oval])
      cells.append(row)
 else:
    canv.delete('txt')
    for row_num in range(row_count):
        for col_num in range(col_count):
            clear_cell(row_num, col_num)
 var_score.set(0)
 flg_game=add_balls(8)
 

btn_newgame=ttk.Button(root, text='Новая игра', width=btn_width,command=fnc_newgame)
btn_newgame.grid(row=1, column=0,sticky=E+N, pady=5, padx=5)
var_score=IntVar()
var_score.set(0)
edt_score=ttk.Entry(root, width=10, textvariable=var_score,justify=RIGHT)
edt_score.grid(row=1, column=1, padx=5, pady=5)
root.resizable(width=False, height=False)
root.mainloop()


``` </p>

![]("./Screenshotstart.png")

![]("./Screenshotprocess.png")

<h2 align="center">Пункт 3. Вывод из работы.</h2>
<p align="left">За время написания работы была проведена попытка научиться писать алгоритмы для разработки простых игр на снове языка python при помощи модуля Tkinter. Были выполнены все пункты работы . </p>
<br>