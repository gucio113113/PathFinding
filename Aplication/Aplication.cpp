// Aplication.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <PathFinding/PathNodeTable.h>
#include <PathFinding/SquareSlantPathFinder.h>
#include <PathFinding/GridGenerator.h>
#include <vector>



int main()
{
    SquareSlantPathFinder path;
    GridGenerator generator;
 
    generator.SetWidth(10);
    generator.SetHeight(10);
    
    SquareSlantNodeTable squares=generator.GenerateSquareSlantGrid();
    path.SetNodeTable(&squares);

    squares.SetUnPassable(1, 1);
    squares.SetUnPassable(1, 2);
    squares.SetUnPassable(1, 3);
    squares.SetUnPassable(1, 4);

    squares.SetUnPassable(2, 1);
    squares.SetUnPassable(3, 1);
    squares.SetUnPassable(4, 1);

    squares.ShowCost();
    squares.ShowNumberNeigbors();


    std::stack<Vector2i> FindedPath = path.GetPath(0, 0, 6, 6);



    std::cout << "Hello World!\n";
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
