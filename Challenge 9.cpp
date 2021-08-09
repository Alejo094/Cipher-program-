#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>

using namespace std;

void cifrar_mensaje_stand();
void cifrar_mensaje_vig();
void decifrar_mensaje_stand();
void descifrar_mensaje_vig();
void extrachallenge_1();

int y = 0;
int x = 0;
int i = 0;
int opcion= 0;
int turno=0;
char cifrado=' ';
char mensaje[500];
char llave[] ="ALCtALC";
int key_1= 25;
int key_2= 14;
int key_3= 17;
int key_4= 10;
char a =mensaje[x];
char c =mensaje[x+1];
char cifrado_a =' ';
char cifrado_b =' ';
char cifrado_c =' ';
char cifrado_d =' ';



main ()
{

    cout << "Bienvenido!" << "\n\n";

    cout<<"Por favor escoga que accion desea realizar?"<<"\n\n";
    
    cout<<"1. Cifrar un mensaje utilizando una estrategia estandard de encriptacion\n\n";
    cout<<"2. Cifrar un mensaje utilizando una estrategia de cifrado de Vigenere\n\n";
    cout<<"3. Descifrar un mensaje que he recibido que utiliza encriptacion estandard\n\n";
    cout<<"4. Descifrar un mensaje que he recibido que utiliza cifrado de Vigenere\n\n";
  	cout<<"5. Programa que detecta automaticamente si el archivo contiene un mensaje cifrado o descifrado y hace su respectiva tarea dependiendo\n\n";
  	
    cout<<"\n";
    
    cin>>opcion;
    
    switch(opcion){
        
        case 1:

        cifrar_mensaje_stand();
        
        exit(1);
        
        case 2:

        cifrar_mensaje_vig();

        exit(1);
        
        case 3:

        decifrar_mensaje_stand();

        exit(1);
        
        case 4:

        descifrar_mensaje_vig();

        exit(1);
        
        case 5:
        	
        extrachallenge_1();
        exit(1);
        
        default:
        
        cout<<"Opcion Incorrecta! Por favor revise el menu de opciones bien"<<endl;
    }
 

}


void cifrar_mensaje_stand(){

    system("cls");
    
    cout <<"Por favor escriba el mensaje que desea encriptar en el documento titulado (mensaje_por_enviar.txt)"<< "\n\n";
    
    cout <<"Escriba solo la frase por favor nada mas!"<< "\n\n";
    
    cout<<"Su mensaje cifrado aparecera en el documento titulado (mensaje_encriptado.txt) por favor revise"<<endl;
    
    string texto;
    
    fstream mensaje_archivo;

	mensaje_archivo.open("mensaje_por_enviar.txt",ios::in);
	
	if(mensaje_archivo.is_open()){
		
	getline(mensaje_archivo,texto);
		
	fstream mensaje1;
	
	mensaje1.open("mensaje_encriptado.txt", ios::out);
	
	if(mensaje1.is_open()){

    mensaje1<<"Mensaje Encriptado: "<<"\n\n";
		
	while(texto[x]!='\0'){
		
		char b = llave[y];
       	
     	cifrado = texto[x] ^ b;
     	
        if(cifrado>=32){
        
			mensaje1 << cifrado;
        }
        else{
        	mensaje1<<texto[x];
		}

	    x+=1;
        y+=1;
       
        
        if(llave[y]=='\0'){
        	y=0;
    	}
    	
        b = llave[y];
       
     } 
     
    mensaje1.close();
				
	}

	mensaje_archivo.close();
	}
    
 
}


