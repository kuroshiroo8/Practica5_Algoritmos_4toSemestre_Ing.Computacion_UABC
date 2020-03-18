// Carlos Daniel Orozco Bravo 351285 441 L5

//**************************************************LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//**************************************************ESTRUCTURA SIMPLE
typedef struct _tdato	{
									int dato ;
									struct _tdato *sig ;
								} stdato;

typedef stdato *Tdato ;

//**************************************************ESTRUCTURA ALUMNO
typedef struct _talumno	{
									int status ;
									long matri ;
									char nombre[30] , appat[30] , apmat[30] ;
									struct _talumno *sig ;
								} stalumno ;

typedef stalumno *Talumno ;

//**************************************************PROTOTIPO DE FUNCIONES
int MENU( void ) ;
int MENUsimple( void ) ;
int MENUalumno( void ) ;

int leenum( int InfLim , int SupLim , char *msg , char *msgError ) ;
long leenumlong( long InfLim , long SupLim , char *msg , char *msgError ) ;

void serviciodato( Tdato temp ) ;
void servicioalumno( Talumno temp ) ;

void AddlistaDato( Tdato *lista , Tdato *nuevo ) ;
void AddlistaAlumno( Talumno *lista , Talumno *nuevo ) ;
void PrintlistaDato( Tdato lista ) ;
void PrintlistaAlumno( Talumno lista ) ;
Tdato FindlistaDato( Tdato lista , int num ) ;
Talumno FindlistaAlumno( Talumno lista , long num ) ;
void DeletelistaDato( Tdato *lista , int num ) ;
void DeletelistaAlumno( Talumno *lista , long num ) ;

Tdato GenDato( void ) ;
Talumno GenAlumno( void ) ;

//**************************************************MAIN
int main()
{
	srand(time(NULL));
	MENU();
	return 0;
}

//**************************************************MENU
int MENU( )
{
	int opcion = 0 ;
	do
		{
			system( "cls" ) ;
			printf( "M   E   N   U\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- Listas simples (Estructura simple).\n" ) ;
			printf( "\nb).\n" ) ;
			printf( "\t2- Listas simples (Estructura alumno).\n" ) ;
			printf( "\n\n3- Salir.\n" ) ;
			printf( "\n\nESCOGE UNA OPCION.\n\n" ) ;
			opcion = leenum( 1 , 3 , "Dame un numero.\t" , "Error..\n\n" ) ;
			switch( opcion )
				{
					case 1:	system( "cls" ) ;	MENUsimple( ) ;	break ;
					case 2:	system( "cls" ) ;	MENUalumno( ) ;	break ;
				}
		} while( opcion!=3 ) ;
}

//**************************************************MENU PILA
int MENUsimple( )
{
	int opcion = 0 , num ;
	Tdato lista = NULL , nuevo = NULL , temp = NULL , anterior = NULL ;
	do
		{
			system( "cls" ) ;
			printf( "M   E   N   U   -   E S T R U C T U R A S I M P L E\n\n" ) ;
			printf( "a).\n" ) ;
			printf( "\t1- Agregar.\n" ) ;
			printf( "\t2- Eliminar.\n" ) ;
			printf( "\t3- Buscar.\n" ) ;
			printf( "\t4- Imprimir.\n" ) ;
			printf( "\n\n5- Salir.\n" ) ;
			printf( "\n\nESCOGE UNA OPCION.\t" ) ;
			opcion = leenum( 1 , 5 , "Dame un numero.\t" , "Error..\n\n" ) ;
			switch( opcion )
				{
					case 1:
								nuevo=GenDato();
                    		AddlistaDato( &lista , &nuevo ) ;
                    		break;
					case 2:
                			num=leenum(1, 100, "Dame un numero.\t", "Error..\n\n");
                			DeletelistaDato(&lista ,num);
                    		system( "pause" ) ;
                    		break;
					case 3:
                    		if( lista )
									{
										num=leenum(1, 100, "Dame un numero.\t", "Error..\n\n");
                    				temp=FindlistaDato( lista , num ) ;
                    				if( temp )
                        			{
                        				serviciodato( temp ) ;
                        			}
                        			else
                            			{
													printf( "\n\nNo existe...\n\n" ) ;
                            			}
									}
									else
										{
											printf( "\n\nNo hay ningun dato...\n\n" ) ;
										}
								system( "pause" ) ;
                    		break ;
					case 4:
								printf( "\n\nLISTA\n\n" ) ;
                    		PrintlistaDato( lista ) ;
                    		system( "pause" ) ;
                    		break ;
				}
		} while( opcion!=5 ) ;
	return 0 ;
}

