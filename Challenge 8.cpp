#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

void cifrar_mensaje_stand();
void cifrar_mensaje_vig();
void decifrar_mensaje_stand();
void descifrar_mensaje_vig();
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
        
        default:
        
        cout<<"Opcion Incorrecta! Por favor revise el menu de opciones bien"<<endl;
    }
 

}


void cifrar_mensaje_stand(){


    system("cls");
    
    cout <<"Por favor escriba la frase que desea encriptar con cifrado estandard?"<< "\n\n";
    
    cin.ignore();
    
    cout<<"Mensaje Original: "<<"\n\n";
        
    cin.get (mensaje, 500);
    
    char a = mensaje[x];
    
    char b = llave[y];
    
    cout<<"\nMensaje Encriptado: "<<"\n\n";

	while(a!='\0'){
       
     	cifrado = a ^ b;
     	
        if(cifrado>=32){
           	
			cout << cifrado;
        }
        else{
        	cout<<a;
		}

	    x+=1;
        y+=1;
       
        a = mensaje[x];
        
        if(llave[y]=='\0'){
        	y=0;
    	}
    	
        b = llave[y];
       
     }    
  
 
}


void cifrar_mensaje_vig(){

    system("cls");
    
    cout <<"Por favor escriba la frase que desea desencriptar utilizando cifrado de Vigenere?"<< "\n\n";
    
    cin.ignore();
    
    cout<<"Mensaje Cifrado: "<<"\n\n";

    cin.get (mensaje, 200);
    
    char a = mensaje[x];

    char b = mensaje[x+1];
    
    char c =mensaje[x+2];
    
    char d =mensaje[x+3];
    
    cout<<"\nMensaje original ya desencriptado: "<<"\n\n";

    while(turno==0){
      
        cifrado_a = a + (key_1);
        
        cifrado_b = b + (key_2);
        
        cifrado_c = c + (key_3);
        
        cifrado_d = d + (key_4);
        
        
        cout << cifrado_a;
        cout << cifrado_b;
        cout << cifrado_c;
        cout << cifrado_d;

        x+=4;
        
        a = mensaje[x];
        b = mensaje[x+1];
        c =mensaje[x+2];
        d =mensaje[x+3];
        
        if(a=='\0'){
            turno=1;
            break;
        }  
        
        if(b=='\0'){
            
        cifrado_a = a + (key_1);
        
        cout << cifrado_a;
            
        break;
        
        }  
        
        if(c=='\0'){
            
        cifrado_a = a + (key_1);
        
        cifrado_b = b + (key_2);

        
        cout << cifrado_a;
        cout << cifrado_b;
            
            break;
        }
        if(d=='\0'){
            
        cifrado_a = a + (key_1);
        
        cifrado_b = b + (key_2);
        
        cifrado_c = c + (key_3);
        
        cout << cifrado_a;
        cout << cifrado_b;
        cout << cifrado_c;
            
            break;
        }
        
     }
  
}


void decifrar_mensaje_stand(){

    system("cls");
    
    cout <<"Por favor escriba la frase que desea desencriptar con cifrado estandard?"<< "\n\n";
    
    cin.ignore();
    
    cout<<"Mensaje Encriptado: "<<"\n\n";
        
    cin.get (mensaje, 500);
    
    char a = mensaje[x];
    
    char b = llave[y];
    
    cout<<"\nMensaje Original: "<<"\n\n";

	while(a!='\0'){
       
     	cifrado = a ^ b;
     	
        if(cifrado>=32){
           	
			cout << cifrado;
        }
        else{
        	cout<<a;
		}

	    x+=1;
        y+=1;
       
        a = mensaje[x];
        
        if(llave[y]=='\0'){
        	y=0;
    	}
    	
        b = llave[y];
       
     }    
   
}

void descifrar_mensaje_vig(){
	
    system("cls");
    
    cout <<"Por favor escriba la frase que desea desencriptar utilizando cifrado de Vigenere?"<< "\n\n";
    
    cin.ignore();
    
    cout<<"Mensaje Cifrado: "<<"\n\n";

    cin.get (mensaje, 200);
    
    char a = mensaje[x];

    char b = mensaje[x+1];
    
    char c =mensaje[x+2];
    
    char d =mensaje[x+3];
    
    cout<<"\nMensaje original ya desencriptado: "<<"\n\n";

    while(turno==0){
      
        cifrado_a = a - (key_1);
        
        cifrado_b = b - (key_2);
        
        cifrado_c = c - (key_3);
        
        cifrado_d = d - (key_4);
        
        
        cout << cifrado_a;
        cout << cifrado_b;
        cout << cifrado_c;
        cout << cifrado_d;

        x+=4;
        
        a = mensaje[x];
        b = mensaje[x+1];
        c =mensaje[x+2];
        d =mensaje[x+3];
        
        if(a=='\0'){
            turno=1;
            break;
        }  
        
        if(b=='\0'){
            
        cifrado_a = a - (key_1);
        
        cout << cifrado_a;
            
        break;
        
        }  
        
        if(c=='\0'){
            
        cifrado_a = a - (key_1);
        
        cifrado_b = b - (key_2);

        
        cout << cifrado_a;
        cout << cifrado_b;
            
            break;
        }
        if(d=='\0'){
            
        cifrado_a = a - (key_1);
        
        cifrado_b = b - (key_2);
        
        cifrado_c = c - (key_3);
        
        cout << cifrado_a;
        cout << cifrado_b;
        cout << cifrado_c;
            
            break;
        }
        
     }
    
    
}

