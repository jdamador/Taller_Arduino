#!/usr/bin/python
import telepot, time, serial, sys
ser = serial.Serial('/dev/ttyACM1', 9600)
 
print('Bot activado.')
print('Esperando comandos...')
    
def handle(msg):
 
        userName = msg['from']['first_name']
 
        content_type, chat_type, chat_id = telepot.glance(msg)
 
        if (content_type == 'text'):
                command = msg['text']
                print ('Comando obtenido: %s' % command+' enviado por '+userName)
 
                if('/start' in command):
                    bot.sendMessage(chat_id,"Bienvenido,"+userName+"\n"
                    +"/GE ---> Encender led verde\n"
                    +"/GA ---> Apagar led verde\n"
                    +"/BE ---> Enceder led azul\n"
                    +"/BA ---> Apagar led azul\n")
                elif('/GE' in command or '/ge' in command):
                    ser.write(b'G')
                    bot.sendMessage(chat_id,"led verde encendido")
                elif('/GA' in command or '/ga' in command):
                    ser.write(b'g')
                    bot.sendMessage(chat_id,"led verde apagado")
                elif('/BE' in command or '/be' in command):
                    ser.write(b'B')
                    bot.sendMessage(chat_id,"led azul  encendido")
                elif('/BA' in command or '/ba' in command ):
                    ser.write(b'b')
                    bot.sendMessage(chat_id,"led azul apagado")
                elif('hola'in command):
                    bot.sendMessage(chat_id,"Hola,"+userName)
                else:
                    bot.sendMessage(chat_id,userName+", no entiendo lo que dices?")
 
bot = telepot.Bot('639550307:AAHAxXOJFb4EGCZyFWOcPm75tdLCwz-ce6g')
 
bot.message_loop(handle)
 
# Espera por nuevos mensajes
while 1:
        time.sleep(20)
 