//**************************************************MENU COLA
int MENUalumno( )
{
	int opcion = 0 , num ;
	Talumno lista = NULL , nuevo = NULL , temp = NULL , anterior = NULL ;
	do
		{
			system( "cls" ) ;
			printf( "M   E   N   U   -   E S T R U C T U R A A L U M N O\n\n" ) ;
			printf( "b).\n" ) ;
			printf( "\t1- Agregar.\n" ) ;
			printf( "\t2- Eliminar.\n" ) ;
			printf( "\t3- Buscar.\n" ) ;
			printf( "\t4- Imprimir.\n" ) ;
			printf( "\n\n5- Salir.\n" ) ;
			printf( "\n\nESCOGE UNA OPCION.\t" ) ;
			opcion = leenum( 1 , 5 , "Dame un numero.\t" , "Error..\n\n" ) ;
			switch( opcion )
				{
					case 1:
                    		nuevo=GenAlumno() ;
                    		AddlistaAlumno( &lista , &nuevo ) ;
                    		break ;
					case 2:
                			num=leenumlong( 1 , 10300000 , "Dame un numero.\t" , "Error..\n\n" ) ;
                			DeletelistaAlumno( &lista ,num ) ;
                    		system( "pause" ) ;
                    		break ;
					case 3:
                    		if( lista )
									{
										num=leenumlong( 1 , 10300000 , "Dame un numero.\t" , "Error..\n\n" ) ;
            						temp=FindlistaAlumno( lista , num ) ;
            						if( temp )
                						{
                    						servicioalumno( temp ) ;
                						}
                						else
                    						{
                        					printf( "\n\nNo existe...\n\n" ) ;
                    						}
									}
									else
										{
											printf( "\n\nNo hay ningun dato...\n\n" ) ;
										}
                    		system( "pause" ) ;
                    		break ;
					case 4:
                    		printf( "\n\nLISTA\n\n" ) ;
                    		PrintlistaAlumno( lista ) ;
								system( "pause" ) ;
                    		break ;
				}
		} while( opcion!=5 ) ;
	return 0 ;
}

//**************************************************VALIDAR NUMERO
int leenum( int InfLim , int SupLim , char *msg , char *msgError )
{
	char strnum[30] ;
	int num ;
	do
		{
			puts( msg ) ;
			fflush( stdin ) ;
			gets( strnum ) ;
			num = atoi( strnum ) ;
			if( num<InfLim || num>SupLim )
				{
					puts( msgError ) ;
					system( "pause" ) ;
				}
		} while( num<InfLim || num>SupLim ) ;
	return num ;
}

//**************************************************VALIDAR NUMERO LONG
long leenumlong( long InfLim , long SupLim , char *msg , char *msgError )
{
	char strnum[30] ;
	long num ;
	do
		{
			puts( msg ) ;
			fflush( stdin ) ;
			gets( strnum ) ;
			num = atoi( strnum ) ;
			if ( num<InfLim || num>SupLim )
				{
					puts( msgError ) ;
					system( "pause" ) ;
				}
		} while( num<InfLim || num>SupLim ) ;
	return num;
}

//**************************************************SERVICIO DATO
void serviciodato( Tdato temp )
{
	printf( "%d\n" , temp->dato ) ;
}

//**************************************************SERVICIO ALUMNO
void servicioalumno( Talumno temp )
{
	printf( "%10ld %15s %15s %15s\n" , temp->matri , temp->nombre , temp->appat , temp->apmat ) ;
}

//**************************************************Addlista Dato
void AddlistaDato( Tdato *lista , Tdato *nuevo )
{
	Tdato temp = NULL ;
	if ( !*lista || ( *nuevo )->dato < ( *lista )->dato )
		{
			(*nuevo)->sig = *lista ;
			*lista = *nuevo ;
		}
		else
			{
				temp = *lista;
				while ( temp->sig && ( (*nuevo)->dato )>( temp->sig )->dato )
					{
						temp = temp->sig ;
					}
				(*nuevo)->sig = temp->sig ;
				temp->sig = *nuevo ;
			}
}

//**************************************************Addlista Alumno
void AddlistaAlumno( Talumno *lista , Talumno *nuevo )
{
	Talumno temp = NULL ;
	if ( !*lista || ( *nuevo )->matri < ( *lista )->matri )
		{
			( *nuevo )->sig = *lista ;
			*lista = *nuevo ;
		}
		else
			{
				temp = *lista;
				while ( temp->sig && ( ( *nuevo )->matri )>( temp->sig )->matri )
					{
						temp = temp->sig ;
					}
				(*nuevo)->sig = temp->sig ;
				temp->sig = *nuevo ;
			}
}

//**************************************************Printlista Dato
void PrintlistaDato( Tdato lista )
{
	Tdato temp = NULL ;
	temp = lista ;
	while ( temp )
		{
			serviciodato( temp ) ;
			temp = temp->sig ;
		}
}

//**************************************************Printlista Alumno
void PrintlistaAlumno( Talumno lista )
{
	Talumno temp = NULL ;
	temp = lista ;
	while ( temp )
		{
			servicioalumno( temp ) ;
			temp = temp->sig ;
		}
}

