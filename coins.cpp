#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int naiveMakeChange(int change, int coin_denoms[], int  n_coins)
{
	if(change == 0)
		return 0;
	
	int result = INT_MAX;
	int sub_result;
	for(int i = 0; i < n_coins; i++){
		if(coin_denoms[i] <= change){ // check if coin is legal to use
			sub_result = naiveMakeChange(change-coin_denoms[i], coin_denoms, n_coins);

			if(sub_result+1 < result){
				result = sub_result+1;
			}
		}
	}
	return result;
}

int memoChange(int change, int coin_denoms[], int  n_coins, int* memo)
{
	if(memo[change] != INT_MAX)
		return memo[change];
	
	if(change == 0)
		return 0;
	
	int result = INT_MAX;
	int sub_result;
	for(int i = 0; i < n_coins; i++){
		if(coin_denoms[i] <= change){ // check if coin is legal to use
			sub_result = memoChange(change-coin_denoms[i], coin_denoms, n_coins, memo);

			if(sub_result+1 < result){
				result = sub_result+1;
			}
		}
	}
	memo[change] = result;
	return result;
}



int main()
{
	int change;
	cout << "How much change do we need to make: ";
	cin >> change;
	
	int* memo = new int[change+1];
	for(int i = 0; i < change+1; i++){
		memo[i] = INT_MAX;
	}
	
	int coin_denoms[4] = {1, 5, 6, 9};
	int n_coins = 4;
	int result = memoChange(change, coin_denoms, n_coins, memo);
	cout << "We need " << result << " coins";
	return 0;
}