#include <iostream>
#include <string>
#include <locale>

class Materia
{
    private:
        int Clave;
        std::string Nombre;
        std::string ProfesorTit;
    public:

    Materia(int clave, const std::string& nombre, const std::string& profesorTit)
    {
        Clave = clave;
        Nombre = nombre;
        ProfesorTit = profesorTit;
    }

    void Imprime()
    {
        std::cout << "\tClave de la Materia: " << Clave << std::endl;
        std::cout << "\tNombre de la Materia: " << Nombre << std::endl;
        std::cout << "\tProfesor: " << ProfesorTit << std::endl;
    }

    void CambiaClave(int nuevaClave)
    {
        Clave = nuevaClave;
    }

    void CambiaMaestro(const std::string& nuevoMaestro)
    {
        ProfesorTit = nuevoMaestro;
    }
};

int main()
{
    Materia Programacion(123, "Programacion", "ProfesorProgramacion");
    std::string nuevoProfesor; // Declaramos la variable aqu�

    int opc;

    setlocale(LC_ALL, ""); // Movido aqu� para que se aplique durante todo el ciclo

    while (true)
    {
        std::cout << "\n\t------------MEN� CONTROL DE MATERIAS------------\n" << std::endl;
        std::cout << "\t1. Cambiar la clave de la materia Programaci�n." << std::endl;
        std::cout << "\t2. Cambiar el nombre del maestro que imparte la materia BasesDatos." << std::endl;
        std::cout << "\t3. Imprimir todos los datos de la materia BasesDatos." << std::endl;
        std::cout << "\t4. Salir" << std::endl;
        std::cout << "\n\tIngresa una opci�n: ";
        std::cin >> opc;

        std::cin.ignore();  // Ignora el car�cter de nueva l�nea en el b�fer

        if (opc == 4)
        {
            break;
        }

        switch (opc)
        {
        case 1:
            int nuevaClave;
            std::cout << "\tIngresa la nueva clave de la materia Programacion: ";
            std::cin >> nuevaClave;
            Programacion.CambiaClave(nuevaClave);
            std::cout << "\tLa clave se actualiz� correctamente.\n" << std::endl;
            break;
        case 2:
            std::cout << "\tIngresa el nuevo nombre del maestro de la materia BasesDatos: ";
            //std::cin.ignore();
            std::getline(std::cin, nuevoProfesor);
            std::cout << "\tSe cambi� correctamente el nombre del maestro.\n" << std::endl;
            break;
        case 3:
        {
            Materia BasesDatos(345, "BasesDatos", nuevoProfesor); // Crear la instancia aqu�
            std::cout << "\n\t\tDatos de la materia BasesDatos" << std::endl;
             std::cout << "\t--------------------------------------------------" << std::endl;
            BasesDatos.Imprime();

        }
        break;
        default:
            std::cout << "\n\tOpci�n no v�lida." << std::endl;
            break;
        }
    }

    return 0;
}
