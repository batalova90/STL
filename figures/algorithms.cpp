#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <random>
#include <ctime>
#include <algorithm>

struct point
{
    int x{ 0 };
    int y{ 0 };
};

void PrintPoints(point& p)
{
    std::cout << "Point: (" << p.x << ", " << p.y << ")\n";
}


void addPoint(point& p)
{
    int x = 0;
    int y = 0;

    x = std::rand() % 101;
    y = std::rand() % 101;

    p.x = x;
    p.y = y;


}
struct geometric_figure
{
private:

public:
    int amountVertex{ 0 };
    std::vector<point> points{ 0 };
    bool operator < (const geometric_figure& sh)
    {
        return amountVertex < sh.amountVertex;
    }


};

void addGeometricFigure(std::vector<geometric_figure>& generate)
{

    for (int i = 0; i < generate.size(); ++i)
    {
        generate[i].amountVertex = 3 + std::rand() % (6 - 3);
        generate[i].points.resize(generate[i].amountVertex);
        for (int j = 0; j < generate[i].amountVertex; ++j)
        {
            addPoint(generate[i].points[j]);
        }
    }
}

int sumOfVertex(std::vector<geometric_figure>& vertex)
{
    int sum(0);
    for (int i = 0; i < vertex.size(); ++i)
        sum = sum + vertex[i].amountVertex;
    return sum;

}

bool isTriangle(const geometric_figure& figures)
{
    return figures.amountVertex == 3;
}

bool isRectangle(const geometric_figure& figures)
{
    return figures.amountVertex == 4;
}

bool isPentagon(const geometric_figure& figures)
{
    return figures.amountVertex == 5;
}

void countFigures(std::vector<geometric_figure>& figures)
{
    int countTriangle = std::count_if(figures.begin(), figures.end(), isTriangle);
    int countRectangle = std::count_if(figures.begin(), figures.end(), isRectangle);
    int countPentagon = std::count_if(figures.begin(), figures.end(), isPentagon);

    std::cout << "Amount of triangle: " << countTriangle << "\nAmount of rectangle: "
        << countRectangle << "\nAmount of Pentagon: " << countPentagon << "\n";
}

void deletePentagons(std::vector<geometric_figure>& figures)
{
    figures.erase(remove_if(figures.begin(), figures.end(), isPentagon), figures.end());

}

bool operator < (const geometric_figure& fig1, const geometric_figure& fig2)
{
    return fig1.amountVertex < fig2.amountVertex;
}

void printFigures(std::vector<geometric_figure>& arrayFigures)
{
    for (int i = 0; i < arrayFigures.size(); ++i)
    {
        switch (arrayFigures[i].amountVertex)
        {
        case 3:
        {
            std::cout << "Triangle: ";
            for (auto temp : arrayFigures[i].points)
                PrintPoints(temp);
        } break;
        case 4:
        {
            std::cout << "Rectangle: ";
            for (auto temp : arrayFigures[i].points)
                PrintPoints(temp);
        } break;
        case 5:
        {
            std::cout << "Pentagon: ";
            for (auto temp : arrayFigures[i].points)
                PrintPoints(temp);
        } break;

        }

    }

}





void readFile(const std::string& filename, std::string& buffer) //read file
{
    std::ifstream fin(filename);
    std::string str;
    if (!fin.is_open())
        std::cout << "The file cannot be opened! " << "\n";
    else
    {
        while (!fin.eof())
        {
            getline(fin, str);
            buffer += str + "\n";

        }
    }
}

void stringToVector(const std::string& mainString, std::vector<std::string>& setStrings)
{
    std::string strBuffer;
    std::istringstream strStream(mainString);

    while (strStream >> strBuffer)
        setStrings.push_back(strBuffer);

}

bool operator < (const std::string& str1, const std::string& str2)
{
    if (str1.length() == str2.length())
        return false;
    else
        return str1.length() < str2.length();
}

void convertedToPoint(const std::vector<geometric_figure>& figures, std::vector<point>& points)
{
    int numberOfPoints = 0;
    for (int i = 0; i < figures.size(); i++)
    {
        numberOfPoints = std::rand() % (figures[i].amountVertex);
        points.push_back(figures[i].points[numberOfPoints]);
    }

}



int main()
{
    srand(time(NULL));
    std::string str("Here you can find activities to practise your reading skills. Reading will help you to improve your understanding of the language and build your vocabulary. Kill kill kill Here You Can. The self-study lessons in this section are written and organised according to the levels of the Common European Framework of Reference for languages (CEFR). There are different types of texts and interactive exercises that practise the reading skills you need to do well in your studies, to get ahead at work and to communicate in English in your free time.");
    std::vector<std::string> str2;
    stringToVector(str, str2);

    std::set<std::string> amountWords;

    for (int i = 0; i < str2.size(); ++i)
    {
        amountWords.insert(str2[i]);

    }

    for (auto it = amountWords.begin(); it != amountWords.end(); ++it)
        std::cout << *it << "\n";

    //Task2
    int amountFigures = 10; //количество фигур
    std::vector<geometric_figure> myFigure(amountFigures);
    addGeometricFigure(myFigure); //добавление фигур в вектор
    int count = sumOfVertex(myFigure); //количество вершин в векторе фигур

    //сортировка по вершинам фигур
    std::cout << "\n\nSource array: \n";
    printFigures(myFigure);

    //Удаление пятиугольников
    std::cout << "\nBefor deletePentagons: \n";
    countFigures(myFigure); //кол-во треуг, прямоуг, пятиугольников
    //deletePentagons(myFigure); //удаляет пятиугольники
    //std::cout << "After deletePentagons: \n";
    //countFigures(myFigure);


    //преобразование в вектор point
    std::vector<point> myPoint;
    convertedToPoint(myFigure, myPoint);
    for (int i = 0; i < myPoint.size(); i++)
        PrintPoints(myPoint[i]);

    //сортировка по вершинам фигур
    std::cout << "\n\nAfter sort: \n";
    std::sort(myFigure.begin(), myFigure.end());
    printFigures(myFigure);


    return 0;
}
