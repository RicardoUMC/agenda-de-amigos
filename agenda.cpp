// Autor: Ricardo Uriel Mora Campos

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>

using namespace std;

struct nodo
{
  string nombre;
  string telefono;
  string correo;
  nodo *sig;
};

typedef nodo *apu_nodo;

class lista
{
  public:
  apu_nodo inicio;
};

lista agenda;
int opcion;
int contactos = 0;

void menuInicial(void);
void menuCompleto(void);

void agregar(void);
void eliminar(void);
void mostrar(void);
void actualizar(void);
void menu_actualizar(apu_nodo modificado);
void guardar(void);
void recuperar(void);

string cadena(char* a, int size);
string telefono(void);
string correo(void);

int main(void)
{
  system("cls");
  cout << "[NO. CONTACTOS: " << contactos << "]" << '\n' << endl;

  if (contactos<1) menuInicial();
  else menuCompleto();

  return 0;
}

//MENÚS DIFERENTES
void menuInicial(void)
{
  // MENU INICIAL

  cout << "MENU:" << '\n';
  cout << "1. Agregar amigos." << '\n';
  FILE *fp = fopen("./datos.csv", "r");
  if (fp != NULL)
  {
    fclose(fp);
    cout << "2. Recuperar de unidad fisica." << '\n';
    cout << "3. Salir." << '\n';
    cout << '\n' << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
      case 1:
        // Agregar amigos
        agregar();
        break;
      case 2:
        // Recuperar de externo
        recuperar();
        break;
      case 3:
        // Salir
        system("cls");
        exit(-1);
        break;
      default:
        cout << '\n' << "Elija una opcion valida." << endl;

        cout << '\n' << "Pulse cualquier tecla para continuar.";
        getch();
        main();
        break;
    }
  }
  else
  {
    cout << "2. Salir." << '\n';
    cout << '\n' << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
      case 1:
        // Agregar amigos
        agregar();
        break;
      case 2:
        // Salir
        system("cls");
        exit(-1);
        break;
      default:
        cout << '\n' << "Elija una opcion valida." << endl;

        cout << '\n' << "Pulse cualquier tecla para continuar.";
        getch();
        main();
        break;
    }
  }
}

void menuCompleto(void)
{
  // MENU COMPLETO
  cout << "MENU:" << '\n';
  cout << "1. Agregar amigos." << '\n';
  cout << "2. Ver amigos." << '\n';
  cout << "3. Actualizar amigo." << '\n';
  cout << "4. Borrar amigo." << '\n';
  cout << "5. Guardar a unidad fisca." << '\n';
  FILE *fp = fopen("./datos.csv", "r");
  if (fp != NULL)
  {
    fclose(fp);
    cout << "6. Recuperar de unidad fisica." << '\n';
    cout << "7. Salir." << '\n';
    cout << '\n' << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
      case 1:
      // Agregar amigos
      agregar();
      break;
      case 2:
      // Ver amigos
      mostrar();
      break;
      case 3:
      // Actualizar amigo
      actualizar();
      break;
      case 4:
      // Borrar amigo
      eliminar();
      break;
      case 5:
      // Guardar en unidad
      guardar();
      break;
      case 6:
      // Recuperar de externo
      recuperar();
      break;
      case 7:
      // Salir
      system("cls");
      exit(-1);
      break;
      default:
      cout << '\n' << "Elija una opcion valida." << endl;

      cout << '\n' << "Pulse cualquier tecla para continuar.";
      getch();
      main();
      break;
    }

  }
  else
  {
    cout << "6. Salir." << '\n';
    cout << '\n' << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
      case 1:
      // Agregar amigos
      agregar();
      break;
      case 2:
      // Ver amigos
      mostrar();
      break;
      case 3:
      // Actualizar amigo
      actualizar();
      break;
      case 4:
      // Borrar amigo
      eliminar();
      break;
      case 5:
      // Guardar en unidad
      guardar();
      break;
      case 6:
      // Salir
      system("cls");
      exit(-1);
      break;
      default:
      cout << '\n' << "Elija una opcion valida." << endl;

      cout << '\n' << "Pulse cualquier tecla para continuar.";
      getch();
      main();
      break;
    }
  }

}

