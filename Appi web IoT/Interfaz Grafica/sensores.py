import serial
import time
from tkinter import *
#from win32api import GetSystemMetrics 
from PIL import ImageTk,Image


ventana = Tk()
ventana.title("Interfaz de sensores arduino")
ventana.geometry("1920x1080")

image2 = Image.open("c:/interfaz.png")
image2 = image2.resize((1280,720), Image.ANTIALIAS)
image1 = ImageTk.PhotoImage(image2)

background = Label(ventana, image=image1, bd=1)
background.pack()


arduino = serial.Serial('COM5', 9600)


informacion = arduino.readline().decode().strip('\r\n')



while(True):
    
    informacion = arduino.readline().decode().strip('\r\n')

    gas = informacion.split("$")[1]
    luz = informacion.split("#")[1]
    humedad = informacion.split("?")[1]

    print(informacion)

    
    if int(gas) == 1:
        textoGas = "No hay presencia"
    else:
        textoGas = "Hay presencia"

    if int(luz)<= 700:
        textoLuz = "Mucha luz"
    else:
        textoLuz = "Poca luz"

    if int(humedad) == 0:
        textoHumedad = "No hay humedad"
    else:
        textoHumedad = "Hay humedad"

   
    
    valorSensor1 = Label(ventana, text=gas, font=("Roboto",40),bg="#EEEEEE", fg="#FF6F00");
    valorSensor1.place(x=600,y=250)

    labelGas = Label(ventana, text=textoGas, font=("Roboto",30),bg="#EEEEEE", fg="black")
    labelGas.place(x=460, y=350)


    valorSensor2 = Label(ventana, text=luz, font=("Roboto",40),bg="#EEEEEE", fg="#FFEA00");
    valorSensor2.place(x=130,y=200)

    labelLuz = Label(ventana, text=textoLuz, font=("Roboto",30),bg="#EEEEEE", fg="black");
    labelLuz.place(x=130,y=300)

    valorSensor3 = Label(ventana, text=humedad, font=("Roboto",40),bg="#EEEEEE", fg="#4CAF50");
    valorSensor3.place(x=1040,y=200)

    labelHumedad = Label(ventana, text=textoHumedad, font=("Roboto",30),bg="#EEEEEE", fg="black")
    labelHumedad.place(x=900, y=300)
 
    
    ventana.update()
    labelHumedad.destroy();
    labelLuz.destroy();
    labelGas.destroy();
  


arduino.close()






