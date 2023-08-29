#include <iostream>
#include <string>
#include <locale>

class Empleado
{
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;

public:
    Empleado(int clave, const std::string& nombre, const std::string& domicilio, float sueldo, const std::string& reportaA)
    {
        ClaveEmpleado = clave;
        Nombre = nombre;
        Domicilio = domicilio;
        Sueldo = sueldo;
        ReportaA = reportaA;
    }

    void Imprime()
    {
        std::cout << "\tClave: " << ClaveEmpleado << std::endl;
        std::cout << "\tNombre: " << Nombre << std::endl;
        std::cout << "\tDomicilio: " << Domicilio << std::endl;
        std::cout << "\tSueldo: " << Sueldo << std::endl;
        std::cout << "\tReporta a: " << ReportaA << std::endl;
    }

    void CambiaDomic(const std::string& nuevoDomicilio)
    {
        Domicilio = nuevoDomicilio;
    }

    void CambiaReportaA(const std::string& nuevoReportaA)
    {
        ReportaA = nuevoReportaA;
    }

    void ActualSueldo(float incremento)
    {
        Sueldo *= (1 + incremento / 100);
    }

    void CambiaNombre(const std::string& nuevoNombre)
    {
        Nombre = nuevoNombre;
    }
};

int main()
{
    Empleado JefePlanta(123, "NombreJefePlanta", "DomicilioJefePlanta", 5000.0, "DirectorGeneral");
    Empleado JefePersonal(456, "NombreJefePersonal", "DomicilioJefePersonal", 6000.0, "DirectorGeneral");

    int opc;
    while (true)
    {
        setlocale(LC_ALL,"");
        std::cout << "\n------------MENÚ CONTROL DE EMPLEADO------------\n" << std::endl;
        std::cout << "\t1. Cambiar el domicilio de uno de los empleados" << std::endl;
        std::cout << "\t2. Actualizar el sueldo de un empleado" << std::endl;
        std::cout << "\t3. Imprimir los datos de un empleado" << std::endl;
        std::cout << "\t4. Cambiar nombre" << std::endl;
        std::cout << "\t5. Cambiar el nombre de la persona a quien reporta uno de los empleados" << std::endl;
        std::cout << "\t6. Salir" << std::endl;
        std::cout << "\n\tIngrese una opción: ";
        std::cin >> opc;

        if (opc == 6)
        {
            break;
        }

        int clave;
        switch (opc)
        {
        case 1:
            std::cout << "\tIngresa la clave del empleado: ";
            std::cin >> clave;
            if (clave == 123)
            {
                std::string nuevoDomicilio;
                std::cout << "\tIngresa el nuevo domicilio del empleado: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);
                JefePlanta.CambiaDomic(nuevoDomicilio);
                std::cout << "\n\tDomicilio actualizado\n" << std::endl;
            }
            else if (clave == 456)
            {
                std::string nuevoDomicilio;
                std::cout << "\tIngresa el nuevo domicilio del empleado: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);
                JefePersonal.CambiaDomic(nuevoDomicilio);
                std::cout << "\n\tDomicilio actualizado\n" << std::endl;
            }
            else
            {
                std::cout << "\tClave de empleado no válida." << std::endl;
            }
            break;
        case 2:
            float incremento;
            std::cout << "\tIngrese la clave del empleado: ";
            std::cin >> clave;
            if (clave == 123)
            {
                std::cout << "\tIngrese el incremento de sueldo del empleado (%): ";
                std::cin >> incremento;
                JefePlanta.ActualSueldo(incremento);
                std::cout << "\n\tIncremento agregado" << std::endl;
            }
            else if (clave == 456)
            {
                std::cout << "\tIngrese el incremento de sueldo del empleado (%): ";
                std::cin >> incremento;
                JefePersonal.ActualSueldo(incremento);
                std::cout << "\n\tIncremento agregado" << std::endl;
            }
            else
            {
                std::cout << "\tClave de empleado no válida." << std::endl;
            }
            break;
        case 3:
            std::cout << "\tIngrese la clave del empleado: ";
            std::cin >> clave;
            if (clave == 123)
            {
                JefePlanta.Imprime();
            }
            else if (clave == 456)
            {
                JefePersonal.Imprime();
            }
            else
            {
                std::cout << "\tClave de empleado no válida." << std::endl;
            }
            break;
        case 4:
            std::cout << "\tIngrese la clave del empleado: ";
            std::cin >> clave;
            if (clave == 123)
            {
                std::string nuevoNombre;
                std::cout << "\tIngrese el nuevo nombre del empleado: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoNombre);
                JefePlanta.CambiaNombre(nuevoNombre);
                std::cout << "\n\tNombre actualizado\n" << std::endl;
            }
            else if (clave == 456)
            {
                std::string nuevoNombre;
                std::cout << "\tIngrese el nuevo nombre del empleado: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoNombre);
                JefePersonal.CambiaNombre(nuevoNombre);
                std::cout << "\n\tNombre actualizado\n" << std::endl;
            }
            else
            {
                std::cout << "\tClave de empleado no válida." << std::endl;
            }
        case 5:
            std::cout << "\tIngrese la clave del empleado: ";
            std::cin >> clave;
            if (clave == 123)
            {
                std::string nuevoReportaA;
                std::cout << "\tIngrese el nuevo nombre de la persona a quien reporta uno de los empleados: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoReportaA);
                JefePlanta.CambiaReportaA(nuevoReportaA);
                std::cout << "\n\tNombre actualizado\n" << std::endl;
            }
            else if (clave == 456)
            {
                std::string nuevoReportaA;
                std::cout << "\tIngrese el nuevo nombre de la persona a quien reporta uno de los empleados: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoReportaA);
                JefePersonal.CambiaReportaA(nuevoReportaA);
                std::cout << "\n\tNombre actualizado\n" << std::endl;
            }
            else
            {
                std::cout << "\tClave de empleado no válida." << std::endl;
            }
        default:
            std::cout << "\tOpción no válida." << std::endl;
            break;
        }
    }

    return 0;
}