// FUNCIONES
void agregar(void)
{
  system("cls");

  char *nom = (char*) malloc(100*sizeof(char));
  apu_nodo nuevo = new(nodo);

  cout << "AGREGA A TU AMIGO" << '\n';
  cin.ignore();
  cout << "Nombre: ";
  cin.getline(nom,100);
  nuevo->nombre = cadena(nom,strlen(nom));
  nuevo->telefono = telefono();
  nuevo->correo = correo();

  apu_nodo desborde = agenda.inicio;
  apu_nodo ultimo;

  while (desborde != NULL)
  {
    ultimo = desborde;
    desborde = desborde->sig;
  }

  if (agenda.inicio == NULL)
  {
    agenda.inicio = nuevo;
  }
  else
  {
    ultimo->sig = nuevo;
  }

  nuevo->sig = desborde;

  contactos++;

  free(nom);

  cout << '\n' << "Pulse cualquier tecla para continuar.";
  getch();
  main();
}

void mostrar(void)
{
  system("cls");

  apu_nodo aux = agenda.inicio;

  cout << "LISTA DE AMIGOS:" << '\n';

  int conta = 1;
  while (aux != NULL)
  {
    cout << '\t' << "[CONTACTO " << conta << "]" << '\n';
    cout << '\t' << '\t' << "Nombre: " << aux->nombre << '\n';
    cout << '\t' << '\t' << "Tel: " << aux->telefono << '\n';
    cout << '\t' << '\t' << "Correo: " << aux->correo << '\n';
    aux = aux->sig;
    conta++;
  }


  cout << '\n' << "Pulse cualquier tecla para continuar.";
  getch();
  main();
}

void eliminar(void)
{
  apu_nodo aux;
  int conta;

  do
  {
    system("cls");

    aux = agenda.inicio;

    conta = 0;
    while (aux != NULL)
    {
      conta++;
      cout << '\t' << "[CONTACTO " << conta << "]" << '\n';
      cout << '\t' << '\t' << "Nombre: " << aux->nombre << '\n';
      cout << '\t' << '\t' << "Tel: " << aux->telefono << '\n';
      cout << '\t' << '\t' << "Correo: " << aux->correo << '\n';
      aux = aux->sig;
    }

    cout << endl << "Ingrese numero de contacto a eliminar: ";
    cin >> opcion;
  } while(opcion > conta || opcion < 1);

  apu_nodo eliminado = agenda.inicio;
  apu_nodo salto;

  for (int i = 1; i < opcion; i++)
  {
    salto = eliminado;
    eliminado = eliminado->sig;
  }

  if (opcion == 1)
  {
    agenda.inicio = agenda.inicio->sig;
  }
  else
  {
    salto->sig = eliminado->sig;
  }

  contactos--;

  cout << endl << "CONTACTO ELIMINADO CORRECTAMENTE." << endl;


  cout << '\n' << "Pulse cualquier tecla para continuar.";
  getch();
  main();
}

void actualizar(void)
{
  int conta;
  apu_nodo aux;

  do
  {
    system("cls");

    aux = agenda.inicio;

    conta = 0;
    while (aux != NULL)
    {
      conta++;
      cout << "[CONTACTO " << conta << "]" << '\n';
      aux = aux->sig;
    }

    cout << endl << "Ingrese numero de contacto a modificar: ";
    cin >> opcion;
  } while(opcion > conta || opcion < 1);

  apu_nodo desborde = agenda.inicio;
  apu_nodo modificado;

  for (int i = 0; i < opcion && modificado != NULL; i++)
  {
    modificado = desborde;
    desborde = desborde->sig;
  }

  if (modificado == NULL)
  {
    cout << endl << "NO SE PUDO MODIFICAR." << endl;

    cout << '\n' << "Pulse cualquier tecla para continuar.";
    getch();
    main();
  }

  menu_actualizar(modificado);
}

void menu_actualizar(apu_nodo modificado)
{
  do
  {
    system("cls");

    cout << "ACCIONES:" << '\n';
    cout << "1. Modificar nombre." << '\n';
    cout << "2. Modificar telefono." << '\n';
    cout << "3. Modificar correo." << '\n';
    cout << "4. Modificar todo." << '\n';
    cout << "5. Regresar." << '\n';
    cout << '\n' << "Elija una opcion: ";
    cin >> opcion;

  } while(opcion < 1 || opcion > 5);

  system("cls");

  cout << "NUEVOS VALORES:" << '\n';

  char *nom = (char*) malloc(100*sizeof(char));

  switch (opcion)
  {
    case 1:
      cin.ignore();
      cout << "Nombre: ";
      cin.getline(nom,100);
      modificado->nombre = cadena(nom,strlen(nom));
      break;
    case 2:
      modificado->telefono = telefono();
      break;
    case 3:
      modificado->correo = correo();
      break;
    case 4:
      cin.ignore();
      cout << "Nombre: ";
      cin.getline(nom,100);
      modificado->nombre = cadena(nom,strlen(nom));
      modificado->telefono = telefono();
      modificado->correo = correo();
      break;
    case 5:
      main();
      break;
    default:
      system("cls");
      cout << "ERROR AL MODIFICAR. REGRESANDO..." << endl;

      cout << '\n' << "Pulse cualquier tecla para continuar.";
      getch();
      main();
      break;
  }

  cout << endl << "ACTUALIZADO CORRECTAMENTE." << endl;


  cout << '\n' << "Pulse cualquier tecla para continuar.";
  getch();

  free(nom);
  menu_actualizar(modificado);
}

