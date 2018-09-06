#Importar librerias
import telepot, sys, time, serial;
#Conexion con el puerto serial
ser = serial.Serial('/dev/ttyACM1')
def handle(msg):
    #Obtener el nombre de usario
    userName= msg['from']['first_name']
    #Obneter los datos del chat
    content_type,chat_type,chat_id= telepot.glance(msg)
    if(content_type=='text'):
        command=msg['text']
        print(userName+' ingreso '+command)
        if('/start' in command):
            bot.sendMessage(chat_id,"Bienvenido,"+userName+"\n"
            +"/GE ---> Encender led verde"
            +"/GA ---> Apagar led verde"
            +"/BE ---> Enceder led azul"
            +"/BA ---> Apagar led azul")
        if('/GE' in command):
            ser.write(b'G')
            bot.sendMessage(chat_id,"led verde encendido")
        if('/GA' in command):
            ser.write(b'g')
            bot.sendMessage(chat_id,"led verde apagado")
        if('/BE' in command):
            ser.write(b'B')
            bot.sendMessage(chat_id,"led azul  encendido")
        if('/BA' in command):
            ser.write(b'b')
            bot.sendMessage(chat_id,"led azul apagado")
        else:
              bot.sendMessage(chat_id,", no entiendo lo que dices?")
bot = telepot.Bot('639550307:AAHAxXOJFb4EGCZyFWOcPm75tdLCwz-ce6g')
bot.message_loop()
while 1:
    time.sleep(20)
            
    