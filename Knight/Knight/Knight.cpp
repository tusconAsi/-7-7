#include <iostream>
#include <random>
#include <ostream>
#include <Windows.h>

using namespace std;

void SetRussian()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void PrintDelimeter()
{
    cout << "------------------" << endl;
}

int PackPosition(const int row, const int column, int fieldColumnCount)
{
    return row*fieldColumnCount + column;
}

int UnpackPositionRow(const int position, int fieldColumnCount)
{
    return position/fieldColumnCount;
}

int UnpackPositionColumn(const int position, int fieldColumnCount)
{
    return position % fieldColumnCount;
}

int GetRelativePosition(
    const int position, const int deltaRow, const int deltaColumn,
    const int fieldColumnCount, const int fieldRowCount)
{
    const int baseColumn = UnpackPositionColumn(position, fieldColumnCount);
    const int baseRow = UnpackPositionRow(position, fieldColumnCount);
    const int column = baseColumn + deltaColumn;
    const int row = baseRow + deltaRow;

    if (column < 0 || row < 0 ||
        column >= fieldColumnCount || row >= fieldRowCount)
    {
        return -1;
    }
    
    return PackPosition(row, column, fieldColumnCount); 
}

int GetAccessiblePositionsCount(int* draftPositions, const int positionsSize, const int fieldColumnCount, const int fieldRowCount)
{
    int accessiblePositionsCount = 0;
    
    for (int counter = 0; counter < positionsSize; counter++)
    {
        int checkingPosition = draftPositions[counter];
        if (checkingPosition >= 0 && checkingPosition < fieldColumnCount * fieldRowCount)
        {
            accessiblePositionsCount++;
        }
    }

    return accessiblePositionsCount;
}

int* GetAccessiblePositions(int* draftPositions, const int positionsSize, const int fieldColumnCount, const int fieldRowCount)
{
    const int accessiblePositionsCount = GetAccessiblePositionsCount(draftPositions, positionsSize, fieldColumnCount, fieldRowCount);
    int* accessiblePositions = new int[accessiblePositionsCount];
    int accessiblePositionIndex = 0;
    
    for (int counter = 0; counter < positionsSize; counter++)
    {
        int position = draftPositions[counter];
        if (position >= 0 && position < fieldColumnCount * fieldRowCount)
        {
            accessiblePositions[accessiblePositionIndex] = position;
            accessiblePositionIndex++;
        }
    }

    return accessiblePositions;
}

int* GetKnightDraftTurns(const int position, const int fieldColumnCount, const int fieldRowCount)
{
    int* draftTurns = new int[]
    {
        GetRelativePosition(position, 3, -1, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, 3, 1, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, -3, 1, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, -3, -1, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, -1, -3, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, 1, -3, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, 1, 3, fieldColumnCount, fieldRowCount),
        GetRelativePosition(position, -1, 3, fieldColumnCount, fieldRowCount),
    };

    return draftTurns;
}

int GetKnightDraftTurnsCount()
{
    return 8;
}


int* GetKnightTurns(const int position, const int fieldColumnCount, const int fieldRowCount)
{
    int* draftTurns = GetKnightDraftTurns(position, fieldColumnCount, fieldRowCount);
    int draftTurnsCount= GetKnightDraftTurnsCount();

    int* accessiblePositions = 
        GetAccessiblePositions(draftTurns, draftTurnsCount, fieldColumnCount, fieldRowCount);
    delete [] draftTurns;
    return accessiblePositions;
}

int GetKnightTurnsCount(const int position, const int fieldColumnCount, const int fieldRowCount)
{
    int* draftTurns = GetKnightDraftTurns(position, fieldColumnCount, fieldRowCount);
    int draftTurnsCount= GetKnightDraftTurnsCount();

    int accessiblePositionsCount = 
        GetAccessiblePositionsCount(draftTurns, draftTurnsCount, fieldColumnCount, fieldRowCount);
    delete [] draftTurns;
    return accessiblePositionsCount;
}

int** AddTurnsToPath(const int startPosition, const int* turnVariables, const int turnVariablesCount)
{
    int** paths = new int*[turnVariablesCount];

    for (int counter = 0; counter < turnVariablesCount; counter++)
    {
        paths[counter] = new int[] {startPosition, turnVariables[counter]};
    }

    return paths;
}

void PrintPackedPaths(int** paths, const int pathsCount, const int turnsCount)
{
    cout << "Пути:" << endl;
    for (int pathCounter = 0; pathCounter < pathsCount; pathCounter++)
    {
        cout << "Путь " << pathCounter << " : ";

        for (int turnsCounter = 0; turnsCounter < turnsCount; turnsCounter++)
        {
            cout << paths[pathCounter][turnsCounter] << " ";
        }

        cout << endl;
    }
}

void PrintUnpackedPaths(
    int** paths, const int pathsCount, const int turnsCount,
    const int fieldColumnsCount)
{
    cout << "Пути:" << endl;
    for (int pathCounter = 0; pathCounter < pathsCount; pathCounter++)
    {
        cout << "Путь " << pathCounter << " : ";

        for (int turnsCounter = 0; turnsCounter < turnsCount; turnsCounter++)
        {
            int position = paths[pathCounter][turnsCounter];
            int row = UnpackPositionRow(position, fieldColumnsCount);
            int column = UnpackPositionColumn(position, fieldColumnsCount);
            cout << row << "x" << column << " ";
        }

        cout << endl;
    }
}

void DeletePaths(int** paths, int pathCount)
{
    for (int counter = 0; counter < pathCount; counter++)
    {
        delete [] paths[counter];
    }

    delete [] paths;
}