void guardar(void)
{
  FILE *fp;
  fp = fopen("./datos.csv", "r+t");

  if(fp == NULL)
  {
    fp = fopen("./datos.csv", "w+t");
  }
  else
  {
    fclose(fp);
    fp = fopen("./datos.csv", "w+t");
  }

  apu_nodo aux = agenda.inicio;

  while (aux != NULL)
  {
    fprintf(fp, "%s,", aux->nombre.c_str());
    fprintf(fp, "%s,", aux->telefono.c_str());
    fprintf(fp, "%s,", aux->correo.c_str());
    fputs("\n", fp);
    aux = aux->sig;
  }

  fclose(fp);

  cout << endl << "LOS DATOS FUERON GUARDADOS CORRECTAMENTE." << endl;


  cout << '\n' << "Pulse cualquier tecla para continuar.";
  getch();
  main();
}

void recuperar(void)
{
  FILE *fp;
  fp = fopen("./datos.csv", "r");

  if(fp == NULL)
  {
    system("cls");
    cout << "No se encontro el archivo 'datos.csv'." << endl;

    cout << '\n' << "Pulse cualquier tecla para continuar.";
    getch();
    main();
  }

  char *pch = (char *) malloc(sizeof(char));
  if (pch == NULL) {
    fclose(fp);
    cout << "ERROR EN EL BUFFER." << endl;

    cout << '\n' << "Pulse cualquier tecla para continuar.";
    getch();
    main();
  }

  agenda.inicio = NULL;

  while (!feof(fp))
  {
    apu_nodo nuevo = new(nodo);

    char str[100];
    fgets(str, sizeof(str), fp);

    char *buffer = (char*) malloc((strlen(str)+1)*sizeof(char));
    strcpy(buffer,str);

    pch = strtok(buffer,",");
    nuevo->nombre = cadena(pch,strlen(pch));
    pch = strtok(NULL,",");
    nuevo->nombre = cadena(pch,strlen(pch));
    pch = strtok(NULL,",");
    nuevo->nombre = cadena(pch,strlen(pch));

    apu_nodo desborde = agenda.inicio;
    apu_nodo ultimo;

    while (desborde != NULL)
    {
      ultimo = desborde;
      desborde = desborde->sig;
    }

    if (agenda.inicio == NULL)
    {
      agenda.inicio = nuevo;
    }
    else
    {
      ultimo->sig = nuevo;
    }

    nuevo->sig = desborde;
  }

  apu_nodo desborde = agenda.inicio;
  apu_nodo ultimo;

  contactos = 0;

  while (desborde->sig != NULL)
  {
    contactos++;
    ultimo = desborde;
    desborde = desborde->sig;
  }
  contactos++;

  string datos = ultimo->nombre + ultimo->telefono + ultimo->correo;
  string repetido = ultimo->sig->nombre + ultimo->sig->telefono + ultimo->sig->correo;

  if (datos == repetido)
  {
    contactos--;
    ultimo->sig = NULL;
  }

  fclose(fp);

  cout << endl << "LOS DATOS FUERON GUARDADOS CORRECTAMENTE." << endl;


  cout << '\n' << "Pulse cualquier tecla para continuar.";
  getch();
  main();
}

//USABLES
string cadena(char* a, int size)
{
  int i;
  string s = "";
  for (i = 0; i < size; i++)
  {
    s = s + a[i];
  }
  return s;
}

string telefono(void)
{
  string cadena;

  do {
    cout << "Telefono: ";
    cin >> cadena;
  } while(cadena.length()!=10);

  return cadena;
}

string correo(void)
{
  size_t arroba, punto;
  string cadena;

  do {
    cout << "Correo: ";
    cin >> cadena;
    arroba = cadena.find('@');
    punto = cadena.find('.');
    if (arroba == string::npos || punto == string::npos)
    {
      arroba = 0;
    }
  } while(arroba == 0 || punto <= (arroba+1) || (cadena.length()-1) == punto);

  return cadena;
}
