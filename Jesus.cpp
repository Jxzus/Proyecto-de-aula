#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Estudiante
{
    string nombre;
    string codigo;
    string carrera;
    float nota1, nota2, nota3, definitiva;
};

void CrearEstudiante(ofstream &estudiante)
{
    system("cls");
    Estudiante nuevoEstudiante;
    cout << "Agregue el codigo del estudiante: ";
    cin >> nuevoEstudiante.codigo;
    cout << "Agregue el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nuevoEstudiante.nombre);
    cout << "Agregue la carrera del estudiante: ";
    getline(cin, nuevoEstudiante.carrera);
    cout << "Agregue la primera nota del estudiante: ";
    cin >> nuevoEstudiante.nota1;
    cout << "Agregue la segunda nota del estudiante: ";
    cin >> nuevoEstudiante.nota2;
    cout << "Agregue la tercera nota del estudiante: ";
    cin >> nuevoEstudiante.nota3;
    nuevoEstudiante.definitiva = (nuevoEstudiante.nota1 + nuevoEstudiante.nota2 + nuevoEstudiante.nota3) / 3.0f;

    estudiante.open("H:\\Proyecto2\\estudiante.txt", ios::out | ios::app);
    if (estudiante.is_open())
    {
        estudiante << nuevoEstudiante.codigo << " " << nuevoEstudiante.nombre << endl;
        estudiante << nuevoEstudiante.carrera << endl;
        estudiante << nuevoEstudiante.nota1 << " " << nuevoEstudiante.nota2 << " " << nuevoEstudiante.nota3 << " " << nuevoEstudiante.definitiva << endl;
        estudiante.close();

        cout << "\n";
        cout << "Estudiante creado exitosamente. Redirigiendo al menu principal";
        for (int i = 1; i <= 5; i++)
        {
            cout << ".";
            Sleep(1000);
        }
    }
    else
    {
        cout << "Error al abrir el archivo." << endl;
    }
}

