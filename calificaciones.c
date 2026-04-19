#include <stdio.h>
int main() {
    const int estudiante = 5; 
    const int asignatura = 3;

    float notas[estudiante][asignatura]; 
    float suma, mayor, menor;
    int aprobados, reprobados;

    for (int i = 0; i < estudiante; i++) { 
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < asignatura; j++) { 
            do {
                printf("  Ingrese la nota de la asignatura %d (nota entre 0-10): ", j + 1);
                scanf("%f", &notas[i][j]); // Pide la nota y la guarda en la coordenada [i][j]
                if (notas[i][j] < 0 || notas[i][j] > 10) { 
                    printf("La nota debe estar entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10); 
        }
    }
    printf("\nReporte de los estudiantes\n");
    for (int i = 0; i < estudiante; i++) {
        suma = 0; 
        mayor = notas[i][0]; 
        menor = notas[i][0]; 

        for (int j = 0; j < asignatura; j++) {
            suma = suma + notas[i][j]; 
            if (notas[i][j] > mayor) mayor = notas[i][j]; 
            if (notas[i][j] < menor) menor = notas[i][j]; 
        }

        printf("\nEstudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f", 
                i + 1, suma / asignatura, mayor, menor);
    }

    printf("\nReporte de cada asignatura\n");
    for (int j = 0; j < asignatura; j++) {
        suma = 0; 
        aprobados = 0; 
        reprobados = 0;
        mayor = notas[0][j]; 
        menor = notas[0][j]; 

        for (int i = 0; i < estudiante; i++) {
            suma =suma + notas[i][j]; // Suma notas de la misma columna (asignatura)
            if (notas[i][j] > mayor) mayor = notas[i][j]; // Busca nota máxima de la materia
            if (notas[i][j] < menor) menor = notas[i][j]; // Busca nota mínima de la materia
            
            if (notas[i][j] >= 6) aprobados++; // Cuenta si es mayor o igual a 6
            else reprobados++; // Si no, cuenta como reprobado
        }
        printf("\nAsignatura %d -> Promedio: %.2f | Max: %.2f | Min: %.2f | Aprobados: %d | Reprobados: %d", 
                j + 1, suma / estudiante, mayor, menor, aprobados, reprobados);
    }
    printf("\n");
    return 0; 
}
