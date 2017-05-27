#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cifrado(char *cadena,int num);
void morse(char *palabra);

int main(int argc, char *argv[]){
	if(argc == 3){
		int numero;
		numero= atoi(argv[1]);
		cifrado(argv[2],numero);
	}
	else{
		char palabra[1024]={0};
		printf("Introduce el mensaje: ");
		gets(palabra);
		int llave;
	        printf("Introduce llave numerica: ");
	        scanf("%d", &llave);
		cifrado(palabra,llave);
	}
	return 0;
}

void cifrado(char *cadena,int num){
	int tam,tamalfabeto,bandera,i,b;
        tam=strlen(cadena);
	tamalfabeto=strlen(alfabeto_min);
	char codigo[1024]={0};
        char alfabeto_min[27]="abcdefghijklmnopqrstuvwxyz";
        char alfabeto_may[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf("Cifrado cíclico \n");

	for(i=0;i<tam;i++){
		bandera=0;
			for(b=0;b<tamalfabeto;b++){
				if(cadena[i]==alfabeto_min[b]){
					if(b > 25-num){
						codigo[i]=alfabeto_min[b+num-26];
					}
					else{
						codigo[i]=alfabeto_min[b+num];
					}
					bandera=1;
				}
				else if(cadena[i]==alfabeto_may[b]){
					if(b > 25-num){
                                                codigo[i]=alfabeto_may[b+num-26];
                                        }
                                        else{
                                                codigo[i]=alfabeto_may[b+num];
                                        }
                                        bandera=1;
				}

			}
			if(bandera==0){
				codigo[i]=cadena[i];
			}
	}
	printf("Mensaje cifrado: ");
	printf(codigo);
	printf("\n");

}

