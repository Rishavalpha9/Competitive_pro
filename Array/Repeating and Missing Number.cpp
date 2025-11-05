vector<int> findMissingRepeatingNumbers(vector < int > a) {
  long long n = a.size();

  // S - Sn = x - y

  // S2 - S2N
  long long SN = (n * (n + 1)) / 2;
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

  long long S = 0, S2 = 0;
  for(int i = 0; i < n; i++) {
    S += a[i];
    S2 += (long long)a[i] * (long long)a[i];
  }

  long long val1 = S - SN; // x - y
  long long val2 = S2 - S2N;

  val2 = val2 / val1; // x + y

  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};
}
---------------------------------------------------------------------------------------------------------------------------------------------------------------
// Second Method
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // n is the range size, assuming numbers are 1 to n
    int n = a.size();
    // or a vector initialized to zero, e.g., vector<int> hash(n + 1, 0);
    int hash[n + 1] = {0}; // In C++, this initialization might be done using a vector: vector<int> hash(n + 1, 0);
    // Step 1: Count the frequency of each element in the input array 'a'
    for(int i = 0; i < n; i++) {
        hash[a[i]]++;
    }
    // Step 2: Iterate through the expected numbers (1 to n) to find the missing and repeating ones
    int repeating = -1;
    int missing = -1;
    for(int i = 1; i <= n; i++) {
        // A number 'i' is repeating if its count is 2
        if(hash[i] == 2) {
            repeating = i;
        } 
        // A number 'i' is missing if its count is 0
        else if(hash[i] == 0) {
            missing = i;
        }
        // Optimization: Once both are found, stop searching
        if(repeating != -1 && missing != -1) {
            break;
        }
    }
    // Return the result as a pair: {repeating, missing}
    return {repeating, missing};
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Third method 
  vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n = a.size();
    
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    int bitNo = 0;
    while(1) {
        if ((xr & (1 << bitNo)) != 0) {
            break;
        }
        bitNo++;
    }

    int zero = 0; 
    int one = 0;

    for (int i = 0; i < n; i++) {
        if((a[i] & (1 << bitNo)) != 0) {
            one = one ^ a[i];
        }
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if((i & (1 << bitNo)) != 0) {
            one = one ^ i;
        }
        else {
            zero = zero ^ i;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == zero)
            cnt++;
    }

    if(cnt == 2) return {zero, one};
    
    return {one, zero};
}