//**************************************************Findlista Dato
Tdato FindlistaDato( Tdato lista , int num )
{
	Tdato temp = NULL ;
	temp = lista ;
	while ( temp )
		{
			if ( temp->dato == num )
				{
					return temp ;
				}
			temp = temp->sig ;
		}
	return temp ;
}

//**************************************************Findlista Alumno
Talumno FindlistaAlumno( Talumno lista , long num )
{
	Talumno temp = NULL ;
	temp = lista ;
	while ( temp )
		{
			if ( temp->matri == num )
				{
					return temp ;
				}
			temp = temp->sig ;
		}
	return temp ;
}

//**************************************************Eliminar lista Dato
void DeletelistaDato( Tdato *lista , int num )
{
	if( ( *lista )!=NULL )
		{
			Tdato temp = NULL , anterior=NULL ;
			temp = ( *lista ) ;
			while ( ( temp!=NULL ) && ( temp->dato!=num ) )
        		{
            	anterior=temp ;
            	temp=temp->sig ;
        		}
			if( temp==NULL )
				{
					printf( "\n\nElemento no encontrado\n\n" ) ;
				}
				else if( anterior=NULL )
 					{
						( *lista )=( *lista )->sig ;
					}
					else
						{
							anterior->sig = temp->sig ;
							free( temp ) ;
						}
		}
		else
			{
				printf( "\n\nNo hay ningun dato...\n\n" ) ;
			}
}

//**************************************************Eliminar lista Alumno
void DeletelistaAlumno( Talumno *lista , long num )
{
	if( ( *lista )!=NULL )
		{
			Talumno temp = NULL , anterior=NULL ;
			temp = ( *lista ) ;
			while ( ( temp!=NULL ) && ( temp->matri!=num ) )
        		{
            	anterior=temp ;
            	temp=temp->sig ;
        		}
			if( temp==NULL )
				{
					printf( "\n\nElemento no encontrado\n\n" ) ;
				}
				else if( anterior=NULL )
 					{
						( *lista )=( *lista )->sig ;
					}
					else
						{
							anterior->sig = temp->sig ;
							free( temp ) ;
						}
		}
		else
			{
				printf( "\n\nNo hay ningun dato...\n\n" ) ;
			}
}

//**************************************************GenDato
Tdato GenDato( void )
{
	Tdato temp ;
	temp = ( Tdato )malloc( sizeof( stdato ) ) ;
	temp->dato = rand()%100 ;
	return temp;
}

//**************************************************GenAlumno
Talumno GenAlumno( void )
{
	int sex ;
	char vecNomFem[30][30]={ "Sofia" , "Camila" , "Valentina" , "Isabella" , "Ximena" , "Natalia" , "Mia" , "Fernanda" , "Nicole" , "Melanie" , "Regina" , "Renata" , "Antonella" , "Luna" , "Constanza" , "Zoe" , "Michelle" , "Aitana" , "Stephanie" , "Maria" , "Ana" , "Adriana" , "Fernanda" , "Sheila" , "Samantha" , "Mariana" , "Samara" , "Josefa" , "Alexa" , "Guadalupe" };
	char vecNomMas[30][30]={ "Luis" , "Miguel" , "Jose" , "Jesus" , "Alejandro" , "Juan" , "Ricardo" , "Daniel" , "Fernando" , "Jorge" , "Roberto" , "Carlos" , "Francisco" , "Manuel" , "Santiago" , "Sebastian" , "Javier" , "Nicolas" , "Eliud" , "Mateo" , "Matias" , "Gabriel" , "Emiliano" , "Rodrigo" , "Pablo" , "Emmanuel" , "Emilio" , "Christopher" , "Jonathan" , "Iker" };
	char vecAp[30][30]={ "Gonzalez" , "Rodriguez" , "Gomez" , "Huertas" , "Lopez" , "Diaz" , "Martinez" , "Perez" , "Garcia" , "Sanchez" , "Romero" , "Sosa" , "Alvarez" , "Torres" , "Ruiz" , "Ramirez" , "Flores" , "Acosta" , "Benitez" , "Medina" , "Suarez" , "Herrera" , "Aguirre" , "Pereyra" , "Gutierrez" , "Jimenez" , "Molina" , "Silva" , "Castro" , "Rojas" };
	Talumno nodo = NULL ;
	nodo=( Talumno )malloc( sizeof( stalumno ) ) ;
	nodo->status = 1 ;
	nodo->matri = ( rand()%1000000 )+300000 ;
	sex=( rand()%2 )+1 ;
	if( sex==1 )
		{
			strcpy( nodo->nombre , vecNomMas[ rand()%30 ] ) ;
		}
		else
			{
				strcpy( nodo->nombre , vecNomFem[ rand()%30 ] ) ;
			}
	strcpy( nodo->appat, vecAp[ rand()%30 ] ) ;
	strcpy( nodo->apmat, vecAp[ rand()%30 ] ) ;
	printf( "%10ld %15s %15s %15s\n" , nodo->matri , nodo->nombre , nodo->appat, nodo->apmat ) ;
	nodo->sig = NULL ;
	return nodo ;
}
