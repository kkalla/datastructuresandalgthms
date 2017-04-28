#include <iostream>
#include <vector>

using std::vector;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
	int n = weights.size();
  while(n){
	if(capacity==0)
		break;
	int i=0;
	double max = 0.0;
	for(int j=0;j<n;++j){
		if(weights[j]>0&&max<(values[j]/weights[j])){
			max = static_cast<double>(values[j])/weights[j];
			i = j;
		}
	}
	int a = std::min(weights[i],capacity);
	value = value + a*(static_cast<double>(values[i])/weights[i]);
	weights[i] -= a;
	capacity -= a;
	n--;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
