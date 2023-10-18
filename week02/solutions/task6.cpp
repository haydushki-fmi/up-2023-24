#include <cmath>
#include <iostream>

int main() {
  std::cout << "Enter the foundations' width:\t";
  double width = 0.0;
  std::cin >> width;

  std::cout << "Enter the foundations' height:\t";
  double height = 0.0;
  std::cin >> height;

  std::cout << "Enter the foundations' length:\t";
  double length = 0.0;
  std::cin >> length;

  std::cout << "Enter the concrete's price (in BGN ";
  std::cout << "per cubic meter):\t";
  double concrete_price_per_m3 = 0.0;
  std::cin >> concrete_price_per_m3;

  double concrete_volume = width * height * length;
  double concrete_price = concrete_volume * concrete_price_per_m3;

  std::cout << "Enter the capacity (in cubic meters) ";
  std::cout << "of the concrete truck:\t";
  double truck_capacity = 0.0;
  std::cin >> truck_capacity;

  int n_trucks_needed = std::ceil(concrete_volume / truck_capacity);

  std::cout << "Enter the distance to the construction site:\t";
  double distance_to_site = 0.0;
  std::cin >> distance_to_site;

  std::cout << "Enter the fuel consumption rate (in litres ";
  std::cout << "per 100 km) of the concrete truck:\t";
  double fuel_consumption_rate = 0.0;
  std::cin >> fuel_consumption_rate;

  // Double the fuel consumption to account for the return trip too.
  double fuel_consumption = fuel_consumption_rate * 2 * distance_to_site / 100;

  std::cout << "Enter the fuel's price (in BGN per liter):\t";
  double fuel_price_per_l = 0.0;
  std::cin >> fuel_price_per_l;

  double fuel_price = n_trucks_needed * fuel_consumption * fuel_price_per_l;
  double total_price = concrete_price + fuel_price;

  std::cout << "The concrete's price (to the company) is ";
  std::cout << concrete_price << " BGN.\n";
  std::cout << "The fuel's price (to the company) is ";
  std::cout << fuel_price << " BGN.\n";
  std::cout << "The total price is " << total_price << " BGN.\n";
  
  return 0;
}
