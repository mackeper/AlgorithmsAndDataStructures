#include <iostream>     // cout, sin
#include <list>         // list: push_front, push_back... pop...
#include <algorithm>    // sort, min, max
#include <limits>       // std::numeric_limits<T>::infinity()
#include <vector>       // vector

using namespace std;

enum Side {left = 0, right = 1};

struct Car
{
    int arrival_time;
    int destination_time = 0;
    int side;
};

void print_destination_times(vector<Car> &cars)
{
    for(Car c : cars)
        cout << c.destination_time << "\n";
}

int check_waiting_time(int time, vector<Car> &cars)
{
    int a_time = 0;
    int car_index = 0;
    while(cars[car_index++].destination_time != 0) {}
    a_time = cars[car_index-1].arrival_time;
    return max(time, a_time);
}

int pickup_cars(int cars_per_trip, int time, vector<Car> &cars, int travel_time, int side)
{
    int count = 0;
    for(int i = 0; count < cars_per_trip && i < cars.size(); i++)
    {
        if(cars[i].arrival_time <= time && cars[i].destination_time == 0 && cars[i].side == side)
        {
            cars[i].destination_time = time + travel_time;
            count++;
        }
    }
    return count;
}

void ferryloading(int cars_per_trip, vector<Car> &cars, int travel_time)
{
    int cars_moved = 0;
    int side = Side::left;
    int time = 0;
    while(cars_moved < cars.size())
    {
        time = check_waiting_time(time, cars);
        cars_moved += pickup_cars(cars_per_trip, time, cars, travel_time, side);
        time += travel_time;
        side = side == Side::left ? Side::right : Side::left;
    }

    print_destination_times(cars);
}


int main()
{
    int c;
    cin >> c;

    while(c-- > 0)
    {
        int cars_per_trip;
        int travel_time;
        int m;

        cin >> cars_per_trip >> travel_time >> m;

        vector<Car> cars;

        while(m-- > 0)
        {
            Car new_car;
            int arrival_time;
            char side[5];

            cin >> new_car.arrival_time;
            cin >> side;

            new_car.side = side[0] == 'l' ? Side::left : Side::right;

            cars.emplace_back(new_car);
        }

        ferryloading(cars_per_trip, cars, travel_time);
        cout << "\n";

    }

    return 0;
}