void MostrarEstudiantes(ifstream &archivo)
{
    system("cls");
    Estudiante estudiante;
    archivo.open("H:\\Proyecto2\\estudiante.txt", ios::in);
    if (!archivo)
    {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "\n";
    cout << "Creando tabla con los estudiantes";
    for (int i = 1; i <= 5; i++)
    {
        cout << ".";
        Sleep(1000);
    }
    cout << "\n";
    cout << "|    Codigo    |" << "      Nombre      |" << "      Carrera       |" << "   nota 1   |" << "   nota2   |" << "   nota3   |" << "   definitiva   |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;

    while (archivo >> estudiante.codigo >> ws)
    {
        getline(archivo, estudiante.nombre);
        getline(archivo, estudiante.carrera);
        archivo >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3 >> estudiante.definitiva;

        cout << "|   " << setw(10) << left << estudiante.codigo << " | "
             << setw(18) << left << estudiante.nombre << " | "
             << setw(21) << left << estudiante.carrera << " | "
             << setw(10) << right << estudiante.nota1 << " | "
             << setw(9) << right << estudiante.nota2 << " | "
             << setw(9) << right << estudiante.nota3 << " | "
             << setw(14) << right << estudiante.definitiva << " |" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;

    archivo.close();
    system("pause");
}

void BuscarEstudiante(ifstream &lectura)
{
    system("cls");
    Estudiante estudiante;
    string codigoAux;
    bool encontrado = false;
    cout << "Digite el codigo del estudiante que desea hallar: ";
    cin >> codigoAux;

    lectura.open("H:\\Proyecto2\\estudiante.txt", ios::in);
    if (!lectura)
    {
        cerr << "Error al abrir el archivo de estudiantes." << endl;
        return;
    }

    cout << "\n";
    cout << "Buscando al estudiante";
    for (int i = 1; i <= 5; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << "\n";
    while (lectura >> estudiante.codigo >> ws)
    {
        getline(lectura, estudiante.nombre);
        getline(lectura, estudiante.carrera);
        lectura >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3 >> estudiante.definitiva;

        if (estudiante.codigo == codigoAux)
        {
            cout << "Estudiante encontrado!" << endl;
            cout << "|    Codigo    |" << "      Nombre      |" << "      Carrera       |" << "   nota 1   |" << "   nota2   |" << "   nota3   |" << "   definitiva   |" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "|   " << setw(10) << left << estudiante.codigo << " | "
                 << setw(18) << left << estudiante.nombre << " | "
                 << setw(21) << left << estudiante.carrera << " | "
                 << setw(10) << right << estudiante.nota1 << " | "
                 << setw(9) << right << estudiante.nota2 << " | "
                 << setw(9) << right << estudiante.nota3 << " | "
                 << setw(14) << right << estudiante.definitiva << " |" << endl;
            encontrado = true;
            break;
        }
    }

    lectura.close();
    if (!encontrado)
        cout << "Dato no encontrado" << endl;
    system("pause");
}

void ModificarEstudiante() {
    system("cls");
    ifstream lectura("H:\\Proyecto2\\estudiante.txt");
    ofstream temporal("H:\\Proyecto2\\temp.txt");
    Estudiante estudiante;
    string codigoAux;
    bool encontrado = false;

    if (!lectura) {
        cerr << "Error al abrir el archivo de estudiantes." << endl;
        return;
    }

    cout << "Digite el codigo del estudiante que desea modificar: ";
    cin >> codigoAux;

    while (lectura >> estudiante.codigo >> ws) {
        getline(lectura, estudiante.nombre);
        getline(lectura, estudiante.carrera);
        lectura >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3 >> estudiante.definitiva;

        if (estudiante.codigo == codigoAux) {
            encontrado = true;
            int opcionModificar;
            cout << "Estudiante encontrado! Seleccione que desea modificar:" << endl;
            cout << "[1] Nombre" << endl;
            cout << "[2] Carrera" << endl;
            cout << "[3] Notas" << endl;
            cout << "[4] Regresar al menu principal" << endl;
            cout << "Ingrese la opcion: ";
            cin >> opcionModificar;

            switch (opcionModificar) {
                case 1:
                    cout << "Nuevo nombre: ";
                    cin.ignore();
                    getline(cin, estudiante.nombre);
                    break;
                case 2:
                    cout << "Nueva carrera: ";
                    cin.ignore();
                    getline(cin, estudiante.carrera);
                    break;
                case 3:
                    system("cls");
                    int notaOpcion;
                    cout << "Seleccione la nota que desea modificar:" << endl;
                    cout << "[1] Nota 1" << endl;
                    cout << "[2] Nota 2" << endl;
                    cout << "[3] Nota 3" << endl;
                    cout << "Ingrese la opcion: ";
                    cin >> notaOpcion;

                    switch (notaOpcion) {
                        case 1:
                            cout << "Nueva nota 1: ";
                            cin >> estudiante.nota1;
                            break;
                        case 2:
                            if (estudiante.nota1 == 0) {
                                cout << "Primero debe ingresar la nota 1." << endl;
                            } else {
                                cout << "Nueva nota 2: ";
                                cin >> estudiante.nota2;
                            }
                            break;
                        case 3:
                            if (estudiante.nota1 == 0 || estudiante.nota2 == 0) {
                                cout << "Primero debe ingresar la nota 1 y la nota 2." << endl;
                            } else {
                                cout << "Nueva nota 3: ";
                                cin >> estudiante.nota3;
                            }
                            break;
                        default:
                            cout << "Opcion incorrecta." << endl;
                            break;
                    }
                    estudiante.definitiva = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3.0f;
                    break;
                case 4:
                    cout << "\nVolviendo al menu principal";
                    for (int i = 1; i <= 5; i++) {
                        cout << ".";
                        Sleep(1000);
                    }
                    return;
                default:
                    cout << "Opcion incorrecta" << endl;
                    break;
            }
            cout << "Estudiante modificado correctamente." << endl;
        }
        temporal << estudiante.codigo << " " << estudiante.nombre << endl;
        temporal << estudiante.carrera << endl;
        temporal << estudiante.nota1 << " " << estudiante.nota2 << " " << estudiante.nota3 << " " << estudiante.definitiva << endl;
    }

    lectura.close();
    temporal.close();

    remove("H:\\Proyecto2\\estudiante.txt");
    rename("H:\\Proyecto2\\temp.txt", "H:\\Proyecto2\\estudiante.txt");

    if (!encontrado)
        cout << "Dato no encontrado." << endl;
    system("pause");
}

void BorrarEstudiante()
{
    system("cls");
    ifstream lectura("H:\\Proyecto2\\estudiante.txt");
    ofstream temporal("H:\\Proyecto2\\temp.txt");
    Estudiante estudiante;
    string codigoAux;
    bool encontrado = false;

    if (!lectura)
    {
        cerr << "Error al abrir el archivo de estudiantes." << endl;
        return;
    }

    cout << "Digite el codigo del estudiante que desea borrar: ";
    cin >> codigoAux;

    while (lectura >> estudiante.codigo >> ws)
    {
        getline(lectura, estudiante.nombre);
        getline(lectura, estudiante.carrera);
        lectura >> estudiante.nota1 >> estudiante.nota2 >> estudiante.nota3 >> estudiante.definitiva;

        if (estudiante.codigo == codigoAux)
        {
            encontrado = true;
            cout << "Estudiante borrado correctamente." << endl;
        }
        else
        {
            temporal << estudiante.codigo << " " << estudiante.nombre << endl;
            temporal << estudiante.carrera << endl;
            temporal << estudiante.nota1 << " " << estudiante.nota2 << " " << estudiante.nota3 << " " << estudiante.definitiva << endl;
        }
    }

    lectura.close();
    temporal.close();

    remove("H:\\Proyecto2\\estudiante.txt");
    rename("H:\\Proyecto2\\temp.txt", "H:\\Proyecto2\\estudiante.txt");

    if (!encontrado)
        cout << "Dato no encontrado." << endl;
    system("pause");
}

int main()
{
    int opcion;

    do
    {
        system("cls");
        cout << "M E N U  P R I N C I P A L" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cout << "[1] Crear estudiante" << endl;
        cout << "[2] Mostrar estudiantes" << endl;
        cout << "[3] Buscar estudiante" << endl;
        cout << "[4] Borrar estudiante" << endl;
        cout << "[5] Modificar estudiante" << endl;
        cout << "[6] Salir" << endl;
        cout << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        if (!(cin >> opcion)) {
            // Clear error flag
            cin.clear();
            // Ignore remaining input
            cin.ignore();
            cout << "Opcion no valida. Por favor, ingrese un numero entre 1 y 6." << endl;
            Sleep(2000);
            continue; // Volver al principio del bucle
        }
        switch (opcion)
        {
        case 1:
            cout << "Ha seleccionado crear estudiante" << endl;
            {
                ofstream estudiante;
                CrearEstudiante(estudiante);
            }
            break;
        case 2:
            cout << "Ha seleccionado mostrar estudiantes" << endl;
            {
                ifstream archivo;
                MostrarEstudiantes(archivo);
            }
            break;
        case 3:
            cout << "Ha seleccionado buscar estudiante" << endl;
            {
                ifstream lectura;
                BuscarEstudiante(lectura);
            }
            break;
        case 4:
            cout << "Ha seleccionado borrar estudiante" << endl;
            BorrarEstudiante();
            break;
        case 5:
            cout << "Ha seleccionado modificar estudiante" << endl;
            ModificarEstudiante();
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}
