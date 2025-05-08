#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

struct KnapsackSolution {
  int maxProfit;
  int totalWeight;
  std::vector<int> itemsIncluded;
};

// Calculate upper bound for branch and bound
double calculateBound(
  const std::vector<int>& profits,
  const std::vector<int>& weights, 
  int currentProfit,
  int currentWeight,
  int index,
  int capacity
)
{
  double bound = currentProfit;
  int remainingWeight = currentWeight;

  for (int i = index + 1; i < profits.size(); ++i) {
    remainingWeight += weights[i];
    if (remainingWeight <= capacity) {
      bound += profits[i];
    } else {
      // Add the fractional profit for the last item that partially fits
      return bound + (1.0 - (double)(remainingWeight - capacity) / weights[i]) * profits[i];
    }
  }
  return bound;
}

// Branch and bound knapsack algorithm
void branchAndBoundKnapsack(
  const std::vector<int>& profits,
  const std::vector<int>& weights, 
  int capacity, int index,
  int currentProfit, int currentWeight,
  std::vector<int>& currentSolution,
  KnapsackSolution& bestSolution
)
{
  int n = profits.size();

  // Try including the current item if it fits
  if (currentWeight + weights[index] <= capacity) {
    currentSolution[index] = 1;

    if (index < n - 1) {
      branchAndBoundKnapsack(profits, weights, capacity, index + 1, 
        currentProfit + profits[index], currentWeight + weights[index],
        currentSolution, bestSolution);
    }

    // Update best solution if we've reached the end and found a better solution
    if ((currentProfit + profits[index] > bestSolution.maxProfit) && index == n - 1) {
      bestSolution.maxProfit = currentProfit + profits[index];
      bestSolution.totalWeight = currentWeight + weights[index];
      bestSolution.itemsIncluded = currentSolution;
    }
  }

  // Try excluding the current item if the bound is promising
  if (calculateBound(profits, weights, currentProfit, currentWeight, index, capacity) >= bestSolution.maxProfit) {
    currentSolution[index] = 0;

    if (index < n - 1) {
      branchAndBoundKnapsack(profits, weights, capacity, index + 1, 
          currentProfit, currentWeight,
          currentSolution, bestSolution);
    }

    // Update best solution if we've reached the end and found a better solution
    if (currentProfit > bestSolution.maxProfit && index == n - 1) {
      bestSolution.maxProfit = currentProfit;
      bestSolution.totalWeight = currentWeight;
      bestSolution.itemsIncluded = currentSolution;
    }
  }
}

void preprocessItems(std::vector<int>& weights, std::vector<int>& profits) {
  int n = weights.size();
  std::vector<int> indices(n);
  std::iota(indices.begin(), indices.end(), 0);

  // Sort indices by decreasing profit/weight ratio
  std::sort(indices.begin(), indices.end(), [&](int i, int j) {
    return (double)profits[i] / weights[i] > (double)profits[j] / weights[j];
  });

  // Create new sorted arrays
  std::vector<int> sortedWeights(n);
  std::vector<int> sortedProfits(n);

  for (int i = 0; i < n; ++i) {
    sortedWeights[i] = weights[indices[i]];
    sortedProfits[i] = profits[indices[i]];
  }

  // Replace original arrays with sorted ones
  weights = sortedWeights;
  profits = sortedProfits;
}

KnapsackSolution solveKnapsack(std::vector<int> weights, std::vector<int> profits, int capacity) {
  int n = weights.size();
  preprocessItems(weights, profits);

  KnapsackSolution bestSolution;
  bestSolution.maxProfit = 0;
  bestSolution.totalWeight = 0;
  bestSolution.itemsIncluded.resize(n, 0);

  std::vector<int> currentSolution(n, 0);

  branchAndBoundKnapsack(profits, weights, capacity, 0, 0, 0, currentSolution, bestSolution);

  return bestSolution;
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}


int main() {
  int numItems = 5;
  int knapsackCapacity = 15;
  std::vector<int> weights = {12, 2, 1, 1, 4};
  std::vector<int> profits = {4, 2, 2, 1, 10};

  std::cout << "Capacity: " << knapsackCapacity << "\n--------------\n";
  std::cout << "WEIGHTS:\n";
  printVector(weights);

  std::cout << "PROFITS:\n";
  printVector(profits);

  KnapsackSolution solution = solveKnapsack(weights, profits, knapsackCapacity);

  std::cout << "Max Profit: " << solution.maxProfit << "\n";
  std::cout << "Total Weight: " << solution.totalWeight << "\n";
  std::cout << "Items: ";
  printVector(solution.itemsIncluded);

  std::cout << "\n";

  return 0;
}
