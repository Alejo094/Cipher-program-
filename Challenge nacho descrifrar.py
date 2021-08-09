from IPython.display import clear_output

llave="ALCtALC"

llave_long=len(llave)


def main_menu():

    print("Bienvenido!")
    
    print("\n")
    
    print("1. Cifrar un mensaje utilizando una estrategia estandard de encriptacion")
    print("2. Cifrar un mensaje utilizando una estrategia de cifrado de Vigenere")
    print("3. Descifrar un mensaje que he recibido que utiliza encriptacion estandard")
    print("4. Descifrar un mensaje que he recibido que utiliza cifrado de Vigenere")
    print("5. Programa que detecta automaticamente si el archivo contiene un mensaje cifrado o descifrado y hace su respectiva tarea dependiendo")
  
    print("\n")
    
    opcion= int(input("Por favor escoga que accion desea realizar?\n"))
    
    
    if opcion is 1:
        
        cifrar_mensaje_stand()
        
    elif opcion is 2:
        
        cifrar_mensaje_vig()
        
    elif opcion is 3:
        
        decifrar_mensaje_stand()
        
    elif opcion is 4:

        descifrar_mensaje_vig()

    elif opcion is 5:

        extrachallenge_1()

    else:
    
        print("Opcion Incorrecta! Por favor revise el menu de opciones bien")


def cifrar_mensaje_stand():

    clear_output()

    print("Por favor escriba el mensaje que desea encriptar en el documento titulado (mensaje_por_enviar.txt)")

    print("Escriba solo la frase por favor nada mas!")

    print("Su mensaje cifrado aparecera en el documento titulado (mensaje_encriptado.txt) por favor revise")

    x=0
    y=0

    with open('mensaje_por_enviar.txt','r') as mensaje_enviado:

        with open('mensaje_encriptado.txt', 'w') as mensaje_encriptado:

            mensaje_encriptado.write ("Mensaje Encriptado Estandard: \n\n")

            for line in mensaje_enviado:
                
        
                while( y != len(line)):

                    cifrado = ord(llave[x]) ^ ord(line[y])            

                    if cifrado>=32:

                        mensaje_encriptado.write(chr(cifrado))

                    else:

                        mensaje_encriptado.write(line[y]) 

        
                    
                    x+=1;
                    y+=1;

                    if (llave_long-1)==x:

                        x=0


def decifrar_mensaje_stand():

    clear_output()

    print("Por favor escriba el mensaje que desea desencriptar por estrategia estandard en el documento titulado (mensaje_encriptado.txt)")

    print("Escriba solo la frase que desea desencriptar nada mas!")

    print("Su mensaje original desencriptado aparecera en el documento titulado (mensaje_desencriptado.txt)")

    x=0
    y=0

    with open('mensaje_encriptado.txt','r') as mensaje_enviado:

        with open('mensaje_desencriptado.txt', 'w') as mensaje_encriptado:

            mensaje_encriptado.write ("Mensaje Original Desencriptado Estandard: \n\n")

            for line in mensaje_enviado:

                while( y != len(line) ):

                    cifrado = ord(llave[x]) ^ ord(line[y])            

                    if cifrado>=32:

                        mensaje_encriptado.write(chr(cifrado))

                    else:

                        mensaje_encriptado.write(line[y]) 

                    x+=1;
                    y+=1;
                    

                    if (llave_long- 1)==x:

                        x=0
                        
                        

def cifrar_mensaje_vig():
    
    x=0
    y=0

    key_vige= [10,6,4,25]

    clear_output()

    print("Por favor escriba el mensaje que desea encriptar en el documento titulado (mensaje_por_enviar.txt)")

    print("Escriba solo la frase que desea encriptar con cifrado de Vigenere por favor nada mas!")

    print("Su mensaje cifrado aparecera en el documento titulado (mensaje_encriptado.txt) por favor revise")

    with open('mensaje_por_enviar.txt','r') as mensaje_enviado:

        with open('mensaje_encriptado.txt', 'w') as mensaje_encriptado:

            mensaje_encriptado.write ("Mensaje Encriptado Vigenere: \n\n")

            for line in mensaje_enviado:
                
                while y != len(line) :
                                      
                    cifrado = ord(line[y]) + key_vige[x] 
                    
                    mensaje_encriptado.write(chr(cifrado))
                        
                    x+=1
                    y+=1

                    if x==4:

                        x=0
            

def descifrar_mensaje_vig():
    
    x=0
    y=0

    key_vige= [10,6,4,25]

    clear_output()

    print("Por favor escriba el mensaje que desea encriptar en el documento titulado (mensaje_por_enviar.txt)")

    print("Escriba solo la frase que desea encriptar con cifrado de Vigenere por favor nada mas!")

    print("Su mensaje cifrado aparecera en el documento titulado (mensaje_encriptado.txt) por favor revise")
 
    with open('mensaje_encriptado.txt','r') as mensaje_enviado:

        with open('mensaje_desencriptado.txt', 'w') as mensaje_encriptado:

            mensaje_encriptado.write ("Mensaje Desencriptado Vigenere: \n\n")

            for line in mensaje_enviado:
                
                while y != len(line) :
                                      
                    cifrado = ord(line[y]) - key_vige[x] 
                                      
                    mensaje_encriptado.write(chr(cifrado))
                        
                    x+=1
                    y+=1

                    if x==4:

                        x=0
                        

def extrachallenge_1():
    
    x=0
    y=0

    clear_output()
    
    print("El siguiente programa detecta lo guardado en (deteccion_autom.txt) y dependiendo de eso encripta o   desencripta el texto \n\n ")
    
    print("Recuerde este mecanismo funciona en este caso con texto cifrado por medio de modo estandar XOR \n\n ")
    
    print("Para cifrar o desifrar algun texto escribalo comenzando el archivo hasta que termine su contenido \n\n ")
    
    print("Su mensaje cifrado/desifrado aparecera en el mismo texto donde guardo en principio (deteccion_autom.txt) por favor revise su solucion \n\n")

    with open('deteccion_autom.txt','r+') as mensaje_enviado:

        mensaje_enviado.write ("\n\nMensaje Original/Encriptado: \n\n")

        for line in mensaje_enviado:

            while( y != len(line) ):

                cifrado = ord(llave[x]) ^ ord(line[y])            

                if cifrado>=32:

                    mensaje_enviado.write(chr(cifrado))

                else:

                    mensaje_enviado.write(line[y]) 

                x+=1;
                y+=1;


                if (llave_long- 1)==x:

                    x=0

main_menu()