int** AddTurnsToPath(int* path, const int turnsCount, const int* turnVariables, const int turnVariablesCount)
{
    int** paths = new int*[turnVariablesCount];

    for (int counter = 0; counter < turnVariablesCount; counter++)
    {
        paths[counter] = new int[turnsCount + 1];
        memcpy(paths[counter], path, sizeof(int) * turnsCount);
        paths[counter][turnsCount] = turnVariables[counter];
    }
    
    return paths;
}

bool IsCircledPath(int* path, const int turnsCount)
{
    for (int counter = 0; counter < turnsCount; counter++)
    {
        for (int checkCounter = counter + 1; checkCounter < turnsCount; checkCounter++)
        {
            if (path[counter] == path[checkCounter])
            {
                return true;
            }
        }
    }

    return false;
}

int GetNonCircledPathsCount(int** paths, const int pathsCount, const int turnsCount)
{
    int nonCircledPathsCount = 0;
    
    for (int pathCounter = 0; pathCounter < pathsCount; pathCounter++)
    {
        if (!IsCircledPath(paths[pathCounter], turnsCount))
        {
            nonCircledPathsCount++;
        }
    }

    return nonCircledPathsCount;
}

int** FilterCircledPaths(int** paths, const int pathsCount, const int turnsCount)
{
    const int nonCircledPathsCount = GetNonCircledPathsCount(paths, pathsCount, turnsCount);
    int** nonCircledPaths = new int*[nonCircledPathsCount];
    int nonCircledPathIndex = 0;

    for (int counter = 0; counter < pathsCount; counter++)
    {
        if (!IsCircledPath(paths[counter], turnsCount))
        {
            nonCircledPaths[nonCircledPathIndex] = paths[counter];
            nonCircledPathIndex++;
        } else
        {
            delete [] paths[counter];
        }
    }

    return nonCircledPaths;
}

int* FindPath(int** paths,
    const int &pathsCount, const int turnsCount,
    const int fieldColumnCount, const int fieldRowCount)
{
    cout << "Подбираю ход коня номер: " << turnsCount + 1 << "." << endl;
    cout << "Предыдущее количество вариантов хода коня: " << pathsCount << "." << endl;
    
    int newPathsCount = 0;
    int ** newPaths = new int*[0];
    
    for (int pathCounter = 0; pathCounter < pathsCount; pathCounter++)
    {
        int position = paths[pathCounter][turnsCount - 1];
        int* positions = GetKnightTurns(position, fieldColumnCount, fieldRowCount);
        int positionsCount = GetKnightTurnsCount(position, fieldColumnCount, fieldRowCount);
        int** pathVariables = AddTurnsToPath(
            paths[pathCounter], turnsCount,
            positions, positionsCount);
        int** tempPaths = new int*[newPathsCount + positionsCount];
        memcpy(tempPaths, newPaths, sizeof(int*) * newPathsCount);
        for (int counter = 0; counter < positionsCount; counter++)
        {
            tempPaths[counter + newPathsCount] = pathVariables[counter];
        }
        newPathsCount += positionsCount;
        delete [] newPaths;
        newPaths = tempPaths;
    }

    int turns = turnsCount + 1;
    //PrintUnpackedPaths(newPaths, newPathsCount, turns, fieldColumnCount);

    const int notCircledPathsCount = GetNonCircledPathsCount(newPaths, newPathsCount, turns);

    if (notCircledPathsCount == 0)
    {
        cout << "Невозможно достичь покрытия всей доски." << endl;
        return nullptr;
    } else if (turns == fieldColumnCount * fieldRowCount - 1)
    {
        cout << "Покрытие всей доски возможно." << endl;
        int** notCircledPaths = FilterCircledPaths(newPaths, newPathsCount, turns);

        PrintUnpackedPaths(notCircledPaths, notCircledPathsCount, turns, fieldColumnCount);

        return notCircledPaths[0];
    }
    
    int** notCircledPaths = FilterCircledPaths(newPaths, newPathsCount, turns);
    delete [] newPaths;
    
    //PrintUnpackedPaths(notCircledPaths, notCircledPathsCount, turns, fieldColumnCount);

    return FindPath(notCircledPaths, notCircledPathsCount, turns, fieldColumnCount, fieldRowCount);
}

int* FindPath(const int position, const int fieldColumnCount, const int fieldRowCount)
{
    int* positions = GetKnightTurns(position, fieldColumnCount, fieldRowCount);
    int pathsCount = GetKnightTurnsCount(position, fieldColumnCount, fieldRowCount);
    int** paths = AddTurnsToPath(position, positions, pathsCount);
    
    PrintUnpackedPaths(paths, pathsCount, 2, fieldColumnCount);
    FindPath(paths, pathsCount, 2, fieldColumnCount, fieldRowCount);
    PrintUnpackedPaths(paths, pathsCount, 2, fieldColumnCount);
    
    return nullptr;
}

int main(int argc, char* argv[])
{
    const int FIELD_ROW_COUNT = 7;
    const int FIELD_COLUMN_COUNT = 7;
    SetRussian();
    PrintDelimeter();
    cout << "Доска " << FIELD_ROW_COUNT << "х" << FIELD_COLUMN_COUNT << endl;
    cout << "Укажите стартовую позицию коня:" << endl;
    int knightRow;
    cout << "Линия: ";
    cin >> knightRow;
    int knightColumn;
    cout << "Столбец: ";
    cin >> knightColumn;

    int position = PackPosition(knightRow, knightColumn, FIELD_COLUMN_COUNT);
    int* path = FindPath(position, FIELD_COLUMN_COUNT, FIELD_ROW_COUNT);
    //cout << position << endl;
    //cout << UnpackPositionRow(position, 6) << endl;
    //cout << UnpackPositionColumn(position, 6) << endl;
    return 0;
}
