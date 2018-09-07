# Importamos las librerias que vamos a utilizar
import sys,telepot,time,serial

# Crear conexion serial
#ser= serial.Serial('/dev/ttyACM0')

# Mensaje de estado
print('Ejecutando bot')
print('Esperando instrucciones...')

# Funcion que manejara los mensajes entrantes
def handle(msg):
    # Obtener el nombre de usuario
    userName= msg['from']['fist_name']
    # Obtener toda la informacion sobre la sesion con el bot
    content_type,chat_type,chat_id= telepot.glance(msg)
    # Verificar que  la instruccion sea de tipo texto
    if(content_type == 'text'):
        # Almacenar la instruccion en una variblea para meyor facilidad de manejo
        command=msg['text']
        # Verificar cual instruccion es la que se solicita
        if('/start' in command):
            # Enviar mensaje al bot
            bot.sendMessage(chat_id,'El menu')
        if('/GE' in command):
            # Escribir en el puerto serial para que el arduino pueda captar la informacion
            #ser.write(b'V')
            # Mensaje de confirmacion
            bot.sendMessage(chat_id,'Encendido led verde')
        if('/GA' in command):
            # Escribir en el puerto serial para que el arduino pueda captar la informacion
            #ser.write(b'v')
            # Mensaje de confirmacion
            bot.sendMessage(chat_id,'Apagado led verde')
        if('/BE' in command):
            # Escribir en el puerto serial para que el arduino pueda captar la informacion
            #ser.write(b'B')
            # Mensaje de confirmacion
            bot.sendMessage(chat_id,'Encendido led azul')
        if('/BA' in command):
            # Escribir en el puerto serial para que el arduino pueda captar la informacion
            #ser.write(b'b')
            # Mensaje de confirmacion
            bot.sendMessage(chat_id,'Apagado led azul')
        else:
             bot.sendMessage(chat_id, userName+', que esta haciendo?')
        
# Establecer sesion con el bot creado en Telegram
bot= telepot.Bot('639550307:AAHAxXOJFb4EGCZyFWOcPm75tdLCwz-ce6g')
# Loop de espera de mensajes
bot.message_loop()
while 1:
    time.sleep(20)

