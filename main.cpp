#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Profesor
{
private:
    string nombre;
    string apellido;
    string sexo;
    int edad;
    string tituloProfesion;
    string noCedulaProfesional;

public:
    // Constructor con todos los datos del profesor
    Profesor(string nombre, string apellido, string sexo, int edad,
             string tituloProfesion, string noCedulaProfesional)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->sexo = sexo;
        this->edad = edad;
        this->tituloProfesion = tituloProfesion;
        this->noCedulaProfesional = noCedulaProfesional;
    }

    // Para leer cada dato
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    string getSexo() { return sexo; }
    int getEdad() { return edad; }
    string getTituloProfesion() { return tituloProfesion; }
    string getNoCedulaProfesional() { return noCedulaProfesional; }
};

// Materia que cursa el alumno
class Materia
{
private:
    string nombre;
    int numeroCreditos;
    Profesor profesor;

public:
    // Constructor: cada materia tiene su profesor
    Materia(string nombre, int numeroCreditos, Profesor profesor)
        : profesor(profesor)
    {
        this->nombre = nombre;
        this->numeroCreditos = numeroCreditos;
    }

    // Para leer cada dato
    string getNombre() { return nombre; }
    int getNumeroCreditos() { return numeroCreditos; }
    Profesor getProfesor() { return profesor; }
};

class Alumno
{
private:
    string nombre;
    string apellido;
    string noControlEscolar;
    int edad;
    string sexo;
    int semestre;
    vector<Materia> materias;

public:
    // Constructor con los datos del alumno
    Alumno(string nombre, string apellido, string noControlEscolar,
           int edad, string sexo, int semestre)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->noControlEscolar = noControlEscolar;
        this->edad = edad;
        this->sexo = sexo;
        this->semestre = semestre;
    }

    // Para leer cada dato
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    string getNoControlEscolar() { return noControlEscolar; }
    int getEdad() { return edad; }
    string getSexo() { return sexo; }
    int getSemestre() { return semestre; }
    vector<Materia> getMaterias() { return materias; }

    // Agrego una materia a las que cursa el alumno
    void agregarMateria(Materia materia)
    {
        materias.push_back(materia);
    }
};

int main()
{
    // Datos de ejemplo para probar que las clases se conectan
    Profesor profesora("Laura", "Gomez Hernandez", "F", 38,
                       "Licenciatura en Informatica", "1234567");

    Materia materia1("Programacion Orientada a Objetos", 8, profesora);
    Materia materia2("Bases de Datos", 7, profesora);

    Alumno alumno("Maria Fernanda", "Ruiz Torres", "202601",
                  19, "F", 3);
    alumno.agregarMateria(materia1);
    alumno.agregarMateria(materia2);

    // Muestro los datos para comprobar que todo quedo guardado
    cout << "=== SISTEMA DE CONTROL ESCOLAR ===" << endl;
    cout << endl;

    cout << "--- Alumno ---" << endl;
    cout << "Nombre: " << alumno.getNombre() << " " << alumno.getApellido() << endl;
    cout << "No. de control: " << alumno.getNoControlEscolar() << endl;
    cout << "Edad: " << alumno.getEdad() << endl;
    cout << "Sexo: " << alumno.getSexo() << endl;
    cout << "Semestre: " << alumno.getSemestre() << endl;
    cout << endl;

    cout << "--- Materias que cursa ---" << endl;
    for (int i = 0; i < (int)alumno.getMaterias().size(); i++)
    {
        Materia m = alumno.getMaterias()[i];
        cout << (i + 1) << ". " << m.getNombre()
             << " (" << m.getNumeroCreditos() << " creditos)" << endl;
        cout << "   Profesor: " << m.getProfesor().getNombre()
             << " " << m.getProfesor().getApellido() << endl;
    }
    cout << endl;

    cout << "--- Profesor ---" << endl;
    cout << "Nombre: " << profesora.getNombre() << " " << profesora.getApellido() << endl;
    cout << "Sexo: " << profesora.getSexo() << endl;
    cout << "Edad: " << profesora.getEdad() << endl;
    cout << "Titulo: " << profesora.getTituloProfesion() << endl;
    cout << "No. de cedula: " << profesora.getNoCedulaProfesional() << endl;

    return 0;
}
