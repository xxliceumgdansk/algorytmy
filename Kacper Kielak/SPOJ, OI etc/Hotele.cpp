#include <iostream>
#include <vector>

struct City
{
    int number;
    std::vector<int> neighbours;
};

class possibilitiesCalculator
{
    public:
        possibilitiesCalculator(City *_cities, int _citiesNumber):
            cities(_cities),
            citiesNumber(_citiesNumber),
            possibilities(0)
        {
            std::cout << "pc created!\n";
            countAllPossib();
        }

        int getPossibilities()
        {
            return possibilities;
        }

    private:
        City *cities;
        int citiesNumber;
        int possibilities;

        void countAllPossib()
        {
            for(int i=0; i<citiesNumber; i++)
                countFrom(i);
        }

        void countFrom(int city)
        {
            std::cout << "count from " << city+1 << " started!; ";

            bool checkedCities[citiesNumber];
            checkedCities[city]=true;

            int subtreesNumber = cities[city].neighbours.size();
            if(subtreesNumber<3)
            {
                std::cout << std::endl;
                return;
            }
            std::cout << "subtreesNumber: " << subtreesNumber;

            std::vector<int> row1[subtreesNumber];
            std::vector<int> row2[subtreesNumber];

            //
            for(int i=0; i<subtreesNumber; i++)
                row1[i].push_back(cities[city].neighbours[i]);
            //
            while(atLeast3FullSubtrees(row1, subtreesNumber))
            {
                for(int i=0; i<subtreesNumber; i++)
                {
                    for(int j=0; j<row1[i].size(); j++)
                        if(!checkedCities[row1[i][j]])
                        {
                            addUncheckedNeighbours(row2[i], cities[row1[i][j]].neighbours, checkedCities);
                            checkedCities[row1[i][j]]=true;
                        }
                }

                countCombinations(row1, subtreesNumber);
                std::cout << "; in each subtree: ";
                for(int i=0; i<subtreesNumber; i++)
                {
                    std::cout << row1[i].size() << " ";
                    row1[i]=row2[i];
                    row2[i].clear();
                }
            }
            std::cout << std::endl;
        }

        void countCombinations(std::vector<int> *subtreesRows, int subtreesNumber)
        {
            for(int i=0; i<subtreesNumber-2; i++)
                for(int j=i+1; j<subtreesNumber-1; j++)
                    for(int k=j+1; k<subtreesNumber; k++)
                        possibilities+=(subtreesRows[i].size()*subtreesRows[j].size()*subtreesRows[k].size());
        }

        bool atLeast3FullSubtrees(std::vector<int> *subtrees, int subtreesNumber)
        {
            int notEmptySubtrees=0;
            for(int i=0; i<subtreesNumber; i++)
                if(!subtrees[i].empty())
                    notEmptySubtrees++;

            if(notEmptySubtrees>2)
                return true;

            return false;
        }

        void addUncheckedNeighbours(std::vector<int> &base, std::vector<int> neighbours, bool *checkedCities)
        {
            if(!neighbours.empty())
                for(int i=0; i<neighbours.size(); i++)
                    if(!checkedCities[neighbours[i]])
                        base.push_back(neighbours[i]);
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

    std::cout << "paths parsed to cities!\n";
    return cities;
}

int main()
{
    int citiesNumber;
    std::cin >> citiesNumber;

    int paths[citiesNumber-1][2];
    for(int i=0; i<citiesNumber-1; i++)
    {
        std::cin >> paths[i][0] >> paths[i][1];
        paths[i][0]--; paths[i][1]--; //computer counts from 0, cities are given from 1
    }

    City *cities = parsePaths(paths, citiesNumber);

    possibilitiesCalculator pc(cities, citiesNumber);
    std::cout << pc.getPossibilities();
    return 0;
}