void cifrar_mensaje_vig(){

    system("cls");
    
    cout <<"Por favor escriba el mensaje que desea encriptar en el documento titulado (mensaje_por_enviar.txt)"<< "\n\n";
    
    cout <<"Escriba solo la frase que desea encriptar con cifrado de Vigenere por favor nada mas!"<< "\n\n";
    
    cout<<"Su mensaje cifrado aparecera en el documento titulado (mensaje_encriptado.txt) por favor revise"<<"\n";
    
    string texto;
    
    fstream mensaje_archivo;

	mensaje_archivo.open("mensaje_por_enviar.txt",ios::in);
	
	if(mensaje_archivo.is_open()){
		
	getline(mensaje_archivo,texto);
		
	fstream mensaje1;
	
	mensaje1.open("mensaje_encriptado.txt", ios::out);
	
	if(mensaje1.is_open()){

    mensaje1<<"Mensaje Encriptado Vigenere: "<<"\n\n";

    while(turno==0){
        
	    cifrado_a = texto[x] + (key_1);
        
        cifrado_b = texto[x+1] + (key_2);
        
        cifrado_c = texto[x+2] + (key_3);
        
        cifrado_d = texto[x+3] + (key_4);
        
       
        
        mensaje1 << cifrado_a;
        mensaje1 << cifrado_b;
        mensaje1 << cifrado_c;
        mensaje1 << cifrado_d;

        
        x+=4;
        
        if(texto[x]=='\0'){
            turno=1;
            break;
        }  
        
        if(texto[x+1]=='\0'){
            
        cifrado_a = texto[x] + (key_1);
        
        mensaje1 << cifrado_a;
            
        break;
    	}
    	
    	if(texto[x+2]=='\0'){
            
	        cifrado_a = texto[x] + (key_1);
	        
	        cifrado_b = texto[x+1] + (key_2);

        
	        mensaje1<< cifrado_a;
	     	mensaje1<< cifrado_b;
           
            break;
		}
		
       
        if(texto[x+3]=='\0'){
            
	        cifrado_a = texto[x] + (key_1);
	        
	        cifrado_b = texto[x+1] + (key_2);
	        
	        cifrado_c = texto[x+2] + (key_3);
	        
	       	mensaje1 << cifrado_a;
	        mensaje1 << cifrado_b;
	        mensaje1 << cifrado_c;
            
            break;
        }
        
 }
  
     
    mensaje1.close();
				
	}
	
		mensaje_archivo.close();
	}
  
}


void decifrar_mensaje_stand(){

    system("cls");
    
    cout <<"Por favor escriba el mensaje que desea desencriptar por estrategia estandard en el documento titulado (mensaje_encriptado.txt)"<< "\n\n";
    
    cout <<"Escriba solo la frase que desea desencriptar nada mas!"<<"\n\n";
    
    cout<<"Su mensaje original desencriptado aparecera en el documento titulado (mensaje_desencriptado.txt) "<<endl;
    
    string texto;
    
    fstream mensaje_archivo;

	mensaje_archivo.open("mensaje_encriptado.txt",ios::in);
	
	if(mensaje_archivo.is_open()){
		
	getline(mensaje_archivo,texto);
		
	fstream mensaje1;
	
	mensaje1.open("mensaje_desencriptado.txt", ios::out);
	
	if(mensaje1.is_open()){

    mensaje1<<"Mensaje Original Desencriptado: "<<"\n\n";
		
	while(texto[x]!='\0'){
		
		char b = llave[y];
       	
     	cifrado = texto[x] ^ b;
     	
        if(cifrado>=32){
           	
			mensaje1 << cifrado;
        }
        else{
        	mensaje1<<texto[x];
		}

	    x+=1;
        y+=1;
       
        
        if(llave[y]=='\0'){
        	y=0;
    	}
    	
        b = llave[y];
       
     } 
     
    mensaje1.close();
				
	}

	mensaje_archivo.close();
	}
			    

}

