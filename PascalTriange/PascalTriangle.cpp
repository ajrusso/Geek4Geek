#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>


using namespace std;

vector<long long> nthRowOfPascalTriangle(int);
vector<long long> getRow(vector<long long>, int, int);

int main() {
    int n = 100;
    vector<long long> result;
    
    result = nthRowOfPascalTriangle(n);

    if(!result.empty()) {
        for(long long i: result) {
            printf("%llu ", i);
        }
    }
}

vector<long long> nthRowOfPascalTriangle(int n) {
    vector<long long> result = {1};
    
    if(n >= 2) {
        result = {1,1};
        result = getRow(result, 2, n);
    }
    
    return result;
}

vector<long long> getRow(vector<long long> row, int curRowNum, int desiredRowNum) {
    vector<long long> nextRow;

    if(desiredRowNum == curRowNum) {
        return row;
    } else {
        nextRow.push_back(1);
        for(int i = 0; i < row.size() - 1; i++) {
            nextRow.push_back((long long)(row[i] + row[i + 1]) % ((long long)pow(10,9) + 7));
        }
        nextRow.push_back(1);
        nextRow = getRow(nextRow, curRowNum + 1, desiredRowNum);
        return nextRow;
    }
}