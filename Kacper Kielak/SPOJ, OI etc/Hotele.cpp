#include <iostream>
#include <vector>

struct City
{
    int number;
    std::vector<int> neighbours;
    bool wasChecked;
};

class possibilitiesCalculator
{
    public:
        possibilitiesCalculator(City *_cities, int _citiesNumber):
            cities(_cities),
            citiesNumber(_citiesNumber),
            possibilities(0)
        {
            count();
        }

        int getPossibilities()
        {
            return possibilities;
        }

    private:
        City *cities;
        int citiesNumber;
        int possibilities;

        void count()
        {
            for(int i=0; i<citiesNumber; i++)
                getPossibilitiesWith(cities[i]);
        }

        void getPossibilitiesWith(City city)
        {
            city.wasChecked=true;
            std::vector<int> row1; //row = cities in same distance from city(arg)
            std::vector<int> row2;
            row1.push_back(city.number);
            int citiesInRow = 0;
            while(!row1.empty())
            {
                for(int i=0; i<row1.size(); i++)
                    if(!cities[row1[i]].wasChecked)
                    {
                        citiesInRow++;
                        addVectors(row2, cities[row1[i]].neighbours);
                    }

                row1=row2;
                row2.clear();
                possibilities+=(citiesInRow)*(citiesInRow-1)/2; //combination
            }
        }

        void addVectors(std::vector<int> &base, std::vector<int> adder)
        {
            for(int i=0; i<adder.size(); i++)
                base.push_back(adder[i]);
        }
};

City* parsePaths(int paths[][2], int citiesNumber)
{
    City *cities = new City[citiesNumber];
    for(int i=0; i<citiesNumber; i++)
        cities[i].number=i;

    for(int i=0; i<citiesNumber-1; i++)
    {
        cities[paths[i][0]].neighbours.push_back(paths[i][1]);
        cities[paths[i][1]].neighbours.push_back(paths[i][0]);
    }

    return cities;
}

int main()
{
    int citiesNumber;
    std::cin >> citiesNumber;

    int paths[citiesNumber-1][2];
    for(int i=0; i<citiesNumber-1; i++)
        std::cin >> paths[i][0] >> paths[i][1];

    City *cities = parsePaths(paths, citiesNumber);

    possibilitiesCalculator pc(cities, citiesNumber);
    std::cout << pc.getPossibilities();
    return 0;
}