void descifrar_mensaje_vig(){


    system("cls");
    
    cout <<"Por favor escriba el mensaje que desea desencriptar en el documento titulado (mensaje_encriptado.txt)"<< "\n\n";
    
    cout <<"Escriba solo la frase que desea desencriptar con cifrado de Vigenere por favor nada mas!"<< "\n\n";
    
    cout<<"Su mensaje desencriptado aparecera en el documento titulado (mensaje_desencriptado.txt) revise"<<"\n";
    
    string texto;
    
    fstream mensaje_archivo;

	mensaje_archivo.open("mensaje_encriptado.txt",ios::in);
	
	if(mensaje_archivo.is_open()){
		
	getline(mensaje_archivo,texto);
		
	fstream mensaje1;
	
	mensaje1.open("mensaje_desencriptado.txt", ios::out);
	
	if(mensaje1.is_open()){

    mensaje1<<"Mensaje Original Desencriptado por Vigenere: "<<"\n\n";

    while(turno==0){
        
	    cifrado_a = texto[x] - (key_1);
        
        cifrado_b = texto[x+1] - (key_2);
        
        cifrado_c = texto[x+2] - (key_3);
        
        cifrado_d = texto[x+3] - (key_4);
        
        mensaje1 << cifrado_a;
        mensaje1 << cifrado_b;
        mensaje1 << cifrado_c;
        mensaje1 << cifrado_d;

        
        x+=4;
        
        if(texto[x]=='\0'){
            turno=1;
            break;
        }  
        
        if(texto[x+1]=='\0'){
            
        cifrado_a = texto[x] - (key_1);
        
        mensaje1<< cifrado_a;
            
        break;
    	}
    	
    	if(texto[x+2]=='\0'){
            
	        cifrado_a = texto[x] - (key_1);
	        
	        cifrado_b = texto[x+1] - (key_2);

        
	        mensaje1<< cifrado_a;
	     	mensaje1<< cifrado_b;
           
            break;
		}
		
       
        if(texto[x+3]=='\0'){
            
	        cifrado_a = texto[x] - (key_1);
	        
	        cifrado_b = texto[x+1] - (key_2);
	        
	        cifrado_c = texto[x+2] - (key_3);
	        
	       	mensaje1 << cifrado_a;
	        mensaje1 << cifrado_b;
	        mensaje1 << cifrado_c;
            
            break;
        }
        
 }
  
     
    mensaje1.close();
				
	}
	
		mensaje_archivo.close();
	}
  

}



void extrachallenge_1(){
	
    system("cls");
    
    cout <<"El siguiente programa detecta lo guardado en (deteccion_autom.txt) y dependiendo de eso encripta o 	   desencripta el texto "<< "\n\n";
    
    cout <<"Recuerde este mecanismo funciona en este caso con texto cifrado por medio de modo estandar XOR "<< "\n\n";
    
    cout<<"Para cifrar o desifrar algun texto escribalo comenzando el archivo hasta que termine su contenido "<<"\n\n";
    
    cout<<"Su mensaje cifrado/desifrado aparecera en el mismo texto donde guardo en principio 			(deteccion_autom.txt) por favor revise su solucion"<<endl;
    
    string texto;
    
    fstream mensaje_archivo;

	mensaje_archivo.open("deteccion_autom.txt",ios::in);
	
	if(mensaje_archivo.is_open()){
		
	getline(mensaje_archivo,texto);
		
	fstream mensaje1;
	
	mensaje1.open("deteccion_autom.txt", ios::app);
	
	if(mensaje1.is_open()){

    mensaje1<<"\n\nMensaje Original/Encriptado: \n"<<"\n";
    
		
	while(texto[x]!='\0'){
		
		char b = llave[y];
       	
     	cifrado = texto[x] ^ b;
     	
        if(cifrado>=32){
        	

			mensaje1 << cifrado;
        }
        else{
        	
        	
        	mensaje1<<texto[x];
		}

	    x+=1;
        y+=1;
       
        
        if(llave[y]=='\0'){
        	y=0;
    	}
    	
        b = llave[y];
       
     } 
     
    mensaje1.close();
				
	}

	mensaje_archivo.close();
	}
	
	
	
	
}


